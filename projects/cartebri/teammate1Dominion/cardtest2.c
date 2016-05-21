/* Adventurer

    case adventurer:
      while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
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
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }
      return 0;
refactored adventurer:
  while(state->handCount[currentPlayer] > 0){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;

    temphand[z]=cardDrawn;
    state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
    z++;

    }
  while(z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
    }
  return 0;

*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

int main(){

    int i, j;
    int numPlayer = 2;
    int p, p2;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , sea_hag, smithy, village, cutpurse, great_hall};
    struct gameState G;
    struct gameState test;
    int cphandSize, cpdeckSize, ophandSize, opdeckSize;
    int numtests = 1;
    int amount;
    int totalDrawn;
    int drawnTreasure;


    for(i=0; i < numtests; i++)
    {
      p = 0;
      p2 = 1;

      initializeGame(numPlayer, k, 1200, &G);
      memcpy(&test, &G, sizeof(struct gameState));
      
      cpdeckSize = test.deckCount[p];
      opdeckSize = test.deckCount[p2];

      totalDrawn = 0;
      drawnTreasure = 0;
      amount = 0;
      int count;

      initializeGame(numPlayer, k, 1200, &G);
      memcpy(&test, &G, sizeof(struct gameState));
      test.hand[p][0] = adventurer; 
      test.hand[p][1] = village;
      test.hand[p][2] = province;
      test.hand[p][3] = smithy;
      test.hand[p][4] = copper;
      test.hand[p][5] = silver;
      test.hand[p][6] = gold;
      test.hand[p][7] = copper;
      test.hand[p][8] = silver;
      count = test.handCount[p];
      cardEffect(adventurer, 0, 0, 0, &test, 0, 0);
      if(test.handCount[p] - count == 2)
      {
        printf("PASSED. Coin card amount expected: %d   count finish: %d\n", 2, test.handCount[p] - count);
      }
      else
      {
        printf("FAILED. Coin card amount expected: %d   count: %d\n", 2, test.handCount[p] - count);
      }

  /*    printf("Coin cards found: ");
      for(j = 0; j< test.handCount[p]; j++)
      {
        if(test.hand[p][j] == copper)
        {
          printf("copper, ");
          amount += 1;
        }
        if(test.hand[p][j] == silver)
        {
          printf("silver, ");
          amount +=2;
        }
        if(test.hand[p][j] == gold)
        {
          printf("gold, ");
          amount += 3;

        }
      }
      */
     if(G.coins == test.coins)
     {
      printf("PASSED. Coin amount the same.\n");
     } 
     else
     {
      printf("FAILED. Coin amounts different.\n");
     }

     initializeGame(numPlayer, k, 1200, &G);
     memcpy(&test, &G, sizeof(struct gameState));
      test.hand[p][0] = adventurer;
      test.hand[p][1] = village;
      test.hand[p][2] = province;
      test.hand[p][3] = smithy;
      test.hand[p][4] = copper;
      test.hand[p][5] = silver;
      test.hand[p][6] = gold;
      test.hand[p][7] = copper;
      test.hand[p][8] = silver;
      count = test.handCount[p];

      printf("Test hand before card played.\n");
      for(j = 0; j < test.handCount[p]; j++)
      {
        printf("Card: %d\n", test.hand[p][j]);
      }

      cardEffect(adventurer, 0, 0, 0, &test, 0, 0);

      printf("Test hand after card played.\n");
      for(j = 0; j < test.handCount[p]; j++)
      {
        printf("Card: %d\n", test.hand[p][j]);
      }

      if(test.handCount[p] == count + 2)
      {
        printf("PASSED. Before Hand count: %d  After hand count: %d\n", count, test.handCount[p]);
      }
      else
      {
        printf("FAILED. Hand count before: %d hand count after: %d\n", count, test.handCount[p]);
      }

/*      printf("coin cards found: ");

            for(j = 0; j< test.handCount[p; j++])
      {
        if(test.hand[p][j] == copper)
        {
          printf("copper, ");
          amount += 1;
        }
        if(test.hand[p][j] == silver)
        {
          printf("silver, ");
          amount +=2;
        }
        if(test.hand[p][j] == gold)
        {
          printf("gold, ");
          amount += 3;

        }
      }
*/
      initializeGame(numPlayer, k, 1200, &G);
     memcpy(&test, &G, sizeof(struct gameState));
      test.hand[p][0] = adventurer;
      test.hand[p][1] = village;
      test.hand[p][2] = province;
      test.hand[p][3] = smithy;
      test.hand[p][4] = copper;
      test.hand[p][5] = silver;
      test.hand[p][6] = gold;
      test.hand[p][7] = copper;
      test.hand[p][8] = duchy;
      cardEffect(adventurer, 0, 0, 0, &test, 0, 0);

     /* if(1 == test.discardCount[p])
      {
        printf("PASSED. Expected 1 card in the discard pile.\n");
      }
      else
      {
        printf("FAILED. Expected 1 discard. Actual: %d\n", test.discardCount[p]);
      }
*/
      if(test.deckCount[p2] == opdeckSize)
      {
        printf("PASSED. Other player's deck size is the same.\n");
      }
      else
      {
        printf("FAILED. Other player's deck size changed.\n");
      }


      if(test.handCount[p2] == G.handCount[p2])
      {
        printf("PASSED. ohter players hand count is the same.\n");
      }
      else
      {
        printf("FAILED. Other players hand count changed.\n");
      }

      if(test.deckCount[p] == G.deckCount[p] - 2)
      {
        printf("PASSED. cards removed from player's deck\n");
      }
      else
      {
        printf("FAILED. cards not removed from players deck\n");
        printf("   test deck: %d   game deck: %d\n", test.deckCount[p], G.deckCount[p]);
      }

    /*  if(test.playedCardCount == 1)
      {
        printf("PASSED. Card moved to played pile\n");
      }
      else
      {
        printf("FAILED. Card not moved to played pile\n");
      }
*/
              if(test.supplyCount[curse] == G.supplyCount[curse])
        {
            printf("PASSED. Cursed cards have not been changed.\n");
        }
        else
        {
            printf("FAILED. Cursed cards have been changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[curse], G.supplyCount[curse]);
        }

        if(test.supplyCount[estate] == G.supplyCount[estate])
            {printf("PASSED. Estate cards have not been changed\n");}
        else
        {
             printf("FAILED. Estate cards have been changed.\n");
             printf("    Card count: %d   Expected card count: %d\n", test.supplyCount[estate], G.supplyCount[estate]);
        }

        if(test.supplyCount[duchy] == G.supplyCount[duchy])
            {printf("PASSED. Duchy cards have not changed\n");}
        else
        {  
            printf("FAILED. Duchy cards have changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[duchy], G.supplyCount[duchy]);
        }

        if(test.supplyCount[province] == G.supplyCount[province])
            {printf("PASSED. Province cards have not changed.\n");}
        else
        {
            printf("FAILED. Province cards have changed.\n");
            printf("   Card amount: %d   Expected card amount: %d\n", test.supplyCount[province], G.supplyCount[province]);
        }

        //test that the supply cards are the same
        if(test.supplyCount[copper] == G.supplyCount[copper])
            {printf("PASSED. Copper cards have not changed.\n");}
        else
        {
            printf("FAILED. Copper cards have changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[copper], G.supplyCount[copper]);
        }

        if(test.supplyCount[silver] == G.supplyCount[silver])
            {printf("PASSED. Silver cards have not changed.\n");}
        else
        {
            printf("FAILED. Silver cards have changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[silver], G.supplyCount[silver]);
        }

        if(test.supplyCount[gold] == G.supplyCount[gold])
            {printf("PASSED. Gold cards have not changed.\n");}
        else
        {
            printf("FAILED. Gold cards have changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[gold], G.supplyCount[gold]);
        }
    }

return 0;
}