 
// CS 362
// Assignment 4 randomhistory.c
// Hong Lin


 For randomtestadventurer:

 >>>>> SUCCESS: Testing complete adventurer <<<<<
 >>>>> PASSED: 7702, NOT PASSED: 3302 <<<<<

File 'randomtestadventurer.c'
Lines executed:83.33% of 90
Branches executed:100.00% of 34
Taken at least once:64.71% of 34

File 'dominion.c'
Lines executed:32.47% of 659
Branches executed:36.34% of 421
Taken at least once:24.70% of 421

 For randomtestcard:

 >>>>> SUCCESS: Testing complete village <<<<<
 >>>>> PASSED: 7004, NOT PASSED: 4000 <<<<<

File 'randomtestcard.c'
Lines executed:80.65% of 93
Branches executed:100.00% of 26
Taken at least once:65.38% of 26

File 'dominion.c'
Lines executed:32.47% of 659
Branches executed:36.34% of 421
Taken at least once:24.70% of 421

The random tester for the adventurer card and village card in randomtestadventurer.c
and randomtestcard.c tests for runAdventurer and runVillage in refactored dominion.c.
From the last unit test for adventurer and village, it is easier for me to come up with
the test procedure for this random test for randomtestadventurer and randomtestcard. 
After run the tests, about half of the test cases failed in the test, and the bugs in 
refactored dominion.c caused the result, which is what we expect.

They firstly initialize a game state and player cards with random set player numbers
from 2 to 4 players and a random seed for initialize the game. Then it copy the game
state to a test case testGame and give the target card to player. After play the game
with a specific set of inputs within the range of possible inputs that could be 
encountered during execution, we check the result by compared to the control state to
verify if we get the executed outcomes.

They all found bug successfully. The test get all bugs in every loop and under some extreme
condition the result is right for some of them because the randomly generated paramters happen 
to make the function produce right result. The bugs that I wrote for four Dominion cards from 
the changes in the dominion.c file are all appeared in the random test.
