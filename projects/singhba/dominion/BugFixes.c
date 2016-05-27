/***DiscardCard Bug ****/
Test Status: Failed... the function allows you to call the function with an invalid hand position
and then decreases the handcount even though the card position was invalid. Reported by: donneler

/**FIX***/ Added assert(G.handCount[p] > -1); statement to the unitest3.c which was used to test discardCard

int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
  /**FIX**/ 
    /*Added this condition to fix the bug for invalid had pos****/
  if ( state->handCount[currentPlayer] <= 0 || handPos < 0) //No Card in player hand
    {
      //return 
      return 0;
    }
	
  //if card is not trashed, added to Played pile 
  if (trashFlag < 1)
    {
      //add card to played pile
      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
      state->playedCardCount++;
    }
	
  //set played card to -1
  state->hand[currentPlayer][handPos] = -1;
	
  //remove card from player's hand
  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else 	
    {
      //replace discarded card with last card in hand
      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
      //set last card to -1
      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
	
  return 0;
}

/*******************************************************/
/****Bug in smithy card ***/
int smithyEffect(struct gameState *state, int handPos)
Testfile: cardtest2.c
Test Status: Failed.
handcount is one less than expected. Reported by: donneler
PlayedCardCount was wrong also reported by kosloffd

//Method for effect of smithy
int smithyEffect(struct gameState *state, int handPos){
  int currentPlayer = whoseTurn(state);
  int i;
  //+3 Cards
  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }  
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);  /**FIX**/ //Changed thrash flag back to 0 and all the test passed
  return 0;
}
----------------- Testing Card: smithy ----------------
----------------- Player 0: smithy ----------------
hand count = 7, expected = 7
deck count = 2, expected = 2
actions = 1, expected = 1
playedcards = 1, expected = 1
----------------- Player 1: smithy ----------------
hand count = 0, expected = 0
deck count = 10, expected = 10
actions = 1, expected = 1

/****************************************/
/******Bug in adveturerCard ***/
FAILED: Played Card Count was wrong
FAILED: Discard pile and Deck count was wrong
FAILED: handCount is wrong
BUG - adventurerEffect does not exit if there are no treasures in the discard pile or the players deck. reported by :donneler

/***Added following code to cartest4.c to assert number of treasure card added when 2 treasure cards on deck**////
tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 2);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 2 == tresureAfter);
 /***********************************************/
 
 /***Added following code to cartest4.c to assert number of treasure card added when 1 treasure card on deck**////
tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 1);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 1 == tresureAfter);
 /***********************************************/
 
 /******Addded following code to test when there is no treasure on deck case reported by donneler***/
 /*deck top 10 cards*/
	for(i = 1; i < 11; i++){			
		G.deck[thisPlayer][i] = smithy;
	}
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0: 0 treasure on deck: %s ----------------\n", TESTCARD);
	newCards = 10;
	xtraActions = 0;
	xtraPlayedCard= 1;
	discarded = 10;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	printf("discardcards = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 0);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 0 == tresureAfter);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("FAIL: handCount is wrong\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("FAIL: deckCount is wrong\n");
	}
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] + discarded){
		printf("FAIL: discardCount is wrong\n");
	}
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}
  
  /******Addded following code to test when there is no treasure on deck but there is treasure is on discard pile case reported by donneler***/
	initializeGame(numPlayers, k, seed, &G);
	G.deckCount[thisPlayer] = 0;
	G.discardCount[thisPlayer] = 10;

	/*deck top 10 cards*/
	for(i = 1; i < 11; i++){			
		G.discard[thisPlayer][i] = gold;
	}
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0: 0 treasure on deck: %s ----------------\n", TESTCARD);
	newCards = 2;
	xtraActions = 0;
	xtraPlayedCard= 1;
	discarded = 0;
	shuffledCards = 10;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	printf("discardcards = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] -10 + discarded);
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 2);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 2 == tresureAfter);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("FAIL: handCount is wrong\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("FAIL: deckCount is wrong\n");
	}
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] -10 + discarded){
		printf("FAIL: discardCount is wrong\n");
	}
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}

/*******************FIX for adventurerEffect ***************/
//Method for effect of Adventurer
int adventurerEffect(struct gameState *state, int handPos){
  int drawntreasure = 0;
  int z = 0;
  int temphand[MAX_HAND];
  int cardDrawn;
  int currentPlayer = whoseTurn(state);
  while(drawntreasure<2){
    /**FIX changed to < 1 instead to <= 1 ****/
    if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else{
      temphand[z]=cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  /**FIX changed to z - 1 instead to z ****/
  while(z - 1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }
  state->playedCardCount++; /****FIX To add card to play count****/
  return 0;
}


/**********************************/
After fixing all the bugs, I ran all the tests again and all the tests were passed.
unittestresults.out, randomtestadventurer.out and randomtestcard.out are updated with current results

/****Coverage before ****/
File 'dominion.c'
Lines executed:32.80% of 561
Branches executed:32.85% of 417
Taken at least once:25.42% of 417
Calls executed:26.26% of 99
Creating 'dominion.c.gcov'

/****Coverage after adding more conditions in my tests which were reported by donneler*****/

File 'dominion.c'
Lines executed:33.69% of 564
Branches executed:33.02% of 421
Taken at least once:26.37% of 421
Calls executed:21.21% of 99
Creating 'dominion.c.gcov'

There is some improvement in coverage overall because of the bug conditions reported by donneler