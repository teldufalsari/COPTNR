WFLAGS = -Wall -Wextra -Wnarrowing -Wfloat-equal -Wundef -Wshadow
WFLAGS += -Wunreachable-code -Wpointer-arith -Wcast-align
WFLAGS += -Wconversion -Wunreachable-code -Wstrict-prototypes
WFLAGS += -Wwrite-strings -Wswitch-default -Wswitch-enum -Winit-self -Wcast-qual
WFLAGS += -Werror

CFLAGS = -O3 -march=native

LFLAGS =  -fopenmp


all: qsort

qsort: main.c sort.c
	cc ${WFLAGS} ${CFLAGS} ${LFLAGS} main.c sort.c -o qsort

clean:
	rm qsort
