/*---------------------------------------
* Brett Irvin
* 5/16/16
* CS362_400 Software Engineering II
* Assignment 5--BugsInTeammates.c
* Reports bugs found in teammates' files 
* for assignment 5
*---------------------------------------*/

------------------------------------------
Bugs Found, Teammate 1 - Alex Balab/balaba
------------------------------------------

---Unit and card test results---: 
	unittest1.c, updateCoins function: 
		passes all tests--all treasure cards are functioning correctly.

	unittest2.c, shuffle function: 
		works correctly, but Player 1 and Player 2's decks appear to be identical.  I noticed the same result when I ran this unit test
		on my own dominion code earlier in the class.  If this is the result of a bug, it's either a bug in the original Dominion code or
		a problem with my unit tester not setting up truly random variables; either way, it's not a bug	that my teammate intentionally introduced.

	unittest3.c, isGameOver function: 
		passes all tests.

	unittest4.c, numHandCards function: 
		passes all tests for both Player 1 and Player 2.

	cardtest1.c, Smithy card:
		does not add 3 cards to player 1's current hand. Other tests (check if the card affected Player 2, and check if it affected
		the supply cards) pass.  This ended up being a false positive.  I had my tester set up to check for +3 cards added to the hand, but it really 
		needs to check for 2 (since we discard the Smithy card after it is played, the net gain is 2 cards).  I corrected my error, and the "bug" went
		away.
			
	cardtest2.c, Adventurer card:
		Player 1 either did not discard a card, or the discarded card was not placed in the discard pile.  My tester only checks
		to see whether the discard pile incremented by 1, which didn't happen in this case.  According to his refactor.c file, my teammate did introduce
		a bug into the discard action, so my tester was correct to flag it.
		
	cardtest3.c, Village card:
		None of the tests pass.  Player 1's hand count is off by 1, and the deck count is off by 2.  Player 1's actions are off--should 
		increase by 2, but appear to decrease instead.  My teammate did not introduce any bugs for the Village card, so 
		
	cardtest4.c, Steward card:
		All of the tests pass.  I thought there might be an error in Choice 3 (player trashes 2 cards) since the count appeared to be off by 1,
		but like before, I forgot to account for removing the card that was played from the current hand.

		
---Random tester results---: 		
	Randomtestcard.c:
		The Smithy random tester returned incorrect counts for the hand and deck counts.  Tests for the supply cards passed with no errors.
		Since this test's results are so far off (hand count was 269, expected 214; deck count was 215, expected 209) and my earlier Smithy 
		unit and card tests passed when I ran them on this same code, I suspect something is wrong with how I'm setting up a game state in the randomtestcard.c
		file.  In this case, the error is probably with my tester instead of with my teammate's code.


	Randomtestadventurer.c:
		The Adventurer card tests returned incorrect counts for the hand and deck counts.  Again, this does not match the error reported by my unit test.
		This time, my results aren't as far off as they were for the randomtestcard test (hand count 1, expected 3; deck count 435, expected 420), but 
		I still think there's something wrong with how I'm setting up my game state. As with the randomtestcard test, I believe the errors I'm seeing here
		are from something incorrect in my random tester, not from an error in my teammate's code. 

		
	
-------------------------------------------------
Bugs Found, Teammate 2 - Dane Schoonover/schoonod
-------------------------------------------------

---Unit and card test results---: 
	unittest1.c, updateCoins function: 
		passes all tests--all treasure cards are functioning correctly.

	unittest2.c, shuffle function: 
		works correctly, but Player 1 and Player 2's decks appear to be identical.  As I mentioned above with my other teammate, I noticed the same result 
		when I ran this unit test on my own dominion code earlier in the class.  If this is the result of a bug, it's either a bug in the original Dominion
		code or a problem with my unit tester not setting up truly random variables; it's not a bug	that my teammate intentionally introduced.

	unittest3.c, isGameOver function: 
		passes all tests.

	unittest4.c, numHandCards function: 
		passes all tests for both Player 1 and Player 2.

	cardtest1.c, Smithy card:
		The hand count is incorrect; the Smithy card is allowing the player to draw more than 3 cards.  
		
	cardtest2.c, Adventurer card:
		Player 1 either did not discard a card, or the discarded card did not go into the discard pile.  My tester only checks to see whether the discard pile
		incremented by 1, which didn't happen in this case.  This does not match what my teammate recorded in refactor.c, so I think my tester might be wrong
		in this case.  According to my teammate, the only bug in Adventurer should be that the user can draw 3 Treasure cards instead of 2.
		
	cardtest3.c, Village card:
		None of the tests pass.  Player 1's hand count is off by 1, and the deck count is off by 2.  Player 1's actions are off--should increase by 2, but 
		appear to decrease instead.  Again, this matches almost exactly what I found when testing teammate 1's code, which cannot be correct.  There is probably
		an error in my tester, since neither teammate reported modifying the Villager card.
		
	cardtest4.c, Steward card:
		passes all tests.
		
---Random tester results---: 		
	Randomtestcard.c:
		The Smithy random tester returned an incorrect hand count.  I expected this, since it matches the earlier error found by cardtest1.	However, I did not 
		expect to see a deck count mismatch, meaning that either the cardtest missed the bug, or that my random tester is incorrectly reporting an error.  
		Furthermore, I'm seeing the same pattern that I saw when I used the random tester on teammate 1's code:  the hand count is off by more than 50, while
		the deck count is off by 5 or 6 cards.  There's no way both teammates' code just happened to produce similar bugs where there shouldn't be any at all.
		The bug here is somewhere in my random tester, not in my teammate's code.


	Randomtestadventurer.c:
		My randomtestadventurer and randomtestcard files were set up very similarly, so after finding a strange error with randomtestcard.c, I wondered if I 
		wouldn't find the same thing with the randomtestadventurer tester.  As I expected, this tester returned incorrect hand and deck counts, just like it 
		did when I ran it on teammate 1's dominion code.  Even the numbers were very similar to the earlier test, so there's clearly something wrong with how 
		the game state is being randomized for this test.  My teammate modified how many Treasure cards the Adventurer card allows, but there should not be any
		errors with the hand count or deck count.  Again, the bugs reported here are from my tester, not from my teammate's code.
		
-------------------------------------------------
Notes about Randomization and Refactoring
-------------------------------------------------
After completing my initial run of tests, I was concerned in several instances that my randomizing function wasn't producing a truly random test environment.  
I spoke with Dane (teammate #2 for this assignment), and he walked me through the way he had approached randomization.  He used <time.h> and srand, while I had 
been using floor(Random), SelectStream and PutSeed.  Since I wasn't sure my own testers were working correctly, I ended up refactoring some of my files to use 
his method of randomization.  

I went back and ran the entire set of tests again for both of my teammates, this time using my old tests with one teammate's code, and using my new ones on my 
other teammate's code.  I ended up getting the same results for both tests, leading me to believe that what I had originally was inefficient, but was still 
producing a sufficiently random environment.  		