Bug Fixes:

	Smithy - On line 707, changed "for (i = 0; i <= 3; i++)" back to "for (i = 0; i < 3; i++)", returning the code 
	to its original functionality.
	
	Adventurer - Added on line 780, "discardCard(handPos, currentPlayer, state, 0)" so that the adventurer card       <-- I found this one
				 would be discarded from the handPos when used.
			   - Added on line 782, "return 0;", so that adventurer would return to its original functionality.
	
	Council Room - On line 693, changed "if ( i == currentPlayer )" back to "if ( i != currentPlayer )", 
				   returning the code to its original functionality.
				   
	Remodel - On line 734, changed "if ( (getCost(state->hand[currentPlayer][choice1]) + 2) < getCost(choice2) )" back to 
			  "if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )", returning the code to its
			  original functionality.