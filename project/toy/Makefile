# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf

#additional rules for files
toy.elf: ${COMMON_OBJECTS} buzzer.o main.o play.o led.o stateMachines.o wdInterruptHandler.o switches.o p2_interrupt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf


led.o: led.h

wdInterruptHandler.o: stateMachines.h buzzer.h play.h led.h

stateMachines.o: led.h

