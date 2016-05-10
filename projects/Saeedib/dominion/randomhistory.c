//-Behnam Saeedi
//-Saeedib
//-Assignment 4
/*

- The makefile rule is: make randomtest
- The file randomResults.c contains all the details about the output and coverage tests

For generating the test we looked at the properties of the two cards:
Smithy:
	This car should return a value as its price and also it needs to make certain changes to deck of cards
This changes could be monitored and tracked in order to assure that the code runs properly.

Adventurer
	This card similarly, affect the deck in a specific way. Those changes could be tracked and monitored
in order to assure that the code runs properly. 

The random test generates series of random values as player, card number and gold, silver and copper cards.
The random test then checks and outputs the values and what is expected to be outputed.

Cards selected for this test are Adventurer and Smithy

The random test will pick random hands and try to aswsign random gold values to it. Then the values for the gold is checked and if they match what was expected, it passes correct

the results of the test runs are stored at randomtestResult.c

according to last test results, adventurer with 100% coverage and mannages to return expected values
The smithy coverage in first attempt covers only 21% of the code. However further changes in code increased
that to 100.00%

The smithy card test happens 1000 times each time movingn a random card location in the hand with a
random player and random hand. similarly Adventurer cards do the same and there are 3 assertions that fail
when the value doesnt match.

*/

