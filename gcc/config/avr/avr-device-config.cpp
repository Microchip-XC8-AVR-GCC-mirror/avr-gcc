#include <stdlib.h>
#include <fstream>

#include "avr-device-config.h"
#include "CFGDataParse.h"

#include <assert.h>
#include <cstdio>
#include <cerrno>
#include <cstdlib>

ConfigSpace::ConfigSpace(std::string sectionName) :
  AsmSectionName (sectionName), isReferenced(false), decl(NULL) {}

void
ConfigSpace::SetValues(std::string name, uint32_t addr, uint32_t nbytes)
{
  sname = name;
  address = addr;
  width = nbytes;
}

void
ConfigSpace::Print(std::ostream &Stream)
{
  char buffer[255] = "";
  sprintf (buffer, "Space: %s (0x%x, %d)\n", sname.c_str(), address, width);

  Stream << buffer;

  //Stream << "Space: " << sname << " (0x" << std::hex << address << ", " << width << ")\n";
  for (RegIterator R = registers.begin(); R != registers.end(); R++)
    R->Print(Stream);
}

ConfigReg::ConfigReg(std::string name, uint32_t addr, uint8_t bits,
                     uint32_t defval)
  : rname (name), address (addr), width (bits), factorydefault (defval)
{
  offset = 0x0000FFFF & addr;
}

uint32_t
ConfigReg::GetValue()
{
  uint32_t RegValue = factorydefault;

  for (ConfigIterator C = configs.begin(); C != configs.end(); C++)
    {
      // clear config bits in a byte and set config bits
      RegValue = RegValue & (~(C->mask));
      RegValue |= C->GetValue();
    }

  return RegValue & ((1 << width) - 1);
}

void ConfigReg::SetDefaultValues ()
{
  for (ConfigIterator C = configs.begin(); C != configs.end(); C++)
    {
      C->SetDefaultValue (factorydefault);
    }
}

void
ConfigReg::Print(std::ostream &Stream)
{
  char buffer[255] = "";
  sprintf (buffer, "  Reg: %s (offset: 0x%x width: 0x%x default: 0x%x)\n",
           rname.c_str(), offset, width, factorydefault);
  Stream << buffer;
  //Stream << "  Reg: " << rname << " (offset: " << std::hex << offset << " width: "
  //     << std::hex << width << " default: 0x" << std::hex << factorydefault << ")\n";
  for (ConfigIterator C = configs.begin(); C != configs.end(); C++)
    {
      C->Print(Stream);
    }
}

/*
  CSETTING:<mask>:<name>[,<alias list>]:<description>

  mask: value for the representing bits
  e.g. for 2-3 bits, mask will be 0xC
*/
ConfigSpec::ConfigSpec (std::string name, uint32_t cmask, uint8_t bpos,
                        bool canEdit=true)
  : cname(name), mask(cmask), bitPos(bpos), isModified (false)
{
  width = __builtin_popcount (cmask);
  isEditable = canEdit;
}

void ConfigSpec::SetDefaultValue(uint32_t RegDefaultVal)
{
  /* default value as in the respective bit position.  */
  default_value = RegDefaultVal & mask;
}

void ConfigSpec::AddRefValue(std::string id, uint8_t val)
{
  reference_values.push_back (std::make_pair(id, val));
}

// Set value for config. Returns false if not valid value
bool ConfigSpec::SetValue(std::string value)
{
  char *endptr = NULL;
  errno = 0;
  uint32_t int_val = strtoul (value.c_str(), &endptr, 0);
  bool isNumber = *endptr == '\0';

  /* If no reference values found, allow any NUMERIC value
     but check the limits. Ref: XC8-1741  */
  if (reference_values.empty())
    {
      if (!isNumber) return false;
      if (int_val > mask) return false;
      user_value = int_val;
      isModified = true;

      return true;
    }

  bool IsRefFound = false;
  for (RefValIterator R = reference_values.begin();
       R != reference_values.end(); R++)
    {
      if (isNumber ? R->second != int_val : R->first.compare(value) != 0)
        continue;
      IsRefFound = true;
      user_value = R->second;
      isModified = true;
    }
  return IsRefFound;
}

uint8_t ConfigSpec::GetValue()
{
  if (isModified == false)
    return default_value;

  return user_value << bitPos;
}

void
ConfigSpec::Print(std::ostream &Stream)
{
  char buffer[255]="";
  sprintf (buffer, "    config: %s %d bits offset: %d default: 0x%x\n",
           cname.c_str(), width, bitPos, default_value);

  Stream << buffer;

  for (RefValIterator Val = reference_values.begin();
       Val != reference_values.end(); Val++)
    {
      char buf[128]="";
      sprintf(buf, "      (%s, 0x%x)\n", Val->first.c_str(), Val->second);
      Stream << buf;
    }
}

AvrDeviceConfig::AvrDeviceConfig()
{
  AreConfigsLoaded = false;
  AreConfigsChanged = false;
}

bool AvrDeviceConfig::LoadConfigurations(std::string File)
{
  if (File.empty()) return false;

  std::ifstream cfgfile(File.c_str(), std::ifstream::in);
  if (!cfgfile.good()) return false;

  CFGDataParser cfgParser (File);
  std::string errorMsg;
  bool status = cfgParser.GetConfigurations (Spaces, errorMsg);
  if (!status)
    {
      fprintf (stderr, "Warning: Could not load configurations (%s)\n",
               errorMsg.c_str());
      return false;
    }

  AreConfigsLoaded = true;
  return true;
}

bool AvrDeviceConfig::SetConfig(std::string config_name, std::string value,
                                char* Error)
{
  bool isConfigFound = false;

  for (SpaceIterator itS = Spaces.begin();
       itS != Spaces.end(); itS++)
    {
      for (RegIterator itR = itS->registers.begin();
           itR != itS->registers.end(); itR++)
        {
          for (ConfigIterator itC = itR->configs.begin();
               itC != itR->configs.end(); itC++)
            {
              if (itC->cname.compare(config_name) != 0)
                continue;

              isConfigFound = true;
              if (!itC->IsPermitted())
                {
                  sprintf (Error, "configuration setting '%s' is not writable",
                           config_name.c_str());
                  return false;
                }

              if (itC->isModified)
                {
                  sprintf (Error, "multiple definition for configuration setting '%s'",
                           config_name.c_str());
                  return false;
                }

              if (false == itC->SetValue(value))
                {
                  sprintf (Error, "unknown value for configuration '%s': '%s'",
                           config_name.c_str(), value.c_str());
                  return false;
                }

              /* return as error issued or config set.  */
              itS->isReferenced = true;
              AreConfigsChanged = true;
              return true;
            }
        }
    }

  if (!isConfigFound)
    {
      sprintf (Error, "unknown configuration setting: '%s'", config_name.c_str());
      return false;
    }

  assert (0);
}

