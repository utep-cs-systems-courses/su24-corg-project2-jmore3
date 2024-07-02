#include <msp430.h>
#include "libTimer.h"
#include "melody.h"
#include "switches.h"

void melody_init(){
  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}
void tone(int tone, int duration){  /*assigns tone and duration to CCR0 and CCR1*/
  for (int i =0; i<duration; i++){
     CCR0 = tone;
     CCR1 = tone>>1;
     __delay_cycles(400);
       }
  }
void audio_siren(){   /*Siren that goes from frequency 2000 to 4000 and the comes back to 2000*/
  for(int i = 2000; i< 4000; i++){
      tone(i,80);
   }
  for(int j = 4000; j> 2000; j--){
    tone(j,80);
  }
  tone(0,10000);
  switch_state_changed = 1;
}

void melody_play(){  /*plays a short melody when called*/
  if(!switch_state_changed){
    tone(3824,7000);//C
    tone(3034,7000);//E
    tone(2551,7000);//G
    tone(1911,7000);//C
    tone(0,1000);
    tone(1911,7000);//C
    tone(0,1000);
    tone(1911,7000);//C
    tone(0,1000);
    tone(2551,7000);//G
    tone(0,1000);
    tone(2551,7000);//G
    tone(0,1000);
    tone(2551,7000);//G
    tone(0,1000);
    tone(3034,7000);//E
    tone(2551,7000);//G
    tone(3034,7000);//E
    tone(3824,7000);//C
    
    tone(0,10000);
  }
  switch_state_changed = 1;
}