/***************Erin Donnelly************/
/***************donnelerDominion ************/
Successfully ran all tests written by me.

TEST PASSED: All the 4 unitests are passed, cardtest1 and cardtest2 are also passed. randomcardtest is also passed.

TEST FAILED: cardtest3 and cardtest4 are failed. randomtestadventurer is also failed.

Following 2 bugs are to report
BUG-1: Smithy Card->    Hand Count, deck count and actions are not as expected
----------------- Testing Card: smithy ----------------
----------------- Player 0: smithy ----------------
hand count = 6, expected = 7
deck count = 3, expected = 2
actions = 3, expected = 1
playedcards = 1, expected = 1
cardtest3: cardtest3.c:55: main: Assertion `testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded failed.
Abort (core dumped)

BUG-2: Adventurer card
----------------- Testing Card: adventurer ----------------
----------------- Player 0 All treasure cards on deck: adventurer ----------------
hand count = 5, expected = 6
deck count = 10, expected = 8
actions = 1, expected = 1
playedcards = 0, expected = 1
FAIL: handCount is wrong
FAIL: deckCount is wrong
FAIL: playedCardCount is wrong

/***************Dylan York Kosloff************/
/***************kosloffdDominion************/
Successfully ran all tests written by me.

TEST PASSED: All the 4 unitests are passed, cardtest1 and cardtest2 are also passed. randomcardtest is also passed.

TEST FAILED: cardtest3 and cardtest4. randomtestadventurer is also failed.

Following 2 bugs are to report
BUG-1: Smithy Card->   Deck count and actions are not as expected
----------------- Testing Card: smithy ----------------
----------------- Player 0: smithy ----------------
hand count = 7, expected = 7
deck count = 1, expected = 2
actions = 3, expected = 1
playedcards = 1, expected = 1
cardtest3: cardtest3.c:56: main: Assertion `testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards' failed.
Abort (core dumped)

BUG-2: Adventurer card
----------------- Testing Card: adventurer ----------------
----------------- Player 0 All treasure cards on deck: adventurer ----------------
hand count = 11, expected = 6
deck count = 3, expected = 8
actions = 1, expected = 1
playedcards = 1, expected = 1
FAIL: handCount is wrong
FAIL: deckCount is wrong