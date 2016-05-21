Bugs found in smithjoe/dominion:

	1. In testing the council room card effect, one too few cards is being pulled from the deck in the current player's hand
		- The council room card should withdraw 4 cards from the players deck, adds them to their hand and then gives 1 extra buy to player
		- test results show:
		  player 1: hand count = 7, expected = 8
					deck count = 2, expected = 1
					buys count = 2, expected = 2
		all other values are correct with this card effect.
		
	2. In testing the adventurer card effect, only one treasure card is being withdrawn from the deck and the adventurer card is not 
	   being discarded from the player's hand.
	   - The adventurer card pulls 2 treasure cards out of the players deck and adds it to there hand.
	   - test results show:
	     player 1: hand count = 6, expected = 6		when using copper
				   deck count = 4, expected = 3
				   coins = 5, expected = 6
				   
		 player 1: hand count = 6, expected = 6		when using silver
				   deck count = 4, expected = 3
				   coins = 10, expected = 12
				   
		 player 1: hand count = 6, expected = 6		when using gold
				   deck count = 4, expected = 3
				   coins = 15, expected = 18
				   
		You'll notice that in all cases there is one treasure card worth of value less from each coins value of the copper, silver, gold test cases.
		Also you should notice that the hand count and deck count do not add up correctly since there are only 10 cards that player 1 should have. 
		Even when adventurer pulls out only 1 treasure card, the player should have 5 cards in hand, 4 cards in deck and 1 card in discarded.
		
Bugs found in spolsdoj/dominion:

Have not been able to test since his refactoring wasn't correct.
The refactoring was commented out and even when uncommented and embedded within the cardEffect switch statment it does not compile.

Bugs found in dimuzioa/dominion:

	1. In testing the council room card effect, it appears that the council room card is not being discarded and that there is no buys being added.
		- The council room card should withdraw 4 cards from the players deck, adds them to their hand and then gives 1 extra buy to player
		- test results show:
		  player 1: hand count = 9, expected = 8
					deck count = 1, expected = 1
					buys count = 1, expected = 2
		all other values are correct with this card effect.
		
	2. In testing the smithy card effect, it appears that the smithy card is drawing one too many cards out of the deck.
		- The smithy card should withdraw 3 cards from the players deck and add them to the players hand
		- test results show:
		  player 1: hand count = 8, expected = 7
					deck count = 1, expected = 2
					coins = 4, expected = 4
		all other values are correct with this card effect.