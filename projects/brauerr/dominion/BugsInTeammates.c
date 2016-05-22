//bugsinteammates.c
//Assignment 5 testing teammates code for adventurer and smithy
//bugs intentionally introduced

//David code

//Results:

/***cardtest1.c - testing smithy
Failed on test that deck has been decremented by 3
Failed on test that hand has been incremented by 2 (hand has 9 cards)
****/

/***cardtest2.c - testing adventurer
Failed on test that treasure cards are both added to hand - only incremented
coins by 1
failed on test that adventurer was removed from hand and added to played pile
****/

/***randomtestadventurer.c
adventurer to played failed 250 times out of 250
cards to discard failed 56 times out of 250
***/

/***randomtestcard.c (smithy)
decrement deck failed 250 times out of 250
increment hand failed 250 times out of 250
***/

//Bug descriptions

/*** Adventurer
Cards not properly added to discard - possibly due to mishandling
Of case where deck is empty and cards aren't yet drawn

Method discards silver rather than adding them to the deck when drawn
Card not added to played pile at end of resolution of effects 
***/

/*** Smithy
Player ends up drawing an extra card due to loop running until
i <= 3 - one  more card in hand and one less card in deck than
expected, value should be i < 3
***/

//Notes on testing and refactoring:

/***
David's functions were included in the dominion.c source code
they were called from within the original select case block for played crads
so no refactoring was needed - just add makefile and test files and run
from within the copy of his dominion directory
***/

//Raw test results

/***
Testing Adventurer 250 times...
Cards to Discard Passed 194 times
Treasure to Hand Passed 250 times
Adventurer to Played Passed 0 times
Other Player State Passed 250 times
Decrement Actions Passed 250 times
File 'dominion.c'
Lines executed:41.53% of 561
Branches executed:40.53% of 417
Taken at least once:30.22% of 417
Calls executed:28.42% of 95
Creating 'dominion.c.gcov'

Testing cardtest2 for adventurer card
Test should successfully draw zero or one treasure card if that is all in deck and discard
FAIL
Testing that code shuffles once
SUCCESS
Testing that other cards are added to discard
SUCCESS
Testing that treasure cards are added to hand
FAIL - p1Coins: 4, currentCoins: 5
Testing that adventurer removed from hand and added to played pile
FAIL

Testing Smithy 250 times...
Decrement Deck Passed 0 times
Increment Hand Passed 0 times
Other Player State Passed 250 times
Decrement Actions Passed 250 times
File 'dominion.c'
Lines executed:63.99% of 561
Branches executed:66.91% of 417
Taken at least once:53.96% of 417
Calls executed:64.21% of 95
Creating 'dominion.c.gcov'

Testing cardtest1 for smithy
Testing that card won't play with zero actions left
SUCCESS
Testing that deck has been decremented by 3
FAIL
Testing that hand has been incremented by 2
FAIL - hand count 9
Testing that state of other player hasn't changed
SUCCESS
Checking that actions have been decremented
SUCCESS
***/

//Michael code

//Results:

/***cardtest1.c - testing smithy
Failed on test that deck has been decremented by 3
Failed on test that hand has been incremented by 2 (hand has 9 cards)
***/

/***cardtest2.c - testing adventurer
Failed on test that treasure cards are both added to hand - only incremented
coins by 1
failed on test that adventurer was removed from hand and added to played pile
***/

/***randomtestadventurer.c
card to discard failed 32 times out of 250
adventurer to played failed 250 times out of 250
***/

/***randomtestcard.c (smithy)
decrement deck failed 250 times out of 250
increment hand failed 250 times out of 250
***/

//Bug Descriptions

/*** Adventurer
Empty deck test in cardtest 1 and random test fails
Due to bug in if statement where it is shuffling every time the
deck has more than 1 card, should say less than one card

Also does not add card to played deck at end of function
***/

/*** Smithy
Player draws 4 cards instead of 3 - resulting in one more card
than is needed in hand, and one less card than 
expected in deck - loop should only draw until i < 3
***/

//Notes on refactoring

/***
Michaels refactored functions were included separately in the dominion.c code
but then he replaced the original code in the select case statement for played cards
with calls to his new functions - so refactoring was not required
just dropped my makefile and tests into the copy of his directory and all successfully ran
***/

//Raw Output of Tests:

/***
Testing Adventurer 250 times...
Cards to Discard Passed 219 times
Treasure to Hand Passed 250 times
Adventurer to Played Passed 0 times
Other Player State Passed 250 times
Decrement Actions Passed 250 times
File 'dominion.c'
Lines executed:65.43% of 567
Branches executed:66.75% of 415
Taken at least once:54.22% of 415
Calls executed:66.67% of 96
Creating 'dominion.c.gcov'

Testing cardtest2 for adventurer card
Test should successfully draw zero or one treasure card if that is all in deck and discard
FAIL
Testing that code shuffles once
SUCCESS
Testing that other cards are added to discard
SUCCESS
Testing that treasure cards are added to hand
FAIL - p1Coins: 4, currentCoins: 5
Testing that adventurer removed from hand and added to played pile
FAIL

Testing Smithy 250 times...
Decrement Deck Passed 0 times
Increment Hand Passed 0 times
Other Player State Passed 250 times
Decrement Actions Passed 250 times
File 'dominion.c'
Lines executed:65.43% of 567
Branches executed:66.75% of 415
Taken at least once:54.22% of 415
Calls executed:66.67% of 96
Creating 'dominion.c.gcov'

Testing cardtest1 for smithy
Testing that card won't play with zero actions left
SUCCESS
Testing that deck has been decremented by 3
FAIL
Testing that hand has been incremented by 2
FAIL - hand count 9
Testing that state of other player hasn't changed
SUCCESS
Checking that actions have been decremented
SUCCESS
***/