/*
File: BugFixes.c
Author: Elliot Bates
Description: This file outlines the bugs that I have fixed in my dominion code.

==++ CHANGES DUE TO TEAMATE BUG REPORTS ++==
Based on the bugs in my dominion code found by my teamates, I have made the following changes to the code:
1. In the smithyCard function

	for (i = 0; i > 3; i++)
		
   Has been changed to
   
	for (i = 0; i < 3; i++)
		
   i.e. the greater than has been changed to a less than. This bug was causing the player not to draw any cards.
   
2. In the adventurerCard function it was revealed that the adventurer card was not being discarded from the players hand. I have therefore added the line 

	discardCard(handPos, currentPlayer, state, 0);
	
   To the adventurer function, and have also as a result added handPos as an arguement to the function.
   
3. In the villageCard function

	state->numActions = state->numActions + 1;
	
   Has been changed to
   
	state->numActions = state->numActions + 2;
	
   i.e. the number of actions now increases by 2, as it should.
   
==++ CHANGES DUE TO MY OWN TESTING ++==
Based on the unit and random tests that I performed on my code, I have made the following additional changes:
1. In the council_roomCard function

	for (i = 1; i < state->numPlayers; i++)
		
   Has been changed to 
   
	for (i = 0; i < state->numPlayers; i++)
		
   i.e. the for loop starts at position 0 instead of position 1. This bug was causing the player in position 0 not to draw their aditional card.

==++ OTHER CHANGES ++==
I have also fixed the bugs in my code that were introduced earlier in the term that were either not detected by testing or were not covered in the testing.
1. In the adventurerCard function '|| cardDrawn == gold' has been added back in so that gold treasure cards will also be drawn into the players hand. This bug is quite difficult to detect, and would require a test
   that checks the player's deck and identifies the next two treasure cards to be drawn, and then checks that these were the two cards drawn after th card effect has taken place.
   
2. In the embargoCard function 

	discardCard(handPos, currentPlayer, state, 0);	
	
   Has been changed to 
   
	discardCard(handPos, currentPlayer, state, 1);	
	
   So that the embargo card is actually trashed instead of being added to the discard pile.
   
==++ DISCUSSION OF COVERAGE ++==
Whilst I dont think that designing my tests with coverage in mind necessarily helped me to find any additional bugs in this case, I did see how doing so can be very beneficial when designing tests. The argument that 
you won't find a bug in a line of code unless you actually test that line of code is a pretty strong one in my opinion and I will continue to think critically about coverage when writing tests in the future. 
*/