/*
	********** Introduction **********
	In this document, I will be describing the fixes I implemented for bugs that I found in my code
	and my teammates' code from their respective dominion folders.  Specifically, I will be describing
	fixes that I implemented my own source code and in the code of my following two teammates:

			Connor Pacala (ONID: pacalac)
			Eugene Andrew Pak (ONID: pake)

	I have created the following two directories in my own directory, which contain the code that
	was written by my teammates, along with the fixes that I implemented:

			/cs362sp16/projects/clinedim/pacalac_code/
			/cs362sp16/projects/clinedim/pake_code/

	In the following three sections, I will describe the fixes that I created for my bugs and my
	teammates' bugs.

	*********** Bug Fixes for My Code **********
	I introduced a number of bugs in my code during the course of working on my copy of the dominion.c
	file.  The file in question is located by following this path:

			/cs362sp16/projects/clinedim/dominion/dominion.c

	The information below includes descriptions of my fixes for these bugs:

	*** playAdventurer:  The Adventurer card is meant to look through the player's deck to find treasure
	cards.  The buggy version of my code includes this check:

	..........
	if (cardDrawn == silver || cardDrawn == gold) {
		drawntreasure++;
	}
	..........

	This is obviously wrong since it does not count copper cards as treasure.  The fix for this bug is to
	change it to what is below:

	..........
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
		drawntreasure++;
	}
	..........

	*** playSmithy:  The Smithy card is allows the player to draw three new cards.  My buggy implementation
	of the Smithy card makes the player draw four cards instead:

	..........
	for (index = 0; index < 4; index++) {
			drawCard(currentPlayer, state);
	}
	..........

	The fix for this bug is shown below:

	..........
	for (index = 0; index < 3; index++) {
		drawCard(currentPlayer, state);
	}
	..........

  	*** playVillage:  The Village card allows the user to draw an additional card and get two extra actions. My
  	buggy implmeenation of the code grants the player three extra actions instead of two:

  	..........
  	state->numActions = state->numActions + 3;
  	..........

  	To fix this bug, I changed the line above to what appears below:

	..........
	state->numActions = state->numActions + 2;
	..........

	*** playCouncil_Room:  The Council Room card allows the player to draw four cards and make an additional 
	buy, but also allows every other player to draw a card.  I introduced a bug where the player draws 3 cards
	instead and the number of buys is decremented.  The buggy code is shown below:

	..........
	for (index = 0; index < 3; index++) {
		drawCard(currentPlayer, state);
	}

	state->numBuys--;
	..........

	I fixed the code by changing it to what appears below:

	..........
	for (index = 0; index < 4; index++) {
		drawCard(currentPlayer, state);
	}

	state->numBuys++;
	..........

	*** playGardens:  The Gardens card is worth 1 victory point for every 10 cards in the deck.  In the original
	version of the code, the function simply returned -1.  I introduced a bug by making it return 0 instead. To
	fix this bug, I simply changed the return value from the buggy 0 to the correct -1.

	********** Bug Fixes for Connor Pacala's Code **********
	During my testing of Connor's code, I found three bugs.  The fixes for each of these bugs will be
	described in detail below.  Please note that all changes to code are available in the following
	file:

			/cs362sp16/projects/clinedim/pacalac_code/dominion.c

	Bug #1:  Adventurer Leaves Too Many Cards in Current Player's Hand
	The bug in the code was a result of a missing call to the discardCard function.  I corrected the code by making modifications to the
	dominion.h and dominion.c files.  Specifically, I updated the function prototype for the playAdventurer card from what is below:

	int playAdventurer(struct gameState *state);

	to what is below:

	int playAdventurer(struct gameState *state, int handPos);

	In addition to the change to the function prototype, I also added a call to the discardCard function.  Prior to my changes, the 
	code looked like this:

	..........
	int playAdventurer(struct gameState *state, int handPos) {
		int cardDrawn;
		int drawntreasure=0;
		int z = 0;// this is the counter for the temp hand
		int temphand[MAX_HAND];
		int currentPlayer = whoseTurn(state);

		while(drawntreasure<2) {
	..........

	After my changes, the code looked like this:

	..........
	int playAdventurer(struct gameState *state, int handPos) {
		int cardDrawn;
		int drawntreasure=0;
		int z = 0;// this is the counter for the temp hand
		int temphand[MAX_HAND];
		int currentPlayer = whoseTurn(state);
		
	  	discardCard(handPos, currentPlayer, state, 0); 			<--- I added this line
		while(drawntreasure<2) {
	..........

	The result of these changes is that the current player ends up with the correct number of cards
	in their hand after playing the adventurer card.  This fixed the bug in Connor's code, and all
	tests related to the Adventurer card passed after making this change.

	Bug #2:  Smithy Card Results in Incorrect Number of Cards in Current Player's Hand and Deck
	As with the previous bug, the Smithy Card bug has an issue with the player ending up with the
	wrong number of cards in their hand after playing the card.  This, too, is a result of a missing
	call to discardCard.
	
	The code below represents Connor's implementation of the function:

	..........
	int playSmithy(struct gameState *state, int handPos) {
		int currentPlayer = whoseTurn(state);
		int i = 0;
		
		//+3 Cards
		for (i = 0; i < 3; i++) {
			drawCard(currentPlayer, state);
		}
		
		return 0;
	}
	..........

	The code below represents the changes I made:

	..........
	int playSmithy(struct gameState *state, int handPos) {
		int currentPlayer = whoseTurn(state);
		int i = 0;

		discardCard(handPos, currentPlayer, state, 0)		<-- I added this line

		//+3 Cards
		for (i = 0; i < 3; i++) {
			drawCard(currentPlayer, state);
		}
		
		return 0;
	}
	..........

	This helped ensure that the card counts were correct.  After making these changes, the card passed all tests.

	Bug #3:  Council Room Card Results in Incorrect Number of Cards in Hand and Deck and Incorrect Number of Buys
	This bug is similar to the two previous bugs in that it results in the player having an incorrect number of
	cards.  It also introduces a new issue where the player does not have the correct number of buys.

	The code below represents Connor's implementation:

	..........
	int playCouncil(struct gameState *state, int handPos) {
		int currentPlayer = whoseTurn(state);
		int i = 0;
		
		for (i = 0; i < 4; i++) {
			drawCard(currentPlayer, state);
		}

		for (i = 0; i < state->numPlayers; i++) {
			drawCard(i, state);
		}

		discardCard(handPos, currentPlayer, state, 0);

		return 0;
	}
	..........

	The corrections that I implemented are below:

	..........
	int playCouncil(struct gameState *state, int handPos) {
		int currentPlayer = whoseTurn(state);
		int i = 0;
		
		for (i = 0; i < 4; i++) {
			drawCard(currentPlayer, state);
		}

		state->numBuys++;		<-- I added this

		for (i = 0; i < state->numPlayers; i++) {
			if (index != currentPlayer) {		<-- I added this
				drawCard(i, state);
			}
		}

		discardCard(handPos, currentPlayer, state, 0);

		return 0;
	}
	..........

	After making the changes above, I re-ran the test suite against Connor's implementation and all tess passed.
	
	********** Bug Fixes for Andrew Pak's Code **********

	Bug #1:  Player Has Incorrect Number of Played Cards and Cards in Deck and Hand After Playing Treasure
	Before I made any changes to Andrew Pak's source code, his implementation of the Adventurer card's logic appeared
	like what is below:

	..........
	int pAdventurer(int handPos, int currentPlayer, struct gameState *state) {
		int cardDrawn = 0;
		int	temphand[MAX_HAND];
		int	drawntreasure = 0;
		int	z = 0;

	    while(drawntreasure<1){
	        if (state->deckCount[currentPlayer] <1) {
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

	    while(z-1>0){
	        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
	        z=z-1;
	    }

	    return 0;
	}
	..........

	As can be seen above, there is no call to the discardCard function, which should be used to
	handle the Adventurer card after it is played.  Likewise, the while loop is only looping long
	enough to add a single treasure card to the player's hand.  I made the following changes to the
	code to correct the bugs:

	..........
	int pAdventurer(int handPos, int currentPlayer, struct gameState *state) {
		int cardDrawn = 0;
		int	temphand[MAX_HAND];
		int	drawntreasure = 0;
		int	z = 0;	//this is the counter for the temp hand

	    while(drawntreasure<2){									<-- I made this change
	        if (state->deckCount[currentPlayer] <1) {
	            shuffle(currentPlayer, state);
	        }

	            drawCard(currentPlayer, state);
	            cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];

	        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	            drawntreasure++;
	        else{
	            temphand[z]=cardDrawn;
	            state->handCount[currentPlayer]--;
	            //this should just remove the top card (the most recently drawn one).
	            z++;
	        }
	    }

	    while(z-1>0) {
	        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
	        z=z-1;
	    }

	    discardCard(handPos, currentPlayer, state, 0);	<-- I made this change.

	    return 0;
	}
	..........

	After making the changes above, the tests in my test suite passed.

	Bug #2:  Bug #2:  Player Has Incorrect Number of Actions after Playing Village Card
	Before I made any changes to Andrew Pak's code, it looked like what is showin below:

	..........
	int pVillage(int handPos, int currentPlayer, struct gameState *state) {
		drawCard(currentPlayer, state);
		state->numActions = state->numActions + 1;
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
	}
	..........

	The error that showed up from my unit test's results indicated that the player had an
	incorrect number of actions.  This error is clearly coming from the line of code that 
	increases the player's number of actions.  I made the following changes:

	..........
	int pVillage(int handPos, int currentPlayer, struct gameState *state) {
		drawCard(currentPlayer, state);
		state->numActions = state->numActions + 2;		<-- I changed this
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
	}
	..........

	After implementing the changes shown above, the unit tests for the Village card passed.

	********** Final Thoughts **********
	In the above sections, I have included fixes for all of the bugs that I included in my implementation
	of various cards in the Dominion deck, as well as for bugs that I found while testing Connor's and
	Andrew's code.  My test suite was very helpful in identifying these bugs, and the error messages that
	I created in my test suite often helped me narrow in on the source of the bug very quickly.  Based on
	the results of my test suite, I believe that the tests that I have implemented are pretty good overall.
	The biggest issue (which I also identified in my BugsInTeamates.c file) is the relatively low overall
	test coverage.  This could be improved, however, by creating additional tests for more cards in the
	Dominion deck.
*/