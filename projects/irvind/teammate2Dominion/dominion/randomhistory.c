/*

Dane Schoonover
Assignment 4
Random testing coverage

Random test coverage was for the Adventurer card and Great Hall card. 

For the adventurer card, I randomized the parameters taken by the calling function: drawnTreasure, handPos, and numPlayers. Since the total possible combinations of these random inputs is only 40 (2 * 5 * 4), the number of iterations needed to cover all of these scenarios would be based on probability. In this case I just used 100 iterations to get a general sense of the random tests.

For the great hall card, I randomized its input of numPlayers and handPos. This only left 20 combinations to test (within boundaries).


When setting up random ranges for testing variables, nearly all of the tests failed since much of the dominion.c code would catch values exceeding boundary conditions. This was useful for validating that these boundaries had been established, however, it mostly not useful since it did not tell me anything meaningful from the tests. For example, if a bug caused a test to fail, I would not know to check that particular test since so many failed. As a result, I modified the random range values to be within boundary conditions, which caused all tests to pass. The only tests that failed were from the adventurerCard tests.

The random testing could be improved by selecting other gamestate variables that are not necessarily inputs on the functions being tested, but rather necessary components of other functions that are involved with the card effect functions being tested.

The random testing increased coverage of dominion.c by the folllowing:

Before:
Lines executed:36.00% of 650
Branches executed:43.88% of 417
Taken at least once:34.29% of 417

After:
Lines executed:37.23% of 650
Branches executed:44.36% of 417
Taken at least once:35.49% of 417

As seen, there was a slight increase in coverage. It cannot be immediately determined if the slight increase gives any major positive benefits to the overall testing scheme, however, at least more conditionals were tested. If the testing goal for complete coverage, then these random tests would would have brought us closer to that goal.

*/