SHELL := /bin/bash
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

cardsuite: 
	gcc -coverage mirTestSuite.c dominion.c rngs.c -o mirTestSuite -lm

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.out

printout:
	./mirTestSuite > unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov -f dominion.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out	

unittestresults.out: cardsuite printout

randomtestadventurer.out: 
	gcc -coverage randomtestadventurer.c dominion.c rngs.c -o mirRandomAdventurer -lm
	-./mirRandomAdventurer 
	-gcov dominion.c > randomtestadventurer.out
	-gcov -f dominion.c >> randomtestadventurer.out
	-gcov -b dominion.c >> randomtestadventurer.out

randomtestcard.out: 
	gcc -coverage randomtestcard.c dominion.c rngs.c -o mirRandomCard -lm
	-./mirRandomCard > randomtestcard.out
	-gcov dominion.c >> randomtestcard.out
	-gcov -f dominion.c >> randomtestcard.out
	-gcov -b dominion.c >> randomtestcard.out



