/***************************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
*
* --------------------------------------------------------------------------------------
* BUGS IN SINGHBA'S DOMINION CODE 
* Note: Unit tests had to be modified to accomodate this code.
*
* updateCoins
* Testfile: unittest1.c
* Test Status: Passed test.
*
* drawCard
* Testfile: unittest2.c
* Test Status: Passed test.
*
* discardCard
* Testfile: unittest3.c
* Test Status: Failed... the function allows you to call the function with an invalid hand position
* 		and then decreases the handcount even though the card position was invalid.
*
* endTurn
* Testfile: unittest4.c
* Test Status: Passed test.
*
* int smithyEffect(struct gameState *state, int handPos)
* Testfile: cardtest2.c
* Test Status: TODO
* Testfile: randomtestcard.c 
* Test Status: TODO
*
* int adventurerEffect(struct gameState *state, int handPos)
* Testfile: cardtest1.c
* Test Status: TODO
* Testfile: randomtestadventurer.c
* Test Status: TODO
*
* int councilEffect(struct gameState *state, int handPos)
*		No unit test was implemented for this card.
*
* int feastEffect(struct gameState *state, int choice1)
*		No unit test was implemented for this card.
*
* BUG SUMMARY FOR SINGHBA:
* BUG1 -
* BUG2 - 
* BUG3 - the discardCard function allows you to call it with an invalid hand position
* and then decreases the handcount even though the card position was invalid.
* --------------------------------------------------------------------------------------
*
* --------------------------------------------------------------------------------------
* BUGS IN KOSLOFFD'S DOMINION CODE 
* Note: Unit tests did not need be modified to accomodate this code.
*
* updateCoins
* Testfile: unittest1.c
* Test Status: Passed test.
*
* drawCard
* Testfile: unittest2.c
* Test Status: Passed test.
*
* discardCard
* Testfile: unittest3.c
* Test Status: Failed... the function allows you to call the function with an invalid hand position
* 		and then decreases the handcount even though the card position was invalid.
*
* endTurn
* Testfile: unittest4.c
* Test Status: Passed test.
*
* int playAdventurer(int currentPlayer, struct gameState* state)
* Testfile: cardtest1.c
* Test Status: Failed
*		- Can call function with another player other than the actual current player, you should
*		use the current player from the gamestate instead
*		- Treasure count is +1 treasures more than expected.
*		- When player has no cards in deck but cards in its discard pile, it appears no treasures
*		are being added to the players hand.
*		- Fails first test in which there are no treasures in the players deck nor discard pile.
* Testfile: randomtestadventurer.c
* Test Status: Failed 100/100 
*		- Treasure count is +1 treasures more than expected. This is due to drawntreasure being 
*		initialized to -1 instead of 0.
*
* int playSmithy(int currentPlayer, struct gameState *state, int handPos);
* Testfile: cardtest2.c
* Test Status: Failed
*		- players hand count is one less than expected
*		- Failed assertion due to checkHand test_helper function. This is because the discardcard fxn
* 		is called by discardCard(handPos, 0, state, 1). The second parameter should be the current
*		player and not fixed at 0. This is causing a change to another players hand when player 0
*		isn't the current player.
* Testfile: randomtestcard.c 
* Test Status: Failed 10/10
* 		- Handcount is one less than expected
*		- The function is discarding the card, but this is not an effect of the card.
*
* int playMinion(int currentPlayer, struct gameState* state, int choice1, int choice2, int handPos);
*		No unit test was implemented for this card.
*
* int playSteward(int currentPlayer, struct gameState* state, int choice1, int choice2, int choice3, int handPos);
*		No unit test was implemented for this card.
*
* int playCutpurse(int currentPlayer, struct gameState* state, int handPos);
* Testfile: cardtest4.c
* Test Status: Passed
*
* BUG SUMMARY FOR KOSLOFFD:
* BUG1 - playAdventurer is initialized to -1 instead of 0, and thus an additional
* treasure is being added.
* BUG2 - playSmithy is discarding the card, when this is not an effect of the card. 
* Additionally, the discardCard function is not called with the curent player and
* thus you are always discarding a card from player 0's hand.
* BUG3 - the discardCard function allows you to call it with an invalid hand position
* and then decreases the handcount even though the card position was invalid.
* --------------------------------------------------------------------------------------
*
****************************************************************************************/