#include "main.h"
void dioChaseLights(void);
void delay(size_t ulMiliseconds);
/*!
 * \brief The main entry point for the application.
 */
int main(void)
  {
    DRV_DIO_Init();
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
