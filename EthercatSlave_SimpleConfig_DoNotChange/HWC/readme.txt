/*!\page hwc_files Hardware Configurations
NETX90 Hardware Configurations
==============================

The hardware configurations in this folder are preconfigured examples of common
use cases. The purpose is to use them out of the box. They may have to be adapted
to the application cases.

Compatibility Version is:
 - netXStudio V1.0700.1.3056 (tool_version="3.0.17")

The sub folder contains preconfigured hardware configurations for the
pre mass production chips (netx90_rev0), the mass production chips (netx90)
and the netRAPID90.

# hardware_config_16bitdpm.xml
  - 16bit dpm interface
  - internal DPM (idpm) deactive
  - Application CPU deactive

# hardware_config_idpm_flash_sdram.xml
  - internal DPM (idpm) active
  - Application CPU active
  - external flash active
  - external SDRAM interface active
  
# hardware_config_idpm.xml
  - internal DPM (idpm) active
  - Application CPU active

# hardware_config_spm_flash_sdram.xml
  - Serial DPM in mode3 active
  - internal DPM (idpm) deactive
  - Application CPU deactive
  - external flash active
  - external SDRAM interface active
  
# hardware_config_spm.xml
  - Serial DPM in mode3 active
  - internal DPM (idpm) deactive
  - Application CPU deactive
  
*/


