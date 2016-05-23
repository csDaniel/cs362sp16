/*
Ben Beckerman
CS 362
Assignment 5
May 22, 2016

Bugs Found by Teammates:

* Both teammates discovered a bug where the Smithy was trashed instead of discarded after it was played. Debugging revealed that the cause of the problem is on line 1295 of dominion.c. A flag was set on the discardCard function that is called in the smithy method that caused the card to be removed from the hand but not added to the discard pile.

* poolj discovered a bug where the correct number of actions is not set in the village function. After debugging, it appeared that reason is because the two additonal actions that the card is supposed to add are in fact just added to a local variable. This bug was on line 1333. It was fixed by correctly incrementating the actions count on the game state struct.

* eldriges discovered a bug where the adventurer card is not discarded after it is played.

*/
