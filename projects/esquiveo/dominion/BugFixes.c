Osbaldo Esquivel
CS 362
Assignment 5
18MAY2016

===========================
     Bug Fixes for My Dominion Code
===========================

-----------------------------
   Bugs found by Jason
-----------------------------


*** Bug Report 1 ***
Title: Multiple card effects applied for one played card.
Classification: Severe (game rules violated, unpredictable behavior)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: Multiple card effects appear to occur when calling cardEffect() to test the effect of a single card, when called for adventurer, council_room, mine, remodel, and smithy cards. I actually found this bug due to excessive running time of the randomtestadventurer.c random testing code; the test had to be aborted.
Reproducible?: Yes.
Steps to Reproduce:
Perform the following steps, or run randomtestadventurer.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure either player to play: adventurer, council_room, mine, remodel, or smithy cards.
3. call cardEffect(), specifying one of the cards mentioned in (2).

Expected Results:
The expectation is for a single card to be played, whichever was chosen.

Actual Results:
Depending on which card is played, multiple card effects will be executed. This manifests itself as multiple cards being played, and accumulation of multiple card effects (e.g. cards added to hand).

Debugging/Fix:
It was necessary for me to fix this bug in order to run some of my tests. The fix is simply to provide a return statement after the call to adventurerPlay(), councilRoomPlay(), minePlay(), remodelPlay(), and smithyPlay() in their respective cases in the cardEffect() switch statement.

Attachments:
randomtestadventurer.c (test for adventurer card effect)



*** Bug Report 2 ***
Title: Incorrect player score calculation.
Classification: Severe (game rules violated, potential buffer overflow/crash)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: For any player whose deck and discard piles contain different numbers of cards when the game ends, the score calculated for that player (may) be erroneous.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run unittest3.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have 1 curse card in his deck and 0 cards in his hand and 0 cards in his discard.
3. call scoreFor() for player 1.

Expected Results:
The expected score is -1 for a single curse card.

Actual Results:
The score calculated by scoreFor() is 0.

Debugging/Fix:
The terminating condition for the "score for deck" for-loop in scoreFor() is incorrect. That loop should terminate based on "i < state->deckCount[player]", NOT based on state->discardCount[player].

Attachments:
unittest3.c (test for scoreFor() function)



*** Bug Report 3 ***
Title: Council Room effect draws too many cards.
Classification: Severe (game rules violated)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: Playing the council_room card results in the player drawing 5 cards into his hand, instead of the expected 4.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run cardtest3.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have a council_room card to play, and at least 5 cards available in his deck + discard.
3. call cardEffect(), playing the council_room card from any handpos.

Expected Results:
The council_room should cause the player to draw 4 cards into his current hand.

Actual Results:
The council_room actually causes the player to draw 5 cards into his current hand.

Debugging/Fix:
The terminating condition for drawing cards in the councilRoomPlay() function is incorrect; the for-loop executes 5 times, where it should only execute 4 times.

Attachments:
cardtest3.c (test for council_room card effect)



*** Bug Report 4 ***
Title: Adventurer card not put in played pile.
Classification: Severe (game rules violated)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: After calling cardEffect() to play the adventurer card, the adventurer card is not added to the pile of played cards.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run randomtestadventurer.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have an adventurer card to play.
3. call cardEffect(), playing the adventurer card from any handpos.

Expected Results:
An adventurer should end up in the played pile after the cardEffect() function called.

Actual Results:
There is no change to the played card pile after calling cardEffect() for the adventurer card.

Debugging/Fix:
The discardCard() function must be called after the adventurer logic has completed. This could be after the call to adventurerPlay() in the cardEffect() function switch-statement, or prior to adventurerPlay() returning.

Attachments:
randomtestadventurer.c (test for adventurer card effect)

------------------------------
   Bugs found by Preston
------------------------------

Bug Report 1
Title: Adventurer card discards inappropriate number of cards
Preston From (fromp@oregonstate.edu)
Date: 5/19/2015

Product: dominion.c
Tested on: Ubuntu 16.04

Description:
Playing the adventurer card results in the player discarding more cards than should be discarded.
Reproducible: Yes
To reproduce:
1. Initialize a game state with random seed of 900 and a hand for player 2 consisting of an adventurer card in the first place and 4 copper cards.
2. Call adventurerPlay with: adventurerPlay(0, &game, 1, 0, temphand, 0).

Expected results: 
4 cards are drawn and 2 (copper) are added to player 2's hand and 2 (estate) are discarded.
Actual results: 
4 cards are drawn and 2 (copper) are added to player 2's hand and 3 (2 estate and 1 curse) are discarded.

Fixing/debugging:
The while for discarding cards appears to be incorrect and reads as below.

while(z >= 0) 

Instead of z >= 0, the loop should continue only while z - 1 >= 0.



Bug Report 2
Title: Adventurer card is not discarded after use
Preston From (fromp@oregonstate.edu)
Date: 5/19/2015

Product: dominion.c
Tested on: Ubuntu 16.04

Description:
The adventurer card is not discarded after it is used.
Reproducible: Yes
To reproduce:
1. Initialize a game state with random seed of 900 and a hand for player 2 consisting of an adventurer card in the first place and 4 copper cards.
2. Call adventurerPlay with: adventurerPlay(0, &game, 1, 0, temphand, 0).

Expected results: 
Adventurer card is added to the played cards pile
Actual results: 
Adventurer card remains in player 2's hand.

Fixing/debugging:
A call to discardCard should be added at the end of the adventurerPlay function as below:
discardCard(0, 1, &compareGame, 0);

-----------------------------------
              Discussion
-----------------------------------

Fixing the bugs that I introduced for Assigment 2 was a bit trivial as I already knew what needed to be fixed so that my code could be run. Jason found bugs that were introduced outside of the Adventurer and Smithy cards and Preston did not find any bugs in the Smithy card, although this was probably due to the fact that the dominion.c file he received already had the fix for that function. I did, however, use GDB to backtrace through assert failures so I could find where some of the bugs were. This proved to be extremely useful as GDB would show where the function had an error and where that function was called in main.