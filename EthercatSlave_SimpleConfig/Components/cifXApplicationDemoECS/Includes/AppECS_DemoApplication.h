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

#ifndef COMPONENTS_CIFXAPPLICATIONDEMOEIS_INCLUDES_APPEIS_DEMOAPPLICATION_H_
#define COMPONENTS_CIFXAPPLICATIONDEMOEIS_INCLUDES_APPEIS_DEMOAPPLICATION_H_

#include "App_DemoApplication.h"

/***************************************************************************************/

#define ECS_DEMO_CHANNEL_INDEX  0

/*************************************************************************************/
/*************************************************************************************/

long SetConfigParams( void* pvPck, uint16_t usDeviceClass );
long SetModulConfig( void* pvPck );

bool     AppECS_PacketHandler( CIFX_PACKET* ptPacket, void* pvUserData );
uint32_t AppECS_ConfigureStack( APP_DATA_T* ptAppData );

#endif /* COMPONENTS_CIFXAPPLICATIONDEMOEIS_INCLUDES_APPEIS_DEMOAPPLICATION_H_ */
