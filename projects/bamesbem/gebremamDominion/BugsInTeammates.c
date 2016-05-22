/*

Michael Bamesberger
CS 362
Assignment 4
BugsInTeammates - gebremam (Martha Gebremariam)

------------------- BUG 1 -------------------------

Description: Adventurer card fails to discard necessary cards

A bug was discovered in the adventurerRefactored() function in the dominion.c file
 
Classification: Minor bug
 
Summary: The while loop in the function fails to discard non-treasure
 cards drawn in the course of the operation of the function. 
 
What's the error: A counter variable, int z, inside the function is not
 incremented as non-treasure cards are drawn.
 
 else{
    temphand[z]=cardDrawn;
    state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	//z++;
 }
 
 Because the variable is not incremented, and therefore stays at zero
 throughout the operation of the function, the second while loop in the function
 is never executed. This while loop is responsible for discarding the non-treasure
 cards. 
 
 Steps to reproduce:
  1. Initialize a test gamestate. Copy contents into second gamestate for comparision.
  2. Call adventurerRefactored() and pass in test gamestate
  3. Compare test gamestate discardCount to the second gamestate. The difference should be
   the number of treasure cards drawn (2) plus the difference in the deck count between the 
two gamestates.
 
 Expected vs Actual results: 
    The discardCount was three less than expected.
 
 Additional testing information:
  A fourth test was added to my cardtest2.c to discover this bug. My previous tests
  did not test for the discard discrepancies.
 
 -------------------- BUG 2 --------------------------
 
 Description: Smithy card draws too many cards
 
 A bug was discovered in the smithyRefactored() function in the dominion.c file
 
 Classification: Minor bug
 
 Summary: The for loop in the function operates one too many times, resulting in one
 too many cards drawn.
 
 What's the error: The for loop currently reads this: for (i=0; i <= 3; i++), which causes
 the contents of the loop, which in this case is a call to drawCard, to be executed 4 times,
 instead of 3 times.
 
 Steps to reproduce:
 1. Initialize a test gamestate. Copy contents into second gamestate for comparision.
 2. Call smithyRefactored() and pass in test gamestate
 3. Compare the handCount variable in both gamestates
 
 Expected vs Actual results:
 The gamestate's handCount was expected to be one less than it is.
 

 
 

 
*/