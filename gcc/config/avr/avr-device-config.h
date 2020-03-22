#ifndef AVR_DEVICE_CONFIG_H
#define AVR_DEVICE_CONFIG_H 1
#include <stdint.h>

#include <vector>
#include <string>
#include <iostream>

/*
  Configuration File Syntax (.cfgdata)
  Each configuration register is given as:

  CWORD:<address>:<mask>:<default value>[:<name>[,<alias list>]]

  for each CWORD the configuration settings are listed as

  CSETTING:<mask>:<name>[,<alias list>]:<description>

  lastly for each CSETTING all possible values are listed as

  CVALUE:<value>:<name>[,<alias list>]:<description>

  All numerical values are given in unqualified hex.  In terms of
  #pragma config, note the following correspondence:

  #pragma config CSETTING<name> = CVALUE<name>

*/

/* Class for configuration setting i.e. CSETTING.

   CSETTING:<mask>:<name>[,<alias list>]:<description>
*/
class ConfigSpec
{
public:
  std::string    cname;  // CSETTING::name or edc:DCRFieldDef[edc:cname]
  uint8_t        width;  // count bits in mask or ...[edc:nzwidth] e.g. 0x6
  uint8_t        mask;   // mask or (((1 << width) - 1) << bit_position)
  uint8_t        bitPos; // CSETTING or DCRFieldDef starting offset
  uint8_t        default_value;  // register_default & mask
  std::vector< std::pair<std::string,uint8_t> >
  reference_values; // CVALUE[name] & CVALUE[value] or
                    // edc:DCRFieldSemantic[edc:cname],[edc:when]

  bool           isEditable;  // true if editable
  bool           isModified;  // true if user modified
  uint8_t        user_value;  // constant/ ID evaluated to one of reference_values

  //struct reg_t*  config_reg;    // pointer register where this config exists
  //unsigned int   reg_position;  // bit position in register

  // create config with name and width
  ConfigSpec(std::string name, uint32_t mask, uint8_t bitpos,
             bool canEdit);

  void AddRefValue(std::string id, uint8_t val);
  void SetDefaultValue(uint32_t RegDefaultVal);

  bool IsPermitted() { return isEditable; }
  bool SetValue(std::string value);
  uint8_t GetValue();
  void Print (std::ostream &stream);
};

/* Class for configuration word or register i.e. CWORD.

   CWORD:<address>:<mask>:<default value>[:<name>[,<alias list>]]
*/
class ConfigReg
{
public:
  std::string  rname;  // register name
  uint32_t     address; // sector_addr | offset
  uint8_t      width;  // width in bits (multiple of 8)
  uint32_t     factorydefault; // default value
  uint8_t      offset; // offset in the respective group/ space (e.g. fuses)

  ConfigReg(std::string name, uint32_t address, uint8_t bits,
            uint32_t defval);

  /* available configurations in this register.  */
  std::vector<class ConfigSpec> configs;
  uint32_t GetValue();
  void SetDefaultValues ();
  
  void Print (std::ostream &stream);
};

/* Class for configuration register groups (space)
   Example: FUSES and LOCKBITS.
*/
class ConfigSpace
{
public:
  std::string  sname;
  std::string  AsmSectionName;
  unsigned int address;
  unsigned int width; // size in bytes; endaddress - 1
  std::vector<class ConfigReg> registers;
  bool isReferenced;
  void *decl; // Decl associated with this config space
  ConfigSpace(std::string sectionName);
  void SetValues(std::string name, uint32_t addr, uint32_t nbytes);
  void Print (std::ostream &stream);
};

/* Class for AVR Device configurations.
   It loads the configuration from the file, provides function
   to set value for configurations.
*/
class AvrDeviceConfig
{
public:
  bool AreConfigsChanged;
  bool AreConfigsLoaded;
  std::vector<class ConfigSpace> Spaces;
  AvrDeviceConfig();
  bool LoadConfigurations(std ::string config_file);
  bool SetConfig(std::string cname, std::string value, char* err);
};

extern int avr_load_configuration_values (std::string filename);
extern void avr_handle_configuration_setting (std::string config_name,
                                              std::string value);
extern void avr_output_configurations (void);
extern AvrDeviceConfig DeviceConfigurations;

typedef std::vector<class ConfigSpace>::iterator SpaceIterator;
typedef std::vector<class ConfigReg>::iterator RegIterator;
typedef std::vector<class ConfigSpec>::iterator ConfigIterator;
typedef std::vector<std::pair<std::string,uint8_t> >::iterator RefValIterator;

#endif /* AVR_DEVICE_CONFIG_H */

