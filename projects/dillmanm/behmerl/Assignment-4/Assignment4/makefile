CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestcard.out 

randomtestcard.out: randomtestcard.c dominion.c rngs.c interface.c



	echo "Result for random test for Smith card:" > randomtestcard.out

	echo "randometestcard.c:" >> randomtestcard.out
	gcc -o randomtest dominion.c rngs.c interface.c randomtestcard.c -lm $(CFLAGS)
	randomtest >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out

	echo "Result for random test for adventurer card:" > randomtestadventurer.out

	echo "randomtestadventurer.c" >> randomtestadventurer.out
	gcc -o randomAdven dominion.c rngs.c interface.c randomtestadventurer.c -lm $(CFLAGS)
	randomAdven >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

clean:
	rm randomtestcard.out 


cleanall:
	rm randomtestcard.out randomtest  *.gcda *.gcno *.gcov
