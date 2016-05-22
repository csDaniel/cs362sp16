/*
Ben Beckerman
CS 362
Assignment 5
May 22, 2016

Tests run on eldridgs code:

Smithy Function:
* The unit test for the card function uncovered two bugs:
  - The number of cards in the player's hand should have gone up by two after playing the smithy. Instead it increased by 1.
  - The Smithy was not added to the player's stack of played cards.

Village Function:
* No bugs were found with the unit test.
* No bugs were found with the random tests.

Adventurer Function:
* The unit test uncovered the following bug:
  - With multiple treasures in the deck, the player's hand size should have increased by 1. Instead it stayed the same size.

* Random testing uncovered the following bugs. They may all have the same root cause, but manifested in different ways:
  - Two money in deck or discard, so number of coins should be +2 in hand and -2 in deck, but was not.
  - One money in deck or discard, so handsize should stay the same, but did not.
  - At least two money in deck or discard, so handsize should increase by 1, but did not.


Tests run poolj code:

Village Function:

Adventurer Function:

Smithy Function:


*/
