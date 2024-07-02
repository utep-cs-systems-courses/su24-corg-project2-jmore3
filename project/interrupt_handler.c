#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES1){            /*P2IFG Interrupt flag*/
    P2IFG &= ~SWITCHES1;
    switch_interrupt_handlerSW1();
  }
  if(P2IFG & SWITCHES2){
    P2IFG &= ~SWITCHES2;
    switch_interrupt_handlerSW2();
  }
  if(P2IFG & SWITCHES3){
    P2IFG &= ~SWITCHES3;
    switch_interrupt_handlerSW3();
  }
  if(P2IFG & SWITCHES4){
    P2IFG &= ~SWITCHES4;
    switch_interrupt_handlerSW4();
  }
}