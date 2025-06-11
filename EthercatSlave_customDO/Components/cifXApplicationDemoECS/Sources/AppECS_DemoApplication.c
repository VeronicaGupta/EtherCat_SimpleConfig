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

#include "AppECS_DemoApplication.h"
#include "App_DemoApplication.h"
#include "App_PacketCommunication.h"
#include "App_SystemPackets.h"
#include "hostAbstractionLayer.h"
#include "Hil_ApplicationCmd.h"
#include "Hil_SystemCmd.h"
#include "Hil_Results.h"
#include "Hil_Packet.h"
#include "Hil_DualPortMemory.h"
#include "App_EventHandler.h"
#include "Ecs_Public.h"
#include "OdV3_Public.h"
#include "OdV3_Defines.h"
#include "OdV3_Results.h"

/***************************************************************************************/

#define STR(tok) #tok

static struct
{
  char* szCommandName;
  uint32_t ulCommandCode;
} s_atCommandNameLookupTable[] =
{
  { STR(HIL_CHANNEL_INIT_REQ), HIL_CHANNEL_INIT_REQ },
    { STR(HIL_CHANNEL_INIT_CNF), HIL_CHANNEL_INIT_CNF },

    { STR(HIL_REGISTER_APP_REQ), HIL_REGISTER_APP_REQ },
    { STR(HIL_REGISTER_APP_CNF), HIL_REGISTER_APP_CNF },

    { STR(HIL_UNREGISTER_APP_REQ), HIL_UNREGISTER_APP_REQ },
    { STR(HIL_UNREGISTER_APP_CNF), HIL_UNREGISTER_APP_CNF },

    { STR(HIL_START_STOP_COMM_REQ), HIL_START_STOP_COMM_REQ },
    { STR(HIL_START_STOP_COMM_CNF), HIL_START_STOP_COMM_CNF },

    { STR(HIL_LINK_STATUS_CHANGE_IND), HIL_LINK_STATUS_CHANGE_IND },
    { STR(HIL_LINK_STATUS_CHANGE_RES), HIL_LINK_STATUS_CHANGE_RES },

    { STR(HIL_SET_REMANENT_DATA_REQ), HIL_SET_REMANENT_DATA_REQ },
    { STR(HIL_SET_REMANENT_DATA_CNF), HIL_SET_REMANENT_DATA_CNF },

    { STR(HIL_FIRMWARE_IDENTIFY_REQ), HIL_FIRMWARE_IDENTIFY_REQ},
    { STR(HIL_FIRMWARE_IDENTIFY_CNF), HIL_FIRMWARE_IDENTIFY_CNF},

    /* Protocol stack specific packets */
    { STR(ECAT_SET_CONFIG_REQ), ECAT_SET_CONFIG_REQ},
    { STR(ECAT_SET_CONFIG_CNF), ECAT_SET_CONFIG_CNF},

    { STR(ECAT_ESM_ALSTATUS_CHANGED_IND), ECAT_ESM_ALSTATUS_CHANGED_IND},
    { STR(ECAT_ESM_ALSTATUS_CHANGED_RES), ECAT_ESM_ALSTATUS_CHANGED_RES},

    { STR(ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ), ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ},
    { STR(ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF), ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_CNF},

    { STR(ECAT_ESM_ALCONTROL_CHANGED_IND), ECAT_ESM_ALCONTROL_CHANGED_IND},
    { STR(ECAT_ESM_ALCONTROL_CHANGED_RES), ECAT_ESM_ALCONTROL_CHANGED_RES},

    { STR(ECAT_ESM_SET_ALSTATUS_REQ), ECAT_ESM_SET_ALSTATUS_REQ},
    { STR(ECAT_ESM_SET_ALSTATUS_CNF), ECAT_ESM_SET_ALSTATUS_CNF},

    { STR(ODV3_GET_SUBOBJECT_INFO_IND), ODV3_GET_SUBOBJECT_INFO_IND},
    { STR(ODV3_GET_SUBOBJECT_INFO_RES), ODV3_GET_SUBOBJECT_INFO_RES},

    { STR(ODV3_GET_OBJECT_INFO_IND), ODV3_GET_OBJECT_INFO_IND},
    { STR(ODV3_GET_OBJECT_INFO_RES), ODV3_GET_OBJECT_INFO_RES},

    { STR(ODV3_GET_OBJECT_INFO_IND), ODV3_GET_OBJECT_INFO_IND},
    { STR(ODV3_GET_OBJECT_INFO_RES), ODV3_GET_OBJECT_INFO_RES},

    { STR(ODV3_GET_OBJECT_COUNT_IND), ODV3_GET_OBJECT_COUNT_IND},
    { STR(ODV3_GET_OBJECT_COUNT_RES), ODV3_GET_OBJECT_COUNT_RES},

    { STR(ODV3_GET_OBJECT_LIST_IND), ODV3_GET_OBJECT_LIST_IND},
    { STR(ODV3_GET_OBJECT_LIST_RES), ODV3_GET_OBJECT_LIST_RES},

    { STR(ODV3_GET_OBJECT_SIZE_IND), ODV3_GET_OBJECT_SIZE_IND},
    { STR(ODV3_GET_OBJECT_SIZE_RES), ODV3_GET_OBJECT_SIZE_RES},

    { STR(ODV3_CREATE_OBJECT_REQ), ODV3_CREATE_OBJECT_REQ},
    { STR(ODV3_CREATE_OBJECT_CNF), ODV3_CREATE_OBJECT_CNF},

    { STR(ODV3_CREATE_SUBOBJECT_REQ), ODV3_CREATE_SUBOBJECT_REQ},
    { STR(ODV3_CREATE_SUBOBJECT_CNF), ODV3_CREATE_SUBOBJECT_CNF},

    { STR(ODV3_REGISTER_OBJINFO_NOTIFY_REQ), ODV3_REGISTER_OBJINFO_NOTIFY_REQ},
    { STR(ODV3_REGISTER_OBJINFO_NOTIFY_CNF), ODV3_REGISTER_OBJINFO_NOTIFY_CNF},

    { STR(ODV3_REGISTER_OBJECT_NOTIFY_REQ), ODV3_REGISTER_OBJECT_NOTIFY_REQ},
    { STR(ODV3_REGISTER_OBJECT_NOTIFY_CNF), ODV3_REGISTER_OBJECT_NOTIFY_CNF},

    { STR(ODV3_REGISTER_UNDEFINED_NOTIFY_REQ), ODV3_REGISTER_UNDEFINED_NOTIFY_REQ},
    { STR(ODV3_REGISTER_UNDEFINED_NOTIFY_CNF), ODV3_REGISTER_UNDEFINED_NOTIFY_CNF},

    { STR(ODV3_GET_OBJECT_ACCESS_INFO_IND), ODV3_GET_OBJECT_ACCESS_INFO_IND},
    { STR(ODV3_GET_OBJECT_ACCESS_INFO_RES), ODV3_GET_OBJECT_ACCESS_INFO_RES},

    { STR(ODV3_READ_OBJECT_IND), ODV3_READ_OBJECT_IND},
    { STR(ODV3_READ_OBJECT_RES), ODV3_READ_OBJECT_RES},

    { STR(ODV3_WRITE_OBJECT_IND), ODV3_WRITE_OBJECT_IND},
    { STR(ODV3_WRITE_OBJECT_RES), ODV3_WRITE_OBJECT_RES},

    { STR(ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND), ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND},
    { STR(ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES), ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES},

  /* This always must be the last entry in this table */
  { "Unknown command", 0xffffffff },
};

/*******************************************************************************/

extern char* LookupCommandCode(uint32_t ulCmd)
{
  int i;
  for (i = 0; i < sizeof(s_atCommandNameLookupTable) / sizeof(s_atCommandNameLookupTable[0]); i++)
  {
    if (s_atCommandNameLookupTable[i].ulCommandCode == ulCmd)
    {
      return s_atCommandNameLookupTable[i].szCommandName;
    }
  }

  /* Comamnd not in lookup table: Return last entry of table */
  return s_atCommandNameLookupTable[i - 1].szCommandName;
}

/*******************************************************************************/



uint32_t Protocol_StartConfiguration( APP_DATA_T* ptAppData )
{
  uint32_t ulRet = CIFX_NO_ERROR;

  if (!Pkt_Init(ECS_DEMO_CHANNEL_INDEX, 3))
  {
    return CIFX_DRV_INIT_ERROR;
  }

  /* Register handler for indication packets. */
  if( Pkt_RegisterIndicationHandler( ECS_DEMO_CHANNEL_INDEX, AppECS_PacketHandler, (void*)ptAppData ) )
  {
    #ifdef HOST_APPLICATION_SETS_MAC_ADDRESS
      uint8_t abMacAddr[6] = { 0x00, 0x02, 0xA2, 0x2F, 0x90, 0x58 };

      App_SysPkt_AssembleSetMacAddressReq( &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket, &abMacAddr[0] );
      ulRet = Pkt_SendReceivePacket( ptAppData, ECS_DEMO_CHANNEL_INDEX, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket, TXRX_TIMEOUT );
      if( ulRet != CIFX_NO_ERROR )
        return ulRet;
    #endif

#ifdef HOST_APPLICATION_STORES_REMANENT_DATA
    /* Set non-volatile BLOB */
    ulRet = AppECS_SetRemanentData( ptAppData );
    if( ulRet != CIFX_NO_ERROR )
      return ulRet;
#endif

    /* Register application */
     App_SysPkt_AssembleRegisterAppReq( &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket );
     ulRet = Pkt_SendReceivePacket( ptAppData, ECS_DEMO_CHANNEL_INDEX, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket, TXRX_TIMEOUT );
     if( ulRet != CIFX_NO_ERROR )
       return ulRet;

    /* Download the configuration */
        ulRet = AppECS_ConfigureStack( ptAppData );
  }
  else
  {
    ulRet = CIFX_DRV_INIT_ERROR;
  }

  return ulRet;
}

/*******************************************************************/

uint32_t Protocol_PacketHandler( APP_DATA_T* ptAppData )
{
  uint32_t ulRet = CIFX_NO_ERROR;

  ulRet = Pkt_CheckReceiveMailbox( ptAppData, ECS_DEMO_CHANNEL_INDEX, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket );

  if( CIFX_DEV_GET_NO_PACKET == ulRet || CIFX_DEV_NOT_READY == ulRet )
  {
    /* Handle "no packet" and "stack not ready" as success. */
    ulRet = CIFX_NO_ERROR;
  }

  return ulRet;
}

/*****************************************************************************/
/*! Protocol special event handler
*   \param ptAppData   pointer to APP_DATA_T structure
*   \param eEvent      event type                                            */
/*****************************************************************************/
void Protocol_EventHandler( APP_DATA_T* ptAppData,
                            APP_EVENT_E eEvent,
                            uint32_t    ulEventData )
{
  switch(eEvent)
  {
    case APP_EVENT_SET_ALARM1:
      break;
    case APP_EVENT_CLEAR_ALARM1:
      break;

    case APP_EVENT_SET_ALARM2:
      break;
    case APP_EVENT_CLEAR_ALARM2:
      break;

    case APP_EVENT_SET_ALARM3:
      break;
    case APP_EVENT_CLEAR_ALARM3:
      break;

    case APP_EVENT_SET_ALARM4:
      break;
    case APP_EVENT_CLEAR_ALARM4:
      break;

    case APP_EVENT_SET_ERROR1:
      break;
    case APP_EVENT_CLEAR_ERROR1:
      break;

    case APP_EVENT_SET_ERROR2:
      break;
    case APP_EVENT_CLEAR_ERROR2:
      break;

    case APP_EVENT_SET_ERROR3:
      break;
    case APP_EVENT_CLEAR_ERROR3:
      break;

    case APP_EVENT_SET_ERROR4:
      break;
    case APP_EVENT_CLEAR_ERROR4:
      break;

    default:
      break;
  }
}

static uint32_t Protocol_TerminalHandler(struct APP_DATA_Ttag* ptAppData, char *szBuffer)
{
  if (0 == strcmp(szBuffer, "help"))
  {
    PRINTF("Hello from the ECS protocol part: no terminal commands implemented yet" NEWLINE);
  }

  return 0;
}

PROTOCOL_DESCRIPTOR_T g_tRealtimeProtocolHandlers =
{
  .pfStartChannelConfiguration = Protocol_StartConfiguration,
  .pfPacketHandler             = Protocol_PacketHandler,
  .pfEventHandler              = Protocol_EventHandler,
  .pfTerminalHandler           = Protocol_TerminalHandler,
};

