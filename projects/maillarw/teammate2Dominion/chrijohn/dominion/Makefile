CFLAGS = -Wall -fpic -coverage -lm
MYFLAGS = -fpic -coverage -lm -w

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

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittest[1-4] cardtest[1-4] randomtestcard randomtestadventurer

unit1:
	gcc -std=c99 dominion.o unittest1.c rngs.c -o unittest1 $(MYFLAGS)
unit2:
	gcc -std=c99 dominion.o unittest2.c rngs.c -o unittest2 $(MYFLAGS)
unit3:
	gcc -std=c99 dominion.o unittest3.c rngs.c -o unittest3 $(MYFLAGS)
unit4:
	gcc -std=c99 dominion.o unittest4.c rngs.c -o unittest4 $(MYFLAGS)
card1:
	gcc -std=c99 dominion.o cardtest1.c rngs.c -o cardtest1 $(MYFLAGS)
card2:
	gcc -std=c99 dominion.o cardtest2.c rngs.c -o cardtest2 $(MYFLAGS)
card3:
	gcc -std=c99 dominion.o cardtest3.c rngs.c -o cardtest3 $(MYFLAGS)
card4:
	gcc -std=c99 dominion.o cardtest4.c rngs.c -o cardtest4 $(MYFLAGS)
unittestresults.out: dominion.o unit1 unit2 unit3 unit4 card1 card2 card3 card4 
	./unittest1 >> unittestresults.out 
	./unittest2 >> unittestresults.out 
	./unittest3 >> unittestresults.out  
	./unittest4 >> unittestresults.out  
	./cardtest1 >> unittestresults.out  
	./cardtest2 >> unittestresults.out 
	./cardtest3 >> unittestresults.out  
	./cardtest4 >> unittestresults.out
	printf "\n************************    Begin Coverage Information   **********************\n\n" >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
randomtestadventurer.out: dominion.o
	gcc -std=c99 dominion.o randomtestadventurer.c rngs.c -o randomtestadventurer $(MYFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	printf "\n************************    Begin Coverage Information   **********************\n\n" >> randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
randomtestcard.out: dominion.o
	gcc -std=c99 dominion.o randomtestcard.c rngs.c -o randomtestcard $(MYFLAGS)
	./randomtestcard >> randomtestcard.out
	printf "\n************************    Begin Coverage Information   **********************\n\n" >> randomtestcard.out
	gcov -b -f dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out
randomtests: randomtestadventurer.out
	rm dominion.o 
	make randomtestcard.out 
runUnitThenRandom: dominion.o unit1 unit2 unit3 unit4 card1 card2 card3
	gcc -std=c99 dominion.o randomtestadventurer.c rngs.c -o randomtestadventurer $(MYFLAGS)
	gcc -std=c99 dominion.o randomtestcard.c rngs.c -o randomtestcard $(MYFLAGS)
	./unittest1 >> combinedRandomUnit.out
	./unittest2 >> combinedRandomUnit.out
	./unittest3 >> combinedRandomUnit.out 
	./unittest4 >> combinedRandomUnit.out
	./cardtest1 >> combinedRandomUnit.out 
	./cardtest2 >> combinedRandomUnit.out
	./cardtest3 >> combinedRandomUnit.out
	./randomtestadventurer >> combinedRandomUnit.out
	./randomtestcard >> combinedRandomUnit.out
	printf "\n************************    Begin Coverage Information   **********************\n\n" >> combinedRandomUnit.out
	gcov -b -f dominion.c >> combinedRandomUnit.out
	cat dominion.c.gcov >> combinedRandomUnit.out