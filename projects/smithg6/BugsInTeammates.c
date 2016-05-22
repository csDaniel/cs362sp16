Grant Smith
CS362 Software Engineering II
Assignment 5 - Bug Report

Bugs for Michael's code:
----------------------------

The main bug found with the unit tests is that the "isGameOver" function is unable to
recognize a corrupted game state. I was able to fix this code by implementing a 
check and correction that would allow the game to end if a corrupted value occurred.
By setting any negative values to zero, it ensured that the dominion code detected
when a value became corrupted and took action to prevent an error.

Here are the results after fixing the unit test bug:

	Testing the isGameOver function
	Game is over, test was successful.
	Test passed, game recognized corrupted state and ended game.
	Test passed on acceptable value, game is not over.
	Lines executed:22.59% of 571
	Branches executed:27.90% of 423
	Taken at least once:17.97% of 423
	Calls executed:8.00% of 100

In addition to this bug, fixing it (and modifying the tests to catch it), resulted
in about a 1% increase in total lines executed in the coverage matrix.

Bug found with card test 1:
  Testing the Adventurer card.

  Adventurer test failed. Not enough treasures drawn.
  File 'dominion.c'
  Lines executed:23.99% of 571
  Branches executed:28.37% of 423
  Taken at least once:18.91% of 423
  Calls executed:8.00% of 100
  Creating 'dominion.c.gcov'

This test confirms that the refactored adventurer card does not actually add any
treasures to the hand. I had to modify the test to be more specific about what was
failing, but then it was clear that the loop to draw treasure is never engaged. First
off, I added a loop to count pre-adventurer treasures, then added some checks and
explicit outputs when the test failed (see below)
  
  Testing the Adventurer card.

  Adventurer test failed.
   gS.handCount[currPlayer] should be: 7, but is 7
   afterCoins should be: 32770,  but is 6
   Incorrect treasure drawn.

  Once I fixed the bug: -------------------------
    Testing the Adventurer card.

    Current player hand count 5
    Adventurer test passed. Treasure total matches.

Next bug uncovered in Smithy code was that the loop entrance was not triggered due
to a backward logical operator. After fixing the bug and updating the test to give
a more verbose gamestate description, here were the results:
  Testing the smithy card
    Before Smithy handCount: 5
    Smithy test passed.
    Hand Total is 7

The total should be 2 more than starting hand, as the smithy card is discarded, and
3 cards are added.

Village card after fix: 

Testing the Village card.
  Before actions: 1
  After actions: 3
  Village card test passed.
  Village action test passed.

The bug in the village card was that the correct number of cards were drawn, but
the loop incrementing actions for the current player terminated too late and
resulted in extra turns being added.
There was a similar solution for the remaining refactored cards, along with the
cardtests that I needed to modify to get the tests to trigger correctly.



Bugs for Jessica's code:
----------------------------