Observations about using my tests on Ben’s and David’s code:
My tests ran on both Ben and David’s code with almost no changes, which means that they are pretty maintainable.  The changes that I had to make were because I had added a trash and trashCount variable to my dominion.c code and I was using these variables in some of my tests.  I had done this because I noticed that discardCard wasn’t trashing cards even if they were marked to be trashed.  I fixed this behavior when I refactored the Feast card for an earlier assignment.  The other fixes that I made were just to fix warnings because of missing prototype functions and extra, unused variables in Ben’s dominion.c code.

When running my tests on their code, I realized that I never tested to see if cards were being trashed instead of discarded (by having the trashFlag set when discardCard() was called).  I only tested to see if cards were being added to the discard pile.  By testing to make sure that cards were being added to the discard pile, I was testing what was supposed to happen when these cards were played and not what could mistakenly happen if the wrong parameter value was used.  This gave me good coverage of the lines of code, but still didn’t test all of the possible game state changes.  Therefore, it could miss bugs in my code and in Ben’s and David’s code.  This is why it is important to keep improving your tests.  They are never perfect and there is always room for improvement.  I did manage to catch a lot of bugs in Ben’s and David’s code (or at least a lot of my tests failed).  I suspect that many of these bugs (failing tests) will be related and I tried to make note of bugs that I thought were related to help Ben and David.



Notes on testing Ben’s code:
-------------------------------------------------------------------------------------
To get Ben’s code working with my tests without errors or warnings, I had to do the following things.
- add prototype functions for Ben’s refactored card functions: myAdventurer, myFeast, myRemodel, mySmithy, myTribute in dominion.h
- delete unused variables in dominion.c
- add trashCount and trash variables to struct gameState in dominion.h
- initialize trashCount in dominion.c

Ben’s Bug Reports:
-------------------------------------------------------------------------------------
Title: Bug1 - Discarded cards not being added to discard pile

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/23/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
Discarded card is not added to discard pile and discardCount is not updated properly in discardCard().


Steps to Produce/Reproduce
--------------------------
Discard a card, check top card in discard pile, check that discardCount has been incremented.


Expected Results
----------------
Discarded card is on top of the discard pile and discardCount has been incremented.


Actual Results
--------------
Discarded card is not in the discard pile and discardCount is not incremented.


=====================================================================================
Title: Bug2 - Smithy not on discard pile after being played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/23/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
Smithy is not added to discard pile and discardCount is not updated properly after Smithy is played.


Steps to Produce/Reproduce
--------------------------
Play Smithy, check top card in discard pile, check that discardCount has been incremented.


Expected Results
----------------
Smithy is on top of the discard pile and discardCount has been incremented.


Actual Results
--------------
Smithy is not in the discard pile and discardCount is not incremented.


Other Information
-----------------
May be related to Bug1.


=====================================================================================
Title: Bug3 - Adventurer hand count not correct after card is played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/23/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
The player’s hand had one extra card after playing Adventurer.


Steps to Produce/Reproduce
--------------------------
Play Adventurer, check hand count, compare to expected hand count.


Expected Results
----------------
Expected 6 cards in hand after Adventurer is played.


Actual Results
--------------
Player had 7 cards in hand after Adventurer was played.


=====================================================================================
Title: Bug4 - Adventurer not on top of discard pile after being played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/23/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
After playing Adventurer, this card should be on top of the discard pile, but it isn’t.


Steps to Produce/Reproduce
--------------------------
Play Adventurer, check top of discard pile.


Expected Results
----------------
Adventurer on top of discard pile.


Actual Results
--------------
Adventurer not on top of discard pile.


Other Information
-----------------
May be related to Bug3 and/or Bug1.


=====================================================================================
Title: Bug5 - All non-treasure revealed cards should be in discard pile under Adventurer.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/23/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
The discard pile didn’t contain the correct cards after playing Adventurer.


Steps to Produce/Reproduce
--------------------------
Play Adventurer with known deck, check discard pile for non-treasure revealed cards starting at the second card from the top.


Expected Results
----------------
All non-treasure revealed cards should be in discard pile under Adventurer (starting second from top) in correct order.


Actual Results
--------------
The discard pile didn’t contain the non-treasure revealed cards.


Other Information
-----------------
May be related to Bug3, Bug4, and/or Bug1.


=====================================================================================
Title: Bug6 - Player drew too few treasure cards when playing Adventurer.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/23/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
The player should draw 2 treasure cards, but they only drew one treasure card when playing Adventurer.


Steps to Produce/Reproduce
--------------------------
Count the treasure cards in player’s hand, play Adventurer, count the treasure cards in player’s hand.


Expected Results
----------------
Expected 2 new treasure cards in player’s hand.


Actual Results
--------------
Player only had one new treasure card.


=====================================================================================
Title: Bug7 - Player didn’t draw enough cards when playing Adventurer.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/23/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
With a known deck, player doesn’t draw enough cards to draw the 2 treasure cards allowed for Adventurer.


Steps to Produce/Reproduce
--------------------------
Use known deck, play Adventurer, check deck to see if the expected cards were drawn.


Expected Results
----------------
Expected 4 cards to be drawn from deck when Adventurer is played.


Actual Results
--------------
Only 2 cards were drawn when Adventurer was played.


Other Information
-----------------
Might be related to Bug6


=====================================================================================
Title: Bug8 - Player should draw cards from his own deck when playing Adventurer.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/23/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
With a known deck, check the treasure cards that are drawn and make sure they match what was expected to be drawn.


Steps to Produce/Reproduce
--------------------------
Use known deck, play Adventurer, compare drawn treasure cards to expected treasure cards.


Expected Results
----------------
Expected player to draw a gold treasure card first and a silver treasure card second.


Actual Results
--------------
Player did not draw a silver treasure card second.


Other Information
-----------------
May be related to Bug6.


*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
**************************************************************************************************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************

Notes on testing David’s code:
-------------------------------------------------------------------------------------
To get David’s code working with my tests without errors or warnings, I had to do the following things.
- add trashCount and trash variables to struct gameState in dominion.h
- initialize trashCount in dominion.c

David’s Bug Reports:
-------------------------------------------------------------------------------------
Title: Bug1 - Discarded cards not being added to discard pile

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
Discarded card is not added to discard pile and discardCount is not updated properly in discardCard().


Steps to Produce/Reproduce
--------------------------
Discard a card, check top card in discard pile, check that discardCount has been incremented.


Expected Results
----------------
Discarded card is on top of the discard pile and discardCount has been incremented.


Actual Results
--------------
Discarded card is not in the discard pile and discardCount is not incremented.


=====================================================================================
Title: Bug2 - Smithy not on discard pile after being played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
Smithy is not added to discard pile and discardCount is not updated properly after Smithy is played.


Steps to Produce/Reproduce
--------------------------
Play Smithy, check top card in discard pile, check that discardCount has been incremented.


Expected Results
----------------
Smithy is on top of the discard pile and discardCount has been incremented.


Actual Results
--------------
Smithy is not in the discard pile and discardCount is not incremented.


Other Information
-----------------
May be related to Bug1.


=====================================================================================
Title: Bug3 - Adventurer hand count not correct after card is played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
The player’s hand had one extra card after playing Adventurer.


Steps to Produce/Reproduce
--------------------------
Play Adventurer, check hand count, compare to expected hand count.


Expected Results
----------------
Expected 6 cards in hand after Adventurer is played.


Actual Results
--------------
Player had 7 cards in hand after Adventurer was played.


=====================================================================================
Title: Bug4 - Adventurer not on top of discard pile after being played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
After playing Adventurer, this card should be on top of the discard pile, but it isn’t.


Steps to Produce/Reproduce
--------------------------
Play Adventurer, check top of discard pile.


Expected Results
----------------
Adventurer on top of discard pile.


Actual Results
--------------
Adventurer not on top of discard pile.


Other Information
-----------------
May be related to Bug2, Bug3 and/or Bug1.


=====================================================================================
Title: Bug5 - All non-treasure revealed cards should be in discard pile under Adventurer.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
The discard pile didn’t contain the correct cards after playing Adventurer.


Steps to Produce/Reproduce
--------------------------
Play Adventurer with known deck, check discard pile for non-treasure revealed cards starting at the second card from the top.


Expected Results
----------------
All non-treasure revealed cards should be in discard pile under Adventurer (starting second from top) in correct order.


Actual Results
--------------
The discard pile didn’t contain the non-treasure revealed cards.


Other Information
-----------------
May be related to Bug2, Bug3, Bug4, and/or Bug1.


=====================================================================================
Title: Bug6 - Player should draw cards from his own deck when playing Adventurer.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
With a known deck, check the treasure cards that are drawn and make sure they match what was expected to be drawn.


Steps to Produce/Reproduce
--------------------------
Use known deck, play Adventurer, compare drawn treasure cards to expected treasure cards.


Expected Results
----------------
Expected player to draw a gold treasure card first and a silver treasure card second.


Actual Results
--------------
Player did not draw a silver treasure card second.


=====================================================================================
Title: Bug7 - Player doesn’t have the correct number of actions after playing Village.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
The player doesn’t receive the expected 2 additional actions when playing Village.


Steps to Produce/Reproduce
--------------------------
Check player’s actions, play Village, check player’s actions and compare new number to previous number.


Expected Results
----------------
Player should receive 2 additional actions.


Actual Results
--------------
Player receives one additional action.


=====================================================================================
Title: Bug8 - Village not on top of discard pile after being played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
After playing Village, this card should be on top of the discard pile, but it isn’t.


Steps to Produce/Reproduce
--------------------------
Play Village, check top of discard pile.


Expected Results
----------------
Village on top of discard pile.


Actual Results
--------------
Village not on top of discard pile.


Other Information
-----------------
May be related to Bug1, Bug2, Bug3, Bug4, and/or Bug5.


=====================================================================================
Title: Bug9 - Council Room not on top of discard pile after being played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
After playing Council Room, this card should be on top of the discard pile, but it isn’t.


Steps to Produce/Reproduce
--------------------------
Play Council Room, check top of discard pile.


Expected Results
----------------
Council Room on top of discard pile.


Actual Results
--------------
Council Room not on top of discard pile.


Other Information
-----------------
May be related to Bug1, Bug2, Bug3, Bug4, Bug5, and/or Bug8.


=====================================================================================
Title: Bug10 - Other player did not draw a card when Council Room was played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
After playing Council Room, other player’s hand should have one additional card and their deck should have one fewer card.


Steps to Produce/Reproduce
--------------------------
Play Council Room, check other player’s hand and deck counts.


Expected Results
----------------
Other player has one additional card in their hand and one less card in their deck.


Actual Results
--------------
Other player’s hand and deck counts were unchanged.


=====================================================================================
Title: Bug11 - Current player drew one extra card when Council Room was played.

Class: Serious Bug

Date: 05/18/2016
Reported By: Kristen Dhuse
Email: dhusek@oregonstate.edu


Product: dominion.c		Version: last modified 04/24/2016
Platform: Version: flip3


Is it reproducible: Yes

Description
===========
After playing Council Room, current player should have 8 cards in his hand, but he has 9 cards.


Steps to Produce/Reproduce
--------------------------
Play Council Room, check current player’s hand count.


Expected Results
----------------
Current player should have 8 cards in his hand.


Actual Results
--------------
Current player has 9 cards in his hand.


Other Information
-----------------
May be related to Bug10.