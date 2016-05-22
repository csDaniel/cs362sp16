/*****************************************************************************
randomtestadventurer.c

Since other players' state isn't affected by playing the Adventurer card, I only generated random
deck, discard, and hand data for one player. The game state data was also generated randomly, except
for numPlayers, playedCardCount, and whoseTurn, for which reasonable values were needed in order to test
the Adventurer card.
For the test cases, I mostly reused tests from Assignment 3. The bugs detected are the same as in 
Assignment 3, with the Adventurer card not being added to the played pile and the Smithy being counted
as a treasure card when Adventurer is played. The Adventurer card not being added to the played pile
occurs every time the Adventurer card is played, but the bug I introduced with the Smithy being counted
as a treasure card only occurs sometimes (only if a Smithy card is encountered in the deck before two
actual Treasure cards are found).
In order to run my tests without the assert() function causing the program to crash, I created my own
assert function, myAssert(), which prints out whether the test was successful and also helps
keep track of the number of failed tests.
The gcov data shows that each line of the play_adventurer function is executed many times during the
tests. The case where the deck needs to be reshuffled is covered as much as the rest of the code, but,
as long as there is a decent number of tests, it achieves a reasonable amount of coverage.

gcov function data:
Function 'play_adventurer'
Lines executed:100.00% of 15
Branches executed:100.00% of 14
Taken at least once:100.00% of 14
Calls executed:100.00% of 2


************************************************************************************************
randomtestcard.c

I tested the Council Room card. Random data was generated for the game state and for all players.
When running the tests, the program would sometimes cause a segmentation fault when the drawCard()
function was called. I thought perhaps there could have been a bug in drawCard() or cardEffect(),
but then I realized that I had made a mistake when randomly generating a number to represent whose
turn it was.
When running the tests 2000 times, the tests originally failed if the player's deckCount before calling the function
was below 4, since the current player draws 4 cards from the deck when playing the Council Room card.
My tests didn't account for the reshuffling of the discard pile. An if statement checking for this condition 
was added to the tests.
The gcov data shows that each line of code in the cardEffect function that relates to the Council Room
card is run at least 2000 times each time the tests code is executed (2000 tests are executed in the current
version of the test code).

gcov function data:
Function 'cardEffect'
Lines executed:16.75% of 197
Branches executed:23.64% of 165
Taken at least once:12.12% of 165
Calls executed:17.54% of 57
*********************************************************************************/