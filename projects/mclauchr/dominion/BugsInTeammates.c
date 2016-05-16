/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  BugsInTeammates.c
** Date:  5/15/16
** Due Date: 5/22/16
**
** Description:  This is a text file that will discuss the 
** the bugs that I found in each of my team mates dominion.c
** files when running the tests that I created over the past 
** 2 assignments.
*************************************************************/

//Teammate 1 - scheibnl

/************************************************************
** Bug #1A Title:  Smithy Card Draws an Additional Card
** Reporter: Chris McLaughlin - mclauchr
** Product: dominion.c
** Component: cardEffect() - smithyAction()
** Priority: P3
** Severity: Minor - Give's slight advantage to the user who
** 			 plays the cardEffect

** Description: Each time the smithy card is played an extra
** card is added to the players hand
** 
** Reproduction: In order to produce the bug I used my 
** unit/card test suite.  cardtest1 was able to reproduce the 
** bug.
**
** Test Results: 
**
** Test1: Appropriate Cards Add/Subtract (+3 - 1 = +2) Total: FAIL
** Expected: 7, Test: 8
*************************************************************/

/************************************************************
** Bug #1B Title:  Adventurer Card Produces Error in handCount
** Reporter: Chris McLaughlin - mclauchr
** Product: dominion.c
** Component: cardEffect() - adventurerAction()
** Priority: P3
** Severity: Minor - Give's slight advantage to the user who
** 			 plays the cardEffect

** Description: Each time the adventurer card is played, the 
** player should draw cards until two treasure cards are drawn
** all cards that were not treasure cards are discarded in
** addition to the adventurer card itself.  This should result
** in a +1 handCount for the current player. Tests have 
** revealed that there is an additional card in the player's
** handCount after the adventurer card is played.  
** 
** Reproduction: In order to produce the bug I used my 
** unit/card test suite.  cardtest2 was able to
** reproduce the bug.
**
** Test Results: 
**
** Test1: New Hand Count Should be +1: FAIL
** Expected: 6, Tested: 7
*************************************************************/

//Teammate 2 - vondyk

/************************************************************
** Bug #2A Title:  Smithy Card Draws an Additional Card
** Reporter: Chris McLaughlin - mclauchr
** Product: dominion.c
** Component: cardEffect() - playSmithy()
** Priority: P3
** Severity: Minor - Give's slight advantage to the user who
** 			 plays the cardEffect

** Description: Each time the smithy card is played an extra
** card is added to the players hand
** 
** Reproduction: In order to produce the bug I used my 
** unit/card test suite.  cardtest1 was able to reproduce the 
** bug.  
**
** Test Results: 
**
** Test1: Appropriate Cards Add/Subtract (+3 - 1 = +2) Total: FAIL
** Expected: 7, Test: 8
*************************************************************/

/************************************************************
** Bug #2B Title:  Adventurer Card Produces +2 Treasure Error
** Reporter: Chris McLaughlin - mclauchr
** Product: dominion.c
** Component: cardEffect() - playAdventurer()
** Priority: P3
** Severity: Minor - Give's slight advantage to the user who
** 			 plays the cardEffect

** Description: Each time the adventurer card is played, the 
** player should draw cards until two treasure cards are drawn.
** All tests showed that upon the completion of the cardEffect
** for adventurer, +2 treasure cards were not added to the 
** player's hand.  Results show +0 cards added.
** 
** Reproduction: In order to produce the bug I used my 
** unit/card test suite.  cardtest2 was able to reproduce the 
** bug.  I also was able to use my randomtestadventurer test
** to reveal the same bug.
**
** cardtest2 Results: 
**
** Test2: Current Player has +2 Treasure Cards: FAIL
** Expected: 6, Tested: 4
**
** randomtestadventurer Results:
**
** Example Iteration:
** 
** SubTest2: +2 Current Player Treasure Cards FAILED at Iteration: 995
** Expected: 4, Tested: 2
**
** SubTest 2 - +2 TREASURE Cards for Current Player: 
** Passed: 0, Failed: 1000
*************************************************************/