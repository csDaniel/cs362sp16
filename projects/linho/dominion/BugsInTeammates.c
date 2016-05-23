// CS 362
// Assignment 5 BugsInTeammates.c
// Hong Lin
// bug report of teammates' code

Noverse Bug Reporting Template
============================================================
Teammate: Patrick Ho
==============================

Title:  bug of playSmithy() function

Date:  05/20/2016 
Reported By:  Hong Lin


Is it reproducible: Yes

Description
===========

When play smithy card the playSmithy() is called. The function is expected to
draw 3 cards, but the the actual result is drawing 1 card only.


Steps to Produce/Reproduce
--------------------------
In cardtest1.c, firstly initialize a game state and player cards with 2 players 
numbers a set seed for initialize the game. Then it copy the game  state to a 
test case testGame and give the smithy card to player. After play the game check 
the result by compared to the control state to verify if we get the expected outcomes.


Expected and Actual Results
----------------
----------------- Testing Card: smithy ----------------
checking for +3 cards...
hand count = 5, expected = 7
deck count = 3, expected = 2
...NOT PASSED


============================================================
Teammate: Jordan White
==============================

Title:  bug of villageEffect() function

Date:  05/20/2016 
Reported By:  Hong Lin


Is it reproducible: Yes

Description
===========

When play village card the villageEffect() is called. The function is expected to
+2 actions, but the the actual result is no action is added.


Steps to Produce/Reproduce
--------------------------
In cardtest2.c, firstly initialize a game state and player cards with 2 players 
numbers a set seed for initialize the game. Then it copy the game  state to a 
test case testGame and give the smithy card to player. After play the game check 
the result by compared to the control state to verify if we get the expected outcomes.


Expected and Actual Results
----------------
----------------- Testing Card: village ----------------
Checking for +1 cards...
Hand count = 5, expected = 5
Deck count = 4, expected = 4
...PASSED
Checking for +2 actions...
Actions = 1, expected = 3
...NOT PASSED

