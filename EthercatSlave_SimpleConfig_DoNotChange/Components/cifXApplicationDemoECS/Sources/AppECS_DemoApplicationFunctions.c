/**************************************************************************************
Exclusion of Liability for this demo software:
  The following software is intended for and must only be used for reference and in an
  evaluation laboratory environment. It is provided without charge and is subject to
  alterations. There is no warranty for the software, to the extent permitted by
  applicable law. Except when otherwise stated in writing the copyright holders and/or
  other parties provide the software "as is" without warranty of any kind, either
  expressed or implied.
  Please refer to the Agreement in README_DISCLAIMER.txt, provided together with this file!
  By installing or otherwise using the software, you accept the terms of this Agreement.
  If you do not agree to the terms of this Agreement, then do not install or use the
  Software!
**************************************************************************************/

/**************************************************************************************

Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.

***************************************************************************************/
/* Includes */

#include <stdio.h>

#include "AppECS_DemoApplication.h"
#include "App_DemoApplication.h"
#include "App_PacketCommunication.h"
#include "App_SystemPackets.h"
#include "hostAbstractionLayer.h"
#include "Hil_ApplicationCmd.h"
#include "Hil_Results.h"
#include "Hil_Packet.h"
#include "Hil_DualPortMemory.h"
#include "App_EventHandler.h"
#include "Ecs_Public.h"


/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/* Configuration related definitions */

#define IP_ADDRESS(a,b,c,d) (uint32_t)(((a) << 24) | ((b) << 16) | ((c) << 8) | (d))

#define ECS_PRODUCTCODE                                               0x0000003d
#define ECS_SECONDARY_VENDORID_HILSCHER                               0xE0000044
#define ECS_REVISIONNUMBER                                            0x00000001
#define DEV_GROUP_TYPE_INFO                                           "netX"
#define DEV_TYPE_INFO                                                 "NETX 90-RE/ECS"
#define DEV_NAME_INFO                                                 "NETX 90-RE/ECS"

uint32_t AppECS_ConfigureStack(APP_DATA_T *ptAppData)
{
  uint32_t ulRet = SUCCESS_HIL_OK;

  ECAT_SET_CONFIG_REQ_T* ptConfigReq         = (ECAT_SET_CONFIG_REQ_T*)&ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket;
  ECAT_SET_CONFIG_DEVICEINFO_T* ptDevInfo;

  memset(ptConfigReq, 0, sizeof(*ptConfigReq));

  ptConfigReq->tHead.ulDest = HIL_PACKET_DEST_DEFAULT_CHANNEL;
  ptConfigReq->tHead.ulSrc = 0x00;
  ptConfigReq->tHead.ulLen = sizeof(ptConfigReq->tData);
  ptConfigReq->tHead.ulCmd = ECAT_SET_CONFIG_REQ;
  ptConfigReq->tHead.ulSta = 0;
  ptConfigReq->tHead.ulExt = 0;

  ptConfigReq->tData.tBasicCfg.ulSystemFlags = ECAT_SET_CONFIG_SYSTEMFLAGS_APP_CONTROLLED;
  ptConfigReq->tData.tBasicCfg.ulWatchdogTime = 1000;

  ptConfigReq->tData.tBasicCfg.ulVendorId = ECS_SECONDARY_VENDORID_HILSCHER;  /** Creates Vendor ID in Sii Image in accordance to ESI file */
  ptConfigReq->tData.tBasicCfg.ulProductCode = ECS_PRODUCTCODE; /** Creates Product Code in Sii Image in accordance to ESI file */
  ptConfigReq->tData.tBasicCfg.ulRevisionNumber = ECS_REVISIONNUMBER; /** Creates Revision Number in in Sii Image accordance to ESI file: increments with every released change of ESI file */
  ptConfigReq->tData.tBasicCfg.ulSerialNumber = ptAppData->tBoardInfo.tSystemInfo.ulSerialNumber;
  ptConfigReq->tData.tBasicCfg.ulProcessDataOutputSize = sizeof(APP_PROCESS_DATA_INPUT_T); /**< Process Data Output Size from master view */
  ptConfigReq->tData.tBasicCfg.ulProcessDataInputSize = sizeof(APP_PROCESS_DATA_OUTPUT_T); /**< Process Data Input Size from master view */

  /** ECAT_SET_CONFIG_DEVICEINFO configuration ***************************************/
  ptConfigReq->tData.tBasicCfg.ulComponentInitialization |= ECAT_SET_CONFIG_DEVICEINFO;
  ptDevInfo = &ptConfigReq->tData.tComponentsCfg.tDeviceInfoCfg;

  memcpy( ptDevInfo->szGroupIdx, DEV_GROUP_TYPE_INFO, sizeof(DEV_GROUP_TYPE_INFO)-1 );
  ptDevInfo->bGroupIdxLength = sizeof(DEV_GROUP_TYPE_INFO)-1;

  memcpy( ptDevInfo->szOrderIdx, DEV_TYPE_INFO, sizeof(DEV_TYPE_INFO)-1 );
  ptDevInfo->bOrderIdxLength = sizeof(DEV_TYPE_INFO)-1;

  memcpy( ptDevInfo->szNameIdx, DEV_NAME_INFO, sizeof(DEV_NAME_INFO)-1 );
  ptDevInfo->bNameIdxLength = sizeof(DEV_NAME_INFO)-1;

  CIFX_PACKET* ptPacket         = &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket;
  /* first load the configuration */
  ulRet = Pkt_SendReceivePacket(ptAppData, ECS_DEMO_CHANNEL_INDEX, ptPacket, TXRX_TIMEOUT);
  if( ulRet != CIFX_NO_ERROR )
	  return ulRet;

  /* initialize channel to use the configured data */
  App_SysPkt_AssembleChannelInitReq(ptPacket);
  ulRet = Pkt_SendReceivePacket(ptAppData, ECS_DEMO_CHANNEL_INDEX, ptPacket, TXRX_TIMEOUT);
  if( ulRet != CIFX_NO_ERROR )
	  return ulRet;

  App_SysPkt_AssembleStartStopCommReq(ptPacket, true);
  ulRet = Pkt_SendReceivePacket(ptAppData, ECS_DEMO_CHANNEL_INDEX, ptPacket, TXRX_TIMEOUT);
  if( ulRet != CIFX_NO_ERROR )
	  return ulRet;

  return ulRet;
}




/*******************************************************************************
 *  _           _ _                 _
 * (_)         | (_)           _   (_)
 *  _ ____   _ | |_  ____ ____| |_  _  ___  ____   ___
 * | |  _ \ / || | |/ ___) _  |  _)| |/ _ \|  _ \ /___)
 * | | | | ( (_| | ( (__( ( | | |__| | |_| | | | |___ |
 * |_|_| |_|\____|_|\____)_||_|\___)_|\___/|_| |_(___/
 *
 * http://www.network-science.de/ascii/  font stop
 ******************************************************************************/

/*******************************************************************/

bool AppECS_PacketHandler( CIFX_PACKET* ptPacket,
                           void*        pvUserData )
{
  bool fPacketCouldBeHandled = false;
  APP_DATA_T* ptAppData = (APP_DATA_T*) pvUserData;

  if(ptPacket != &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket)
  {
    printf("Unexpected packet resource received!!!" NEWLINE);
    return false;
  }

  switch (ptPacket->tHeader.ulCmd)
  {
  case HIL_LINK_STATUS_CHANGE_IND:
    (void) App_SysPkt_HandleLinkStatusChangeInd(ptAppData, ECS_DEMO_CHANNEL_INDEX, ptPacket);
    fPacketCouldBeHandled = true;
    break;

#ifdef HOST_APPLICATION_STORES_REMANENT_DATA
    case HIL_STORE_REMANENT_DATA_IND:
    AppECS_HandlStoreRemanentInd( ptAppData );
    fPacketCouldBeHandled = true;
    break;
#endif

  default:
    if((ptPacket->tHeader.ulCmd & 0x1) == 0) /* received an indication*/
    {
      PRINTF("Warning: Disregarded indication packet received!" NEWLINE);
      ptPacket->tHeader.ulLen = 0;
      ptPacket->tHeader.ulState = ERR_HIL_UNKNOWN_COMMAND;
      ptPacket->tHeader.ulCmd |= 0x01; /* Make it a response */

      (void) Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX, ptPacket, TX_TIMEOUT);
      fPacketCouldBeHandled = true;
    }
    else
    { /* received a confirmation */
      PRINTF("Warning: Disregarded confirmation packet received!" NEWLINE);
    }
    break;
  } /*switch*/

  return fPacketCouldBeHandled;
}

