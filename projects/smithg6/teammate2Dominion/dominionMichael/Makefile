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

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittest1 unittest2 unittest3 unittest4

clean:
	rm -f *.o playdom.exe *.out playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

unittest1: unitTest1Grant.c dominion.o rngs.o
	gcc -o unittest1 -g  unitTest1Grant.c dominion.o rngs.o $(CFLAGS)
unittest2: unitTest2Grant.c dominion.o rngs.o
	gcc -o unittest2 -g  unitTest2Grant.c dominion.o rngs.o $(CFLAGS)
unittest3: unitTest3Grant.c dominion.o rngs.o
	gcc -o unittest3 -g  unitTest3Grant.c dominion.o rngs.o $(CFLAGS)
unittest4: unitTest4Grant.c dominion.o rngs.o
	gcc -o unittest4 -g  unitTest4Grant.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1Jessica.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1Jessica.c dominion.o rngs.o $(CFLAGS)
cardtest2: cardtest2Jessica.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2Jessica.c dominion.o rngs.o $(CFLAGS)
cardtest3: cardtest3Jessica.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3Jessica.c dominion.o rngs.o $(CFLAGS)
cardtest4: cardtest4Jessica.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4Jessica.c dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 dominion.o rngs.o
	./unittest1 &> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestresults.out: randomtestadventurer randomtestcard

randomtestadventurer: randomtestadventurerGrant.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurerGrant.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard: randomtestcardGrant.c dominion.o rngs.o
	gcc -o randomtestcard -g randomtestcardGrant.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard >> randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out
