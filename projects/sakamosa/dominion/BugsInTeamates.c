BugsInTeamates.c

**********************************************************************
Brandon: swansonb

#1: Problem in cardEffect function when smithy card is played.

Summary: When the smithy card is passed to the cardEffect function, inaccuracies are found in the resulting game state.

	Bug 1A: The current player's deck count was reduced by 4 and not by 3 as expected.

	Bug 1B: The current player's hand count increases by 3 and not by 2 as expected. We would expect to see an increase of 3 from three 	cards drawn, less one for the discarded smithy card.

	Bug1C: There is an incorrect number of cards in the current player's discard pile.

	A, B, and C all point to an incorrect number of cards (4) being drawn.


#2: Problem in initializeGame function.

Summary: There is an apparent error in the initializeGame function that gives the players an incorrect number of cards.

	After the initilizeGame function is called to initialize a two player game, the first player (index 0) is given 5 cards while the second player is given 10.
	
	 

************************************************************************

Alisha: crawleya

#1: Problem in cardEffect function whe adventurer card is played.

Summary: When the adventurer card is passed to the cardEffect function, inaccuracies are found in the resulting game state.

	Bug 1A: The current player's deck count was reduced by 4 and not by 3 as expected.

	Bug 1B: The current player's hand count increases by 4 and not by 1 as expected. We would expect to see an increase of 2 from three 	cards drawn, less one for the discarded adventurer card.

	Bug1C: An incorrect number of treasure cards were added to the player's hand. We would expect 2 new cards, but there are 3.

	Bug1D: The number of cards in the current player's discard pile did not increase. We would expect to see an increase of 1 from the discarding of the adeventurer card, but it remained 0.

	A, B, C and D point to two separate but related problems. It appears that the number of treasure cards drawn is incorrect. It also appears that no card is discarded.


#2: Problem in initializeGame function.

Summary: There is an apparent error in the initializeGame function that gives the players an incorrect number of cards.

	After the initilizeGame function is called to initialize a two player game, the first player (index 0) is given 5 cards while the second player is given 10.	
