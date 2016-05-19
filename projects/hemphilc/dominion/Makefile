 # Corey Hemphill
 # hemphilc@oregonstate.edu
 # CS362_400 - Software Engineering II
 # Assignment 4
 # May 8, 2016
 # Makefile

CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestcard.out randomtestadventurer.out

randomtestcard.out: randomtestcard.c dominion.c
	echo "Result for running Random Dominion (Mine) Card Unit tests:" > randomtestcard.out
	
	echo "randomtestcard.c:" >> randomtestcard.out
	gcc -o randomtestcard dominion.c rngs.c randomtestcard.c $(CFLAGS)
	randomtestcard >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out

randomtestadventurer.out: randomtestadventurer.c dominion.c
	echo "Result for running Random Adventurer Card Unit tests:" > randomtestadventurer.out
	
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	
clean:
	rm randomtestcard.out randomtestadventurer.out

cleanall:	
	rm randomtestcard.out randomtestadventurer.out randomtestcard randomtestadventurer *.gcda *.gcno *.gcov

