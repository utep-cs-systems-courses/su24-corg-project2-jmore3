#ifndef led_included
#define led_included

#define LED_RED BIT6               // P1.6
#define LED_GREEN BIT0             // P1.0
#define LEDS (BIT6 | BIT0)

extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init();		/* initialize LEDs */
void led_update();		/* update leds */

// these are boolean flags
extern unsigned char leds_changed, green_led_state, red_led_state;

#endif // included