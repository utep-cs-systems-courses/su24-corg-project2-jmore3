#ifndef switches_included
#define switches_included

#define SW1 BIT0              //SW1 is p2.0
#define SW2 BIT1              //SW2 is p2.1
#define SW3 BIT2              //SW3 is p2.2
#define SW4 BIT3              //SW4 is p2.3

#define SWITCHES1 SW1
#define SWITCHES2 SW2
#define SWITCHES3 SW3
#define SWITCHES4 SW4

void switch_init();
void switch_interrupt_handlerSW1();
void switch_interrupt_handlerSW2();
void switch_interrupt_handlerSW3();
void switch_interrupt_handlerSW4();

extern char switch_state_downSW1, switch_state_downSW2, switch_state_downSW3, switch_state_downSW4, switch_state_changed;

#endif