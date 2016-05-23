/*
David DeRisi
CS362 - 400
Assignment 5
BugFixes.c
5/17/2016


Adventurer Card:  For this function, a bug was introduced that changed the way an empty deck was handled
upon playing the card.  state->deckCount[currentPlayer] < 1 was changed to state->deckCount[currentPlayer] > 1.

This error was corrected and the dominion.c file was updated.

Smithy:  For this function a bug was introduced earlier in the quarter where the loop counter
at line 1298 was altered from three to four, which resulted in an extra card being drawn for 
the player who executed the card play.


Brief thoughts on coverage
High coverage is generally seen as a good thing.  Throughout the 
course it has been reiterated numerous times that the goal
of testing is to be as thorough as possible as this makes fixing
bugs easier and more efficient.  However, there are no absolutes, and
no test suite is truly 100% effective as bugs do slip by, and no tester
is omnipotent.  Despite the fact that tests I wrote yielded a very high degree
of coverage, bugs outside of the tested functions still linger, in this case
a bug in the auxiliary discardCard function, a function not directly tested,
contains a bug where discard behavior does not perform accordingly.  
Although testing code does provide peace of mind when evaluating code, 
perspective is circumstantial, a tester or test suite simply may not 
embrace all perspectives necessary to test for every bug that may exist in a given
piece of code.



*/