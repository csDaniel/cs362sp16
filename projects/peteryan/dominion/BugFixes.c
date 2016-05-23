/*
Ryan Peters
05/21/16
CS362
Assignment 5

Function buyCard()
Line 297-301 - I added a check to see if the card was gained. If gainCard() returns -1, buyCard will 
return -1 and print debug statement.  My unit tests showed that buy card works when passed an invalid
card.  gainCard now check if the card is valid and fails if it is not.  butCard() now fails
if gainCard() fails.
 
Function isGameOver()
Line 395 - I changed the if condition to state->supplyCount[province] <= 0.  My unit tests showed that 
if there is a bug where province has a negative amount, game ends will not be triggered.  The changed
will make game ends tigger with any value that is not positive.

Line 402 - I changed the for loop condition to i < treasure_map.  My unit tests showed
the loop was not checking every supply stack to see if it is empty.  The change has the loop checking
all the supply stacks.

Line 404 - I changed the if condition to state->supplyCount[i] <= 0.  I found a similar problem
as with checking the province supply on Line 395.  I made the condition true for all non-positive
numbers.


Function gainCard()
Line 1106-1109 - I added a check to see if the supplyPos is a valid card.  My unit test found that the 
function executes and returns 0 when an invalid card is passed to the function.

Function cardEffect()
Line 672 - I took the call to playAdventurer out of the return statement and put it on its own line.
Using gdb showed calling playAdventurer in the return statement caused the next case (council_room) to 
behave abnormally.  I ran my unit tests and random test and found that this corrected the bugs I found 
for the council_room.

Line 756 - I took the call to playMine out of the return statement and put it on its own line.  This had the 
same problem as line 672.  Using gdb showed this caused remodel to behave as expected, fixing the bug
found by geurraj.

Line 785 - I took the call to playSmithy out of the return statement and put it on its own line.  There 
was the same problem as the adventurer and mine cases.  I ran my unit test and found this fixed the bug
for the village card found by loom.

Line 863 - I took the call to playMinion out of the return statement and put it on its own line.  I made
this change because the abnormall behavior caused by the other refactoring I did.  

Line 949 - I took the call to playAmbassador out of the return statement and put it on its own line.  I made
this change because the abnormall behavior caused by the other refactoring I did.  

Function updateCoins()
loom found a bug in updateCoins.  He said it does not work correctly.  I am not sure what the bug actually is.
I ran my unit test for updateCoins and used gdb, and could not find the bug. 

Line 1178 - I added a check to add the bonus if it is greater than 0.  If the bonus is negative it is ignored.

Function playAdventurer()
Line 1193 - I changed the if statement to state->deckCount[currentPlayer] <1, fixing the bug I introduced.

Line 1192 - I changed the while clause to drawntreasure<2, fixing the bug I introduced.

Line 1197 - I changed cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1], fixing the bug
I introduced.

I ran my test again and used gdb, and found the bug found by guerraj fixed.

Function playSmithy()
Line 1217 - I changed the for loop condition to for (i = 0; i < 3; i++), fixing the bug I introduced.

Line 1223 - I changed the call to discardCard(handPos, currentPlayer, state, 1), fixing the bug I introduced.

Line 1224 - I changed the return to 0, fixing the bug I introduced.

I ran my test again and used gdb, and found the bug found by guerraj fixed.

Function playMine()
Line 1246 - I changed the return to -1, fixing the bug I introduced.

Line 1244 - I changed the if statement to getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2)
fixing the bug I introduced.

Line 1249 - I changed the call to gainCard(choice2, state, 2, currentPlayer), fixing the bug I introduced.

Line 1257 - I changed the if condition to (state->hand[currentPlayer][i] == j), fixing the bug I introduced.

I used gdb to check that the bugs where properly fixed.

Function playMinion()
Line 1276 - I changed the call to discardCard(handPos, currentPlayer, state, 0), fixing the bug I introduced.

Line 1280 - I changed == to =, fixing the bug I introduced.

Line 1298 - I changed the for condition to (i = 0; i < state->numPlayers; i++), fixing the bug I introduced.

Line 1302 - I changed the if condition to ( state->handCount[i] > 4 ), fixing the bug I introduced.

Line 1320 - I changed the return to 0, fixing the bug I introduced.

I used gdb to check that the bugs where properly fixed.

Function playAmbassador()
Line 1327 - I changed the if condition to (choice2 > 2 || choice2 < 0), fixing the bug I introduced.

Line 1332 - I changed the if condition to (choice1 == handPos), fixing the bug I introduced.

Line 1346 - I changed the return to 0, fixing the bug I introduced.

Line 1358 - I changed the if condition to (i != currentPlayer), fixing the bug I introduced.

Line 1374 - I changed the call to discardCard(handPos, currentPlayer, state, 0), fixing the bug I introduced.

Line 1375 - I added break;, fixing the bug I introduced.

I used gdb to check that the bugs where properly fixed.
*/