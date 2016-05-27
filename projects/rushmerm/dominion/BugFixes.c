/**************************************************************************************************
* Mark Rushmere
* CS 362
* Assignment 5 
* Description of bugs fixed
**************************************************************************************************/

// Bug found by Saie Kurakula and Rob Stine
// Both reported the bugs in playSmithy() and playAdventurer()

// BUG 1:
// Function: playSmithy()
// Fault: less than or equals sign in for loop.
// Fix: Replaced with less than sign. 


// BUG 2:
// Function: play Adventurer()
// Error: Too many treasure cards drawn

// Fault 1: while loop with condition z >= 0 
// Fix: Repace z with z-1

// Fault 2: z incremented before the drawn card is assigned to the temp hand
// Fix: Increment z after.

// Fault 3: cardDrawn was being assigned the wrong card. The second to last card in the hand was
// assigned instead of the last. This is becuase of state->handCount[thisPlayer]-2
// Fix: Change to state->handCount[thisPlayer]-1


/*******************************************************************************/
// Some bugs that I introduced were not caught by the tests my teammate's and I ran.

// Bugs in my impletmentation of the remodel card playRemodel():

// Fault 1: discardCard() called with handPos + 1.
// Fix: discardCard() called with handPos

// Fault 2: discardCard() called with i + 1 when discarding tashed card
// FIx: discardCard() called with i

// Bugs in my implementation on the mine card playMine():

// Fault 1: choice1 was passed to the gainCard() function
// Fix: choice1 changed to choice2


/********************************************************************************/
// Discussion of Coverage:

// Although the tests that my teammates and I developed did not even come close to 
// covering most of the program, the tests did find faults in the specific functions
// they were designed for. Any bugs in the functions that had test were found by them.




