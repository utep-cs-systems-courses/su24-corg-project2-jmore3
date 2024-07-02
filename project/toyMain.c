#include <msp430.h>
#include "libTimer.h"
#include "leds.h"
#include "switches.h"
#include "melody.h"

int main(void){
  configureClocks();
  switch_init();
  led_init();
  enableWDTInterrupts();
  melody_init();

  or_sr(0x18);
}