/* Eric Walters -- Assignment 5 */

/* I only have one teammate. Brian Brown has talked with the professor about this
and he said to make sure we mention it in our assignments to avoid getting
penalized. Therefore, I only have tests for the teammate1Dominion directory. */

/* Bug 1 

After running randomtestcard on Brian's code, I was able to identify a bug in his
Smithy function (see randomtestcard.out in teammate1Dominion/dominion). The issue
with the code is that in the smithy_card function the loop is pre-incremented rather
than post. This is causing the discard count to be off. To fix this bug, Brian should
post-increment his loop.


*/

/* Bug 2

After running randomtestadventurer on Brian's code, I was able to identify a bug in the
Adventurer function (see randomtestadventurer.out in teammate1Dominion/dominion). The
adventurer_card function is causing an issue with the number of treasure cards after
playing the card. The issue with the code is that z is initialized to 1 in the function.
To fix this issue, Brian should initialize z to 0 and the treasure count will be 
accurate.


*/