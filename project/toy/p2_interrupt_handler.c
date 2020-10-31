#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

extern float max_count;
char button_pressed = 4; /* This variable is set to 4 so there are no leds or sounds when we first load the msp430 */

/* Switches on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & S1) {	      /* S1 is used to change song */
    P2IFG &= ~S1;		      /* clear pending sw interrupts */
    button_pressed = (button_pressed + 1)%3;
    if(button_pressed == 0) /* When button pressed is equal to 0, it will play the megaman song, which is twice as fast as the other two */
      max_count = 50;

    else                  
      max_count = 100;
  } else if(P2IFG & S2) {   /* S2 is used to toggle between setting the speed or half as fast or twice as fast (except for the megaman song) */
    P2IFG &= ~S2;
    static unsigned char speed = 0;
    if(speed)  /* Make song go twice as fast */
      max_count = 50;

    else /* Make song go twice as slow */
      max_count = 200;

    speed = !speed;  /* speed is set to the opposite value so it toggles between setting the song fast and slow */
    
  } else if(P2IFG & S3) {  /* S3 is used to reset the speed to normal */
    P2IFG &= ~S3;
    max_count = 100;
    
  } else if(P2IFG & S4){  /* S4 is used to turn the buzzer and leds off */
    P2IFG &= ~S4;
    button_pressed = 4;
    red_on = 0;
    green_on = 0;
    led_changed = 1;
    led_update();
  }
}
