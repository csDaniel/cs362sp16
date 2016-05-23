BugsInTeamates

BUG NUM: 1
BUG NAME: Adventurer - Some of the treasure cards are never tested
BUG DESCRIPTION:
In Rick G.'s code: When one of the first 2 treasury cards in the player's deck
is Gold, the Gold card ends up in the discard pile. Revealed by test 3 of the
adventurer suite
----------------- Testing Card: adventurer ----------------
[...]
TEST 3: No treasury card should have been discarded.
  TEST FAILED.
In David B.'s code: When one of the first treasury cards in the player's deck
is either copper or silver, the card ends up in the discard pile. Revealed by TESTCARD
3 of the adventure suite.
TEST 3: No treasury card should have been discarded.
  TEST FAILED.

BUG NUM: 2
BUG NAME: Adventurer - Player receives 3 rather than 2 cards
BUG DESCRIPTION: The player's hand contains 3 more cards after playing Adventure.
It should only have 2 more cards. Revealed by test 1 of the adventure suite.
----------------- Testing Card: adventurer ----------------
TEST 1: +2 cards in player's hand
  hand count = 8, expected = 7
  TEST FAILED
(This bug appears in David B.'s code)

BUG NUM: 3
BUG NAME: Adventurer - Player receives 1 rather than 2 cards
BUG DESCRIPTION: The player's hand contains 1 more card after playing Adventure.
It should have 2 more cards. Revealed by test 1 of the adventure suite.
----------------- Testing Card: adventurer ----------------
TEST 1: +2 cards in player's hand
  hand count = 6, expected = 7
  TEST FAILED
(This bug appears in David B.'s code)

BUG NUM: 4
BUG NAME: Smithy - Player receives 4 cards instead of 3.
BUG DESCRIPTION: One too many cards are taken from player's deck
and end up in player's hand. Revealed by tests 1 and 2 of the
"smithy" test suite.
----------------- Testing Card: smithy ----------------
TEST 1: +3 cards in player's hand
  hand count = 8, expected = 7
  TEST FAILED
TEST 2: -3 cards in player's deck
  deck count = 1, expected = 2
  TEST FAILED
(This bug appears in Rick G.'s code)

BUG NUM: 5
BUG NAME: remodel - Desired card is trashed rather than added to discard
BUG DESCRIPTION: (associated bugs) The desired card is not found in discard pile;
meanwhile the remodeled card is not fund in trash.
----------------- Testing Card: remodel ----------------
[...]
TEST 2: Card that the player wants to gain (choice 2) ends up in player's discard pile.
 discarded: 3, expected: 5,  TEST FAILED.
[...]
TEST 4: Card that the player wants to trash (choice 1) ends up in trash (not discard pile)
 trashed: 3, expected not to be 3,  TEST FAILED.
(This bug appears in David B.'s code)
