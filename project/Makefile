# makefile configuration
COMMON_OBJECTS	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as
AR		= msp430-elf-ar

all: toy.elf

toy.elf: ${COMMON_OBJECTS} toyMain.o switches.o interrupt_handler.o leds.o stateMachines.o  wdInterruptHandler.o melody.o libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

install: libTimer.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

wdInterruptHandler.o: stateMachines.h
stateMachines.o: leds.h stateMachines.h

melody.c: melody.h