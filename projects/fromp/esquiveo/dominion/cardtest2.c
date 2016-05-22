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

	//int k[10] = {copper, silver, gold, copper, silver, gold, copper, silver, gold, gold};

	printf("Testing adventurer.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 900;

	struct compareReturn compres; 
	int problems = 0;
	int temphand[100];

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

	//adventurerCard(1, &game);
	adventurerPlay(0, &game, 1, 0, temphand, 0) ;
	//compareGame
	int revealed[MAX_DECK];
	int revealedCounter = 0;
	int treasureFound = 0;
	int i = 0;
	int shuffleCount = 0;
	int cardDrawn;
	while(treasureFound < 2){
		if(i >= compareGame.deckCount[1]){
			shuffle(1, &compareGame);
			i = 0;
			shuffleCount++;
		}
		drawCard(1, &compareGame);
		cardDrawn = compareGame.hand[1][compareGame.handCount[1]-1];	
		if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
			treasureFound++;
		} else {
			revealed[revealedCounter] = cardDrawn;
			revealedCounter++;
			compareGame.handCount[1]--;
		}
		if(shuffleCount > 2){
			printf("Too few treasure cards.\n");
			break;
		}
		i++;

	}

	for(int z = 0; z < revealedCounter; z++){
		compareGame.discard[1][compareGame.discardCount[1]] = revealed[z];
		compareGame.discardCount[1]++;
	}
	discardCard(0, 1, &compareGame, 0);
	revealedCounter = 0;



	printf("+++++ Testing game vs compare state for player 2. +++++\n");
	compres = compareGameStates(&game, &compareGame, 1);
	if(printCompareResults(compres)) printf("Player 2: Added cards to game state okay.\n");
	else{
	   	printResults(&game, &compareGame);
		problems++;
	}
	compres = compareGameStates(&game, &compareGame, 0);
	if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
	else {
		printResults(&game, &compareGame);
		problems++;
	}
	compres = compareGameStates(&game, &startState, 0);
	if(printCompareResults(compres)) printf("Game and start state unchanged (for player 1) as expected.\n");
	else{
		printResults(&game, &startState);
		problems++;
	}
	compres = compareGameStates(&compareGame, &compareStartState, 0);
	if(printCompareResults(compres)) printf("Compare and start state unchanged (for player 1) as expected.\n");
	else{
		printResults(&compareGame, &compareStartState);
		problems++;
	}

	
	printf("\n\nNumber of operations where problems were found: %i\n\n", problems);

	printf("<--- adventurer Testing Completed successfully --->\n\n");
}

int main(){

	adventurerTest();
	return 0;

}
