/*
Charles Siebert
Assignment 5
BugFixes.c

Description: These are the bugs that my teammates found during our rounds
of testing. Each bug will have a description of what it is, the fix of the
bug described, and an analysis at the end of this file. Ironically, all our
team members used the same buggy cards, so we ended up using all of our tests.

-------------------------------------------
RESULTS
-------------------------------------------

Smithy: 
Both teammates reported to me that Smithy was drawing one too many cards,
they also notified me that it was caused by a one off error, where the for loop condition
was '<=' instead of '<', where it was including the limit to draw another, instead of stopping
at the limit. This was changed as the bug was reported by my team members.

Adventurer: 
Teammembers told me that this card was drawing an estate card as a
treasure card instead of gold as it was intended, which is caused by the following line : 

	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == estate)
		drawntreasure++;
	
This bug was fixed by changing the 'cardDrawn == estate' to gold. This was fixed in my
dominion code as it was reported.

Council Room:
Bug was reported by my teammates that there was one too many cards within the current player's hand
One person even reported that the for loop was causing the current player to draw an extra card it shouldn't
when played. It was caused by these lines:

	for (i = 0; i < state->numPlayers; i++) {
		drawCard(i, state);
	}

There is no check for the current player to NOT draw a card, as all other players are supposed to be drawing one.
This makes it so one extra is drawn, so this is fixed by adding this into the function :
	
	if ( i != currentPlayer ) {
		drawCard(i, state);
	}
	
The bug is fixed as it was reported.

Village:
Teammates reported to me that this card wasn't drawing the correct amount of cards to the player,
and one even caught that it sometimes caused a segfault when attempting to play the card when it's
the last player using it, as this line: 

	'drawCard(state->whoseTurn +1, state); 
	
was causing it to make a player draw a card that could potentially not exist. This also changed
that the current player did not get the card they were supposed to. The bug is now fixed by removing
the +1 to whoseTurn.

Mine:
This was not tested by my teammates, but the bug caused by it is done by changing where the card is placed
when the card is played. Originally the card gains a card determined by its value, and placed it in the player's
hand when it is played. Instead, the bug makes it so the card gained is placed into the deck instead. It is caused
by this line: 

	gainCard(choice2, state, 1, currentPlayer);
	
This bug has been fixed.

-------------------------------------------
ANALYSIS
-------------------------------------------

In these cases of testing, coverage can be a good thing, as it is more likely to catch bugs, because there are
tests in place to guarantee how the function should behave, and if it doesn't, then something has changes. That
is one of the beauties of TDD in general. Having test cases allows us to track and determine behavior of a function,
but it doesn't catch all of the potential bugs. Even with 100% coverage, lines are executed, branches are executed,
but the bugs could exist within the entire scope of th program, and change the behavior of other parts of the program.

If testing is only done with the scope of what the function is intended to do, then testing isn't sufficient, as it can
manipulate how other parts of functions can behave. Testing should cover all potential avenues, such as in the case of
dominion. if a card's scope is to draw a card to a current player, whose to say that it doesn't draw other players card
if we're only  if we're only looking at the currentPlayer.

Coverage is good, but it doesn't guarantee a bug free program.

*/