Summary:

Unit tests, card tests, and random tests were ran against my teammates: Hong Lin and Jordan White's 
implementation of Dominion. I refactored cardtest3.c to adapt to the card selection "council_room."  
Other cardtests were compatible with Hong's selection of modifications. Jordan's modification to
Dominion were 4/5 cards similar to mine, therefore, I was able to trace bugs using the unit test,
card tests, and random tests that I've developed over the past weeks. The following are the four
bugs I found in Hong and Jordan's implementation and they have been reported to them.


Bug Reports:

Noverse Bug Reporting Template
==============================
Bugs found and reported in Hong Lin's Implmenetation
==============================
Bug 1
==============================
Title:   	 Incorrect number of cards drawn when playing Smithy card 

Class:		 Game Rule
e.g. "Feature Request", "System Error", "Serious Bug"

Date: 		 May 18, 2016
Reported By: Patrick Ho
Email:     	 hop@oregonstate.edu 


Product:     Dominion
Platform:    Linux
Browser:     N/A
URL:       	 N/A 

Is it reproducible: Yes 

Description
===========
The action of the smithy card has the ability to increase your hand by 3 cards. Current implementation will only increase your hand by 2 cards.


Steps to Produce/Reproduce
--------------------------
Initialize the game with the following kingdom cards: adventurer, baron, gardens, feast, ambassador, remodel, great_hall, minion, sea_hag, treasure_map and
provide the intialize function with a seed of 1001.
Play the card by invoking this function: cardEffect(smithy, 0, 0, 0, &state, 0, NULL);  


Expected Results
----------------
Expect 7 cards when checking value of state.handCount[state.whoseTurn].


Actual Results
--------------
After reproducing the bug, the value in state.handCount[state.whoseTurn] is 6.


Workarounds
-----------
Invoke drawCard(state.whoseTur, &state) to draw one card and complete the action to be taken by smithy.

Attachments
-----------
None.


Other Information
-----------------
None.

==============================
Bug 2
==============================
Title:   	 Council room card draws an extra card for the current player when it's only suppose to be drawn for other players.

Class:		 Game Rule
e.g. "Feature Request", "System Error", "Serious Bug"

Date: 		 May 18, 2016
Reported By: Patrick Ho
Email:     	 hop@oregonstate.edu 


Product:     Dominion
Platform:    Linux
Browser:     N/A
URL:       	 N/A 

Is it reproducible: Yes 

Description
===========
The action of the council room card adds 4 cards to the current player's hand and all other player adds one. Current implementation will add 4 cards to current player's hand, but also draw an extra one under for the current player under the premise of "draw one for all other players."


Steps to Produce/Reproduce
--------------------------
Initialize the game with the following kingdom cards: council_room, adventurer, gardens, mine, ambassador, remodel, great_hall, minion, sea_hag, outpost and
provide the intialize function with a seed of 1000.
Play the card by invoking this function: cardEffect(council_room, 0, 0, 0, &state, 0, NULL);  


Expected Results
----------------
Expect 8 cards when checking value of state.handCount[state.whoseTurn].


Actual Results
--------------
After reproducing the bug, the value in state.handCount[state.whoseTurn] is 9.


Workarounds
-----------
None.

Attachments
-----------
None.


Other Information
-----------------
None.

==============================
Bugs found and reported in Jordan White's Implementation
==============================
Bug 1
==============================
Title:   	 Playing the smithy card will draw an extra card from pile.

Class:		 Game Rule
e.g. "Feature Request", "System Error", "Serious Bug"

Date: 		 May 19, 2016
Reported By: Patrick Ho
Email:     	 hop@oregonstate.edu 


Product:     Dominion
Platform:    Linux
Browser:     N/A
URL:       	 N/A 

Is it reproducible: Yes 

Description
===========
The action of the smithy card has the ability to increase your hand by 3 cards. While the current player's hand will increase by 3 cards, an extra card is being drawn from the pile. This is likely due to a missing break statement after the smithyEffect() invocation in cardEffect's switch statement.


Steps to Produce/Reproduce
--------------------------
Initialize the game with the following kingdom cards: adventurer, baron, gardens, feast, ambassador, remodel, great_hall, minion, sea_hag, treasure_map and provide the intialize function with a seed of 1001.
Play the card by invoking this function: cardEffect(smithy, 0, 0, 0, &state, 0, NULL);  


Expected Results
----------------
Expect 7 cards when checking value of state.handCount[state.whoseTurn] and 2 cards when checking value of state.deckCount[state.whoseTurn].


Actual Results
--------------
After reproducing the bug, the value in state.handCount[state.whoseTurn] is 7 and the value in state.deckCount[state.whoseTurn] is 1..


Workarounds
-----------
None.

Attachments
-----------
None.
