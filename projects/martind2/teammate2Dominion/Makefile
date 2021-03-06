CFLAGS = -Wall -fpic -coverage -lm -fprofile-arcs -ftest-coverage

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

unittestresults.out: cardtest1.c unittest1.c cardtest2.c unittest2.c cardtest3.c unittest3.c cardtest4.c unittest4.c
	make dominion.o
	gcc -o ct1 cardtest1.c rngs.c dominion.o $(CFLAGS) 
	gcc -o ct2 cardtest2.c rngs.c dominion.o $(CFLAGS)
	gcc -o ct3 cardtest3.c rngs.c dominion.o $(CFLAGS)
	gcc -o ct4 cardtest4.c rngs.c dominion.o $(CFLAGS)
	gcc -o ut1 unittest1.c rngs.c dominion.o $(CFLAGS)
	gcc -o ut2 unittest2.c rngs.c dominion.o $(CFLAGS)
	gcc -o ut3 unittest3.c rngs.c dominion.o $(CFLAGS)
	gcc -o ut4 unittest4.c rngs.c dominion.o $(CFLAGS)
	./ct1 &> unittestresults.out
	./ct2 >> unittestresults.out
	./ct3 >> unittestresults.out
	./ct4 >> unittestresults.out
	./ut1 >> unittestresults.out
	./ut2 >> unittestresults.out
	./ut3 >> unittestresults.out
	./ut4 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
randomtestcard.out: randomtestcard.c
	make dominion.o
	gcc -o rtc randomtestcard.c rngs.c dominion.o $(CFLAGS) 
	./rtc
	gcov -b -f dominion.c &> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out
	
randomtestadventurer.out: randomtestadventurer.c
	make dominion.o
	gcc -o rta randomtestadventurer.c rngs.c dominion.o $(CFLAGS) 
	./rta
	gcov -b -f dominion.c &> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
	
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

assignment5: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest4.c rngs.o dominion.o
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest1 unittest1.c rngs.c dominion.o $(CFLAGS)
	gcc -o unittest2 unittest2.c rngs.c dominion.o $(CFLAGS)
	gcc -o unittest3 unittest3.c rngs.c dominion.o $(CFLAGS)
	gcc -o unittest4 unittest4.c rngs.c dominion.o $(CFLAGS)
	echo '' > unittestresults.out
	echo '#### #### #### TEST OUTPUT #### #### ####' >> unittestresults.out
	echo '' >> unittestresults.out
	./unittest1 >> unittestresults.out
	echo '' >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo '' >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo '' >> unittestresults.out
	./unittest4 >> unittestresults.out
	echo '' >> unittestresults.out
	./cardtest1 >> unittestresults.out
	echo '' >> unittestresults.out
	./cardtest2 >> unittestresults.out
	echo '' >> unittestresults.out
	./cardtest4 >> unittestresults.out
	echo '' >> unittestresults.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
