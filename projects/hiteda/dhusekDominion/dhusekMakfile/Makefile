CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testBuyCard.c dominion.o rngs.o
	gcc -o testBuyCard -g  testBuyCard.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o interface.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o interface.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o interface.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o interface.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o interface.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o interface.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o interface.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o interface.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o interface.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o interface.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o interface.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o interface.o rngs.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	echo "Running Dominion unit tests..." > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	./unittest1 >> unittestresults.out
	echo "unittest2.c:" >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo "unittest3.c:" >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo "unittest4.c:" >> unittestresults.out
	./unittest4 >> unittestresults.out
	echo "cardtest1.c:" >> unittestresults.out
	./cardtest1 >> unittestresults.out
	echo "cardtest2.c:" >> unittestresults.out
	./cardtest2 >> unittestresults.out
	echo "cardtest3.c:" >> unittestresults.out
	./cardtest3 >> unittestresults.out
	echo "cardtest4.c:" >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o interface.o rngs.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o interface.o rngs.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer
	echo "Running Random Tests on Adventurer Card..." > randomtestadventurer.out
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c -b -f >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard: randomtestcard.c dominion.o interface.o rngs.o
	gcc -o randomtestcard -g  randomtestcard.c dominion.o interface.o rngs.o $(CFLAGS)

randomtestcard.out: randomtestcard
	echo "Running Random Tests on Smithy Card..." > randomtestcard.out
	echo "randomtestcard.c:" >> randomtestcard.out
	./randomtestcard >> randomtestcard.out
	gcov dominion.c -b -f >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

randomtest: randomtestadventurer randomtestcard
	echo "Running Random Tests on Adventurer Card..." > randomtestadventurer.out
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c -b -f >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
	echo "Running Random Tests on Smithy Card..." > randomtestcard.out
	echo "randomtestcard.c:" >> randomtestcard.out
	./randomtestcard >> randomtestcard.out
	gcov dominion.c -b -f >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4
	rm -f *.gcda

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe testDrawCard testDrawCard.exe badTestDrawCard badTestDrawCard.exe testBuyCard testBuyCard.exe unittest1 unittest1.exe unittest2 unittest2.exe unittest3 unittest3.exe unittest4 unittest4.exe unittestresults.out randomtestadventurer randomtestadventurer.exe randomtestcard randomtestcard.exe
	rm -rf *.dSYM
