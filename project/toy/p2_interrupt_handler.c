#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

extern float max_count;
char button_pressed = 4;
/* Switches on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & S1) {	      /* did a button cause this interrupt? */
    P2IFG &= ~S1;		      /* clear pending sw interrupts */
    button_pressed = (button_pressed + 1)%2;
    //switch_interrupt_handler();	/* single handler for all switches */
  }

  else if(P2IFG & S2) {
    P2IFG &= ~S2;
    static unsigned char speed = 0;
    if(speed)
      max_count = 50;

    else
      max_count = 200;

    speed = !speed;
  }

  else if(P2IFG & S3) {
    P2IFG &= ~S3;
    max_count = 100;
  }
  
  else if(P2IFG & S4){
    P2IFG &= ~S4;
    button_pressed = 4;
    red_on = 0;
    green_on = 0;
    led_changed = 1;
    led_update();
  }

  
}
