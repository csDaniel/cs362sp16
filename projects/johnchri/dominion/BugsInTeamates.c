//bug report
/*
teammate1 creesl
Random Test: adventurerAffect
results:
	FAIL! Incorrect handCount
	SUCCESS! Discards increased
	SUCCESS! Num treasures increased by 2
	FAIL! Incorrect handCount for player 2
	SUCCESS! Discards increased for player 2
	SUCCESS! Num treasures increased by 2 for player 2

test: adventurerAffect
results:
	FAIL! Incorrect handCount
	SUCCESS! Discards increased

test: smithyEffect
resutls:
	SUCCESS! Correct handCount
	FAIL! Incorrect playedCardCount
	SUCCESS! Correct deckCount
	
Bugs:
	-adventurerEffect does not not end with the correct number of cards in the players hand.
	-the smithyEffect does not discard the right number of cards.

------------------------------------------------------------------------
teammate2 mcmilljac
Random Test: randomtestadventurer
results:
	FAIL! Incorrect handCount
	SUCCESS! Discards increased
	SUCCESS! Num treasures increased by 2
	FAIL! Incorrect handCount for player 2
	SUCCESS! Discards increased for player 2
	SUCCESS! Num treasures increased by 2 for player 2

test: playAdventurer
results:
	FAIL! Incorrect handCount
	SUCCESS! Discards increased

Random Test: playCouncil_Room
results:
	SUCCESS! Num buys was increased
	SUCCESS! Correct handCount
	SUCCESS! Correct deckCount
	SUCCESS! Correct discardCount
	SUCCESS! Correct discardCount for player 2

test: playCouncil_Room
results:
	SUCCESS! Correct handCount
	SUCCESS! Correct card discarded
	SUCCESS! Correct deckCount

Bugs:
	-playAdventurer does not end with the correct number of cards in the players hand.



*/