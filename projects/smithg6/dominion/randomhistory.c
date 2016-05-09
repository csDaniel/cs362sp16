Grant Smith
CS362 - Software Engineering II
Assignment 4
Testing methodology and discussion

Need to generate random inputs for gamestate items
	a.	Card functions: 
	b.	cardAdventurer – source Lines 1343-1376
		i.	inputs: currentPlayer and gamestate
		ii.	return value 0
		iii.	modifies
			1.	Cards in hand
			2.	cards in deck (possibly add checks for some or all of these values)
			3.	Number of treasures in hand
			4.	Number of discarded cards
			5.	Number of treasure cards in deck
	c.	cardVillage – source Lines 1378-1390
		i.	inputs: currentPlayer, gameState, handpost
		ii.	return value 0
		iii.	modifies:
			1.	all under drawCard
			2.	all under discardCard
			3.	numActions (related to assignment1 bug) line 1384


****NOTE: If a greater number of test runs is desired, both tests have a variable
called "numberOfTests" that can be increased to the user's preference.

ADVENTURER CARD

The random tester for this card will initialize a game state and
populate it with a significant amount of randomized data in order to
gain better coverage within the scope of the entire code. 

Each run, once the gamestate has been generated, the test will count
the treasures remaining in the deck, along with the non-treasure cards.
This value will be stored for later to compare it once the action is complete.
Because there is a bug built into the adventurer card effect function,
this test should detect failure almost all of the time.

The test will call the adventurer card function on the random player's starting hand.
Upon completion, the test will check for two things:

	Total Treasure cards in the deck (should be two less than before adventurer card).
	Total non-treasure cards in the deck (should not be the same value as before).

	RESULTS

	As expected, the tests failed consistently, due to the bug described in refactor.c,
	along with some other unexpected bugs.

	As for coverage, when taking into account this test alone, the coverage was quite good
	for a single test, but could be expanded as well. One way to expand the coverage would
	be to modify the game state in a more specific way, and test other "reaction style"
	card functions during, and/or after playing the Adventurer card. As is though, coverage
	is as follows:
		Lines executed:17.30% of 578
		Branches executed:16.67% of 432
		Taken at least once:14.12% of 432
		Calls executed:7.37% of 95

	The number of tests would not likely increase this, so the amount has been set to 100.


VILLAGE CARD

The random tester for this card will initialize a game state and
populate it with a significant amount of randomized data in order to
gain better coverage within the scope of the entire code. 

Once a gamestate has been generated, we check for the presence of the village
card and record the current state of the game. Two preconditions are taken:
	
	Total cards in hand (should remain the same, due to draw/discard action village card)
	Total actions for current player (should increase by 2, will fail due to refactor.c bug)

	RESULTS

	As expected, the tests fail consistently on the number of actions.

		Lines executed:18.86% of 578
		Branches executed:17.59% of 432
		Taken at least once:13.43% of 432
		Calls executed:9.47% of 95

	For the current coverage by the random testers, this is acceptable.

THOUGHTS

A great way to increase coverage here (as mentioned above) would be to modify
the gamestate further between test checks. The convenient nature of the random
tests written is that a gameState is initialized, and can be customized based on
the desired function to be tested (e.g. If you were testing the smithy card, you
could add checks for deck total and hand total, or testing market you could test
for the amount of player "BUYS" remaining before and after running the tests)




