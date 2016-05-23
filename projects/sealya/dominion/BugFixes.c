/*
Aaron Sealy
Assignment 5
CS 362
Spring 2016

Bug Fixes

My teammates both found the bugs that I introduced to my Smithy, Adventurer, and Great_Hall functions.
So, I will remove them as well as the other bugs I added to the remodel and Sea_hag functions

Smithy:
	Buggy code:   for (i = 1; i < 3; i++)
                {
                    drawCard(currentPlayer, state);
                }
    Restored code:   for (i = 0; i < 3; i++)
                {
                    drawCard(currentPlayer, state);
                }

Adventurer:
    Buggy code:   if (cardDrawn == copper || cardDrawn == silver)
                    drawntreasure++;
    Restored code:   if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
                    drawntreasure++;

Great Hall:
    Buggy Code:   state->numActions++;
                state->numActions--;
    Restored code:   state->numActions++;

Remodel:
    Buggy Code:  if ( (getCost(state->hand[currentPlayer][choice1]) + 4) > getCost(choice2) )
                {
                  return -1;
                }
    Restored code:   if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
                {
                  return -1;
                }

Sea hag:
    Buggy Code:   if (i = currentPlayer)
    Restored code:   if (i != currentPlayer)

After these changes were made, I ran my 10 test files and...

All unittest cards passed.

cardtest1 (Smithy): all tests passed.

cardtest3 (Great_Hall): all tests passed.

cardtest 4 (Village): all tests passed.

randomtestcard (Great_Hall): all tests passed.

Tests continue to fail, however, in cardtest2 and randomtestadventurer, both of which relate to the adventurer function

The tests show that the coin values seem to work now, but that it is not discarding properly.  It seems the temp pile
is not discarding properly and the adventurer card is not discarding properly.

I decided to manually inspect the code related to the temp pile and discarding.

I optimized the adventurer code in dominion to fix the discard issue as below.

int adventurerCard(int currentPlayer, struct gameState *state, int handPos){
    int drawntreasure = 0;
    int temphand[MAX_HAND];
    int cardDrawn;
    int z = 0;

    while(drawntreasure<2){
        if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawntreasure++;
        else{
            discardCard(cardDrawn, currentPlayer, state, 0);
        }
    }
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}

I thought it should work, but I still got weird results.
I used gdb and debugging to check the values at different points, and I found where things went wrong, but I could not figure
out why.

After several hours of frustration I realized that my logic was off because for some reason I was thinking that drawcard picked
from the lowest deck index position instead of the highest.  Once I fixed that silly mistake in my test, my optimized code passed
all four tests.

Testing Adventurer card:
TEST 1: hand count = 2. Expected result = 2.
TEST 2: played count = 3. Expected result = 3.
TEST 3: coins = 2. Expected result = 2.
TEST 4: deck count = 1. Expected result = 1.
All 4 tests passed!

*/
