David Hite
BugFixes.c

=== FIXED - Bug1 found by Kristen ===
Discarded card was not added to discard pile and discardCount was not updated
properly in discardCard().

Added to discardCount() in the first if statement:
	state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][handPos];
	state->discardCount[currentPlayer]++;
	
=== FIXED - Bug2 found by Kristen ===
Smithy was not properly discarded after being played.

She found a bug I introduced!
To fix it, in playSmithy(), I removed handPos++ from the first for loop.

=== FIXED - Bug3 found by Kristen ===
Hand count not correct after Adventurer card was played.

Appears to be fixed already, may have been related to a previous bug.

=== FIXED - Bug4 found by Kristen ===
Adventurer card was not on top of discard pile after playing Adventurer card.

Added handPos argument to playAdventurer() and added discardCard() with handPos to the end
of playAdventurer(). Also added handPos to the call of playAdventurer() in cardEffect().

=== FIXED - Bug5 found by Kristen ===
Non-treasure cards drawn during playAdventurer() were not in discard pile after
call to playAdventurer(). 
She found another bug I introduced!

Added back z++ to the while (drawnTreasure < 2) statement that I had removed. I
also changed the initialization of z from 1 back to 0.

=== FIXED - Bug6 found by Kristen ===
Player did not draw cards from his own deck (?) with playAdventurer().

Fixed with previous bug fixes.

=== FIXED - Bug7 found by Kristen ===
Player did not have the correct number of actions after playing Village.
Another bug I introduced!

Changed back from state->numActions++ to state->numActions += 2.

=== FIXED - Bug8 found by Kristen ===
Village card on top of discard pile after playing Village.

Fixed with another bug fix.

=== FIXED - Bug9 found by Kristen ===
Council Room card not on top of discard pile after played.

Fixed with a previous bug fix.

=== FIXED - Bug10 found by Kristen ===
Other player did not draw a card when Council Room was played.
Another bug I introduced!

Changed == in if statement checking which players to draw cards (line 1370) back to !=.

=== FIXED - Bug11 found by Kristen ===
Current player drew 1 extra card when Council Room was played.

Fixed with previous bug fix.