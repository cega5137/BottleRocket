# The make file for the Base function

.PHONY: clean depend
CC = gcc
CFLAGS = -Wall -c
LFLAGS = -Wall
CLIBRA = -lm
OBJS = test.o BuildMatrix.o
SRCS = test.c BuildMatrix.c

Run: $(OBJS)
	$(CC) $(LFLAGS) -o $@ $^ $(CLIBRA)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $<

clean :
	rm -rf *.o *.*~  deps.mk

depend:
	$(CC) -MM $(SRCS) > deps.mk

-include deps.mk
