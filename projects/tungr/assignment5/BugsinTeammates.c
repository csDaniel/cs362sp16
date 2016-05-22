/*
	Rosa Tung
	Assignment 5
	BugsinTeammates.c
	CS 362
*/

Teammate 1: Kara Franco

---Testing Smithy Card START---

Initialize Game...
Testing smithy cardEffect function return value...
	PASS
Testing smithy action...
	FAIL
		Player does not receive 3 new cards
		current handCount: 6, previous handCount: 5
	FAIL
		exactly 3 cards not taken from the deck
		current deckCount: 3, previous deckCount: 5
		cards in discard pile: 0
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing Smithy Card COMPLETE---

/*
	So the tests that failed were the ones that tested for the number of cards the player received and the number 
	of cards taken from the deck. It appears that instead of receiving 3 cards the players receives only one card. 
	The discard pile count is also not correct. In Addition, the player supposedly takes 2 cardss instead of 3 cards 
	from their own deck.
*/

---Testing Adventurer Card START---

Initialize Game...
Testing adventurer cardEffect function return value...
	PASS
Testing Adventurer action...
	FAIL
		Player did not receive just 2 cards
		current handCount: 8, previous handCount: 5
	FAIL
		exactly 2 cards not taken from currentPlayers Deck
		current deckCount: 2, previous deckCount: 5
		cards in discard pile: 0
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing Adventurer Card COMPLETE---

/*
	So the tests that failed were the ones that tested for the number of cards the player received and the number 
	of cards taken from the deck. It appears that instead of receiving 2 cards the players receives one extra card. 
	The discard pile count is also not correct. In Addition, the player supposedly takes 3 cardss instead of 2 cards 
	from their own deck.
*/

---Testing great_hall Card START---

Initialize Game...
Testing great_hall cardEffect function return value...
	PASS
Testing great_hall action...
	PASS
		Player received just 1 card
		current handCount: 5, previous handCount: 5
	PASS
		exactly 1 card taken from currentPlayers Deck
		current deckCount: 4, previous deckCount: 5
	FAIL
		exactly 1 card was not taken from currentPlayers Deck
		current actions: 1, previous actions: 1
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing great_hall Card COMPLETE---

/*
	So all tests but one passed. So the unit test that failed is the one testing for the correct number of actions acquired, 
	it seems that no action was taken. It appears that Kara's great hall negates the players number of actions going up so 
	they don't actually get another action like they're supposed to. Upon further review it seems Kara has purposely removed 
	that action. 
*/

Samuel Nelson

---Testing Smithy Card START---

Initialize Game...
Testing smithy cardEffect function return value...
	PASS
Testing smithy action...
	PASS
		Player received 3 new cards
		current handCount: 7, previous handCount: 5
	FAIL
		exactly 3 cards not taken from the deck
		current deckCount: 1, previous deckCount: 5
		cards in discard pile: 0
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing Smithy Card COMPLETE---

/*
	So the tests that failed were the ones that tested for the number of cards the player received, and the number of cards 
	taken from the deck. For the first test it appears that instead of receiving 3 cards the players receives 2. The discard 
	pile count is also not correct. In Addition, the player supposedly takes 4 cards instead of 3 cards from their own deck.
*/

---Testing Adventurer Card START---

Initialize Game...
Testing adventurer cardEffect function return value...
	FAIL
Testing Adventurer action...
	FAIL
		Player did not receive just 2 cards
		current handCount: 9, previous handCount: 5
	FAIL
		exactly 2 cards not taken from currentPlayers Deck
		current deckCount: 0, previous deckCount: 5
		cards in discard pile: 0
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing Adventurer Card COMPLETE---

/*
	So the tests that failed were the ones that tested for the return value, the number of cards the player received,
	and the number of cards taken from the deck. It appears that instead of returning 0 it returns -1. For the second 
	test it appears that instead of receiving 2 cards the players receives 4. The discard pile count is also not correct. 
	In Addition, the player supposedly takes 5 cards instead of 2 cards from their own deck.
*/