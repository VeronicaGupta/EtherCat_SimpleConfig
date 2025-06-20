/**************************************************************************************
 Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: Ecs_Defines.h 74936 2018-03-28 08:35:03Z Sven $:
**************************************************************************************/

#ifndef _ECS_DEFINES_H
#define _ECS_DEFINES_H

/* AL state */
#define ECAT_AL_STATE_INIT                                          0x01
#define ECAT_AL_STATE_PRE_OPERATIONAL                               0x02
#define ECAT_AL_STATE_BOOTSTRAP_MODE                                0x03
#define ECAT_AL_STATE_SAFE_OPERATIONAL                              0x04
#define ECAT_AL_STATE_OPERATIONAL                                   0x08

/* AL status changes */
#define ECAT_AL_STATUS_CHANGE_CONFIRMATION                          0x00
#define ECAT_AL_STATUS_CHANGE_ERROR                                 0x01

/* AL status code definitions */
#define ECAT_AL_STATUS_CODE_NO_ERROR                                            0x0000
#define ECAT_AL_STATUS_CODE_UNSPECIFIED_ERROR                                   0x0001
#define ECAT_AL_STATUS_CODE_NO_MEMORY                                           0x0002
#define ECAT_AL_STATUS_CODE_INVALID_DEVICE_SETUP                                0x0003 // Additional ETG1020
#define ECAT_AL_STATUS_CODE_SII_EEPROM_INFORMATION_DOES_NOT_MATCH_FIRMWARE      0x0006 // Additional ETG1020
#define ECAT_AL_STATUS_CODE_FIRMWARE_UPDATE_NOT_SUCCESSFUL_OLD_FW_STILL_RUNNING 0x0007 // Additional ETG1020
#define ECAT_AL_STATUS_CODE_LICENCE_ERROR                                       0x000E // Additional ETG1020
#define ECAT_AL_STATUS_CODE_INVALID_REQUESTED_STATE_CHANGE                      0x0011
#define ECAT_AL_STATUS_CODE_UNKNOWN_REQUESTED_STATE                             0x0012
#define ECAT_AL_STATUS_CODE_BOOTSTRAP_NOT_SUPPORTED                             0x0013
#define ECAT_AL_STATUS_CODE_NO_VALID_FIRMWARE                                   0x0014
#define ECAT_AL_STATUS_CODE_INVALID_MAILBOX_CONFIGURATION_BOOTSTRAP             0x0015
#define ECAT_AL_STATUS_CODE_INVALID_MAILBOX_CONFIGURATION_PREOP                 0x0016
#define ECAT_AL_STATUS_CODE_INVALID_SYNC_MANAGER_CONFIGURATION                  0x0017
#define ECAT_AL_STATUS_CODE_NO_VALID_INPUTS_AVAILABLE                           0x0018
#define ECAT_AL_STATUS_CODE_NO_VALID_OUTPUTS                                    0x0019
#define ECAT_AL_STATUS_CODE_SYNCHRONIZATION_ERROR                               0x001A
#define ECAT_AL_STATUS_CODE_SYNC_MANAGER_WATCHDOG                               0x001B
#define ECAT_AL_STATUS_CODE_INVALID_SYNC_MANAGER_TYPES                          0x001C
#define ECAT_AL_STATUS_CODE_INVALID_OUTPUT_CONFIGURATION                        0x001D
#define ECAT_AL_STATUS_CODE_INVALID_INPUT_CONFIGURATION                         0x001E
#define ECAT_AL_STATUS_CODE_INVALID_WATCHDOG_CONFIGURATION                      0x001F
#define ECAT_AL_STATUS_CODE_SLAVE_NEEDS_COLD_START                              0x0020
#define ECAT_AL_STATUS_CODE_SLAVE_NEEDS_INIT                                    0x0021
#define ECAT_AL_STATUS_CODE_SLAVE_NEEDS_PREOP                                   0x0022
#define ECAT_AL_STATUS_CODE_SLAVE_NEEDS_SAFEOP                                  0x0023
#define ECAT_AL_STATUS_CODE_INVALID_INPUT_MAPPING                               0x0024
#define ECAT_AL_STATUS_CODE_INVALID_OUTPUT_MAPPING                              0x0025
#define ECAT_AL_STATUS_CODE_INCONSISTENT_SETTINGS                               0x0026
#define ECAT_AL_STATUS_CODE_FREERUN_NOT_SUPPORTED                               0x0027
#define ECAT_AL_STATUS_CODE_SYNCMODE_NOT_SUPPORTED                              0x0028
#define ECAT_AL_STATUS_CODE_FREERUN_NEEDS_3BUFFER_MODE                          0x0029
#define ECAT_AL_STATUS_CODE_BACKGROUND_WATCHDOG                                 0x002A
#define ECAT_AL_STATUS_CODE_NO_VALID_INPUTS_AND_OUTPUTS                         0x002B
#define ECAT_AL_STATUS_CODE_FATAL_SYNC_ERROR                                    0x002C
#define ECAT_AL_STATUS_CODE_NO_SYNC_ERROR                                       0x002D
#define ECAT_AL_STATUS_CODE_CYCLE_TIME_TOO_SMALL                                0x002E // Additional ETG1020
#define ECAT_AL_STATUS_CODE_INVALID_DC_SYNC_CONFIGURATION                       0x0030
#define ECAT_AL_STATUS_CODE_INVALID_DC_LATCH_CONFIGURATION                      0x0031
#define ECAT_AL_STATUS_CODE_PLL_ERROR                                           0x0032
#define ECAT_AL_STATUS_CODE_DC_SYNC_IO_ERROR                                    0x0033
#define ECAT_AL_STATUS_CODE_DC_SYNC_TIMEOUT_ERROR                               0x0034
#define ECAT_AL_STATUS_CODE_DC_INVALID_SYNC_CYCLE_TIME                          0x0035
#define ECAT_AL_STATUS_CODE_DC_SYNCO_CYCLE_TIME                                 0x0036
#define ECAT_AL_STATUS_CODE_DC_SYNC1_CYCLE_TIME                                 0x0037
#define ECAT_AL_STATUS_CODE_MBX_AOE                                             0x0041
#define ECAT_AL_STATUS_CODE_MBX_EOE                                             0x0042
#define ECAT_AL_STATUS_CODE_MBX_COE                                             0x0043
#define ECAT_AL_STATUS_CODE_MBX_FOE                                             0x0044
#define ECAT_AL_STATUS_CODE_MBX_SOE                                             0x0045
#define ECAT_AL_STATUS_CODE_MBX_VOE                                             0x004F
#define ECAT_AL_STATUS_CODE_EEPROM_NO_ACCESS                                    0x0050
#define ECAT_AL_STATUS_CODE_EEPROM_ERROR                                        0x0051
#define ECAT_AL_STATUS_CODE_EXTERNAL_HARDWARE_NOT_READY                         0x0052 // Additional ETG1020
#define ECAT_AL_STATUS_CODE_SLAVE_RESTARTED_LOCALLY                             0x0060
#define ECAT_AL_STATUS_CODE_DEVICE_ID_VALUE_UPDATED                             0x0061
#define ECAT_AL_STATUS_CODE_DETECTED_MODULE_IDENT_LIST_DOES_NOT_MATCH           0x0070 // Additional ETG1020
#define ECAT_AL_STATUS_CODE_APPLICATION_CONTROLLER_AVAILABLE                    0x00F0 // Additional ETG1020
/*0x8000-0xFFFF is customer specific area*/
#define ECAT_AL_STATUS_CODE_HOST_NOT_READY                                      0x8000
#define ECAT_AL_STATUS_CODE_IO_DATA_SIZE_NOT_CONFIGURED                         0x8001
#define ECAT_AL_STATUS_CODE_DPM_HOST_WATCHDOG_TRIGGERED                         0x8002
#define ECAT_AL_STATUS_CODE_FIRMWARE_IS_BOOTING                                 0x8004
#define ECAT_AL_STATUS_CODE_WARMSTART_REQUESTED                                 0x8005
#define ECAT_AL_STATUS_CODE_CHANNEL_INIT_REQUESTED                              0x8006
#define ECAT_AL_STATUS_CODE_CONFIGURATION_CLEARED                               0x8007
#define ECAT_AL_STATUS_CODE_PDI_WATCHDOG_TIME_CONFIGURATION_ERROR               0x8008

/* object dictionary specific access rights */
#define ECAT_OD_READ_PREOP                                          (0x0001)
#define ECAT_OD_READ_SAFEOP                                         (0x0002)
#define ECAT_OD_READ_OPERATIONAL                                    (0x0004)
#define ECAT_OD_WRITE_PREOP                                         (0x0008)
#define ECAT_OD_WRITE_SAFEOP                                        (0x0010)
#define ECAT_OD_WRITE_OPERATIONAL                                   (0x0020)
#define ECAT_OD_MAPPABLE_IN_RXPDO                                   (0x0040)
#define ECAT_OD_MAPPABLE_IN_TXPDO                                   (0x0080)
#define ECAT_OD_BACKUP                                              (0x0100)
#define ECAT_OD_SETTINGS                                            (0x0200)
#define ECAT_OD_READ_INIT                                           (0x4000)
#define ECAT_OD_WRITE_INIT                                          (0x8000)
#define ECAT_OD_READ_ALL                                            (ECAT_OD_READ_PREOP|ECAT_OD_READ_SAFEOP|ECAT_OD_READ_OPERATIONAL|ECAT_OD_READ_INIT)
#define ECAT_OD_WRITE_ALL                                           (ECAT_OD_WRITE_PREOP|ECAT_OD_WRITE_SAFEOP|ECAT_OD_WRITE_OPERATIONAL|ECAT_OD_WRITE_INIT)
#define ECAT_OD_ECAT_ALL                                            (ECAT_OD_SETTINGS|ECAT_OD_BACKUP|ECAT_OD_MAPPABLE_IN_TXPDO|ECAT_OD_MAPPABLE_IN_RXPDO|ECAT_OD_READ_PREOP|ECAT_OD_READ_SAFEOP|ECAT_OD_READ_OPERATIONAL|ECAT_OD_WRITE_PREOP|ECAT_OD_WRITE_SAFEOP|ECAT_OD_WRITE_OPERATIONAL)
#define ECAT_OD_ACCESS_ALL                                          (ECAT_OD_READ_ALL | ECAT_OD_WRITE_ALL)

/* object dictionary specific datatypes */
#define ECAT_OD_DTYPE_BOOLEAN                                       0x0001
#define ECAT_OD_DTYPE_INTEGER8                                      0x0002
#define ECAT_OD_DTYPE_INTEGER16                                     0x0003
#define ECAT_OD_DTYPE_INTEGER32                                     0x0004
#define ECAT_OD_DTYPE_UNSIGNED8                                     0x0005
#define ECAT_OD_DTYPE_UNSIGNED16                                    0x0006
#define ECAT_OD_DTYPE_UNSIGNED32                                    0x0007
#define ECAT_OD_DTYPE_REAL32                                        0x0008
#define ECAT_OD_DTYPE_VISIBLE_STRING                                0x0009
#define ECAT_OD_DTYPE_OCTET_STRING                                  0x000a
#define ECAT_OD_DTYPE_UNICODE_STRING                                0x000b
#define ECAT_OD_DTYPE_TIME_OF_DAY                                   0x000c /*deprecated since ETG V1.1.0*/
#define ECAT_OD_DTYPE_TIME_DIFFERENCE                               0x000d /*deprecated since ETG V1.1.0*/
#define ECAT_OD_DTYPE_DOMAIN                                        0x000f /*deprecated since ETG V1.1.0*/
#define ECAT_OD_DTYPE_INTEGER24                                     0x0010
#define ECAT_OD_DTYPE_REAL64                                        0x0011
#define ECAT_OD_DTYPE_INTEGER40                                     0x0012
#define ECAT_OD_DTYPE_INTEGER48                                     0x0013
#define ECAT_OD_DTYPE_INTEGER56                                     0x0014
#define ECAT_OD_DTYPE_INTEGER64                                     0x0015
#define ECAT_OD_DTYPE_UNSIGNED24                                    0x0016
#define ECAT_OD_DTYPE_UNSIGNED40                                    0x0018
#define ECAT_OD_DTYPE_UNSIGNED48                                    0x0019
#define ECAT_OD_DTYPE_UNSIGNED56                                    0x001a
#define ECAT_OD_DTYPE_UNSIGNED64                                    0x001b
#define ECAT_OD_DTYPE_GUID                                          0x001d
#define ECAT_OD_DTYPE_BYTE                                          0x001e
#define ECAT_OD_DTYPE_WORD                                          0x001F
#define ECAT_OD_DTYPE_DWORD                                         0x0020
#define ECAT_OD_DTYPE_PDO_MAPPING                                   0x0021
#define ECAT_OD_DTYPE_IDENTITY                                      0x0023
#define ECAT_OD_DTYPE_COMMAND_PAR                                   0x0025
#define ECAT_OD_DTYPE_PDO_PARAMETER                                 0x0027
#define ECAT_OD_DTYPE_ENUM                                          0x0028
#define ECAT_OD_DTYPE_SM_SYNCHRONISATION                            0x0029
#define ECAT_OD_DTYPE_SYNC_PAR                                      0x0029 /*legacy name, use former define*/
#define ECAT_OD_DTYPE_RECORD                                        0x002A
#define ECAT_OD_DTYPE_BACKUP_PARAMETER                              0x002B
#define ECAT_OD_DTYPE_MODULAR_DEVICE_PROFILE                        0x002C
#define ECAT_OD_DTYPE_BITARR8                                       0x002D
#define ECAT_OD_DTYPE_BITARR16                                      0x002E
#define ECAT_OD_DTYPE_BITARR32                                      0x002F
#define ECAT_OD_DTYPE_BIT1                                          0x0030
#define ECAT_OD_DTYPE_BIT2                                          0x0031
#define ECAT_OD_DTYPE_BIT3                                          0x0032
#define ECAT_OD_DTYPE_BIT4                                          0x0033
#define ECAT_OD_DTYPE_BIT5                                          0x0034
#define ECAT_OD_DTYPE_BIT6                                          0x0035
#define ECAT_OD_DTYPE_BIT7                                          0x0036
#define ECAT_OD_DTYPE_BIT8                                          0x0037
#define ECAT_OD_DTYPE_ARRAY_OF_INT                                  0x0260
#define ECAT_OD_DTYPE_ARRAY_OF_SINT                                 0x0261
#define ECAT_OD_DTYPE_ARRAY_OF_DINT                                 0x0262
#define ECAT_OD_DTYPE_ARRAY_OF_UDINT                                0x0263
#define ECAT_OD_DTYPE_ERROR_SETTING                                 0x0281
#define ECAT_OD_DTYPE_DIAGNOSIS_HISTORY                             0x0282
#define ECAT_OD_DTYPE_EXTERNAL_SYNC_STATUS                          0x0283
#define ECAT_OD_DTYPE_EXTERNAL_SYNC_SETTINGS                        0x0284
#define ECAT_OD_DTYPE_DEFTYPE_FSOEFRAME                             0x0285
#define ECAT_OD_DTYPE_DEFTYPE_FSOECOMMPAR                           0x0286

#endif
