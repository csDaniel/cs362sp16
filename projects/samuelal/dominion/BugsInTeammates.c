Alex Samuel
Assignment 5
BugsInTeammates.c

Card tests, Unit tests, and random tests were run on teammates' code and the results are listed below.

Teammate 1 - Josh Geller (gellerj)
BUG: Smithy is not trashed when Smithy card is played.
BUG: Adventurer card does not consider Gold cards as Treasure cards when drawing 2 Treasure cards.
BUG: When Village card is played, player's actions are incremented by only +1 rather than +2.
BUG: scoreFor() does not calculate the total scores for each player correctly. scoreFor()
tends to undercalculate the true score. One error in the function occurs when the function is trying
to calculate the total score from the cards in the deck. In this portion of the code, the function iterates 
between 0 and discardCount pile rather than deckCount (state->discardCount[player] should be state->deckCount[player]). 
This could lead to errors if deckCount is larger than discardCount as some cards will not be counted.
	Another error in this function occurs when it calculates the scores from gardens cards present in the player's
entire deck. scoreFor() calls the fullDeckCount() function but passes in the card number of curses and not any other 
card. As a result, the fullDeckCount function will only return the total number of curses cards in the player's possession 
rather than the total number of all cards in the player's poessession. As a result, gardens cards do not grant as many points 
to players as they should.

Teammate 2 - Daniel Ofarrell (ofarreld)
BUG: 4 cards are drawn instead of 3 cards when Smithy card is played.
BUG: When Village card is played, player's action count is decremented by 2 instead of increased by 2.
BUG: scoreFor() does not calculate the total scores for each player correctly. scoreFor()
tends to undercalculate the true score. One error in the function occurs when the function is trying
to calculate the total score from the cards in the deck. In this portion of the code, the function iterates 
between 0 and discardCount pile rather than deckCount (state->discardCount[player] should be state->deckCount[player]). 
This could lead to errors if deckCount is larger than discardCount as some cards will not be counted.
	Another error in this function occurs when it calculates the scores from gardens cards present in the player's
entire deck. scoreFor() calls the fullDeckCount() function but passes in the card number of curses and not any other 
card. As a result, the fullDeckCount function will only return the total number of curses cards in the player's possession 
rather than the total number of all cards in the player's poessession. As a result, gardens cards do not grant as many points 
to players as they should.

