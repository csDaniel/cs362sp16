/*
CS 362 Bugs in Teammates' Code
Sarah Lemieux
Teammates: Jonathan Harijanto and Behnam Saeedi

********************************************************
Teammate 1: Jonathan Harijanto

Test 1: cardtest1 (tests Smithy card)

	Results:
		Test: current player's handCount, deckCount, and discardCount: FAILED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test: +1 playedCardCount: PASSED

	Failed tests:
		(These are the card counts for the player who plays the Smithy card)
		assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer] + 2);
		assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer] - 3);
		assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 1);

	Comments:
		Looking at refactor.c, these failed tests are explained by the bugs that he added.

Test 2: cardtest2 (tests Adventurer card)

	Results:
		Test: +2 treasure in hand: FAILED
		Test: discardCount increased by 2 (this is what should happen given the way I set up my test): FAILED
		Test: Smithy and Minion cards found in discard pile (this is what should happen given the way I set up my test): PASSED
		Test: Adventurer added to played cards pile and playedCardCount incremented by 1: FAILED

	Failed tests:
		assert(treasureBefore + 2 == treasureAfter);
		assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 2);
		assert(game->playedCardCount == testGame.playedCardCount + 1);

	Comments:
		Looking at refactor.c, these failed tests are explained by the bugs that he added.
		Also, the Adventurer card not being addded to the played pile is a bug in the original dominion.c code.

Test 3: cardtest3 (tests Council Room card)

	Results:
		Test: +3 handCount: FAILED
		Test: -4 deckCount: FAILED
		Test: +1 numBuys: FAILED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test: +1 playedCardCount: PASSED

	Failed tests:
		assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer] + 3);
		assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer] - 4);
		assert(game->numBuys == testGame.numBuys + 1);

	Comments:
			Looking at refactor.c, these failed tests are explained by the bugs that he added.


Test 4: cardtest4 (tests Feast card)

	Results:
		Choice 1: Embargo
			Test: current player's handCount, deckCount, and discardCount: PASSED
			Test: Embargo added to discard pile: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED 
		Choice 2: Mine
			Test: current player's handCount, deckCount, and discardCount: PASSED
			Test: Mine added to discard pile: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Choice 3: Adventurer
			Test: player not allowed to gain Adventurer card (too expensive): FAILED (infinite loop)

	Failed tests:
		Trying to gain the Adventurer card causes an infinite loop

	Comments:
		This failed test is caused by a bug in the original dominion.c code.

Test 5: unittest1 (tests function whoseTurn())

	Results:
		Test: set state->whoseTurn = 0, check that whoseTurn(state) returns 0: PASSED
		Test: set state->whoseTurn = 1, check that whoseTurn(state) returns 1: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
	
	Failed tests: none

Test 6: unittest2 (tests function supplyCount())
	
	Results:
		Test: supplyCount() returns initial count of all cards in supply: PASSED
		Test: supplyCount() returns correct modified values of supply count: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED

	Failed tests: none

Test 7: unittest3 (tests function buyCard())
	
	Results:
		Test 1: buy Embargo
			Test: hand/deck count the same, +1 discardCount after buying embargo: PASSED
			Test: embargo added to discard pile: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test 2: buy Mine
			Test: hand/deck count the same, +1 discardCount after buying mine: PASSED
			Test: mine added to discard pile: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test 3: attempt to buy Adventurer (too expensive)
			Test: hand/deck/discard count the same: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test 4: attempt to buy Embargo when numBuys == 0
			Test: hand/deck/discard count the same: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test 5: attempt to buy a card that is out of supply
			Test: hand/deck/discard count the same: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED

	Failed tests: none

Test 8: unittest4 (tests function gainCard())
	
	Results:
		Test 1: gain Adventurer to discard
			Test: hand/deck count the same, +1 discardCount: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test 2: gain Adventurer to deck
			Test: hand/discard count the same, +1 deckCount: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test 3: gain Adventurer to hand
			Test: discard/deck count the same, +1 handCount: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test 4: attempt to gain a card not in supply
			Test: hand/deck/discard count the same: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED

	Failed tests: none

Test 9: randomtestadventurer

	Results:
		When the tests were repeated 2000 times, the Adventurer card was never added to the
		played pile (this is a bug in the original Adventurer code).
		Also, on many of the tests, the number of treasure cards didn't increase by
		exactly 2, and the discard and deck counts were incorrect.

	Comments:
			Looking at refactor.c, these failed tests are explained by the bugs that he added.

Test 10: randomtestcard (tests Council Room)

	Results:
		Every time the tests are run, the handCount, deckCount, and numBuys are incorrect.

	Comments:
		Looking at refactor.c, these failed tests are explained by the bugs that he added.

********************************************************
Teammate 2: Behnam Saeedi

Test 1: cardtest1 (tests Smithy card)

	Results:
		Test: current player's handCount, deckCount, and discardCount: FAILED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test: +1 playedCardCount: PASSED

	Failed tests:
		(These are the card counts for the player who plays the Smithy card)
		assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer] + 2);
		assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer] - 3);
		assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 1);

	Comments:
		Looking at refactor.c, these failed tests are explained by the bugs that he added.

Test 2: cardtest2 (tests Adventurer card)

	Results:
		Test: +2 treasure in hand: PASSED
		Test: discardCount increased by 2 (this is what should happen given the way I set up my test): FAILED
		Test: Smithy and Minion cards found in discard pile (this is what should happen given the way I set up my test): PASSED
		Test: Adventurer added to played cards pile and playedCardCount incremented by 1: FAILED

	Failed tests:
		assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 2);
		assert(game->playedCardCount == testGame.playedCardCount + 1);

	Comments:
		Looking at refactor.c, these failed tests are explained by the bugs that he added.
		Also, the Adventurer card not being addded to the played pile is a bug in the original dominion.c code.

Test 3: cardtest3 (tests Council Room card)

	Results:
		Test: +3 handCount: PASSED
		Test: -4 deckCount: PASSED
		Test: +1 numBuys: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
		Test: +1 playedCardCount: PASSED

	Failed tests: none

Test 4: cardtest4 (tests Feast card)

	Results:
		Choice 1: Embargo
			Test: current player's handCount, deckCount, and discardCount: PASSED
			Test: Embargo added to discard pile: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Choice 2: Mine
			Test: current player's handCount, deckCount, and discardCount: PASSED
			Test: Mine added to discard pile: PASSED
			Test: other players' state and the victory and kingdom piles not modified: PASSED
		Choice 3: Adventurer
			Test: player not allowed to gain Adventurer card (too expensive): FAILED (infinite loop)

	Failed tests:
		Trying to gain the Adventurer card causes an infinite loop

	Comments:
		This failed test is caused by a bug in the original dominion.c code.
		My tests did not catch the bugs he added to this function, which cause
		inaccurate values for the player's hand, as I only tested handCount, not
		the values of the cards in the hand.

Test 5: unittest1 (tests function whoseTurn())

	Results:
		Test: set state->whoseTurn = 0, check that whoseTurn(state) returns 0: PASSED
		Test: set state->whoseTurn = 1, check that whoseTurn(state) returns 1: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED

	Failed tests: none

Test 6: unittest2 (tests function supplyCount())

	Results:
		Test: supplyCount() returns initial count of all cards in supply: PASSED
		Test: supplyCount() returns correct modified values of supply count: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED

	Failed tests: none

Test 7: unittest3 (tests function buyCard())

	Results:
	Test 1: buy Embargo
		Test: hand/deck count the same, +1 discardCount after buying embargo: PASSED
		Test: embargo added to discard pile: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
	Test 2: buy Mine
		Test: hand/deck count the same, +1 discardCount after buying mine: PASSED
		Test: mine added to discard pile: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
	Test 3: attempt to buy Adventurer (too expensive)
		Test: hand/deck/discard count the same: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
	Test 4: attempt to buy Embargo when numBuys == 0
		Test: hand/deck/discard count the same: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
	Test 5: attempt to buy a card that is out of supply
		Test: hand/deck/discard count the same: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED

	Failed tests: none

Test 8: unittest4 (tests function gainCard())

Results:
	Test 1: gain Adventurer to discard
		Test: hand/deck count the same, +1 discardCount: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
	Test 2: gain Adventurer to deck
		Test: hand/discard count the same, +1 deckCount: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
	Test 3: gain Adventurer to hand
		Test: discard/deck count the same, +1 handCount: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED
	Test 4: attempt to gain a card not in supply
		Test: hand/deck/discard count the same: PASSED
		Test: other players' state and the victory and kingdom piles not modified: PASSED

	Failed tests: none

Test 9: randomtestadventurer

	Results:
		When the tests were repeated 2000 times, the Adventurer card was never added to the
		played pile (this is a bug in the original Adventurer code).
		Every test also fails the discard and deck count.
		During 2 of the 2000 tests, the +2 treasure also failed.

	Comments:
		Looking at refactor.c, the failed discard and deck count tests are explained by the bugs that he added.
		However, I can't figure out what causes the +2 treasure to fail occasionally.

Test 10: randomtestcard (tests Council Room)

	Results:
		All of the tests pass.
*/