#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <time.h>
#include <math.h>

#define DEBUGADVENTURER 0
/************************
 * Testing smithy card
 ***********************/

struct compareReturn{
	int handCount;
	int hand;
	int deckCount;
	int deck;	
	int discardCount;
	int discard;
	int playedCardCount;	
	int playedCards;
	int coins;
	int actions;	
	int playerCount;	
	int buys;
	int supply;
	int supplyCount;
	int returnResults;
};  


void setupSupply(struct gameState * state, int numPlayers, int *kingdomCards){
	int i, j;
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
		  			if (numPlayers == 2)
					{ 
		    			state->supplyCount[i] = 8; 
					}
					else
					{ 
						state->supplyCount[i] = 12; 
					}
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
}

int checkStates(struct gameState *game, struct gameState *compareGame, struct compareReturn *compRes, int result){
	int problems = 0;
	int i, playerNum, j, counter;

	//See what the result of the smithy function call was
	compRes->returnResults = result;

	//If not 0, we have a problem.
	if(result != 0){
		problems++;
	}

	//Assuming player numbers are the same for both states...
	playerNum = compareGame->numPlayers;
	//But check in case they're not...
	if(game->numPlayers != compareGame->numPlayers){
		compRes->playerCount++;
		//And set playerNum equal to the smaller
		if(game->numPlayers < compareGame->numPlayers)
			playerNum = game->numPlayers;
		//Also, Houston, we have a problem!
		problems++;
	}

	//Look at the hand counts for each player in both states.
	for(i = 0; i < playerNum; i++){
		//If we have a problem, let us know.
		if(game->handCount[i] != compareGame->handCount[i]){
			compRes->handCount++;
			problems++;

		}
	}

	//Now, let's look at the cards in eaan player's hand!
	for(i = 0; i < playerNum; i++){
		//Assuming hand count is the same...
		counter = compareGame->handCount[i];
		//But in case it's not, set it to whichever is smaller.
		if(compRes->handCount && game->handCount[i] < compareGame->handCount[i]){
				counter = game->handCount[i];
		}
		//Check each card in each player hand in both states.
		for(j = 0; j < counter; j++){
			if(game->hand[i][j] != compareGame->hand[i][j]){
				compRes->hand++;
			}
		}
		if(compRes->hand) problems++;
	}

	//Look at the deck counts for each player in both states.
	for(i = 0; i < playerNum; i++){
		//If we have a problem, let us know.
		if(game->deckCount[i] != compareGame->deckCount[i]){
			compRes->deckCount++;
			problems++;
		}
	}

	//Now, let's look at the cards in each player's deck!
	for(i = 0; i < playerNum; i++){
		//Assuming hand count is the same...
		counter = compareGame->deckCount[i];
		//But in case it's not, set it to whichever is smaller.
		if(compRes->deckCount && game->deckCount[i] < compareGame->deckCount[i]){
				counter = game->deckCount[i];
		}
		//Check each card in each player hand in both states.
		for(j = 0; j < counter; j++){
			if(game->deck[i][j] != compareGame->deck[i][j]){
				compRes->deck++;
			}
		}
		if(compRes->deck) problems++;
	}

	//Look at the discard counts for each player in both states.
	for(i = 0; i < playerNum; i++){
		//If we have a problem, let us know.
		if(game->discardCount[i] != compareGame->discardCount[i]){
			compRes->discardCount++;
			problems++;

		}
	}

	//Now, let's look at the cards in eaan player's discard!
	for(i = 0; i < playerNum; i++){
		//Assuming hand count is the same...
		counter = compareGame->discardCount[i];
		//But in case it's not, set it to whichever is smaller.
		if(compRes->discardCount && game->discardCount[i] < compareGame->discardCount[i]){
				counter = game->discardCount[i];
		}
		//Check each card in each player hand in both states.
		for(j = 0; j < counter; j++){
			if(game->discard[i][j] != compareGame->discard[i][j]){
				compRes->discard++;
			}
		}
		if(compRes->discard) problems++;
	}

	for(i = 0; i < playerNum; i++){
		if(game->numBuys != compareGame->numBuys){
			compRes->buys++;
			problems++;
		}
	}

	for(i = 0; i < playerNum; i++){
		if(game->numActions != compareGame->numActions){
			compRes->actions++;
			problems++;
		}
	}

	if(game->coins != compareGame->coins){
		compRes->coins++;
		problems++;
	}

	if(game->supplyCount[i] != compareGame->supplyCount[i]){
		compRes->supplyCount++;
		problems++;
	}

	//Assuming hand count is the same...
	counter = compareGame->playedCardCount;
	if(game->playedCardCount != compareGame->playedCardCount){
		problems++;
		compRes->playedCardCount++;
		compRes->playedCards++;
	}
	//But in case it's not, set it to whichever is smaller.
	if(compRes->playedCardCount && game->playedCardCount < compareGame->playedCardCount){
		counter = game->playedCardCount;
	}
	//Check each card in each player hand in both states.
	for(j = 0; j < counter; j++){
		if(game->playedCards[j] != compareGame->playedCards[j]){
			compRes->playedCards++;
			problems++;
		}
	}

	return problems;
}

void initCompStruct(struct compareReturn * compRes){
	compRes->handCount = 0;
	compRes->hand = 0;
	compRes->deckCount = 0;
	compRes->deck = 0;	
	compRes->discardCount = 0;
	compRes->discard = 0;
	compRes->playedCardCount = 0;	
	compRes->playedCards = 0;
	compRes->coins = 0;
	compRes->actions = 0;	
	compRes->playerCount = 0;	
	compRes->buys = 0;
	compRes->supply = 0;
	compRes->supplyCount = 0;
	compRes->returnResults = 0;
};  

void printProblems(const struct compareReturn * compRes, struct gameState * game, struct gameState * comp, int problems){
	int i, j, players, uneven;

	players = game->numPlayers;

	printf("*******     ********\n");

	if(game->numPlayers != comp->numPlayers){
		uneven = 1;	
		if(comp->numPlayers < game->numPlayers){
			players = comp->numPlayers;
			uneven = 2;
		}
	}

	if(compRes->handCount){
		printf("Hand count *******\n");
		for(i = 0; i < players; i++){
			printf("Game -- Player %i: %i\n", i, game->handCount[i]);
			printf("Comp -- Player %i: %i\n", i, comp->handCount[i]);
		}
		if(uneven && uneven > 1)
			for(;i < comp->numPlayers; i++)
				printf("Comp -- Player %i: %i\n", i, comp->handCount[i]);
		if(uneven && uneven < 2)
			for(;i < game->numPlayers; i++)
				printf("game -- Player %i: %i\n", i, game->handCount[i]);
	}

	if(compRes->handCount){
		printf("Hand *******\n");
		for(i = 0; i < players; i++){
			printf("Game -- Player %i: ", i);
			for(j = 0; j < game->handCount[i]; j++)
				printf("%i ", game->hand[i][j]);
			printf("\n");
			printf("Comp -- Player %i: ", i);
			for(j = 0; j < comp->handCount[i]; j++)
				printf("%i ", comp->hand[i][j]);
			printf("\n");
		}
		if(uneven && uneven > 1){
			for(;i < comp->numPlayers; i++){
				printf("Comp -- Player %i: ", i);
				for(j = 0; j < comp->handCount[i]; j++)
					printf("%i ", comp->hand[i][j]);
				printf("\n");
			}
		}
		if(uneven && uneven < 2){
			for(;i < game->numPlayers; i++){
				printf("Game -- Player %i: ", i);
				for(j = 0; j < game->handCount[i]; j++)
					printf("%i ", game->hand[i][j]);
				printf("\n");
			}
		}
	}

	if(compRes->deckCount){
		printf("Deck count *******\n");
		for(i = 0; i < players; i++){
			printf("Game -- Player %i: %i\n", i, game->deckCount[i]);
			printf("Comp -- Player %i: %i\n", i, comp->deckCount[i]);
		}
		if(uneven && uneven > 1)
			for(;i < comp->numPlayers; i++)
				printf("Comp -- Player %i: %i\n", i, comp->deckCount[i]);
		if(uneven && uneven < 2)
			for(;i < game->numPlayers; i++)
				printf("game -- Player %i: %i\n", i, game->deckCount[i]);
	}

	if(compRes->deckCount){
		printf("Deck *******\n");
		for(i = 0; i < players; i++){
			printf("Game -- Player %i: ", i);
			for(j = 0; j < game->deckCount[i]; j++)
				printf("%i ", game->deck[i][j]);
			printf("\n");
			printf("Comp -- Player %i: ", i);
			for(j = 0; j < comp->deckCount[i]; j++)
				printf("%i ", comp->deck[i][j]);
			printf("\n");
		}
		if(uneven && uneven > 1){
			for(;i < comp->numPlayers; i++){
				printf("Comp -- Player %i: ", i);
				for(j = 0; j < comp->deckCount[i]; j++)
					printf("%i ", comp->deck[i][j]);
				printf("\n");
			}
		}
		if(uneven && uneven < 2){
			for(;i < game->numPlayers; i++){
				printf("Game -- Player %i: ", i);
				for(j = 0; j < game->deckCount[i]; j++)
					printf("%i ", game->deck[i][j]);
				printf("\n");
			}
		}
	}

	if(compRes->discardCount){
		printf("Discard count *******\n");
		for(i = 0; i < players; i++){
			printf("Game -- Player %i: %i\n", i, game->discardCount[i]);
			printf("Comp -- Player %i: %i\n", i, comp->discardCount[i]);
		}
		if(uneven && uneven > 1)
			for(;i < comp->numPlayers; i++)
				printf("Comp -- Player %i: %i\n", i, comp->discardCount[i]);
		if(uneven && uneven < 2)
			for(;i < game->numPlayers; i++)
				printf("game -- Player %i: %i\n", i, game->discardCount[i]);
	}

	if(compRes->discardCount){
		printf("Discard *******\n");
		for(i = 0; i < players; i++){
			printf("Game -- Player %i: ", i);
			for(j = 0; j < game->discardCount[i]; j++)
				printf("%i ", game->discard[i][j]);
			printf("\n");
			printf("Comp -- Player %i: ", i);
			for(j = 0; j < comp->discardCount[i]; j++)
				printf("%i ", comp->discard[i][j]);
			printf("\n");
		}
		if(uneven && uneven > 1){
			for(;i < comp->numPlayers; i++){
				printf("Comp -- Player %i: ", i);
				for(j = 0; j < comp->discardCount[i]; j++)
					printf("%i ", comp->discard[i][j]);
				printf("\n");
			}
		}
		if(uneven && uneven < 2){
			for(;i < game->numPlayers; i++){
				printf("Game -- Player %i: ", i);
				for(j = 0; j < game->discardCount[i]; j++)
					printf("%i ", game->discard[i][j]);
				printf("\n");
			}
		}
	}

	if(compRes->playedCardCount){
		printf("Played cards count *******\n");
		printf("Game: %i\n", game->playedCardCount);
		printf("Comp: %i\n", comp->playedCardCount);
	}

	if(compRes->playedCardCount){
		printf("Played cards *******\n");
		printf("Game -- Player %i: ", i);
		for(j = 0; j < game->playedCardCount; j++)
			printf("%i ", game->playedCards[j]);
		printf("\n");
		printf("Comp -- Player %i: ", i);
		for(j = 0; j < comp->playedCardCount; j++)
			printf("%i ", comp->playedCards[j]);
		printf("\n");
	}

	if(compRes->coins){
		printf("Coins *******\n");
		printf("Game -- coins: %i\n", game->coins);
		printf("Comp -- coins: %i\n", comp->coins);
	}

	if(compRes->actions){
		printf("Coins *******\n");
		printf("Game -- actions: %i\n", game->numActions);
		printf("Comp -- actions: %i\n", comp->numActions);
	}

	if(compRes->buys){
		printf("Coins *******\n");
		printf("Game -- buys: %i\n", game->numBuys);
		printf("Comp -- buys: %i\n", comp->numBuys);
	}

	if(compRes->supplyCount){
		printf("Played cards *******\n");
		printf("Game: ");
		for(j = 0; j < treasure_map+1; j++)
			printf("%i ", game->supplyCount[j]);
		printf("\n");
		printf("Comp: ");
		for(j = 0; j < treasure_map+1; j++)
			printf("%i ", comp->supplyCount[j]);
		printf("\n");
	}

	if(compRes->returnResults) 
		printf("Return result: %i\n", compRes->returnResults);

	if(problems == 0){
		printf("Number of players *******\n");
		printf("Game: %i\n", game->numPlayers);
		printf("Comp: %i\n", comp->numPlayers);
	}
	printf("*******     ********\n");

}

void randomKingdomCards(int * k){
	int i, j, x;

	for(i = 0; i < 10; ){
		k[i] = rand() % treasure_map+1;
		x = 0;
		for(j = 0; j < i; j++){
			if(k[i] == k[j]){
			   x = 1;
			}
		}
		if(!x) i++;
	}
}

void fillDeck(struct gameState *game, int * k){
	int i, j, playerNum;

	playerNum = game->numPlayers;
	
	//Fill deck with cards
	for(i = 0; i < playerNum; i++){
		for(j = 0; j < game->deckCount[i]; j++){
			if(j >= 3) game->deck[i][j] = k[rand() % 10];
			else game->deck[i][j] = copper;
		}
	}

	//Fill hand with cards
	for(i = 0; i < playerNum; i++){
		for(j = 0; j < game->handCount[i]; j++){
			game->hand[i][j] = k[rand() % 10];
		}
	}

	//Fill discard with cards
	for(i = 0; i < playerNum; i++){
		for(j = 0; j < game->discardCount[i]; j++){
			if(game->deckCount[i] > 3)
				game->discard[i][j] = k[rand() % 10];
			else {
				if(j >= 3) game->discard[i][j] = k[rand() % 10];
				else game->discard[i][j] = copper;
			}
		}
	}

	for(i = 0; i < game->playedCardCount; i++)
		game->playedCards[i] = k[rand() % 10];


	if(DEBUGADVENTURER){
		printf("Players: %i\n", game->numPlayers);
	
		for(i = 0; i < game->numPlayers; i++){
			printf("Player %i deck count: %i\n", i, game->deckCount[i] );
			for(j = 0; j < game->deckCount[i]; j++){
				printf("%i ", game->deck[i][j]);
			}
			printf("\n");

			printf("Player %i hand count: %i\n", i, game->handCount[i] );
			for(j = 0; j < game->handCount[i]; j++){
				printf("%i ", game->hand[i][j]);
			}
			printf("\n");

			printf("Player %i discard count: %i\n", i, game->discardCount[i] );
			for(j = 0; j < game->discardCount[i]; j++){
				printf("%i ", game->discard[i][j]);
			}
			printf("\n");
		}
	}

}

void addToFinalRes(const struct compareReturn * curRes, struct compareReturn * totRes){
	if(curRes->handCount) totRes->handCount++;
	if(curRes->hand) totRes->hand++;
	if(curRes->deckCount) totRes->deckCount++;
	if(curRes->deck) totRes->deck++;	
	if(curRes->discardCount) totRes->discardCount++;
	if(curRes->discard) totRes->discard++;
	if(curRes->playedCardCount) totRes->playedCardCount++;	
	if(curRes->playedCards) totRes->playedCards++;
	if(curRes->coins) totRes->coins++;
	if(curRes->actions) totRes->actions++;	
	if(curRes->playerCount) totRes->playerCount++;	
	if(curRes->buys) totRes->buys++;
	if(curRes->supply) totRes->supply++;
	if(curRes->supplyCount) totRes->supplyCount++;
	if(curRes->returnResults) totRes->returnResults++;
}

void printFinalRes(struct compareReturn * totRes){
	printf("Hand count: %i\n", totRes->handCount);
	printf("Hand: %i\n", totRes->hand);
	printf("Deck count: %i\n", totRes->deckCount);
	printf("Deck: %i\n", totRes->deck);	
	printf("Discard count: %i\n", totRes->discardCount);
	printf("Discard: %i\n", totRes->discard);
	printf("Played card count: %i\n", totRes->playedCardCount);	
	printf("Played cards: %i\n", totRes->playedCards);
	printf("Coins: %i\n", totRes->coins);
	printf("Actions: %i\n", totRes->actions);	
	printf("Player count: %i\n", totRes->playerCount);	
	printf("Buys: %i\n", totRes->buys);
	printf("Supply: %i\n", totRes->supply);
	printf("Supply count: %i\n", totRes->supplyCount);
	printf("Return Results: %i\n", totRes->returnResults);
}


void adventurerRandomTest(const int VERBOSE_TEST){
	struct gameState game, compareGame;
	//int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int k[10];
	int i, curPlayer, handPos, result, problems, x, tempCount, treasureFound, newCard;
	struct compareReturn compRes, finalRes;
	int temp[MAX_DECK];
	int sample = 0;

	for(i = 0; i < 500; i++){
		randomKingdomCards(k);

		x = 0;
		
		game.numPlayers = rand() % MAX_PLAYERS + 1;

		if(game.numPlayers > MAX_PLAYERS) game.numPlayers = MAX_PLAYERS;
		
		for(x = 0; x < game.numPlayers; x++){
			game.handCount[x] = (rand() % 10) + 1;
			game.deckCount[x] = rand() % MAX_DECK;
			game.discardCount[x] = rand() % (MAX_DECK - game.deckCount[x]);
			if(game.deckCount[x] + game.discardCount[x] < 10){
				game.deckCount[x] = 10;
			}
		}
		game.whoseTurn = rand() % (game.numPlayers + 1);
		game.playedCardCount = rand() % MAX_HAND;
		game.numBuys = rand() % MAX_DECK;
		game.numActions = rand() % MAX_HAND;
		game.coins = rand() % MAX_DECK;

		setupSupply(&game, game.numPlayers, k);

		fillDeck(&game, k);

		memcpy(&compareGame, &game, sizeof(struct gameState));

		initCompStruct(&compRes);
	
		if(game.numPlayers > 0)
			curPlayer = rand() % game.numPlayers;

		if(game.handCount[curPlayer] > 0)
			handPos = floor(rand() % game.handCount[curPlayer]);
		else handPos = 0;
	
		game.hand[curPlayer][handPos] = adventurer;

		result = adventurerCard(curPlayer, &game);

		if(compareGame.numPlayers > 0){	
			compareGame.hand[curPlayer][handPos] = adventurer;
			//compareGame.handCount[curPlayer] += 3;
			treasureFound = 0;	
			tempCount = 0;
			while(treasureFound < 2){
				drawCard(curPlayer, &compareGame);
				newCard = compareGame.hand[curPlayer][compareGame.handCount[curPlayer] - 1];
				if(newCard == copper || newCard == silver || newCard == gold)
					treasureFound++;
				else {
					temp[tempCount] = newCard;
					tempCount++;
					compareGame.handCount[curPlayer]--;
				}
			}
			for(x = 0; x < tempCount; x++){
				compareGame.discard[curPlayer][compareGame.discardCount[curPlayer]] = temp[x];
				compareGame.discardCount[curPlayer]++;
			}
			discardCard(handPos, curPlayer, &compareGame, 0);
		}

		problems = checkStates(&game, &compareGame, &compRes, result);
	
		if(VERBOSE_TEST){
			printf("Test run #%i -- Problems: %i\n", i, problems);
			printProblems(&compRes, &game, &compareGame, problems);
		} else if(!sample) {
			if(problems > 10){
				printf("Test run #%i -- Problems: %i\n", i, problems);
				printProblems(&compRes, &game, &compareGame, problems);
				sample++;
			}
		}


		addToFinalRes(&compRes, &finalRes);	
	}
	printFinalRes(&finalRes);
}

int main(int argc, char **argv){

	srand(time(NULL));

	if(argc < 2)
		adventurerRandomTest(0);
	else if(argc == 2){
		if(argv[1][0] == '-' && argv[1][1] == 'v')
			adventurerRandomTest(1);
		else
			printf("Usage: ./randomtestcard {-v}\n -v is optional.\n");
	}

	return 0;

}
