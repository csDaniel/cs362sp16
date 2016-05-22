/*---------------------------------------
* Brett Irvin
* 5/20/16
* CS362_400 Software Engineering II
* Assignment 5--BugFixes.c
* Bug fixes from teammates' bug reports
*---------------------------------------*/

------------------------------------------
Bug Report, Teammate 1 - Alex Balab/balaba
------------------------------------------
Alex and I had the Adventurer, Smithy, and Village cards in common, so only 3 of his card tests and 1 of his random tests
were tested on my code.

cardtest1.c (Adventurer): The hand count was always higher by 2 cards.
		This was not a bug I had introduced into the Adventurer card.  Alex thought that there might have been an issue with his 
	card test, but Dane's tests also reported a bug in the Adventurer card.  Since my cardtest2.c file tested the Adventurer card,
	I ran it using GDB.  First, I stepped through the adventurerCard function and verified that drawntreasure was incrementing until it reached
	2, then exited the loop.  I next checked the various variables in the function, and found that variable 'z' was never incrementing from 0.
	This explained why my tester kept flagging an error, because my card test for Adventurer tests to see whether the discard pile incremented
	after the Adventurer card was played.  Since the value of 'z' determines whether or not the discard action occurs, this explains the discrepancy.
		I tried several things in GDB to figure out why z wasn't incrementing, but was unsuccessful.  Finally, I used GDB to manually step through
	cardtest2, and then forced it to assign 'z=1'.  As I expected, this allowed my tests for Adventurer to pass successfully.  No matter what I tried,
	I couldn't get any further with fixing the bug.  There's a problem with 'z' always being set to 0, which means that cards are never discarded once 
	two Treasures are drawn.  Instead of cards being discarded, they just continue to accumulate in the hand.  This explains why the hand count is always
	off.
	
	The error with z occurs in this block of code.  Z never increments, so the discard action never happens:
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	  z++;
	}
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }
      return 0;
}
	
cardtest2.c	(Smithy): Number of cards on hand is always 1 smaller than expected.
	This was an intentional bug I had introduced during the refactor.  I had changed the loop parameters so that
	the Smithy card would only draw 2 cards instead of 3.  I fixed this bug by changing the loop parameters back.
	
	--Buggy code--:
	int smithyCard(int currentPlayer, struct gameState *state, int handPos){
	//+3 Cards
	int i = 0;
      for (i = 0; i < 2; i++)
	{
	  drawCard(currentPlayer, state);
	}
	
	--Fixed code--:
	int smithyCard(int currentPlayer, struct gameState *state, int handPos){
	//+3 Cards
	int i = 0;
      for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
	
	
cardtest3.c (Village): Number of cards on hand was 1 more than expected, while number of actions was correct.	
	I introduced this bug by removing villageCard's discard function, meaning the card would no longer discard the
	played card from the current hand.  I fixed this bug by reinserting the discardCard function call.
	
	--Buggy code--:
	int villageCard(int handPos, struct gameState *state, int currentPlayer)
	{
		//+1 Card
		drawCard(currentPlayer, state);
				
		//+2 Actions
		state->numActions = state->numActions + 2;

		return 0;
	}

	
	--Fixed code--:
	int villageCard(int handPos, struct gameState *state, int currentPlayer)
	{
		//+1 Card
		drawCard(currentPlayer, state);
				
		//+2 Actions
		state->numActions = state->numActions + 2;
		
		//discard played card from hand
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
	}

	
unittest1.c (updateCoins): No bugs encountered.

unittest2.c (discardCard): No bugs encountered.

unittest3.c (whoseTurn): I did not introduce a bug into this function, so any  bugs found here must have been in the original
	code we were given.  Alex mentioned in his write-up that his unit test here passed, but that he still thought there were 
	bugs in the whoseTurn function.  I went back and looked at the whoseTurn function, and it seemed to be a fairly simple function, 
	with not a lot of room for error.  All we do in that function is pass in a gameState and then return a value to indicate the correct
	turn.  With that being said, though, if there is an error in whoseTurn, it's very significant, since so much of the other functions
	depend on whoseTurn to set up their context properly.  I did not find an error with whoseTurn, but if there is one, then it literally 
	puts into question much of the rest of the game.
	
unittest4.c (fullDeckCount): No bugs encountered.

randomtestadventurer.c: The hand count was always higher by 2 cards.
	Alex's card test 1 and his random tester both flagged an error in the Adventurer card.  I discussed troubleshooting the
	issue above, in the section for Alex's cardtest1.c file.


-------------------------------------------------
Bugs Found, Teammate 2 - Dane Schoonover/schoonod
-------------------------------------------------
1.  Smithy card test. Playing the smithy card caused smithCard() test 1 to fail. This means an incorrect player hand count
occurs after calling smithyCard().
	Both Alex and Dane's tests caught this bug.  I had changed the loop parameters so that Smithy would always draw 2 cards 
	instead of 3.  To fix it, I just corrected the for loop by letting it loop 3 times instead of 2.
	
2. 	scoreFor() test failed. The expected score is 78, but the actual score was 50. This indicates a logic error somewhere in
the function.
		This was not a bug I had introduced during the refactor. To troubleshoot the scoreFor function, I first went back and verified
	that all of the cards were being counted correctly.  Looking at the Dominion Wiki page (http://wiki.dominionstrategy.com/), I 
	verified that all of the cards had the correct values.  I did notice, however, that at the end of the game, the Gardens card is 
	worth +1 for every 10 cards in the deck; I thought there might be an error with how the Garden cards were being scored, but the code
	checked out fine.  The final score should include cards from the deck, the discard pile, and current hand. Since that is calculated
	from the fullDeckCount function, I went to that function and checked to see if it was factoring in the deck, hand, and discard piles
	when calculating the final deck count.  It seemed to be working correctly.
		Finally, I looked back over all of the components of the scoreFor function and noticed that the deck count was set to loop using
	the discardCount variable instead of the deckCount variable.  This will always score the deck incorrectly, and explains the error in 
	scoring.
	
	--Buggy code--:
	//score from deck
	  for (i = 0; i < state->discardCount[player]; i++)
		{
		  if (state->deck[player][i] == curse) { score = score - 1; };
		  if (state->deck[player][i] == estate) { score = score + 1; };
		  if (state->deck[player][i] == duchy) { score = score + 3; };
		  if (state->deck[player][i] == province) { score = score + 6; };
		  if (state->deck[player][i] == great_hall) { score = score + 1; };
		  if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		}
		
	--Fixed code--:
	//score from deck
	  for (i = 0; i < state->deckCount[player]; i++)
		{
		  if (state->deck[player][i] == curse) { score = score - 1; };
		  if (state->deck[player][i] == estate) { score = score + 1; };
		  if (state->deck[player][i] == duchy) { score = score + 3; };
		  if (state->deck[player][i] == province) { score = score + 6; };
		  if (state->deck[player][i] == great_hall) { score = score + 1; };
		  if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		}
		
	
3. 	randomtestadventurer.out segfaults upon make. This fault is traced back to line 18 in dominion.c.
	This was a bug introduced during the refactor.  I changed the while drawntreasure statement parameters so that it would 
	only fire in the case of drawing a copper, silver, and gold card, instead of a copper or silver or gold.  Since that is an 
	impossible scenario (a card can't be three types at once), it introduced an instant segmentation fault.  I reversed the bug 
	by changing if (cardDrawn == copper && cardDrawn == silver && cardDrawn == gold) back to the correct if 
	(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold).

	--Buggy code--:
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper && cardDrawn && silver && cardDrawn == gold)
	  drawntreasure++;
  
	--Fixed code--:
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn || silver || cardDrawn == gold)
	  drawntreasure++;
	