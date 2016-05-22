/*
Aaron Sealy
Assignment 5
CS 362
Spring 2016


TEAMMATE1(BEHMERL):

All unit tests passed.
I had to change my card tests to suit the modified code.

Bug #:          1
Title:          Action decrements instead of increments
Function:       Great_Hall
File tested:    dominion.c
Platform:       OSU flip server
Description:    cardtest3.c revealed that the expected value for actions after the card is played
                is 2 less than the expected amount (in failure description for test 3).  It appears
                that the function is decrementing the action value instead of incrementing it.
How to observe the bug:  Running cardtest3.c will find the fault.  More specifically, comparing the
                numActions value of the game state before and after the card function is run will reveal that
                numActions has decremented instead of incremented.
Reproduceable:  Yes
Severity:       High
Priority:       High

Bug #:          2
Title:          Cards not added to hand
Function:       Smithy
File tested:    dominion.c
Platform:       OSU flip server
Description:    cardtest1.c reported that card function failed Test 1, which concerns hand count.  The
                hand count is 3 less than expected.  This indicates that the 3 cards that were supposed to
                be drawn were either never drawn or were drawn and discarded incorrectly.  Bug 3 below reveals
                that it is the latter.
How to Cause it:  Running cardtest1.c will find the fault.  It can also be found by looking at the handCount value
                of the gamestate before and after the card function and then observing that the handCount value is
                not 3 higher as expected.
Reproduceable:  Yes
Severity:       High
Priority:       High

Bug #:          3
Title:          More cards than expected in played card count
Function:       Smithy
File tested:    dominion.c
Platform:       OSU flip server
Description:    cardtest1.c reported that card function failed Test 2, which concerns the played card count.  The
                played card count is two more than expected.  This indicates that some cards were prematurely discarded.
How to Cause it:  Running cardtest1.c will find the fault.  It can also be found by looking at the playedCardCount value
                of the gamestate before and after the card function and then observing that the playedCardCount value is
                2 more than expected.
Reproduceable:  Yes
Severity:       High
Priority:       High

TEAMMATE2(DILLMANM):

All unit tests passed.
I had to change my card tests to suit the modified code.

Every thing except for the adventurer card passed because, according to his refactor.c, Mark fixed the bugs that he introduced
some some time ago.  I requested the old buggy code to test at the beginning of the week, but have not received it as of 5/21/16.
Only the pre-existing bug in adventurer was still there and this was caught by my tests.

Bug #:          1
Title:          Error due to unexpected return value
Function:       Smithy
File tested:    dominion.c
Platform:       OSU flip server
Description:    The following error message is generated in the playSmithy function: "error: ‘true’ undeclared
                (first use in this function) if (state->deckCount[currentPlayer]<3) return true;"
How to Cause it:  Running cardtest1.c will find the fault.
Reproduceable:  Yes
Severity:       High
Priority:       High

Bug #:          2
Title:          Hand searched for coins instead of deck
Function:       Adventurer
File tested:    dominion.c
Platform:       OSU flip server
Description:    cardtest2.c reported that all four of its tests failed.  The values for hand count, coins, deck count, and
                discard count are all off because the function fails to get coins from the deck because it is searching for
                coins in the hand instead
How to Cause it:  Running cardtest2.c will find the fault.  It can also be found by examining the values for hand count
                , coins, deck count and discard count before and after the function is called, when there are already coins
                in the hand.
Reproduceable:  Yes
Severity:       High
Priority:       High

*/
