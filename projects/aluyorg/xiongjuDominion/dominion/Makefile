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

showtitle: 
	echo "Result for running random card tests:">unittestresults.out

testUpdateCoins:testUpdateCoins.c dominion.o rngs.o
	echo "testUpdateCoins.c:" >> unittestresults.out
	gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
	testUpdateCoins >> unittestresults.out
	gcov dominion.c >> unittestresults.out

unittest1:unittest1.c dominion.o rngs.o
	echo "unittest1.c" >> unittestresults.out
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

unittest2:unittest2 dominion.o rngs.o
	echo "unittest2.c">>unittestresults.out
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

unittest3:unittest3 dominion.o rngs.o
	echo "unittest3.c">>unittestresults.out
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

unittest4:unittest4 dominion.o rngs.o
	echo "unittest4.c">>unittestresults.out
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

cardtest1:cardtest1 dominion.o rngs.o
	echo "cardtest1" >>unittestresults.out
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

cardtest2:cardtest2 dominion.o rngs.o
	echo "cardtest2" >>unittestresults.out
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

cardtest3:cardtest3 dominion.o rngs.o
	echo "cardtest3" >>unittestresults.out
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

cardtest4:cardtest4 dominion.o rngs.o
	echo "cardtest4" >>unittestresults.out
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randomtestcard1:randomtestcard1 dominion.o rngs.o
	echo "randomtestcard1" >>unittestresults.out
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	randomtestcard1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

randomtestcard2:randomtestcard2 dominion.o rngs.o
	echo "randomtestcard2" >>unittestresults.out
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	randomtestcard2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

randomtestadventurer:randomtestadventurer dominion.o rngs.o
	echo "randomtestadventurer" >>unittestresults.out
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	randomtestadventurer >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

all: showtitle randomtestcard1 randomtestcard2 randomtestadventurer

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out *.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer

