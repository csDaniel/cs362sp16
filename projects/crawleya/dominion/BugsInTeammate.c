Alisha Crawley-Davis
CS 362 Assignment 5
5/19/2016
BugsInTeammates.c

Note that this is modified from the Noverse Bug Reporting Template
==============================
Teammate: sakamosa

Bug #1
Title: Adventurer Card Yields Incorrect Number of Cards in cardEffect() case adventurer (which calls playAdventurer())

Class: Severe - Error in Gameplay

Date: 5/19/2016
Reported By: Alisha Crawley-Davis
Email: crawleya@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
At the conclusion of playing the adventurer card, the wrong number of treasure cards and the wrong number of adventurer cards are in the hand of the current player.


Steps to Produce/Reproduce
--------------------------
1. Initialize a 2-player game.
2. Put 4 cards in first player's hand: adventurer, gold, smithy, copper
3. Put 4 cards in first player's deck: silver, copper, gold, province
4. Put 2 cards in first player's discard: remodel, feast
4. Fill Player 2's hand: gold, gold
5. Fill Player 2's deck: province
6. Fill Player 2's discard: smithy, feast
7. Set turn to Player 1
8. Play adventurer card


Expected Results
----------------
Expected 4 treasure cards in Player 1's hand
Expected 0 adventurer cards in Player 1's hand


Actual Results
--------------
There were 2 treasure cards in Player 1's hand
There was 1 adventurer card in Player 1's hand


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
The incorrect number of adventurer cards likely means that the adventurer card was not discarded correctly (or at all).

The incorrect number of treasure cards could be a problem with the number of cards drawn.

Note that there was no problem with the number of cards in the other player's deck, hand, or discard piles. Also the number of cards overall did not change.


==============================
Teammate: sakamosa

Bug #2
Title: scoreFor() function yields incorrect score

Class: Severe - Error in Gameplay

Date: 5/19/2016
Reported By: Alisha Crawley-Davis
Email: crawleya@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
The expected score at the beginning of the game is incorrect for all players.

Steps to Produce/Reproduce
--------------------------
1. Start a 4 player game
2. Call the scoreFor() function for any player

Expected Results
----------------
Any player should have 3 points


Actual Results
--------------
Players have incorrect number of points


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
There is a problem with the loop when counting the score from the deck. It only goes through the number of cards from the discard pile, as opposed to the number of cards from the deck.


==============================
Teammate: swansonb

Bug #3
Title: Smithy card yields incorrect number of cards in cardEffect() case smithy (which calls playSmithy())

Class: Severe - Error in Gameplay

Date: 5/19/2016
Reported By: Alisha Crawley-Davis
Email: crawleya@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
At the conclusion of playing the smithy card, the wrong number of cards are in the current player's hand


Steps to Produce/Reproduce
--------------------------
1. Initialize 2 player game
2. Put 4 cards in Player 1's hand: smithy, gold, adventurer, copper
3. Put 4 cards in Player 1's deck: silver, copper, embargo, province
4. Put 2 cards in Player 1's discard: remodel, feast
5. Put 2 cards in Player 2's hand: gold, gold
6. Put 1 card in Player 2's deck: province
7. Put 2 cards in Player 2's discard pile: smithy, feast
8. Set turn to Player 1
9. Play smithy card


Expected Results
----------------
There should be 6 cards in Player 1's hand


Actual Results
--------------
There are 7 cards in Player 1's hand


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
There were the correct number of Smithy's in Player 1's hand, indicating a problem with the number of cards drawn (as opposed to a problem with discarding the Smithy).

==============================
Teammate: swansonb

Bug #4
Title: Village card yields incorrect number of cards in cardEffect() case village (which calls playVillage())

Class: Severe - Error in Gameplay

Date: 5/19/2016
Reported By: Alisha Crawley-Davis
Email: crawleya@oregonstate.edu

Product: Dominion                   Version: ?
Platform: Unix                      Version: Flip

Is it reproducible: Yes

Description
===========
At the conclusion of playing the village card, the current player has the wrong number of actions and wrong number of village cards in the hand


Steps to Produce/Reproduce
--------------------------
1. Start 2 player game
2. Put 4 cards in Player 1'a hand: village, gold, adventurer, copper
3. Put 4 cards in Player 1's deck: silver, copper, embargo, province
4. Put 4 cards in Player 1's discard: remodel, feast
5. Fill Player 2's hand: gold, gold
6. Fill Player 2's deck: province
7. Fill Player 2's discard: smithy, feast
8. Set turn to Player 1
9. Set the number of actions (of Player 1) to 3
10. Play village card


Expected Results
----------------
There should be 0 village cards in Player 1's hand.
Player 1 should have 5 actions


Actual Results
--------------
There is 1 village card in Player 1's hand
Player 1 has 3 actions

Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------
In the function playVillage(), the correct number of actions are added to the gamestate of Player 1.
In the function playVillage(), the village card is correctly discarded.
The above results are likely because of an incorrect parameter being passed when playVillage() is called.
