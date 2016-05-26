
## Smithy (cardtest1)

Smithy had an issue where it was remaining in the hand and altering the order of the cards in hand.

In line 1302 Smithy had the following:

        discardCard(handPos-1, currentPlayer, state, 0);

This was causing the card to discard one of the other cards in hand rather than Smithy.  This has now been amended to:

        discardCard(handPos, currentPlayer, state, 0);

## Adventurer (cardtest2)

Many issues with adventurer:

1. We were not drawing 2 treasure cards with adventurer 
2. If we had no treasure cards in our deck or discard pile we would segfault
3. Adventurer card was not being added to playedPile after being played

These three issues were fixed.

The while loop for adding treasure cards was only looking for `while (drawnTreasure < 1)`, this has been refractored properly to stop the while loop once 2 treasure cards are drawn.

Furthermore, if we don't have treasure cards available, something needs to stop the while loop so that we do not segfault.  This was accomplished by adding a counter for the number of times the deck has been shuffled, and exiting the loop once we have shuffled it twice.  Thus the while condition has become

        while(drawnTreasure < TREASURES_TO_DRAW && shuffleCount != 2) 

Lastly some simple code was added at the bottom to discard the adventurer card after it was played

        discardCard(handPos, currentPlayer, state, 0)

There was a small bug in my unittest for Adventurer were I had the condition checking number of treasure 
cards reversed.  That has now been fixed to show that if we don't have any treasure cards then we should
have the same amount of treasure cards that we had before after playing adventurer. 

## Draw Card

My tests for drawing a card were incorrectly done with the assumption that the
`discardCard()` function was supposed to discard a card to the discard pile.  In reality
the `discardCard()` function is supposed to add the card to the `playedCard` pile and at 
the end of the turn the `playedCard` pile is supposed to be transferred into the `discard` pile.

I refracted my `unittest3` test to incorporate this understanding and now all of the tests pass.

I feel a 'bug' in of itself is naming this function `discardCard` as its purpose does not at all serve
to discard a card but rather flag a card to be discarded by adding it to the played pile.  The 'garbage'
cleanup at the end of a player's turn should then cycle these cards into the discard pile.

The purpose for this is that cards that you play should not be eligible to be reshuffled into your deck
if another card causes you to draw more cards while your deck is empty.  If your deck is empty
and a card has you draw more cards, you will simply shuffle those cards back into your turn causing
cards that have been played to be replayed.  
