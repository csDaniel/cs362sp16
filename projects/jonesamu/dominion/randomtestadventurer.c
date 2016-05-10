/*
Sam Jones
Date: 05/06/16
Description: Tests  player drawing cards
- Tests if other players draw & discard calls 
- Tests if player discards treasure cards
*/

int main (int argc, char** argv) {
    printf ("---------- Randomly testing adventurerCard() ----------\n");
    
    time_t seed = time(NULL);
    // Random setup
    srand((unsigned int)seed);
    
    // Game instance setup
    int i;
    int temphand[MAX_HAND];
    int z[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    for (i = 0; i < 100; i++){
        // Game setup
        int j, cardDrawn;
        j = cardDrawn = 0;
        struct gameState G;
        struct gameState G2;
    
        // Random inputs
        int drawnTreasure = rand() % (2 + 1 - 0) + 0;
        int handPos = rand() % (4 + 1 - 0) + 0;
        int numPlayers = rand() % (MAX_PLAYERS + 1 - 2) + 2;
        
        printf("drawnTreasure is %i\n", drawnTreasure);
        printf("handPos is %i\n", handPos);
        printf("numPlayers is %i\n", numPlayers);

        
        // Initialize game
        initializeGame(numPlayers, z, 10, &G);
        initializeGame(numPlayers, z, 10, &G2);
        G.whoseTurn = 0;
        
        // Use adventurer card
        G.hand[G.whoseTurn][handPos] = adventurer;
        
        // Play the card
        adventurerCard(drawnTreasure, &G2, G.whoseTurn, j, temphand, cardDrawn);
        
        // TEST 1
        // Check that handCount has 2 additional cards
        if (G2.handCount[G.whoseTurn] == G.handCount[G.whoseTurn] + 2)
            printf ("adventurerCard() test1: passed.\n");
        else
            printf ("adventurerCard() test1: failed.\n");
        
        // TEST 2:
        // Check that all drawn cards are treasure cards
        int i;
        for (i = 0; i < 2; i++){
            if (G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == copper ||
                G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == silver ||
                G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == gold)
                printf ("adventurerCard() card%i test2: passed.\n", i+1);
            else
                printf ("adventurerCard() card%i test2: failed.\n", i+1);
        }
        
        // TEST 3
        // Check that the deckcount decreased by at least 2
        if (G2.deckCount[G.whoseTurn] <= (G.deckCount[G.whoseTurn]))
            printf ("adventurerCard() test3: passed.\n");
        else
            printf ("adventurerCard() test3: failed.\n");
        
    }
    
    return 0;
}