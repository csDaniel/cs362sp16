#ifndef _DOMINION_UNIT_TESTS
#define _DOMINION_UNIT_TESTS

int addTreasureCard(int player, struct gameState *state, int tCard);
int clearHand(int player, struct gameState *state);
void testUpdateCoins(int numOfRuns);
void testGetCost(int numOfRuns);
void testPlayCard(int numOfRuns);
void testBuyCard(int numOfRuns);
void testSmithyCard(int numOfRuns);
void testAdventurerCard(int numOfRuns);
void testCouncilRoomCard(int numOfRuns);
void testVillageCard(int numOfRuns);

#endif