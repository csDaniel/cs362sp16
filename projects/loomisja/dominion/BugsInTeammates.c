Jason Loomis
5/22/2016
Assignment 5: Debugging
Filename: BugsInTeammates.c
Teammates: Osbaldo Esquivel, Preston From

* the following bug reports make use of the Noverse bug report template, with minor modifications. See: http://www.noverse.com/images/noverse-bug-reporting-template.txt

=== Refactoring ===

After copying my teammates code, I found that I was able to apply my unit tests (unittest1.c through unittest4.c, cardtest1.c through cardtest4.c) and my random tests (randomtestadventurer.c and randomtestcard.c)to both of my teammates' code without any refactoring of my test code.

For the tests of the card effects (cardtest1.c through cardtest4.c, and randomtestadventurer.c and randomtestcard.c), this was possible because I wrote my tests to call the cardEffect() function, which, per the assignments, should have been calling the code they refactored for Assignment 2. Since my tests do NOT call the functions they refactored directly, it makes no difference to my tests how they made their changes. That being the case, it is fair to say that my tests for the card effects have very good maintainability--if someone were to make further changes to the implementations of the card effects, my unit tests would still be able to be run without any modifications.

For the tests of the various functions (unittest1.c through unittest4.c), no refactoring was required since my teammates did not change the interfaces for any of the functions that I chose to test. This is expected, since none of our assignments required us to make changes to any of these functions. However, if someone were to refactor these functions when making changes to the dominion codebase, it is possible that my tests would need to be modified to match. Of course, the same would be true for the cardEffect() function, mentioned above, as well. That aside, the fact that I was able to run my tests directly for these functions too indicates that, at least within the scope of the assignments we've done, my tests have very good maintainability.


=== Teammate 1: Osbaldo Esquivel ===

*** Coverage ***
File 'dominion.c'
Lines executed:44.54% of 568
Branches executed:50.60% of 417
Taken at least once:44.60% of 417
Calls executed:25.26% of 95

Executing the suite of unit tests and random tests (cardtest1.c through cardtest4.c, unittest1.c through unittest4.c, randomtestcard.c, and randomtestadventurer.c) on my teammate's code, my tests achieve about 44.5% coverage of dominion codebase and about 50% of the logical branches were executed. This coverage revealed a number of bugs in the code and served to direct my attention to the locations in the code the faults could be found.


*** BUG REPORTS ***

*** Bug Report 1 ***
Title: Multiple card effects applied for one played card.
Classification: Severe (game rules violated, unpredictable behavior)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: Multiple card effects appear to occur when calling cardEffect() to test the effect of a single card, when called for adventurer, council_room, mine, remodel, and smithy cards. I actually found this bug due to excessive running time of the randomtestadventurer.c random testing code; the test had to be aborted.
Reproducible?: Yes.
Steps to Reproduce:
Perform the following steps, or run randomtestadventurer.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure either player to play: adventurer, council_room, mine, remodel, or smithy cards.
3. call cardEffect(), specifying one of the cards mentioned in (2).

Expected Results:
The expectation is for a single card to be played, whichever was chosen.

Actual Results:
Depending on which card is played, multiple card effects will be executed. This manifests itself as multiple cards being played, and accumulation of multiple card effects (e.g. cards added to hand).

Debugging/Fix:
It was necessary for me to fix this bug in order to run some of my tests. The fix is simply to provide a return statement after the call to adventurerPlay(), councilRoomPlay(), minePlay(), remodelPlay(), and smithyPlay() in their respective cases in the cardEffect() switch statement.

Attachments:
randomtestadventurer.c (test for adventurer card effect)



*** Bug Report 2 ***
Title: Incorrect player score calculation.
Classification: Severe (game rules violated, potential buffer overflow/crash)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: For any player whose deck and discard piles contain different numbers of cards when the game ends, the score calculated for that player (may) be erroneous.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run unittest3.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have 1 curse card in his deck and 0 cards in his hand and 0 cards in his discard.
3. call scoreFor() for player 1.

Expected Results:
The expected score is -1 for a single curse card.

Actual Results:
The score calculated by scoreFor() is 0.

Debugging/Fix:
The terminating condition for the "score for deck" for-loop in scoreFor() is incorrect. That loop should terminate based on "i < state->deckCount[player]", NOT based on state->discardCount[player].

Attachments:
unittest3.c (test for scoreFor() function)



*** Bug Report 3 ***
Title: Council Room effect draws too many cards.
Classification: Severe (game rules violated)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: Playing the council_room card results in the player drawing 5 cards into his hand, instead of the expected 4.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run cardtest3.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have a council_room card to play, and at least 5 cards available in his deck + discard.
3. call cardEffect(), playing the council_room card from any handpos.

Expected Results:
The council_room should cause the player to draw 4 cards into his current hand.

Actual Results:
The council_room actually causes the player to draw 5 cards into his current hand.

Debugging/Fix:
The terminating condition for drawing cards in the councilRoomPlay() function is incorrect; the for-loop executes 5 times, where it should only execute 4 times.

Attachments:
cardtest3.c (test for council_room card effect)



*** Bug Report 4 ***
Title: Adventurer card not put in played pile.
Classification: Severe (game rules violated)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: After calling cardEffect() to play the adventurer card, the adventurer card is not added to the pile of played cards.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run randomtestadventurer.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have an adventurer card to play.
3. call cardEffect(), playing the adventurer card from any handpos.

Expected Results:
An adventurer should end up in the played pile after the cardEffect() function called.

Actual Results:
There is no change to the played card pile after calling cardEffect() for the adventurer card.

Debugging/Fix:
The discardCard() function must be called after the adventurer logic has completed. This could be after the call to adventurerPlay() in the cardEffect() function switch-statement, or prior to adventurerPlay() returning.

Attachments:
randomtestadventurer.c (test for adventurer card effect)




=== Teammate 2: Preston From ===

*** Coverage ***
File 'dominion.c'
Lines executed:44.05% of 563
Branches executed:50.24% of 418
Taken at least once:44.26% of 418
Calls executed:23.66% of 93

Executing the suite of unit tests and random tests (cardtest1.c through cardtest4.c, unittest1.c through unittest4.c, randomtestcard.c, and randomtestadventurer.c) on my teammate's code, my tests achieve about 44% coverage of dominion codebase and about 50% of the logical branches were executed. This coverage revealed a number of bugs in the code and served to direct my attention to the locations in the code the faults could be found.


*** BUG REPORTS ***

*** Bug Report 1 ***
Title: Incorrect player score calculation.
Classification: Severe (game rules violated, potential buffer overflow/crash)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: For any player whose deck and discard piles contain different numbers of cards when the game ends, the score calculated for that player (may) be erroneous.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run unittest3.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have 1 curse card in his deck and 0 cards in his hand and 0 cards in his discard.
3. call scoreFor() for player 1.

Expected Results:
The expected score is -1 for a single curse card.

Actual Results:
The score calculated by scoreFor() is 0.

Debugging/Fix:
The terminating condition for the "score for deck" for-loop in scoreFor() is incorrect. That loop should terminate based on "i < state->deckCount[player]", NOT based on state->discardCount[player].

Attachments:
unittest3.c (test of scoreFor() function)



*** Bug Report 2 ***
Title: Smithy card not put in played pile.
Classification: Severe (game rules violated)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: After calling cardEffect() to play the smithy card, the smithy card is not added to the pile of played cards.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run cardtest1.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have an smithy card to play.
3. call cardEffect(), playing the smithy card from any handpos.

Expected Results:
A smithy should end up in the current played pile after the cardEffect() function called.

Actual Results:
There is no change to the current played card pile after calling cardEffect() for the smithy card.

Debugging/Fix:
The discardCard() function is called after the smithy logic has completed, but when the smithy card is discarded, it is trashed (discardCard called with trashFlag parameter of 1), causing it to vanish from the game instead of being added to the played pile. The trashFlag should be set to 0 with this call.

Attachments:
cardtest1.c (test of the smithy card effect)



*** Bug Report 3 ***
Title: Smithy effect removes too many cards from the deck.
Classification: Severe (game rules violated)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: Playing the smithy card results in 4 cards being removed from the player's deck.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run randomtestcard.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have a smithy card to play, and at least 4 cards available in his deck + discard.
3. call cardEffect(), playing the smithy card from any handpos.

Expected Results:
The smithy should cause 3 cards to be removed from the current player's deck.

Actual Results:
The smithy actually causes 4 cards to be removed from the current player's deck.

Debugging/Fix:
The terminating condition for drawing cards in the smithyCard() function is incorrect; the for-loop executes 4 times, where it should only execute 3 times.

Attachments:
randomtestcard.c (test of smithy card effect)



*** Bug Report 4 ***
Title: Adventurer card not put in played pile.
Classification: Severe (game rules violated)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: After calling cardEffect() to play the adventurer card, the adventurer card is not added to the pile of played cards.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run randomtestadventurer.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have an adventurer card to play.
3. call cardEffect(), playing the adventurer card from any handpos.

Expected Results:
An adventurer should end up in the played pile after the cardEffect() function called.

Actual Results:
There is no change to the played card pile after calling cardEffect() for the adventurer card.

Debugging/Fix:
The discardCard() function must be called after the adventurer logic has completed; this should be just prior to the adventurerCard() function returning.

Attachments:
randomtestadventurer.c (test of adventurer card effect)



*** Bug Report 5 ***
Title: Adventurer card effect buffer overflow if no treasures available.
Classification: Severe (game rules violated, buffer overflow, crash)

Date: 5/17/2016
Reported By: Jason Loomis
Email: loomisja@onid.oregonstate.edu

Product: dominion.c
Version: n/a
Platform: CentOS Linux release 7.2.1511 (flip.engr.oregonstate.edu)

Description: After calling cardEffect() to play the adventurer card, if the player's deck + discard contains 0 treasure cards, the card effect causes an unpredictable number (more than MAX_DECK/MAX_HAND) of cards to be removed from the player's deck + discard.
Reproducible?: Yes
Steps to Reproduce:
Perform the following steps, or run cardtest2.c, which does so automatically:
1. Initialize a new game:
    a. call initializeGame with 2 players, a Kingdom cards consisting of {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall}, and a seed of 500.
2. Configure player 1 to have a hand containing 5 adventurer cards, a deck containing 5 estates, and a discard containing 0 cards.
3. call cardEffect(), playing the adventurer card from any handpos.

Expected Results:
Since no treasures are available, the adventurer card effect should iterate over all cards in the player's deck + discard and ultimately cause no cards to be added to the player's hand or be removed from the deck.

Actual Results:
An unpredictable (very large) number of cards are removed from the player's hand, deck, and discard. Game state integrity is compromised.

Debugging/Fix:
Within the adventurerCard() function, logic must be added to keep track of the number of times the deck is shuffled--if no treasures are available, as it is written, the function will continue iterating through the deck over and over (finding nothing); the function should terminate if it finds that it needs to shuffle the discard into a new deck more than once.

Attachments:
cardtest2.c (test of adventurer card effect)