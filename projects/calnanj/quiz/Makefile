CFLAGS = -Wall -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

testme: testme.c
	gcc -o testme testme.c $(CFLAGS)
	
	rm -f *.o testme
