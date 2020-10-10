#include <msp430.h>
#include "libTimer.h"
#include "play.h"
#include "buzzer.h"
#include <string.h>


void play(int note)
{
  if(note == 0xC3)
     buzzer_set_period(15289.00);
  
  else if(note == 0xC31)
    buzzer_set_period(14430.95);
  
  else if(note == 0xD3)
    buzzer_set_period(13621.00);

  else if(note == 0xD31)
    buzzer_set_period(12856.52);
  
  else if(note == 0xE3)
    buzzer_set_period(12134.89);

  else if(note == 0xF3)
    buzzer_set_period(11453.83);

  else if(note == 0xF31)
    buzzer_set_period(10810.98);

  else if(note == 0x63)
    buzzer_set_period(10204.18);

  else if(note == 0x631)
    buzzer_set_period(9631.49);

  else if(note == 0xA3)
    buzzer_set_period(9090.90);

  else if(note == 0xA31)
    buzzer_set_period(8580.67);

  else if(note == 0xB3)
    buzzer_set_period(8099.06);
  
  else if(note == 0xC4)
     buzzer_set_period(7644.50);
    
  else if(note == 0xC41)
    buzzer_set_period(7215.44);

  else if(note == 0xD4)
    buzzer_set_period(6810.48);

  else if(note == 0xD41)
    buzzer_set_period(6428.24);
  
  else if(note == 0xE4)
    buzzer_set_period(6067.44);
  
  else if(note == 0xF4)
    buzzer_set_period(5726.91);

  else if(note == 0xF41)
    buzzer_set_period(5405.49);

  else if(note == 0x64)
    buzzer_set_period(5102.10);

  else if(note == 0x641)
    buzzer_set_period(4815.73);

  else if(note == 0xA4)
    buzzer_set_period(4545.45);

  else if(note == 0xA41)
    buzzer_set_period(4290.33);

  else if(note == 0xB4)
    buzzer_set_period(4049.54);

  else if(note == 0xC5)
     buzzer_set_period(3822.25);
    
  else if(note == 0xC51)
    buzzer_set_period(3607.73);

  else if(note == 0xD5)
    buzzer_set_period(3405.24);

  else if(note == 0xD51)
    buzzer_set_period(3214.12);
  
  else if(note == 0xE5)
    buzzer_set_period(3033.72);

  else if(note == 0xF5)
    buzzer_set_period(2863.45);

  else if(note == 0xF51)
    buzzer_set_period(2702.74);

  else if(note == 0x65)
    buzzer_set_period(2551.04);

  else if(note == 0x651)
    buzzer_set_period(2407.87);

  else if(note == 0xA5)
    buzzer_set_period(2272.72);

  else if(note == 0xA51)
    buzzer_set_period(2145.16);

  else if(note == 0xB5)
    buzzer_set_period(2024.76);

  else if(note == 0xC6)
     buzzer_set_period(1911.13);
    
  else if(note == 0xC61)
    buzzer_set_period(1803.86);

  else if(note == 0xD6)
    buzzer_set_period(1702.62);

  else if(note == 0xD61)
    buzzer_set_period(1607.05);
  
  else if(note == 0xE6)
    buzzer_set_period(1516.86);

  else if(note == 0xF6)
    buzzer_set_period(1431.73);

  else if(note == 0xF61)
    buzzer_set_period(1351.36);

  else if(note == 0x66)
    buzzer_set_period(1275.52);

  else if(note == 0x661)
    buzzer_set_period(1203.93);
	  
  else if(note == 0xA6)
    buzzer_set_period(1136.36);

  else if(note == 0xA61)
    buzzer_set_period(1072.58);

  else if(note == 0xB6)
    buzzer_set_period(1012.38);
   
  else 
    buzzer_set_period(0);
}


