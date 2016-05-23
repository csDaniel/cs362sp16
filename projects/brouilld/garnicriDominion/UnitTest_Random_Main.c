#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <setjmp.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "UnitTest_Random_DefinedTests.h"



int main(int argc, char *argv[])
{

	FILE *doc = fopen("unittestresults.out", "w");
	fclose(doc);

	// testRandom_adventurer(int numOfRuns, int randomNumPlayers, int randomWhoseTurn, int randomDeckCount, int randomCardType)
	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 1 run", 1, 0, 0, 0, 0);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 1 run, randomNumPlayers, randomWhoseTurn, randomDeckCount, randomCardType", 1, 1, 1, 1, 1);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 5 runs", 5, 0, 0, 0, 0);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 2 runs, randomNumPlayers, randomWhoseTurn", 2, 1, 1, 0, 0);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 2 runs, randomDeckCount, randomCardType", 2, 0, 0, 1, 1);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 2 runs, randomWhoseTurn, randomDeckCount", 2, 0, 1, 1, 0);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 2 runs, randomNumPlayers, randomCardType", 2, 1, 0, 0, 1);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 2 run, randomCardType", 2, 0, 0, 0, 1);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 2 runs, randomDeckCount", 2, 0, 0, 1, 0);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 2 runs, randomWhoseTurn", 2, 0, 1, 0, 0);

	TestSuiteRandom(testRandom_adventurer, "Card 'adventurer': Function'card_adventurer' : 2 runs, randomNumPlayers", 2, 1, 0, 0, 0);


	//void testRandom_village(int numOfRuns, int randomNumActions, int randomTopDeck)
	TestSuiteRandom(testRandom_village, "Card 'village': Function 'card_village' : 1 run", 1, 0, 0, 0, 0);

	TestSuiteRandom(testRandom_village, "Card 'village': Function 'card_village' : 5 runs", 5, 0, 0, 0, 0);

	TestSuiteRandom(testRandom_village, "Card 'village': Function 'card_village' : 1 run, randomNumAction", 1, 1, 0, 0, 0);

	TestSuiteRandom(testRandom_village, "Card 'village': Function 'card_village' : 3 runs, randomNumAction", 3, 1, 0, 0, 0);

	TestSuiteRandom(testRandom_village, "Card 'village': Function 'card_village' : 1 run, randomTopDeck", 1, 0, 1, 0, 0);

	TestSuiteRandom(testRandom_village, "Card 'village': Function 'card_village' : 7 runs, randomTopDeck", 7, 0, 1, 0, 0);

	TestSuiteRandom(testRandom_village, "Card 'village': Function 'card_village' : 5 runs, randomNumActions, randomTopDeck", 5, 1, 1, 0, 0);


	return 0;
}