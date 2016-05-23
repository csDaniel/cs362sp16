/*  * BugsInTeammates.c  */
/*

Bamesbem:


unittest1: Success! All tests passed.
unittest2: Success! All tests passed.
unittest3: Success! All tests passed.
unittest4: Success! All tests passed.

cardtest1:
	Found I had too few arguments for Michael's refactored adventurer case. 
	Changed my call to have the appropriate number of arguments and the correct arguments. 
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus) -> playAdventurer( &testG, thisPlayer, drawnTreasure, cardDrawn,temphand, i)
	Michael called the case in his test, used that as reference and reformatted my own to do the same.
	Not meeting my hand count assertion.

	Bug found in code #1: 
	Michael had accidently set his command in makefile for cardtest1 to use cardtest4.c instead
	of cardtest1.c. This also explains the previous error while trying to run the test. 

cardtest2:
	Too many arguments in playSmithy. Changing the amount of calls.
	playSmithy(&testG, thisPlayer,handpos,i) -> playSmithy(handpos,thisPlayer,&testG);
	Changed function call, stops at the 
	hand count assertion due to a bug in Dominion.

	Bug found in code #2:
	The refactored version of smithy doesn't discard any cards although the player can only hold seven cards in total. 

cardtest3: SUCCESS: Testing complete great hall!

cardtest4: SUCCESS: Testing complete Outpost!

gabremam:


unittest1: Success! All tests passed.
unittest2: Success! All tests passed.
unittest3: Success! All tests passed.
unittest4: Success! All tests passed.

cardtest1:
	Different name for refactored function and argument names passed.
	playAdventurer( &testG, thisPlayer, drawnTreasure, cardDrawn,temphand, i) -> adventurerRefactored(drawnTreasure, &testG, thisPlayer, i, temphand);
	SUCCESS: Testing complete adventuer
cardtest2:
	Different name for refactored function and arguments passed.
	playSmithy(&testG, thisPlayer,handpos,i);smithyRefactored(handpos,thisPlayer, &testG)
	Bug found in code #3:
	Even when the max hand count of 7 is reached there are no discarded cards.
cardtest3:
	
	Martha refactored the great hall function. I called that function over my previous call in that test.
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus)->greatHallRefactored(handpos, thisPlayer, &testG);
	Bug found in code #4:
	After calling the function in the program the assertion of action count was not increased.
	Similar to the previous bug there is no discard. 
cardtest4: SUCCESS: Testing complete Outpost!


*/
//