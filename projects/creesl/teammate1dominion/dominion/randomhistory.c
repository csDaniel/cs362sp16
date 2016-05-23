/*
With the random tester function for the adventurer card, the function adds 20 random cards to each players deck and
ensures that the effects are as they should be regardless of the variety of cards. Cards should still be taken from the
deck until the function finds two treasure cards, at which point all cards drawn except for the two treasure cards are
added to the discard pile. The test function tests that each players hand is increased by one and that cards are added
to the discard pile. Even if the function finds two treasure cards first the adventurer card should still be added to
the discard pile. The function also tests that two new treasure cards were added to the players hand and not other
cards.

The other random tester function tests the council room effect function and does so in much the same way. It adds 20
cards to the player's deck and makes sure the function behaves appropriately. This makes sure that there isn't any weird
behavior depending on what cards are available in the deck. The cards added can be any cards but the three main victory
cards. After the cards are added it tests that the council room effect function increments the number of buys by 1, that
the handcount of the player has been increased to 8, that the deckcount is equal to 21, since the number of cards
originally was 10 - 5 + 20, that the council room card was added to the discard pile, and that the other players
handcount was increased by 1.

The randomized aspect of the tests checked that the variation of cards that could be in the players deck wouldn't cause
any weird behavior.



*/