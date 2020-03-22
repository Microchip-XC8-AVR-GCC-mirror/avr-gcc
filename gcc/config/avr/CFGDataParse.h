#include <stdint.h>
#include "avr-device-config.h"

class CFGDataParser
{
private:
  std::string CFGDataFile;
  uint32_t LineNum;
public:
  CFGDataParser(const std::string& file):
    CFGDataFile (file), LineNum (0) {}
  bool GetConfigurations (std::vector<ConfigSpace>&, std::string& errorMsg);
private:
  bool GetCWordConfig (std::string& cwordLine, std::vector<ConfigReg>&,
                       std::string& errorMsg);
  bool GetCSettingConfig (std::string& csettingLine, std::vector<ConfigSpec>&,
                          std::string& errorMsg);
  bool GetCValueConfig (std::string& cvalueLine, ConfigSpec&,
                        std::string& errorMsg);
  bool HexStringToNum (std::string& str, uint32_t *pNum);
};
