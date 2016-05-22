/*
Author: Charles Siebert
Date: 5/8/16
Assignment4

file: randomhistory.c

Description: File explaining the coverage made by randomized testing from both
	randomtestcard (Smithy) and randomtestadventurer (Adventurer). Here we will
	describe the benefits of creating test cases that will most likely cover a larger
	set of test cases by randomizing and running multitudes of tests to find different
	combinations of set functions causing failures.

----------------------------------------------------
randomtestcard
----------------------------------------------------

Description: The card that is tested is Smithy, where it simply draws three cards
	to the current player. Testing that is done on this is to randomize the card amounts
	in the deck, hand, and discard pile, and the number of players within the game to
	determine any possible combinatiosn of failures

Testing: In testing, this test case failed all test cases, as per introduced in an earlier
	assignment, the function draws more than three cards, and so every test case failed.
	The same test cases were used in the previous cardtest.c file, where it checked how many
	cards were drawn, how many cards were discarded, and the net amount given to the current
	player.

Test results:
	
randomtestcard.out:

	----------------- START TESTING: Smithy ----------------
	Tests Passed: 0
	Tests Failed: 33788

	----------------- END TESTING: Smithy ----------------
	Function 'main'
	Lines executed:95.00% of 20
	Branches executed:100.00% of 4
	Taken at least once:75.00% of 4
	Calls executed:100.00% of 12

	File 'randomtestcard.c'
	Lines executed:95.00% of 20
	Branches executed:100.00% of 4
	Taken at least once:75.00% of 4
	Calls executed:100.00% of 12
	Creating 'randomtestcard.c.gcov'
	
	---dominion.c:---
	
	Function 'cardSmithy'
	Lines executed:100.00% of 5
	Branches executed:100.00% of 2
	Taken at least once:100.00% of 2
	Calls executed:100.00% of 2
	
	File 'dominion.c'
	Lines executed:19.50% of 559
	Branches executed:17.83% of 415
	Taken at least once:14.46% of 415
	Calls executed:9.47% of 95
	Creating 'dominion.c.gcov'

Analysis:
	The coverage shows that the test was able to 100% cover the Smithy function as randomtests
	ran. While other portions of dominion.c were covered, to compare, drawcards, and discard,
	they overall resulted in a 19.5% line coverage, showing that this was a good test case for
	this specific function. By adding more functions to test, this will increase our ovrall
	line coverage in dominion.
	
	randomtestcard.c has a 95% line coverage, showing that for most of the test cases displayed
	95% of them were executed and tested against the dominion.c code.
	
----------------------------------------------------
randomtestadventurer
----------------------------------------------------

Description: The card that was tested is Adventurer, where when played, the current player
	continuously draws until two treasures were pulled from the deck. The cards that are
	not treasures are stored in a temp hand, and discarded.

Testing: In testing, this card passed a lot of cases, and failed a lot of cases. In the ones
	that failed, that some of the functionality is working, proprotionally, most of it is
	based on the number of passed tests and failed tests. However, to avoid flooding the 
	screen, the print statements were taken out of where the tests failed. THese tests failed
	when treasures were drawn from the deck, yet when compared to how many treasured (determined
	by which cards are copper, silver, and gold) the numbers were off.

Test results:

randomtestadventurer.out:

----------------- START TESTING: Adventurer ----------------
Tests Passed: 2282
Tests Failed: 1814

----------------- END TESTING: Adventurer ----------------

Function 'main'
Lines executed:97.96% of 49
Branches executed:100.00% of 34
Taken at least once:97.06% of 34
Calls executed:100.00% of 15

File 'randomtestadventurer.c'
Lines executed:97.96% of 49
Branches executed:100.00% of 34
Taken at least once:97.06% of 34
Calls executed:100.00% of 15
Creating 'randomtestadventurer.c.gcov'

---dominion.c:---

Function 'cardAdventurer'
Lines executed:100.00% of 17
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 2

File 'dominion.c'
Lines executed:21.47% of 559
Branches executed:19.76% of 415
Taken at least once:17.11% of 415
Calls executed:10.53% of 95
Creating 'dominion.c.gcov'

Analysis: The analysis of this coverage shows that in the randomtestadventurer, in both
dominion and main, 100% of the lines were executed within cardAdcenturer. And with the
large test cases made for this card to determine which cards are treasure, and which aren't
show that there is a discrepency with how the treasures are pulled from the deck.
The test function covers a large amount of lines executed, and dominion.c shows 21.47%
This will change if more cards are tested together with gcov compared to the dominion.c


*/