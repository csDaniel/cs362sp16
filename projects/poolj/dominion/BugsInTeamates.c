/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 22 May 2016
**
** Program Filename: BugsInTeamates.c
** Description: This is the report file for bugs discovered from performing
**				the unit and random tests on the other teammate's refactored
**				cards.
***************************************************************************/

The only change required for refactoring the tests was to add the '-std=c99' flag in makefile. Otherwise, the tests operated correctly.


/* Benjamin Beckerman <beckermb@oregonstate.edu> */
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

/* Susan Eldridge <eldridgs@oregonstate.edu>*/

General Error:
	An initial error of an uninitialized varibale 'z' was discovered on line 1276:
		(1276) int cardDrawn, z;
	This variable is incremented on line 1290 without being correctly initalized to a value (most likely 0):
		(1290) z++;
	This error was corrected before testing the cards was attempted.

Card Tested: Village
	Unit Test: cardtest3.c
	The first error in the village card that the buy count is incremented, when it should not be. This is due to a fall through of the card switch-case statement due to missing return or break statements. For example in lines 793 and 794 (which comprise the entire village card switch):
		(793)	case village:
		(794)		pVillage(state, handPos);
	There is no following return or break, which causes the baron card to be executed (which is next). This results in the addition of a buy to the current player.
	The second error in the village card is that the supply cards are manipulated when they should not be. This is again due to the above switch-case error and an estate card is removed from the supply and given to the current player.
	
Card Tested: Smithy
	Unit Test: cardtest1.c99
	There were 4 seperate failures in the unit test for the Smithy card:
		1. Deck Count - Decreased by 1 additional card
		2. Action Count - Increased by 2
		3. Buy Count - Increased by 1
		4. Supply Count - Effected
	The majority of these issues are due to the above mentioned switch-case fall through, but an additional error of the Smithy card being trashed was discovered through debugging. The test for played cards did not detect this due to the village card executing directly afterwards causing a correct played card value.
	
	Also, upon debugging an error was discovered in lines 1306 through 1309 which appears to decrement the hand position variable:
		(1306)	if (handPos == 2)
		(1307)	{
        (1308)		handPos--;
		(1309)	}
	The purpose of this code is not understood due to lack of documentation.
	
Note: The switch-case fallthrough is a major issue and currently effects the following cards:
	(669)	adventurer
	(787)	remodel
	(790)	smithy
	(793)	village
	(847)	great_hall
	
Note: There is also an issue of card functions not matching the prototypes in the header, for example:
	<In dominion.h>
		(135)	int playVillage(struct gameState *state, int handPos);
	<In dominion.c>
		(1321)	pVillage(struct gameState *state, int handPos)
The names do not match and 'pVillage' is missing a return variable definiton, even though it returns a value on line 1334.