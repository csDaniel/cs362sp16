Grant Smith
CS362 Software Engineering II
Assignment 5

My first step was to take my unit tests and random testers and drop them into the copied
folders from my teammates. My next step (Cleared with Instructor Aburas) was to move
teammate A's cardtests into teammate B's folder and vice versa, as writing cardtests
is not part of this assignment, but using them is. I had to modify each of the function
calls in the tests to correctly utilize each version of the refactored dominion code, as
there were multiple versions of refactor (cardEffect switch vs direct function).

Next, I did a trial run (without modification of any tests) to see what cropped up. I will
of course move on to modify and craft these tests to the code they are testing, but
I felt that it was good to get a baseline for their performance before I modified anything.

I ran into some issues while trying to run my unit tests on Michaels code. The gamestate
struct was somehow not functioning. Moving on to the random tests, I needed to update
my randomtests to include the right function calls for the modified cards. For some
reason, my gainCard call was not referencing the pointer to the gamestate, causing
a compilation error. After fixing this and some other formatting issues, I was able to
proceed with the unit tests. The results are as follows:

		Testing the getCost functionThis test passed: Return values are appropriate
		This test passed. 
		getCost returned a default value -1 for a card that doesn't exist
		File 'dominion.c'
		Lines executed:16.37% of 568
		Branches executed:22.43% of 419
		Taken at least once:13.37% of 419
		Calls executed:7.00% of 100

		Testing the gainCard functionSuccess! Card total increased!
		Success! Deck total increased!
		File 'dominion.c'
		Lines executed:18.49% of 568
		Branches executed:23.87% of 419
		Taken at least once:14.32% of 419
		Calls executed:8.00% of 100

		Testing the discardCard functionSuccess! Card total decreased!
		Success! Card discarded successfully.
		File 'dominion.c'
		Lines executed:20.60% of 568
		Branches executed:25.30% of 419
		Taken at least once:15.51% of 419
		Calls executed:8.00% of 100

		Testing the isGameOver functionTest failed, game did not recognize corrupted game state.
		Test passed on acceptable value, game is not over.
		File 'dominion.c'
		Lines executed:22.01% of 568
		Branches executed:27.21% of 419
		Taken at least once:16.95% of 419
		Calls executed:8.00% of 100


Bugs found:
I actually found a bug in the way one of my unit tests was running when testing the values
cards. I had modified at some point to test wrong index value for the card array of names,
and corrected this before contiuing to test. Additionally, I modified a unit test that
was testing the wrong value, and therefore passing when it shouldn't. The discardCard
function is working correctly upon testing the trashFlag now.

The main teammate bug found in Micahel's code with the unit tests is that the "isGameOver" 
function is unable to recognize a corrupted game state. I was able to fix this code by
implementing a check and correction that would allow the game to end if a 
corrupted value occurred. By setting any negative values to zero, it ensured that
the test passed when a value became corrupted.

Here are the results after fixing the bug:

	Testing the isGameOver function
	Game is over, test was successful.
	Test passed, game recognized corrupted state and ended game.
	Test passed on acceptable value, game is not over.
	File 'dominion.c'
	Lines executed:22.59% of 571
	Branches executed:27.90% of 423
	Taken at least once:17.97% of 423
	Calls executed:8.00% of 100


The random tests ran just fine after modifying my tests to call Michael's functions with
the right parameters set. As expected, and confirmed by reading Michael's refactor.c
file, the adventurer random test failed everytime due to the check on deck size. The
adventurer card bug introduced by Michael prevents the card from performing the while
loop necessary to pickup any treasure. Random test results and coverage posted below.

		Running test!
		adventurer is present
		Test# 100
		Function Tested: playAdventurerCard(&state);
		Cards in starting hand:
		12, 14, 23, 4, 16, 12, 17, 9,
		Random Seed: 10099
		Failed Item(s):
		Invalid draw from deck.

		Total Tests: 100
		Total Passed: 0
		Total Failed: 100
		File 'dominion.c'
		Lines executed:18.31% of 568
		Branches executed:17.18% of 419
		Taken at least once:14.32% of 419
		Calls executed:8.00% of 100






The coverage amount helped me continue to target further bugs, but has not informed
a significant amount of the testing. With code like this that maintains a constant
state, I've found that some of the more interesting and valuable tests have been
to test the minute functions that modify that state. If this were a much larger code
base, that might not be the best strategy, but it has worked quite well for discovering
a few of the bugs in this pre-provided dominion code. Were I to be tackling this
code without any introduction or understanding, I feel that the coverage values
would be much more useful and inform a great deal of the test design.