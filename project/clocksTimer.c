#include <msp430.h>
#include "libTimer.h"

void configureClocks(){
  WDTCTL = WDTPW + WDTHOLD; //disable timer
  BCSCTL1 = CALBC1_16MHZ;    //Set DCO 16 Mhz
  DCOCTL = CALDCO_16MHZ;

  BCSCTL2 &= ~(SELS);
  BCSCTL2 |=DIVS_3;
}

void enableWDTInterrupts()
{
  WDTCTL = WDTPW |
    WDTTMSEL |    //interval mode
    WDTCNTCL |    //clear watchdog count
    1;            //divide SMCLK by 8192
  IE1 |= WDTIE; //enable interval timer interrupt
}

void timerAUpmode()
{
  TA0CCR0 = 0;
  TA0CCR1 = 0;
  TA0CCTL1 = OUTMOD_3;

  TACTL = TASSEL_2 + MC_1;
}
 