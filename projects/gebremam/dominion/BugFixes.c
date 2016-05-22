/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 5
 * Description:	Discuss how bugs (either found by my teammates or introduced
 * 				by me) were fixed
 * -----------------------------------------------------------------------
 */

/*
Bugs Identified by Teammate1: rechstee
--------------------------------------
BUG 1 Description:	At least in the Smithy functions no cards are never discarded (should be 1). 
					This doesn't work with my test case due to the fact that in my dominion the max is only 7 like in the online game. 
					May not be needed to change.
BUG 2 Description: In the Great Hall function no actions are added to the player.


Bugs Identified by Teammate2: Bamesbem
---------------------------------------
BUG3 Description: Adventurer card fails to discard necessary cards
BUG (Same as BUG1 ABOVE) Description: Smithy card draws too many cards
 
 
Bugs introduced by me and not already identifed by teammates
-------------------------------------------------------------
BUG4 Description: in councilRoomRefactored function, current player draws a card instead of others 

Bugs Founds that were not identified by my teammates or introduced by me
------------------------------------------------------------------------
Bug5 Description:


BUG FIXES
-----------------
BUG1: Fixed by making for loop inside smithyRefactored iterate from  from i=0 to i<3 instead of i=0 to i<=3
	Code Changes: Replaced for (i = 0; i <= 3; i++) with  currentPlayer ) with for (i = 0; i < 3; i++)

BUG2: Fixed by adding incrementation of numAction  in great_hallRefactored function
	Code Changes: added state->numActions++

BUG 3: Fixed by adding incrementation of z in else statement of adventurerRefactored fuction 
	Code Changes: added z++ in else statement

BUG4: Fixed by making others draw a card instead of the current player
	Code Changes: replaced if ( i == currentPlayer ) with if ( i != currentPlayer ) in for loop

BUG5: Fixed by making sure for loop inside isGameOver function iterates through all supply piles
	Code Changes: replaced for (i = 0; i < 25; i++) with for (i = 0; i < 27; i++)

*/
