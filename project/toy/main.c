#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "play.h"
#include "stateMachines.h"
#include "led.h"

int main() {
    configureClocks();
    enableWDTInterrupts();
    buzzer_init();
    led_init();
    switch_init();
    enableWDTInterrupts();
    or_sr(0x18);         // CPU off, GIE on
}
