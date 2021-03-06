CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

testing.o: testing.h testing.c
	gcc -c testing.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

unittest1: unittest1.c dominion.o rngs.o testing.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o testing.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o testing.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o testing.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o testing.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o testing.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o testing.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o testing.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o testing.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o testing.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o testing.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o testing.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o testing.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o testing.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o testing.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o testing.o $(CFLAGS)

tests: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o testing.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o testing.o $(CFLAGS)
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o testing.o $(CFLAGS)
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o testing.o $(CFLAGS)
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o testing.o $(CFLAGS)
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o testing.o $(CFLAGS)
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o testing.o $(CFLAGS)
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o testing.o $(CFLAGS)
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o testing.o $(CFLAGS)

runtests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	touch unittestresults.out
	./unittest1 >> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe