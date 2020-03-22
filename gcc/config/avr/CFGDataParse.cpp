#include "CFGDataParse.h"

#include <fstream>
#include <sstream>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <assert.h>

/* Convert Hex string to number, return false if not possible.  */
bool CFGDataParser::HexStringToNum (std::string& str, uint32_t* pNum)
{
  char *endptr = NULL;
  errno = 0; // reset error flag
  unsigned long val = strtoul (str.c_str(), &endptr, 16);
  // error converting number string, e.g. value is out of range
  if (((errno == ERANGE) && (val == ULONG_MAX)) ||
      ((errno != 0) && (val == 0)))
    return false;

  // not a number string
  if ((endptr == str.c_str()) || (*endptr != '\0'))
    return false;

  *pNum = (uint32_t)val;
  
  return true;
}

bool CFGDataParser::GetConfigurations (std::vector<ConfigSpace>& configSpaces,
                                       std::string& errorMsg)
{
  enum cfg_parse_state
    {
     CFG_CWORD,
     CFG_CSETTING,
     CFG_CVALUE,
     CFG_NONE,
     CFG_ERROR
    };

  const char* filename = CFGDataFile.c_str();
  std::ifstream fileStream (filename, std::ifstream::in);
  std::string lineStr;
  std::string WHITESPACE = " \t";
  LineNum = 0;
  
  enum cfg_parse_state lastParseState = CFG_NONE;
  bool parsingStatus = true;

  std::vector<ConfigReg> configRegisters;
  while (std::getline(fileStream, lineStr))
    {
      LineNum++;
      
      if (lineStr.empty())
        continue;
      /* Ignore lines with just whitespaces or comment.  */
      size_t start = lineStr.find_first_not_of (WHITESPACE);
      if ((start == std::string::npos) || (lineStr.at(start) == '#'))
        continue;
      size_t last = lineStr.find_last_not_of (WHITESPACE);
      assert (last != std::string::npos);
      std::string configLine = lineStr.substr (start, last + 1);

      size_t sepPos = configLine.find_first_of (":");
      if (sepPos == std::string::npos)
        {
          std::stringstream strStream;
          strStream << "Unrecognized pattern at line " << LineNum << ".";
          errorMsg = strStream.str();
          fileStream.close ();
          return false;
        }

      std::string configName = configLine.substr (0, sepPos);
      if (configName == "CWORD")
        {
          parsingStatus =
            GetCWordConfig (configLine, configRegisters, errorMsg);
          lastParseState = parsingStatus == true ? CFG_CWORD : CFG_ERROR;
        }
      else if (configName == "CSETTING")
        {
          assert (lastParseState != CFG_NONE);
          assert (!configRegisters.empty());
          ConfigReg& lastReg = configRegisters.back();
          parsingStatus =
            GetCSettingConfig (configLine, configRegisters.back().configs,
                               errorMsg);
          lastParseState = parsingStatus == true ? CFG_CSETTING : CFG_ERROR;
        }
      else if (configName == "CVALUE")
        {
          assert ((lastParseState == CFG_CSETTING) ||
                  (lastParseState == CFG_CVALUE));
          assert (!configRegisters.empty());
          ConfigReg& lastReg = configRegisters.back();
          assert (!lastReg.configs.empty());
          parsingStatus =
            GetCValueConfig (configLine, lastReg.configs.back(),
                             errorMsg);
          lastParseState = parsingStatus == true ? CFG_CVALUE : CFG_ERROR;
        }
      else
        {
          std::stringstream errStrStream;
          errStrStream << "Unknown directive at line " << LineNum;
          errorMsg = errStrStream.str();
          parsingStatus = false;
        }

      if (parsingStatus == false)
        {
          fileStream.close ();
          return false;
        }
    }

  fileStream.close();

  ConfigSpace fusesSpace (".fuse");
  ConfigSpace lockbitsSpace (".lock");
  uint32_t fusesSize = 0;
  uint32_t lockbitsSize = 0;
  for (RegIterator reg = configRegisters.begin();
       reg != configRegisters.end(); reg++)
    {
      reg->SetDefaultValues();
      switch (reg->address & 0x00FF0000)
        {
        case 0x00820000:
          fusesSpace.registers.push_back (*reg);
          fusesSize += (reg->width / 8);
          break;
        case 0x00830000:
          lockbitsSpace.registers.push_back (*reg);
          lockbitsSize += (reg->width / 8);
          break;
        default:
          {
            assert (0);
            return false;
          }
        }
    }

  if (!fusesSpace.registers.empty())
    {
      fusesSpace.SetValues ("FUSES", 0x820000, fusesSize);
      configSpaces.push_back (fusesSpace);
    }

  if (!lockbitsSpace.registers.empty())
    {
      lockbitsSpace.SetValues ("LOCKBITS", 0x830000, lockbitsSize);
      configSpaces.push_back (lockbitsSpace);
    }

  return true;
}

/* Process CWORD configuration line
   Syntax: CWORD:<address>:<mask>:<default value>[:<name>[,<alias list>]]
*/
bool CFGDataParser::GetCWordConfig (std::string& cwordLine,
                                    std::vector<ConfigReg>& registers,
                                    std::string& errorMsg)
{
  std::stringstream strStream (cwordLine);
  std::stringstream errStrStream;
  std::string token;
  if ((!getline (strStream, token, ':')) ||
      (token != "CWORD"))
    {
      errStrStream << "Unknown directive. Expected CWORD at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  /* Address */
  if (!getline (strStream, token, ':'))
    {
      errStrStream << "Syntax error, expecting address after CWORD at line "
                   << LineNum;
      errorMsg = strStream.str();
      return false;
    }

  uint32_t address = 0;
  if (!HexStringToNum (token, &address))
    {
      errStrStream << "Syntax error, expecting hex digits for CWORD address "
                   << "field at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  // validate address field
  uint32_t addr_space_mask = address & 0xFFFF0000;
  if ((addr_space_mask != 0x00820000) &&
      (addr_space_mask != 0x00830000))
    {
      errStrStream << "Unknown CWORD (register) address (0x" << std::hex
                   << address << ") at line " << std::dec << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  /* Mask */
  if (!getline (strStream, token, ':'))
    {
      errStrStream << "Syntax error, expecting mask after CWORD:address "
                   << "at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }
  
  uint32_t mask = 0;
  if (!HexStringToNum (token, &mask))
    {
      errStrStream << "Syntax error, expecting hex digits for CWORD mask field "
                   << "at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }
  int regSizeInBits = 8;
  switch (mask)
    {
    case 0xFF:
      // regSizeInBits = 8;
      break;
    case 0xFFFF:
      regSizeInBits = 16;
      break;
    case 0xFFFFFF:
      regSizeInBits = 24;
      break;
    case 0xFFFFFFFF:
      regSizeInBits = 32;
      break;
    default:
      errStrStream << "Unknown CWORD mask (" << std::hex << "0x" << mask
                   << ") at line " << std::dec << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  /* Default value */
  if (!getline (strStream, token, ':'))
    {
      errStrStream << "Syntax error, expecting default value after "
                   << "CWORD:address:mask at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }
  
  uint32_t defaultValue = 0;
  if (!HexStringToNum (token, &defaultValue))
    {
      errStrStream << "Syntax error, expecting hex digits for CWORD default "
                   << "value field at line "<< LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  /* Name and alias list */
  if (!getline (strStream, token))
    {
      errStrStream << "Syntax error, expecting name and alias list after "
                   << "CWORD:address:mask:default-value at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  size_t sepPos = token.find_first_of (',');
  std::string name;
  if (sepPos == std::string::npos)
    name = token;
  else
    name = token.substr (0, sepPos);
  // ignore the alias list for now.

  ConfigReg reg(name, (uint32_t)address, regSizeInBits, defaultValue);
  registers.push_back (reg);

  return true;
}

/* Process CSETTING configuration line
   Syntax: CSETTING:<mask>:<name>[,<alias list>]:<description>
*/
bool CFGDataParser::GetCSettingConfig (std::string& csettingLine,
                                       std::vector<ConfigSpec>& configs,
                                       std::string& errorMsg)
{
  std::stringstream strStream (csettingLine);
  std::stringstream errStrStream;
  std::string token;
  if ((!getline (strStream, token, ':')) ||
      (token != "CSETTING"))
    {
      errStrStream << "Unknown directive. Expected CSETTING at line "
                   << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  /* mask */
  if (!getline (strStream, token, ':'))
    {
      errStrStream << "Syntax error, expecting mask after CSETTING at line "
                   << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  uint32_t mask = 0;
  if (!HexStringToNum (token, &mask))
    {
      errStrStream << "Syntax error, expecting hex digits for CSETTING mask "
                   << "field at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }


  /* Name and alias list */
  if (!getline (strStream, token, ':'))
    {
      errStrStream << "Syntax error, expecting name and alias list after "
                   << "CSETTING:mask: at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  size_t sepPos = token.find_first_of (',');
  std::string name;
  if (sepPos == std::string::npos)
    name = token;
  else
    name = token.substr (0, sepPos);
  // ignore the alias list for now.

  // ignore the description field for now.

  // compute the bit position
  uint8_t bitPos = 0;
  for (ConfigIterator C = configs.begin(); C != configs.end(); C++)
    bitPos += C->width;
  ConfigSpec setting(name, (uint32_t)mask, bitPos,
                     name == "reserved" ? false : true);
  configs.push_back (setting);

  return true;
}

/* Process CVALUE configuration line
   Syntax: CVALUE:<value>:<name>[,<alias list>]:<description>
*/
bool CFGDataParser::GetCValueConfig (std::string& cvalueLine,
                                     ConfigSpec& config,
                                     std::string& errorMsg)
{
  std::stringstream strStream (cvalueLine);
  std::stringstream errStrStream;
  std::string token;
  if ((!getline (strStream, token, ':')) ||
      (token != "CVALUE"))
    {
      errStrStream << "Unknown directive. Expected CVALUE at line "
                   << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  /* value */
  if (!getline (strStream, token, ':'))
    {
      errStrStream << "Syntax error, expecting value after CVALUE at line "
                   << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  uint32_t value = 0;
  if (!HexStringToNum (token, &value))
    {
      errStrStream << "Syntax error, expecting hex digits for CVALUE mask "
                   << "field at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }


  /* Name and alias list */
  if (!getline (strStream, token, ':'))
    {
      errStrStream << "Syntax error, expecting name and alias list after "
                   << "CVALUE:value: at line " << LineNum;
      errorMsg = errStrStream.str();
      return false;
    }

  size_t sepPos = token.find_first_of (',');
  std::string name;
  if (sepPos == std::string::npos)
    name = token;
  else
    name = token.substr (0, sepPos);
  // ignore the alias list for now.

  // ignore the description field for now.

  config.AddRefValue (name, (uint8_t)value);

  return true;
}

#ifdef MAIN

std::vector<class ConfigSpace> AvrConfigSpaces;

int main(int argc, char*argv[])
{
  if (argc != 2)
    {
      std::cout << "Usage: argv[0] <device.cfgdata>\n";
      return 0;
    }
  std::string cfgFile (argv[1]);
  CFGDataParser cfgParser (cfgFile);

  std::string errorMsg;
  std::vector<ConfigSpace> configSpaces;
  cfgParser.GetConfigurations (configSpaces, errorMsg);

  if (!errorMsg.empty())
    std::cout << "Error: " << errorMsg.c_str() << "\n\n";

  for (SpaceIterator space = configSpaces.begin(); space != configSpaces.end();
       space++)
    space->Print(std::cout);

  if (configSpaces.empty())
    return 1;
#ifdef MAIN_TEST
  /* add a small test to validate */
  ConfigSpace FusesSpace = configSpaces[0];
  for (ConfigIterator C = FusesSpace.registers[0].configs.begin();
       C != FusesSpace.registers[0].configs.end(); C++)
    {
      bool status = true;
      if (C->cname == std::string("SUT_CKSEL"))
        status = C->SetValue ("0x17");
      else if (C->cname == std::string("CKOUT"))
        status = C->SetValue("SET");
      else if (C->cname == std::string("CKDIV8"))
        status = C->SetValue("CLEAR");

      if (status)
        std::cout << "  reg value after setting " << C->cname.c_str() << " 0x" <<
          std::hex << FusesSpace.registers[0].GetValue() << std::endl;
      else
        std::cout << "could not set value for config " << C->cname
                  << " " << std::endl;
    }

  std::cout << "LOW: def 0x" << std::hex << FusesSpace.registers[0].factorydefault
            << " user 0x" << std::hex << FusesSpace.registers[0].GetValue() << std::endl;

  for (ConfigIterator C = FusesSpace.registers[0].configs.begin();
       C != FusesSpace.registers[0].configs.end(); C++)
    {
      std:: cout << "  " << C->cname << " 0x" << std::hex << (C->user_value << C->bitPos)
                 << "(" << (uint32_t)C->user_value << ")" << std::endl;
    }
#endif
  return 0;
}

#endif
