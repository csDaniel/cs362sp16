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
  - Two coins in deck or discard, so number of coins should be +2 in hand and -2 in deck, but was not.
  - One coin in deck or discard, so handsize should stay the same, but did not.
  - At least two coins in deck or discard, so handsize should increase by 1, but did not.


Tests run on poolj code:

Village Function:
* No bugs uncovered with unit test.

Adventurer Function:
* Bugs uncovered with unit testing:
  - Expected handsize to increase by 1 with two treasures drawn. Instead, handsize decreased by 2.
  - Expected total number of treasures in player's deck, hand, and discard to stay the same. Instead, it changed.

* Bugs uncovered with random testing:
  - Two coins in deck or discard, so number of coins should be +2 in hand and -2 in deck, but was not.
  - One coin in deck or discard, so handsize should stay the same, but did not.
  - No coins in deck or discard, so handsize should decrease by 1, but did not.

Smithy Function:

* Unit test uncovered 2 bugs:
  - Expected hand size to increase by 2 after smithy was played. Instead it increased by 3.
  - Expected deck size to decrease by 3. Instead, decreased by 4.

For both teammates by test suite had to be altered to account for the different method names, and different arguments. In the case of Susan's code, I also had to make some alterations to the test suite, since she did not provide the player to her methods. Instead, I had to set the current player variable of the test suite.
*/
