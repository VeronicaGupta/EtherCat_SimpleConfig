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
#include "AppECS_DemoObjectDictionary.h"
#include "string.h"

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

APP_ECS_DATA_T tAppECSData;

typedef struct CUSTOM_OD_Ttag{
  OBJECT_DESCRIPTION_T* ptCurrObj;
  OBJECT_DESCRIPTION_T* ptBreakObj; /* pointer to one after last object which is taken as break condition in a loop */
  SUBOBJECT_DESCRIPTION_T* ptCurrSubObj;
}CUSTOM_OD_T;


typedef __HIL_PACKED_PRE struct
{
  uint32_t ulLength;
  char     abName[50];
}__HIL_PACKED_POST FRAG_NAME;

typedef __HIL_PACKED_PRE struct
{
  uint32_t ulLength;
  uint8_t  abValue[];
}__HIL_PACKED_POST FRAG_INITIAL_VALUE;

CUSTOM_OD_T g_customOd =
{
  .ptCurrObj = &g_tObjects[0],
  .ptBreakObj = &g_tObjects[ ARRCNT(g_tObjects) ], /* pointer to one after last object which is taken as break condition in a loop */
  .ptCurrSubObj = 0,
};

static uint32_t AppECS_OD_SendCreateObjectReq(APP_DATA_T*, CUSTOM_OD_T*);
static uint32_t AppECS_OD_SendCreateSubObjectReq(APP_DATA_T*, CUSTOM_OD_T*);
static uint8_t Object_4000_1=0x01;
static uint8_t Object_4000_2=0x01;
static uint32_t Object_4000_3=0x12345678;

static void AppECS_OD_AddName(CIFX_PACKET* ptPkt, const char* pbName)
{
  if(NULL != pbName)
  {
    if (ptPkt->tHeader.ulCmd == ODV3_CREATE_OBJECT_REQ)
    {
      ODV3_CREATE_OBJECT_REQ_T* ptReq = (ODV3_CREATE_OBJECT_REQ_T*)ptPkt;
      /*Set pointer to end of data*/
      FRAG_NAME* ptFrag = (FRAG_NAME*)(&ptReq->tData.abData[ptReq->tData.ulTotalDataBytes]);

      /*set length of name and copy it*/
      ptFrag->ulLength = strlen(pbName) +1 ;
      memcpy(&ptFrag->abName, pbName, ptFrag->ulLength);

      ptReq->tData.bValueInfo       |= ODV3_VALUE_INFO_NAME;
      ptReq->tHead.ulLen            += (sizeof(ptFrag->ulLength) + ptFrag->ulLength );
      ptReq->tData.ulTotalDataBytes += (sizeof(ptFrag->ulLength) + ptFrag->ulLength );
    }
    if (ptPkt->tHeader.ulCmd == ODV3_CREATE_SUBOBJECT_REQ)
    {
      ODV3_CREATE_SUBOBJECT_REQ_T* ptReq = (ODV3_CREATE_SUBOBJECT_REQ_T*)ptPkt;
      /*Set pointer to end of data*/
      FRAG_NAME* ptFrag = (FRAG_NAME*)(&ptReq->tData.abData[ptReq->tData.ulTotalDataBytes]);

      /*set length of name and copy it*/
      ptFrag->ulLength = strlen(pbName) +1 ;
      memcpy(&ptFrag->abName, pbName, ptFrag->ulLength);

      ptReq->tData.bValueInfo       |= ODV3_VALUE_INFO_NAME;
      ptReq->tHead.ulLen            += (sizeof(ptFrag->ulLength) + ptFrag->ulLength );
      ptReq->tData.ulTotalDataBytes += (sizeof(ptFrag->ulLength) + ptFrag->ulLength );
    }
  }
}

static void AppECS_OD_AddInitialValue( CIFX_PACKET* ptPkt, const void* pvInitialValue, uint32_t ulInitialValueLength )
{
  if(NULL != pvInitialValue)
  {
    if (ptPkt->tHeader.ulCmd == ODV3_CREATE_OBJECT_REQ)
    {
      ODV3_CREATE_OBJECT_REQ_T* ptReq = (ODV3_CREATE_OBJECT_REQ_T*)ptPkt;
      /*Set pointer to end of data*/
      FRAG_INITIAL_VALUE* ptFrag = (FRAG_INITIAL_VALUE*)(&ptReq->tData.abData[ptReq->tData.ulTotalDataBytes]);

      /*set length and copy name*/
      ptFrag->ulLength = ulInitialValueLength;
      memcpy(&ptFrag->abValue[0], pvInitialValue, ulInitialValueLength);

      ptReq->tData.bValueInfo       |= ODV3_VALUE_INFO_INITIAL_VALUE;
      ptReq->tHead.ulLen            += (sizeof(ptFrag->ulLength) + ptFrag->ulLength );
      ptReq->tData.ulTotalDataBytes += (sizeof(ptFrag->ulLength) + ptFrag->ulLength );
    }
    if (ptPkt->tHeader.ulCmd == ODV3_CREATE_SUBOBJECT_REQ)
    {
      ODV3_CREATE_SUBOBJECT_REQ_T* ptReq = (ODV3_CREATE_SUBOBJECT_REQ_T*)ptPkt;
      /*Set pointer to end of data*/
      FRAG_INITIAL_VALUE* ptFrag = (FRAG_INITIAL_VALUE*)(&ptReq->tData.abData[ptReq->tData.ulTotalDataBytes]);

      /*set length and copy name*/
      ptFrag->ulLength = ulInitialValueLength;
      memcpy(&ptFrag->abValue[0], pvInitialValue, ulInitialValueLength);

      ptReq->tData.bValueInfo       |= ODV3_VALUE_INFO_INITIAL_VALUE;
      ptReq->tHead.ulLen            += (sizeof(ptFrag->ulLength) + ptFrag->ulLength );
      ptReq->tData.ulTotalDataBytes += (sizeof(ptFrag->ulLength) + ptFrag->ulLength );
    }
  }
}

static uint32_t AppECS_OD_HandleNextObject(APP_DATA_T *ptAppData, CUSTOM_OD_T* ptCustOd)
{
  uint32_t lRet = CIFX_NO_ERROR;
  ++ptCustOd->ptCurrObj;
  if(ptCustOd->ptCurrObj != ptCustOd->ptBreakObj)
  {
    lRet = AppECS_OD_SendCreateObjectReq(ptAppData, ptCustOd);
  }
  return lRet;
}



uint32_t Ecat_SetIoSizeReq (APP_DATA_T *ptAppData, uint32_t ulOutputSize, uint32_t ulInputSize )
{
  uint32_t lRet = CIFX_NO_ERROR;
  CIFX_PACKET tSendPkt = {{0}};
  ECAT_DPM_SET_IO_SIZE_REQ_T* ptSetIoSizeReq = (ECAT_DPM_SET_IO_SIZE_REQ_T*) &tSendPkt;

  memset (&ptSetIoSizeReq->tHead, 0 , sizeof(ptSetIoSizeReq->tHead));

  ptSetIoSizeReq->tHead.ulDest    = HIL_PACKET_DEST_DEFAULT_CHANNEL;
  ptSetIoSizeReq->tHead.ulCmd     = ECAT_DPM_SET_IO_SIZE_REQ;
  ptSetIoSizeReq->tHead.ulLen     = sizeof(ptSetIoSizeReq->tData);

  ptSetIoSizeReq->tData.ulProcessDataOutputSize = ulOutputSize;
  ptSetIoSizeReq->tData.ulProcessDataInputSize = ulInputSize;

  Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , (CIFX_PACKET*) ptSetIoSizeReq, TX_TIMEOUT);

  return lRet;
}

static uint32_t  OD_CalculatePdoOffsets(APP_ECS_DATA_T *ptAppEcsData, APP_DATA_T *ptAppData, ODV3_WRITE_OBJECT_REQ_T* ptPck)
{
  uint32_t lRet = CIFX_NO_ERROR;
  uint8_t j;

  switch (ptPck->tData.usIndex)
  {
    case 0x1C12:
    {
      for (j = 0;  j < ECS_NUMBER_OF_RX_SUBINDX_INCL_SUB0; j++)
      {
        /* add offset of PDO to list and calculate next offset,
         * usTotalInpuSize was set to 0 before 1st function call*/
        ptAppEcsData->tAssignment.tAssign1C12Temp.OffsetInProcessData[j] = ptAppEcsData->usTotalOutputSize;
        if (ptAppEcsData->tAssignment.tAssign1C12Temp.SubindexEntry[j] == 0x1600)
        {
          /* calculate next offset */
          ptAppEcsData->usTotalOutputSize += 6;
        }
        else if (ptAppEcsData->tAssignment.tAssign1C12Temp.SubindexEntry[j] == 0x1601)
        {
          /* calculate next offset */
          ptAppEcsData->usTotalOutputSize += 4;
        }
      }
      /*add last offset (length over all) to know length of last value */
      ptAppEcsData->tAssignment.tAssign1C12Temp.OffsetInProcessData[ECS_NUMBER_OF_RX_SUBINDX_INCL_SUB0 + 1] = ptAppEcsData->usTotalInputSize;
    }
    break;

    case 0x1C13:
    {
      for (j = 0;  j < ECS_NUMBER_OF_TX_SUBINDX_INCL_SUB0; j++)
      {
      /* add offset of PDO to list and calculate next offset,
         * usTotalInpuSize was set to 0 before 1st function call*/
        ptAppEcsData->tAssignment.tAssign1C13Temp.OffsetInProcessData[j] = ptAppEcsData->usTotalInputSize;
        if (ptAppEcsData->tAssignment.tAssign1C13Temp.SubindexEntry[j] == 0x1A00)
        {
          /* calculate next offset */
          ptAppEcsData->usTotalInputSize += 10;
        }
        else if (ptAppEcsData->tAssignment.tAssign1C13Temp.SubindexEntry[j] == 0x1A01)
        {
          /* calculate next offset */
          ptAppEcsData->usTotalInputSize += 4;
        }
      }
      /*add last offset (length over all) to know length of last value */
      ptAppEcsData->tAssignment.tAssign1C13Temp.OffsetInProcessData[ECS_NUMBER_OF_TX_SUBINDX_INCL_SUB0 + 1] = ptAppEcsData->usTotalInputSize;
    }
    break;

    default:
      lRet = CIFX_INVALID_PARAMETER; /* TODO: specify error code */
     break;
  }
return lRet;
}

/*****************************************************************************/
/*! Objectdictionary Mapping: PDO Assignment sets PDO´s as data of Syncmanager objects
 *  We only get informed about the object writing to save the data length and order of Mapping.
 *  The objects themselves are written/ hold by the Objectdictionary ODV3
*   \return CIFX_NO_ERROR on success                                         */
/*****************************************************************************/
static uint32_t OD_WriteInd_PDOAssignmentParameter(APP_ECS_DATA_T *ptAppEcsData, APP_DATA_T *ptAppData, ODV3_WRITE_OBJECT_REQ_T* ptPck)
{
  uint32_t lRet = CIFX_NO_ERROR;
  uint16_t usMasterChecksIndex;

  /*****************/
  /***  0x1C12   ***/
  /*****************/

  if (ptPck->tData.usIndex == 0x1C12)
  {
    /* Check max Subindex */
    if( ptPck->tData.bSubIndex > s_b1C12_NumElements)
    {
      lRet = 0;//(TLR_E_ECSV4_COE_SDOABORT_SUBINDEX_DOES_NOT_EXIST);
    }
    /***********************/
    /*  subindex 0     */
    /***********************/
    if (ptPck->tData.bSubIndex == 0)
    {
      if (ptPck->tData.abData[0] ==  0)
      {
        /* Subindex 0 set to 0 = object deactivated*/
        memset(&ptAppEcsData->tAssignment.tAssign1C12Temp, 0, sizeof(ptAppEcsData->tAssignment.tAssign1C12Temp));

        /*allow access to objectwriting */
        ptAppEcsData->tAssignment.tAssign1C12Temp.fWriteUnlocked = true;

        /*send a set io size req in case 0 bytes are configured */
        ptAppEcsData->usTotalOutputSize = 0;
        lRet = Ecat_SetIoSizeReq(ptAppData, ptAppEcsData->usTotalOutputSize, ptAppEcsData->usTotalInputSize);

        /*return packet*/
        ptPck->tHead.ulCmd |= 0x01;
        ptPck->tHead.ulSta = lRet;
        ptPck->tHead.ulLen = 3;
        lRet = Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , (CIFX_PACKET*) ptPck, TX_TIMEOUT);
      }
      else
      {
        if (ptAppEcsData->tAssignment.tAssign1C12Temp.fWriteUnlocked)
        {
          /* this is the end of objectwriting, calculate length for specific I/O direction */
          lRet = OD_CalculatePdoOffsets( ptAppEcsData, ptAppData,ptPck);

          /* send setiosize to firmware*/
          lRet = Ecat_SetIoSizeReq(ptAppData, ptAppEcsData->usTotalOutputSize, ptAppEcsData->usTotalInputSize);

          /* now copy mapping entries from temporary local list to valid list */
          memcpy ( &ptAppEcsData->tAssignment.tAssign1C12, &ptAppEcsData->tAssignment.tAssign1C12Temp, sizeof(ASSIGNMENT_ENTRY));

          /* return packet */
          ptPck->tHead.ulCmd |= 0x01;
          ptPck->tHead.ulSta = lRet;
          ptPck->tHead.ulLen = 3;
          lRet = Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , (CIFX_PACKET*) ptPck, TX_TIMEOUT);

          /*object writing finished, deny access */
          ptAppEcsData->tAssignment.tAssign1C12Temp.fWriteUnlocked = false;
        }
        else
        {
          /* Not allowed to write, but we have to check if value = stored value in valid configuration
             This can happen if the master just writes an unchanged config to check if it is o.k. */
          usMasterChecksIndex = ptPck->tData.abData[0] | (ptPck->tData.abData[1] <<8);
          if (!(ptAppEcsData->tAssignment.tAssign1C12.SubindexEntry[ptPck->tData.bSubIndex] == usMasterChecksIndex))
          {
            lRet = 0;//TLR_E_ECSV4_COE_SDOABORT_SUBINDEX_CANNOT_BE_WRITTEN_SI0_MUST_BE_0;
          }
        }
      }
    }
    else
    { /********************************/
      /* case other subindex than 0 */
      /********************************/
      if (ptAppEcsData->tAssignment.tAssign1C12Temp.fWriteUnlocked != false)
      {
        /* No fix objects which are always mapped and not downloaded,
         * so just map the incomming objects*/
        if (ptPck->tData.bSubIndex == 1)
        {
          ptAppEcsData->tAssignment.tAssign1C12Temp.Index = ptPck->tData.usIndex; /*0x1C12*/
          /* copy mapping entry from packet to local resources */
          memcpy ( &ptAppEcsData->tAssignment.tAssign1C12Temp.SubindexEntry[ptPck->tData.bSubIndex ], ptPck->tData.abData, 2); /* Data contains PDO  */
        }
        else
        {
          /* copy other valid mapping entries from packet to local resources */
          memcpy ( &ptAppEcsData->tAssignment.tAssign1C12Temp.SubindexEntry[ptPck->tData.bSubIndex], ptPck->tData.abData, 2); /* Data contains PDO  */
        }
      }
      else
      { /* Not allowed to write, but we have to check if value = stored value in valid configuration
           This can happen if the master just writes an unchanged config to check if it is o.k. */
        usMasterChecksIndex = ptPck->tData.abData[0] | (ptPck->tData.abData[1] <<8);
        if (!(ptAppEcsData->tAssignment.tAssign1C12.SubindexEntry[ptPck->tData.bSubIndex] == usMasterChecksIndex))
        {
          lRet = 0;//TLR_E_ECSV4_COE_SDOABORT_SUBINDEX_CANNOT_BE_WRITTEN_SI0_MUST_BE_0;
        }
      }
      /* allways return the packet immediately if subindex is  !=0*/
      ptPck->tHead.ulCmd |= 0x01;
      ptPck->tHead.ulSta = lRet;
      ptPck->tHead.ulLen = 3;
      lRet = Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , (CIFX_PACKET*) ptPck, TX_TIMEOUT);
    }
  }
  /****************/
  /***  0x1C13  ***/
  /****************/
  if (ptPck->tData.usIndex == 0x1C13)
  {
    /* Check max Subindex */
    if( ptPck->tData.bSubIndex > s_b1C13_NumElements)
    {
      lRet = 0;//(TLR_E_ECSV4_COE_SDOABORT_SUBINDEX_DOES_NOT_EXIST);
    }
    /***********************/
    /*  subindex 0     */
    /***********************/
    if (ptPck->tData.bSubIndex == 0)
    {
      if (ptPck->tData.abData[0] ==  0)
      {
        /* Subindex 0 set to 0 = object deactivated*/
        memset(&ptAppEcsData->tAssignment.tAssign1C13Temp, 0, sizeof(ptAppEcsData->tAssignment.tAssign1C13Temp));

        /*allow access to objectwriting */
        ptAppEcsData->tAssignment.tAssign1C13Temp.fWriteUnlocked = true;

        /*send a set io size req in case 0 bytes are configured */
        ptAppEcsData->usTotalInputSize = 0;
        lRet = Ecat_SetIoSizeReq(ptAppData, ptAppEcsData->usTotalOutputSize, ptAppEcsData->usTotalInputSize);

        /*return packet*/
        ptPck->tHead.ulCmd |= 0x01;
        ptPck->tHead.ulSta = lRet;
        ptPck->tHead.ulLen = 3;
        lRet = Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , (CIFX_PACKET*) ptPck, TX_TIMEOUT);
      }
      else
      {
        if (ptAppEcsData->tAssignment.tAssign1C13Temp.fWriteUnlocked)
        {
          /* this is the end of objectwriting, calculate length for specific I/O direction */
          lRet = OD_CalculatePdoOffsets(ptAppEcsData, ptAppData, ptPck);

          /* send setiosize to firmware*/
          lRet = Ecat_SetIoSizeReq(ptAppData, ptAppEcsData->usTotalOutputSize, ptAppEcsData->usTotalInputSize);

          /* now copy mapping entries from temporary local list to valid list */
          memcpy ( &ptAppEcsData->tAssignment.tAssign1C13, &ptAppEcsData->tAssignment.tAssign1C13Temp, sizeof(ASSIGNMENT_ENTRY));

          /* return packet */
          ptPck->tHead.ulCmd |= 0x01;
          ptPck->tHead.ulSta = lRet;
          ptPck->tHead.ulLen = 3;
          lRet = Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , (CIFX_PACKET*) ptPck, TX_TIMEOUT);

          /*object writing finished, deny access */
          ptAppEcsData->tAssignment.tAssign1C13Temp.fWriteUnlocked = false;
        }
        else
        {
          /* Not allowed to write, but we have to check if value = stored value in valid configuration
             This can happen if the master just writes an unchanged config to check if it is o.k. */
          usMasterChecksIndex = ptPck->tData.abData[0] | (ptPck->tData.abData[1] <<8);
          if (!(ptAppEcsData->tAssignment.tAssign1C13.SubindexEntry[ptPck->tData.bSubIndex] == usMasterChecksIndex))
          {
            lRet = 0;// TLR_E_ECSV4_COE_SDOABORT_SUBINDEX_CANNOT_BE_WRITTEN_SI0_MUST_BE_0;
          }
        }
      }
    }

    /********************************/
    /* case other subindex than 0 */
    /********************************/
    else
    {
      if (ptAppEcsData->tAssignment.tAssign1C13Temp.fWriteUnlocked != false)
      {
        /* No fix objects which are always mapped and not downloaded,
         * so just map the incomming objects*/
        if (ptPck->tData.bSubIndex == 1)
        {
          ptAppEcsData->tAssignment.tAssign1C13Temp.Index = ptPck->tData.usIndex; /*0x1C13*/
          /* copy mapping entry from packet to local resources */
          memcpy ( &ptAppEcsData->tAssignment.tAssign1C13Temp.SubindexEntry[ptPck->tData.bSubIndex], ptPck->tData.abData, 2); /* Data contains PDO  */
        }
        else
        {
          /* copy other valid mapping entries from packet to local resources */
          memcpy ( &ptAppEcsData->tAssignment.tAssign1C13Temp.SubindexEntry[ptPck->tData.bSubIndex], ptPck->tData.abData, 2); /* Data contains PDO  */
        }
      }
      else
      { /* Not allowed to write, but we have to check if value = stored value in valid configuration
           This can happen if the master just writes an unchanged config to check if it is o.k. */
        usMasterChecksIndex = ptPck->tData.abData[0] | (ptPck->tData.abData[1] <<8);
        if (!(ptAppEcsData->tAssignment.tAssign1C13.SubindexEntry[ptPck->tData.bSubIndex] == usMasterChecksIndex))
        {
          lRet = 0;//TLR_E_ECSV4_COE_SDOABORT_SUBINDEX_CANNOT_BE_WRITTEN_SI0_MUST_BE_0;
        }
      }
      /* allways return the packet immediately if subindex is  !=0*/
      ptPck->tHead.ulCmd |= 0x01;
      ptPck->tHead.ulSta = lRet;
      ptPck->tHead.ulLen = 3;
      lRet = Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , (CIFX_PACKET*) ptPck, TX_TIMEOUT);
    }
  }
  return lRet;
}



static uint32_t AppECS_OD_HandleCreateObjectCnf(APP_DATA_T *ptAppData)
{
  uint32_t lRet = CIFX_NO_ERROR;
  CUSTOM_OD_T* ptCustOd = &g_customOd;
  OBJECT_DESCRIPTION_T* ptCurrObj = ptCustOd->ptCurrObj;

  if(ptCurrObj->ptSi00)
  {
    ptCustOd->ptCurrSubObj = ptCurrObj->ptSi00;
    lRet = AppECS_OD_SendCreateSubObjectReq(ptAppData, ptCustOd);
  }else
  {
    lRet = AppECS_OD_HandleNextObject(ptAppData, ptCustOd);
  }
  return lRet;
}

static uint32_t AppECS_OD_SendCreateObjectReq(APP_DATA_T *ptAppData, CUSTOM_OD_T* ptCustOd)
{
  uint32_t ulRet = CIFX_NO_ERROR;
  ODV3_CREATE_OBJECT_REQ_T* ptReq = (ODV3_CREATE_OBJECT_REQ_T*)&ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket;

  OBJECT_DESCRIPTION_T* ptCurrObj = ptCustOd->ptCurrObj;

  memset(ptReq, 0x00, sizeof(*ptReq));

  ptReq->tHead.ulCmd  = ODV3_CREATE_OBJECT_REQ;
  ptReq->tHead.ulDest = HIL_PACKET_DEST_DEFAULT_CHANNEL;
  ptReq->tHead.ulLen = offsetof(ODV3_CREATE_OBJECT_REQ_DATA_T, abData);

  ptReq->tData.usIndex = ptCurrObj->usIndex;
  ptReq->tData.bMaxNumOfSubObjs = ptCurrObj->bMaxNumOfSubObjs;
  ptReq->tData.bObjectCode = ptCurrObj->bObjectCode;
  ptReq->tData.usAccessFlags = ptCurrObj->usAccessFlags;

  ptReq->tData.bIndicationFlags = ptCurrObj->bIndicationFlags;
  ptReq->tData.usDatatype = ptCurrObj->usDatatype;
  ptReq->tData.usAccessRights = ptCurrObj->usAccessRights;
  ptReq->tData.ulMaxFieldUnits = ptCurrObj->ulMaxFieldUnits;
  ptReq->tData.ulTotalDataBytes = 0; /* incremented by OD_Add*() */

  AppECS_OD_AddName(&ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket ,ptCurrObj->pszName);

  AppECS_OD_AddInitialValue(&ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket,
                            ptCurrObj->pvInitialValue,
                            ptCurrObj->ulInitialValueLength);

  Pkt_SendReceivePacket( ptAppData, ECS_DEMO_CHANNEL_INDEX, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket, TXRX_TIMEOUT );


  AppECS_OD_HandleCreateObjectCnf(ptAppData);

  return ulRet;
}


static uint32_t AppECS_OD_HandleCreateSubObjectCnf(APP_DATA_T *ptAppData)
{
  uint32_t lRet = CIFX_NO_ERROR;
  CUSTOM_OD_T* ptCustOd = &g_customOd;

  ++ptCustOd->ptCurrSubObj;

  if(ptCustOd->ptCurrSubObj != ptCustOd->ptCurrObj->ptSiBreak)
  {
    lRet = AppECS_OD_SendCreateSubObjectReq(ptAppData, ptCustOd);
  }else{
    lRet = AppECS_OD_HandleNextObject(ptAppData, ptCustOd);
  }
  return lRet;
}


static uint32_t AppECS_OD_SendCreateSubObjectReq(APP_DATA_T *ptAppData, CUSTOM_OD_T* ptCustOd)
{
  uint32_t lRet = CIFX_NO_ERROR;
  SUBOBJECT_DESCRIPTION_T* ptCurrSubObj = ptCustOd->ptCurrSubObj;
  ODV3_CREATE_SUBOBJECT_REQ_T* ptReq = (ODV3_CREATE_SUBOBJECT_REQ_T*)&ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket;
  memset(ptReq, 0x00, sizeof(*ptReq));

  ptReq->tHead.ulDest = HIL_PACKET_DEST_DEFAULT_CHANNEL;
  ptReq->tHead.ulCmd = ODV3_CREATE_SUBOBJECT_REQ;
  ptReq->tHead.ulLen = offsetof(ODV3_CREATE_SUBOBJECT_REQ_DATA_T, abData);

  ptReq->tData.usIndex = ptCustOd->ptCurrObj->usIndex;
  ptReq->tData.bSubIndex = ptCurrSubObj->bSubIndex;
  ptReq->tData.bIndicationFlags = ptCurrSubObj->bIndicationFlags;
  ptReq->tData.usAccessRights = ptCurrSubObj->usAccessRights;
  ptReq->tData.usDatatype = ptCurrSubObj->usDatatype;
  ptReq->tData.ulMaxFieldUnits = ptCurrSubObj->ulMaxFieldUnits;
  ptReq->tData.ulTotalDataBytes = 0; /* incremented by OD_Add*() */

  /* Now add values in abData field. (For additional values regard to add them in specific order)*/
  AppECS_OD_AddName(&ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket ,ptCurrSubObj->pszName);

  AppECS_OD_AddInitialValue(&ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket,
                      ptCurrSubObj->pvInitialValue,
                      ptCurrSubObj->ulInitialValueLength);

  Pkt_SendReceivePacket( ptAppData, ECS_DEMO_CHANNEL_INDEX, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket, TXRX_TIMEOUT );

  AppECS_OD_HandleCreateSubObjectCnf(ptAppData);

  return lRet;
}

uint32_t AppECS_Read_ObjectInd(APP_DATA_T*  ptAppDatal, CIFX_PACKET* ptPkt)
{
  ODV3_READ_OBJECT_IND_T *ptInd = (ODV3_READ_OBJECT_IND_T *) ptPkt;
  ODV3_READ_OBJECT_RES_T *ptRes = (ODV3_READ_OBJECT_RES_T *) ptPkt;

  ptRes->tHead.ulCmd   |= 0x01;
  ptRes->tHead.ulSta = 0;
  ptRes->tData.usIndex=ptInd->tData.usIndex;
  ptRes->tData.bSubIndex=ptInd->tData.bSubIndex;
  ptRes->tData.usMaxSegLength=ptInd->tData.usMaxSegLength;

  switch ( ptInd->tData.usIndex )
  {
    case 0x4000:
      switch ( ptInd->tData.bSubIndex )
       {
       case 0x0001:
          ptRes->tHead.ulLen = 9+1;
          ptRes->tData.ulTotalDataBytes=1;
          ptRes->tData.abData[0]= Object_4000_1;
          break;
       case 0x0002:
          ptRes->tHead.ulLen = 9+1;
          ptRes->tData.ulTotalDataBytes=1;
          ptRes->tData.abData[0]= Object_4000_2;
          break;

       case 0x0003:
          ptRes->tHead.ulLen = 9+4;
          ptRes->tData.ulTotalDataBytes=4;
          memcpy(ptRes->tData.abData,&Object_4000_3,sizeof(Object_4000_3));
          break;
       default:
          ptRes->tHead.ulLen = 9;
          ptRes->tData.ulTotalDataBytes=0;
          break;
       }
      break;
    default:
      ptRes->tHead.ulLen = 9;
      ptRes->tData.ulTotalDataBytes=0;
  }

  Pkt_SendPacket(ptAppDatal, ECS_DEMO_CHANNEL_INDEX , ptPkt, TX_TIMEOUT);
  return 0;
}

uint32_t AppECS_Write_ObjectInd(APP_DATA_T *ptAppData, CIFX_PACKET* ptPkt)
{
  uint32_t lRet = CIFX_NO_ERROR;
  ODV3_WRITE_OBJECT_IND_T *ptInd = (ODV3_WRITE_OBJECT_IND_T *) ptPkt;
  ODV3_WRITE_OBJECT_RES_T *ptRes = (ODV3_WRITE_OBJECT_RES_T *) ptPkt;
  ODV3_WRITE_OBJECT_REQ_T *ptReq = (ODV3_WRITE_OBJECT_REQ_T *) ptPkt;

  switch ( ptInd->tData.usIndex )
    {
      case 0x4000:
        switch ( ptInd->tData.bSubIndex )
         {
         case 0x0001:
            Object_4000_1 = ptInd->tData.abData[0] ;
            break;
         case 0x0002:
            Object_4000_2 = ptInd->tData.abData[0];
            break;
         case 0x0003:
            memcpy(&Object_4000_3 , ptInd->tData.abData , sizeof(Object_4000_3));
            break;
         default:
            lRet = CIFX_INVALID_PARAMETER;
            break;
         }
        break;
      case 0x1C12:
         lRet = OD_WriteInd_PDOAssignmentParameter(&tAppECSData, ptAppData, ptReq);
         break;
      case 0x1C13:
         lRet = OD_WriteInd_PDOAssignmentParameter(&tAppECSData, ptAppData, ptReq);
         break;
      default:
         lRet = CIFX_INVALID_PARAMETER;
         break;
    }

  ptRes->tHead.ulCmd   |= 0x01;
  ptRes->tHead.ulLen = 3;
  ptRes->tHead.ulSta = 0;

  ptRes->tData.usIndex=ptInd->tData.usIndex;
  ptRes->tData.bSubIndex=ptInd->tData.bSubIndex;

  Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , ptPkt, TX_TIMEOUT);
  return lRet;
}

uint32_t AppECS_Write_Object_Validation_CompleteInd(APP_DATA_T *ptAppData, CIFX_PACKET* ptPkt)
{
  ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND_T *ptInd = (ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND_T *) ptPkt;
  ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES_T *ptRes = (ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_RES_T *) ptPkt;

  ptRes->tHead.ulCmd   |= 0x01;
  ptRes->tHead.ulLen = 3;
  ptRes->tHead.ulSta = 0;

  ptRes->tData.usIndex=ptInd->tData.usIndex;
  ptRes->tData.bSubIndex=ptInd->tData.bSubIndex;

  Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , ptPkt, TX_TIMEOUT);
  return 0;
}

uint32_t AppECS_Esm_AlStauts_ChangedInd(APP_DATA_T *ptAppData, CIFX_PACKET* ptPkt)
{
  ECAT_ESM_ALSTATUS_CHANGED_IND_T *ptInd = (ECAT_ESM_ALSTATUS_CHANGED_IND_T *) ptPkt;
  if (ptInd->tData.tAlStatus.uState==1)
  {    PRINTF("Init State" NEWLINE); }
  else if (ptInd->tData.tAlStatus.uState==2)
  {    PRINTF("Pre-Operational State" NEWLINE); }
  else if (ptInd->tData.tAlStatus.uState==3)
  {    PRINTF("Bootstrap State" NEWLINE); }
  else if (ptInd->tData.tAlStatus.uState==4)
  {    PRINTF("Safe-Operational State" NEWLINE); }
  else if (ptInd->tData.tAlStatus.uState==8)
  {    PRINTF("Operational State" NEWLINE); }

  ECAT_ESM_ALSTATUS_CHANGED_RES_T *ptRes = (ECAT_ESM_ALSTATUS_CHANGED_RES_T *) ptPkt;


  ptRes->tHead.ulCmd   |= 0x01;
  ptRes->tHead.ulLen = 0;
  ptRes->tHead.ulSta = 0;

  Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , ptPkt, TX_TIMEOUT);
  return 0;
}

void AppECS_Register_FOR_AlControl_IndicationsReq( CIFX_PACKET* ptPkt )
{
  ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_T* ptReq = (ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ_T*)ptPkt;

  memset( ptReq, 0, sizeof(*ptReq) );

  ptReq->tHead.ulDest = HIL_PACKET_DEST_DEFAULT_CHANNEL;
  ptReq->tHead.ulCmd  = ECAT_ESM_REGISTER_FOR_ALCONTROL_INDICATIONS_REQ;
  ptReq->tHead.ulLen  = 4;
  ptReq->tData.fEnableBootToInitHandling = 0;
}


uint8_t AppECS_Esm_AlControl_ChangedInd(APP_DATA_T *ptAppData, CIFX_PACKET* ptPkt)
{
  uint8_t uState = 0;
  ECAT_ESM_ALCONTROL_CHANGED_IND_T *ptInd = (ECAT_ESM_ALCONTROL_CHANGED_IND_T *) ptPkt;
  if (ptInd->tData.tAlControl.uState==1)
  {    PRINTF("Init Control" NEWLINE); }
  else if (ptInd->tData.tAlControl.uState==2)
  {    PRINTF("Pre-Operational Control" NEWLINE); }
  else if (ptInd->tData.tAlControl.uState==3)
  {    PRINTF("Bootstrap Control" NEWLINE); }
  else if (ptInd->tData.tAlControl.uState==4)
  {    PRINTF("Safe-Operational Control" NEWLINE); }
  else if (ptInd->tData.tAlControl.uState==8)
  {    PRINTF("Operational Control" NEWLINE); }
  uState = ptInd->tData.tAlControl.uState;
  ECAT_ESM_ALCONTROL_CHANGED_RES_T *ptRes = (ECAT_ESM_ALCONTROL_CHANGED_RES_T *) ptPkt;

  ptRes->tHead.ulCmd   |= 0x01;
  ptRes->tHead.ulLen = 0;
  ptRes->tHead.ulSta = 0;

  Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , ptPkt, TX_TIMEOUT);
  return uState;
}

void AppECS_Set_AL_StatusReq(APP_DATA_T *ptAppData, CIFX_PACKET* ptPkt, uint8_t uState )
{
  ECAT_ESM_SET_ALSTATUS_REQ_T* ptReq = (ECAT_ESM_SET_ALSTATUS_REQ_T*)ptPkt;

  memset( ptReq, 0, sizeof(*ptReq) );

  ptReq->tHead.ulDest = HIL_PACKET_DEST_DEFAULT_CHANNEL;
  ptReq->tHead.ulCmd  = ECAT_ESM_SET_ALSTATUS_REQ;
  ptReq->tHead.ulLen  = 4;
  ptReq->tData.bAlStatus = uState;

  Pkt_SendPacket(ptAppData, ECS_DEMO_CHANNEL_INDEX , ptPkt, TX_TIMEOUT);

}

uint32_t AppECS_ConfigureStack(APP_DATA_T *ptAppData)
{
  uint32_t ulRet = CIFX_NO_ERROR;
  ECAT_SET_CONFIG_REQ_T* ptConfigReq = (ECAT_SET_CONFIG_REQ_T*)&ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket;
  ECAT_SET_CONFIG_DEVICEINFO_T* ptDevInfo;
  ECAT_SET_CONFIG_SMLENGTH_T* ptSmLength;
  ECAT_SET_CONFIG_COE_T* ptCoECfg; //****Custom OD

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
  ptConfigReq->tData.tBasicCfg.ulComponentInitialization |= ECAT_SET_CONFIG_DEVICEINFO | ECAT_SET_CONFIG_COE | ECAT_SET_CONFIG_SMLENGTH;   //**** Custom OD

  ptDevInfo = &ptConfigReq->tData.tComponentsCfg.tDeviceInfoCfg;

  memcpy( ptDevInfo->szGroupIdx, DEV_GROUP_TYPE_INFO, sizeof(DEV_GROUP_TYPE_INFO)-1 );
  ptDevInfo->bGroupIdxLength = sizeof(DEV_GROUP_TYPE_INFO)-1;

  memcpy( ptDevInfo->szOrderIdx, DEV_TYPE_INFO, sizeof(DEV_TYPE_INFO)-1 );
  ptDevInfo->bOrderIdxLength = sizeof(DEV_TYPE_INFO)-1;

  memcpy( ptDevInfo->szNameIdx, DEV_NAME_INFO, sizeof(DEV_NAME_INFO)-1 );
  ptDevInfo->bNameIdxLength = sizeof(DEV_NAME_INFO)-1;

  ptCoECfg = &ptConfigReq->tData.tComponentsCfg.tCoECfg;
  ptCoECfg->bCoeFlags = ECAT_SET_CONFIG_COEFLAGS_USE_CUSTOM_OD;
  ptCoECfg->bCoeDetails = ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDO
                        | ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDOINFO
                        | ECAT_SET_CONFIG_COEDETAILS_ENABLE_UPLOAD
                        | ECAT_SET_CONFIG_COEDETAILS_ENABLE_SDOCOMPLETEACCESS;

  ptCoECfg->ulOdIndicationTimeout = 1000;
  ptCoECfg->ulDeviceType          = 0;

  /** ECAT_SET_CONFIG_SMLENGTH configuration ***************************************/
  /*  Same values as in ESI file. Using this component forces the stack to write the values to the SII image. Theses are the default values we do not change in the example,
   *  but we set them because of the following effect. The stack also writes the values set in ulProcessDataOutputSize/ ..InputSize as default values for I/O in the SII image.
   *  If the component is not used, the default value for I/O is 200/200 bytes as in Hilscher ESI files. For dynamic data it is possible to change I/O size after Config by SET_IO_SIZE_REQ*/
  ptConfigReq->tData.tBasicCfg.ulComponentInitialization |= ECAT_SET_CONFIG_SMLENGTH;
  ptSmLength = &ptConfigReq->tData.tComponentsCfg.tSmLengthCfg;

  ptSmLength->usMailboxSize = 128;
  ptSmLength->usSM2StartAddress = 0x1100;
  ptSmLength->usSM3StartAddress = 0x1D00;

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

  AppECS_Register_FOR_AlControl_IndicationsReq( &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket);
  ulRet = Pkt_SendReceivePacket(ptAppData, ECS_DEMO_CHANNEL_INDEX, ptPacket, TXRX_TIMEOUT);
  if( ulRet != CIFX_NO_ERROR )
  return ulRet;

  /* Create Objects */
  AppECS_OD_SendCreateObjectReq(ptAppData, &g_customOd);
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
  bool        fPacketCouldBeHandled = false;
  APP_DATA_T* ptAppData             = (APP_DATA_T*) pvUserData;
  uint8_t uState = 0;

  if( ptPacket != &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket )
  {
    printf("Unexpected packet resource received!!!" NEWLINE);
    return false;
  }

  switch( ptPacket->tHeader.ulCmd )
  {
    case HIL_LINK_STATUS_CHANGE_IND:
      (void) App_SysPkt_HandleLinkStatusChangeInd(ptAppData, ECS_DEMO_CHANNEL_INDEX, ptPacket);
      fPacketCouldBeHandled = true;
      break;
    case ODV3_READ_OBJECT_IND:
      AppECS_Read_ObjectInd(ptAppData, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket);
      fPacketCouldBeHandled = true;
      break;
    case ODV3_WRITE_OBJECT_IND:
      AppECS_Write_ObjectInd(ptAppData, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket);
      fPacketCouldBeHandled = true;
      break;
    case ODV3_WRITE_OBJECT_VALIDATION_COMPLETE_IND:
      AppECS_Write_Object_Validation_CompleteInd(ptAppData, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket);
      fPacketCouldBeHandled = true;
      break;
    case ECAT_ESM_ALSTATUS_CHANGED_IND:
      AppECS_Esm_AlStauts_ChangedInd(ptAppData, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket);
      fPacketCouldBeHandled = true;
      break;
    case ECAT_ESM_ALCONTROL_CHANGED_IND:
      uState = AppECS_Esm_AlControl_ChangedInd(ptAppData, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket);
      AppECS_Set_AL_StatusReq(ptAppData, &ptAppData->aptChannels[ECS_DEMO_CHANNEL_INDEX]->tPacket, uState);
      fPacketCouldBeHandled = true;
      break;

#ifdef HOST_APPLICATION_STORES_REMANENT_DATA
    case HIL_STORE_REMANENT_DATA_IND:
      AppECS_HandlStoreRemanentInd( ptAppData );
      fPacketCouldBeHandled = true;
      break;
#endif

    default:
      if( (ptPacket->tHeader.ulCmd & 0x1) == 0 ) /* received an indication*/
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

