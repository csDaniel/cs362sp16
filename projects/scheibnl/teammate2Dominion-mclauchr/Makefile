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


unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard.out:
	make randomtestcard
	echo "-----------------Running randomtestcard (cutpurse) test-------------" >> randomtestcard.out
	echo "*Please note- Failing asserts have been commented out so that program runs through.*" >> randomtestcard.out
	./randomtestcard >> randomtestcard.out
	echo "------------------Coverage Tests----------------------" >> randomtestcard.out
	gcov -f -b dominion.c >> randomtestcard.out

randomtestadventurer.out:
	make randomtestadventurer 
	echo "-----------------Running randomtestadventurer test-------------" >> randomtestadventurer.out
	echo "*Please note- Failing asserts have been commented out so that program runs through.*" >> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	echo "------------------Coverage Tests----------------------" >> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out

randomtestresults.out:
	make randomtestcard.out
	make randomtestadventurer.out

unittestresults.out:
	make unittest1
	make unittest2
	make unittest3
	make unittest4
	make cardtest1
	make cardtest2
	make cardtest3
	make cardtest4
	echo "-------------------Running All Tests--------------------" >> unittestresults.out
	echo "*Please note- Failing asserts have been commented out so that program runs through.*" >> unittestresults.out
	make runtests >> unittestresults.out
	echo "------------------Coverage Tests-----------------------" >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out

runtests:
	./unittest1
	./unittest2
	./unittest3
	./unittest4
	./cardtest1
	./cardtest2
	./cardtest3
	./cardtest4
all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
