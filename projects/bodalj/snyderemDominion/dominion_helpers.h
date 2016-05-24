#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

int adventurerEffect(int, struct gameState*);
int smithyEffect(int, struct gameState*, int);
int baronEffect(int, struct gameState*, int);
int minionEffect(int, struct gameState*, int, int, int);
int tributeEffect(int, int, struct gameState*);

// jensbodal test function prototypes
int playAdventurer(int currentPlayer, struct gameState *state);
int playBaron(int currentPlayer, int choice1, struct gameState *state);
int playCouncilRoom(int currentPlayer, int handPos, struct gameState *state);
int playFeast(int currentPlayer, int choice1, struct gameState *state);
int playSmithy(int currentPlayer, int handPos, struct gameState *state);
int playVillage(int currentPlayer, int handPos, struct gameState *state);
int playGreatHall(int currentPlayer, int handPos, struct gameState *state);

#endif
