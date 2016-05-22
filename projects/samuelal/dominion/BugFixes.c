Alex Samuel
Assignment 5
BugFixes.c

smithyCard()
Bug Fix: The original bug found was that when this card was played 4 cards were being drawn by the player
instead of 3. The bug fix eliminates that error and now 3 cards are now drawn instead of 4. In order to fix 
this bug, the for loop which executed the drawCard() function was modified.
Specific Code Change:
	for (i = 0; i < 4; i++)  is changed to for (i = 0; i < 3; i++)

adventurerCard()
Bug Fix: The original bug found was that 3 treasure cards were bring drawn by the player instead of 2. The bug fix 
eliminates that error and now 2 cards are now drawn instead of 3. In order to fix this bug, the condition which 
triggered execution of the while loop was modified.
Specific Code Change:
	while(drawntreasure<3) is changed to while(drawntreasure<2)

Bug Fix: Another bug that was found was that the Adventurer Card was not discarded after it was played. This error 
was corrected by calling the discardCard() function after both while loops within adventurerCard() had finished 
executing.
Specific Code Change:
	discardCard(handPos, currentPlayer, state, 0); added before return statement.

great_hallCard()
Bug Fix: The original bug found was that when the player plays this card, the great_hall card is not discarded 
and 2 cards are drawn instead of 1. This bug was fixed by replacing one of the calls to drawCard() with a call 
to discardCard().
Specific Code Change:
	drawCard(currentPlayer, state); is changed to discardCard(handPos, currentPlayer, state, 0);

embargoCard()
Bug Fix: The first bug found in this implementation is that the Embargo Card is not trashed immediately after 
it is played. It is merely added to the playedCard pile. This bug was fixed by changing the trashFlag for 
discardCard() from 0 to 1.
Specific Code Change:
	discardCard(handPos, currentPlayer, state, 0); is changed to discardCard(handPos, currentPlayer, state, 1);

Bug Fix: The second bug found was that Embargo Card increases player's number of actions by 2 rather than the 
number of coins by 2. This was fixed by incrementing the coins value in state rather than numActions.
Specific Code Change:
	state->numActions = state->numActions + 2; is changed to state->coins = state->coins + 2;

isGameOver()
Bug Fix: One bug was found in the isGameOver() function where the function only iterates between curse and salvager 
cards to determine if any of the supply piles of these cards are empty. The function fails to check if sea_hag and 
treasure_map piles are empty. This bug was fixed by increasing the range of the iteration of the for loop which 
iterates over each of the 27 card types so that it will also check the supply piles of sea_hag and treasure_map cards.
Specific Code Change:
	for (i = 0; i < 25; i++) is changed to for (i = 0; i < 27; i++)