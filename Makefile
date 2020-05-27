CC = gcc
CFLAGS = -I.

LIBS = -lncurses -lm

DEPS = img.h

OBJ = img.o camera.o cha.o mario.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mario: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core *~
