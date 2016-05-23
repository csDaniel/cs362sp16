Jacob McMillen - mcmiljac@oregonstate.edu
CS 362 - Assignment 5
22 May 2016

BUG FIXES

*** Teammate 1: ***
Smithy - No bugs reported
Adventurer - No bugs reported

*** Teammate 2: ***
Smithy - No bugs reported
Adventurer - PlayAdventurer does not end with the correct number of cards in the players hand.

The adventurer only counted copper and silver as treasure cards, but it should also count gold. The incorrect code
	if (cardDrawn == copper || cardDrawn == silver)
				drawnTreasure++;

was fixed by changing to the following:		
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				drawnTreasure++;


*** Additional bugs either present in original code or introduced ***
Smithy - 
1. Number of actions after smithy is played was incorrectly being increased by one. Fixed bug so that it decreases by one. The incorrect code 
	state->numActions++;

was changed to
	state->numActions--;

	
Adventurer -
1. The adventurer card was not being discarded after it was played.
Added a handPos parameter to the funciton signature, and added the following line to discard the adventurer card.
	discardCard(handPos, currentPlayer, state, 0);


Village - 
1. The village now only supplies +1 card and +1 action instead of the +1 card and +2 actions it should.
The line
	state->numActions++;
was added to provide the additional action.


Remodel -
1. The card that should be trashed was being discared and the remodel card, which should be discarded, was being trashed.
This bug was fixed by simply switching the trash flag in the function calls to discard the two cards.


Council Room -
1. Provided a player other than Player0 has played the council room, Player0 no longer gets +1 card as she should.
The index variable i in the loop
	for (i = 1; i < state->numPlayers; i++){
		if (i != currentPlayer){
			drawCard(i, state);
		}
	}
has been changed to intialize to 0 rather than 1.