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

unittestresults.out: unitTest1.c unitTest2.c unitTest3.c unitTest4.c dominion.o
	echo "%-------------------------------------UNITTEST1-------------------------------------%" >> unittestresults.out

	gcc -o unitTest1 unitTest1.c -g dominion.o rngs.o $(CFLAGS)
	./unitTest1 >> unittestresults.out
	gcov unitTest1.c >> unittestresults.out
	gcov unitTest1.c -b >> unittestresults.out
	cat unitTest1.c.gcov >> unittestresults.out

	echo "%-------------------------------------UNITTEST2-------------------------------------%" >> unittestresults.out

	gcc -o unitTest2 unitTest2.c -g dominion.o rngs.o $(CFLAGS)
	./unitTest2 >> unittestresults.out
	gcov unitTest2.c >> unittestresults.out
	gcov unitTest2.c -b >> unittestresults.out
	cat unitTest2.c.gcov >> unittestresults.out

	echo "%-------------------------------------UNITTEST3-------------------------------------%" >> unittestresults.out

	gcc -o unitTest3 unitTest3.c -g dominion.o rngs.o $(CFLAGS)
	./unitTest3 >> unittestresults.out
	gcov unitTest3.c >> unittestresults.out
	gcov unitTest3.c -b >> unittestresults.out
	cat unitTest3.c.gcov >> unittestresults.out

	echo "%-------------------------------------UNITTEST4-------------------------------------%" >> unittestresults.out
	gcc -o unitTest4 unitTest4.c -g dominion.o rngs.o $(CFLAGS)
	./unitTest4 >> unittestresults.out
	gcov unitTest4.c >> unittestresults.out
	gcov unitTest4.c -b >> unittestresults.out
	cat unitTest4.c.gcov >> unittestresults.out

randomtestcard: randomtestcard randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard >> randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

randomtestadventurer: randomtestadventurer randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

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

all: playdom player testDrawCard testBuyCard badTestDrawCard randomtestadventurer

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

unittest1hueterm: unittest1hueterm.c dominion.o rngs.o
	gcc -o unittest1hueterm -g  unittest1hueterm.c dominion.o rngs.o $(CFLAGS)
unittest2hueterm: unittest2hueterm.c dominion.o rngs.o
	gcc -o unittest2hueterm -g  unittest2hueterm.c dominion.o rngs.o $(CFLAGS)
unittest3hueterm: unittest3hueterm.c dominion.o rngs.o
	gcc -o unittest3hueterm -g  unittest3hueterm.c dominion.o rngs.o $(CFLAGS)
unittest4hueterm: unittest4hueterm.c dominion.o rngs.o
	gcc -o unittest4hueterm -g  unittest4hueterm.c dominion.o rngs.o $(CFLAGS)
cardtest1hueterm: cardtest1hueterm.c dominion.o rngs.o
	gcc -o cardtest1hueterm -g  cardtest1hueterm.c dominion.o rngs.o $(CFLAGS)
cardtest2hueterm: cardtest2hueterm.c dominion.o rngs.o
	gcc -o cardtest2hueterm -g  cardtest2hueterm.c dominion.o rngs.o $(CFLAGS)
randomtestadventurerhueterm: randomtestadventurerhueterm.c dominion.o rngs.o
	gcc -o randomtestadventurerhueterm -g randomtestadventurerhueterm.c dominion.o rngs.o $(CFLAGS)


unittestresultshueterm.out: unittest1hueterm unittest2hueterm unittest3hueterm unittest4hueterm cardtest1hueterm cardtest2hueterm randomtestadventurerhueterm  dominion.o rngs.o
	./unittest1hueterm &> unittestresultshueterm.out
	gcov -b dominion.c >> unittestresultshueterm.out
	./unittest2hueterm >> unittestresultshueterm.out
	gcov -b dominion.c >> unittestresultshueterm.out
	./unittest3hueterm >> unittestresultshueterm.out
	gcov -b dominion.c >> unittestresultshueterm.out
	./unittest4hueterm >> unittestresultshueterm.out
	gcov -b dominion.c >> unittestresultshueterm.out
	./cardtest1hueterm >> unittestresultshueterm.out
	gcov -b dominion.c >> unittestresultshueterm.out
	./cardtest2hueterm >> unittestresultshueterm.out
	gcov -b dominion.c >> unittestresultshueterm.out
	cat dominion.c.gcov >> unittestresultshueterm.out
	./randomtestadventurerhueterm >> randomtestadventurerhueterm.out
	gcov -b dominion.c >> randomtestadventurerhueterm.out
	cat dominion.c.gcov >> randomtestadventurerhueterm.out
