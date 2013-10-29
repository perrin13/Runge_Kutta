# Makefile for rkRun
#

OBJS = rkRun.o \
       rk4.o \
       getnum.o \
       fxnParse.o \
       tree.o  

CFLAGS = -Wall -g -lm

all: rk4

rk4: ${OBJS}
	g++ -o rk4 ${CFLAGS} ${OBJS}

${OBJS}: getnum.h tree.h fxnParse.h rk4.h Makefile

clean:
	rm -f rk4 *.o

test:
	./rk4 in.rk
