CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

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

all: playdom player unittests cardtests	
	
runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	
#unit/card tests	
unittests: unitTest1Grant.c unitTest2Grant.c unitTest3Grant.c unitTest4Grant.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest1 -g unitTest1Grant.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest2 -g unitTest2Grant.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest3 -g unitTest3Grant.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest4 -g unitTest4Grant.c dominion.o rngs.o $(CFLAGS)

unittest1: unitTest1Grant.c dominion.o rngs.o
	gcc -o unittest1 -g  unitTest1Grant.c dominion.o rngs.o $(CFLAGS)
unittest2: unitTest2Grant.c dominion.o rngs.o
	gcc -o unittest2 -g  unitTest2Grant.c dominion.o rngs.o $(CFLAGS)
unittest3: unitTest3Grant.c dominion.o rngs.o
	gcc -o unittest3 -g  unitTest3Grant.c dominion.o rngs.o $(CFLAGS)
unittest4: unitTest4Grant.c dominion.o rngs.o
	gcc -o unittest4 -g  unitTest4Grant.c dominion.o rngs.o $(CFLAGS)


cardtests: dominion.o cardtests1Michael.c cardtests2Michael.c cardtests3Michael.c cardtests4Michael.c rngs.o $(CFLAGS)
	gcc -o cardtest1 cardtest1Michael.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2 cardtest2Michael.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest3 cardtest3Michael.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 cardtest4Michael.c -g dominion.o rngs.o $(CFLAGS)
	
unittestresults.out: unittests cardtests dominion.c
	./unittest1 > unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

customout: unittest1 unittest2 unittest3 unittest4 dominion.o rngs.o
	./unittest1 > unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

#random card tests
randomtestadventurer: dominion.o randomtestadventurerGrant.c
	gcc -o randomtestadventurer randomtestadventurerGrant.c -g dominion.o rngs.o $(CFLAGS)
	
randomtestcard: dominion.o randomtestcardGrant.c
	gcc -o randomtestcard randomtestcardGrant.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer dominion.c
	./randomtestadventurer > randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard.out: randomtestcard dominion.c
	./randomtestcard > randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
	rm -f unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.out
	rm -f randomtestadventurer randomtestcard

