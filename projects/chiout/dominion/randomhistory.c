/*
 
randomtestadventurer.c Random Tester: The randomtestadventuer random tests is written to test the adventuer card in dominion.c. I chose to set up this random tester by using the Random() function in rngs.h to generate different input values. I did this by creating a prepare function that uses Random() to generate different input values for a gameState struct instance called state - specifically the number of players, who the current player is, the number of cards in all the player's hands, decks, and discard piles, which cards make up each player's hands, decks, and discard piles, and the number of cards in the playedCards array. After the values are generated, a copy of state is made for comparison purposes, and then the cardEffect function, in dominion.c, is called to play the adventurer card on state. Afterwards, a checkResults function is called with state and the copy of state to check if the current instance variables of state are expected. All of this equals one testcase in my random function tester, and numerous testcases are generated via a for loop in randomtestadventurer in order to test a large variety of inputs with the adventurer card code.
There were a few design decisions that I made to make randomtestadventuer (and randomtestcard) which were different than my unit tests from the previous week. My unit tests last week only ran around 4 testcases; they were essentially created as manual tests and it made sense to print out all pass/fails. As my random test generators are generating at least 5,000 tests, I felt that printing out successes would make it too difficult to visually isolate the failures so randomtestadventurer and randomtestcard both only print out failures. In addition, I wanted my random tests continue to test the next testcase after one fails. The checkResults function will return 0 if a testcase passes all the result checking and 1 if it does not. Thus, the first time a result check fails for a testcase, an error message is printed and checkResults returns 1. The current player's hand, deck, and discard counts for state and its copy are printed to give testers more information about the failure, and then the program moves on to testing the next testcase.
In the prepare function, the deck count value is any value from 0 to MAX_DECK, the hand count is any value from 0 to MAX_HAND, and the discard count is any value from 0 to MAX_DECK - deck count. After running the random tester on my refactored dominion.c, it was able to catch the first bug that I introduced in every single testcase - which was that the deck and discard were not missing 2 cards. Since my random tester stops checking results after finding the first bug in the testcase, I fixed this bug and ran the randomtester again. The same error came about for most, if not all, the testcases - that the deck and discard are not missing 2 cards which makes sense because my second bug prevented the right number of cards from being discarded.
After fixing the second and last bug that I introduced, I kept getting 2 different types of errors that did not initially make sense to me, based on having I fixed the bugs that I introduced to dominion.c. One error was that in a very small percentage of testcases, one of the other player's counts or arrays would be changed. However, further analysis of the issue showed that this was in fact an issue that would arise in boundary cases and not something that I had considered when developing my random tester. In all the failure cases, the current player had 501 cards in the hand, which means that the current player was adding more cards to the hand array than the hand array had space for, and this overflow of data was corrupting data for the other player's. While is may be useful to have code in place, in dominion, to check for this, it is also unlikely that this would happen in the actual game as there would not be enough cards in an actual game for this to happen. In response to this discovery, I chose to add in code that would prevent the error from popping up if the current player's hand count is 501. I could have chose to modify the prepare function values so that only MAX_DECK cards are in play but I chose not to, as giving more liberties to the inputs generated can point out boundary cases such as this one. It would be a good idea, though, to test adventurer card with a random tester that only generates inputs so that MAX_DECK cards are in play.
The other error I hit was an error where the deck and discard arrays were not missing 2 cards, the hand count only gained 1 card, and the deck count was 0 after the adventurer card was played. After some analysis, I deduced that this error may have resulted from a situation where the deck and discard piles do not have 2 treasure cards and all the cards are drawn until the deck and discard are empty. When this happens, drawCard does not work and returns -1, and the last card in the hand array is evaluated as the drawn card, even though no card is drawn. This situation may possibly happen in the real game, and there should be code implemented to deal with it, such as letting the user know that playing the adventurer card is not possible. I tested this against the dominon.c without my refactored code and also found this error.
Overall, randomtestadventuer.c has covers 12.94% of 564 lines when I ran 5000 testcases in the random tester's for loop. Running 5000 testcases in the random tester, where every testcase is one run of dominion.c, proved to provide good statement coverage. GCOV analysis shows that all the statements in the compare, shuffle, drawCard (except the DEBUG statement), and refactored adventurer function were executed. GCOV did not register counts for some of the intialization variable statements, but they definitely were executed. As statement coverage was good and the random tester was able to catch a good number of bugs in dominion.c, I believe that running 5000 testcases in randomtestadventurer.c was sufficient.

randomtestcard.c Random Tester: I developed the randomtestcard.c random tester to test the Great Hall card in dominion.c. A design design that I made when coding randomtestcard.c was to utilize the code that I wrote for randomtestadventurer.c and make appropriate modifications to ensure that it would be tailored to testing and validating results for the Great Hall card. This decision was made because although the great hall card does different things to the data in a gameState struct, it still requires a gameState with similar valid, interesting input for each players' card piles to test. A drawback to this approach could be that by having somewhat similar random testers, there is a lack of diveristy in how the gameState inputs are being generated but at the same time, the prepare function does generate a lot of input that can cover a lot of different input combinations and boundary conditions, as long as enough testcases are generated and run.
For this random tester, I added cards into the played card array, based on the played card count, and I also generated a random value between 0 to 5 for the number of actions. I did not refactor the great hall card code, so when I tested this against my refactored dominion.c, none of the tests failed. I also tested this against the un-refactored dominion.c, just to check, and it also returned no failed tests. randomtestcard.c covers 12.41% of 564 lines of code in dominion.c with 50,000 testcase runs, where each run is one execution of the great hall card in dominion.c. GCOV analysis showed that 100% statement coverage was not achieved. The function compare and the great hall code had 100% coverage. The shuffle function had almost 100% coverage except for the return statement that executes when the deck is empty - and since drawCard calls shuffle after it moves discard cards over to the deck if the deck is empty, that line of code would never execute in shuffle unless both the discard and deck was empty. The drawCard function also has a return statement that did not execute because the deck and discard were not empty. Therefore instead of trying to brute force a situtation where both deck and discard arrays were intialized as empty, I decided to manually add this boundary condition so that it would be excuted at least once. After running the random tester again, the testcase with this boundary condition failed because a card was not drawn and the player still discarded a card. This may be how the game would handle the situtation if the deck and discard though as it does not really violate the rules of Great Hall so I added an additional message in randomtestcard to disregard if this is acceptable behavior - but it is good to be aware of it.
 Adding that boundary case gave drawCard and shuffle 100% statement coverage, except the DEBUG statements in drawCard. GCOV analysis showed that the modified random tester's coverage increased to 12.77% of 564 lines. The only function that did not have complete statement coverage was the discardCard function but based on how the function is written, it is not possible to get 100% statement coverage. In the if/else-if/else loop, the else-if statements can never be reached because if the handCount is 1, then the card is in position 0 which is one less than the handCount. The condition in the if statement covers the scenario where the card position is one less than the hand count - thus if the player only has one card, the body of the if statement will execute.
 



*/