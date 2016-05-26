/* Eric Walters -- Assignment 5 */

/* I only had one teammate, Brian Brown. I spoke with the professor about this
and he said to test two random peoples' code*/

/* Teammate 1 -- Brian Brown -- browbria */
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


/* Teammate 2 -- Tatsiana Clifton -- cliftota */

/* Bug 1 

After running randomtestcard on Tatsiana's code, I was able to identify a bug in her
Smithy function. The discard and hand count both fail because the for loop is incrementing
one too many times. If the for loop is changed to < instead of <=, the problem will be 
corrected. (randomtestcard.out in teammate2Dominion/dominion)

*/

/* Bug 2 

After running randomtestadventurer on Tatsiana's code, I found an bug in the adventurer
function. The discard and hand counts are off. The logic for shuffling the cards isn't 
correct because it is shuffling any time the deck has more than one card instead of less 
than one. If this is changed to be less than one the problem will be fixed. 
(randomtestadventurer.out in teammate2Dominion/dominion)

*/

