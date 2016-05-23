
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

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -std=c99 -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -std=c99 -g randomtestcard.c dominion.o rngs.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

unittestresults.out: unittest1.c unittest2.c cardtest1.c cardtest2.c dominion.o rngs.o interface.o
	echo "--------------------------------------------" >> unittestresults.out
	echo "dimuzioa Assignment 3 Unit Test Results" > unittestresults.out
	echo "--------------------------------------------" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "--------------------------------------------" >> unittestresults.out
	echo "unittest1" >> unittestresults.out
	echo "--------------------------------------------" >> unittestresults.out
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "--------------------------------------------" >> unittestresults.out
	echo "unittest2" >> unittestresults.out
	echo "--------------------------------------------" >> unittestresults.out
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "--------------------------------------------" >> unittestresults.out
	echo "cardtest1" >> unittestresults.out
	echo "--------------------------------------------" >> unittestresults.out
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o interface.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "--------------------------------------------" >> unittestresults.out
	echo "cardtest2" >> unittestresults.out
	echo "--------------------------------------------" >> unittestresults.out
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "--------------------------------------------" >> unittestresults.out
	echo "gcov results" >> unittestresults.out
	echo "--------------------------------------------" >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out



randomtestadventurer.out:
	make randomtestadventurer 
	echo "------------------Random Testing: Adventurer card---------------" >> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	echo "------------------gcov Test Results----------------------" >> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out

randomtestcard.out:
	make randomtestcard
	echo "------------------Random Testing: Village card---------------" >> randomtestcard.out
	./randomtestcard >> randomtestcard.out
	echo "------------------gcov Test Results----------------------" >> randomtestcard.out
	gcov -f -b dominion.c >> randomtestcard.out

jstests:
	gcc -o smithyTest js_cardtest1.c dominion.c rngs.c -lm
	gcc -o adventTest js_cardtest2.c dominion.c rngs.c -lm
	gcc -o randTestAdvent js_randomtestadventurer.c dominion.c rngs.c -lm
	./smithyTest &> test.out
	./adventTest >> test.out
	./randTestAdvent >> test.out
	gcov dominion.c -b >> test.out

clean:
	rm -f *.out *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
