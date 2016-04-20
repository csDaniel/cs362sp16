/*
	Rosa Tung
	CS362
	(20 points) Write unit tests for four Dominion cards implemented in dominion.c.  
	These tests should be checked in as cardtest1.c, cardtest2.c,cardtest3.c, and cardtest4.c. 
	(For example, create a test for smithy card.). It is mandatory to test smithy and adventurer card. 
	
	Testing:
		smithy card - bug found line 57
		int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
*/

#include "dominion.h" 

#include <stdio.h> //printf scanf

int main(){
	//make new game 
	struct gameState G;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int kingdomCardsCheck[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int flag; //return state 
	
	int currentPlayer;
	int baseHandCount;
	int baseDeckCount;
	
	int victoryCheck;
	int kingdomCheck;
	
	printf("---Testing Smithy Card START---\n\n");
	
	printf("Initialize Game...\n");
	initializeGame(2, k, 4, &G);
	
	currentPlayer = G.whoseTurn;
	baseHandCount = G.handCount[currentPlayer];
	baseDeckCount = G.deckCount[currentPlayer];
	victoryCheck = G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province];
	
	//check for function execution
	printf("Testing smithy cardEffect function return value...\n");
	flag = cardEffect(smithy, 0, 0, 0, &G, 0, 0);
	if(flag == -1){
		printf("	PASS\n");
	} else {
		printf("	FAIL\n");
	}
	//check smithy effect correctness
	printf("Testing smithy action...\n");
	//check number of cards received from currentPlayer
	if(G.handCount[currentPlayer] == baseHandCount + 2){ //draw 3 cards but put one back
		printf("	PASS\n"); 
		printf("		Smithy gave 3 cards\n");
		printf("		current handCount: %d, previous handCount: %d\n", G.handCount[currentPlayer], baseHandCount);

	} else {
		printf("	FAIL\n");
		printf("		Smithy did not give 3 cards\n");
		printf("		current handCount: %d, previous handCount: %d\n", G.handCount[currentPlayer], baseHandCount);
	}
	//check number of cards given from players deck 
	if(G.deckCount[currentPlayer] == baseDeckCount - 2){ //give 3 cards but take one in 
		printf("	PASS\n"); 
		printf("		3 cards taken from currentPlayers Deck\n\n");
		printf("		current deckCount: %d, previous deckCount: %d\n", G.deckCount[currentPlayer], baseDeckCount);		
	} else {
		printf("	FAIL\n");
		printf("		3 cards not taken from currentPlayers Deck\n");
		printf("		current deckCount: %d, previous deckCount: %d\n", G.deckCount[currentPlayer], baseDeckCount);
	}
	//check other player state change 
	if(G.handCount[currentPlayer+1] == 0){
		printf("	PASS\n");
		printf("		Other player's handCount has not changed\n");
	} else {
		printf("	FAIL\n");
		printf("		Other player's handCount has changed\n");
	}
	if(G.deckCount[currentPlayer+1] == 10){
		printf("	PASS\n");
		printf("		Other player's deckCount has not changed\n");
	} else {
		printf("	FAIL\n");
		printf("		Other player's deckCount has changed\n");
	}
	//victory card pile check
	if((G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province]) == victoryCheck){
		printf("	PASS\n");
		printf("		no state change to victory card piles\n");
	} else {
		printf("	FAIL\n");
		printf("		there has been a state change to the victory card piles\n");
	}
	
	//kingdom card pile check 
	flag = 0; //reset flag
	for(kingdomCheck = 0; kingdomCheck < 10; kingdomCheck++){
		if(k[kingdomCheck] != kingdomCardsCheck[kingdomCheck]){
			flag = 1;
		}
	}
	if(flag == 0){
		printf("	PASS\n");
		printf("		no state change to kingdom card piles\n\n");
	} else {
		printf("	FAIL\n");
		printf("		there has been a state change to the kingdom card piles\n\n");
	}
	
	printf("---Testing Smithy Card COMPLETE---\n\n\n\n");
	return 0;
}






