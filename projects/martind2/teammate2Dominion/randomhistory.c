Name: Lauren Miller
Class: CS362
Assighnment: Assignment 4
Date: 5/5/2016

For both tests, the number of players, (between 2 and 4 inclusive), and which player of these would be the one playing the tested card were randomly selected. I initialized the game using initializeGame, since most parts of the gameState would needed to be rewritten if random characters or integer values were used, as the extreme majority of cases otherwise resulted in segmentation faults. However, for the active player, the number of cards in the deck, the discard pile, and hand were randomly selected, using the MAX_HAND and MAX_DECK values. These cards were randomly selected from those enumerated in dominion.h. Boundary cases were relatively rare, but were assured given that values were randomly selected out of moderately-sized sets of options and a sufficient number of these tests were run. A million tests run for both cards took only a few minutes each and had full (possible) statement and branch coverage, as measured using gcov.

Both cards tested, village and adventurer, were also tested using the unit tests written for Assignment 3. The adventurer had significantly better coverage of the and had tests covering more conditions. The better coverage of the relevant parts of dominion was due to the number of tests run. The additional tests written were prompted in part by slightly more thoughrough consideration of conditions in adventurer_card, the refactored adventurer card, and also by the presence of confusing error messages. These rewritten tests, especially for the adventurer, were an attempt to narrow down the source of the error and to remove error messages for valid border cases that were still triggering the error messages.

randomtestcard.out

The village random tests had relatively little modification from the corresponding unit tests written for Assignment 3, and when the number of tests run were relatively small, it seemed like all relevant conditions were tested. All of the tests were passing, at least. However, when the number of tests was increased to a million, a small number of error messages were output, indicating that there were not the correct number of cards added to the hand of the active player, (the village gives the active player two actions and one card). When the error messages were modified to output more information, about the number of cards in the discard pile and deck, it showed that these error messages were output in the rare cases where there were no cards available for the player to acquire in either the deck or discard pile, and so no card was added to the player's hand. The tests were modified accordingly, to allow this condition to pass without printing an error message.

randomtestadventurer.out

The random tester for the adventurer was significantly improved from the adventurer tests for Assignment 3. Some of the improvements were made in a concious attempt to have better coverage of boundary cases. For example, after improving the random tester for village, I adjusted the conditions for my error statements to accept having no cards added to the hand, (the adventurer adds two treasure cards from the deck and discard pile, if necessary, to the active player's hand), if there were no cards in either the deck or discard pile. After error messages were still returned, I realized both that the condition of there being only one card in the deck or discard pile was not covered, and that no cards should be added to the hand if there were a sufficient number of cards but they were not treasure cards. I counted the gold, silver, and copper cards in these two piles before running playing the card, and adjusted the tests to include conditions for there being no treasure cards available, one treasure card available, and two or more, as these three situations should result in different numbers of cards added to the hand.

There were known errors already, that there were incorrect numbers of cards added to the hand. However, the attempt to clarify the exact situations in which error messages were produced and to remove error messages produced will valid input/effect combinations did clarify the situation, and revealed that there might be multiple problems in the code, multiple sources, producing the same error message. For example, when there was 0 treasure cards available, there were either too many or too few cards added to the hand, and in inconsistent amounts. However, when there was only 1 treasure card available, the net number of cards added to the hand was either 1 or 2, when there should be 0. It seems likely that the source of this error was at least partially separate from the one adding or removing cards from the hand when there are 0 treasure cards available. It might be partially related, however, to the source of the error when there are 2 or more treasure cards available. In this case, there is a net of 2 cards added to the hand when there should be 1, the adventurer card played being removed and the two treasure cards added. 

It was also found that when a treasure card was not the last card in the hand, it was often an adventurer card, and that no treasure cards had been added. Likewise, checking whether the second to last card in the hand is a treasure card reveals that it is sometimes also an adventurer card, but that this only occurs when there are 2 treasures in the discard and deck piles, whereas the other situation occurs when there are many more treasure cards available, so this may be unrelated to the previous problem. Showing only these two error messages indicates that these two error messages are not produced for the same test. 

Some of these failing conditions were found in an attempt to discover a consistent pattern of error and some in an attempt to confirm that these errors were not the result of some boundary condition like there being 0 or only 1 card, for example.