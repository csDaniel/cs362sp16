Bug my Teammates Found in My Code

************************************************************************
Alisha: crawleya

#1: Problem in cardEffect function whe adventurer card is played.

Summary: When the adventurer card is passed to the cardEffect function, inaccuracies are found in the resulting game state.

	Bug 1A: The current player's deck count was reduced by 4 and not by 3 as expected.

	Bug 1B: The current player's hand count increases by 4 and not by 1 as expected. We would expect to see an increase of 2 from three 	cards drawn, less one for the discarded adventurer card.

	Bug1C: An incorrect number of treasure cards were added to the player's hand. We would expect 2 new cards, but there are 3.

	Bug1D: The number of cards in the current player's discard pile did not increase. We would expect to see an increase of 1 from the discarding of the adeventurer card, but it remained 0.

	A, B, C and D point to two separate but related problems. It appears that the number of treasure cards drawn is incorrect. It also appears that no card is discarded.


#2: Problem in initializeGame function.

Summary: There is an apparent error in the initializeGame function that gives the players an incorrect number of cards.

	After the initilizeGame function is called to initialize a two player game, the first player (index 0) is given 5 cards while the second player is given 10.

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
==============================
