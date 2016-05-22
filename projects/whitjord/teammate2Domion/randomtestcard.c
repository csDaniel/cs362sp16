/* random card test for smithy card
 * cs 362 Jordan White
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int main() {
    // set up random stream
    SelectStream(1);
    PutSeed(45678);
         
    struct gameState og, cg; // original, changed game states
    int i, j, handPos, cardEffectReturn, coin_bonus, card_played;
    // main test loop
    for( i = 0; i < 1000; i++) {
        randomGameState(&og);
        memcpy(&cg, &og, sizeof(struct gameState));
        card_played = 0;
        // check for smithy card, if it's in hand play it
        for(handPos = 0; handPos < cg.handCount[cg.whoseTurn]; handPos++) {
            if (cg.hand[cg.whoseTurn][handPos] == smithy) {
                // choosing to call cardEffect vs playCard
                // so we don't have to take into account playCard()'s changes
                cardEffectReturn = cardEffect(smithy,0,0,0,&cg,handPos,&coin_bonus);
                card_played = 1;
                break;
            }
        }
        // if card was played do comparision of changed gameState to original
        if ( card_played == 1 ) {

            printf("####################################################\n");
            printf("smithy card was played\n");
            myAssert(og.numPlayers, cg.numPlayers, "number of players shouldn't change");
            myAssert(og.whoseTurn, cg.whoseTurn, "turn should not change");
            myAssert(og.coins, cg.coins, "coins should not change");
            myAssert(og.numActions, cg.numActions, "num actions should not change");
            myAssert((og.handCount[og.whoseTurn] + 3 -1),cg.handCount[og.whoseTurn], "player should now have a handCount +2 (+3 -1)");  
            // check to see that other players info didn't change
            for ( j = 0; j < cg.numPlayers; j++) {
                if (j != cg.whoseTurn) {
                    myAssert(cg.discardCount[j], og.discardCount[j], "other players discardCounts should not change");
                    myAssert(cg.deckCount[j], og.deckCount[j], "other players deckCounts should not change");
                }
            }
        }
    }

    return 0;
}

                                                           
 

