/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 5
* BugsInTeammates.c
* Discussion of Bugs found in my teammates' code
*----------------------------------------------------------------------*/
In my first teammate's code (siebertc), I found problems in the following tests:

unittest2 - buyCard() method

Test player 1 with 1 cards in hand and 9 in deck.
Hand = 0, Expected = 1
Deck = 0, Expected = 9

It appears to happen around boundary condition, as it happened again here:
Test player 0 with 1 cards in hand and 9 in deck.
Hand = 0, Expected = 1
Deck = 0, Expected = 9

So I would conclude that this function has been changed by my teammate as well,
as it is causing unexpected behavior.

unittest3 - discardCard() method

Again, errors were encountered with this method, particularly around the final
check that tries to catch "playing" a card with an empty hand. This is actually
a problem with how the original program was written, in my opinion.

Empty hand, played = 6, Expected = 5
Errors were encountered.

cardtest1 - smithy card

I found some error in my teammate's code:
Testing smithy for playCard(0, 0, 0, 0, gamestate):
Testing for player 0:
Test actions updated correctly:
Actions = 0, Expected = 0
Test buys unchanged:
Buys = 1, Expected = 1
Test deck updated correctly:
Deck = 1, Expected = 2
Test hand updated correctly:
Hand = 8, Expected = 7
Errors were encountered.

Hand doesn't have the right number of cards.

cardtest2 - adventurer card

I found some error in my teammate's code:
Testing adventurer for playCard(0, 0, 0, 0, gamestate):
Testing for player 0:
G.handcount is 5
Number of treasures is 3 before playing card.
Playing card...
Test actions updated correctly:
Actions = 0, Expected = 0
Test buys unchanged:
Buys = 1, Expected = 1
Test hand updated correctly:
Hand = 7, Expected = 6
Test number of treasures:
numTreasuresPost = 5, Expected = 5
Errors were encountered.

Hand doesn't have the right number of cards.

In addition, the random test turned up errors as well:
Testing for adventurer for playcard(3, 0, 0, 0, gameState):
Test actions updated correctly:
Actions = 0, Expected = 0
Test buys unchanged:
Buys = 1, Expected = 1
Test hand updated correctly:
Hand = 6, Expected = 6
Test number of treasures:
numTreasuresPost = 3, Expected = 5
Test player 1 unchanged:
Deck = 10, Expected = 10
Hand = 0, Expected = 0
Test player 2 unchanged:
Deck = 10, Expected = 10
Hand = 0, Expected = 0
Number of tests run: 1000
Number of tests that encountered errors: 1000
Errors were encountered.

Number of treasures in hand is not correctly updated.

cardtest3 - council_room card

More errors:
Testing council_room for playCard(0, 0, 0, 0, gamestate):
Testing for player 0:
Test actions updated correctly:
Actions = 0, Expected = 0
Test buys updated correctly:
Buys = 2, Expected = 2
Test deck updated correctly:
Deck = 0, Expected = 1
Test hand updated correctly:
Hand = 9, Expected = 8
Checking the hands of other players:
Player 1 Hand = 1, Expected = 1
Errors were encountered.

Incorrect number of cards in hand.

cardtest4 - village card

Yet more errors:
Testing village for playCard(0, 0, 0, 0, gamestate):
Testing for player 0:
Test actions updated correctly:
Actions = 2, Expected = 2
Test buys updated correctly:
Buys = 1, Expected = 1
Test deck updated correctly:
Deck = 5, Expected = 4
Test hand updated correctly:
Hand = 4, Expected = 5
Errors were encountered.

Incorrect number of cards in hand.

In addition, the random test was for the village card, it came up with errors as well:
Testing village for playCard(0, 0, 0, 0, gameState):
Testing for village card player 0:
Test actions updated correctly:
Actions = 2, Expected = 2
Test buys updated correctly:
Buys = 1, Expected = 1
Test deck updated correctly:
Deck = 5, Expected = 4
Test hand updated correctly:
Hand = 4, Expected = 5
Test player 1 unchanged:
Deck = 9, Expected = 10
Hand = 1, Expected = 0
Test player 2 unchanged:
Deck = 10, Expected = 10
Hand = 0, Expected = 0
Number of tests run: 1000

Incorrect number of cards in hand.

Checking on my second teammate's code, (batese), I found errors:

unittest2 - buyCard() method
Test player 0 with 1 cards in hand and 9 in deck.
Hand = 0, Expected = 1
Deck = 0, Expected = 9
Boundary condition problem.


unittest3 - discardCard() method
Test player 0 with 0 cards in hand and 5 played.
Hand = 0, Expected = 0
Played = 5, Expected = 5
Empty hand, played = 6, Expected = 5
Errors were encountered.

Similar problem with discardCard() method. This is probably normal to everyone, so maybe it
can be ignored as part of the code architecture moves this change away from this function.

cardtest1 - smithy card
Testing smithy for playCard(0, 0, 0, 0, gamestate):
Testing for player 0:
Test actions updated correctly:
Actions = 0, Expected = 0
Test buys unchanged:
Buys = 1, Expected = 1
Test deck updated correctly:
Deck = 5, Expected = 2
Test hand updated correctly:
Hand = 4, Expected = 7
Errors were encountered.

Hand has an incorrect number of cards, deck has not been drawn from.

cardtest2 - adventurer card

Testing adventurer for playCard(0, 0, 0, 0, gamestate):
Testing for player 0:
G.handcount is 5
Number of treasures is 3 before playing card.
Playing card...
Test actions updated correctly:
Actions = 0, Expected = 0
Test buys unchanged:
Buys = 1, Expected = 1
Test hand updated correctly:
Hand = 7, Expected = 6
Test number of treasures:
numTreasuresPost = 5, Expected = 5
Errors were encountered.

Hand has an incorrect number of cards.

cardtest4 - village card
Testing village for playCard(0, 0, 0, 0, gamestate):
Testing for player 0:
Test actions updated correctly:
Actions = 1, Expected = 2
Test buys updated correctly:
Buys = 1, Expected = 1
Test deck updated correctly:
Deck = 4, Expected = 4
Test hand updated correctly:
Hand = 5, Expected = 5
Errors were encountered.

Actions is not updated correctly.