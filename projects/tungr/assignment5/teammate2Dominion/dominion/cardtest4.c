/*
	Rosa Tung
	CS362
	(20 points) Write unit tests for four Dominion cards implemented in dominion.c.  
	These tests should be checked in as cardtest1.c, cardtest2.c,cardtest3.c, and cardtest4.c. 
	(For example, create a test for smithy card.). It is mandatory to test smithy and adventurer card. 
	
	Testing:
		gardens card 
		int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);	
*/

#include "dominion.h" 

#include <stdio.h> //printf scanf

int main(){
	//make new game 
	struct gameState G;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int kingdomCardsCheck[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	int flag;
	int currentPlayer; 
	int baseHandCount;
	int baseDeckCount;	
	int baseActions;
	
	int victoryCheck;
	int kingdomCheck;
	
	printf("---Testing gardens Card START---\n\n");
	
	printf("Initialize Game...\n");
	initializeGame(2, k, 4, &G);	
	
	currentPlayer = G.whoseTurn;
	baseHandCount = G.handCount[currentPlayer];
	baseDeckCount = G.deckCount[currentPlayer];
	baseActions = G.numActions;
	victoryCheck = G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province];
	
	//check for function execution
	printf("Testing gardens cardEffect function return value...\n");
	flag = cardEffect(gardens, 0, 0, 0, &G, 0, 0);
	if(flag == -1){
		printf("	PASS\n");
	} else {
		printf("	FAIL\n");
	}	
	//check adventurer effect correctness
	printf("Testing gardens action...\n");
	
	//check number of cards received from currentPlayer
	if(G.handCount[currentPlayer] == baseHandCount){ //take 1 card and give 1 away
		printf("	PASS\n"); 
		printf("		No change in player hand count\n");
		printf("		current handCount: %d, previous handCount: %d\n", G.handCount[currentPlayer], baseHandCount);

	} else {
		printf("	FAIL\n");
		printf("		There was a change in player hand count\n");
		printf("		current handCount: %d, previous handCount: %d\n", G.handCount[currentPlayer], baseHandCount);
	}
	
	//check number of cards given from players deck 
	if(G.deckCount[currentPlayer] == baseDeckCount){ //take 1 card
		printf("	PASS\n"); 
		printf("		No change in currentPlayers Deck\n");
		printf("		current deckCount: %d, previous deckCount: %d\n", G.deckCount[currentPlayer], baseDeckCount);		
	} else {
		printf("	FAIL\n");
		printf("		There was a change in currentPlayers DeckCount\n");
		printf("		current deckCount: %d, previous deckCount: %d\n", G.deckCount[currentPlayer], baseDeckCount);
		printf("		cards in discard pile: %d\n", G.discardCount[currentPlayer]);
	}
	
	//check action count 
	if(G.numActions == baseActions){
		printf("	PASS\n"); 
		printf("		Actions unchanged\n");
		printf("		current actions: %d, previous actions: %d\n", G.numActions, baseActions);			
	} else {
		printf("	FAIL\n");
		printf("		Actions changed\n");
		printf("		current actions: %d, previous actions: %d\n", G.numActions, baseActions);
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
	printf("---Testing gardens Card COMPLETE---\n\n\n\n");
	return 0;
}