/*

 Brandon Swanson
 Assignment 5  CS - 362

 Process of finding bugs in teammates code:
 ------------------------------------------
 For sakamosa I was able to run my unit tests and the card tests and random 
 tests for adventurer and smithy. I had to update my function calls to match
 the function signatures for playAdventurer and playSmithy because their 
 implementation included the current player as a parameter. for crawleya I 
 also had to modify my function signatures to add the current player parameter.
 Also they wrote their tests to call the cardEffect function and therefore did
 not have the card functions exposed in the header.  I think It is better to 
 run the test by calling the function directly to isolate the causes of bugs. 
 So I added their functions to the header and updated my tests to match the 
 function names and signatures.  We implemented the same cards so I was able 
 to run all 10 of my tests (4 unit tests, 4 card tests, 2 random tests)

 Bugs in crawleya's implementations:
 -----------------------------------
 the doCouncilRoom card tests failed in every instance on the two tests that
 checked if the player had 4 new cards in their hand and (council room
 discarded and hand count increased by 3) and another test that checked that
 the otherplayers had drawn 1 card from their draw piles. I ran GDB and
 examined the game state struct before and after the function ran, and it
 showed that the current player in fact drew 5 new cards and the other players
 did not draw a card.  looking at the source this is a problem with the if
 statement was meant to exclude the current player from the draw 1 each loop 
 but instead exclusively included the current player.

 I found a bug in the doAdventurer function discovered by the failed tests:
 Player's hand has 2 new coin cards (FAILED)
 Investigating further it turned out that in fact the hand did have two new 
 coin cards but the tests failed because it depended on the played card also 
 being discarded.  after using this test to find bugs I think it would be 
 better if there were a separate test for discarding the played card and these
 two tests did not depend on properly discarding the played card.  Checking 
 for properly drawing 2 new treasure cards in my unit test checked that there
 was 1 card more in the players hand and the new cards were treasure cards. 
 In the future I will avoid combined conditionals when possible in unit tests.


 Bugs in sakamosa's implementations:
 -----------------------------------
 I found 3 bugs in playAdventurer

 The first bug was that instead of the two discovered coin cards being added to
 the players hand they were added to the discard pile for that player. with no
 change to the players hand. The tests that check that two coin cards were 
 added to the players hand and the test that checked if the other drawn cards 
 were added to the players discard pile both failed in every test Looking at 
 the source the error seems to be code that used to be in an else statement for
 placing the drawn card in a temp pile to be discarded instead was inside the 
 if statement causing only the coin cards to be placed in the discard and the 
 other cards to be lost from the game state

 The other bug was discovered in the random tests, that uncovered in my own 
 implementation that the function would infinitely loop if there were 0 
 treasure cards available in the players draw and discard pile combined, but 
 not if there were at least one.  In sakamosa's implementation the function 
 also loops infinitely on anything less than 2 as my running my random tests 
 on her implementation uncovered.

 The final bug is one that was present in the original implementation and is 
 still present in this implementation and that is that the played adventurer 
 card is not discarded.  This was discovered by examining the game state on 
 function enter and exit in GDB and also highlighted by my IDE providing a 
 warning that the variable representing the hand position of the card being 
 played (handPos) was not used in this function.


 Bugs filed with teammates

==============================
Teammate: crawleya

Bug #1
Title: doCouncilRoom fails to draw correct number of cards

Class: Game Rules Broken

Date: 5/19/2016
Reported By: Brandon Swanson
Email: swansonb@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
When a player plays the council room, via the doCouncilRoom() function the
player 1 to many cards afterwards and the other players have failed to draw 
any cards


Steps to Produce/Reproduce
--------------------------
1. Initialize 4 player game
2. Output contents and size of all players hands
3. call doCouncilRoom() with initialized game state and player 1
4. Output and observe new size and contents of all players hands


Expected Results
----------------
councilRoom card is discarded
current player has 1 more buy available
current player has 4 new cards (hand size increased by 3) from their draw pile
other players have 1 new card in their hands from their own decks

Actual Results
--------------
councilRoom card is discarded (success)
current player has 1 more buy available (success)
current player has 5 new cards from their draw pile
other players have not drawn a card


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
This problem seems to be related to the inverted conditional statement 
on line# 695



==============================
Teammate: crawleya

Bug #2
Title: Adventurer card fails to discard played card

Class: Game Rules Broken

Date: 5/19/2016
Reported By: Brandon Swanson
Email: swansonb@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
After the current player plays the adventurer card using the doAdventurer() 
function their handis not changed but cards are removed from their draw/discard
pile.


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2. Output contents and size of all players hands
3. call doAdventurer() with the gameState, and current player
4. Output and observe new size and contents of all players hands


Expected Results
----------------
players hand contains one less adventurer card
the players hand has 2 new coin cards
the total number of cards and contents of their hand/deck/discared/played 
card have remained the same


Actual Results
--------------
players hand contains the same number of adventurer cards (failed)
the players hand has 2 new coin cards
the total number of cards and contents of their hand/deck/discared/played card
have remained the same


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
Title: Adventurer card fails to place treasure cards in players hand

Class: Game Rules Broken

Date: 5/19/2016
Reported By: Brandon Swanson
Email: swansonb@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
After the current player plays the adventurer card using the playAdventurer()
function their hand is not changed but cards are removed from their 
draw/discard pile.


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2. Output contents and size of all players hands
3. call playAdventurer() with the gameState, and current player
4. Output and observe new size and contents of all players hands


Expected Results
----------------
the players hand has 2 new coin cards
the total number of cards and contents of their hand/deck/discared/played card have remained the same


Actual Results
--------------
The players hand size has not increased
the total number of cards in the players hand/deck/discared/played has decreased


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
Calling this function not only fails to draw 2 new coin cards for the player but 
permanantly removes cards from that players pool of cards


==============================
Teammate: sakamosa

Bug #4
Title: Infinite loop in adventurer function when player has less than 2 coin 
cards total in their deck/discard piles 

Class: Causes Program to "freeze"

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
2. set players deck and discard to contain 1 or 0 coin cards
3. Output contents and size of all players hands
4. add verbose output before and after function calls, loop beginings
3. call playAdventurer() with the gameState, and current player
4. observe that program hangs and does not exit draw card loop


Expected Results
----------------
players hand contains one less adventurer card
the players hand has 2 new coin cards
the total number of cards and contents of their hand/deck/discared/played card have remained the same


Actual Results
--------------
Program hangs in playAdventurer function


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
suggested solution is to add a conditional to the while loop that will break 
when the discard and deck size are both 0


==============================
Teammate: sakamosa

Bug #5
Title: Adventurer card fails to discard played card

Class: Game Rules Broken

Date: 5/19/2016
Reported By: Brandon Swanson
Email: swansonb@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
After the current player plays the adventurer card using the doAdventurer() 
function their hand is not changed but cards are removed from their 
draw/discard pile.


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2. Output contents and size of all players hands
3. call doAdventurer() with the gameState, and current player
4. Output and observe new size and contents of all players hands


Expected Results
----------------
players hand contains one less adventurer card
the players hand has 2 new coin cards
the total number of cards and contents of their hand/deck/discared/played card have remained the same


Actual Results
--------------
players hand contains the same number of adventurer cards (failed)
(other eroneous behavior noted on bug #3)


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------


 */