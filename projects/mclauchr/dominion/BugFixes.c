/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  BugsFixes.c
** Date:  5/15/16
** Due Date: 5/22/16
**
** Description:  This is a text file that will discuss the 
** the process of fixing the bugs that were found in my 
** teammates source code; in addition to my own.
**
** NOTE: BugsInTeammates.c describes only 2 bugs for each 
** teammate.  In some cases, tests revealed more than the 
** required 2 that needed to be reported for assignment #5.
** I will attempt to fix all that were found during testing.
*************************************************************/

//Teammate 1 Reported Bugs - scheibnl 
//1. Smithy Card Adds Additional Card
//2. Adventurer Does not Add +2 Treasure Cards

//Teammate 2 Reported Bugs - vondyk
//1. Smithy Card Adds Addtional Card
//2. Adventurer Does not Add +2 Treasure Cards

//My dominion.c Bug Fixes

/*************************************************************
Bug #1 Fix - Smithy Card Adds too Many Cards

Description:

Reports from teammates and report from own test suite show
that the Smithy card effect is resulting in too many cards
being added to the current player.

Test results show that there is an off by 1 error in terms of
expected handCount and tested handCount after the smithy card
has been played. 

GDB reveals that the for loop calls drawCard 4 times, before 
the smithy card is discarded. Resulting in an overall 
handCount changes of +3 instead of +2.

Modification to Source Code:

Changed the for loop from...
for (i = 0; i <= 3; i++)
to...
for (i = 0; i < 3; i++)
	
Test Results after Change:

*****TEST: cardtest1() - BEGIN *********

Test1: Appropriate Cards Add/Subtract (+3 - 1 = +2) Total: PASS
Test2: Other Players Discard Pile NOT Affected: PASS
Test3: Card Effect for Smithy Returned Successfully: PASS

*****TEST: cardtest1() - END ***********

Discussion of Test Results:

Test 1 has changed from FAIL to PASS.

Coverage:

Function 'smithyFunction'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

Discussion of Coverage:

100% Line and Branch Coverage with my 3 Passing tests make my
confidence that I have fixed the bug strong.

*************************************************************/


/*************************************************************
Bug #2 Fix - Adventurer doesn't grant player +2 Treasure Cards

Description:

Reports from teammates in addition to results from personal
test suite show that the card effect for Adventurer does not
grant +2 treasure cards.  Expected versus tested results show
that there is an off by one error causing the player to add
only 1 additional treasure card.

Using GDB, it was found that the while loop exits after the 
condition of drawntreasure < 1.  This means, no additional
calls to drawCard will be made after a single treasure card
is drawn.

Modification to Source Code:

Changed from...
while(drawntreasure<1)
To...
while(drawntreasure<2)
	
Test Results after Change:

Test1: New Hand Count Should be +1: FAIL
Expected: 6, Tested: 7
Test2: Current Player has +2 Treasure Cards: PASS
Test3: Deck Changes Occurred Only in Current Players Deck: PASS
Test4: Card Effect for Adventurer Returned Successfully: PASS
Test5: Card Effect for Adventurer Returned Successfully when Deck Count = 0: PASS

Discussion Post Fix:

After fixing the while loop, I noticed that the change had
caused a different test failure.  At this point, the players
handCount was +1 greater than it should be.  When looking
through the code, I noticed that the adventurer card effect
discards the non-treasure cards of the temphand that is 
created from the card effect to draw +2 treasure cards.
However, there is no part of the function that will discard
the adventurer card once it has been played.  This is
something that I did not catch in previous assignments.
It seems as though I need to have a call to discardCard()
in order to remove the played adventurer card into the played
card pile.  

NOTE: This was an interesting bug...as I never introduced this
into the adventurer card effect (I was more skeptical)

Modification to Source Code:

Changed from...
nothing.
To...
Added - discardCard(handPos, currentPlayer, state, 0);

Test Results:

*****TEST: cardtest2() - BEGIN *********

Test1: New Hand Count Should be +1: PASS
Test2: Current Player has +2 Treasure Cards: PASS
Test3: Deck Changes Occurred Only in Current Players Deck: PASS
Test4: Card Effect for Adventurer Returned Successfully: PASS
Test5: Card Effect for Adventurer Returned Successfully when Deck Count = 0: PASS

*****TEST: cardtest2() - END ***********

Coverage:

Function 'adventurerFunction'
Lines executed:73.68% of 19
Branches executed:66.67% of 12
Taken at least once:50.00% of 12
Calls executed:100.00% of 3

Discussion of Coverage:

As mentioned in assignment #3, this was my weakest coverage
statistics of all my unit tests.  The fact that I have the
least coverage of all my tests, and that I found a bug that I
did not introduce, makes me feel less confident that I have 
fixed the bug 100%.  More testing would be needed to improve
my level of confidence.
*************************************************************/


/*************************************************************
Bug #3 Fix - Great Hall Doesn't Discard to Played Cards

Description:

Test results have shown that the Great Hall card effect does
not properly handle the discarding of cards.  We expected a 
single card to be discarded to the played card pile, and I 
have shown through my tests that 0 cards are added to the
played card pile.

Through GDB, I see that once the call to discardCard() has been
made; a section of code in the discardCard function is skipped
which increments/adds the cards to the played card pile.  This
is due to the fact that the trashFlag is set to 1.

Modification to Source Code:

Changed From...
discardCard(handPos, currentPlayer, state, 1);
To...
discardCard(handPos, currentPlayer, state, 0);
	
Test Results after Change:

*****TEST: cardtest3() - BEGIN *********

Test1: Players New Hand Count Should be Same(+1-1): PASS
Test1b: + 1 card discarded to played cards: PASS
Test2: Num Actions + 1: PASS
Test3: Other Players Deck Count Remains Unchanged: PASS
Test4: Card Effect for Great_Hall Returned Successfully: PASS

*****TEST: cardtest3() - END ***********

Discussion of Test Results:

Test1b has changed from FAIL to PASS

Coverage:

Function 'great_hallFunction'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

Discussion of Coverage:

100% line and branch coverage and a 100% unit test PASS result
give me higher confidence that my fix was appropriate.
*************************************************************/


/*************************************************************
Bug #4 Fix - Embargo Card Adds less coins than expected to 
			 player state.

Description:

Test results show that there is an off by one error in the 
amount of coins added to the current player's state after
the embargo card is played.

GDB shows that the state.coins is incremented only a single
time in the refactored embargoFunction()

Modification to Source Code:

Changed From...
state->coins++;
To...
state->coins + 2;

Test Results after Change:

*****TEST: cardtest4() - BEGIN *********

Test1: +2 Coins Added to Player State: PASS
Test2: Card is trashed when discarded: FAIL
Played Card Count Expected: 0, Tested: 1
Test3: Embargo Token for Choice1 Increased: PASS
Test4: Other Players Deck Count Remains Unchanged: PASS
Test5: Card Effect for Embargo Returned Successfully: PASS
Test6: Caught Inappropriate Choice 1 Parameter: PASS

*****TEST: cardtest4() - END ***********

Discussion of Test Results:

We see that Test1 has changed from PASS to FAIL.  We still have
a failure with Test2...However, we will deal with that bug 
separately.

Coverage:

Function 'embargoFunction'
Lines executed:100.00% of 7
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 1

Discussion of Coverage:

100% line and branch coverage combined with a passing test of 
a previously failed test case give me confidence that my fix
was appropriate.  However, the fact that a failure still
exists in Test2, makes me cautious of the fix until the other
bug is also addressed. (see below)
*************************************************************/


/*************************************************************
Bug #5 Fix - Embargo Card is not discarded appropriately

Description:

After running my tests, I have shown that Embargo card has not
been handled appropriately when it comes to its discard. 
During our test, we expected our playedCardCount to remain
constant after the card effect.  This is due to the fact that
the embargo card should be trashed after use.  

Using GDB, we see that once the discardCard() function is
called.  A series of lines of code is executed that adds the
card to the played card pile and increments it's count.  This
should not be happening.  

This is caused by the trashFlag being set to 0 instead of 1.

Modification to Source Code:

Changed From...
discardCard(handPos, currentPlayer, state, 0);	
To...
discardCard(handPos, currentPlayer, state, 1);		

Test Results after Change:

*****TEST: cardtest4() - BEGIN *********

Test1: +2 Coins Added to Player State: PASS
Test2: Card is trashed when discarded: PASS
Test3: Embargo Token for Choice1 Increased: PASS
Test4: Other Players Deck Count Remains Unchanged: PASS
Test5: Card Effect for Embargo Returned Successfully: PASS
Test6: Caught Inappropriate Choice 1 Parameter: PASS

*****TEST: cardtest4() - END ***********

Discussion of Test Results:

We see now that Test2 has passed.

Coverage:

Function 'embargoFunction'
Lines executed:100.00% of 7
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 1

Discussion of Coverage:

100% line and branch coverage, a passing unit test, combined
with the fact that Test1 was also fixed in the previous bug
fix, give me high confidence that both bugs found from Test1 
AND Test2 have been fixed appropriately.
*************************************************************/


