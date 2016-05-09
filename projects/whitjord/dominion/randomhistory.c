/*
 * Notes on randomtestadventurer and randomtestcard
 *
 * Jordan White
 *
 * make randomtestadventurer
 * maked randomtestcard
 *
 * I spent a lot of time thinking about the approach and a desing that 
 * would limit repeating code. I didn't commit any changed until the end.
 * 
 * The heart of the random testing is randomtest_helper.c
 *
 * My general approach was to create random game states, play the card 
 * under test (using cardEffect) and then compare the before and after
 * game states.
 *
 * (right now the tests run through 1000 random game states)
 *
 * My first step was to create randomtest_helper.c and run some initial
 * checks on it's functions.
 *
 * randomtest_helper.c has two functions
 *
 * randomGameState() take a pointer to a game state and initializes it
 * in a random fashion. It randomly picks the number of players, 
 * randomly draws cards and puts them in the players decks, and randomly
 * cycles through the players so you have a random active player (among
 * other things)
 *
 * myAssert() takes two ints and a message, if the ints match it displays
 * "Passed: <msg>", if they don't match it displays "Failled: <msg>
 * This was created to avoid aborting the test program like what would 
 * happen with a normal assert()
 *
 * files:
 * update Makefile
 * randomtestadvernturer.c
 * randomtestcard.c (smithy)
 * randomtest_helper.c
 *
 * issues overcome:
 * In the randomGameState() when I was adding cards using the 
 * gainCard function I was initially passing it the index of the 
 * card in the kingdom array instead of the card enumerted value
 * I didn't notice this at first, because I was testing with the
 * adventureer card and it's enumerated value was under 10, so
 * it still got drawn inadvertently. When I moved on to test cards
 * with higher enum values the issue became apparent
 *
 * Coverage was good from the begining.
 *
