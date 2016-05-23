Bryan Serif
Assignment 5
Filename: BugFixes.c


Bugs Provided by teammates:
Smithy: test failed. Incorrect number of cards added to current player's hand /
		test failed. Incorrect number of cards drawn
Adventurer: test failed. Cards incorrectly added to the current player’s hand /
			test failed. bug fix needed
			
Fixes made to smithy:
	Upon running GDB and code review I found that my playSmity() function was 
	only drawing one card into the player's hand instead of three. The 
	following code was updated:
	
	Before Fix:
	int playSmithy(struct gameState *state, int currentPlayer, int handPos)
	{
		// draw a card
		drawCard(currentPlayer, state);

		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);

		return 0;
	}
	
	After Fix:
	int playSmithy(struct gameState *state, int currentPlayer, int handPos)
	{
		int i;
		
		for (i = 0; i < 3; i++)
		{
			drawCard(currentPlayer, state);
		}
		

		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);

		return 0;
	}
	
Fixes made to adventurer:
	On reviewing the code for the adventurer card if discovered that playAdventurer()
	was only counting copper and silver as treasure card and omit gold. The following
	code was changed:
	
	Before Fix:
	while (drawntreasure<2){
		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver)
			drawntreasure++;
		else{
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	
	After Fix:
	while (drawntreasure<2){
		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else{
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	
Other Bugs Found;
	There were bugs found in both my village card and my great hall card.
	
Fixes made to village:
	On debugging my code I found that the number of actions village was adding
	was i when it should have been two. It was also drawing 2 cards instead of
	one. The following code was updated:
	
	Before Fix:
	int playVillage(struct gameState *state, int currentPlayer, int handPos)
	{
		drawCard(currentPlayer, state);
		drawCard(currentPlayer, state);

		state->numActions = state->numActions + 1;

		//discard played card from hand
		discardCard(handPos, currentPlayer, state, 0);

		return 0;
	}
	
	After Fix:
	int playVillage(struct gameState *state, int currentPlayer, int handPos)
	{
		drawCard(currentPlayer, state);

		state->numActions = state->numActions + 2;

		//discard played card from hand
		discardCard(handPos, currentPlayer, state, 0);

		return 0;
	}
	
Fixes made to great_hall
	On review of my code for great_hall it was discovered that the number of
	actions was decresing instead of increasing. The following changes were
	made;
	
	Before Fix:
	int playGreatHall(struct gameState *state, int currentPlayer, int handPos)
	{
		drawCard(currentPlayer, state);

		state->numActions--;

		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);

		return 0;
	}
	
	After Fix:
	int playGreatHall(struct gameState *state, int currentPlayer, int handPos)
	{
		drawCard(currentPlayer, state);

		state->numActions++;

		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);

		return 0;
	}
	
	
For the card functions where bugs were found I do not believe that coverage was
too much of a concern outside of just making sure that the card functions were run.
Most of these functinos are written in a way that as long as they get run one time
you will have about 100% coverage. The only card function that this does not hold
true for was adventurer. This is due to the fact that if the first two cards that 
are drawn are considered treasure, then the else statement will not be covered in
the while (drawnTreasure <2) statement. Other bugs were not found in my dominion
code however due to my grand scheme coverage being low. 