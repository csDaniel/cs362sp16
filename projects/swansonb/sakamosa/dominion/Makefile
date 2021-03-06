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

all: playdom player testDrawCard testBuyCard badTestDrawCard

unittestresults.out: unittest*.c cardtest*.c testUtilities.c dominion.o rngs.o
	echo "Result for running dominion tests:" > unittestresults.out
	
	gcc -o unittest1.out unittest1.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest1.out >> unittestresults.out
	
	gcc -o unittest2.out unittest2.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest2.out >> unittestresults.out
	
	gcc -o unittest3.out unittest3.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest3.out >> unittestresults.out
	
	gcc -o unittest4.out unittest4.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./unittest4.out >> unittestresults.out
	
	gcc -o cardtest1.out cardtest1.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./cardtest1.out >> unittestresults.out
	
	gcc -o cardtest2.out cardtest2.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./cardtest2.out >> unittestresults.out

	gcov dominion.c -f -b >> unittestresults.out

randomtestcard.out: randomtestcard.c testUtilities.c dominion.o rngs.o
	echo "Result for running dominion tests:" > randomtestcard.out

	gcc -o randomtestcard.compile.out randomtestcard.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./randomtestcard.compile.out >> randomtestcard.out

randomtestadventurer.out: randomtestadventurer.c testUtilities.c dominion.o rngs.o
	echo "Result for running dominion tests:" > randomtestadventurer.out

	gcc -o randomtestadventurer.compile.out randomtestadventurer.c testUtilities.c dominion.o rngs.o -g  $(CFLAGS)
	./randomtestadventurer.compile.out >> randomtestadventurer.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *test?.out 
