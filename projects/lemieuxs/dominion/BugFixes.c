/******************************************************************
Bug fixes:
	1. Fixed extra call of drawCard() that occurs when Smithy is played.
	2. Fixed bug in play_adventurer() that causes Smithy to be counted as a treasure card.
	3. Added discardCard() to end of play_adventurer().
	4. Fixed infinite loop that occurs in Feast card if player attempts to buy a card that is
	out of supply or too expensive.
	5. Changed if statement condition to state->supplyCount[province] <= 0 in isGameOver() to
	account for negative provinces.
	6. Fixed bug in play_minion() that caused some players to not have to draw cards.
	7. Fixed bug in play_embargo() that caused state->numPlayers to be incremented by 1.

Comments:
	The number of failures detected by my tests have been greatly reduced. My function unit tests and 
	my card tests for Smithy, Council Room, and Feast no longer detect any failures. However, there 
	is another bug in Adventurer that I can't find that causes	there to sometimes not be 2 
	treasure cards in hand afterward. I think this may be occurring when there are no treasure 
	cards left in the deck or discard pile. Running my random tests 2000 times on the Adventurer card 
	detects roughly between 200 and 300 failures, as opposed to about 6000 failures	before 
	making the above changes, but the code still does fail a significant number of times.
	The gcov data shows 100% line and branch coverage of the Adventurer function. The case where
	the deck needs to be shuffled is not covered as much as the other lines of code, so improvement
	in the randomtestadventurer.c code could help to determine whether the error is triggered
	by that condition. This bug is not one that I introduced myself, so it must be a bug in the
	original Dominion code.

	I preserved my buggy Dominion code in the file "buggydominion.c".
*********************************************************************/