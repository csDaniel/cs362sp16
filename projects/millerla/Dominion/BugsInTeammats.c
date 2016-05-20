Assignment 5

Name: Lauren Miller
Date: May 19, 2016


Bugs in Dave Martin's Dominion

Bug Number: 1 (DM)
Bug Title: Smithy Draws Too Many Cards
Severity: Minor
Function Tested: playSmithy
Description: Every player consistently has 2 more cards in hand after playing the Smithy card than there should be. 
Expected Results: There should be a net of 2 cards in hand after playing Smithy, 3 drawn as the benefit of playing Smithy and 1 discarded, the Smithy itself. For example, if a player had 10 cards in hand and plays Smithy, their handCount should change from 10 to 8.
Actual Results: In all tested cases, handCount is 2 higher than expected. For example, when a player had 10 cards in hand and plays Smithy, the expected gameState.handCount is 8, but the actual gameState.handCount is 10.

Bug Number: 2 (DM)
Bug Title: DiscardCount Not Incremented When Playing DiscardCount
Severity: Moderate
Function Tested: discardCard
Description: After playing discardCount, gameState.discardCount is not incremented. should be incremented by 1
Expected Results: After playing discardCount, gameState.discardCount should be one 1 higher than it was before playing the game. For example if discardCount is 0 and discardCard us played, discardCount should then be 1.
Actual Results: After playing discardCard, discardCount is not incremented. In all tested cases, handCount remained 0 after playing dicardCard. However, gameState.handCount was appropriately decremented by 1 for every play of discardCard. For example, if a player with 10 cards in hand and 0 in the discard pile plays discardCard, the expected gameState.handCount is 9 and the expected gameState.discardCount is 1, while the actual gameState.handCount is 9 and the actual gameState.discardCount is 0.


Bugs in Runa Trinh's Dominion

Bug Number: 1 (RT)
Bug Title: Adventurer Card Remaining in Hand After Play, Missing Treasure Cards After Play
Severity: Moderate
Function Tested: AdventurerCard, CardEffect
Description: After using CardEffect to play Adventurer, there is either no treaasure card at the end of the active player's deck or there is no treasure card as the second to last card in the active player's deck. If there is no treasure card in the last position of the player's hand, there is one in the second to last position. Likewise, if there is no treasure card in the second to last position in the player's hand, there is one in the last position. In both cases, where there is a missing treasure card, there is an Adventurer card. This might indicate that the Adventurer is not discarded. This is true even if there are available cards and available treasure cards. This is true for every test run, at least where there are sufficient treasure cards.
Expected Results: If there are available treasure cards, after playing Adventurer, there should be a net of 1 card added to the hand of the active player, 2 treasure cards previously in their deck or discard pile, and 1 card discarded, the Adventurer. gameState.handCount should be 1 and both gameState.hand[currentPlayer][game.handCount[currentPlayer]-1] gameState.hand[currentPlayer][game.handCount[currentPlayer]-2] should be gold, silver, or copper.
Actual Results: There are two possible types of outcome that seem mutually exclusive. There will either be  a net of 0 cards added to the hand of the active player, the last card in hand will be an Adventurer, and the second to last card in hand will be one of the treasure cards OR there will be a net of 1 card added to the hand of the active player, there will be a treasure card as the second to last card in the player's hand, and the last card will be an Adventurer. Here samples of the types of errors generated from my random tests:

ERROR IN MISSING TREASURE CARD AT END OF HAND: test: 0, player: 0, game.deckCount previously: 407, game.discardCount previously: 137, treasure in game.deckCount and game.discardCount: 58, CARD enum: 7, net game.handCount: 0

ERROR IN MISSING TREASURE CARD AT END OF HAND - 1: test: 19, player: 0, game.deckCount previously: 180, game.discardCount previously: 353, treasure in game.deckCount and game.discardCount: 57, CARD enum: 7, net game.handCount: 1

Bug Number: 2 (RT)
Bug Title: Adventurer Returns -1
Severity: Minor
Function Tested: AdventurerCard, CardEffect
Description: In every test case, using CardEffect to play Adventurer returns -1 when a return value of 0 is expected.
Expected Results: Calling playCard(gameState.handCount[currentPlayer] - 1, -1, -1, -1, &gameState) when the last card in hand is an Adventurer should return 0.
Actual Results: Calling playCard(gameState.handCount[currentPlayer] - 1, -1, -1, -1, &gameState) when the last card in hand is an Adventurer returns -1.