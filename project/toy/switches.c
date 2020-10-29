#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHESG);	/* if switch up, sense down */
  //P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
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

  //*************************switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */  //RICARDO NO TENIA LA LINEA DE ARRIBA Y ESTA LA TIENE SIN COMENTARIO, CALALA DESPUES

  //switch_state_changed = (switch_state_changed+1)%2;
  
  //if(p2val & S1 == 0)
    //switch_state_changed = 0;
    switch_state_changed = !switch_state_changed;
    /*
  else if(p2val & S2 == 0)
    switch_state_changed = 1;
    */
  //led_update();
}
