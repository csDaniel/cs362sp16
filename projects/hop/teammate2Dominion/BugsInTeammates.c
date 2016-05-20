Noverse Bug Reporting Template
==============================

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

Other Information
-----------------
None.

==============================
Bug 2
==============================
Title:   	 Playing the Smithy card will draw an estate card from the kingdom card pile.

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
The action of the smithy card has the ability to increase your hand by 3 cards. While the current player's hand will increase by 3 cards, two estate cards are being drawn from the kingdom card pile. This is likely due to a missing break statement after the smithyEffect() and villageEffect() invocations in cardEffect's switch statement.

Steps to Produce/Reproduce
--------------------------
Initialize the game with the following kingdom cards: adventurer, baron, gardens, feast, ambassador, remodel, great_hall, minion, sea_hag, treasure_map and provide the intialize function with a seed of 1001.
Play the card by invoking this function: cardEffect(smithy, 0, 0, 0, &state, 0, NULL);  


Expected Results
----------------
Expect 8 cards when checking value of state.supplyCount[estate].


Actual Results
--------------
After reproducing the bug, the value in state.supplyCount[estate] is 6.


Workarounds
-----------
None.

Attachments
-----------
None.

Other Information
-----------------
None.
