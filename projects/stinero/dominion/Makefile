
CFLAGS = -Wall -fpic -coverage -lm

markcardtest: markcardtest.c dominion.o rngs.o
	gcc -o markcardtest -g  markcardtest.c dominion.o rngs.o $(CFLAGS)

saiadven: saiadven.c dominion.o rngs.o
	gcc -o saiadven -g  saiadven.c dominion.o rngs.o $(CFLAGS)
	
saieeSmithy: saieeSmithy.c dominion.o rngs.o
	gcc -o saieeSmithy -g  saieeSmithy.c dominion.o rngs.o $(CFLAGS)	
	
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)	
 
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
	
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)	

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

cardtest5: cardtest5.c dominion.o rngs.o
	gcc -o cardtest5 -g  cardtest5.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)


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

runtests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 
	./unittest1 &./unittest2 &./unittest3 &./unittest4 &./cardtest1 &./cardtest2 &./cardtest3 &./cardtest4
	gcov dominion.c -b -f> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	
testAdventure: randomtestadventurer
	./randomtestadventurer
	gcov dominion.c -b -f > randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out	
	
testRandom: randomtestcard
	./randomtestcard
	gcov dominion.c -b -f > randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out	
	
		
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: markcardtest saieeSmithy saiadven playdom player testDrawCard testBuyCard badTestDrawCard cardtest5 cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4

clean:
	rm -f *.o markcardtest saieeSmithy saiadven unittestresult.out randomtestcard unittestresult.out~ randomtestadventurer unittest2 playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so cardtest1 cardtest5 badTestDrawCard cardtest2 unittest3 cardtest3 cardtest4 unittest4 unittest1 testDrawCard
