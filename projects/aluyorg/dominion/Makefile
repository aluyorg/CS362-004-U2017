CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
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

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

testdom1: dominion.o playdom.c
	gcc -o testdom1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

testdom2: dominion.o playdom.c
	gcc -o testdom2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

testdom3: dominion.o playdom.c
	gcc -o testdom3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

testdom4: dominion.o playdom.c
	gcc -o testdom4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardTest1: dominion.o playdom.c
	gcc -o cardTest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardTest2: dominion.o playdom.c
	gcc -o cardTest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardTest3: dominion.o playdom.c
	gcc -o cardTest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardTest4: dominion.o playdom.c
	gcc -o cardTest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard1: dominion.o playdom.c
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard2: dominion.o playdom.c
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: dominion.o playdom.c
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)


t1: testdom
	randomtestadventurer
	randomtestcard1
	randomtestcard2
	gcov -b -c randomtestadventurer.c >> randomtestadventurer.out
	gcov -b -c randomtestcard1.c >> randomtestcard1.out
	gcov -b -c randomtestcard2.c >> randomtestcard2.out


all: playdom player testDrawCard testBuyCard badTestDrawCard testdom1 testdom2 testdom3 testdom4 cardTest1 cardTest2 cardTest3 cardTest4 randomtestcard1 randomtestcard2 randomtestadventurer
	randomtestadventurer >> randomtestadventurer.out
	randomtestcard1 >> randomtestcard1.out
	randomtestcard2 >> randomtestcard2.out
	gcov -b -c randomtestadventurer.c >> randomtestadventurer.out
	gcov -b -c randomtestcard1.c >> randomtestcard1.out
	gcov -b -c randomtestcard2.c >> randomtestcard2.out

clean:
	rm -f *.o playdom.exe testdom1 testdom2 testdom3 testdom4 cardTest1 cardTest2 cardTest3 cardTest4 randomtestcard1 randomtestcard2 randomtestadventurer playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe