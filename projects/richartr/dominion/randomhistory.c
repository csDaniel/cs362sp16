/***********************************
* Name: Trent Richardson
* Assignment 4 - randomhistory.c
* CS362-400
***********************************/
randomtestadventurer:
File 'dominion.c'
Lines executed:22.95% of 562
Branches executed:20.14% of 417
Taken at least once:18.71% of 417
Calls executed:10.42% of 96
Creating 'dominion.c.gcov'

randomtestcard:
File 'dominion.c'
Lines executed:24.56% of 562
Branches executed:24.22% of 417
Taken at least once:17.27% of 417
Calls executed:11.46% of 96
Creating 'dominion.c.gcov'

Play Adventurer:

Initially, I had a hard time figuring out why nearly all of my tests were failing.  After some thought; however, I realized
that I have an intentional bug in playAdventurer().  This explains why my testing was failing.  To enusure that I was testing
for the correct things, I refactored my code to remove the bug.  With the bug removed, my tests passed.  I then reintroduced
the bug to the assignment.  One thing I did notice is that some of my tests pass, even with the bug.  I have not had a chance to
fully investigate why this is the case, but out of the 5000 iterations, typically 3-5 of the tests are successful.  When I revert
my changes to supress the intentional bug, all tests pass.  There may be a bug in my refactored code or my test that is leading to
this result.

***  These tests will fail, as I have an intentional bug in the playAdventurer() function.  ***

Random Test Card (Great Hall):

I did not previously test the Great Hall card, so I cannot compare the coverage results specific to that function.  However, after
looking over the results, the random test did achieve 100% coverage.  The random test did generate enough test cases to achieve
the desired test coverage.

I used a similar template/outline as previously used in my work (provided in previous assignment module).  In the case of the Great Hall
card, I decided that it would be a straightforward card to use to try and test all possible outcomes.  The card increases the actions
by 1 and adds a card to the player's hand.  It is possible for the test to fail if either the deck or discard piles are empty.  The test
did not seem to catch any bugs; however, it is possible that I may have not tested every case.
