#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include <string.h>

void buzzer_init()
{
  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */
  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;/* one half cycle */
}
/*
void play(char *note)
{
  if(strcmp(note,"C3" == 0))
     buzzer_set_period(15289.00);
  
  else if(strcmp(note,"C3#" == 0))
    buzzer_set_period(14430.95);

  else if(strcmp(note,"D3" == 0))
    buzzer_set_period(13621.00);

  else if(strcmp(note,"D3#" == 0))
    buzzer_set_period(12856.52);
  
  else if(strcmp(note,"E3" == 0))
    buzzer_set_period(12134.89);

  else if(strcmp(note,"F3" == 0))
    buzzer_set_period(11453.83);

  else if(strcmp(note,"F3#" == 0))
    buzzer_set_period(10810.98);

  else if(strcmp(note,"G3" == 0))
    buzzer_set_period(10204.18);

  else if(strcmp(note,"G3#" == 0))
    buzzer_set_period(9631.49);

  else if(strcmp(note,"A3" == 0))
    buzzer_set_period(9090.90);

  else if(strcmp(note,"A3#" == 0))
    buzzer_set_period(8580.67);

  else if(strcmp(note,"B3" == 0))
    buzzer_set_period(8099.06);

  else if(strcmp(note,"C4" == 0))
     buzzer_set_period(7644.50);
    
  else if(strcmp(note,"C4#" == 0))
    buzzer_set_period(7215.44);

  else if(strcmp(note,"D4" == 0))
    buzzer_set_period(6810.48);

  else if(strcmp(note,"D4#" == 0))
    buzzer_set_period(6428.24);
  
  else if(strcmp(note,"E4" == 0))
    buzzer_set_period(6067.44);

  else if(strcmp(note,"F4" == 0))
    buzzer_set_period(5726.91);

  else if(strcmp(note,"F4#" == 0))
    buzzer_set_period(5405.49);

  else if(strcmp(note,"G4" == 0))
    buzzer_set_period(5102.10);

  else if(strcmp(note,"G4#" == 0))
    buzzer_set_period(4815.73);

  else if(strcmp(note,"A4" == 0))
    buzzer_set_period(4545.45);

  else if(strcmp(note,"A4#" == 0))
    buzzer_set_period(4290.33);

  else if(strcmp(note,"B4" == 0))
    buzzer_set_period(4049.54);

  else if(strcmp(note,"C5" == 0))
     buzzer_set_period(3822.25);
    
  else if(strcmp(note,"C5#" == 0))
    buzzer_set_period(3607.73);

  else if(strcmp(note,"D5" == 0))
    buzzer_set_period(3405.24);

  else if(strcmp(note,"D5#" == 0))
    buzzer_set_period(3214.12);
  
  else if(strcmp(note,"E5" == 0))
    buzzer_set_period(3033.72);

  else if(strcmp(note,"F5" == 0))
    buzzer_set_period(2863.45);

  else if(strcmp(note,"F5#" == 0))
    buzzer_set_period(2702.74);

  else if(strcmp(note,"G5" == 0))
    buzzer_set_period(2551.04);

  else if(strcmp(note,"G5#" == 0))
    buzzer_set_period(2407.87);

  else if(strcmp(note,"A5" == 0))
    buzzer_set_period(2272.72);

  else if(strcmp(note,"A5#" == 0))
    buzzer_set_period(2145.16);

  else if(strcmp(note,"B5" == 0))
    buzzer_set_period(2024.76);

  else if(strcmp(note,"C6" == 0))
     buzzer_set_period(1911.13);
    
  else if(strcmp(note,"C6#" == 0))
    buzzer_set_period(1803.86);

  else if(strcmp(note,"D6" == 0))
    buzzer_set_period(1702.62);

  else if(strcmp(note,"D6#" == 0))
    buzzer_set_period(1607.05);
  
  else if(strcmp(note,"E6" == 0))
    buzzer_set_period(1516.86);

  else if(strcmp(note,"F6" == 0))
    buzzer_set_period(1431.73);

  else if(strcmp(note,"F6#" == 0))
    buzzer_set_period(1351.36);

  else if(strcmp(note,"G6" == 0))
    buzzer_set_period(1275.52);

  else if(strcmp(note,"G6#" == 0))
    buzzer_set_period(1203.93);
	  
  else if(strcmp(note,"A6" == 0))
    buzzer_set_period(1136.36);

  else if(strcmp(note,"A6#" == 0))
    buzzer_set_period(1072.58);

  else if(strcmp(note,"B6" == 0))
    buzzer_set_period(1012.38);
  
  else 
    buzzer_set_period(0);
    }*/


