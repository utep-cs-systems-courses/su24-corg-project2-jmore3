#include <msp430.h>
#include "switches.h"
#include "leds.h"
#include "libTimer.h"

char switch_state_downSW1,switch_state_downSW2, switch_state_downSW3, switch_state_downSW4, switch_state_changed;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES1 | p2val & SWITCHES2 | p2val & SWITCHES3 | p2val & SWITCHES4); //sense if down
  if(P2IES |= p2val & SWITCHES1){
    P2IES &= (p2val| ~SWITCHES1); //sense if up
  }
  if(P2IES |= p2val & SWITCHES2){
    P2IES &= (p2val| ~SWITCHES2); //sense if up
  }
  if(P2IES |= p2val & SWITCHES3){
    P2IES &= (p2val| ~SWITCHES3); //sense if up
  }
  if(P2IES |= p2val & SWITCHES4){
    P2IES &= (p2val| ~SWITCHES4); //sense if up
  }
  
  return p2val;
}

void
switch_init()
{
  P2REN |= SWITCHES1;
  P2IE |= SWITCHES1;
  P2OUT |= SWITCHES1;
  P2DIR &= ~SWITCHES1;
  
  P2REN |= SWITCHES2;
  P2IE |= SWITCHES2;
  P2OUT |= SWITCHES2;
  P2DIR &= ~SWITCHES2;

  P2REN |= SWITCHES3;
  P2IE |= SWITCHES3;
  P2OUT |= SWITCHES3;
  P2DIR &= ~SWITCHES3;

  P2REN |= SWITCHES4;
  P2IE |= SWITCHES4;
  P2OUT |= SWITCHES4;
  P2DIR &= ~SWITCHES4;
  switch_update_interrupt_sense();
  led_update();
}