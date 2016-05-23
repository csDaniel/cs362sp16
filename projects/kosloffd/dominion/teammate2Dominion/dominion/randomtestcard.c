#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct errorType
{
    char* errorName;
    int qty;
    signed int errorSeed;     // For common errors, we don't care which random seed triggered it (that's why the limit is only 32),
                            // but you want to have some record of the seeds that can trigger the rare errors.
};

struct errorCounter
{
    int totalErrors;
    struct errorType** errors;
};


void initErrorCounter(struct errorCounter* eCounter, int totalErrorTypes);
void addError( struct errorCounter* eCounter, char* errorType, signed int seedNumber);
void randomizeGame(struct gameState* state, int* gameCards);
int getRandomDeck(struct gameState* game, int* kCards, int player, int maxCards);
void getRandomDiscard(struct gameState* game, int* kCards, int player, int maxCards);
void getRandomHand(struct gameState* game, int* kCards, int player);
int getRandomCard(struct gameState* game, int* kCards);
int putCouncilRoomInHand(struct gameState* game);
void testCouncilRoom(struct gameState* game, int handIndex, struct errorCounter* ecount, int seedNumber);
void freeErrorCounter(struct errorCounter* eCounter);
void printErrorTotals(struct errorCounter* ecount, int qtyOfTests);

int main(int argc, char **argv)
{
    int maxErrorTypes = 50;
    if(argc != 2)
    {
        printf("\nUsage: %s [number of tests to run]\n", argv[0]);
        exit(1);
    }

    int numOfRuns = atoi(argv[1]);

    struct errorCounter* ecount = malloc(sizeof(struct errorCounter));
    initErrorCounter(ecount, maxErrorTypes);

    int i, testCounter;
    testCounter = 0;
    for(i=0; i < numOfRuns; i++)
    {
        time_t seed = time(NULL);
        srand( seed );
        struct gameState* game = newGame();
        int* cardsInPlay = kingdomCards(adventurer, baron, smithy, mine, remodel, feast, steward, village, salvager, treasure_map);
        if(initializeGame(2, cardsInPlay, seed, game) == -1)
        {
            printf("Couldn't intialize game!\n");
            exit(0);
        }
        randomizeGame(game, cardsInPlay);

        int indexInHand = putCouncilRoomInHand(game);
        testCouncilRoom(game, indexInHand, ecount, seed);
        free(game);
        testCounter++;
    }

    printf("\nTotal Tests Run: %d", testCounter);
    printf("\nTotal errors found: %d", ecount->totalErrors);
    printErrorTotals(ecount, testCounter);
    freeErrorCounter(ecount);

    // At the end, give the percentage of tests out of the whole which failed for each counter
    return 0;
}


/**
 * Initialzes the error counter struct
 * params:
 *      eCounter:           The error counter to initialize
 *      totalErrorTypes:    A number at least as large as the different possible errors the test could encounter
 */
void initErrorCounter(struct errorCounter* eCounter, int totalErrorTypes)
{
    eCounter->totalErrors = 0;
    eCounter->errors = malloc(totalErrorTypes*sizeof(struct errorType *));
    eCounter->errors[0] = NULL;
}

/**
 * Adds an error to the error counter
 * params:
 *      eCounter:       The error counter
 *      errorType:      A brief description of the error (should be consistent with each error)
 *      seedNumber:     The random seed to be stored for duplicating the results
 */
void addError( struct errorCounter* eCounter, char* errorType, signed int seedNumber)
{
    int i = 0;
    while(eCounter->errors[i] != NULL)
    {
        if( strcmp(eCounter->errors[i]->errorName, errorType) == 0 )
        {
            eCounter->errors[i]->qty++;
            int errQty = eCounter->errors[i]->qty;
            if(errQty < 32)
                eCounter->errors[i]->errorSeed = seedNumber;
            eCounter->totalErrors++;
            return;
        }
        i++;
    }
    // If the error has not shown up before, create and initialize a new struct errorType
    eCounter->errors[i] = malloc(sizeof(struct errorType));
    eCounter->errors[i]->errorName = errorType;
    eCounter->errors[i]->qty = 1;
    eCounter->errors[i]->errorSeed = seedNumber;
    eCounter->errors[i+1] = NULL;                           // Using NULL as a sentinel here for the next available error
    eCounter->totalErrors++;
}


/**
 * Prints the total number of each error and the percentage of the tests which it was found
 * params:
 *       ecount:     The error counter which contains the error information
 *       qtyOfTests: The total number of tests performed
 */
void printErrorTotals(struct errorCounter* ecount, int qtyOfTests)
{
    int i = 0;
    float percent;
    printf("\n\nError:%-70s Number of Times Encountered:\tPercentage of total run times:\n", "");
    while(ecount->errors[i] != NULL)
    {
        percent = ( (float)ecount->errors[i]->qty /  qtyOfTests) * 100;
        if(percent < 10)
            printf("\n%-80s%d (seed value: %d)\t\t%2.2f%%", ecount->errors[i]->errorName, ecount->errors[i]->qty, ecount->errors[i]->errorSeed, percent);
        else
            printf("\n%-80s%-22d\t\t\t%2.2f%%", ecount->errors[i]->errorName, ecount->errors[i]->qty, percent);
        i++;
    }
}


/**
 * Frees the error counter and the errorType structs
 * params:
 *       eCounter:       The Error Counter struct to free
 */
void freeErrorCounter(struct errorCounter* eCounter)
{
    int i = 0;
    while(eCounter->errors[i] != NULL)
        free(eCounter->errors[i++]);
    free(eCounter->errors);
    free(eCounter);
}

/**
 * Randomizes the deck and discard of both players and the hand of the current player
 * params:
 *      state:      The game state
 *      gameCards:  An array of pointers to the kingdom cards which are in play
 */
void randomizeGame(struct gameState* state, int* gameCards)
{
    int thisPlayer = whoseTurn(state);
    int otherPlayer = thisPlayer^1;

    /**
     * Randomize deck: 130 treasure possible, 100 kingdom cards possible, 24 Victory cards,
     * so a maximum of 270 is much more reasonable than MAX_DECK (500), which is the number of cards in the
     * entire box, including unplayable cards. We divide that number in half and use it as the random max for each player.
     */
     int cardsLeft = getRandomDeck(state, gameCards, thisPlayer, 135);
     getRandomDiscard(state, gameCards, thisPlayer, cardsLeft);
     int otherCardsLeft = getRandomDeck(state, gameCards, otherPlayer, 135);
     getRandomDiscard(state, gameCards, thisPlayer, otherCardsLeft);

    // Randomize hand   -- not sure this is necessary
    getRandomHand(state, gameCards, thisPlayer);
    getRandomHand(state, gameCards, otherPlayer);
}


/**
 * Gets a random card from those in the game.  Cards 0-6 are the standard cards in every game
 * (victory, curse, treasure) and the remaining 10 values are one of the kingdom cards in play.
 * params:
 *      game:       The current state of the game
 *      kCards:     An array of pointers to the kingdom cards which are in play
 * returns:
 *      cardValue:  A randomly chosen card in the game
 */
int getRandomCard(struct gameState* game, int* kCards)
{
    int cardValue = rand()%16;
    if(cardValue < 7)
        return cardValue;
    else
        return kCards[cardValue - 6];
}

/**
 * Creates a randomly sized deck of random cards which are a part of the current game
 * params:
 *      game:       The current game state
 *      kCards:     An array of pointers to the kingdom cards which are in play
 *      player:     The player for which to organize a random deck
 *      maxCards:   The maximum possible deck size
 * returns:
 *      cardsLeft:  The difference between the chosen deck size and maxCards
 */
int getRandomDeck(struct gameState* game, int* kCards, int player, int maxCards)
{
    int i, cardsInDeck, cardsLeft;
    cardsInDeck = rand() % maxCards;
    cardsLeft = maxCards - cardsInDeck;
    game->deckCount[player] = cardsInDeck;

    for(i=0; i < cardsInDeck; i++)
        game->deck[player][i] = getRandomCard(game, kCards);

    return cardsLeft;
}

/**
 * Creates a randomly sized discard of random cards which are a part of the current game
 * params:
 *      game:       The current game state
 *      kCards:     An array of pointers to the kingdom cards which are in play
 *      player:     The player for which to organize a random discard
 *      maxCards:   The maximum possible discard pile size
 */
void getRandomDiscard(struct gameState* game, int* kCards, int player, int maxCards)
{
    int i, cardsInDiscard;
    cardsInDiscard = rand() % maxCards;
    game->discardCount[player] = cardsInDiscard;

    for(i=0; i < cardsInDiscard; i++)
        game->discard[player][i] = getRandomCard(game, kCards);
}

/**
 * Creates a randomly sized hand of cards which are randomly chosen from the player's deck
 * params:
 *      game:       The current game state
 *      kCards:     An array of pointers to the kingdom cards which are in play
 *      player:     The player for which to organize a random deck
 */
void getRandomHand(struct gameState* game, int* kCards, int player)
{
    int i, deckIndex, tempCard;
    int handSize = rand() % 15 + 1;     // It's not common to have many more than 10 cards in your hand, but you must have at least one to hold Council Room
    game->handCount[player] = handSize;
    for(i=0; i<handSize; i++)
    {
        deckIndex = rand() % game->deckCount[player];   // Swap each card in the hand with a random card from the deck
        tempCard = game->deck[player][deckIndex];
        game->deck[player][deckIndex] = game->hand[player][i];
        game->hand[player][i] = tempCard;
    }
}

/**
 * Replaces a random card in the player's hand with the Council Room card so the player can play it.
 * params:
 *      game:   The current game state
 * returns:
 *      index:  The index of the Council Room card in the player's hand
 */
int putCouncilRoomInHand(struct gameState* game)
{
    int player, index;
    player = whoseTurn(game);
    index = rand() % game->handCount[player];
    game->hand[player][index] = council_room;
    return index;
}

/**
 * Plays the Council Room card and compares the game state tot the state before it was played to determine where errors exist.
 * Any errors found are recorded in the errorCounter to be analyzed after the testing is concluded.
 * params:
 *      game:       The current state of the game
 *      handIndex:  The position of the Council Room card in the player's hand
 *      ecount:     The error counter where errors will be accumulated
 *      seedNumber: The random seed used to generate these game conditions so they can be replicated if necessary
 */
void testCouncilRoom(struct gameState* game, int handIndex, struct errorCounter* ecount, int seedNumber)
{
    int thisPlayer = whoseTurn(game);
    int otherPlayer = thisPlayer ^1;
    int thisPlayerShuffled = 0;
    int otherPlayerShuffled = 0;

    //For each test use
    struct gameState* initialState = malloc(sizeof(struct gameState));
    memcpy(initialState, game, sizeof(struct gameState));

    playCard(handIndex, 0,0,0, game);

    if( initialState->deckCount[thisPlayer] != ( game->deckCount[thisPlayer] - 4 ) &&
       initialState->discardCount[thisPlayer] != game->discardCount[thisPlayer] )
        thisPlayerShuffled = 1;

    if( initialState->deckCount[otherPlayer] != ( game->deckCount[otherPlayer] - 1 ) &&
       initialState->discardCount[otherPlayer] != game->discardCount[otherPlayer] )
        otherPlayerShuffled = 1;
    /* Begin testing for unexpected changes in game state */

    if( initialState->numPlayers != game->numPlayers )
        addError(ecount, "Changed number of players", seedNumber );

    int i;        // There are 26 possible cards, make sure the same are still in play
    for(i=0; i<=26; i++)
    {
        if( initialState->supplyCount[i] != game->supplyCount[i] )
        {
            addError(ecount, "Changed number of kingdom cards", seedNumber );
            break;
        }
    }
    for(i=0; i<=26; i++)
    {
        if(initialState->embargoTokens[i] != game->embargoTokens[i])
        {
            addError(ecount, "Changed number of Embargo Tokens in play", seedNumber );
            break;
        }
    }
    if( initialState->outpostPlayed != game->outpostPlayed)
        addError(ecount, "Changed \"Outpost Played\" status", seedNumber );

    if( initialState->outpostTurn != game->outpostTurn)
        addError(ecount, "Changed the \"Outpost Turn\" status", seedNumber );

    if( initialState->whoseTurn != game->whoseTurn)
        addError(ecount, "Changed whose turn it is", seedNumber );

    if( initialState->phase != game->phase)
        addError(ecount, "Changed the game phase", seedNumber );

    if( initialState->numActions != game->numActions)
        addError(ecount, "Changed number of actions for this turn", seedNumber );

    if( initialState->coins != game->coins)
        addError(ecount, "Changed the \"coins\" variable", seedNumber );

    if( initialState->numBuys == game->numBuys )
        addError(ecount, "Did not change the number of Buy phases available", seedNumber );

    if( initialState->numBuys != game->numBuys - 1)
        addError(ecount, "Incorrectly changed the number of Buy phases available", seedNumber );


    if( game->handCount[thisPlayer] != initialState->handCount[thisPlayer] + 3 )    // Draw 4, put council_room in playedCards, so only 3 total gained
    {
        if( game->handCount[thisPlayer] == initialState->handCount[thisPlayer])
            addError(ecount, "Did NOT change the number of cards in this player's hand", seedNumber );
        else
            addError(ecount, "Incorrectly changed the number of cards in this player's hand", seedNumber );
    }
        // Toggle the bit to check for the other player's hand
    if( initialState->handCount[otherPlayer] != game->handCount[otherPlayer] - 1 )      //The other player gets to draw a card as well
    {
        if( initialState->handCount[otherPlayer] == game->handCount[otherPlayer] )
            addError(ecount, "Did NOT change the number of cards in the other player's hand", seedNumber );
        else
            addError(ecount, "Incorrectly changed the number of cards in the other player's hand", seedNumber );
    }

    for(i=0; i< initialState->handCount[thisPlayer] - 1; i++) // Only up to handCount -1 because of the adventurer that was played from position handCount
    {
        if( initialState->hand[thisPlayer][i] != game->hand[thisPlayer][i])
        {
            addError(ecount, "Changed the cards in this player's hand", seedNumber );
            break;
        }
    }
    for(i=0; i<initialState->handCount[otherPlayer]; i++)
    {
        if( initialState->hand[otherPlayer][i] != game->hand[otherPlayer][i])
        {
            addError(ecount, "Changed the cards in the other player's hand", seedNumber );
            break;
        }
    }

    // Complicated, but basically the sum of the discard and deck (in case a shuffle was necessary) should be two less after playing the card
    if(game->deckCount[thisPlayer] + game->discardCount[thisPlayer] != initialState->deckCount[thisPlayer] + initialState->discardCount[thisPlayer] - 4)
    {
        if(game->deckCount[thisPlayer] + game->discardCount[thisPlayer] == initialState->deckCount[thisPlayer] + initialState->discardCount[thisPlayer])
            addError(ecount, "Did NOT change the total of the \"deck plus discard\" count for this player", seedNumber );
        else
            addError(ecount, "Incorrectly changed the total of the \"deck plus discard\" count for this player", seedNumber );
    }

    if(game->deckCount[otherPlayer] + game->discardCount[otherPlayer] != initialState->deckCount[otherPlayer] + initialState->discardCount[otherPlayer] - 1)
    {
        if(game->deckCount[otherPlayer] + game->discardCount[otherPlayer] == initialState->deckCount[otherPlayer] + initialState->discardCount[otherPlayer])
            addError(ecount, "Did NOT change the total of the \"deck plus discard\" count for the other player", seedNumber );
        else
            addError(ecount, "Incorrectly changed the total of the \"deck plus discard\" count for the other player", seedNumber );
    }

    if( !thisPlayerShuffled )
    {
        for(i=0; i<game->deckCount[thisPlayer]; i++)
        {
            if(initialState->deck[thisPlayer][i] != game->deck[thisPlayer][i] - 4)
            {
                addError(ecount, "Changed the contents of this player's deck", seedNumber );
                break;
            }
        }

        if(initialState->discardCount[thisPlayer] != game->discardCount[thisPlayer])
                addError(ecount, "Changed the count of this player's discard pile", seedNumber );

        for(i=0; i<game->discardCount[thisPlayer]; i++)
        {
            if(initialState->discard[thisPlayer][i] != game->discard[thisPlayer][i])
            {
                addError(ecount, "Changed the contents of this player's discard", seedNumber );
                break;
            }
        }
    }

    if( !otherPlayerShuffled )
    {
        for(i=0; i<game->deckCount[otherPlayer]; i++)
        {
            if(initialState->deck[otherPlayer][i] != game->deck[otherPlayer][i])
            {
                addError(ecount, "Changed the contents of the other player's deck", seedNumber );
                break;
            }
        }

        if(initialState->discardCount[otherPlayer] != game->discardCount[otherPlayer])
                addError(ecount, "Changed the count of the other player's discard pile", seedNumber );

        for(i=0; i<game->discardCount[otherPlayer]; i++)
        {
            if(initialState->discard[otherPlayer][i] != game->discard[otherPlayer][i])
            {
                addError(ecount, "Changed the contents of the other player's discard", seedNumber );
                break;
            }
        }
    }


    if(initialState->playedCardCount != game->playedCardCount + 1)
    {
        if(initialState->playedCardCount == game->playedCardCount)
            addError(ecount, "Did NOT change the count of played cards", seedNumber );
        else
            addError(ecount, "Incorrectly changed the count of played cards", seedNumber );
    }

    for(i=0; i<game->playedCardCount; i++)
    {
        if(initialState->playedCards[i] != game->playedCards[i])
        {
            addError(ecount, "Changed the cards in the \"Played Cards\" stack", seedNumber );
            break;
        }
    }

    free(initialState);
}
