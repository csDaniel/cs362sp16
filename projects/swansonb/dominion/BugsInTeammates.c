/*

 Brandon Swanson
 Assignment 5  CS - 362

 Process of finding bugs in teammates code:
 For sakamosa I was able to run my unit tests and the card tests and random tests for adventurer and smithy.
 I had to update my function calls to match the function signatures for playAdventurer and playSmithy because their
 implementation included the current player as a parameter.
 for crawleya I also had to modify my function signatures to add the current player parameter.  Also they wrote their
 tests to call the cardEffect function and therefore did not have the card functions exposed in the header.  I think
 It is better to run the test by calling the function directly to isolate the causes of bugs.  So I added their
 functions to the header and updated my tests to match the function names and signatures.  We implemented the same
 cards so I was able to run all 10 of my tests (4 unit tests, 4 card tests, 2 random tests)

 Bugs in crawleya's implementations:
 the doCouncilRoom card tests failed in every instance on the two tests that checked if the player had 4 new cards
 in their hand and (council room discarded and hand count increased by 3) and another test that checked that the other
 players had drawn 1 card from their draw piles.
 I ran GDB and examined the game state struct before and after the function ran, and it showed that the current player
 in fact drew 5 new cards and the other players did not draw a card.  looking at the source this is a problem with the
 if statement was meant to exclude the current player from the draw 1 each loop but instead exclusively included the
 current player.

 I found a bugs in the doAdventurer function discovered by the failed tests:
 Player's hand has 2 new coin cards (FAILED)
 Investigating further it turned out that in fact the hand did have two new coin cards but the tests failed because it
 depended on the played card also being discarded.  after using this test to find bugs I think it would be better if
 there were a separate test for discarding the played card and these two tests did not depend on properly discarding the
 played card.  Checking for properly drawing 2 new treasure cards in my unit test checked that there was 1 card more
 in the players hand and the new cards were treasure cards.  In the future I will avoid combined conditionals when
 possible in unit tests.


 Bugs in sakamosa's implementations:

 I found 2 bugs in playAdventurer
 The other bug was discovered in the random tests, that uncovered in my own implementation that the function would
 infinitely loop if there were 0 treasure cards available in the


 Bugs filed with teammates

==============================
Teammate: crawleya

Bug #1
Title:

Class:

Date: 5/19/2016
Reported By: Brandon Swanson
Email: swansonb@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2.


Expected Results
----------------


Actual Results
--------------


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------




==============================
Teammate: crawleya

Bug #2
Title:

Class:

Date: 5/19/2016
Reported By: Brandon Swanson
Email: swansonb@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2.


Expected Results
----------------


Actual Results
--------------


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------




==============================
Teammate: sakamosa

Bug #3
Title:

Class:

Date: 5/19/2016
Reported By: Brandon Swanson
Email: swansonb@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========


Steps to Produce/Reproduce
--------------------------
1. Initialize a 2-player game.
2.


Expected Results
----------------



Actual Results
--------------



Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------



==============================
Teammate: sakamosa

Bug #4
Title:

Class:

Date: 5/19/2016
Reported By: Brandon Swanson
Email: swansonb@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========


Steps to Produce/Reproduce
--------------------------
1. Initialize a 2-player game.
2.


Expected Results
----------------



Actual Results
--------------



Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------




 */