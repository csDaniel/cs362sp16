Author: Patrick Ho
Assignment 5
Due April 22, 2016
Description: Documentation of fixes to dominion.c based on bug reports and by using GDB.


Files Changed:
   dominion.c

Details:

playAdventurer()

Bug: Changed "while(drawntreasure<2)" to a for loop. The intent is for the loop to exit if drawntreasure > 2, however a bug is introduced. On line: "if (drawntreasure++ > 2) break;", the increment of drawntreasure is post-increment, which means it will not evaluate true at the appropriate instance.

   playSmithy()
Bug: Introduced a bug by adding a ";" at the end of the card drawing for loop.  This will only call drawCard() once instead of 3
Bug: In the call to discardCard(), passing in arguments for handPos and currentPlayer are switched. Another bug.
Bug: In the switch statement, under the case "smithy", did not add a "break" statement after the call to playSmithy(). This is a bug.


   playFeast()
Bug: The for loop control is changed from "for (i=0; i <= state->handCount[currentPlayer]; i++)" to "for(i=0; i < state->handCount[currentPlayer]; ++i)".  The change from post-increment to pre-increment is a cosmetic change and is benign. However, the end loop condition change from "<=" to "<" is a bug. The last hand will not be recovered at the end of this play.
Bug: Changed statement "if (supplyCount(choice1, state) <= 0)" to "if(supplyCount(choice1, state) >= 0)"


playCouncil_Room
Bug: Removed call to "discardCard()" entirely. This is an introduced bug. Card is not placed in the discard pile and the game state is not updated to reflect the play of the council room.
