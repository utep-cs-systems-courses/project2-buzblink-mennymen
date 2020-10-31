#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "play.h"

static short sb = 1;
static short x = 500;
static unsigned char tetris_notes[81] = {0xE5,0xB4,0xC5,0xD5,0xC5,0xB4,0xA4,0,0xA4,0xC5, 
					 0xE5,0xD5,0xC5,0xB4,0,0xB4,0xC5,0xD5,0xE5,0xC5,
					 0xA4,0,0xA4,0,0,0,0xD5,0xF5,0xA5,0x65,
					 0xF5,0xE5,1,0xC5,0xE5,0xD5,0xC5,0xB4,0,0xB4,
					 0xC5,0xD5,0xE5,0xC5,0xA4,0,0xA4,0,0xE4,1,
					 0xC4,1,0xD4,1,0xB3,1,0xC4,1,0xA3,1,
					 0x6A,1,0xB3,1,0xE4,1,0xC4,1,0xD4,1,
					 0xB3,1,0xC4,0xE4,0xA4,0,0xA4,0x6B,1,1,
					 1};
static unsigned char tetris_duration[81] = {0,50,50,0,50,50,5,95,50,50,
					    0,50,50,5,95,50,50,0,0,0,
					    5,95,5,95,0,50,0,50,0,50,
					    50,0,50,50,0,50,50,0,95,50,
					    50,0,0,0,0,95,0,0,0,0,
					    0,0,0,0,0,0,0,0,0,0,
					    0,0,0,0,0,0,0,0,0,0,
					    0,0,0,0,0,95,0,0,0,0,
					    0};

static unsigned char zelda_notes[32] = {0x65,0x64,0xC5,0xE5,0xDC,0x64,0xB5,0xB4,0xA5,0xC5,
					0xE5,0xA5,0x65,0xC5,0xD5,0xE5,0xA5,0xC5,0xF5,0xA5,
					0x6C,0xC5,0xD5,0xF5,0xE5,0x64,0xC5,0xE5,0xD5,0xA4,
					0xB4,0xD5};

static unsigned char megaman_notes[38] = {0xC5,0,0xC5,0,0xC5,0xAB,0xC5,1,1,0xD5,
					  0,0xD5,0,0xD5,0xC5,0xD5,1,1,0xDB,0,
				  	  0xDB,0,0xDB,0,0xFB,0,0xFB,0,0xFB,0,
					  0x65,0xF5,0xDB,0xF5,0xFB,0x65,1,1};

static unsigned char megaman_duration[38] = {25,95,50,95,25,50,50,0,0,25,
					     95,50,95,25,50,50,0,0,25,95,
					     50,95,25,0,25,95,50,95,25,0,
					     50,50,25,25,25,25,1,1};



void red75() /* Red led shines at 75% intensity */
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0: /* The led is on for 3 out of the 4 states */
    red_on = 1;
    state = 1;
    changed = 1;
    break;

  case 1:
    red_on = 1;
    state = 2;
    break;

  case 2:
    red_on = 1;
    state = 3;
    break;

  case 3:
    red_on = 0;
    state = 0;
    changed = 1;
  }

  led_changed = changed;
  led_update();
}


void red50() /* Red led shines at 50% intensity */
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0: /* The led is on for 1 out of the 2 states */
    red_on = 1;
    state = 1;
    changed = 1;
    break;

  case 1:
    red_on = 0;
    state = 0;
    changed = 1;
  }

  led_changed = changed;
  led_update();
}

void red25() /* Red led shines at 25% intensity */
{
  char changed = 0;
  static char state = 0;
  switch(state){
  case 0: /* The led is on for 1 out of the 4 states */
    red_on = 0;
    state = 1;
    changed = 1;
    break;

  case 1:
    red_on = 0;
    state = 2;
    break;

  case 2:
    red_on = 0;
    state = 3;
    break;

  case 3:
    red_on = 1;
    state = 0;
    changed = 1;
  }

  led_changed = changed;
  led_update();
}


void green75() /* Green led shines at 75% intensity */
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0: /* The led is on for 3 out of the 4 states */
    green_on = 1;
    state = 1;
    changed = 1;
    break;

  case 1:
    green_on = 1;
    state = 2;
    break;

  case 2:
    green_on = 1;
    state = 3;
    break;

  case 3:
    green_on = 0;
    state = 0;
    changed = 1;
  }

  led_changed = changed;
  led_update();
}


void green50() /* Green led shines at 50% intensity */
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0: /* The led is on for 1 out of the 2 states */
    green_on = 1;
    state = 1;
    changed = 1;
    break;

  case 1:
    green_on = 0;
    state = 0;
    changed = 1;
  }

  led_changed = changed;
  led_update();
}


void green25() /* Green led shines at 25% intensity */
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0: /* The led is on for 1 out of the 4 states */
    green_on = 0;
    state = 1;
    changed = 1;
    break;

  case 1:
    green_on = 0;
    state = 2;
    break;

  case 2:
    green_on = 0;
    state = 3;
    break;

  case 3:
    green_on = 1;
    state = 0;
    changed = 1;
  }

  led_changed = changed;
  led_update();
}

void leds_advance() /* I feel I was a bit lazy with the leds state machine. Basically, it starts with the red led at full bright, and the green one off. Then the red one gradually shines less each time, while the green one does the opposite until the green one is fully bright and the red one off. Then they do the opposite until it returns to the original state */
{
  extern char blink_state;
  switch(blink_state){
  case 0: /* Red at 100% and green off */
    red_on = 1;
    green_on = 0;
    break;
    
  case 1: /* Red at 75% and green at 25% */
    red75();
    green25();
    break;
    
  case 2:
    red50(); /* Red at 50% and green at 50% */
    green50();
    break;
    
  case 3: /* Red at 25% and green at 75% */
    red25();
    green75();
    break;
    
  case 4: /* Red off and green at 100% */
    red_on = 0;
    green_on = 1;
    break;
    
  case 5: /* Red at 25% and green at 75% */
    red25();
    green75();
    break;
    
  case 6: /* Red at 50% and green at 50% */
    red50();
    green50();
    break;

  case 7: /* Red at 75% and green at 25% */
    red75();
    green25();
    break;
  }
  led_changed = 1;
  led_update();
}

void alarm_advance() /* From the alarm we did in class */
{
  static short state = 0;
  
  switch (state){
  case 0:
  case 1:
    up_state();
    state++;
    break;

  case 2:
    down_state();
    state = 0;

  default:
    break;

  }
}

void up_state() /* From the alarm we did in class */
{
  sb = 1;
  red_on = 0;
  green_on = 1;
  led_changed = 1;
  led_update();
}

void down_state() /* From the alarm we did in class */
{
  sb = 0;
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void buzzer_advance() /* From the alarm we did in class */
{
  if(sb)
    x += 225;
  else
    x -= 450;
  short cycles = 2000000/x;
  buzzer_set_period(cycles);   
}



void tetris_advance()
{
  extern unsigned char count;
  extern float max_count;
  static unsigned char state = 0;
  if(tetris_notes[state] != 1){ /* 1 is used to make the same note play for longer */
    play(tetris_notes[state]);
  }
  count = (max_count/100) * tetris_duration[state]; /* The values for duration are the percentage of what count should be, this is used to make half or quarter notes */
  state = (state+1)%81;
}

void zelda_advance() /* This song does not have a duration array as all notes have the same duration */
{
  extern unsigned char count;
  extern float max_count;
  static unsigned char state = 0;
  play(zelda_notes[state]);
  state = (state+1)%32;
}

void megaman_advance()
{
  extern unsigned char count;
  extern float max_count;
  static unsigned char state = 0;
  if(megaman_notes[state] != 1){
    play(megaman_notes[state]);
  }
  count = (max_count/100) * megaman_duration[state];
  state = (state+1)%38;
}
