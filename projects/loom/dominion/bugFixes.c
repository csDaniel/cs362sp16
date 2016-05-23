//
// Created by Michael Loo on 5/22/16.
//
/*
 * BUGS FOUND
 *
 * Michael Loo/loom
    Village Card - The village cards gives the wrong amount of actions.

    Smithy Card - The player does not draw 3 cards.
 *
 *Smithy Card - The player drew 2 cards instead of the expected 3.

Adventurer Card: Player drew non treasure card to hand.

Remodel Card: wrong card added when trading (card action returns -1 on
 applicable card effect ie returns as non legal move when it is legal)
 *
 *
 */


//Village card fix

/*

old code:

 int playVillage(struct gameState *state, int handPos){

  int currentPlayer = whoseTurn(state);
  //+1 Card
  drawCard(currentPlayer, state);

  //+2 Actions
  state->numActions = state->numActions;

  //discard played card from hand
  discardCard(handPos, currentPlayer, state, 1);
  return 0;

new code:

int playVillage(struct gameState *state, int handPos){

  int currentPlayer = whoseTurn(state);
  //+1 Card
  drawCard(currentPlayer, state);

  //+2 Actions
  state->numActions = state->numActions++;

  //discard played card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;

}


//smithy card fix

old code:

 int playSmithy(struct gameState *state, int handPos){

  int i;
  int currentPlayer = whoseTurn(state);

  for (i = 0; i < 2; i++)
  {
    drawCard(currentPlayer, state);
  }

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 1);

  return 0;
}

 new code:

 int playSmithy(struct gameState *state, int handPos){

  int i;
  int currentPlayer = whoseTurn(state);

  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 1);

  return 0;
}

 Remodel card:

      j = state->hand[currentPlayer][choice1];  //store card we will trash

      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
	{
	  return -1;
	}

      gainCard(choice2, state, 0, currentPlayer);

      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);

      //discard trashed card
      for (i = 0; i < state->handCount[currentPlayer]; i++)
	{
	  if (state->hand[currentPlayer][i] == j)
	    {
	      discardCard(i, currentPlayer, state, 0);
	      break;
	    }
	}

      return 0;

Through testing, I did not find any errors with this card.  According to the test report, this function fails when
 trying to add the adventurer card.  However, I did not introduce any bugs into this code and do not see any errors.

 */