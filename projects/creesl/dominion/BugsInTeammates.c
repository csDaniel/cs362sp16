/*
Bugs in teammates' code.
Assignement 5

Teammate 1 - johnchri
Common cards refactored to test: smithy, adventurer
---------------------------------------------------
Smithy
Test: cardtest1 - smithy
	Player should have 3 more cards: FAIL
	Should be 3 less cards in player's pile: FAIL

Report
Title: Smithy card not effecting precisely 3 cards
Classification: Serious Bug
Reproducibility: Every time
Description: The smithy card, when played, does not add precisely 3 cards
to the player's hand nor does it reduce the player's deck by
precisely 3 cards.
Bug appeard in cardtest.
---------------------------------------------------
Adventurer
Test: cardtest2 - adventurer
	Player's hand should have two more cards: FAIL
	Discard + 2 = difference in deck amount: FAIL

Test: randomtestadventurer
	Player's hand should have two more cards: FAIL
	Discard + 2 = difference in deck amount: FAIL
	Number of Players: 2
	Location: 0, Coin: copper
	Rerun
	Player's hand should have two more cards: FAIL
	Discard + 2 = difference in deck amount: FAIL
	Number of Players: 3
	Location: 0, Coin: silver
	Location: 1, Coin: gold

Report
Title: Adventurer card not effecting precisely 2 cards
Classification: Serious Bug
Reproducibility: Every time
Description: The adventurer card, when played, does not add precisely 2
cards to the player's hand.  This also effects the number of cards drawn
from the deck.
Problem appeared in both cardtest and random testing.
---------------------------------------------------
---------------------------------------------------
---------------------------------------------------
Teammate 2 - mcmiljac
Common cards refactored to test: smithy, adventurer
---------------------------------------------------
Smithy
Test: cardtest1 - smithy
	All tests pass

No bugs to report.
---------------------------------------------------
Adventurer
Test: cardtest2 - adventurer
	All tests pass

Test: randomtestadventurer
	Player's hand should have two more cards: FAIL
	Discard + 2 = difference in deck amount: FAIL
	Number of players: 2
	Rerun
	Number of players: 4
	Rerun
	Number of players: 3
	Deck count for player in each instance <= 0
	This makes sense, because if the player's deck has no
	cards, then there can be no drawing of treasure cards.
	So, this failure is actually a pass under these circumstances.

No bugs to report.

*/