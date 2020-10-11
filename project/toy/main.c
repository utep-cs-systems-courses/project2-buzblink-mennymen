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
      if (++buzzer_count == 80) {
	switch (state){
	case 0:
	  play(0x65);
	  state = 1;
	  break;
	  
	case 1:
	  play(0x64);
	  state = 2;
	  break;

	case 2:
	  play(0xC5);
	  state = 3;
	  break;

	case 3:
	  play(0xE5);
	  state = 4;
	  break;

	case 4:
	  play(0xD51);
	  state = 5;
	  break;

	case 5:
	  play(0x64);
	  state = 6;
	  break;

	case 6:
	  play(0xB5);
	  state = 7;
	  break;
	
	case 7:
	  play(0xB4);
	  state = 8;
	  break;
	
        case 8:
	  play(0xA5);
	  state = 9;
	  break;

	case 9:
	  play(0xC5);
	  state = 10;
	  break;

	case 10:
	  play(0xE5);
	  state = 11;
	  break;
	  
	case 11:
	  play(0xA5);
	  state = 12;
	  break;

	case 12:
	  play(0x65);
	  state = 13;
	  break;

	case 13:
	  play(0xC5);
	  state = 14;
	  break;

	case 14:
	  play(0xD5);
	  state = 15;
	  break;

	case 15:
	  play(0xE5);
	  state = 16;
	  break;

	case 16:
	  play(0xA5);
	  state = 17;
	  break;

        case 17:
	  play(0xC5);
	  state = 18;
	  break;

	case 18:
	  play(0xF5);
	  state = 19;
	  break;

	case 19:
	  play(0xA5);
	  state = 20;
	  break;

	case 20:
	  play(0x651);
	  state = 21;
	  break;

	case 21:
	  play(0xC5);
	  state = 23;
	  break;
	  
	case 23:
	  play(0xD5);
	  state = 24;
	  break;

	case 24:
	  play(0xF5);
	  state = 25;
	  break;
	  
	case 25:
	  play(0xE5);
	  state = 26;
	  break;

	case 26:
	  play(0x64);
	  state = 27;
	  break;

	case 27:
	  play(0xC5);
	  state = 28;
	  break;


	case 28:
	  play(0xE5);
	  state = 29;
	  break;

	case 29:
	  play(0xD5);
	  state = 30;
	  break;

	case 30:
	  play(0xA4);
	  state = 31;
	  break;

	case 31:
	  play(0xB4);
	  state = 32;
	  break;

	case 32:
	  play(0xD5);
	  state = 0;
	  break;
	}
	  
	buzzer_count = 0; 
      }

      /*
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
	  state = 24;
	  buzzer_count = 95;
	  goto start;
	  break;

	case 24:
	  play(0);
	  state = 245;
	  break;

	case 245:
	  state = 25;
	  buzzer_count = 50;
	  goto start;
	  break;
	  
	case 25:
	  play(0xD5);
	  state = 26;
	  break;

	case 26:
	  play(0xF5);
	  state = 27;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 27:
	  play(0xA5);
	  state = 28;
	  break;


	case 28:
	  play(0x65);
	  state = 29;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 29:
	  play(0xF5);
	  state = 30;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 30:
	  play(0xE5);
	  state = 135;
	  break;

	case 135:
	  state = 31;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 31:
	  play(0xC5);
	  state = 32;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 32:
	  play(0xE5);
	  state = 33;
	  break;

	case 33:
	  play(0xD5);
	  state = 34;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 34:
	  play(0xC5);
	  state = 35;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 35:
	  play(0xB4);
	  state = 36;
	  break;

	case 36:
	  play(0);
	  state = 37;
	  buzzer_count = 95;
	  goto start;
	  break;

        case 37:
	  play(0xB4);
	  state = 38;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 38:
	  play(0xC5);
	  state = 39;
	  buzzer_count = 50;
	  goto start;
	  break;

	case 39:
	  play(0xD5);
	  state = 40;
	  break;

	case 40:
	  play(0xE5);
	  state = 41;
	  break;
	  
       	case 41:
	  play(0xC5);
	  state = 42;
	  break;

	case 42:
	  play(0xA4);
	  state = 43;
	  break;

 	case 43:
	  play(0);
	  state = 44;
	  buzzer_count = 95;
	  goto start;
	  break;

	case 44:
	  play(0xA4);
	  state = 45;
	  break;

 	case 45:
	  play(0);
	  state = 46;
	  break;

	case 46:
	  play(0xE4);
	  state = 47;
	  break;

	case 47:
	  state = 48;
	  break;

 	case 48:
	  play(0xC4);
	  state = 133;
	  break;

        case 133:
	  state = 49;
	  break;
	  
	case 49:
	  play(0xD4);
	  state = 50;
	  break;

 	case 50:
	  state = 51;
	  break;

	case 51:
	  play(0xB3);
	  state = 52;
	  break;

	case 52:
	  state = 53;
	  break;

	case 53:
	  play(0xC4);
	  state = 54;
	  break;

 	case 54:
	  state = 55;
	  break;

	case 55:
	  play(0xA3);
	  state = 56;
	  break;	 

	case 56:
	  state = 57;
	  break;

 	case 57:
	  play(0x631);
	  state = 58;
	  break;

 	case 58:
	  state = 59;
	  break;

	case 59:
	  play(0xB3);
	  state = 60;
	  break;

	case 60:
	  state = 61;
	  break;

 	case 61:
	  play(0xE4);
	  state = 62;
	  break;

 	case 62:
	  state = 63;
	  break;

	case 63:
	  play(0xC4);
	  state = 64;
	  break;

	case 64:
	  state = 65;
	  break;

	case 65:
	  play(0xD4);
	  state = 66;
	  break;

 	case 66:
	  state = 67;
	  break;

	case 67:
	  play(0xB3);
	  state = 68;
	  break;	  

	case 68:
	  state = 69;
	  break;

	case 69:
	  play(0xC4);
	  state = 70;
	  break;

 	case 70:
	  play(0xE4);
	  state = 71;
	  break;

	case 71:
	  play(0xA4);
	  state = 72;
	  break;

	case 72:
	  play(0);
	  state = 73;
	  buzzer_count = 95;
	  goto start;
	  break;

 	case 73:
	  play(0xA4);
	  state = 74;
	  break;

	case 74:
	  play(0x641);
	  state = 75;
	  break;

 	case 75:
	  state = 76;
	  break;

	case 76:
	  state = 77;
	  break;

	case 77:
	  state = 0;
	  break;
	}
	  
	buzzer_count = 0; 
      }
      */      
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
