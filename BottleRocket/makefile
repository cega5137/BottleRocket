# The make file for the Base function

.PHONY: clean depend
CC = gcc
CFLAGS = -c
LFLAGS =
CLIBRA = -lm -lblas -lgfortran
OBJS = bottlemain.o ODE45.o RK45.o dydt.o
SRCS = bottlemain.c ODE45.c RK45.c dydt.c

Run: $(OBJS)
	$(CC) $(LFLAGS) -o $@ $^ $(CLIBRA)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $<

clean :
	rm -rf *.o *.*~ deps.mk

depend:
	$(CC) -MM $(SRCS) > deps.mk

-include deps.mk
