#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
char button_pressed = 4; /* This variable is set to 4 so there are no leds or sounds when we first load the msp430 */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHESG);	/* if switch up, sense down */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHESG;		/* enables resistors for switches */
  P2IE |= SWITCHESG;		/* enable interrupts from switches */
  P2OUT |= SWITCHESG;		/* pull-ups for switches */
  P2DIR &= ~SWITCHESG;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = !switch_state_down;
  switch_state_changed = !switch_state_changed;
}
