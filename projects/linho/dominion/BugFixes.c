// CS 362
// Assignment 5 BugFixes.c
// Hong Lin
// bug fix documentation file

============================================================================
Bug 1 from teammate
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

HOW I FIXED IT: in runSmithy():

The bug was caused by the variable i in for loop it +2 cards instead of +3:
//+3 Cards
    for (i = 0; i < 2; i++)
    {
        drawCard(currentPlayer, state);
    }
I have now fixed it by changing the number 2 to 3:
//+3 Cards
    for (i = 0; i < 3; i++)
    {
        drawCard(currentPlayer, state);
    }


============================================================================
Bug 2 from teammate
============================================================================
Title:   	 Council room card draws an extra card for the current player when it's only suppose to be drawn for other players.

Class:		 Game Rule
e.g. "Feature Request", "System Error", "Serious Bug"

Date: 		 May 18, 2016
Reported By: Patrick Ho
Email:     	 hop@oregonstate.edu 


Product:     Dominion
Platform:    Linux
Browser:     N/A
URL:       	 N/A 

Is it reproducible: Yes 

Description
===========
The action of the council room card adds 4 cards to the current player's hand and all other player adds one. Current implementation will add 4 cards to current player's hand, but also draw an extra one under for the current player under the premise of "draw one for all other players."


Steps to Produce/Reproduce
--------------------------
Initialize the game with the following kingdom cards: council_room, adventurer, gardens, mine, ambassador, remodel, great_hall, minion, sea_hag, outpost and
provide the intialize function with a seed of 1000.
Play the card by invoking this function: cardEffect(council_room, 0, 0, 0, &state, 0, NULL);  


Expected Results
----------------
Expect 8 cards when checking value of state.handCount[state.whoseTurn].


Actual Results
--------------
After reproducing the bug, the value in state.handCount[state.whoseTurn] is 9.
============================================================================

HOW I FIXED IT: in runCouncil_room():

The bug was because it +5 cards instead of +4, and in for loop it will draw a 
card when i is current player instead of is not current player:
//+4 Cards
    for (i = 0; i < 5; i++)
    {
        drawCard(currentPlayer, state);
    }
	if ( i == currentPlayer )
	{
        drawCard(i, state);
    }
I have now fixed it by changing the number 5 to 4 and right condition:
//+4 Cards
    for (i = 0; i < 4; i++)
    {
        drawCard(currentPlayer, state);
    }
if ( i != currentPlayer )
	{
        drawCard(i, state);
    }
    

============================================================================
Bug 1 from teammate's code
============================================================================
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
============================================================================

HOW I FIXED IT: in playSmithy():

The bug was because it adds a ";" at the end of the card drawing for loop.
This will only call drawCard() once instead of 3.:
   
   for (i = 0; i < 3; i++);
	  drawCard(currentPlayer, state);

I have now fixed it by adding the correct for loop fomat:

for (i = 0; i < 3; i++){
	  drawCard(currentPlayer, state);
  }

============================================================================
Bug 2 from teammate's code
============================================================================
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
============================================================================

HOW I FIXED IT: in villageEffect():

The bug was caused by the variable +0 actions instead of +2.:

//+2 Actions
  state->numActions = state->numActions;

I have now fixed it by adding the number 2:

  //+2 Actions
  state->numActions = state->numActions + 2;