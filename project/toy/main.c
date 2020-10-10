#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "play.h"

int main() {
    configureClocks();
    enableWDTInterrupts();
    buzzer_init();
    void
    __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
      static char buzzer_count = 0;
      static char state = 0;
      static int riff = 0;
      static int riff2 = 0;
    start:
      if (++buzzer_count == 100) {
	switch (state){
	case 0:
	  play(0xE5);
	  //buzzer_set_period(9090.90);
	  state = 1;
	  break;
	  
	case 1:
	  play(0xB4);
	  //buzzer_set_period(6067.44);
	  state = 2;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 2:
	  play(0xC5);
	  //buzzer_set_period(4049.54);
	  state = 3;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 3:
	  play(0xD5);
	  //buzzer_set_period(3822.25);
	  state = 4;
	  break;

	case 4:
	  play(0xC5);
	  state = 5;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 5:
	  play(0xB4);
	  //buzzer_set_period(0);
	  state = 6;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 6:
	  play(0xA4);
	  state = 7;
	  buzzer_count = 5;
	  goto start;
	  break;
	
	case 7:
	  buzzer_set_period(0);
	  state = 8;
	  buzzer_count = 95;
	  goto start;
	  break;
	

        case 8:
	  play(0xA4);
	  //buzzer_set_period(10204.18);
	  state = 9;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 9:
	  play(0xC5);
	  //buzzer_set_period(7644.50);
	  state = 10;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 10:
	  play(0xE5);
	  state = 11;
	  break;
	  
	case 11:
	  play(0xD5);
	  //buzzer_set_period(5102.10);
	  state = 12;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 12:
	  play(0xC5);
	  //buzzer_set_period(4545.45);
	  state = 13;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 13:
	  play(0XB4);
	  state = 14;
	  buzzer_count = 5;
	  goto start;
	  break;

	case 14:
	  buzzer_set_period(0);
	  state = 15;
	  buzzer_count = 95;
	  goto start;
	  break;

	case 15:
	  play(0xB4);
	  state = 16;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 16:
	  play(0xC5);
	  state = 17;
	  buzzer_count = 50;
	  goto start;
	  break;

        case 17:
	  play(0xD5);
	  state = 18;
	  break;

	case 18:
	  play(0xE5);
	  state = 19;
	  break;

	case 19:
	  play(0xC5);
	  state = 20;
	  break;

	case 20:
	  play(0xA4);
	  state = 21;
	  buzzer_count = 5;
	  goto start;
	  break;

	case 21:
	  play(0);
	  state = 22;
	  buzzer_count = 95;
	  goto start;
	  break;

	case 22:
	  play(0xA4);
	  state = 23;
	  buzzer_count = 5;
	  goto start;
	  break;

	case 23:
	  play(0);
	  state = 0;
	  buzzer_count = 95;
	  goto start;
	  break;
	  
	}    
	buzzer_count = 0; 
      }
      
      /*  Californication Intro
      if (++buzzer_count == 99) {
	switch (state){
	case 0:
	  play(0xA3);
	  //buzzer_set_period(9090.90);
	  state = 1;
	  break;
	  
	case 1:
	  play(0xE4);
	  //buzzer_set_period(6067.44);
	  state = 2;  
	  break;

	case 2:
	  play(0xB4);
	  //buzzer_set_period(4049.54);
	  state = 3;
	  break;

	case 3:
	  play(0xC5);
	  //buzzer_set_period(3822.25);
	  state = 4;
	  break;

	case 4:
	  
	  state = 5;
	  break;

	case 5:
	  buzzer_set_period(0);
	  state = 6;
	  break;

	case 6:
      
	  state = 7;
	  break;
	
	case 7:
	  buzzer_set_period(0);
	  state = 8;
	  break;
	

        case 8:
	  play(0x63);
	  //buzzer_set_period(10204.18);
	  state = 9;
	  break;

	case 9:
	  play(0xC4);
	  //buzzer_set_period(7644.50);
	  state = 11;
	  break;

	case 11:
	  play(0x64);
	  //buzzer_set_period(5102.10);
	  state = 12;
	  break;

	case 12:
	  play(0xA6);
	  //buzzer_set_period(4545.45);
	  state = 13;
	  break;

	case 13:
	  
	  state = 14;
	  break;

	case 14:
	  buzzer_set_period(0);
	  state = 15;
	  break;

	case 15:
      
	  state = 0;
	  break;
	
      
	}  
	buzzer_count = 0; 
      }*/
    }
    or_sr(0x18);         // CPU off, GIE on
}
