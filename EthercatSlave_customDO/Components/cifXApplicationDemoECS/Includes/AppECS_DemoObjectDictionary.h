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

#ifndef COMPONENTS_CIFXAPPLICATIONDEMOECS_INCLUDES_APPECS_DEMO_OBJECT_DICTIONARY_H_
#define COMPONENTS_CIFXAPPLICATIONDEMOECS_INCLUDES_APPECS_DEMO_OBJECT_DICTIONARY_H_

#include "OdV3_Public.h"
#include "OdV3_Defines.h"
#include "OdV3_Results.h"
#include "Ecs_Defines.h"
#include "Ecs_Public.h"

#ifndef ARRCNT
#define ARRCNT(arr)  sizeof(arr)/sizeof(arr[0])
#endif

#define DEFTYPE_RECORD              0x002A
#define PDOMAPPING(Idx, SubIdx, BitSize)  (Idx<<16 | (SubIdx & 0xFF)<<8 | (BitSize & 0xFF)<<0)

typedef struct SUBOBJECT_DESCRIPTION_Ttag
{
   uint8_t               bSubIndex;
   uint8_t               bIndicationFlags;
   uint16_t              usAccessRights;
   uint16_t              usDatatype;
   uint32_t              ulMaxFieldUnits;
   const char*           pszName;
   const void*           pvInitialValue;
   uint32_t              ulInitialValueLength;
}SUBOBJECT_DESCRIPTION_T;

typedef struct OBJECT_DESCRIPTION_Ttag
{
  uint16_t              usIndex;
  uint8_t               bMaxNumOfSubObjs;
  uint8_t               bObjectCode;
  uint16_t              usAccessFlags;
  uint8_t               bIndicationFlags;
  uint16_t              usDatatype;
  /* following two are only evaluated on SimpleVar { */
  uint16_t              usAccessRights;
  uint32_t              ulMaxFieldUnits;
  /* } */
  const char*           pszName;
  const void*           pvInitialValue;
  uint32_t              ulInitialValueLength;
  struct SUBOBJECT_DESCRIPTION_Ttag* ptSi00;
  struct SUBOBJECT_DESCRIPTION_Ttag* ptSiBreak;/* pointer to one after last object which is taken as break condition in a loop */
}OBJECT_DESCRIPTION_T;


//static const uint32_t s_ab1600_Elements[] = { PDOMAPPING(0x2000, 1, 32) };
static const uint32_t s_ab1600_Elements[] =
{
  PDOMAPPING(0x2000, 1, 8),
  PDOMAPPING(0x2000, 2, 8),
  PDOMAPPING(0x2000, 3, 8),
  PDOMAPPING(0x2000, 4, 8),
  PDOMAPPING(0x2000, 5, 8),
  PDOMAPPING(0x2000, 6, 8),
};

static const uint8_t s_b1600_NumElements = ARRCNT(s_ab1600_Elements);

SUBOBJECT_DESCRIPTION_T g_tSiObj_1600[] =
{
  {
    .bSubIndex = 0,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Number of elements",
    .pvInitialValue = &s_b1600_NumElements,
    .ulInitialValueLength = sizeof(s_b1600_NumElements),
  },
  {
    .bSubIndex = 1,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1600_Elements[0],
    .ulInitialValueLength = sizeof(s_ab1600_Elements[0]),
  },
  {
    .bSubIndex = 2,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1600_Elements[1],
    .ulInitialValueLength = sizeof(s_ab1600_Elements[1]),
  },
  {
    .bSubIndex = 3,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1600_Elements[2],
    .ulInitialValueLength = sizeof(s_ab1600_Elements[2]),
  },
  {
    .bSubIndex = 4,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1600_Elements[3],
    .ulInitialValueLength = sizeof(s_ab1600_Elements[3]),
  },
  {
    .bSubIndex = 5,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1600_Elements[4],
    .ulInitialValueLength = sizeof(s_ab1600_Elements[4]),
  },
  {
    .bSubIndex = 6,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1600_Elements[5],
    .ulInitialValueLength = sizeof(s_ab1600_Elements[5]),
  },
//  {
//    .bSubIndex = 1,
//    .bIndicationFlags = 0,
//    .usAccessRights = ECAT_OD_READ_ALL,
//    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
//    .ulMaxFieldUnits = 1,
//    .pszName = 0,
//    .pvInitialValue = &s_ab1600_Elements[0],
//    .ulInitialValueLength = sizeof(s_ab1600_Elements[0]),
//  },
};

static const uint32_t s_ab1A00_Elements[] =
{
  PDOMAPPING(0x3000, 1, 8),
  PDOMAPPING(0x3000, 2, 8),
  PDOMAPPING(0x3000, 3, 8),
  PDOMAPPING(0x3000, 4, 8),
  PDOMAPPING(0x3000, 5, 8),
  PDOMAPPING(0x3000, 6, 8),
  PDOMAPPING(0x3000, 7, 8),
  PDOMAPPING(0x3000, 8, 8),
  PDOMAPPING(0x3000, 9, 8),
  PDOMAPPING(0x3000, 10, 8),
};
static const uint8_t s_b1A00_NumElements = ARRCNT(s_ab1A00_Elements);

SUBOBJECT_DESCRIPTION_T g_tSiObj_1A00[] =
{
  {
    .bSubIndex = 0,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Number of elements",
    .pvInitialValue = &s_b1A00_NumElements,
    .ulInitialValueLength = sizeof(s_b1A00_NumElements),
  },
  {
    .bSubIndex = 1,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[0],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[0]),
  },
  {
    .bSubIndex = 2,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[1],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[1]),
  },
  {
    .bSubIndex = 3,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[2],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[2]),
  },
  {
    .bSubIndex = 4,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[3],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[3]),
  },
  {
    .bSubIndex = 5,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[4],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[4]),
  },
  {
    .bSubIndex = 6,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[5],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[5]),
  },
  {
    .bSubIndex = 7,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[6],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[6]),
  },
  {
    .bSubIndex = 8,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[7],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[7]),
  },
  {
    .bSubIndex = 9,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[8],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[8]),
  },
  {
    .bSubIndex = 10,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_ab1A00_Elements[9],
    .ulInitialValueLength = sizeof(s_ab1A00_Elements[9]),
  },
};

static const uint8_t s_ab1C00_Elements[] = {1, 2, 3, 4};
static const uint8_t s_b1C00_NumElements = ARRCNT(s_ab1C00_Elements);

SUBOBJECT_DESCRIPTION_T g_tSiObj_1C00[] =
{
  {
    .bSubIndex = 0,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = sizeof(uint8_t),
    .pszName = "Number of elements",
    .pvInitialValue = &s_b1C00_NumElements,
    .ulInitialValueLength = sizeof(s_b1C00_NumElements),
  },
  {
    .bSubIndex = 1,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = sizeof(uint8_t),
    .pszName = "Sync Manager 0",
    .pvInitialValue = &s_ab1C00_Elements[0],
    .ulInitialValueLength = sizeof(s_ab1C00_Elements[0]),
  },
  {
    .bSubIndex = 2,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = sizeof(uint8_t),
    .pszName = "Sync Manager 1",
    .pvInitialValue = &s_ab1C00_Elements[1],
    .ulInitialValueLength = sizeof(s_ab1C00_Elements[1]),
  },
  {
    .bSubIndex = 3,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = sizeof(uint8_t),
    .pszName = "Sync Manager 2",
    .pvInitialValue = &s_ab1C00_Elements[2],
    .ulInitialValueLength = sizeof(s_ab1C00_Elements[2]),
  },
  {
    .bSubIndex = 4,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = sizeof(uint8_t),
    .pszName = "Sync Manager 3",
    .pvInitialValue = &s_ab1C00_Elements[3],
    .ulInitialValueLength = sizeof(s_ab1C00_Elements[3]),
  }
};


static const uint16_t s_aus1C12_Entries[] = { 0x1600 };
static const uint8_t s_b1C12_NumElements = ARRCNT(s_aus1C12_Entries);

SUBOBJECT_DESCRIPTION_T tSiObj_1C12[] =
{
  {
    .bSubIndex = 0,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Number of elements",
    .pvInitialValue = &s_b1C12_NumElements,
    .ulInitialValueLength = sizeof(s_b1C12_NumElements),
  },
  {
    .bSubIndex = 1,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_aus1C12_Entries[0],
    .ulInitialValueLength = sizeof(s_aus1C12_Entries[0]),
  },
};

static const uint16_t s_aus1C13_Entries[] = { 0x1A00 };
static const uint8_t s_b1C13_NumElements = ARRCNT(s_aus1C13_Entries);

SUBOBJECT_DESCRIPTION_T g_tSiObj_1C13[] =
{
  {
    .bSubIndex = 0,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Number of elements",
    .pvInitialValue = &s_b1C13_NumElements,
    .ulInitialValueLength = sizeof(s_b1C13_NumElements),
  },
  {
    .bSubIndex = 1,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,
    .ulMaxFieldUnits = 1,
    .pszName = 0,
    .pvInitialValue = &s_aus1C13_Entries[0],
    .ulInitialValueLength = sizeof(s_aus1C13_Entries[0]),
  },
};


static const uint8_t s_b2000_NumElements;

SUBOBJECT_DESCRIPTION_T g_tSiObj_2000[] =
{
  {
    .bSubIndex = 0,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Number of elements",
    .pvInitialValue = &s_b2000_NumElements,
    .ulInitialValueLength = sizeof(s_b2000_NumElements),
  },
  {
    .bSubIndex = 1,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Outputdata0",
    .pvInitialValue = 0,
    .ulInitialValueLength = 0,
  },
  {
    .bSubIndex = 2,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Outputdata1",
    .pvInitialValue = 0,
    .ulInitialValueLength = 0,
  },
  {
    .bSubIndex = 3,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Outputdata2",
    .pvInitialValue = 0,
    .ulInitialValueLength = 0,
  },
  {
    .bSubIndex = 4,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Outputdata3",
    .pvInitialValue = 0,
    .ulInitialValueLength = 0,
  },
  {
    .bSubIndex = 5,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Outputdata4",
    .pvInitialValue = 0,
    .ulInitialValueLength = 0,
  },
  {
    .bSubIndex = 6,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Outputdata5",
    .pvInitialValue = 0,
    .ulInitialValueLength = 0,
  },
//  {
//    .bSubIndex = 1,
//    .bIndicationFlags = 0,
//    .usAccessRights = ECAT_OD_ACCESS_ALL,
//    .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
//    .ulMaxFieldUnits = 1,
//    .pszName = "Outputdata0",
//    .pvInitialValue = 0,
//    .ulInitialValueLength = 0,
//  },
};
static const uint8_t s_b2000_NumElements = ARRCNT(g_tSiObj_2000) - 1; /* SI 00 does not counts */


static const uint8_t s_b3000_NumElements;

SUBOBJECT_DESCRIPTION_T g_tSiObj_3000[] =
{
  {
    .bSubIndex = 0,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Number of elements",
    .pvInitialValue = &s_b3000_NumElements,
    .ulInitialValueLength = sizeof(s_b3000_NumElements),
  },
  {
    .bSubIndex = 1,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Dip_Inputdata",
  },
  {
    .bSubIndex = 2,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "CycleCnt",
  },
  {
    .bSubIndex = 3,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Alarm0_Code",
  },
  {
    .bSubIndex = 4,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Error0_Code",
  },
  {
    .bSubIndex = 5,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Alarm0",
  },
  {
    .bSubIndex = 6,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Error0",
  },
  {
    .bSubIndex = 7,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Uart_Inputdata0",
  },
  {
    .bSubIndex = 8,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Uart_Inputdata1",
  },
  {
    .bSubIndex = 9,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Alarm1",
  },
  {
    .bSubIndex = 10,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Error1",
  },
};
static const uint8_t s_b3000_NumElements = ARRCNT(g_tSiObj_3000) - 1; /* SI 00 does not counts */


static const uint8_t s_b4000_NumElements;
static const uint8_t s_bBooleanInitTrueValue = 1;
static const uint32_t s_ulValue12345678 = 0x12345678;

SUBOBJECT_DESCRIPTION_T g_tSiObj_4000[] =
{
  {
    .bSubIndex = 0,
    .bIndicationFlags = 0,
    .usAccessRights = ECAT_OD_READ_ALL,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .ulMaxFieldUnits = 1,
    .pszName = "Number of elements",
    .pvInitialValue = &s_b4000_NumElements,
    .ulInitialValueLength = sizeof(s_b4000_NumElements),
  },
  {
   .bSubIndex = 1,
   .bIndicationFlags = ODV3_INDICATION_FLAGS_ALLOWED_ON_SUBOBJ,
   .usAccessRights = ECAT_OD_ACCESS_ALL,
   .usDatatype = ECAT_OD_DTYPE_BOOLEAN,
   .ulMaxFieldUnits = 1,
   .pszName = "Flag 0",
  },
  {
   .bSubIndex = 2,
   .bIndicationFlags = ODV3_INDICATION_FLAGS_ALLOWED_ON_SUBOBJ,
   .usAccessRights = ECAT_OD_ACCESS_ALL,
   .usDatatype = ECAT_OD_DTYPE_BOOLEAN,
   .ulMaxFieldUnits = 1,
   .pszName = "Flag 1",
   .ulInitialValueLength = sizeof(s_bBooleanInitTrueValue),
   .pvInitialValue = &s_bBooleanInitTrueValue
 },
 {
   .bSubIndex = 3,
   .bIndicationFlags = ODV3_INDICATION_FLAGS_ALLOWED_ON_SUBOBJ,
   .usAccessRights = ECAT_OD_ACCESS_ALL,
   .usDatatype = ECAT_OD_DTYPE_UNSIGNED32,
   .ulMaxFieldUnits = 1,
   .pszName = "UINT32 Value",
   .ulInitialValueLength = sizeof(s_ulValue12345678),
   .pvInitialValue = &s_ulValue12345678
 },
};

static const uint8_t s_b4000_NumElements = ARRCNT(g_tSiObj_4000) - 1; /* SI 00 does not counts */


OBJECT_DESCRIPTION_T g_tObjects[] =
{
  {
    .usIndex = 0x1600,
    .bMaxNumOfSubObjs = ARRCNT(s_ab1600_Elements),
    .bObjectCode = ODV3_OBJCODE_RECORD,
    .usAccessFlags = 0,
    .bIndicationFlags = 0,
    .usDatatype = ECAT_OD_DTYPE_PDO_MAPPING,
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    /* no SimpleVar, therefore no ulMaxFieldUnits value */
    .pszName = "1. RxPDO",
    /* no SimpleVar, therefore no initial value */
    .ptSi00 = &g_tSiObj_1600[0],
    .ptSiBreak = &g_tSiObj_1600[ ARRCNT(g_tSiObj_1600) ],
  },
  {
    .usIndex = 0x1A00,
    .bMaxNumOfSubObjs = ARRCNT(s_ab1A00_Elements),
    .bObjectCode = ODV3_OBJCODE_RECORD,
    .usAccessFlags = 0,
    .bIndicationFlags = 0,
    .usDatatype = ECAT_OD_DTYPE_PDO_MAPPING,
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    /* no SimpleVar, therefore no ulMaxFieldUnits value */
    .pszName = "1. TxPDO",
    /* no SimpleVar, therefore no initial value */
    .ptSi00 = &g_tSiObj_1A00[0],
    .ptSiBreak = &g_tSiObj_1A00[ ARRCNT(g_tSiObj_1A00) ],
  },
  {
    .usIndex = 0x1C00,
    .bMaxNumOfSubObjs = 4,
    .bObjectCode = ODV3_OBJCODE_ARRAY,
    .usAccessFlags = 0,
    .bIndicationFlags = 0,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,//DEFTYPE_RECORD,
    .usAccessRights = ECAT_OD_READ_ALL,
    /* no SimpleVar, therefore no ulMaxFieldUnits value */
    .pszName = "Sync Manager Communication Types",
    /* no SimpleVar, therefore no initial value */
    .ptSi00 = &g_tSiObj_1C00[0],
    .ptSiBreak = &g_tSiObj_1C00[ ARRCNT(g_tSiObj_1C00) ],
  },
//  {
//    .usIndex = 0x1C10,
//    .bMaxNumOfSubObjs = 0,
//    .ulMaxFieldUnits = 1,
//    .bObjectCode = ODV3_OBJCODE_ARRAY,
//    .usAccessFlags = ODV3_ACCESS_FLAGS_CREATE_SUBINDEX_0 | ODV3_ACCESS_FLAGS_FORCE_INDEXED, /*this object has 0 subobjects but is not a simple var, so we have to set this both flags*/
//    .bIndicationFlags = 0,
//    .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,/**< \todo what exactly shall be used here */
//    .usAccessRights = ECAT_OD_READ_ALL,
//    /* no SimpleVar, therefore no ulMaxFieldUnits value */
//    .pszName = "Sync Manager 0 PDO Assignment",
//    /* no SimpleVar, therefore no initial value */
//    .ptSi00 = 0,
//  },
//  {
//    .usIndex = 0x1C11,
//    .bMaxNumOfSubObjs = 0,
//    .ulMaxFieldUnits = 1,
//    .bObjectCode = ODV3_OBJCODE_ARRAY,
//    .usAccessFlags = ODV3_ACCESS_FLAGS_CREATE_SUBINDEX_0 | ODV3_ACCESS_FLAGS_FORCE_INDEXED, /*this object has 0 subobjects but is not a simple var, so we have to set this both flags*/
//    .bIndicationFlags = 0,
//    .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,/**< \todo what exactly shall be used here */
//    .usAccessRights = ECAT_OD_READ_ALL,
//    /* no SimpleVar, therefore no ulMaxFieldUnits value */
//    .pszName = "Sync Manager 1 PDO Assignment",
//    /* no SimpleVar, therefore no initial value */
//    .ptSi00 = 0,
//  },
  {
    .usIndex = 0x1C12,
    .bMaxNumOfSubObjs = 1,
    .bObjectCode = ODV3_OBJCODE_ARRAY,
    .usAccessFlags = 0,
    .bIndicationFlags = 0,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,/**< \todo what exactly shall be used here */
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    /* no SimpleVar, therefore no ulMaxFieldUnits value */
    .pszName = "Sync Manager 1 PDO Assignment",
    /* no SimpleVar, therefore no initial value */
    .ptSi00 = &tSiObj_1C12[0],
    .ptSiBreak = &tSiObj_1C12[ ARRCNT(tSiObj_1C12) ],
  },
  {
    .usIndex = 0x1C13,
    .bMaxNumOfSubObjs = 1,
    .bObjectCode = ODV3_OBJCODE_ARRAY,
    .usAccessFlags = 0,
    .bIndicationFlags = 0,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED16,/**< \todo what exactly shall be used here */
    .usAccessRights = ECAT_OD_ACCESS_ALL,
    /* no SimpleVar, therefore no ulMaxFieldUnits value */
    .pszName = "Sync Manager 1 PDO Assignment",
    /* no SimpleVar, therefore no initial value */
    .ptSi00 = &g_tSiObj_1C13[0],
    .ptSiBreak = &g_tSiObj_1C13[ ARRCNT(g_tSiObj_1C13) ],
  },
  {
    .usIndex = 0x2000,
    .bMaxNumOfSubObjs = ARRCNT(g_tSiObj_2000) - 1,
    .bObjectCode = ODV3_OBJCODE_RECORD,
    .usAccessFlags = ODV3_ACCESS_FLAGS_RXPDO_MAPPABLE,
    .bIndicationFlags = 0,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,/**< \todo what exactly shall be used here */
    .usAccessRights = ECAT_OD_READ_ALL,
    /* no SimpleVar, therefore no ulMaxFieldUnits value */
    .pszName = "Outputs",
    /* no SimpleVar, therefore no initial value */
    .ptSi00 = &g_tSiObj_2000[0],
    .ptSiBreak = &g_tSiObj_2000[ ARRCNT(g_tSiObj_2000) ],
  },
  {
    .usIndex = 0x3000,
    .bMaxNumOfSubObjs = ARRCNT(g_tSiObj_3000) - 1,
    .bObjectCode = ODV3_OBJCODE_RECORD,
    .usAccessFlags = ODV3_ACCESS_FLAGS_TXPDO_MAPPABLE,
    .bIndicationFlags = 0,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,/**< \todo what exactly shall be used here */
    .usAccessRights = ECAT_OD_READ_ALL,
    /* no SimpleVar, therefore no ulMaxFieldUnits value */
    .pszName = "Inputs",
    /* no SimpleVar, therefore no initial value */
    .ptSi00 = &g_tSiObj_3000[0],
    .ptSiBreak = &g_tSiObj_3000[ ARRCNT(g_tSiObj_3000) ],
  },
  {
    .usIndex = 0x4000,
    .bMaxNumOfSubObjs = ARRCNT(g_tSiObj_4000) - 1,
    .ulMaxFieldUnits = 1,
    .bObjectCode = ODV3_OBJCODE_RECORD,
    .usAccessFlags = 0,
    .bIndicationFlags = 0,
    .usDatatype = ECAT_OD_DTYPE_UNSIGNED8,
    .usAccessRights = ECAT_OD_READ_ALL,
    .pszName = "Hello World Object",
    .ptSi00 = &g_tSiObj_4000[0],
    .ptSiBreak = &g_tSiObj_4000[ ARRCNT(g_tSiObj_4000) ],
  },
};

#endif /* COMPONENTS_CIFXAPPLICATIONDEMOECS_INCLUDES_APPECS_DEMO_OBJECT_DICTIONARY_H_ */
