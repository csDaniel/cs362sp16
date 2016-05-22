//bugfixes.c

//Fixed functions with comments

/*
Subtracted 1 from second array index when setting cardDrawn = state->hand[][] 
to properly set selection to top card in current player's hand
added call to discardCard() at end of method to ensure card is added to played pile
*/
int playAdventurer(struct gameState *state, int handPos, int currentPlayer) {
  int drawnTreasure = 0;
  int cardDrawn;
  int z = 0; //counter for temp hand
  int temphand[MAX_HAND];
  
  while (drawnTreasure < 2) {
    if (state->deckCount[currentPlayer] < 1) {
      //if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    
    //UPDATED
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];
    //top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawnTreasure++;
    else {
      temphand[z] = cardDrawn;
      state->handCount[currentPlayer]--; 
      //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  
  discardCard(handPos, currentPlayer, state, 0); //UPDATED
  return 0;
}

//updated code with call to discardCard() function at end of method
int playSmithy(struct gameState *state, int handPos, int currentPlayer) {
  int i = 0;
  
  //+3 Cards
  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }

  discardCard(handPos, currentPlayer, state, 0); //UPDATED
  return 0;
  
}

//Original functions

/*
  when setting the value of cardDrawn - the value should be set to 
  state->hand[currentPlayer][state->handCount[currentPlayer] - 1]
  but the subtract 1 has been omitted
  the cardDrawn in this case will be an index beyond the actual cards in hand
  so likely have a value of -1
  
  another interesting aspect of the implementation of adventurer in the source code
  that was refactored for this assignment
  is that the card is not discarded - so technically could be played again if the user
  had previously played a card giving +2 actions - probably a bug?
*/
int playAdventurer_Bad(struct gameState *state, int handPos, int currentPlayer) {
  int drawnTreasure = 0;
  int cardDrawn;
  int z = 0; //counter for temp hand
  int temphand[MAX_HAND];
  
  while (drawnTreasure < 2) {
    if (state->deckCount[currentPlayer] < 1) {
      //if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]];
    //top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawnTreasure++;
    else {
      temphand[z] = cardDrawn;
      state->handCount[currentPlayer]--; 
      //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  return 0;
}

//bug - card is not discarded at end of function - allowing
//user to play it again
int playSmithy_Bad(struct gameState *state, int handPos, int currentPlayer) {
  int i = 0;
  
  //+3 Cards
  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }

  return 0;
}