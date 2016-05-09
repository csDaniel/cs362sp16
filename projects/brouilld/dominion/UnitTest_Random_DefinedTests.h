#ifndef UNITTEST_RANDOM_DEFINEDTESTS_H
#define	UNITTEST_RANDOM_DEFINEDTESTS_H

void setup(struct gameState *state, int currentPlayer, int deckCount, int cardType);
void village_Setup(struct gameState *state, int currentPlayer, int cardType);
void testRandom_adventurer(int numOfRuns, int randomNumPlayers, int randomWhoseTurn, int randomDeckCount, int randomCardType);
void testRandom_village(int numOfRuns, int randomNumActions, int randomTopDeck, int blank, int blank2);

#endif