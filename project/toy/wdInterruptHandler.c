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
  /*
      if ((++count%25) == 0) buzzer_advance();

      if(count == 250){
	alarm_advance();
	count = 0;
	}*/
         
      if (++count != max_count && button_pressed != 4){
	leds_advance();
      } else{
	blink_state = (blink_state+1)%8;
	count = 0;
	if(button_pressed == 1){
	  max_count = 50;
	  megaman_advance();
	}
	else if (button_pressed == 0){
	  zelda_advance();
	}

	else if (button_pressed == 2){
	  tetris_advance();
	}
	
	else
	  play(0);
      }       
}
