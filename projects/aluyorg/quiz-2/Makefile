CFLAGS = -Wall -fpic -coverage -lm

testme:
	gcc -o testme testme.c $(CFLAGS)
	./testme

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out testme

all: 	clean testme
