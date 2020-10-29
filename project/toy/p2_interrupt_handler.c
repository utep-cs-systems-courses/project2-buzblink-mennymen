#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

char button_pressed;

/* Switches on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & S1) {	      /* did a button cause this interrupt? */
    P2IFG &= ~S1;		      /* clear pending sw interrupts */
    button_pressed = 1;
    //switch_interrupt_handler();	/* single handler for all switches */
  }

  else if(P2IFG & S2) {
    P2IFG &= ~S2;
    button_pressed = 0;
  }
  
  else if(P2IFG & S4){
    P2IFG &= ~S4;
    button_pressed = 4;
  }

  
}
