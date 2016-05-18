/***************************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
*
* --------------------------------------------------------------------------------------
* BUGS IN SINGHBA'S DOMINION CODE 
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
* and then decreases the handcount even though the card position was invalid.
*
* endTurn
* Testfile: unittest4.c
* Test Status: Passed
*
* int smithyEffect(struct gameState *state, int handPos)
* Testfile: cardtest2.c, randomtestcard.c 
*
* int adventurerEffect(struct gameState *state, int handPos)
* Testfile: cardtest1.c, randomtestadventurer.c:
*
* int councilEffect(struct gameState *state, int handPos)
*		I did not implement a unit test for this card.
*
* int feastEffect(struct gameState *state, int choice1)
*		I did not implement a unit test for this card.
* --------------------------------------------------------------------------------------
*
* --------------------------------------------------------------------------------------
* BUGS IN KOSLOFFD'S DOMINION CODE 
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
* and then decreases the handcount even though the card position was invalid.
*
* endTurn
* Testfile: unittest4.c
* Test Status: Passed test.
*
* int playAdventurer(int currentPlayer, struct gameState* state)
* Tesfile: cardtest1.c, randomtestadventurer.c:
* Test Status: TOOD
*
* int playSmithy(int currentPlayer, struct gameState *state, int handPos);
* Testfile: cardtest2.c, randomtestcard.c 
* Test Status: TOOD
*
* int playMinion(int currentPlayer, struct gameState* state, int choice1, int choice2, int handPos);
*		I did not implement a unit test for this card.
*
* int playSteward(int currentPlayer, struct gameState* state, int choice1, int choice2, int choice3, int handPos);
*		I did not implement a unit test for this card.
*
* int playCutpurse(int currentPlayer, struct gameState* state, int handPos);
* Testfile: cardtest4.c
* Test Status: TOOD
* --------------------------------------------------------------------------------------
*
****************************************************************************************/