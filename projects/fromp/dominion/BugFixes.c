PrestonFrom

Bug fixes for adventurer:

--- Handling cases where there is no treasure
In case there are no treasure cards to be drawn in the deck/discard pile, the old code would result the program crashing. To handle this, I added a check to see if the shuffle function returns a -1 (which it does when there are no cards in the discard deck). The logic is: If the deck is empty and there are cards in the discard deck, they should be added to the deck and shuffled, since this will be the first time the discard cards are added. If the discard is empty, it means all the cards are in the temp deck (which is held until adveturer is finished). In that case, there are no more cards left to draw, so we should exit (and return a -1 to show that we did not full draw 2 cards).

gcov was useful for testing for this function to ensure that the unit test was correctly setting up the comparison state and to ensure that all the different branches were taken. Since some refactoring of the unit test was necessary to better test for loop to prevent crashing the program.

New code:
while(drawntreasure < 2 && noTreasure < 1){
	//if the deck is empty we need to shuffle discard and add to deck
	if (state->deckCount[currentPlayer] == 0){
		if(shuffle(1, state) == -1)
			noTreasure = 1;
}
if(noTreasure < 1){
	drawCard(currentPlayer, state);
	//top card of hand is most recently drawn card.
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
	else{
		temphand[z]=cardDrawn;
		//this should just remove the top card (the most recently drawn one).
		state->handCount[currentPlayer]--;
		z++;
        }
}

--- Drawing only 2 cards
This bug was relatively simple -- the bug was in the while loop.
I just changed while(drawntreasure < 3) to while(drawntreasure < 2)
For debugging, it was really only necessary to look at the unit test and obvious when spotted.

--- Shuffle on when deck is empty
This bug caused the deck to be shuffled with every pass of the loop. All that was necessary was to change the if statement to "state->deckCount[currentPlayer] == 0".

gcov was helpful in debugging this, since it was obvious that the branch was being taken 100% of the time, which was clearly irregular. The unit test also indicated when the order of the deck was different between the game and comparison state, which allowed debugging to focus on the call to the shuffle function.

--- Properly discarding adventurer card
The adventurer card was not being discarded (the discard function was not called for the card). This was fixed by calling discard with the hand position of adventurer and the current player. Debugging the issue was relatively easy based on unit tests and the bug reports provided by team mates. 


Bug fixes for smithy:

--- Discard smithy card (instead of trashing)
This bug resulted in the smithy card being trashed instead of simply discarded. Finding the bug was relatively easy by stepping through the call to smithy and noticing that the card was removed from the player's hand but NOT put in the played cards pile. Looking at the call to discardCard revealed that the final parameter was set to 1, which was the flag for trashing a card. I changed this parameter to 0.

--- Change cards drawn from 4 to 3
This bug resulted in a player drawing 4 cards instead of the expected 3.
This was made obvious through unit testing, which revealed that more than the expected number of cards were drawn and the problem was pin pointed by stepping through the loop and counting each pass to find that it was looping more than the expected number of times.
Fixing it was a matter of changing the loop to stop at 3.

Bug fixes for scoreFor

--- Changed third for loop to deckCount (from discardCount)
This bug was pointed out in a bug report from a teammate, which also inluded the specific location and problem. This made it easy to fix.


Bug fixes for council_room
--- Number of buys increases as it should 
This bug resulted in the number of buys decreasing by one when the number should have increased by one. It was found via unit testing -- the unit test indicated that the number of buys was zero when it was expected to be two -- and stepping through the function and watching where the number of buys changed.
The old code was: state->numBuys--
The new code is: state->numBuys++

--- Fixed second for loop so that other players gets to draw
This bug resulted in the player drawing a card when the other players were meant to be drawing cards. Gcov was helpful in finding this since the branch was taken 1/n percent of the time, even though it should have been taken n-1/n percent of the time. This indicated that there was a problem with the if statement, and, on closer inspection, the bug was found.
Old code: if ( i == currentPlayer )
New code: if ( i != currentPlayer )


Bug fixes for remodel
--- Fixed it so the correct card is discarded
This bug caused the wrong card (the correct card's position minus one) to be discarded. This was spotted via unit testing that showed that final hand did not contain the correct cards compared to the expected results. Based on that information, a quick look at the function itself made it quickly obvious where the problem was and the offending code was removed.
Old code: if(handPos > 0) handPos -= 1;
New code: (Nothing, the above line was simply deleted.)

--- Fixed it so card to be trashed is correctly trashed (instead of just discarded)
In addition to the bug mentioned above, unit tests showed that the card chosen to be trashed actually was only discarded. The solution was obvious as the card was being discarded -- it was a matter of setting the trash flag for the call to discardCard.


Fixing shuffle
--- Shuffle was fixed so that it would include cards from the discard pile
This bug was spotted while fixing the adventurer card. I noticed that the call to shuffle was not correctly putting the discard deck into the deck while running unit tests on the adventure card. I added code to ensure that the discard deck is added to the deck when the deck is empty.
Looking at coverage was useful here, since it showed that shuffle was being called correctly -- but the deck was still not getting the discard cards.

New code:
if (state->deckCount[player] < 1){
	if(state->discardCount[player] < 1) return -1;
	for(i = 0; i < state->discardCount[player]; i++){
		state->deck[player][i] = state->discard[player][i];
		state->deckCount[player]++;
	}
	state->discardCount[player] = 0;
}

