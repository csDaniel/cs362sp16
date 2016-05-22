/************************
Team Mate - Gunnar Martin

This team mate separated the adventurer function from its original form and created a new function called useAdventurer();  This new function nearly mimics the original function, aside from the errors he created. When he re-factored the code, he added an extra discardCard() function, which we will have to remove for proper function. This was his refactored code:

	
int useAdventurer(struct gameState *state, int handPos, int currentPlayer){
	
	int drawntreasure=0;
	int cardDrawn;
	int temphand[MAX_HAND];// moved above the if statement
	int z = 0;// this is the counter for the temp hand
	
	while(drawntreasure<2){
		if (state->deckCount[currentPlayer] <1){
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; 
			z++;
		}
	}
	while(z-1>=0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
		z=z-1;
	}
	
	discardCard(handPos, currentPlayer, state, 1);    //   *********  This is what has to be removed *********
	
	return 0;

}



In the smithy card function, we need to change the loop to draw only 3 cards. There is also an extra discardCard statement we need to remove This was his code:

int useSmithy(struct gameState *state, int handPos, int currentPlayer){

	int i;

	//+3 Cards
	for (i = 0; i < 4; i++){   // ********* Change to for (i = 0; i < 3; i++ *********
		
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	discardCard(handPos+1, currentPlayer, state, 0);  // *********  EXTRA REMOVE THIS *********
	
	return 0;
	
};

************************/