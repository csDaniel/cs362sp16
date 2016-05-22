BugsInTeamates.c

**********************************************************************
Brandon: swansonb

Bug #1
Title: Smithy card fails to leave correct number of cards in player's hand

Class: Game Rules Broken

Date: 5/19/2016
Reported By: Sara Sakamoto
Email: sakamosa@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
After the current player plays the smithy card using the cardEffect()
function, an incorrect number of cards are drawn and retained in the player's hand.


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2. Output contents and size of all players hands
3. call cardEffect() with the gameState, smithy and current player
4. Output and observe new size and contents of all players hands, discard pile and deck.


Expected Results
----------------
The player's deck + discard pile count is reduced by 3.
The player's hand count is increased by 2.


Actual Results
--------------
The players deck + discard count is reduced by 4.
The player's hand count in increased by 3.


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
The resulting card state would suggest that four cards are being drawn from the deck instead of three which could indicate an off by one error while drawing the cards.

==============================

Bug #2
Title: initializeGame function gives players the incorrect number of cards.

Class: Game Rules Broken

Date: 5/19/2016
Reported By: Sara Sakamoto
Email: sakamosa@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
After the initializeGame function is called for a two person game, the first player (index 0) is given 5 cards while player two (index 1) is given 10.


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2. Output contents and size of all players hands


Expected Results
----------------
All player's should have 10 cards to begin the game.


Actual Results
--------------
The current player is given 5 cards while the other players are given 10.


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
N/A


************************************************************************

Alisha: crawleya
Bug #3
Title: Adventurer card leaves incorrect number of cards in player's hand and deck.

Class: Game Rules Broken
Date: 5/19/2016
Reported By: Sara Sakamoto
Email: sakamosa@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
After the adventurer is called using cardEffect, the player's hand count has more cards than expected and the treasure cards were not correctly added.


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2. Output contents and size of all players hands
3. Call cardEffect with the adventurerer card and the initialized game
4. Output the contents and size of all players hands


Expected Results
----------------
The current player's deck count should be reduced by 3.
The current player's hand count should increase by 1.
The current player's discard count should increase by 1.
The number of treasure cards in the player;s hand should increase by 2.



Actual Results
--------------
The current player's deck count is reduced by 4.
The current player's hand count increases by 4.
The current player's discard count should did not increase.
The number of treasure cards increased by 3.


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
There may be two problems contriuting to these results. It appears that the incorrect number of treasure cards are drawn and that the adventurer card is not discarded.


Bug #4
Title: initializeGame function gives players the incorrect number of cards.

Class: Game Rules Broken

Date: 5/19/2016
Reported By: Sara Sakamoto
Email: sakamosa@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
After the initializeGame function is called for a two person game, the first player (index 0) is given 5 cards while player two (index 1) is given 10.


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2. Output contents and size of all players hands


Expected Results
----------------
All player's should have 10 cards to begin the game.


Actual Results
--------------
The current player is given 5 cards while the other players are given 10.


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
N/A
