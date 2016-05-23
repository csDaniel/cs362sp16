# Author: tranm2
# CS362 - Spring 2016

//---------Bug 1------------
// shuffle() function is broken, does not shuffle when deck is 0 like
//it is supposed to.
// Fix -  In shuffle() add to resolve deckCount = 0 state
if (state->deckCount[player] == 0)
    return 0;

//---------Bug 2------------
// fullDeckCount() does not return anything but 0 regardless of how many
//cards are in the deck/hand/discard.
// Fix -  Initialize count = 0
int count = 0;

//---------Bug 3------------
// Adventurer card effect
// Once the card is play, instead of discard adventurer card into discard pile, 
//dominion only removes the card from the hand
// Fix - update adventure card effect - see comments for changes 
int adventurer_effect(int currentPlayer, struct gameState *state, int handPos, int bonus)
{ 
	...

	while(drawntreasure<2)
	{
		if (state->deckCount[currentPlayer] < 1) 
		{
		//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
	  	//REVISED------break out of the loop when deck is empty
	  		break;
		}
		//REVISED------draw new card
		drawCard(currentPlayer, state);

		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		{
	  		drawntreasure++;
		}	
		else
		{
			//REVISED-------discard non treasure card into discard pile instead of just removing it from hand
	  		discardCard((state->handCount[currentPlayer]-1), currentPlayer, state, 0);
		}
	}

	//REVISED------add update coins at the end
	updateCoins(currentPlayer, state, 0);

	return 0;
}

//---------Bug 3------------
// Smithy card effect
// In the action phase, player draws 4 cards while smithy only allows 3
// At the end of the turn, smithy card does not return to discard pile
// Fix - Set counter to i<3 instead of i<=3
for (i = 0; i < 3; i++)

//--------Bug 4-----------
// Village card effect	
// village failed to discard card into discard pile	
// Fixed discardCard() function by changing trashflag to 0, instead of 1
discardCard(handPos, currentPlayer, state, 0);

//--------Bug 5-----------
// Mine card knows no bounds
// mine card accepts card enumerations less than curse (0) and greater than
// treasure_card (26) as choice2 of cardEffect() function call.
// Expected: Mine card should fail and return -1 for card enumerations outside the
// accepted domain (0 - 26).
// Actual Results:  mine card does not fail and accepts card enumerations outside the card
// enumeration domain of 0 - 26, returning 0.
 
// Fix - Can't reproduce bug.
// Step: Run cardEffect(mine, 3, -1, choice3, &testG, handpos, &bonus); for cardtest5.c
// choice2 = -1 
 if (choice2 > treasure_map || choice2 < curse)
	{
		printf("Failed 02");
	  	return -1;
	}
// Program exits with "Failed 02" message as expected