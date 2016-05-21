Assignment 5: Bug Fixes

Name: Lauren Miller
Date: May 20, 2016

Bug 1: Other Players Not Drawing Cards After Council Room 

Report from Dave Martinez:

	CARD TEST 4: council_room_card
	TEST 3: Does each other player get a card?
	Player 1 hand count = 0, expected 1

	LOCATION
	dominion.c:54 council_room_card()

	EXPECTATION
	Player 1 should receive a card after Player 0 draws four 
	after playing a councilroom. Player 1's handcount begins
	at zero and should iterate to 1. 

	POSSIBLE CAUSE
	dominion.c:66 for loop
	The condition of the 'for' loop at this line is the likely
	culprit. Rather than iteration over the number of players, 
	the function only iterates to the current player. Thus, if
	player 0 played a councilroom, only players in memory at 
	indexes less than 0 (impossible) will recieve an extra card.

	This should instead iterate up to gameState->numPlayers 
	and guard against providing gameState->whoseTurn an extra
	card. This guard is already in place at dominion.c:68 if.

Code Changes:
	
	"for (i = 0; i < currentPlayer; i++)" in council_room_card was changed to "for (i = 0; i < state->numPlayers; i++)".
	
	Dave correctly identified the error in the for-loop in council_room_card, the function refactored from the original Council Room effect in CardEffect. This was one of the bugs I introduced for Assignment 2, and adjusting the for-loop so that it iterated over every player in a given game instead of only those with an id less than the active player's corrected this bug. The corrected for-loop allowed all other players besides the current player to draw a card, one of the effects of Council Room.

Bug 2: Smithy Adds Incorrect Number of Cards to Hand

Report from Runa Trinh:

	Bug #1
	Title: playSmithy() Adds Incorrect Number of Cards to Hand

	Class: Minor Bug

	Date: 5/20/2016          
	Reported By: Runa Trinh   
	Email: trinhr@oregonstate.edu

	Product: smithy_card(currentPlayer, &state, handPos, bonus);                 
		   
	Is it reproducible: Yes 

	Description
	===========
	Playing the smithy card resulted in the incorrect
	hand and deck count for the player. 

	Steps to Produce/Reproduce
	--------------------------
	1. Set the number of players to two.
	2. The player turn was set to 1.
	3. The smithy card was in hand position 0.
	4. Player's Hand Count was only 1.
	5. Player's Deck Count was 10 cards.
	6. Called the playSmithy function card.

	Expected Results
	----------------
	End Deck Count: 7
	End Hand Count: 3
	Player's deck count would be decremented by three cards.
	Player's hand count would be two higher because of three drawn cards
	and a discarded smithy.

	Actual Results
	--------------
	End Deck Count: 6
	End Hand Count: 4
	Player's deck count was decremented by four.
	Player's hand count was three higher. 

	Smithy card is probably drawing four cards from the deck
	instead of three.

Code Changes:
	
	"for (i = 0; i <= 3; i++)" in smithy_card was changed to "for (i = 0; i < 3; i++)".
	
	Runa correctly identified the error in the for-loop in smithy_card, the function refactored from the original Smithy effect in CardEffect. This bug was one of those I introduced for Assignment 2, and adjusting the for-loop that it looped exactly 3 times corrected this bug. The corrected for-loop allowed allowed the current player to draw the correct number of cards, 3, which is the sole effect of Smithy.

Bug 3: adventurer_card() not Discarding Cards Correctly

Report from Runa Trinh:

	Bug #2
	Title: adventurer_card() not Discarding Cards Correctly  

	Class: Moderate Bug 

	Date: 5/20/2016          
	Reported By: Runa Trinh   
	Email: trinhr@oregonstate.edu

	Product: adventurer_card(player, &actual, temphand);                
		   
	Is it reproducible: Yes  

	Description
	===========
	 Playing the adv

	Steps to Produce/Reproduce
	--------------------------
	Steps to Produce/Reproduce
	--------------------------
	1. Set the number of players to two.
	2. Initialize the game.
	3. The player's deck(5): village, gold, smithy, feast, copper.
	4. The player's hand(2): adventurer, mine.
	5. The player's discard count was 0.
	6. The player's discard: 0. 
	7. Play the adventurer card.

	Expected Results
	----------------
	Expected Deck Count: 0
	Expected Discard Count: 4 (Village, Smithy, Feast, Adventurer)
	Expected Hand Count: 3
	-Player Hand Count will only increase by one with a discarded 
	adventurer card and addition of two treasure cards.
	-The Discard Count: three drawn unused cards and discarded adventurer. 
	-The Deck Count will be empty since last card is the second treasure card.


	Actual Results
	--------------
	Actual Deck Count: 1
	Actual Discard Count: 0
	Actual Hand Count: 4
	-The adventurer card is most likely not being discarded.
	-Drawn non-treasure cards are likely not being put back in the discard
	pile. 
	-Can't tell what is affecting the incorrect deck count. Maybe
	a card is being read as a treasure card when it isn't.

Code Changes:
	
	"z++;" was reintroduced to the else condition of "if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)".
	
	Runa correctly identified that there was an error in the number of cards discarded after Adventurer was played. One of the bugs I introduced for Assignment 2 was the deletion of "z", which counted the number of non-treasure cards to be discarded after a sufficient number of treasure cards had been drawn. The reintroduction of the counter of these cards ensured that these were removed at the end of the function. 
	
	"int adventurer_card(int currentPlayer, struct gameState *state, int *temphand)" was changed to "int adventurer_card(int currentPlayer, struct gameState *state, int *temphand, int handPos)"
	
	"discardCard(handPos, currentPlayer, state, 0);" was added as the last statement before the return statement.
	
	The second cause of the error in the number of cards in hand and number of cards discarded after the play of Adventurer was the failure of to discard the Adventurer itself after it was played. The hand count of the current player was consistenly 1 higher than expected, even after re-introducing the counter of the non-treasure cards to be discarded. Introducing discardCard removes the Adventurer card from the active player's hand, as is expected after playing Adventurer.
	
	
	
