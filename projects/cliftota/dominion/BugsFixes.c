In total I fixed 8 bugs.

The bugs fixes that the teammates reported:

1. The Adventurer Card:
	discardCard(handPos, currentPlayer, state, 0); was added to the adventurerPlay function
	in order to the Adventurer card leaving the player’s hand and going
	into the played pile.
	
	This bug was fixed using GDB. I was running the adventurer card test in GDB and
    set break point before the adventurerPlay function was called. Next, I used step command
	to execute the test line by line. I noticed that the discardCard function was never called.

2. The Smithy Card:
	for (i = 0; i <= 3; i++){ drawCard(currentPlayer, state);}
	was changed to
	for (i = 0; i < 3; i++){ drawCard(currentPlayer, state); }
	in order the correct number of cards were added to the players hand
	(3 instead of 4).
	
	This bug was fixed using code review.

3. The function scoreFor():
	for (i = 0; i < state->discardCount[player]; i++)
	was changed to
	for (i = 0; i < state->deckCount[player]; i++)
	in order the score was calulated for the deck.

    This bug was fixed using code review.

The bugs fixes that were introduced (one bug was reported by a teammate):

4. The Adventurer Card:
	state->deckCount[currentPlayer] > 1; 
	was changed to
	state->deckCount[currentPlayer] < 1;
	in order discarded cards be shuffled and added to the deck while deck
	has no cards.
	
	This bug was fixed using code review.

5. The Minion Card:
	the line state->numActions++; 
	was added in order incrementing the action count.
	
	This bug was fixed using code review.

6. The Remodel Card:
	j = state->hand[currentPlayer][choice2]; 
	was changed to
	j = state->hand[currentPlayer][choice1];
	in order to store the correct cards that will be trashed
	
	This bug was fixed using code review.

7. The Council Room Card:
	i == currentPlayer 
	was changed to
	i != currentPlayer
	in order other player to draw a card (no the current player).
	
	This bug was fixed using code review.
	
After fixing all these bugs some tests still fails. Thus, I had to fix other 
bugs:

8. The function isGameOver(): game is not always over if three piles
   are empty.
   
   I used GDB. I set break point before the testing with three piles
   empty begins. Next, I step through each line. I noticed that when
   G.supplyCount[k[8]] = 0; was set to 0 the test fails. It means 
   it fails on the sea_hag card. This card is 25th.  However,
   the isGameOver checks only including 24th card: for (i = 0; i < 25; i++).
   Once it was fixed the test passed. 
   
The last bug shows that the coverage is not prove that the code is tested
throughly. The unittest for isGameOver shows good coverage. However,
the bug could be not found if the game did not have the sea_hag card. 
It this case since the coverage is good and test passed, we could assume
that the code is correct. It would be a mistake. Thus, even tough it is
worth to pay attention to the coverage. Other factors should be 
considered also. 