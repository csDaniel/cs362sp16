Bugs in Dave Martin's Dominion

Name: Lauren Miller
Date: May 19, 2016

Bug Number: 1
Bug Title: Smithy Draws Too Many Cards
Severity: Minor
Function Tested: playSmithy
Description: Every player consistently has 2 more cards in hand after playing the Smithy card than there should be. 
Expected Results: There should be a net of 2 cards in hand after playing Smithy, 3 drawn as the benefit of playing Smithy and 1 discarded, the Smithy itself. For example, if a player had 10 cards in hand and plays Smithy, their handCount should change from 10 to 8.
Actual Results: In all tested cases, handCount is 2 higher than expected. For example, when a player had 10 cards in hand and plays Smithy, the expected gameState.handCount is 8, but the actual gameState.handCount is 10.

Bug Number: 2
Bug Title: DiscardCount Not Incremented When Playing DiscardCount
Severity: Moderate
Function Tested: discardCard
Description: After playing discardCount, gameState.discardCount is not incremented. should be incremented by 1
Expected Results: After playing discardCount, gameState.discardCount should be one 1 higher than it was before playing the game. For example if discardCount is 0 and discardCard us played, discardCount should then be 1.
Actual Results: After playing discardCard, discardCount is not incremented. In all tested cases, handCount remained 0 after playing dicardCard. However, gameState.handCount was appropriately decremented by 1 for every play of discardCard. For example, if a player with 10 cards in hand and 0 in the discard pile plays discardCard, the expected gameState.handCount is 9 and the expected gameState.discardCount is 1, while the actual gameState.handCount is 9 and the actual gameState.discardCount is 0.

