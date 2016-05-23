CFLAGS = -Wall -fpic -coverage -lm -std=c99

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

runtests:  randomtestcard.c randomtestadventurer.c randomtestvillage.c randomtestfeast.c
	echo "randomtestadventurer.c: testing adventure:" &> randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS) -std=c99
	randomtestadventurer >> randomtestadventurer.out
	gcov -f dominion.c >> randomtestadventurer.out
	
	echo "randomtestcard.c: testing smity:" &> randomtestcard.out
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS) -std=c99
	randomtestcard >> randomtestcard.out
	gcov -f dominion.c >> randomtestcard.out
	
	echo "randomtestvillage.c: testing village:" &> randomtestvillage.out
	gcc -o randomtestvillage -g randomtestvillage.c dominion.o rngs.o $(CFLAGS) -std=c99
	randomtestvillage >> randomtestvillage.out
	gcov -f dominion.c >> randomtestvillage.out
	
	echo "randomtestfeast.c: testing feast:" &> randomtestfeast.out
	gcc -o randomtestfeast -g randomtestfeast.c dominion.o rngs.o $(CFLAGS) -std=c99
	randomtestfeast >> randomtestfeast.out
	gcov -f dominion.c >> randomtestfeast.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
