/*
Ben Beckerman
CS 362
Assignment 5
May 22, 2016

Bugs Found by Teammates:

* Both teammates discovered a bug where the Smithy was trashed instead of discarded after it was played. Debugging revealed that the cause of the problem is on line 1295 of dominion.c. A flag was set on the discardCard function that is called in the smithy method that caused the card to be removed from the hand but not added to the discard pile.

* poolj discovered a bug where the correct number of actions is not set in the village function. After debugging, it appeared that reason is because the two additonal actions that the card is supposed to add are in fact just added to a local variable. This bug was on line 1333 of dominion.c. It was fixed by correctly incrementating the actions count on the game state struct.

* eldriges discovered a bug where the adventurer card is not discarded after it is played. I implemented a fix on line 1325 of dominion.c to discard the card after use by calling the discard method. Before this fix, my own random testing would fail 100% of the time. After the fix, my own random testing would instead fail only 10% of the time. However, since my own tests were still failing, this revealed an additional bug. This bug would occur if there were less than 2 coins in the player's deck and discard.  This was fixed by adding a conditional to line 1305 of dominion.c that would check to see if there are any cards left in a player's hand or discard before continuing the loop. Without this check, we could get array indexes that were outside of the scope of the game and get unpredictable behavior.

In this case, having random testing available for this function was hugely helpful, because it uncovered an obscure bug, and it also allowed me to test the validity of the other results after fixing the one case. If this had been a production system, I would have been much less confident about deploying my fix without the random tests.

* Neither teammate tested the great_hall card. This card had a bug I introduced where player 0 would always receive the card drawn, not the currentPlayer. This was fixed by changing 0 to the current player variable on line 1345 of dominion.c

*/
