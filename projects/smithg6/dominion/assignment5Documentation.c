Grant Smith
CS362 Software Engineering II
Assignment 5

My first step was to take my unit tests and random testers and drop them into the copied
folders from my teammates. My next step (Cleared with Instructor Aburas) was to move
teammate A's cardtests into teammate B's folder and vice versa, as writing cardtests
is not part of this assignment, but using them is. I needed to make sure that I achieved
the maximum coverage possible for their code.

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

As for the randomtestcard (testing village), most likely due to the bug introduced by
Michael regarding the number of actions