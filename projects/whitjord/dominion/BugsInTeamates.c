
/*
Bug reports for Smithy card on for linho and hop
Jordan White 5/19/2016
CS362 Assignment 5

The following are bug reports on the "smithy" card. When the smith card is 
played the player draws 3 cards. The end result is that the player should 
have 2 more cards (draws three cards but discards smithy) and 1 less action
(for playing the smithy). 

teammate 1 onid: linho
============================================================================
Description: 

Smithy card only draws two cards when it should draw three

Results of tests:

myAssert Failed: player should now have a handCount +2 (+3 -1) - expected: 10 actual: 9

myAssert Failed: player should now have a handCount +2 (+3 -1) - expected: 10 actual: 9

Steps to reproduce:

Call cardEffect with "smithy" set as the first parameter 

end of bug report
============================================================================

teammate 2 onid: hop
============================================================================
Description: 

Playing smithy card results in the player gaining two actions and 0 cards
when it should gain 2 cards (draw 3 cards and discard smithy) and 0 actions

Results of tests:

myAssert Failed: num actions should not change - expected: 1 actual: 3
myAssert Failed: player should now have a handCount +2 (+3 -1) - expected: 10 actual: 8

yAssert Failed: num actions should not change - expected: 4 actual: 6
myAssert Failed: player should now have a handCount +2 (+3 -1) - expected: 10 actual: 8

Steps to reproduce:

Call cardEffect with "smithy" set as the first parameter

*/
