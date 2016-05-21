/******************************************************
Name: Shawn Seibert
Date: 5/20/2016
File: BugFixes.c
*****************************************************/

	Starting with Ellard Gerritsen van der Hoop's bug report, he reported that there was a bug found in my Smithy card,
Adventurer Card and Council Card. Based on the feed back provided, using GDB to step through each line of code, I 
was able to pin point the various bugs. Starting with the Smithy Card, my for loop for drawing a card had an <= sign
instead of just a < symbol. Because of the added equal sign, the player drew an additional card.
	The next bug found deals with the adventurer card. The bug reported that when adventurer is played, it provides an
incorrect amount of cards in the players hand. By stepping through the lines of code using GDB for Adventurer, I was able
to locate the bug in this line cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]]-1; Because the -1
is outside the brackets, it is actually subtracting from the value of cardDrawn and not from the hand. By placing the -1 
inside of state->handCount[currentPlayer]-1] fixed this error.
	The last bug provided by Ellard deals with the Council Card. His bug reported that when the council card is played, the 
player(s) would draw an incorrect amount of cards. Again, by stepping through the code using GDB, I located the error 
within this line of code: for (i = 0; i <= 4; i++){...} ; I found that when this loop is ran, it actually runs 5 times
causing the player to draw 5 cards instead of the required 4. By changing the <= to < , fixed the bug in the card.

	Next, I reviewed the bugs provided by Suyana Lozada. Her report found the same bugs within the Smithy Card, Adventurer Card,
 and Council Room Card. This can be used to confirm that both Ellard and Suyana created tests that found the correct bugs.
 The same fixes would be applied to the Smithy Card, Adventurer Card, and Council Room Card if I did not review Ellards 
 bug report.
 
	After fixing the bugs found by my teammates, I continued to complete the bug fixes the my previous tests had found. Staring
 with the Council Room Card and utilizing GDB, I found that number of buys did not increase. This occured because line 1304
 state->numActions++; increases actions which is not supposed to happen. By changning the numActions++ to numBuys++ fixed this
 bug. 
	The next set of bug fix(s) deals with the minion card. From my card tests, I found two bugs that were causing various issues.
 The first bug was the number of actions did not increase the number by one, but in fact increased the number of buys. The code at 
 line 1326 had state->numBuys++ and when changed to state->numActions++ fixed this bug. The next bug found in the minion card was
 the number of cards drawn was not correct. Using GDB, I found that the for loop at line 1345 had an additional = sign which caused
 the for loop to increment by an additional number. To fix this code, I changed for (i = 0; i <= 4; i++) to for (i = 0; i < 4; i++).
 