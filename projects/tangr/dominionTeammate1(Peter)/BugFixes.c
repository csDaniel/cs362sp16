******************************************
******************************************
**Bug Number One - Smithy Card************
***Bug Report One*************************
***Bug Reported From: Nick Martin*********
******************************************

Bug Report: This bug report stated that the smithy card adds twice
as many cards to the players hand than it should. The report also
suggested a cause of the bug, suspecting that it is in a loop
which is too long. Nick rated both the severity and the priority 
of this bug as medium, since it doesn't cause any crashes to the
game.

Smith Card Specification: In the Dominion documentation, it specifies
that the smithy card causes the player who played it to draw three cards.

Code: The smithy card is implemented through the smithyEffect() function, which
is printed below.

	int smithyEffect(struct gameState *state, int currentPlayer, int handPos){
		int i;
		
		//+3 Cards
		for (i = 0; i < 3; i++)
		{
			drawCard(currentPlayer, state);
			drawCard(currentPlayer, state); //----BUG FOUND HERE
		}
				
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
	}

Solution: Taking Nick's advice, I looked at the loop. My first suspect was
the loop counter. I thought maybe it was a greater than or equal sign where
there should be a greater than sign or maybe the counter variables 
weren't initialized correctly. Nick also gave me a good hint that the
results were exactly double that of the expected results. I thought that
maybe a counter variable was being doubled or not being decremented as 
fast as it should be. However, just looking at the code, it is
obvious to see that the drawCard() function is called twice, resulting in
six cards being drawn. This explains why the result was double what
was expected To solve the problem, I simply removed one of 
the calls to drawCard().

******************************************
******************************************
**Bug Number Two - Adventurer Card********
***Bug Report Two*************************
***Bug Reported From: Nick Martin*********
******************************************

Bug Report: This bug report found that the implementation of the
adventurer card adds three treasure cards to the hand, when it is
actually only supposed to add two treasure cards. The suspected
cause of the bug is in a loop counter. Both the severity and the
priority of the bug are rated as medium since the overall program is
still stable but it does affect gameplay.

Adventurer Card Specification: In the Dominion documentation, it specifies
that the adventurer card should "Reveal cards from your deck until you reveal
two Treasure cards. Put those Treasure cards into your hand and discard the
other revealed cards." This means that the user should end up with two more
treasure cards than when they started.

Code: The adventurer card is implemented through the adventurerEffect()
function. Here is the function.

	int adventurerEffect(struct gameState *state, int currentPlayer, int handPos){
		int temphand[MAX_HAND];
		int drawntreasure=0;
		int cardDrawn;
		int z = 0;
		
		while(drawntreasure<=2){ //----BUG CODE FOUND HERE
			if (state->deckCount[currentPlayer] <1){
				shuffle(currentPlayer, state);
			}
			drawCard(currentPlayer, state);
			cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
			if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				drawntreasure++;
			else{
				temphand[z]=cardDrawn;
				state->handCount[currentPlayer]--;
				z++;
			}
		}
		while(z-1>=0){
			state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
			z=z-1;
		}
		return 0;
				
	}

Solution: This bug was more difficult to track down. The code in the
adventurerEffect() function is longer than in the smithyEffect() function.
However, the bug report did suggest looking in the loops, which narrowed
my initial search for the bug. I tried stepping through using GDB, but that
didn't really show me the bug. Then, I used the printf method inside the loop.
I just printed out the deckCount of the player at ever iteration of the loop.
The actual deckCount wasn't helpful, but I could see how many times the loop
was being run and noticed it was one more time than needed. I then examined
the code for the loop more closely and noticed that it was a less than or
equal to instead of a less than, which it needed to be. In the end, the 
printf approach worked very well for this situation.