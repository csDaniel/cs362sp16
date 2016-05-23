/*
Ben Beckerman
CS 362
Assignment 5
May 22, 2016


Card Tested: Village
	Unit Test: cardtest3.c
	The unit test discovered that the number of actions was not increased by the proper amount. This error is based on lines 1333 and 1334:
		(1333)	int actions;
		(1334)	actions = state->numActions + 2;
	The additional acctions are added to the 'actions' variable, but not added to the 'state->actions' structure variable as required.

	Random Test: randomtestcard.c
	The random test determined a single failure in the action count, which is consistant with the unit test. This failure was present for every iteration of the random test and no additional error was discovered.

Card Tested: Smithy
	Unit Test: cardtest1.c
	The unit test discovered that the number of played cards was not getting increased by the proper amount. Since the hand count and deck counts are correct, it can be assumed that the card is being placed into the discard pile instead of the played pile. Investigating the code revealed that this is the case, The error is based on line 1295:
		(1295)	discardCard(handPos, currentPlayer, state, 1);
	The final argument value of '1' causes the card to be trashed instead of placed in the played pile.


beckermb:
*Smithy:
Unittest uncovered that the card is being discarded incorrectly.

*Adventurer:
Unittest found that the wrong card was added to the played pile.
Random test found that the hand (after play) contained the wrong number of cards when the draw pile contained 2 or more treasures.

*/
