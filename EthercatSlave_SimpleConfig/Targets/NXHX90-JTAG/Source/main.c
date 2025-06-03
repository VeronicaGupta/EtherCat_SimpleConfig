#include "main.h"
#include <stdio.h>
DRV_UART_HANDLE_T tUART = { 0 };
void dioChaseLights(void);
void delay(size_t ulMiliseconds);
/*!
 * \brief The main entry point for the application.
 */
int main(void)
  {
    DRV_DIO_Init();

    tUART.tConfiguration.eDeviceID = DRV_UART_DEVICE_ID_UART2;
    tUART.tConfiguration.eOperationMode = DRV_OPERATION_MODE_POLL;
    tUART.tConfiguration.eBaudrate = DRV_UART_BAUDRATE_115200;
    tUART.tConfiguration.eWordLength = DRV_UART_WORD_LENGTH_8_BITS;
    tUART.tConfiguration.eLineControl =
  DRV_UART_LINE_CONTROL_MASK_FIFO_ENABLE;
    tUART.tConfiguration.eLoopBack = DRV_UART_LOOP_BACK_INACTIVE;
    DRV_UART_Init(&tUART);
    /** Deactivate all buffering */
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    printf("\n\r**** Application started ****\n\r");

    while(1)
    {
      dioChaseLights();
    }
    return 0;
  }
/*!
 * \brief This function implements a chase light on MMIO 4..7
 * that are the LEDs 0 to 3 on the NXHX evaluation board.
*/
void dioChaseLights(void)
{
  size_t channel;
  for(channel = 0; channel < 4; channel++)
  {
    DRV_DIO_ChannelOutSet(DRV_DIO_ID_MMIO_4 + channel);
    delay(1000/8);
  }
  for(channel = 0; channel < 4; channel++)
  {
    DRV_DIO_ChannelOutReset(DRV_DIO_ID_MMIO_4 + channel);
    delay(1000/8);
  }
}
/*!
 * \brief Helper function with a simple busy delay
 */
void delay(size_t ulMiliseconds)
{
  size_t const ulCalibrationValue = 41u;
  size_t volatile ns, ms;
  for(ms = 0; ms < ulMiliseconds; ms++)
  {
    while(ns < 100000000)
    {
      ns += ulCalibrationValue;
    }
  }
}

/*!
 * \brief Retargets the C library printf function to the UART.
 * \param iFile File handle
 * \param pvBuffer Data to write to file
 * \param iBytes number of bytes to write
 * \return number of bytes successfully written
 */
uint32_t _write(int iFile, const void* pvBuffer, uint32_t iBytes)
{
  DRV_UART_Transmit(&tUART, pvBuffer, iBytes);
  return iBytes;
}
