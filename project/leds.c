#include <msp430.h>
#include "leds.h"
#include "switches.h"
#include "stateMachines.h"
#include "libTimer.h"


unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0;   //no LEDS on by deafult

    ledFlags |= switch_state_downSW2 ? LED_GREEN : 0;
    ledFlags |= switch_state_downSW2 ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
    
  }
  switch_state_changed = 0;
}
 

void led_dim_update(){  /*creates a dimmed red light*/
  if(switch_state_changed){
    char ledFlags = redVal[red_on];
    ledFlags |= switch_state_downSW1 ? 0 : LED_RED ;
    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;     
    led_changed = 0;
  }
}

void led_update_green(){ /*turns the green LED on*/
  if(switch_state_changed){
    char ledFlags =  greenVal[green_on];
    ledFlags |= switch_state_downSW3 ? LED_GREEN :  0 ;
    P1OUT &= (0xf^LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;

}

void led_siren(){
  if(switch_state_changed){
    char ledFlags =  greenVal[green_on];
    //(switch_state_downSW4){
    P1OUT &= (0xf^LEDS) | ledFlags;
    P1OUT |= ledFlags;
    state_advance();
    led_siren();
    
  }
  switch_state_changed = 0;
}