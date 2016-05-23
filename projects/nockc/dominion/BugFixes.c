/*
 * Bug #1
 *
 * Title: The scoreFor() function does not return correct score for discard and deck
 * Assigned By: Tatsiana Clifton
 * Tatsiana's Description:
 * The for loop of counting score for deck is not based on the deck count.
 * state->discardCount[player] should be state->deckCount[player]
 * Fix: Change line 444 on dominion.c from the following: 
 * for (i = 0; i < state->discardCount[player]; i++)
 * to the following:
 * for (i = 0; i < state->deckCount[player]; i++)
 *
 * Bug #2
 *
 * Title: The smithy card: the current player does not receive exactly 3 cards
 * Assigned By: Tatsiana Clifton, Alex Marsh
 * Tatsiana's and Alex's Description:
 * The function should add 3 cards to the player's hand. It adds 5.
 * for (i = 0; i <= 4; i++) should be for (i = 0; i < 3; i++)
 * Fix: Change line 1264 on dominion.c from the following: 
 * for (i = 0; i <= 4; i++) 
 * to the following:
 * (i = 0; i < 3; i++)
 *
 * Bug #3
 *
 * Title: The smithy card: actual handCount and deckCount not same as expected values
 * Assigned By: me
 * Description:
 * Actual handCount should be 2 less than actual handCount and deckCount should be 2 more than actual handCount, due to same bug # 2.
 * It was fixed by Bug # 2 fix.
 *
 * Bug #4
 *
 * Title: The adventurer card: play count is not changed
 * Assigned By: Tatsiana Clifton
 * Tatsiana's Description:
 * The play count should be increased by 1. Description: The play count should be increased by 1. 
 * The call of the function discardCard should be added to the adventurer card.
 * Fix: Add discardCard(handPos, currentPlayer, state, 0); to line 1256 
 * Add int playAdventurer(struct gameState *state, int currentPlayer, int handPos){ to line 1229
 * Add return playAdventurer(state, currentPlayer, handPos); to line 671
 * This fix discards Adventurer after its played, and increases the played cards count by 1.
 *
 * Bug #5
 *
 * Title: The discard Card function increases the played cards count instead of discard count
 * Assigned By: me
 * Description:
 * Played cards should be added to the player's discarded cards pile and their discarded cards count should increase by 1. 
 * Fix:
 * Add to line 1132 the following:
 * state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][handPos];
 *  
 *  state->discardCount[currentPlayer]++;
 *
 *  Bug #6
 *
 *  Title: The adventurer card: actual treasure card count doesn't increase by 2 from previous to post game state 
 *  Assigned By: Alex Marsh
 *  Alex's Description: 
 *  Actual handCount is not more than that of previous game state. This is due to the bug introduced in refactored Adventurer which causes player to draw cards until 1 additional treasure card is drawn instead of 2. 
 *  Fix:
 *  Change line 1238 to int drawntreasure = 0;
 *
 *  Bug #7
 *  Title: The village card: the number of actions is not increased by 2
 *  Assigned By: Tatsiana Clifton
 *  Tatsiana's Description:
 *  The function should add 2 actions. It adds 3.
 *  state->numActions = state->numActions + 3; should be state->numActions = state->numActions + 2;
 *  Fix: 
 *  Change line 1286 to state->numActions = state->numActions + 2;
 *
 *  Bug #8
 *  Title: The council room card: 
 *  Assigned by: me
 *  Description:
 *  Actual handCount for current player is 1 more than expected, actual deckCount for current player is 1 less than expected, actual handCount for other player is 1 less than expected, actual deckCount for other player
 *  is 1 more than expected due to the bug which gives current player (instead of other player/s) an additional card draw  
 *  Fix:
 *  Change line 1351 to if ( i != currentPlayer )
 *
 *  Bug #9
 *  Title: The isGameOver function: three empty pile test fails for 2 cards
 *  Assigned By: me
 *  Description:
 *  Three empty pile test fails when one of the empty piles is either sea_hag (card 25) or treasure_map (card 26) 
 *  Fix: 
 *  Change line 402 to for (i = 0; i < 27; i++) 
 *
 *  Due to the above fixes, overall dominion coverage improved from 33.69% to 52.21%. 'playCouncil_Room', 'playFeast', 'playVillage', 'playSmithy', 'isGameOver', 'fullDeckcount', and 'updateCoins' ( functions tested in unit random and card tests)  are improved to 100% lines executed. buyCard is at 92.31% lines executed.   
 *  */
