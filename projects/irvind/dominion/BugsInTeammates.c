/*---------------------------------------
* Brett Irvin
* 5/16/16
* CS362_400 Software Engineering II
* Assignment 5--BugsInTeammates.c
* Reports bugs found in teammates' files 
* for assignment 5
*---------------------------------------*/

Testing process:  I used the makefile commands from Assignment 3 and Assignment 4 (make unittestresults.out, make randomtestadventurer.out, 
make randomtestcard.out) to run my unit, card, and random tests on my teammates' code. Even though we didn't really need to run the unit tests
again for this assignment, I went ahead and let them run.  There seems to be an error in the shuffle function.  My unit test for that function,
unittest2.c, flagged an error on both of my teammates' code, as well as my own code.  Since none of us had altered anything in the shuffle function,
it makes me think that maybe the original Dominion code has some bugs, or that something is off in that particular tester I made.


------------------------------------------
Bugs Found, Teammate 1 - Alex Balab/balaba
------------------------------------------

Cards we had in common: Adventurer, Smithy, Village

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
		passes all tests.

	cardtest1.c, Smithy card:
		BUG (false positive): Hand count is incorrect; does not add 3 cards to player 1's current hand. Other tests (check if the card affected Player 2, 
		and check if it affected the supply cards) pass.  This ended up being a false positive.  I had my tester set up to check for +3 cards added to the
		hand, but it really needs to check for 2 (since we discard the Smithy card after it is played, the net gain is 2 cards).  I corrected my error, and
		the "bug" went away.
			
	cardtest2.c, Adventurer card:
		BUG: Player 1 either did not discard a card, or the discarded card was not placed in the discard pile.  My tester checks to see whether the discard
		pile incremented by 1, which didn't happen in this case.  According to his refactor.c file, my teammate did introduce a bug into the discard action,
		so my tester was correct to flag it.
		
	cardtest3.c, Village card:
		BUG (false positive?): I got some weird results with this test (Player 1's hand count is off by 1, deck count is off by 2, and actions are decreasing 
		instead of increasing by 2).  Since my teammate did not refactor the Village card, I knew something was off.  I later realized that my teammate had put this 
		card into a separate playVillageCard function.  I thought I needed to refactor my test, since my tester was set up to access the Village card by calling
		cardEffect and passing in Villager as a parameter.  After looking again at Alex's code again, I didn't need to refactor after all.  He had left code to 
		call the playVillageCard function from within the cardEffect switch statement, so my test still worked as designed.
			**Update: I changed several things around in my test file to try and eliminate the false positive, but was unable to do so. When I tested Dane's code
			I got the same results, even though he too had not touched the Smithy card.  If there is a legitimate bug here, it's somewhere besides the code my 
			teammates refactored, but again, it could very well still be some strange bug in my test program.
		
	cardtest4.c, Steward card:
		This test did not apply, since Alex did not refactor the Steward card. The test returned no errors, which was as expected since the card had not been
		refactored.

		
---Random tester results---: 		
	Randomtestcard.c:
		BUG: The Smithy random tester returned incorrect counts for the hand and deck counts.  Tests for the supply cards passed with no errors.  Alex did 
		refactor the Smithy card to trash an extra card from each hand, so I expected the hand count to be off, but I'm not sure if the hand count should be off 
		by so much (hand count was 269, expected 214). I'm also not sure why my earlier card test didn't find the same bug, so I suspect something is wrong with how 
		I'm setting up a game state in the randomtestcard.c	file.  In this case, the error is probably with my tester instead of with my teammate's code.
			**Update: I ran this test multiple times after completely redoing my code to set up a random game, and still got the same results.


	Randomtestadventurer.c:
		BUG: The Adventurer card tests returned incorrect counts for the hand and deck counts.  Alex did alter the code for discarding cards in the temporary hand
		as they are drawn, and his refactored file is set to discard an additional card each time.  From what I understand, depending on the state of the game, this
		alteration can affect both the hand and deck counts.
			**Update: I also ran this test again after I had changed my code that set up a random game state, and again, still got the same results.
		
	
-------------------------------------------------
Bugs Found, Teammate 2 - Dane Schoonover/schoonod
-------------------------------------------------

Cards we had in common: Adventurer, Smithy

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
		passes all tests.

	cardtest1.c, Smithy card:
		BUG: The hand count is incorrect; the Smithy card is allowing the player to draw more than 3 cards.  This matches what Dane described in his   
		
	cardtest2.c, Adventurer card:
		I thought I might need to refactor my test, since this was a card that Dane separated out into its own function.  However, as with Alex's code earlier,
		Dane left code in the cardEffect function that would call his adventurerCard function, so I did not need to change anything.
		Player 1 either did not discard a card, or the discarded card did not go into the discard pile.  My tester only checks to see whether the discard pile
		incremented by 1, which didn't happen in this case.  This does not match what my teammate recorded in refactor.c, so I think my tester might be wrong
		in this case.  According to my teammate, the only bug in Adventurer should be that the user can draw 3 Treasure cards instead of 2.
		
	cardtest3.c, Village card:
		BUG (false positive?) Dane did not refactor the Village card, but I ran the test anyway.  I ended up with the same errors as I found with Alex's code: 
		Player 1's hand count is off by 1, deck count is off by 2, and actions are decreasing instead of increasing by 2.  If there is a bug here (and it seems 
		like there might be), then it's not something that either of my teammates intentionally altered.
		
	cardtest4.c, Steward card:
		Dane did not refactor the Steward card, but I ran the test--it passes all tests.
		
---Random tester results---: 		
	Randomtestcard.c:
		BUG: The Smithy random tester returned an incorrect hand count.  I expected this, since it matches the earlier error found by cardtest1.  It also fits 
		Dane's refactor, since he allowed the Smithy card to draw an additional card.  I did not expect to see a deck count mismatch, meaning that either the 
		cardtest missed the bug, or that my random tester is incorrectly reporting an error.  Furthermore, I'm seeing the same pattern that I saw when I used 
		the random tester on Alex's code:  the hand count is off by more than 50, while the deck count is off by 5 or 6 cards.  There's no way both teammates'
		code just happened to produce similar bugs where there shouldn't be any at all.	If there really is a bug here, it's not in Dane's code.
			**Update: I ran this test multiple times after completely redoing my code to set up a random game, and still got the same results.  If the bug is 
			in my test code, then it's something other than the random function.


	Randomtestadventurer.c:
		My randomtestadventurer and randomtestcard files were set up very similarly, so after finding a strange error with randomtestcard.c, I wondered if I 
		wouldn't find the same thing with the randomtestadventurer tester.  As I expected, this tester returned incorrect hand and deck counts, just like it 
		did when I ran it on teammate 1's dominion code.  Even the numbers were very similar to the earlier test, so there's clearly something wrong with how 
		the game state is being randomized for this test.  My teammate modified how many Treasure cards the Adventurer card allows, but that shouldn't affect
		the hand or deck counts.
			**Update: I ran this test multiple times after completely redoing my code to set up a random game, and still got the same results.
		
-------------------------------------------------
Notes about Randomization and Refactoring
-------------------------------------------------
After completing my initial run of tests, I was concerned in several instances that my randomizing function wasn't producing a truly random test environment.  
I spoke with Dane (teammate #2 for this assignment), and he walked me through the way he had approached randomization.  He used <time.h> and srand, while I had 
been using floor(Random), SelectStream and PutSeed.  Since I wasn't sure my random testers were working correctly, I ended up refactoring some of my files to use 
his method of randomization.  

I went back and ran the entire set of tests again for both of my teammates, this time using my old tests with one teammate's code, and using my new ones on my 
other teammate's code.  I ended up getting the same results for both tests, leading me to believe that what I had originally was inefficient, but was still 
producing a sufficiently random environment.  		