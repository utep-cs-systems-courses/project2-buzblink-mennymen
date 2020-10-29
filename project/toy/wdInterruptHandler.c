#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "play.h"
#include "stateMachines.h"
#include "switches.h"

int count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static unsigned char state = 0;
  static char blink_state = 0;
  
  /*
      if ((++count%25) == 0) buzzer_advance();

      if(count == 250){
	alarm_advance();
	count = 0;
	}*/
      
      /*
      if (++count == 80){
        count = 0;
	zelda_advance();
      }*/


      
      if (++count != 100){
	switch(blink_state){
	case 0:
	  red_on = 1;
	  green_on = 0;
	  break;

	case 1:
	  red75();
	  green25();
	  break;

	case 2:
	  red50();
	  green50();
	  break;

	case 3:
	  red25();
	  green75();
	  break;

	case 4:
	  red_on = 0;
          green_on = 1;
	  break;

	case 5:
	  red25();
	  green75();
	  break;

	case 6:
	  red50();
	  green50();
	  break;

	case 7:
	  red75();
	  green25();
	  break;
	}
	led_changed = 1;
	led_update();
      } else{
	blink_state = (blink_state+1)%8;
	count = 0;
	extern char button_pressed;
	if(button_pressed == 1)
	  tetris_advance();
	else if (button_pressed == 0)
	  zelda_advance();
	else
	  play(0);
      }
       
}
