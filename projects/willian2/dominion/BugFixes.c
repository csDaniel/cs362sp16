/******************************************************************************
* ASSIGNMENT 5 - BugFixes.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 05/22/2016
* NOTES: bug fixes according to reports provided by...
*	- Max Grubb (grubbm@oregonstate.edu)
*	- Wesley Jinks (jinksw@oregonstate.edu)
******************************************************************************/

/******************************************************************************
* SMITHY CARD BUGS REPORTED
* Bug 1 - Wesley Jinks
* 	Description:  Handcount is higher 8, expected 7. Deckcount is 1, 
* 	expected 2. Discard count is 0, expected 1
* FIX - Test correctly found bug I introduced that draws one extra card.
*	Unable to diagnose discard count discrepency; handCount is incremented
*	and deckCount decremented in manner consistent with extra card being
*	drawn, but discardCount not increasing is not explained. Checked
*	call to discardCard function as well as discardCard function itself;
*	trashFlag not set so it is not clear how to replicate problem.
*		ORIGINAL LINE 1263  for (i = 0; i <= 3; i++)
* 		CORRECTD LINE 1263  for (i = 0; i < 3; i++)
* 
* Bug 2 - Wesley Jinks
* 	Description: Action count isn't decremented
* FIX - This is an error in testing. The test suite does not call the
* 	playCard() function, the end of which is responsible for decrementing the
* 	action counter. Test suite calls the cardEffect() function, which does not
*	decrement the action counter.
*
* Bug 3 - Max Grubb
* 	Title: Smithy discard fail 
* 	Classification: Severe
* 	Description: Author refactored playSmith() to draw four cards instead of 
*	three. Operations are correct, but counting incorrect.
* FIX - Corrected this error as part of Bug 1 fix.
******************************************************************************/

/******************************************************************************
* ADVENTURER CARD BUGS REPORTED
* Bug 1 - Wesley Jinks
* 	Description: Adventurer is kept in hand and isn't discarded, affecting 
* 	hand count and discard count
* FIX - Added a discardCard() call to the end of playAdventurer to discard
*	the adventurer card as indicated in handPos variable.
*		ADDED TO LINE 1161  discardCard(handPos, currentPlayer, state, 0);
*
* Bug 2 - Wesley Jinks
* 	Description: Action count isn't decremented
* FIX - This is an error in testing. The test suite does not call the
* 	playCard() function, the end of which is responsible for decrementing the
* 	action counter. The cardEffect() function does not decrement the action
*	counter.
*
* Bug 3 - Wesley Jinks
* 	Description: treasure cards are lower than expected when reshuffling 
* 	isn't needed and is higher when reshuffling and discarding is needed
* FIX - Test correctly found bug I introduced that does not reshuffle discard
*	pile into deck for use with adventurer card. Corrected by adding a call
*	to shuffle() function back in if the deckCount is < 1 (also known as 0).
*		ADDED TO LINE 1135  if (state->deckCount[currentPlayer] < 1)
*		ADDED TO LINE 1136  {
*		ADDED TO LINE 1137  	//if the deck is empty we need ...
*		ADDED TO LINE 1138  	shuffle(currentPlayer, state);
*		ADDED TO LINE 1139  }
* 
* Bug 4 - Max Grubb
*	Title: Deck count off after random testing adventurer
*	Classification: Medium
*	Description: I found a similar bug in in my random testing of my own code. 
*	About 3 in 75 runs results in a deck miscount.
*	I have yet to figure out why the random testing does this, and it 
*	admittedly could be an issue with my own testing. 
* FIX - Unable to replicate problem as described. May have been corrected by
*	action taken to fix Bug 3, because problem described in Bug 3 would result
*	in deck counts that are not as expected if shuffle() was not called asctime
*	needed.
******************************************************************************/