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



char toggle_red()/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;/* always changes an led */
}

void red75()
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0:
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


void red50()
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0:
    red_on = 1;
    state = 1;
    changed = 1;
    break;

  case 1:
    red_on = 1;
    state = 2;
    break;

  case 2:
    red_on = 0;
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

void red25()
{
  char changed = 0;
  static char state = 0;
  switch(state){
  case 0:
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


void green75()
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0:
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


void green50()
{
  char changed = 0;
  static char state = 0;
  switch(state){
    
  case 0:
    green_on = 1;
    state = 1;
    changed = 1;
    break;

  case 1:
    green_on = 1;
    state = 2;
    break;

  case 2:
    green_on = 0;
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


void green25()
{
  char changed = 0;
  static char state = 0;
  switch(state){
  case 0:
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

char toggle_green2()/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }
  return 1;/* always changes an led */
}


void leds_advance()
{
  static char state = 0;
  switch(state){
  case 0:
    toggle_red();
    toggle_green2();
    break;
  case 1:
    green25();
    break;
  case 2:
    red75();
    break;
  }
  led_changed = 1;
  state = (state+1)%3;
}


void state_advance()/* alternate between toggling red & green */
{
  char changed = 0;

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green2(); color = R; break;
  }

  led_changed = changed;
  led_update();
}



void alarm_advance()
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

void up_state()
{
  sb = 1;
  red_on = 0;
  green_on = 1;
  led_changed = 1;
  led_update();
}

void down_state()
{
  sb = 0;
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void buzzer_advance()
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
  static unsigned char state = 0;
  if(tetris_notes[state] != 1){
    play(tetris_notes[state]);
  }
  count = tetris_duration[state];
  state = (state+1)%81;
}

void zelda_advance()
{
  extern unsigned char count;
  static unsigned char state = 0;
  play(zelda_notes[state]);
  state = (state+1)%32;
}

