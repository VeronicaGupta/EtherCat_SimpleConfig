/**************************************************************************************
 Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: Ecs_Public.h 90592 2020-03-02 16:17:25Z Sven $:
**************************************************************************************/

#ifndef _ECS_PUBLIC_H
#define _ECS_PUBLIC_H

#include <Hil_Packet.h>

#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_PACK_1(ECS_PUBLIC)
#endif

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */

/* EtherCAT error LED codes */
#define ECAT_ERRORLED_OFF                                           0
#define ECAT_ERRORLED_SOLID_ON                                      1
#define ECAT_ERRORLED_FLICKERING                                    2
#define ECAT_ERRORLED_BLINKING                                      4
#define ECAT_ERRORLED_SINGLE_FLASH                                  5
#define ECAT_ERRORLED_DOUBLE_FLASH                                  6
#define ECAT_ERRORLED_TRIPLE_FLASH                                  7
#define ECAT_ERRORLED_QUADRUPLE_FLASH                               8
#define ECAT_ERRORLED_QUINTUPLE_FLASH                               9

/* codes for parameters of "set configuration" packet */
#define ECAT_SET_CONFIG_COE                                         0x00000001
#define ECAT_SET_CONFIG_EOE                                         0x00000002
#define ECAT_SET_CONFIG_FOE                                         0x00000004
#define ECAT_SET_CONFIG_SOE                                         0x00000008
#define ECAT_SET_CONFIG_SYNCMODES                                   0x00000010
#define ECAT_SET_CONFIG_SYNCPDI                                     0x00000020
#define ECAT_SET_CONFIG_UID                                         0x00000040
#define ECAT_SET_CONFIG_AOE                                         0x00000080
#define ECAT_SET_CONFIG_BOOTMBX                                     0x00000100
#define ECAT_SET_CONFIG_DEVICEINFO                                  0x00000200
#define ECAT_SET_CONFIG_SMLENGTH                                    0x00000400

#define ECAT_SET_CONFIG_SYSTEMFLAGS_AUTOSTART                       0x00000000
#define ECAT_SET_CONFIG_SYSTEMFLAGS_APP_CONTROLLED                  0x00000001

#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDO                       0x01
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDOINFO                   0x02
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_PDOASSIGN                 0x04
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_PDOCONFIGURATION          0x08
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_UPLOAD                    0x10
#define ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDOCOMPLETEACCESS         0x20

#define ECAT_SET_CONFIG_COEFLAGS_USE_CUSTOM_OD                      0x01

#define ECAT_SET_CONFIG_SYNCPDI_SYNC0_OUTPUT_TYPE_MASK              0x01
#define ECAT_SET_CONFIG_SYNCPDI_SYNC0_POLARITY_MASK                 0x02
#define ECAT_SET_CONFIG_SYNCPDI_SYNC0_OUTPUT_ENABLE_MASK            0x04
#define ECAT_SET_CONFIG_SYNCPDI_SYNC0_IRQ_ENABLE_MASK               0x08
#define ECAT_SET_CONFIG_SYNCPDI_SYNC1_OUTPUT_TYPE_MASK              0x10
#define ECAT_SET_CONFIG_SYNCPDI_SYNC1_POLARITY_MASK                 0x20
#define ECAT_SET_CONFIG_SYNCPDI_SYNC1_OUTPUT_ENABLE_MASK            0x40
#define ECAT_SET_CONFIG_SYNCPDI_SYNC1_IRQ_ENABLE_MASK               0x80

/* DPM sync sources */
#define ECAT_DPM_SYNC_SOURCE_FREERUN                                0x00
#define ECAT_DPM_SYNC_SOURCE_SYNC0                                  0x02
#define ECAT_DPM_SYNC_SOURCE_SYNC1                                  0x03
#define ECAT_DPM_SYNC_SOURCE_SM2                                    0x22
#define ECAT_DPM_SYNC_SOURCE_SM3                                    0x23

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_SET_CONFIG_REQ                                         0x00002CCE
#define ECAT_SET_CONFIG_CNF                                         0x00002CCF

/*tell AP task time limit is reached*/
#define ECAT_CMD_LIMITATION_LIB_EXPIRED_IND                         0x00002CD2
#define ECAT_CMD_LIMITATION_LIB_EXPIRED_RES                         0x00002CD3
/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

typedef struct ECAT_READYWAIT_STATUS_tag
{
  uint32_t uReadyWaitBits;
} ECAT_READYWAIT_STATUS_T;

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_SET_CONFIG_REQ/
 * ECAT_SET_CONFIG_CNF
 */

/* basic configuration */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_REQ_DATA_BASIC_Ttag
{
  uint32_t ulSystemFlags;
  uint32_t ulWatchdogTime;
  uint32_t ulVendorId;
  uint32_t ulProductCode;
  uint32_t ulRevisionNumber;
  uint32_t ulSerialNumber;
  uint32_t ulProcessDataOutputSize;
  uint32_t ulProcessDataInputSize;
  uint32_t ulComponentInitialization;
  uint32_t ulExtensionNumber;
} ECAT_SET_CONFIG_REQ_DATA_BASIC_T;

/* component configuration */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_COE_Ttag
{
  uint8_t bCoeFlags;
  uint8_t bCoeDetails;
  uint32_t ulOdIndicationTimeout;
  uint32_t ulDeviceType;
  uint16_t usReserved;
} ECAT_SET_CONFIG_COE_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_EOE_Ttag
{
  uint32_t ulReserved;
} ECAT_SET_CONFIG_EOE_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_FOE_Ttag
{
  uint32_t ulTimeout;
} ECAT_SET_CONFIG_FOE_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_SOE_Ttag
{
  uint32_t ulIdnIndicationTimeout;
} ECAT_SET_CONFIG_SOE_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_SYNCMODES_Ttag
{
  uint8_t bPDInHskMode;
  uint8_t bPDInSource;
  uint16_t usPDInErrorTh;
  uint8_t bPDOutHskMode;
  uint8_t bPDOutSource;
  uint16_t usPDOutErrorTh;
  uint8_t bSyncHskMode;
  uint8_t bSyncSource;
  uint16_t usSyncErrorTh;
} ECAT_SET_CONFIG_SYNCMODES_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_SYNCPDI_Ttag
{
  uint8_t bSyncPdiConfig;
  uint16_t usSyncImpulseLength;
  uint8_t bReserved;
} ECAT_SET_CONFIG_SYNCPDI_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_UID_Ttag
{
  uint16_t usStationAlias;
  uint16_t usDeviceIdentificationValue;
} ECAT_SET_CONFIG_UID_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_BOOTMBX_Ttag
{
  uint16_t usBootstrapMbxSize;
} ECAT_SET_CONFIG_BOOTMBX_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_DEVICEINFO_Ttag
{
  uint8_t bGroupIdxLength;
  uint8_t szGroupIdx[127];     /* Matches ESI DeviceType:Group Type     */
  uint8_t bImageIdxLength;     /* reserved, set to 0 */
  uint8_t szImageIdx[255];     /* reserved */
  uint8_t bOrderIdxLength;
  uint8_t szOrderIdx[127];     /* Matches ESI DeviceType:Type           */
  uint8_t bNameIdxLength;
  uint8_t szNameIdx[127];      /* Matches ESI DeviceType:Name          */
} ECAT_SET_CONFIG_DEVICEINFO_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_SMLENGTH_Ttag
{
  uint16_t usMailboxSize;
  uint16_t usSM2StartAddress;
  uint16_t usSM3StartAddress;  /* should match (usProcDataSm2Start + 3 * ((usProcDataSm2Length + 3) & (~3)) <= usProcDataSm3Start)*/
} ECAT_SET_CONFIG_SMLENGTH_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_REQ_DATA_COMPONENTS_Ttag
{
  ECAT_SET_CONFIG_COE_T tCoECfg;
  ECAT_SET_CONFIG_EOE_T tEoECfg;
  ECAT_SET_CONFIG_FOE_T tFoECfg;
  ECAT_SET_CONFIG_SOE_T tSoECfg;
  ECAT_SET_CONFIG_SYNCMODES_T tSyncModesCfg;
  ECAT_SET_CONFIG_SYNCPDI_T tSyncPdiCfg;
  ECAT_SET_CONFIG_UID_T tUidCfg;
  ECAT_SET_CONFIG_BOOTMBX_T tBootMxbCfg;
  ECAT_SET_CONFIG_DEVICEINFO_T tDeviceInfoCfg;
  ECAT_SET_CONFIG_SMLENGTH_T tSmLengthCfg;
} ECAT_SET_CONFIG_REQ_DATA_COMPONENTS_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_REQ_DATA_Ttag
{
  ECAT_SET_CONFIG_REQ_DATA_BASIC_T tBasicCfg;
  ECAT_SET_CONFIG_REQ_DATA_COMPONENTS_T tComponentsCfg;
} ECAT_SET_CONFIG_REQ_DATA_T;

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SET_CONFIG_REQ_DATA_T tData;
} ECAT_SET_CONFIG_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SET_CONFIG_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_SET_CONFIG_CNF_T;

/*******************************************************************************

 #######
  #    #
  #
  #  #    #####  ### #
  ####   #     #  # # #
  #  #    ###     # # #
  #          ##   # # #
  #    # #     #  # # #
 #######  #####  ## # ##

*/

/******************************************************************************/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */

#define ECAT_ESM_FILTER_SIIWRITE_INDICATIONS_STATION_ALIAS          0x00000001

#define ECAT_ESM_SII_READ_DATA_BYTESIZE                             1024
#define ECAT_ESM_SII_WRITE_DATA_BYTESIZE                            1024

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ             0x00001B18
#define ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF             0x00001B19
#define ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_REQ          0x00001B1A
#define ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_CNF          0x00001B1B
#define ECAT_ESM_ALCONTROL_CHANGED_IND                              0x00001B1C
#define ECAT_ESM_ALCONTROL_CHANGED_RES                              0x00001B1D
#define ECAT_ESM_ALSTATUS_CHANGED_IND                               0x000019DE
#define ECAT_ESM_ALSTATUS_CHANGED_RES                               0x000019DF
#define ECAT_ESM_SET_ALSTATUS_REQ                                   0x00001B48
#define ECAT_ESM_SET_ALSTATUS_CNF                                   0x00001B49
#define ECAT_ESM_GET_ALSTATUS_REQ                                   0x00002CD0
#define ECAT_ESM_GET_ALSTATUS_CNF                                   0x00002CD1

#define ECAT_ESM_SII_READ_REQ                                       0x00001914
#define ECAT_ESM_SII_READ_CNF                                       0x00001915
#define ECAT_ESM_SII_WRITE_REQ                                      0x00001912
#define ECAT_ESM_SII_WRITE_CNF                                      0x00001913
#define ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ              0x00001B82
#define ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF              0x00001B83
#define ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_REQ           0x00001B84
#define ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_CNF           0x00001B85
#define ECAT_ESM_SII_WRITE_IND                                      0x00001B80
#define ECAT_ESM_SII_WRITE_RES                                      0x00001B81

#define ECAT_ESM_SII_SAFE_STATION_ADDRESS_REQ                       0x00001B90
#define ECAT_ESM_SII_SAFE_STATION_ADDRESS_CNF                       0x00001B91

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ALCONTROL_tag
{
  uint8_t uState                : 4;
  uint8_t fAcknowledge          : 1;
  uint8_t reserved              : 3;
  uint8_t bApplicationSpecific  : 8;
} ECAT_ALCONTROL_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ALSTATUS_Ttag
{
  uint8_t uState                : 4;
  uint8_t fChange               : 1;
  uint8_t reserved              : 3;
  uint8_t bApplicationSpecific  : 8;
} ECAT_ALSTATUS_T;

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ/
 * ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF
 */

/* request packet legacy */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_LEGACY_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_LEGACY_REQ_T;

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_DATA_Ttag
{
  uint32_t fEnableBootToInitHandling;
} ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_DATA_T  tData;
} ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T                       tHead;
  /* no data part */
} ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_REQ/
 * ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_UNREGISTER_FROM_ALCONTROL_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_ALCONTROL_CHANGED_IND/
 * ECAT_ESM_ALCONTROL_CHANGED_RES
 */

/* indication packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_ALCONTROL_CHANGED_IND_DATA_Ttag
{
  ECAT_ALCONTROL_T tAlControl;
  uint16_t usErrorLed;
  uint16_t usSyncControl;
  uint16_t usSyncImpulseLength;
  uint32_t ulSync0CycleTime;
  uint32_t ulSync1CycleTime;
  uint8_t bSyncPdiConfig;
  uint8_t bOriginState;
} ECAT_ESM_ALCONTROL_CHANGED_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_ALCONTROL_CHANGED_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_ALCONTROL_CHANGED_IND_DATA_T tData;
} ECAT_ESM_ALCONTROL_CHANGED_IND_T;

/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_ALCONTROL_CHANGED_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_ALCONTROL_CHANGED_RES_T;

/*******************************************************************************
 * ECAT_ESM_ALSTATUS_CHANGED_IND/
 * ECAT_ESM_ALSTATUS_CHANGED_RES
 */

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_ALSTATUS_CHANGED_IND_DATA_Ttag
{
  ECAT_ALSTATUS_T tAlStatus;
  uint16_t usErrorLed;
  uint16_t usAlStatusCode;
} ECAT_ESM_ALSTATUS_CHANGED_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_ALSTATUS_CHANGED_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_ALSTATUS_CHANGED_IND_DATA_T tData;
} ECAT_ESM_ALSTATUS_CHANGED_IND_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_ALSTATUS_CHANGED_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_ALSTATUS_CHANGED_RES_T;

/*******************************************************************************
 * ECAT_ESM_SET_ALSTATUS_REQ/
 * ECAT_ESM_SET_ALSTATUS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SET_ALSTATUS_REQ_DATA_Ttag
{
  uint8_t bAlStatus;
  uint8_t bErrorLedState;
  uint16_t usAlStatusCode;
} ECAT_ESM_SET_ALSTATUS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_CHANGE_SET_ALSTATUS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_SET_ALSTATUS_REQ_DATA_T tData;
} ECAT_ESM_SET_ALSTATUS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SET_ALSTATUS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_SET_ALSTATUS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_GET_ALSTATUS_REQ/
 * ECAT_ESM_GET_ALSTATUS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_GET_ALSTATUS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_GET_ALSTATUS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_GET_ALSTATUS_CNF_DATA_Ttag
{
  uint8_t bAlStatus;
  uint8_t bErrorLedState;
  uint16_t usAlStatusCode;
} ECAT_ESM_GET_ALSTATUS_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_GET_ALSTATUS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_GET_ALSTATUS_CNF_DATA_T tData;
} ECAT_ESM_GET_ALSTATUS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_SII_READ_REQ/
 * ECAT_ESM_SII_READ_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_READ_REQ_DATA_Ttag
{
  uint32_t ulOffset;
  uint32_t ulSize;
} ECAT_ESM_SII_READ_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_READ_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_SII_READ_REQ_DATA_T tData;
} ECAT_ESM_SII_READ_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_READ_CNF_DATA_Ttag
{
  uint8_t abData[ECAT_ESM_SII_READ_DATA_BYTESIZE];
} ECAT_ESM_SII_READ_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_READ_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_SII_READ_CNF_DATA_T tData;
} ECAT_ESM_SII_READ_CNF_T;


/*******************************************************************************
 * ECAT_ESM_SII_WRITE_REQ/
 * ECAT_ESM_SII_WRITE_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_WRITE_REQ_DATA_Ttag
{
  uint32_t ulOffset;
  uint8_t abData[ECAT_ESM_SII_WRITE_DATA_BYTESIZE];
} ECAT_ESM_SII_WRITE_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_WRITE_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_SII_WRITE_REQ_DATA_T tData;
} ECAT_ESM_SII_WRITE_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_WRITE_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_SII_WRITE_CNF_T;

/*******************************************************************************
 * ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ/
 * ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_DATA_Ttag
{
  uint32_t ulIndicationFlags;
} ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_DATA_T tData;
} ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_REGISTER_FOR_SIIWRITE_INDICATIONS_CNF_T;


/*******************************************************************************
 * ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_REQ/
 * ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_UNREGISTER_FROM_SIIWRITE_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_ESM_SII_WRITE_IND/
 * ECAT_ESM_SII_WRITE_RES
 */

/* indication packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_WRITE_IND_DATA_Ttag
{
  uint32_t ulSiiWriteStartAddress;
  uint8_t abData[2];
} ECAT_ESM_SII_WRITE_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_WRITE_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_ESM_SII_WRITE_IND_DATA_T tData;
} ECAT_ESM_SII_WRITE_IND_T;

/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_ESM_SII_WRITE_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_ESM_SII_WRITE_RES_T;


/*******************************************************************************


 #####   ######  ##   ##
  #   #   #    #  #   #
  #    #  #    #  ## ##
  #    #  #    #  ## ##
  #    #  #####   # # #
  #    #  #       # # #
  #    #  #       #   #
  #   #   #       #   #
 #####   ####    ### ###


*/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */
#define PID_ECS_DEVICE_IDENTIFICATION 0x30009001    /* { UINT16 usDeviceIdentification; UINT16 usPadding; } */
#define PID_ECS_SCND_STATION_ADDRESS  0x30009002    /* { UINT16 usScndStationAddress; UINT16 usPadding; } */

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_DPM_SET_IO_SIZE_REQ                                    0x00002CC0
#define ECAT_DPM_SET_IO_SIZE_CNF                                    0x00002CC1
#define ECAT_DPM_SET_STATION_ALIAS_REQ                              0x00002CC6
#define ECAT_DPM_SET_STATION_ALIAS_CNF                              0x00002CC7
#define ECAT_DPM_GET_STATION_ALIAS_REQ                              0x00002CC8
#define ECAT_DPM_GET_STATION_ALIAS_CNF                              0x00002CC9

#define ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_REQ                    0x00002600
#define ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_CNF                    0x00002601

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_REQ/
 * ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_REQ_DATA_Ttag
{
  uint32_t ulBitPosition; /* if it exceeds the SM3 length it will be disabled */
} ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_REQ_DATA_T tData;
} ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_DPM_SET_NEW_MSG_AVAIL_TX_BITPOS_CNF_T;

/*******************************************************************************
 * ECAT_DPM_SET_IO_SIZE_REQ/
 * ECAT_DPM_SET_IO_SIZE_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_IO_SIZE_REQ_DATA_Ttag
{
  uint32_t ulProcessDataOutputSize;
  uint32_t ulProcessDataInputSize;
} ECAT_DPM_SET_IO_SIZE_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_IO_SIZE_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_DPM_SET_IO_SIZE_REQ_DATA_T tData;
} ECAT_DPM_SET_IO_SIZE_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_IO_SIZE_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_DPM_SET_IO_SIZE_CNF_T;

/*******************************************************************************
 * ECAT_DPM_SET_STATION_ALIAS_REQ/
 * ECAT_DPM_SET_STATION_ALIAS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_STATION_ALIAS_REQ_DATA_Ttag
{
  uint16_t usStationAlias;
} ECAT_DPM_SET_STATION_ALIAS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_STATION_ALIAS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_DPM_SET_STATION_ALIAS_REQ_DATA_T tData;
} ECAT_DPM_SET_STATION_ALIAS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_SET_STATION_ALIAS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_DPM_SET_STATION_ALIAS_CNF_T;

/*******************************************************************************
 * ECAT_DPM_GET_STATION_ALIAS_REQ/
 * ECAT_DPM_GET_STATION_ALIAS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_GET_STATION_ALIAS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_DPM_GET_STATION_ALIAS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_GET_STATION_ALIAS_CNF_DATA_Ttag
{
  uint16_t usStationAlias;
} ECAT_DPM_GET_STATION_ALIAS_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_DPM_GET_STATION_ALIAS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_DPM_GET_STATION_ALIAS_CNF_DATA_T tData;
} ECAT_DPM_GET_STATION_ALIAS_CNF_T;



/*******************************************************************************


   ####          #######
  #    #          #    #
 #                #
 #        #####   #  #
 #       #     #  ####
 #       #     #  #  #
 #       #     #  #
  #    # #     #  #    #
   ####   #####  #######


*/

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_COE_SEND_EMERGENCY_REQ                                 0x00001994
#define ECAT_COE_SEND_EMERGENCY_CNF                                 0x00001995

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_COE_SEND_EMERGENCY_REQ/
 * ECAT_COE_SEND_EMERGENCY_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_COE_SEND_EMERGENCY_REQ_DATA_Ttag
{
  uint16_t usStationAddress;
  uint16_t usPriority;
  uint16_t usErrorCode;
  uint8_t bErrorRegister;
  uint8_t abDiagnosticData[5];
} ECAT_COE_SEND_EMERGENCY_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_COE_SEND_EMERGENCY_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_COE_SEND_EMERGENCY_REQ_DATA_T tData;
} ECAT_COE_SEND_EMERGENCY_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_COE_SEND_EMERGENCY_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_COE_SEND_EMERGENCY_CNF_T;

/*******************************************************************************

 #######          #######
  #    #           #    #
  #                #
  #  #     #####   #  #
  ####    #     #  ####
  #  #    #     #  #  #
  #       #     #  #
  #    #  #     #  #    #
 #######   #####  #######

*/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */

#define ECAT_EOE_FRAME_DATA_SIZE                                    1504
#define ECAT_EOE_FRAME_HEADER_SIZE                                  14

#define ECAT_EOE_FRAME_FLAG_TIME_REQUEST                            0x0001
#define ECAT_EOE_FRAME_FLAG_TIME_VALID                              0x0002

#define ECAT_EOE_SET_IP_PARAM_MAC_ADDRESS_INCLUDED                  0x00000001
#define ECAT_EOE_SET_IP_PARAM_IP_ADDRESS_INCLUDED                   0x00000002
#define ECAT_EOE_SET_IP_PARAM_SUBNET_MASK_INCLUDED                  0x00000004
#define ECAT_EOE_SET_IP_PARAM_DEFAULT_GATEWAY_INCLUDED              0x00000008
#define ECAT_EOE_SET_IP_PARAM_DNS_SERVER_IP_ADDR_INCLUDED           0x00000010
#define ECAT_EOE_SET_IP_PARAM_DNS_NAME_INCLUDED                     0x00000020

#define ECAT_EOE_GET_IP_PARAM_MAC_ADDRESS_INCLUDED                  0x00000001
#define ECAT_EOE_GET_IP_PARAM_IP_ADDRESS_INCLUDED                   0x00000002
#define ECAT_EOE_GET_IP_PARAM_SUBNET_MASK_INCLUDED                  0x00000004
#define ECAT_EOE_GET_IP_PARAM_DEFAULT_GATEWAY_INCLUDED              0x00000008
#define ECAT_EOE_GET_IP_PARAM_DNS_SERVER_IP_ADDR_INCLUDED           0x00000010
#define ECAT_EOE_GET_IP_PARAM_DNS_NAME_INCLUDED                     0x00000020

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ                 0x00001B76
#define ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_CNF                 0x00001B77
#define ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_REQ              0x00001B78
#define ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_CNF              0x00001B79
#define ECAT_EOE_SEND_FRAME_REQ                                     0x00001B72
#define ECAT_EOE_SEND_FRAME_CNF                                     0x00001B73
#define ECAT_EOE_FRAME_RECEIVED_IND                                 0x00001B70
#define ECAT_EOE_FRAME_RECEIVED_RES                                 0x00001B71
#define ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_REQ              0x00001B7A
#define ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_CNF              0x00001B7B
#define ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_REQ           0x00001B7C
#define ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_CNF           0x00001B7D
#define ECAT_EOE_SET_IP_PARAM_IND                                   0x00001B7E
#define ECAT_EOE_SET_IP_PARAM_RES                                   0x00001B7F
#define ECAT_EOE_GET_IP_PARAM_IND                                   0x00001B50
#define ECAT_EOE_GET_IP_PARAM_RES                                   0x00001B51

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 * ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ/
 * ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_REGISTER_FOR_FRAME_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_REQ/
 * ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_REQ_T;


/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_UNREGISTER_FROM_FRAME_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_REQ/
 * ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_REGISTER_FOR_IP_PARAM_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_REQ/
 * ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_UNREGISTER_FROM_IP_PARAM_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_EOE_SET_IP_PARAM_IND/
 * ECAT_EOE_SET_IP_PARAM_RES
 */

/* indication packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_SET_IP_PARAM_IND_DATA_Ttag
{
  uint32_t ulFlags;
  uint8_t abMacAddr[6];
  uint8_t abIpAddr[4];
  uint8_t abSubnetMask[4];
  uint8_t abDefaultGateway[4];
  uint8_t abDnsServerIpAddress[4];
  uint8_t abDnsName[32];
} ECAT_EOE_SET_IP_PARAM_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_SET_IP_PARAM_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_EOE_SET_IP_PARAM_IND_DATA_T tData;
} ECAT_EOE_SET_IP_PARAM_IND_T;

/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_SET_IP_PARAM_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_SET_IP_PARAM_RES_T;

/*******************************************************************************
 * ECAT_EOE_GET_IP_PARAM_IND/
 * ECAT_EOE_GET_IP_PARAM_RES
 */

/* indication packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_GET_IP_PARAM_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  /* no data part */
} ECAT_EOE_GET_IP_PARAM_IND_T;

/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_GET_IP_PARAM_RES_DATA_Ttag
{
  uint32_t ulFlags;
  uint8_t abMacAddr[6];
  uint8_t abIpAddr[4];
  uint8_t abSubnetMask[4];
  uint8_t abDefaultGateway[4];
  uint8_t abDnsServerIpAddress[4];
  uint8_t abDnsName[32];
} ECAT_EOE_GET_IP_PARAM_RES_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_GET_IP_PARAM_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_EOE_GET_IP_PARAM_RES_DATA_T tData;
} ECAT_EOE_GET_IP_PARAM_RES_T;

/*******************************************************************************
 * ECAT_EOE_SEND_FRAME_REQ/
 * ECAT_EOE_SEND_FRAME_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_SEND_FRAME_REQ_DATA_Ttag
{
  uint16_t usFlags;
  uint16_t usPortNo;
  uint32_t ulTimestampNs;
  uint8_t abDstMacAddr[6];
  uint8_t abSrcMacAddr[6];
  uint16_t usEthType;
  uint8_t abData[ECAT_EOE_FRAME_DATA_SIZE];
} ECAT_EOE_SEND_FRAME_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_SEND_FRAME_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_EOE_SEND_FRAME_REQ_DATA_T tData;
} ECAT_EOE_SEND_FRAME_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_SEND_FRAME_CNF_DATA_Ttag
{
  uint16_t usFlags;
  uint32_t ulTimestampNs;
  uint16_t usFrameLen;
} ECAT_EOE_SEND_FRAME_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_SEND_FRAME_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_EOE_SEND_FRAME_CNF_DATA_T tData;
} ECAT_EOE_SEND_FRAME_CNF_T;

/*******************************************************************************
 * ECAT_EOE_FRAME_RECEIVED_IND/
 * ECAT_EOE_FRAME_RECEIVED_RES
 */

/* indication packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_FRAME_RECEIVED_IND_DATA_Ttag
{
  uint16_t usFlags;
  uint16_t usPortNo;
  uint32_t ulTimestampNs;
  uint8_t abDstMacAddr[6];
  uint8_t abSrcMacAddr[6];
  uint16_t usEthType;
  uint8_t abData[ECAT_EOE_FRAME_DATA_SIZE];
} ECAT_EOE_FRAME_RECEIVED_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_FRAME_RECEIVED_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_EOE_FRAME_RECEIVED_IND_DATA_T tData;
} ECAT_EOE_FRAME_RECEIVED_IND_T;

/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_FRAME_RECEIVED_RES_DATA_Ttag
{
  uint16_t usFlags;
  uint32_t ulTimestampNs;
  uint16_t usFrameLen;
} ECAT_EOE_FRAME_RECEIVED_RES_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_EOE_FRAME_RECEIVED_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_EOE_FRAME_RECEIVED_RES_DATA_T tData;
} ECAT_EOE_FRAME_RECEIVED_RES_T;


/*******************************************************************************


  #####          #######
 #     #          #    #
 #                #
 #        #####   #  #
  #####  #     #  ####
       # #     #  #  #
       # #     #  #
 #     # #     #  #    #
  #####   #####  #######


*/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
 */
#define ECAT_SOE_IDN_PROCESS_QUEUE_NAME                             "ECAT_SOEIDN_QUE"

#define ECAT_SOEIDN_CREATE_IDN_MIN_DATA_SIZE                        (sizeof(ECAT_SOEIDN_CREATE_IDN_REQ_DATA_T) - sizeof(((ECAT_SOEIDN_CREATE_IDN_REQ_DATA_T*)0)->abData))
#define ECAT_SOEIDN_SET_IDN_NAME_REQ_MIN_SIZE                       (3 * sizeof(uint16_t) + sizeof(uint8_t))
#define ECAT_SOEIDN_SET_IDN_UNIT_REQ_MIN_SIZE                       (3 * sizeof(uint16_t) + sizeof(uint8_t))
#define ECAT_SOE_READ_RES_MIN_SIZE                                  sizeof(uint16_t)
#define ECAT_SOE_READ_CNF_MIN_SIZE                                  sizeof(uint16_t)
#define ECAT_SOE_WRITE_IND_MIN_SIZE                             (sizeof(uint16_t) + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint16_t))
#define ECAT_SOE_WRITE_REQ_MIN_SIZE                             (sizeof(uint16_t) + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint16_t))

/* following values are appended in order of their definition to abData */
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_DATASTATE             0x01
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_NAME                  0x02
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_UNIT                  0x04
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_MINIMUM               0x08
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_MAXIMUM               0x10
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_VALUE                 0x20
#define MSK_ECAT_SOEIDN_CREATE_IDN_VALUE_INFO_DEFVALUE              0x40

/* definitions for bElement */
#define ECAT_SOE_IDN_ELEMENT_DATASTATE                              1
#define ECAT_SOE_IDN_ELEMENT_NAME                                   2
#define ECAT_SOE_IDN_ELEMENT_ATTRIBUTE                              3
#define ECAT_SOE_IDN_ELEMENT_UNIT                                   4
#define ECAT_SOE_IDN_ELEMENT_MINIMUM_VALUE                          5
#define ECAT_SOE_IDN_ELEMENT_MAXIMUM_VALUE                          6
#define ECAT_SOE_IDN_ELEMENT_OPDATA                                 7
#define ECAT_SOE_IDN_ELEMENT_DEFAULT_VALUE                          8

/* definitions for usDataStatus */
#define MSK_ECAT_SOE_IDN_DATA_STATUS_OPDATA_INVALID                 0x0100
#define MSK_ECAT_SOE_IDN_DATA_STATUS_COMMAND_ERROR                  0x0008
#define MSK_ECAT_SOE_IDN_DATA_STATUS_COMMAND_NOT_EXECUTED           0x0004
#define MSK_ECAT_SOE_IDN_DATA_STATUS_COMMAND_EXECUTION_ENABLED      0x0002
#define MSK_ECAT_SOE_IDN_DATA_STATUS_COMMAND_SET                    0x0001

/* definitions for ulAttribute */
#define MSK_ECAT_SOE_IDN_ATTR_OPDATA_WRITE_PROTECTED_IN_CP4         0x40000000
#define MSK_ECAT_SOE_IDN_ATTR_OPDATA_WRITE_PROTECTED_IN_CP3         0x20000000
#define MSK_ECAT_SOE_IDN_ATTR_OPDATA_WRITE_PROTECTED_IN_CP2         0x10000000

#define MSK_ECAT_SOE_IDN_ATTR_DECIMAL_PLACEMENT                     0x0F000000
#define SRT_ECAT_SOE_IDN_ATTR_DECIMAL_PLACEMENT                     24

#define MSK_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT                        0x00700000
#define SRT_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT                        20
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_BINARY                 0x00000000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_UNSIGNED_DECIMAL       0x00100000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_SIGNED_DECIMAL         0x00200000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_UNSIGNED_HEXADECIMAL   0x00300000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_TEXT                   0x00400000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_IDN                    0x00500000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_FLOATING_POINT         0x00600000
#define VAL_ECAT_SOE_IDN_ATTR_DISPLAY_FORMAT_RESERVED               0x00700000

#define MSK_ECAT_SOE_IDN_ATTR_OPDATA_IS_PROC_CMD                    0x00080000

#define MSK_ECAT_SOE_IDN_ATTR_DATA_LENGTH                           0x00070000
#define SRT_ECAT_SOE_IDN_ATTR_DATA_LENGTH                           16
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_RESERVED0                 0x00000000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_TWO_BYTE                  0x00010000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_FOUR_BYTE                 0x00020000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_EIGHT_BYTE                0x00030000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_ONE_BYTE_LIST             0x00040000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_TWO_BYTE_LIST             0x00050000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_FOUR_BYTE_LIST            0x00060000
#define VAL_ECAT_SOE_IDN_ATTR_DATA_LENGTH_EIGHT_BYTE_LIST           0x00070000
#define MSK_ECAT_SOE_IDN_ATTR_DATA_LENGTH_IS_LIST                   0x00040000

#define MSK_ECAT_SOE_IDN_ATTR_SCALING                               0x0000FFFF
#define SRT_ECAT_SOE_IDN_ATTR_SCALING                               0

/* -----------------------------------------------------------------------------
 *  commands
 * -----------------------------------------------------------------------------
 */
#define ECAT_SOEIDN_CREATE_IDN_REQ                                  0x00005840
#define ECAT_SOEIDN_CREATE_IDN_CNF                                  0x00005841
#define ECAT_SOEIDN_DELETE_IDN_REQ                                  0x00005842
#define ECAT_SOEIDN_DELETE_IDN_CNF                                  0x00005843
#define ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ                0x00005844
#define ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF                0x00005845
#define ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ             0x00005846
#define ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF             0x00005847
#define ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ      0x00005848
#define ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF      0x00005849
#define ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ   0x0000584A
#define ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF   0x0000584B
#define ECAT_SOEIDN_SET_IDN_NAME_REQ                                0x0000584C
#define ECAT_SOEIDN_SET_IDN_NAME_CNF                                0x0000584D
#define ECAT_SOEIDN_SET_IDN_UNIT_REQ                                0x0000584E
#define ECAT_SOEIDN_SET_IDN_UNIT_CNF                                0x0000584F

#define ECAT_SOE_READ_REQ                                       0x00005802
#define ECAT_SOE_READ_CNF                                       0x00005803
#define ECAT_SOE_READ_IND                                       0x00005802
#define ECAT_SOE_READ_RES                                       0x00005803
#define ECAT_SOE_WRITE_REQ                                      0x00005800
#define ECAT_SOE_WRITE_CNF                                      0x00005801
#define ECAT_SOE_WRITE_IND                                      0x00005800
#define ECAT_SOE_WRITE_RES                                      0x00005801

#define ECAT_SOE_PROCCMD_NOTIFY_REQ                                 0x00005810
#define ECAT_SOE_PROCCMD_NOTIFY_CNF                                 0x00005811

/* -----------------------------------------------------------------------------
 *  types
 * -----------------------------------------------------------------------------
 */

/* -----------------------------------------------------------------------------
 *  packets
 * -----------------------------------------------------------------------------
 */

/*******************************************************************************
 *  ECAT_SOEIDN_CREATE_IDN_REQ/
 *  ECAT_SOEIDN_CREATE_IDN_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_CREATE_IDN_REQ_DATA_Ttag
{
  /* unfragmentable part */
  uint32_t ulTotalLength;
  uint16_t usIdn;
  uint16_t usMaxListDataSize;
  uint32_t ulAttribute;
  uint8_t bDriveNo;
  uint8_t bValueInfo;
  uint16_t usMaxNameLength;
  uint16_t usMaxUnitLength;
  /* fragmentable part */
  uint8_t abData[1];
} ECAT_SOEIDN_CREATE_IDN_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_CREATE_IDN_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_CREATE_IDN_REQ_DATA_T tData;
} ECAT_SOEIDN_CREATE_IDN_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_CREATE_IDN_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_SOEIDN_CREATE_IDN_CNF_T;

/*******************************************************************************
 *  ECAT_SOEIDN_DELETE_IDN_REQ/
 *  ECAT_SOEIDN_DELETE_IDN_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_DELETE_IDN_REQ_DATA_Ttag
{
  uint16_t usIdn;
  uint8_t bDriveNo;
} ECAT_SOEIDN_DELETE_IDN_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_DELETE_IDN_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_DELETE_IDN_REQ_DATA_T tData;
} ECAT_SOEIDN_DELETE_IDN_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_DELETE_IDN_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_SOEIDN_DELETE_IDN_CNF_T;

/*******************************************************************************
 * ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ/
 * ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_DATA_Ttag
{
  uint16_t usIdn;
  uint8_t bDriveNo;
  uint8_t fReadNotify;
  uint8_t fWriteNotify;
} ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_DATA_T tData;
} ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_DATA_Ttag
{
  uint16_t usIdn;
  uint8_t bDriveNo;
} ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_DATA_T tData;
} ECAT_SOEIDN_REGISTER_FOR_IDN_INDICATIONS_CNF_T;

/*******************************************************************************
 *  ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ/
 *  ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_DATA_Ttag
{
  uint16_t usIdn;
  uint8_t bDriveNo;
} ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_DATA_T tData;
} ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_DATA_Ttag
{
  uint16_t usIdn;
  uint8_t bDriveNo;
} ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_DATA_T tData;
} ECAT_SOEIDN_UNREGISTER_FROM_IDN_INDICATIONS_CNF_T;

/*******************************************************************************
 *  ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ/
 *  ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_DATA_Ttag
{
  uint8_t bDriveNo;
} ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_DATA_T tData;
} ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_DATA_Ttag
{
  uint8_t bDriveNo;
} ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_DATA_T tData;
} ECAT_SOEIDN_REGISTER_FOR_UNDEFINED_IDN_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ/
 * ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_DATA_Ttag
{
  uint8_t bDriveNo;
} ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_DATA_T tData;
} ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_DATA_Ttag
{
  uint8_t bDriveNo;
} ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_DATA_T tData;
} ECAT_SOEIDN_UNREGISTER_FROM_UNDEFINED_IDN_INDICATIONS_CNF_T;

/*******************************************************************************
 * ECAT_SOEIDN_SET_NAME_REQ/
 * ECAT_SOEIDN_SET_NAME_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_SET_IDN_NAME_REQ_DATA_Ttag
{
  uint8_t bDriveNo;
  uint16_t usIdn;
  uint16_t usNameLength;
  uint16_t usPad;
  uint8_t szName[256];
} ECAT_SOEIDN_SET_IDN_NAME_REQ_DATA_T;

typedef  __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_SET_IDN_NAME_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_SET_IDN_NAME_REQ_DATA_T tData;
} ECAT_SOEIDN_SET_IDN_NAME_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_SET_IDN_NAME_CNF_DATA_Ttag
{
  uint8_t bDriveNo;
  uint16_t usIdn;
} ECAT_SOEIDN_SET_IDN_NAME_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_SET_IDN_NAME_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_SET_IDN_NAME_CNF_DATA_T tData;
} ECAT_SOEIDN_SET_IDN_NAME_CNF_T;

/*******************************************************************************
 * ECAT_SOEIDN_SET_UNIT_REQ/
 * ECAT_SOEIDN_SET_UNIT_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_SET_IDN_UNIT_REQ_DATA_Ttag
{
  uint8_t bDriveNo;
  uint16_t usIdn;
  uint16_t usUnitLength;
  uint16_t usPad;
  uint8_t szUnit[256];
} ECAT_SOEIDN_SET_IDN_UNIT_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_SET_IDN_UNIT_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_SET_IDN_UNIT_REQ_DATA_T tData;
} ECAT_SOEIDN_SET_IDN_UNIT_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_SET_IDN_UNIT_CNF_DATA_Ttag
{
  uint8_t bDriveNo;
  uint16_t usIdn;
} ECAT_SOEIDN_SET_IDN_UNIT_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOEIDN_SET_IDN_UNIT_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOEIDN_SET_IDN_UNIT_CNF_DATA_T tData;
} ECAT_SOEIDN_SET_IDN_UNIT_CNF_T;

/*******************************************************************************
 * ECAT_SOE_READ_REQ/
 * ECAT_SOE_READ_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_READ_REQ_DATA_Ttag
{
  uint16_t usIdn;
  uint8_t bElement;
  uint8_t bDriveNo;
  uint16_t usMaxReadLength;
} ECAT_SOE_READ_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_READ_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOE_READ_REQ_DATA_T tData;
} ECAT_SOE_READ_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_READ_CNF_DATA_Ttag
{
  /* unfragmentable part */
  uint16_t usTotalLength;
  /* fragmentable part */
  uint8_t abData[1];
} ECAT_SOE_READ_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_READ_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOE_READ_CNF_DATA_T tData;
} ECAT_SOE_READ_CNF_T;

/*******************************************************************************
 * ECAT_SOE_READ_IND/
 * ECAT_SOE_READ_RES
 */

/* indication packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_READ_IND_DATA_Ttag
{
  uint16_t usIdn;
  uint8_t bElement;
  uint8_t bDriveNo;
  uint16_t usMaxReadLength;
} ECAT_SOE_READ_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_READ_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOE_READ_IND_DATA_T tData;
} ECAT_SOE_READ_IND_T;

/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_READ_RES_DATA_Ttag
{
  /* unfragmentable part */
  uint16_t usTotalLength;
  /* fragmentable part */
  uint8_t abData[1];
} ECAT_SOE_READ_RES_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_READ_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOE_READ_RES_DATA_T tData;
} ECAT_SOE_READ_RES_T;

/* packet union */
typedef union ECAT_SOE_READ_PCK_Ttag
{
  HIL_PACKET_HEADER_T tHead;

  /* indication packet */
  ECAT_SOE_READ_IND_T tInd;
  ECAT_SOE_READ_RES_T tRes;

  /* request packet */
  ECAT_SOE_READ_REQ_T tReq;
  ECAT_SOE_READ_CNF_T tCnf;
} ECAT_SOE_READ_PCK_T;

/*******************************************************************************
 * ECAT_SOE_WRITE_IDN_REQ/
 * ECAT_SOE_WRITE_IDN_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_WRITE_REQ_DATA_Ttag
{
  /* unfragmentable part */
  uint16_t usIdn;
  uint8_t bElement;
  uint8_t bDriveNo;
  uint16_t usTotalLength;
  /* fragmentable part */
  uint8_t abData[1];
} ECAT_SOE_WRITE_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_WRITE_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOE_WRITE_REQ_DATA_T tData;
} ECAT_SOE_WRITE_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_WRITE_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_SOE_WRITE_CNF_T;

/*******************************************************************************
 * ECAT_SOE_WRITE_IND/
 * ECAT_SOE_WRITE_RES
 */

/* indication packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_WRITE_IND_DATA_Ttag
{
  /* unfragmentable part */
  uint16_t usIdn;
  uint8_t bElement;
  uint8_t bDriveNo;
  uint16_t usTotalLength;
  /* fragmentable part */
  uint8_t abData[1];
} ECAT_SOE_WRITE_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_WRITE_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOE_WRITE_IND_DATA_T tData;
} ECAT_SOE_WRITE_IND_T;

/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_WRITE_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_SOE_WRITE_RES_T;


/* packet union */
typedef union ECAT_SOE_WRITE_PCK_Ttag
{
  HIL_PACKET_HEADER_T tHead;

  /* indication packet */
  ECAT_SOE_WRITE_IND_T tInd;
  ECAT_SOE_WRITE_RES_T tRes;

  /* request packet */
  ECAT_SOE_WRITE_REQ_T tReq;
  ECAT_SOE_WRITE_CNF_T tCnf;
} ECAT_SOE_WRITE_PCK_T;

/*******************************************************************************
 * ECAT_SOE_PROCCMD_NOTIFY_REQ/
 * ECAT_SOE_PROCCMD_NOTIFY_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_PROCCMD_NOTIFY_REQ_DATA_Ttag
{
  uint16_t usIdn;
  uint8_t bDriveNo;
  uint16_t usDataState;
} ECAT_SOE_PROCCMD_NOTIFY_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_PROCCMD_NOTIFY_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_SOE_PROCCMD_NOTIFY_REQ_DATA_T tData;
} ECAT_SOE_PROCCMD_NOTIFY_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_SOE_PROCCMD_NOTIFY_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_SOE_PROCCMD_NOTIFY_CNF_T;


/*******************************************************************************


   ###           #######
  #   #           #    #
 #     #          #
 #     #  #####   #  #
 ####### #     #  ####
 #     # #     #  #  #
 #     # #     #  #
 #     # #     #  #    #
 #     #  #####  #######


*/

/* defines */
#define ECS_AOE_REGISTER_PORT_REQ             0x8D00
#define ECS_AOE_REGISTER_PORT_CNF             0x8D01

#define ECS_AOE_UNREGISTER_PORT_REQ           0x8D02
#define ECS_AOE_UNREGISTER_PORT_CNF           0x8D03

/*******************************************************************************
 * ECS_AOE_REGISTER_PORT_REQ/
 * ECS_AOE_REGISTER_PORT_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECS_AOE_REGISTER_PORT_REQ_DATA_Ttag
{
  uint16_t usPort;
  uint32_t ulPortFlags;
} ECS_AOE_REGISTER_PORT_REQ_DATA_T;

#define MSK_ECS_AOE_PORT_FLAGS_SDO            0x00000001
#define MSK_ECS_AOE_PORT_FLAGS_SDOINFO        0x00000002

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECS_AOE_REGISTER_PORT_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECS_AOE_REGISTER_PORT_REQ_DATA_T tData;
} ECS_AOE_REGISTER_PORT_REQ_T;


/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECS_AOE_REGISTER_PORT_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECS_AOE_REGISTER_PORT_CNF_T;

/*******************************************************************************
 * ECS_AOE_UNREGISTER_PORT_REQ/
 * ECS_AOE_UNREGISTER_PORT_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECS_AOE_UNREGISTER_PORT_REQ_DATA_Ttag
{
  uint16_t usPort;
} ECS_AOE_UNREGISTER_PORT_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECS_AOE_UNREGISTER_PORT_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECS_AOE_UNREGISTER_PORT_REQ_DATA_T tData;
} ECS_AOE_UNREGISTER_PORT_REQ_T;


/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECS_AOE_UNREGISTER_PORT_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECS_AOE_UNREGISTER_PORT_CNF_T;


/*******************************************************************************


 #######          #######
 #                #
 #                #
 #        #####   #  #
 ####### #     #  ####
 #       #     #  #  #
 #       #     #  #
 #       #     #  #    #
 #        #####  #######


*/

/* commands */

#define ECAT_FOE_SET_OPTIONS_REQ 0x1BD6
#define ECAT_FOE_SET_OPTIONS_CNF 0x1BD7

#define ECAT_FOE_REGISTER_FILE_INDICATIONS_REQ 0x9500
#define ECAT_FOE_REGISTER_FILE_INDICATIONS_CNF 0x9501

#define ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ 0x9502
#define ECAT_FOE_UNREGISTER_FILE_INDICATIONS_CNF 0x9503

#define ECAT_FOE_WRITE_FILE_IND 0x9510
#define ECAT_FOE_WRITE_FILE_RES 0x9511

#define ECAT_FOE_READ_FILE_IND 0x9512
#define ECAT_FOE_READ_FILE_RES 0x9513

#define ECAT_FOE_MAX_FILE_NAME_LENGTH 256


/******************************************************************************
 * Packet:  ECAT_FOE_SET_OPTIONS_REQ/ECAT_FOE_SET_OPTIONS_CNF
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_SET_OPTIONS_REQ_DATA_Ttag
{
  uint32_t ulOptions;
  uint16_t usExpectedBuildDeviceVariant;
} ECAT_FOE_SET_OPTIONS_REQ_DATA_T;

/* ulOptions */
#define ECAT_FOE_SET_OPTIONS_CHECK_PROTOCOL_CLASS                   0x00000001
#define ECAT_FOE_SET_OPTIONS_CHECK_COMMUNICATION_CLASS              0x00000002
#define ECAT_FOE_SET_OPTIONS_REJECT_NON_NXF_FILE_DOWNLOADS          0x00000004
#define ECAT_FOE_SET_OPTIONS_CHECK_VARIANT                          0x00000008
#define ECAT_FOE_SET_OPTIONS_CHECK_DEVICE_CLASS                     0x00000010

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_SET_OPTIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_SET_OPTIONS_REQ_DATA_T tData;
} ECAT_FOE_SET_OPTIONS_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_SET_OPTIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_FOE_SET_OPTIONS_CNF_T;


/******************************************************************************
 * Packet:  ECAT_FOE_REGISTER_FILE_INDICATIONS_REQ/ECAT_FOE_REGISTER_FILE_INDICATIONS_CNF
 */

#define ECAT_FOE_INDICATION_TYPE_VIRTUAL_FILE 3

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_REGISTER_FILE_INDICATIONS_REQ_DATA_Ttag
{
  uint8_t bIndicationType;
  uint8_t abFilename[ECAT_FOE_MAX_FILE_NAME_LENGTH];
} ECAT_FOE_REGISTER_FILE_INDICATIONS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_REGISTER_FILE_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_REGISTER_FILE_INDICATIONS_REQ_DATA_T tData;
} ECAT_FOE_REGISTER_FILE_INDICATIONS_REQ_T;


/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_REGISTER_FILE_INDICATIONS_CNF_DATA_Ttag
{
  uint32_t ulHandle;
} ECAT_FOE_REGISTER_FILE_INDICATIONS_CNF_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_REGISTER_FILE_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_REGISTER_FILE_INDICATIONS_CNF_DATA_T tData;
} ECAT_FOE_REGISTER_FILE_INDICATIONS_CNF_T;


/* packet union */
typedef union ECAT_FOE_REGISTER_FILE_INDICATIONS_PCK_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_REGISTER_FILE_INDICATIONS_REQ_T tReq;
  ECAT_FOE_REGISTER_FILE_INDICATIONS_CNF_T tCnf;
} ECAT_FOE_REGISTER_FILE_INDICATIONS_PCK_T;


/******************************************************************************
 * Packet:  ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ/ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ_DATA_Ttag
{
  uint32_t ulHandle;
} ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ_DATA_T tData;
} ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ_T;


/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_UNREGISTER_FILE_INDICATIONS_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_FOE_UNREGISTER_FILE_INDICATIONS_CNF_T;


/* packet union */
typedef union ECAT_FOE_UNREGISTER_FILE_INDICATIONS_PCK_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_UNREGISTER_FILE_INDICATIONS_REQ_T tReq;
  ECAT_FOE_UNREGISTER_FILE_INDICATIONS_CNF_T tCnf;
} ECAT_FOE_UNREGISTER_FILE_INDICATIONS_PCK_T;


/******************************************************************************
 * Packet:  ECAT_FOE_WRITE_FILE_IND/ECAT_FOE_WRITE_FILE_RES
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_WRITE_FILE_IND_DATA_Ttag
{
  uint8_t abData[1024]; /* may be larger depending on foreign queue size */
  /* first packet contains password and filename in abData, following packets have data */
  /* last segment is signaled when ulExt.Seq is set to LAST, can have zero bytes of data */
  /* middle segment is signaled when ulExt.Seq is set to MIDDLE */
} ECAT_FOE_WRITE_FILE_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_WRITE_FILE_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_WRITE_FILE_IND_DATA_T tData;
} ECAT_FOE_WRITE_FILE_IND_T;


/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_WRITE_FILE_RES_DATA_Ttag
{
  uint8_t abText[1024]; /* only valid when packet status != 0 */
} ECAT_FOE_WRITE_FILE_RES_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_WRITE_FILE_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_WRITE_FILE_RES_DATA_T tData;
} ECAT_FOE_WRITE_FILE_RES_T;


/* packet union */
typedef union ECAT_FOE_WRITE_FILE_PCK_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_WRITE_FILE_IND_T tInd;
  ECAT_FOE_WRITE_FILE_RES_T tRes;
} ECAT_FOE_WRITE_FILE_PCK_T;


/******************************************************************************
 * Packet:  ECAT_FOE_READ_FILE_IND/ECAT_FOE_READ_FILE_RES
 */

/* indication packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_READ_FILE_IND_DATA_Ttag
{
  uint32_t ulMaximumByteSizeOfFragment; /* each packet fragment that is not marked LAST has to use this amount of data in its response handling */
  /* on MIDDLE segments, the packet will have ulLen set to 4 */
  uint32_t ulPassword;  /* only valid on first fragment */
  uint8_t abFilename[ECAT_FOE_MAX_FILE_NAME_LENGTH]; /* only valid on first fragment */
} ECAT_FOE_READ_FILE_IND_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_READ_FILE_IND_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_READ_FILE_IND_DATA_T tData; /* only valid on first fragment, following fragments have ulLen set to 0 */
} ECAT_FOE_READ_FILE_IND_T;


/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_READ_FILE_RES_DATA_Ttag
{
  uint8_t abData[1600]; /* actual size depends on ulLen */
  /* last segment is signaled when length is smaller than ulMaximumByteSizeOfFragment and it is expected to have ulExt.Seq set to LAST */
  /* middle segment is signaled when length is equal to ulMaximumByteSizeOfFragment and it is expected to have ulExt.Seq set to MIDDLE */

  /* in case of error, this field is used for communicating the error string */
} ECAT_FOE_READ_FILE_RES_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_FOE_READ_FILE_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_READ_FILE_RES_DATA_T tData;
} ECAT_FOE_READ_FILE_RES_T;


/* packet union */
typedef union ECAT_FOE_READ_FILE_PCK_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_FOE_READ_FILE_IND_T tInd;
  ECAT_FOE_READ_FILE_RES_T tRes;
} ECAT_FOE_READ_FILE_PCK_T;


/*******************************************************************************


  #       #          #######
  #       #          #
   #     #           #
   #     #   #####   #  #
    #   #   #     #  ####
    #   #   #     #  #  #
     # #    #     #  #
     # #    #     #  #     #
      #      #####   #######
*/

/* -----------------------------------------------------------------------------
 *  defines
 * -----------------------------------------------------------------------------
*/

#define ECAT_SYNCMAN_MBX_SIZE (128)

#define ECAT_MAILBOX_IND                                            0x00001900
#define ECAT_MAILBOX_RES                                            0x00001901
#define ECAT_MAILBOX_ADDTYPE_REQ                                    0x00001902
#define ECAT_MAILBOX_ADDTYPE_CNF                                    0x00001903
#define ECAT_MAILBOX_SEND_REQ                                       0x00001906
#define ECAT_MAILBOX_SEND_CNF                                       0x00001907
#define ECAT_MAILBOX_REMTYPE_REQ                                    0x0000190C
#define ECAT_MAILBOX_REMTYPE_CNF                                    0x0000190D

/******************************************************************************
 * Packet ECAT_MAILBOX_ADDTYPE_REQ/ECAT_MAILBOX_ADDTYPE_CNF
 *
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_MBX_ADD_TYPE_REQ_DATA_Ttag
{
  uint32_t ulType;
} ECAT_MBX_ADD_TYPE_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_MBX_ADD_TYPE_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_MBX_ADD_TYPE_REQ_DATA_T tData;
} ECAT_MBX_ADD_TYPE_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_MBX_ADD_TYPE_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_MBX_ADD_TYPE_CNF_T;


/******************************************************************************
 * Packet ECAT_MAILBOX_REMTYPE_REQ/ECAT_MAILBOX_REMTYPE_CNF
 *
 */

/* request packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_MBX_REM_TYPE_REQ_DATA_Ttag
{
  uint32_t ulType;
} ECAT_MBX_REM_TYPE_REQ_DATA_T;

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_MBX_REM_TYPE_REQ_Ttag
{
  HIL_PACKET_HEADER_T tHead;
  ECAT_MBX_REM_TYPE_REQ_DATA_T tData;
} ECAT_MBX_REM_TYPE_REQ_T;

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_MBX_REM_TYPE_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_MBX_REM_TYPE_CNF_T;


/******************************************************************************
 * Packet ECAT_PACKET_MAILBOX_REQ_T
 * Packet ECAT_PACKET_MAILBOX_IND_T
 */

#define ECAT_MBXHEADER_T_SIZE  6
#define ECAT_MAILBOX_DATA_SIZE (ECAT_SYNCMAN_MBX_SIZE - ECAT_MBXHEADER_T_SIZE)

typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_MAILBOX_Ttag
{
  uint16_t usLength;
  uint16_t usAddress;
  uint8_t uChannelandPriority;
  uint8_t uType;
  uint8_t bData[ECAT_MAILBOX_DATA_SIZE];
} ECAT_MAILBOX_T;

__HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_PACKET_MAILBOX_Ttag
{
  HIL_PACKET_HEADER_T tHead; /* packet header, defines */
  ECAT_MAILBOX_T tMailBox;
};

typedef struct ECAT_PACKET_MAILBOX_Ttag ECAT_PACKET_MAILBOX_REQ_T;
typedef struct ECAT_PACKET_MAILBOX_Ttag ECAT_PACKET_MAILBOX_IND_T;

/******************************************************************************
 * Packet ECAT_PACKET_MAILBOX_CNF_T
 * Packet ECAT_PACKET_MAILBOX_RES_T
 */

/* confirmation packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_PACKET_MAILBOX_CNF_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_PACKET_MAILBOX_CNF_T;

/* response packet */
typedef __HIL_PACKED_PRE struct __HIL_PACKED_POST ECAT_PACKET_MAILBOX_RES_Ttag
{
  HIL_PACKET_HEADER_T tHead;
} ECAT_PACKET_MAILBOX_RES_T;


#ifdef PRAGMA_PACK_ENABLE
#pragma PRAGMA_UNPACK_1(ECS_PUBLIC)
#endif

#endif
