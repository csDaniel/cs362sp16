/* 
Author: Jonathan Hardman
File name: randomtestcard.c

Card Effect Requirements: Smithy
1. Current player should receive exact 3 cards.

2. 3 cards should come from his own pile.

3. No state change should occur for other players.

4. No state change should occur to the victory card piles and kingdom card piles.


CARD IMPLEMENTATION NOTES:
Card Inputs: gameState *state, int handPos

Used External Variables:
whoseTurn(state)	(should be anywhere between 0 and state->numPlayers-1)

*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


/**************************TESTING DIALS****************************/
//Set for total number for test cycles you want to run for each treasure type
#define TOTAL_CYCLES 100


//Altered initializeGame function which allows for custom deck size, starting hand size, and current player
//returns a initialized game state
int initializeGame2(int numPlayers, int kingdomCards[10], int randomSeed,
		   struct gameState *state, int initdeckSize, int inithandSize, 
		   int thisPlayer);


int main() {
	//Control switches
	//1 = ON, 0 = OFF
	int AlltextON = 0;
	
	//Comparison variables
    int p1newCards = 0;
	int p1discarded = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;
	
	//Looping variables
    int t,cycles;
	
	//card effect variables
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	
	//Randomly generated variables
    int numPlayers, initdeckSize, inithandSize, handPos, thisPlayer, otherPlayer;
	
	//Test result variable
	int status;
	
	//Game state initialization
	int seed = 1000;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	//Reset random number generator
	srand(time(NULL));
	
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("| Player Count | Current Player |    Deck Size   |   Drawn Cards  |  Hand Position |    PASS/FAIL   |\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	
	for(cycles=0; cycles<TOTAL_CYCLES; cycles++)
	{
		//randomly pick number of players between 2 and MAX_PLAYERS
		numPlayers = MAX_PLAYERS - (rand() % (MAX_PLAYERS - 1));
		printf("\t%i\t", numPlayers);
		
		//randomly pick current player between 0 and numPlayers - 1
		thisPlayer = rand() % numPlayers;
		printf("\t%i\t", thisPlayer);
		
		//Set other player reference with respect to current player
		if(thisPlayer == (numPlayers-1)) //if current player is max value
			otherPlayer = thisPlayer - 1;
		else
			otherPlayer = thisPlayer + 1;
		
		//randomly pick a deck size between 10 and MAX_DECK
		initdeckSize = MAX_DECK - (rand() % (MAX_DECK - 9));
		printf("\t%i\t", initdeckSize);
		
		//randomly pick a drawn card amount between 5 and initdeckSize
		inithandSize = initdeckSize - (rand() % (initdeckSize - 4));
		printf("\t%i\t", inithandSize);
		
		//randomly pick a hand position between 0 and inithandSize-1
		handPos = rand() % inithandSize;
		printf("\t%i\t", handPos);
		
		// initialize a game state and player cards
		initializeGame2(numPlayers, k, seed, &G, initdeckSize, inithandSize, thisPlayer);
	
		//copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
	
		//USE SMITHY
		cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);

		p1newCards = 3;
		p1discarded = 1;
		status = 1;
		
		
		/********************Player 1 checks***********************/
		if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + p1newCards - p1discarded)
			status &= 0;
		if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - p1newCards + shuffledCards)
			status &= 0;
		if(testG.coins != G.coins)
			status &= 0;
		if(testG.numActions != G.numActions)
			status &= 0;
		if(testG.numBuys != G.numBuys)
			status &= 0;
		
		if(AlltextON == 1){
			printf("\nPlayer 1 checks\n");
			printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + p1newCards - p1discarded);
			printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - p1newCards + shuffledCards);
			printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
			printf("actions = %d, expected = %d\n", testG.numActions, G.numActions);
			printf("buys count = %d, expected = %d\n", testG.numBuys, G.numBuys);
		}
		
	
		/********************Player 2 checks***********************/
		if(testG.handCount[otherPlayer] != G.handCount[otherPlayer])
			status &= 0;
		if(testG.deckCount[otherPlayer] != G.deckCount[otherPlayer])
			status &= 0;
	
		if(AlltextON == 1){
			printf("\nPlayer 2 checks\n");
			printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
			printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
		}
	
		
		/********************Supply checks***********************/
		//checking victory cards
		int temp = supplyCount(estate,&testG), temp2 = supplyCount(estate,&G);
		if(temp != temp2)
			status &= 0;
		
		temp = supplyCount(duchy,&testG), temp2 = supplyCount(duchy,&G);
		if(temp != temp2)
			status &= 0;
		
		temp = supplyCount(province,&testG), temp2 = supplyCount(province,&G);
		if(temp != temp2)
			status &= 0;
	
		//checking kingdom cards
		for (t=0; t<10; t++)
		{
			temp = supplyCount(k[t],&testG);
			temp2 = supplyCount(k[t],&G);
			if(temp != temp2)
				status &= 0;
		}
		
		//Check if PASS/FAIL status changed
		if (status == 1){
			printf("\tPASSED\n");
		}else{
			printf("\tFAILED\n");
		}
	}
	
	return 0;
}

/**********************************************************************************************
***********************************************************************************************
***********************************************************************************************
***********************************************************************************************
***********************************************************************************************
**********************************************************************************************/

int initializeGame2(int numPlayers, int kingdomCards[10], int randomSeed,
		   struct gameState *state, int initdeckSize, int inithandSize,
		   int thisPlayer) {

  int i;
  int j;
  int it;			
  //set up random number generator
  SelectStream(1);
  PutSeed((long)randomSeed);
  
  //check number of players
  if (numPlayers > MAX_PLAYERS || numPlayers < 2)
    {
      return -1;
    }

  //set number of players
  state->numPlayers = numPlayers;

  //check selected kingdom cards are different
  for (i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
        {
	  if (j != i && kingdomCards[j] == kingdomCards[i])
	    {
	      return -1;
	    }
        }
    }


  //initialize supply
  ///////////////////////////////

  //set number of Curse cards
  if (numPlayers == 2)
    {
      state->supplyCount[curse] = 10;
    }
  else if (numPlayers == 3)
    {
      state->supplyCount[curse] = 20;
    }
  else
    {
      state->supplyCount[curse] = 30;
    }

  //set number of Victory cards
  if (numPlayers == 2)
    {
      state->supplyCount[estate] = 8;
      state->supplyCount[duchy] = 8;
      state->supplyCount[province] = 8;
    }
  else
    {
      state->supplyCount[estate] = 12;
      state->supplyCount[duchy] = 12;
      state->supplyCount[province] = 12;
    }

  //set number of Treasure cards
  state->supplyCount[copper] = 60 - (7 * numPlayers);
  state->supplyCount[silver] = 40;
  state->supplyCount[gold] = 30;

  //set number of Kingdom cards
  for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
    {
      for (j = 0; j < 10; j++)           		//loop chosen cards
	{
	  if (kingdomCards[j] == i)
	    {
	      //check if card is a 'Victory' Kingdom card
	      if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
		{
		  if (numPlayers == 2){ 
		    state->supplyCount[i] = 8; 
		  }
		  else{ state->supplyCount[i] = 12; }
		}
	      else
		{
		  state->supplyCount[i] = 10;
		}
	      break;
	    }
	  else    //card is not in the set choosen for the game
	    {
	      state->supplyCount[i] = -1;
	    }
	}

    }

  ////////////////////////
  //supply initialization complete

  //set player decks
  for (i = 0; i < numPlayers; i++)
  {	
	state->deckCount[i] = 0;
    for (j = 0; j < initdeckSize; j++) //BEGINNING OF CHANGES
	{	
		state->deck[i][j] = estate; //set a card, doesn't matter which
		state->deckCount[i]++;
	}
  }

  //shuffle player decks
  for (i = 0; i < numPlayers; i++)
    {
      if ( shuffle(i, state) < 0 )
	{
	  return -1;
	}
    }

  //draw player hands
  for (i = 0; i < numPlayers; i++)
    {  
      //initialize hand size to zero
      state->handCount[i] = 0;
      state->discardCount[i] = 0;
      //draw 5 cards
      // for (j = 0; j < 5; j++)
      //	{
      //	  drawCard(i, state);
      //	}
    }
  
  //set embargo tokens to 0 for all supply piles
  for (i = 0; i <= treasure_map; i++)
    {
      state->embargoTokens[i] = 0;
    }

  //initialize first player's turn
  state->outpostPlayed = 0;
  state->phase = 0;
  state->numActions = 1;
  state->numBuys = 1;
  state->playedCardCount = 0;
  state->whoseTurn = thisPlayer;
  state->handCount[state->whoseTurn] = 0;
  //int it; move to top

  //Moved draw cards to here, only drawing at the start of a turn
  for (it = 0; it < inithandSize; it++){	//CHANGED DRAW COUNT
    drawCard(state->whoseTurn, state);
  }

  updateCoins(state->whoseTurn, state, 0);

  return 0;
}




