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

great_hallCard()
Bug Fix: The original bug found was that when the player plays this card, the great_hall card is not discarded 
and 2 cards are drawn instead of 1. This bug was fixed by replacing one of the calls to drawCard() with a call 
to discardCard().
Specific Code Change:
	drawCard(currentPlayer, state); is changed to discardCard(handPos, currentPlayer, state, 0);