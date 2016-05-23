/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 22 May 2016
**
** Program Filename: BugFixes.c
** Description: This is the report file for bugs discovered by my teammates
**				which were either introduced intentionally or accidentally
**				to the domininon source code.
***************************************************************************/

Adventurer Card:
	A. Expected handsize to increase by 1 with two treasures drawn. Instead, handsize decreased by 2.
	B. Expected total number of treasures in player's deck, hand, and discard to stay the same. Instead, it changed.
	C. Unittest found that when 2 treasures were available to be drawn, the wrong card was discarded and the wrong card was added to the played pile.
	D. RandomTest found that the hand (after play) contained the wrong number of cards when the draw pile contained 2 or more treasures.

All of the above bugs can be traced back to an issue with drawing and discarding the treasure cards. This lead me to believe that something within the card drawing phase of the card is incorrect. Upon closer examination, line 53 contains the error:
	(53)	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]];
This line of code does not check the most recently drawn card, but the space in the array past the most recently drawn card (which contains a garbage value), by adjusting the index to be correct we end up with the following line:
	(53)	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
This fix corrects all of the issues regarding drawing the treasure cards, althogh there is still an issue with the discard pile. The discard pile error is corrected by adding the code related to discarding the card from the hand:
	(NEW)	discardCard(handPos, currentPlayer, state, 0);
Once both of these fixes are in place, there are no more bugs detected by the unit or random tests.

Smithy Card:
	A. Expected hand size to increase by 2 after smithy was played. Instead it increased by 3.
	B. Expected deck size to decrease by 3. Instead, decreased by 4.
	
Looking at the above bugs, it can be infered that there is an additional card being drawn during the Smithy card draw phase. Upon inspection of the card drawing code, line 152 contains the error:
	(152)	for (i = 0; i <= 3; i++)	{  /* Draw 3 cards */
	(153)		drawCard(currentPlayer, state);
	(154)	}
The error is due to the '<=' in the for loop with causes the loop to execute 4 times, instead of 3. By chainging this to a simple '<' conditional, the error is corrected.