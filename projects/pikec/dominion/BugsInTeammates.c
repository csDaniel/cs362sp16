/********************************
** filename:BugsInTeammates.c
** author: Candis Pike
** date: April 16, 2016
** description: bug report for teams refactored code
***********************************/
***************Refactoring of card tests*************************
I had discovered a bug with the adventurer card test when coding the random tests. The card test was originally 
looking for coin cards in the playcard pile and not the discard pile. This has been fixed. Also created a deck that had only 2 coin cards and the rest non to
catch a refactored bug where non coin cards were not being discarded properly.

There was an issue with the vilage test. Before refactoring the test was checking for 1 additional card in the hand without taking
into account that village is to be discarded ie. it was checking that post hand count was 1 greater then pre when in truth there is no net change. 
Also, looked at deck change instead of hand count change.

There was a serious error in cutpurse that had to be refactored. The card is designed to take 1 copper coin card and not all. The
original code was looking for all copper coin cards being removed.

Refactoring the tests
No change in coverage with Smithy.
No change in coverage with Adventurer
Slight decrease in coverage with Cutpurse.
No change in coverage with Village.

Overall the unit test codes was easily maintainable. The majority of refactoring was a result of logic errors on my part.

-----------------------Bug report for hueymi--------------------------------------------------------------------
*****Smithy Card*******
Total Bugs:2

Bug #S1
Severity: Effects game play
Description: Currentplayer is not receiving 3 new cards.

Bug #S2
Severity: Effects game play
Desciption: Smithy is not being discarded. Another card in the hand is being discarded instead.

******Adventurer******
Total Bugs: 3

Bug #A1
Severity: Effects game play
Description: Current player has more cards in hand then intended.

Bug: #A2
Severity: Effects game play
Description: Non coin cards are not being discarded after being drawn. Those cards are remaining in the current players hand.

Bug: #A3
Severity: Effects game play
Description: Adventurer card is not being discarded at the end of play. 

*****Cutpurse*********
Note: test for copper in other players hand. testing for hand reveal requires altering the debug to 1
Total Bugs: 2

Bug: #C1
Severity: effects game play
Description: Other player is keeping copper coin card

Bug: #C2
Severity: effects game play
Description: Coin count is not decreasing by 1 for other player.


-----------------------Bug report for wegnerma--------------------------------------------------------------------
*****Smithy Card*******
Total bugs: 1

Bug: #S1
Severity: Effects game play
Description: Current player is receiving more than 3 new cards. 

*****Adventurer Card*******
Total bugs:3

Bug: #A1
Severity: Effects game play
Description: Current player has less cards in hand then started with. Is not receiving
2 new cards.

Bug: #A2
Severity: Effects game play
Description: Current player has not drawn any cards from his/her deck.

Bug: #A3
Severity: Effects game play
Description: Coin count for current player does not increase as expected with 2 additional
coin cards being drawn.

*****Village Card*******
Total bugs: 2

Bug: #V1
Severity: Effects game play
Description: Current player hand count is less then expected

Bug: #V2
Severity: Effects game play
Description: No cards are drawn from the deck pile. 
