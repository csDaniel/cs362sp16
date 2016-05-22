Summary

Before I was able to find the bugs in my teammate's code, or fix them in my own, I needed to fix a couple of bugs I found in my test code. When I ran teh tests against my teammates code, I found a number of errors that were identical between all three sets, but aparently unrelaetd to errors that were part of the original code base. Thi led me to realize that I hadn't properly initialized ome of my test game states. After I fixed the issue, I was able to effectively test my teammate's code and my own.

In testing, I discovered that good coverage was helpful in catching some bugs, but that unit tests with explicit return values were the most helpful in catching problems in functions used by all the other functions. For example, bugs that I found related to the number of cards in a player's hand or discard hand after calling the playAdventurer function could be from the adventurer function or from one of the functions that the playAdventurer function calls. Unit tests of the discard, draw and end turn functions offered much more insight into those problems even though it didn't increase coverage. 

Bugs Fixed:
Adventurer

I replaced the 'else' statement that had been removed so that the treasure hands are now added to the current player's hand instead of being discarded.
This was a bug that I introduced and it also resolved bug #1 found by Alisha Crawley and bugs #3 and #5 found by Brandon Swanson.

I added a conditional in the while loop to check that there are still cards in the deck and discard pile. This fixes bug #4 found by Brandon Swanson. The bug caused the game to hang when there were less than two treasure cards available to be drawn.

Smithy:

I returned the trah card to '0' so that the Smithy card is now discarded instead of being trashed.

Salvager:

Fixed the call to the playSalvager function to use the correct parameters.

Embargo:

Fixed the call to discardCard to trash the card instead of discarding it.

Seahag:

Changed it to correctly decerement the deckCount by one and up the discardCount by one when cards are discarded.

scoreFor():
The scoreFor function wa returning the wrong number of points. This was a bug noted by Alisha Crawley in bug #2.
In the for loop used to add points for the card in the players deck, it wa using the discard card count so it was not processing all the cards in the deck.
I resolved the problem by changing the loop to look for 'deckCount' instead of 'discardCount'.

