/*

Teammate 1, Joe Cuellar:

Notes: No editing needed to be done to match card or function names, indicates very maintainable tests. 

Adventurer Card:
	Location: inside while loop in callAdventurerCard.
	Bug #1: state->handCount[currentPlayer] is not decremented
	Code: 
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]];
	Notes: Found as HandCount test failed for all players in test and TreasureCardCount failed for all players after Player 0. Notably, the HandCount matched the TreasureCardCount for each player.

Smithy Card:
	Location: declaration of for loop in callSmithyCard
	Bug #2: i terminates with 6, not 3
	Code: 
		  //+3 Cards
		  for (i = 0; i < 6; i++){
		    drawCard(currentPlayer, state);
		  }
	Notes: All tests failed except for which player played their turn. Test results indicate that two to three cards are drawn (depending on deckCount) but none are discarded. Code inspection shows this anomaly.

isGameOver():
	Notes: All tests passed; no bugs found. Code inspection revealed no modifications to function.


Teammate 2, James Taylor:

Notes: No editing needed to be done to match card or function names, indicates very maintainable tests. 

Adventurer Card:
	Location: first if statement of while loop in adventurer_ref
	Bug #3: current player's deckCount must be less than 1 to shuffle, not greater than
	Code:
		if (state->deckCount[currentPlayer] >1){//if the deck is empty we need to shuffle discard and add to deck
		  shuffle(currentPlayer, state);
		} 
	Notes: All tests passed; code inspection revealed this bug. 

Smithy Card:
	Location: declaration of for loop in smithy_ref
	Bug #4: i begins at 1, not 0
	Code: 
	      for (i = 1; i < 3; i++)
		{
		  drawCard(currentPlayer, state);
		}
	Notes: Tests showed that the function was drawing one less card than expected. 

isGameOver:
	Notes: All tests passed; no bugs found. Code inspection revealed no modifications to function.

*/