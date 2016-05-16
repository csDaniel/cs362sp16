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
	updateCoins function passes all tests--all treasure cards are functioning correctly.

	shuffle function works correctly, but Player 1 and Player 2's decks appear to be identical.  I noticed the same result
	when I ran this unit test on my own dominion code earlier in the class.  If this is the result of a bug, it's a bug in the
	original Dominion code, not a bug that my teammate introduced.

	isGameOver function passes all tests.

	numHandCards passes all tests for both Player 1 and Player 2.

	Smithy card:
		does not add 3 cards to player 1's current hand. Other tests (check if the card affected Player 2, and check if it affected
		the supply cards) pass. 
		
	Adventurer card:
		Player 1 either did not discard a card, or the discarded card was placed somewhere besides the discard pile.  All other Adventurer
		tests pass.
		
	Village card:
		None of the tests pass.  Player 1's hand count is off by 1, and the deck count is off by 2.  Player 1's actions are off--should 
		increase by 2, but appear to decrease instead.
		
	Steward card:
		Choices 1 and 2 (player receives 2 new cards or 2 coins) pass.  Choice 3 (player trashes 2 cards) appears to function correctly,
		but seems to trash 3 cards instead of 2.

		
---Randomtestcard results---:
	The Smithy card tests returned incorrect counts for the hand, deck, and discount.


---Randomtestadventurer results---:

		
	
	
	
		
	






-------------------------------------------------
Bugs Found, Teammate 2 - Dane Schoonover/schoonod
-------------------------------------------------

---Unit and card test results---: 

---Randomtestcard results---:

---Randomtestadventurer results---: