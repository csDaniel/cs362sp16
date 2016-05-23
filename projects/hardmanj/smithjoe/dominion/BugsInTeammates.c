dimuzioa:


	
	on line 1307 of dominion.c in function playSmithyCard, change i < 4 to i < 3
	
	on line 1326 of dominion.c in function playGreatHall, call the function discardCard(handPos, currentPlayer, state, 0); to discard the card
	in great hall, hand count is 6 when it should be 5

hardmanj:

	in smithy, hand count is is 8 when it should be 7. Deck count is 2 when it should be 1.
	on line 707 of dominion.c, change <= to <, so that one less card is drawn
	
	on line 676 of dominion.c, make sure a return statement is present to prevent errors.
	

spolsdoj:

	in adventurer , deck count is 3 when it should be 2
	in line 1368, modify   while(drawntreasure<3){ to  while(drawntreasure<2){ 
	
	
	in line 1390 of dominion.c, for smithy modify i < 4 into i < 3 
	
	