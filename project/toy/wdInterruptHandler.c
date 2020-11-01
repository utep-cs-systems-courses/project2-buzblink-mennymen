#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "play.h"
#include "stateMachines.h"
#include "switches.h"

char count = 0;
float max_count = 100;     
extern char button_pressed;
char blink_state = 0;
void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static unsigned char state = 0;
  
  /*  This was for the alarm we did as homework, left it to prove I did it.
      if ((++count%25) == 0) buzzer_advance();

      if (count == 250) {
	alarm_advance();
	count = 0;
	}*/
         
      if (++count != max_count && button_pressed != 4) {   
	leds_advance();   /* The leds will keep lighting, except for the instance when the song state advances */
	
      } else {
	blink_state = (blink_state+1)%8;  /* Go to the next led state */
	count = 0;
	if (button_pressed == 0) {   /* S1 cycles through 3 songs */
	  megaman_advance();
	} else if (button_pressed == 1) {
	  zelda_advance();
	} else if (button_pressed == 2) {
	  tetris_advance();
	} else /* S4 will turn the leds off, as well as the buzzer */
	  play(0);
      }       
}
