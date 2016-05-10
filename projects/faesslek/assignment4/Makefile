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
   
randomtestadventurer: dominion.o randomtestadventurer.c
	gcc -o randomtestadventurer randomtestadventurer.c -g  dominion.o rngs.o $(CFLAGS)
	
randomtestcard: dominion.o randomtestcard.c
	gcc -o randomtestcard randomtestcard.c -g  dominion.o rngs.o $(CFLAGS)
   
randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "Unit Test Results" > randomtestadventurer.out
	
	echo "randomtestadventurer.c" >> randomtestadventurer.out
	gcc -o randomtestadventurer randomtestadventurer.c -g  dominion.o rngs.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	
randomtestcard.out: randomtestcard.c dominion.o rngs.o
	echo "Unit Test Results" > randomtestcard.out
	
	echo "randomtestcard.c" >> randomtestcard.out
	gcc -o randomtestcard randomtestcard.c -g  dominion.o rngs.o $(CFLAGS)
	randomtestcard >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom test player testInit *estDrawCard randomtestadventurer randomtestcard *.gcov *.gcda *.gcno *.so *.out
