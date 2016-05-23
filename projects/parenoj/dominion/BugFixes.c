/*************************************************************************************************************************

BUGS FOR FIXING


****Adventurer Card - Bug found in my unit tests as well as by teammate code review. 
	
	The bug in the conditional was introduced in Assignment 2 and found by a teammate's code review. This bug assigned the deckCount to 0 which caused unneeded
	shuffles and messed up card states.
	
	Test Result:
		TESTING that hand count for current player is 1 more than it started at (Gain 2 treasures, but lose adventurer card)
			Hand Count: 5	Expected: 6

	Bad Code:
		if (state->deckCount[currentPlayer] = 0){//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}

	Code changed to:
		if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
	
	This bug was found in my card unit test:
	discardCard was not called in the adventurer card, which caused it to stay in the player's hand. Therefore I added the handPos parameter to the function call and 
	added this line	to the code:
		discardCard(handPos, currentPlayer, state, 0);
		
	Test Result after bug fixes:
		TESTING that hand count for current player is 1 more than it started at (Gain 2 treasures, but lose adventurer card)
			Hand Count: 6   Expected: 6


****Smithy Card - Bug found by teammate's card unit test that was introduced in assignment 2.

	This is a bug with the conditional being "greater than" instead of "less than"
	
	Test Result:
		TESTING that hand count for current player is 2 more than it started at (Gain 3 cards, but lose smithy card)
			Hand Count: 4	Expected: 7
		TESTING that deck card count for current player went down by 3
			Deck Count: 5	Expected: 2
			
	Bad Code:
		for (i = 0; i > 3; i++)
		{
			drawCard(currentPlayer, state);
		}
		
	Changed to:
		for (i = 0; i < 3; i++)
		{
			drawCard(currentPlayer, state);
		}
		
	Test Result after bug fixes:
		TESTING that hand count for current player has stayed the same(draw a new card and discard great_hall)
			Hand Count: 5   Expected: 5
		TESTING that deck card count for current player has decreased by 1
			Deck Count: 4   Expected: 4

			
****Cutpurse Card - Bug found by my unit test
	
	The bug in the conditional that was introduced in Assignment 2 was found by my card unit test. This bug caused all actions to be applied to the current Player,
	when they should have been applied to all other players.
	
	Test Result:
		TESTING that hand count for current player has decreased by 1
			Hand Count: 3   Expected: 4

			
	Bad Code:
		if (i == currentPlayer)
			
	Code Changed to:
		if (i != currentPlayer)
			
	Test Result after bug fixes:
		TESTING that hand count for current player has decreased by 1
			Hand Count: 4   Expected: 4


****isGameOver Function - Bug found by my unit test

	This bug occurs because when looping through all supply piles to find empties, the function only goes through 25 of the 27 card piles.
	If the last two card piles are empty, it will not trigger a 'Game Over'
	
	Test Result:
		TESTING with an empty salvager, sea_hag, and treasure_map stack:(last 3 'action cards')         Return value: 0 Expected Value: 1
	
	Bad Code:
		for (i = 0; i < 25; i++)
		{
			if (state->supplyCount[i] == 0)
			{
				j++;
			}
		}
		
	Code Changed to:
		for (i = 0; i < 27; i++)
		{
			if (state->supplyCount[i] == 0)
			{
				j++;
			}
		}
	Test Result after bug fixes:
		TESTING with an empty salvager, sea_hag, and treasure_map stack:(last 3 'action cards')         Return value: 1 Expected Value: 1
		
****scoreFor Function - Bug found by my unit test

	This bug occurs because when calculating a score with the gardens card, the function calls fullDeckCount with 0 as its second parameter.
	This means that it will only return a count of how many curse cards are in each deck, not the total card count which is what is needed 
	based on the purpose of the gardens card.
	
	Test Result:
		TESTING where players have 29 smithy cards and 1 gardens card
			Player 1 - Return value: 0      Expected Value: 3
			Player 2 - Return value: 0      Expected Value: 3
			Player 3 - Return value: 0      Expected Value: 3
			Player 4 - Return value: 0      Expected Value: 3

	Bad Code:
		if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		
		if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		
		if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		
	Code Changed to:
		if (state->hand[player][i] == gardens) { score = score + ( state->handCount[player] / 10 ) + (state->discardCount[player] / 10) + (state->deckCount[player] / 10); };
		
		if (state->discard[player][i] == gardens) { score = score + ( state->handCount[player] / 10 ) + (state->discardCount[player] / 10) + (state->deckCount[player] / 10); };
		
		if (state->deck[player][i] == gardens) { score = score + ( state->handCount[player] / 10 ) + (state->discardCount[player] / 10) + (state->deckCount[player] / 10); };
		
	Test Result after bug fixes:
		TESTING where players have 29 smithy cards and 1 gardens card
			Player 1 - Return value: 3      Expected Value: 3
			Player 2 - Return value: 3      Expected Value: 3
			Player 3 - Return value: 3      Expected Value: 3
			Player 4 - Return value: 3      Expected Value: 3
			

			
****Salvager Card Function - Fixed the bug I introduced in Assignment 2 which sent the wrong trash flag.


DISCUSSION OF COVERAGE

	Although I used the coverage information provided by gcov during the creation of my tests, I did not use it too much in finding/fixing bugs. The way that the test failed
	pointed very readily to where the problem was. For example, the isGameOver function failed when the highest 3 card piles were empty. This immediately caused me to look at
	the for loop that looks at all of the piles. Also, the unit test results for the scoreFor function point directly to the garden card.
	
	I did, on the other hand, take coverage into account when writing my test programs. I used this to ensure that the majority of the code was covered in hopes of uncovering 
	any issues. 

USING GDB

	Again, as with coverage, I did not use gdb much in finding bugs because the tests pointed to the problem areas. I did use gdb extensively though, in writing my random tests
	because of the many seg faults. I had to do a lot of refining with the random tests, because the functions expected a "sane" gameState. gdb allowed me to see a lot of my 
	variables were remaining uninitialized when I thought they were initialized. This allowed me to fine-tune the "set-up" I did to the gameState before running each random test.
	
	The ability to backtrace and also look at the information for all local variables proved very helpful. I could see that an array was filled with garbage uninitialized data, when
	I thought it had be initialized. I could also use gdb to jump to directly where a seg fault occued which was nice. 
	
*************************************************************************************************************************/