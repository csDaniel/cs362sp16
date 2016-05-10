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


randomtestadventurer.out:
	make randomtestadventurer
	echo "************  ADVENTURER TESTS  ************" >> randomtestadventurer.out
	make unitTests >> randomtestadventurer.out
	echo "************ COVERAGE ************" >> randomtestadventurer.out 
	make testCoverage >> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out

unitTests: 
	./randomtestadventurer

testCoverage:
	gcov randomtestadventurer.c -b

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)




all: playdom player testDrawCard testBuyCard badTestDrawCard randomtestadventurer.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe randomtestadventurer randomtestadventurer.exe  *.gcov *.gcda *.gcno *.so
