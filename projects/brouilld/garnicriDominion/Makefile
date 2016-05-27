CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

unitTestFramework.o: unitTestFramework.h unitTestFramework.c
	gcc -c unitTestFramework.c -c $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

unittestresults.out: dominion.o rngs.o unittests.h unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest2.c cardtest4.c unittestsmain.c unitTestFramework.h unitTestFramework.c
	gcc -o showTestResults -g dominion.o rngs.o unitTestFramework.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittestsmain.c $(CFLAGS)

randomtestadventurer.out: dominion.o rngs.o unitTestFramework.o UnitTest_Random_DefinedTests.h UnitTest_Random_Main.c randomtestadventurer.c randomtestcard.c
	gcc -o showAdvResults -g dominion.o rngs.o unitTestFramework.o UnitTest_Random_Main.c randomtestadventurer.c randomtestcard.c $(CFLAGS)

randomtestcard.out: dominion.o rngs.o unitTestFramework.o UnitTest_Random_DefinedTests.h UnitTest_Random_Main.c randomtestadventurer.c randomtestcard.c
	gcc -o showCardResults -g dominion.o rngs.o unitTestFramework.o UnitTest_Random_Main.c randomtestadventurer.c randomtestcard.c $(CFLAGS)

allRandomTests: randomtestadventurer.out randomtestcard.out

runAllTests: unittestresults.out allRandomTests

rungcov: runAllTests
	gcov dominion.c >> testresults.out

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out

randomtestcard.out: 

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe showCardResults showAdvResults showTestResults *.out *.gcov *.gcda *.gcno *.so
