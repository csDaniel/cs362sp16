#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "test_helpers_unit.h"
#include <assert.h>


/************************
 * Testing adventurer card
 ***********************/

void adventurerTest(){
	struct gameState game, compareGame, startState, compareStartState;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int zz;
	//int k[10] = {copper, silver, gold, copper, silver, gold, copper, silver, gold, gold};

	printf("Testing adventurer.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 900;

	int problems = 0;

	initializeGame(numberOfPlayers, k, randomSeed, &game);

	for(zz = 0; zz < game.deckCount[1]; zz++){
		if(game.deck[1][zz] < 7)
			game.deck[1][zz] = 7;
	}

	for(zz = 0; zz < game.discardCount[1]; zz++){
		if(game.discard[1][zz] < 7)
			game.discard[1][zz] = 7;
	}

	memcpy(&compareGame, &game, sizeof(struct gameState));
	memcpy(&startState, &game, sizeof(struct gameState));
	memcpy(&compareStartState, &compareGame, sizeof(struct gameState));

	game.handCount[1] = 5;
	game.hand[1][0] = adventurer;
	game.hand[1][1] = copper;
	game.hand[1][2] = copper;
	game.hand[1][3] = copper;
	game.hand[1][4] = copper;

	compareGame.handCount[1] = 5;
	compareGame.hand[1][0] = adventurer;
	compareGame.hand[1][1] = copper;
	compareGame.hand[1][2] = copper;
	compareGame.hand[1][3] = copper;
	compareGame.hand[1][4] = copper;

	printf("\n\n\Before:\n\n");	
	printResults(&game, &compareGame);


	adventurerCard(1, &game);

	//compareGame
	int revealed[MAX_DECK];
	int revealedCounter = 0;
	int treasureFound = 0;
	//int i = 0;
	int shuffleCount = 0;
	//int cardDrawn;
	
	int i, handPos;
	int z = 0;
	int cardDrawn;
	int drawntreasure = 0;
	int temphand[MAX_HAND];
	int noTreasure = 0;
	
	for(i = 0; i < compareGame.handCount[1]; i++)
		if(compareGame.hand[1][i] == adventurer)
			handPos = i;

	while(drawntreasure < 2 && noTreasure < 2){
		//if the deck is empty we need to shuffle discard and add to deck
		if (compareGame.deckCount[1] == 0){
			if(noTreasure < 1) 
				if(shuffle(1, &compareGame) == -1)
					noTreasure = 2;
		}
		
		if(noTreasure < 2){	
			drawCard(1, &compareGame);
			//top card of hand is most recently drawn card.
			cardDrawn = compareGame.hand[1][compareGame.handCount[1]-1];
			if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				drawntreasure++;
			else{
				temphand[z]=cardDrawn;
				//this should just remove the top card (the most recently drawn one).
				compareGame.handCount[1]--; 
				z++;
			}
		}
	}

	while(z-1>=0){
		//discard all cards in play that have been drawn
		compareGame.discard[1][compareGame.discardCount[1]++]=temphand[z-1]; 
		z=z-1;
	}

	discardCard(handPos, 1, &compareGame, 0);

	printf("\n\n\nAfter:\n\n");
	printResults(&game, &compareGame);

	printf("\n\n\n\n\n");	

	initializeGame(numberOfPlayers, k, randomSeed, &game);
	memcpy(&compareGame, &game, sizeof(struct gameState));
	memcpy(&startState, &game, sizeof(struct gameState));
	memcpy(&compareStartState, &compareGame, sizeof(struct gameState));

	game.handCount[1] = 5;
	game.hand[1][0] = adventurer;
	game.hand[1][1] = copper;
	game.hand[1][2] = copper;
	game.hand[1][3] = copper;
	game.hand[1][4] = copper;

	compareGame.handCount[1] = 5;
	compareGame.hand[1][0] = adventurer;
	compareGame.hand[1][1] = copper;
	compareGame.hand[1][2] = copper;
	compareGame.hand[1][3] = copper;
	compareGame.hand[1][4] = copper;

	for(int z = 0; z < game.deckCount[1]; z++){
		game.discard[1][game.discardCount[1]] = game.deck[1][z];
		game.discardCount[1]++;
		compareGame.discard[1][compareGame.discardCount[1]] = compareGame.deck[1][z];
		compareGame.discardCount[1]++;

	}	

	printf("\n\n\nBefore:\n\n");
	printResults(&game, &compareGame);

	adventurerCard(1, &game);

	//compareGame

	while(treasureFound < 2 && shuffleCount < 2){
		if(compareGame.deckCount[1] == 0){
			if(shuffleCount < 1) 
				if(shuffle(1, &compareGame) == -1)
					shuffleCount = 2;
			
		}
		if(shuffleCount < 2){
			drawCard(1, &compareGame);
		   	cardDrawn = compareGame.hand[1][compareGame.handCount[1]-1];	
			if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
				treasureFound++;
			} else {
				revealed[revealedCounter] = cardDrawn;
				revealedCounter++;
				compareGame.handCount[1]--;
			}
		}
		if(shuffleCount > 2){
			printf("Too few treasure cards.\n");
			break;
		}
	}

	discardCard(0, 1, &compareGame, 0);

	for(int z = 0; z < revealedCounter; z++){
		compareGame.discard[1][compareGame.discardCount[1]] = revealed[z];
		compareGame.discardCount[1]++;
	}
	revealedCounter = 0;

	printf("\n\n\nAfter:\n\n");
	printResults(&game, &compareGame);


	printf("\n\n\n\n\n");	

	initializeGame(numberOfPlayers, k, randomSeed, &game);
	memcpy(&compareGame, &game, sizeof(struct gameState));
	memcpy(&startState, &game, sizeof(struct gameState));
	memcpy(&compareStartState, &compareGame, sizeof(struct gameState));

	game.handCount[1] = 5;
	game.hand[1][0] = adventurer;
	game.hand[1][1] = copper;
	game.hand[1][2] = copper;
	game.hand[1][3] = copper;
	game.hand[1][4] = copper;

	compareGame.handCount[1] = 5;
	compareGame.hand[1][0] = adventurer;
	compareGame.hand[1][1] = copper;
	compareGame.hand[1][2] = copper;
	compareGame.hand[1][3] = copper;
	compareGame.hand[1][4] = copper;

	for(int z = 0; z < game.deckCount[1]; z++){
		game.discard[1][game.discardCount[1]] = game.deck[1][z];
		game.discardCount[1]++;
		compareGame.discard[1][compareGame.discardCount[1]] = compareGame.deck[1][z];
		compareGame.discardCount[1]++;

	}	

	game.deckCount[1] = 0;
	compareGame.deckCount[1] = 0;

	printf("\n\n\nBefore:\n\n");
	printResults(&game, &compareGame);

	adventurerCard(1, &game);

	//compareGame
	treasureFound = 0;
	shuffleCount = 0;

	while(treasureFound < 2 && shuffleCount < 2){
		if(compareGame.deckCount[1] == 0){
			if(shuffleCount < 1) 
				if(shuffle(1, &compareGame) == -1)
					shuffleCount = 2;
			
		}
		if(shuffleCount < 2){
			drawCard(1, &compareGame);
		   	cardDrawn = compareGame.hand[1][compareGame.handCount[1]-1];	
			if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
				treasureFound++;
			} else {
				revealed[revealedCounter] = cardDrawn;
				revealedCounter++;
				compareGame.handCount[1]--;
			}
		}
		if(shuffleCount > 2){
			printf("Too few treasure cards.\n");
			break;
		}
	}

	discardCard(0, 1, &compareGame, 0);

	for(int z = 0; z < revealedCounter; z++){
		compareGame.discard[1][compareGame.discardCount[1]] = revealed[z];
		compareGame.discardCount[1]++;
	}

	printf("\n\n\nAfter:\n\n");
	printResults(&game, &compareGame);


	printf("+++++ Testing game vs compare state for player 2. +++++\n");

	printf("\n\nNumber of operations where problems were found: %i\n\n", problems);

	printf("<--- adventurer Testing Completed successfully --->\n\n");
}

int main(){

	adventurerTest();
	return 0;

}
