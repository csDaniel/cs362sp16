Alex Samuel
Assignment 5
BugsInTeammates.c

Card tests, Unit tests, and random tests were run on teammates' code and the results are listed below. These results were then 
shared with my teammates.

Teammate 1 - Josh Geller (gellerj)
unittest1.c - Testing getCost() function
-No bugs found

unittest2.c - Testing fullDeckCount() function
-No bugs found

unittest3.c - Testing isGameOver() function
-No bugs found

unittest4.c - Testing scoreFor() function
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

cardtest1.c, randomtestcard.c - Testing smithy card
BUG: Smithy is not trashed when Smithy card is played.

cardtest2.c, randomtestadventurer.c - Testing adventurer card
BUG: Adventurer card does not consider Gold cards as Treasure cards when drawing 2 Treasure cards.

cardtest3.c - Testing village card
BUG: When Village card is played, player's actions are incremented by only +1 rather than +2.

cardtest4.c - Testing great hall card
-No bugs found

-------------------------------------------------------------------------------

Teammate 2 - Daniel Ofarrell (ofarreld)

unittest1.c - Testing getCost() function
-No bugs found

unittest2.c - Testing fullDeckCount() function
-No bugs found

unittest3.c - Testing isGameOver() function
-No bugs found

unittest4.c - Testing scoreFor() function
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

cardtest1.c, randomtestcard.c - Testing smithy card
BUG: 4 cards are drawn instead of 3 cards when Smithy card is played.

cardtest2.c, randomtestadventurer.c - Testing adventurer card
-No bugs found

cardtest3.c - Testing village card
BUG: When Village card is played, player's action count is decremented by 2 instead of increased by 2.

cardtest4.c - Testing great hall card
-No bugs found
