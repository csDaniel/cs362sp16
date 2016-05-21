/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 4
 * May 8, 2016
 * randomhistory.c
 */

/******************* randomtestcard development & coverage *******************/
/* ----------------------------------------------------------------------------

randomtestcard random tests mine card and gets 29.66% coverage of 563 lines 
in dominion.c file. I think this is a very high percentage of coverage to get 
for the overall dominion file. The random tests I've implemented are getting 
very close to 100% statement coverage for the mine card.

The randomtestcard file first generates a random number of players to initialize.
The first tester tests that the mine card properly disposes of itself upon
being played. This test is run 2000 times and cycles through each player. The
mine card is placed into the current player's hand in a random hand position. 
Once the card is played, it is asserted that the mine card is no longer in the 
player's hand by testing each of the current player's hand positions.

The second tester tests that if choice1 (the position of the card to be trashed)
cost is more than 3$ less than choice2, the cardEffect() function will fail and
return -1. This test is run 2000 times and cycles through each player. This test
is done by inserting random cards into the player's hand, and when the condition
that choice1's cost is more than 3$ less than choice2 is met, it is asserted that 
playing the card will fail.

The third tester tests mine card will only accept valid, enumerated card values
as choice2 (the card the player is attempting to acquire). This test is run 2000
times and cycles through each player. This test is done by setting the current
player's hand to completely random values by first getting a random value modded
by the number of cards total then subtracting a random value modded by the 
number of cards total. This is done in an effort to incorporate negative values 
into the input domain. When a value that is not an enumerated card value is 
encountered, it is asserted that playing mine card will fail and cause a return 
value of -1.

Finally, the fourth tester tests mine card will only accept valid treasure cards
as choice1 (the card to be trashed). This is is run 2000 times and cycles through
each player. This is done by inserting random valid enumerated cards into the
current player's hand and choosing two of those cards at random and setting their
respective hand positions to choice1 and choice2 variables. If choice1 is not a 
treasure card, it is asserted that playing the mine card will cause cardEffect()
to fail and return a value of -1.

In an effort to get a lot of statement coverage, I focused mainly on testing 
for failures rather than successes. This seemed to be the most logical test
strategy considering that the majority of the conditional statements for playing
mine card were error safeguards. Given the perecentage of coverage being so high, 
it would seem that it would be quite difficult to make the coverage any better. 
That's not to say the tests are great. There are certainly improvements that 
could be made to improve the effectiveness of the tests.

---------------------------------------------------------------------------- */


/**************** randomtestadventurer development & coverage ****************/
/* -------------------------------------------------------------------------

randomtestadventurer random tests adventurer card and gets 25.40% coverage 
of 563 lines in dominion.c file. Again, I think this is a relatively high 
percentage of coverage to get for the overall dominion file. The random tests 
I've implemented are getting very close to 100% statement coverage for the 
adventurer card.

The randomtestadventurer file first generates a random number of players to 
initialize. The first tester tests that the adventurer card properly disposes 
of itself upon being played. This test is run 2000 times and cycles through 
each player. The adventurer card is placed into the current player's hand in a 
random hand position. Once the card is played, it is asserted that the adventurer
card is no longer in the player's hand by testing each of the current player's 
hand positions.

The second tester tests that adventurer increments the player's hand count and
decrements the deck count properly. This test is run 2000 times and cycles 
through each player. This done by setting the current player's deck cards all to 
the same arbitrary card (estate in this case), then inserting exactly two treasure 
cards into the deck at random hand positions. The test then asserts that the 
player's hand count is increased by exactly 2 and the deck count is decreased by 
exactly 2.

Finally, the third tester tests that the adventurer card only shuffles the 
current player's discarded cards into the deck when the deck count is exactly
zero. This test is run 2000 times and cycles through each player. First, the
current player's hand count is set to 1 and adventurer card is placed into the 
hand. The player's discard pile count is set to 5 and then filled with five 
somewhat random, but fixed, cards. The player's deck count is randomly generated 
to be a value between 0 and the MAX_DECK global value (which is 500 in this 
case). When the random deck count is found to be 0, it is asserted that the 
shuffle occured and the discard pile has changed.

Once again, I made an effort to get a lot of statement coverage, but this time
I did not focus mainly on testing for failures. With adventurer, none of the 
conditional statements cause a failure of the cards effect, so it didn't make
sense to test adventurer like I did with mine. Similar to the mine tests, the 
random adventurer card tests I have implemented have a high percentage of 
statement coverage. I am not sure what I would do to make coverage better than 
it is. However, there is definitely room for improvement in the overall 
effectiveness of these particular random tests.

----------------------------------------------------------------------------- */


