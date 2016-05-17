#include "interface.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion_helpers.h"
#include <string.h>

#define TRIALS 1000
//initKingdomCards generates an array of 10 kingdom cards within the
//range of 7-26 with no repeating integers. RNG must be initialized.
void initKingdomCards(int*);
//construct gamestate initializes a random game within constraints on
//kingdom cards in play. One kingdom card will always be an adventurer.
void constructGamestate(struct gameState*,int*);
//compares two integer arrays of various sizes (checks hands unchanged)
//mainly used to determine whether hand state has changed. 1 is identical,
//0 is false (different arrays)
int compareArray(int *, int *, int, int);
//calculates number of treasure cards in hand, indifferent to the value
int numTreasureCardsHand(struct gameState*, int);
int numTreasureCardsDeck(struct gameState*, int);
int numTreasureCardsDiscard(struct gameState*, int);
int numTotalTreasure(struct gameState*, int);
//turns RNG into a viable card in current game
int assignCard(int,int*);
//prints a sized array by card name. First arg array, second size
void printArrayString(int *, int);
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
void printNewState(struct gameState*,int*);
void runAdventurerTest(struct gameState*,int*);
int getHandPos(struct gameState*, int, int);
int otherPlayerCounts(struct gameState*, struct gameState*,int);
void deckCurses(struct gameState*,int);

void constructGamestate(struct gameState * state, int * kingCards){
	int numVCards, numCCards, i, j, tempVal, player;
	int hasAdventurer = 0;
	int treasureQuant = NUM_COPPER;
	//randomly determine number of players on interval 2-4
	state->numPlayers = (int)(Random()*2+2);
	//set constants based on number of players
	if (state->numPlayers == 2){
		numVCards = NUM_V_CARDS_2;
		numCCards = NUM_C_CARDS_2;
	}
	else {
		numVCards = NUM_V_CARDS_3or4;
		if (state->numPlayers == 3){
			numCCards = NUM_C_CARDS_3;
		}
		else numCCards = NUM_C_CARDS_4;
	}
	//randomize kingdom card supplies
	for (i=0;i<10;i++){
		//if kingdom card has victory value
		if (kingCards[i] == great_hall || kingCards[i] == gardens){
			//must be bounded by the number of victory cards per player
			state->supplyCount[(kingCards[i])] = (int)(Random()*numVCards);
		}
		//else bounded by 10
		else state->supplyCount[(kingCards[i])] = (int)(Random()*NUM_K_CARDS);
	}
	//randomize treasure card supplies
	for (i=copper;i<=gold;i++){
		if (i==silver) treasureQuant = NUM_SILVER;
		if (i==gold) treasureQuant = NUM_GOLD;
		state->supplyCount[i] = (int)(Random()*treasureQuant);
	}
	//randomize kingdom card supplies
	for (i=curse;i<=province;i++){
		state->supplyCount[i] = (int)(Random()*numVCards);
	}
	//randomize number of curse cards
	state->supplyCount[curse] = Random()*numCCards;
	//generate deck size, hand size, discard size for players
	for (i=0;i<state->numPlayers;i++){
		do
		{
			state->deckCount[i] = (int)(Random()*(MAX_DECK-1));
		} while (state->deckCount[i]<=0 || state->deckCount[i]>MAX_DECK);
		do
		{
			state->handCount[i] = (int)(Random()*(MAX_DECK - state->deckCount[i]));
		} while (state->handCount[i]<=0 || state->handCount[i] >MAX_DECK);
		if (state->handCount[i] == 0) state->handCount[i] == 1;//there must be at least an adventurer in hand
		if ((state->handCount[i] + state->deckCount[i])>=(MAX_DECK-1)) state->discardCount[i] = 0;
		else
		{
			do
			{
				state->discardCount[i] = (int)(Random()*(MAX_DECK - state->deckCount[i] - state->handCount[i]));
			} while (state->discardCount[i]<=0 || state->discardCount[i] > MAX_DECK);
		}
	}
	//populate with cards. 0-9 kingdom cards, 10-12 treasure, 13 curse, 14-16 victory cards
	for (i=0;i<state->numPlayers;i++){
		//start with hand
		for (j=0;j<state->handCount[i];j++){
			//loop assures bounded value of random integer
			do{
				tempVal = (int)(Random()*16);
			} while (tempVal < 0 || tempVal > 16);
			state->hand[i][j] = assignCard(tempVal,kingCards);
			if (state->hand[i][j] == adventurer) {
				hasAdventurer = 1;
			}
		}
		for (j=0; j<state->deckCount[i];j++){
			//loop assures bounded value of random integer
			do{
				tempVal = (int)(Random()*16);
			} while (tempVal < 0 || tempVal > 16);
			state->deck[i][j] = assignCard(tempVal,kingCards);
		}
		//if no adventurer in hand, insert one randomly
		if (state->handCount[i] == 1){
			state->hand[i][0] = adventurer;
		}
		else {
			do{
				tempVal = (int)(Random()*(state->handCount[i] - 1));
			} while (tempVal < 0 || tempVal >= (state->handCount[i]));
			state->hand[i][tempVal] = adventurer;
		}
		for (j=0; j<state->discardCount[i];j++){
			//loop assures bounded value of random integer
			do{
				tempVal = (int)(Random()*16);
			} while (tempVal < 0 || tempVal > 16);
			state->discard[i][j] = assignCard(tempVal,kingCards);
		}
	}
	//all hands and decks are generated. Randomly determine player.
	state->whoseTurn = (int)(Random()*(state->numPlayers-1));
	player = state->whoseTurn;
	//give the player between one and ten actions
	state->numActions = (int)(Random()*9+1);
	//gives the player betwen one and ten buys
	state->numBuys = (int)(Random()*9+1);
	//set played card count to a random number between 0 and total cards possibly remaining for player taking turn
	state->playedCardCount = (int)(Random()*(MAX_DECK-state->deckCount[player]-state->handCount[player]-state->discardCount[player]));
	//fill played cards with kingdom cards
	for (i=0;i<state->playedCardCount;i++){
		do{
			tempVal = (int)(Random()*9);
		} while (tempVal < 0 || tempVal > 9);
		state->playedCards[i] = assignCard(tempVal,kingCards);
	}
	//set phase to 0
	state->phase = 0;
}

//return card. 0-9 kingdom cards, 10-12 treasure, 13 curse, 14-16 victory cards
int assignCard(int value, int * kingCards){
	if (value < 10) return kingCards[value];
	else{
		switch (value){
			case 10:
				return copper;
			case 11:
				return silver;
			case 12:
				return gold;
			case 13:
				return curse;
			case 14:
				return estate;
			case 15:
				return duchy;
			case 16:
				return province;
			default:
				printf("ERROR: assignCard out of bounds.\n\n");
		}
	}
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    /* create temp arrays */
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){
    if (l < r){
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

//array sizes must be correct or this will cause a fault. If shuffling
//is possible, then a sort must be done.
int compareArray(int * array1, int * array2, int size1, int size2){
	//if sizes are different arrays cannot be the same
	int i;
	int * sortArray1;
	int * sortArray2;
	if (size1 != size2) return 0;
	else {
		//make copies of arrays
		sortArray1 = (int*)malloc(sizeof(int)*size1);
		sortArray2 = (int*)malloc(sizeof(int)*size2);
		memcpy(sortArray1,array1,sizeof(int)*size1);
		memcpy(sortArray2,array2,sizeof(int)*size2);
		//sort both arrays as preprocessor to comparison
		mergeSort(sortArray1,0,size1-1);
		mergeSort(sortArray2,0,size2-1);
		for(i=0;i<size1;i++){
			if (sortArray1[i] != sortArray2[i]){
				free(sortArray1);
				free(sortArray2);
				return 0;
			}
		}
	}
	printArrayString(sortArray1,size1);
	printArrayString(sortArray2,size2);
	free(sortArray1);
	free(sortArray2);
	return 1;
}

int numTreasureCardsHand(struct gameState * state, int player){
	int i;
	int count = 0;
	if (player < 0 || player > 3) printf("ERROR! Player hand for count treasure out of bounds.\n");
	else {
		for (i=0;i<state->handCount[player];i++){
			//if card falls in the range of treasure card
			if (state->hand[player][i] > province && state->hand[player][i] < adventurer){
				++count;
			}
		}
	}
	return count;
}

int numTreasureCardsDeck(struct gameState * state, int player){
	int i;
	int count = 0;
	if (player < 0 || player > 3) printf("ERROR! Player hand for count treasure out of bounds.\n");
	else {
		for (i=0;i<state->deckCount[player];i++){
			//if card falls in the range of treasure card
			if (state->deck[player][i] > province && state->deck[player][i] < adventurer){
				++count;
			}
		}
	}
	return count;
}

int numTreasureCardsDiscard(struct gameState * state, int player){
	int i;
	int count = 0;
	if (player < 0 || player > 3) printf("ERROR! Player hand for count treasure out of bounds.\n");
	else {
		for (i=0;i<state->discardCount[player];i++){
			//if card falls in the range of treasure card
			if (state->discard[player][i] > province && state->discard[player][i] < adventurer){
				++count;
			}
		}
	}
	return count;
}

int numTotalTreasure(struct gameState * state, int player){
	return (numTreasureCardsHand(state,player) + numTreasureCardsDeck(state,player) + numTreasureCardsDiscard(state,player));
}

void initKingdomCards(int * kingArray){
	int i, j, randomTemp, redo, adventurerIndex;
	for(i=0;i<10;i++){
		do {
			randomTemp = (int)(Random()*19)+7;
			redo = 0;
			for (j=0;j<i;j++){
				//we dont want repeats or an adventurer (one will be added manually)
				if (kingArray[j]==randomTemp || randomTemp == adventurer){
					redo = 1;
				}
			}
			kingArray[i] = randomTemp;
		} while (redo);
	}
	//randomly add adventurer to a random index in kingdom array
	adventurerIndex = (int)(Random()*9);
	kingArray[adventurerIndex] = adventurer;
}

void printArrayString(int * array, int size){
	char cardName[15];
	int i;
	for (i=0;i<size;i++){
		memset(cardName,0,15*sizeof(char));
		cardNumToName(array[i],cardName);
		printf("%s ",cardName);
	}
	printf("\n");
}

void printNewState(struct gameState * state, int * kingCards){
	int i;

	//print kingdom cards in play
	printf("Kingdom cards in play:\n");
	for (i=0;i<10;i++){

	}
	//print values for all players
	for (i=0;i<state->numPlayers;i++){
		printf("##Player %d ===================\n",(i+1));
		printf("-------Hand:\n");
		printArrayString(state->hand[i],state->handCount[i]);
		printf("-------Deck:\n");
		printArrayString(state->deck[i],state->deckCount[i]);
		printf("-------Discard:\n");
		printArrayString(state->hand[i],state->handCount[i]);
		printf("\n\n");
	}
}

//returns first incidence of a card by index of enum int card in player player's hand
int getHandPos(struct gameState* state, int player, int card){
	int i;
	if (player < 0 || player > 3) return -1;//error condition
	for (i=0;i<state->handCount[player];i++){
		if (state->hand[player][i] == card) return i;
	}
	return -1;
}

//compare counts returns all counts except those for player
int otherPlayerCounts(struct gameState* state, struct gameState* init, int player){
	int i;
	for (i=0;i<state->numPlayers;i++){
		if (i!=player){
			if (state->handCount[i] != init->handCount[i] ||
				state->deckCount[i] != init->deckCount[i] ||
				state->discardCount[i] != init->discardCount[i])
			{
				return 0;
			}
		}
	}
	return 1;
}

//checks all stocks for parity between states
int checkStocks(struct gameState* state, struct gameState * init){
	int i;
	for (i=0;i<treasure_map+1;i++){
		if (state->supplyCount[i] != init->supplyCount[i])
		{
			return 0;
		}
	}
	return 1;
}

void runAdventurerTest(struct gameState * state, int * kingCards){
	int i, handPos, handSize, pullTreasure, playedCardExpected, totalCards, postTotal;
	int treasureCheck = 0;
	int foundTreasure = 0;
	int discarded = 0;
	int numOffDeck = 0;
	int player = state->whoseTurn;
	int index = state->deckCount[player]-1;
	char success[] = "SUCCESS: ";
	char failure[] = "#####FAILED: ";
	struct gameState init;
	memcpy(&init,state,sizeof(struct gameState));
	if ((handPos = getHandPos(state,player,adventurer))<0) {
		printf("Error: Invalid player or no adventurer in current player hand\n\n");
	}
	//check if there is more than two treasures between the deck and discard
	pullTreasure = numTreasureCardsDeck(state,player) + numTreasureCardsDiscard(state,player);
	if (pullTreasure > 2) pullTreasure = 2;
	//adjust index to reflect number of treasures acquired
	index += pullTreasure-1;
	//hand size increased by pullable treasure size
	handSize = pullTreasure + init.handCount[player] -1;
	//played cards should increase by 1
	playedCardExpected = init.playedCardCount + 1;
	//total cards conserved
	totalCards = init.deckCount[player] + init.discardCount[player] + init.playedCardCount + init.handCount[player];
	//play card
	playCard(handPos,0,0,0,state);
	//test for hand size
	if (state->handCount[player] == handSize) printf("%s: ",success);
	else printf("%s: ",failure);
	printf("Expected hand size: %d, actual: %d\n",handSize,state->handCount[player]);
	//test played card adjustment
	if (state->playedCardCount == playedCardExpected) printf("%s: ",success);
	else printf("%s: ",failure);
	printf("Played card count expected: %d, Actual: %d.\n",playedCardExpected,state->playedCardCount);
	//total cards expected
	postTotal = state->deckCount[player] + state->discardCount[player] + state->playedCardCount + state->handCount[player];
	if (postTotal == totalCards) printf("%s: ",success);
	else printf("%s: ",failure);
	printf("Total card count expected: %d, Actual: %d.\n",totalCards,postTotal);
	//supply consistency check
	if (checkStocks(state,&init)) printf("%s: ",success);
	else printf("%s: ",failure);
	printf("Supply pile check.\n");
	//other player consistency check
	if (otherPlayerCounts(state,&init,player)) printf("%s: ",success);
	else printf("%s: ",failure);
	printf("Other player card counts check.\n\n");

}

void deckCurses(struct gameState * state, int treasure){
	int i,j, tempIndex;
	for (i=0;i<state->numPlayers;i++){
		for (j=0;j<state->deckCount[i];j++){
			state->deck[i][j]=curse;
		}
		for (j=0;j<state->discardCount[i];j++){
			state->discard[i][j]=curse;
		}
		//insert one treasure into deck
		if (treasure == 1){
			for (i=0;i<state->numPlayers;i++){
				do{
					tempIndex = (int)(Random()*(state->deckCount[i]-1));
				} while (tempIndex < 0 || tempIndex >= state->deckCount[i]);
				state->deck[i][tempIndex];
			}
		}
		//insert one treasure into discard
		if (treasure == 2){
			for (i=0;i<state->numPlayers;i++){
				do{
					tempIndex = (int)(Random()*(state->discardCount[i]-1));
				} while (tempIndex < 0 || tempIndex >= state->discardCount[i]);
				state->deck[i][tempIndex];
			}
		}
	}
}

int main(int argc, char** argv){

	struct gameState* state = malloc(sizeof(struct gameState));
	int kingArray[10];
	int i;
	SelectStream(0);
	PutSeed(-1);
	printf("=====ADVENTURER TRIALS=====\v");
	for (i=0;i<TRIALS;i++){
		memset(kingArray,0,sizeof(kingArray));
		memset(state,0,sizeof(struct gameState));
		initKingdomCards(kingArray);
		constructGamestate(state,kingArray);
		//forces a no-treasure in deck trial
		if (i==TRIALS-1){
			deckCurses(state,0);
			runAdventurerTest(state,kingArray);
		}
		else if (i==TRIALS-2){
			deckCurses(state,1);
			runAdventurerTest(state,kingArray);
		}
		else if (i==TRIALS-3){
			deckCurses(state,2);
			runAdventurerTest(state,kingArray);
		}
		else runAdventurerTest(state,kingArray);
	}
	return 0;
}