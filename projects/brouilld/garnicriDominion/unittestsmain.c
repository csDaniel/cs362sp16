#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"



int main(int argc, char *argv[])
{

	FILE *doc = fopen("unittestresults.out", "w");
	fclose(doc);

	TestSuite(testUpdateCoins, "Function 'updateCoins()'", 1);

	TestSuite(testGetCost, "Function 'getCost()'", 1);

	TestSuite(testPlayCard, "Function 'playCard()'", 1);

	TestSuite(testBuyCard, "Function 'buyCard()'", 1);

	TestSuite(testSmithyCard, "Card 'Smithy'", 1);

	TestSuite(testAdventurerCard, "Card 'Adventurer'", 1);

	TestSuite(testCouncilRoomCard, "Card 'Council Room'", 1);

	TestSuite(testVillageCard, "Card 'Village'", 1);

	return 0;
}