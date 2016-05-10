How to get randomtestcard.out and randomtestadventurer.out:

There are several ways to get the output files for the random tests depending on what kind of output you want. 

--Verbose
For verbose results (the results and details of each test are printed), you can either run each card's test independently or do them at the same time.
Independently, "make randomtestcardVerbose" will produce randomtestcard.out with the results of each test. (It will likely be over 300,000 lines long.) Similiarly, "make randomtestadventurerVerbose" will produce randomtestcard.out with the results of each test. (It will likely be over 400,000 lines long.) Using "make randomtestresultsVerbose.out" will run both random tests and print the verbose results to a file titled "randomtestsVerbose.out", which will also contain dominion's gcov file text.

--Regular
If you'd prefer not to sift through hundres of thousdans of lines of results, you can alternately use "make randomtestcard" and "make randomtestadventurer" to run each independently. The results, which contain 1 sample of the error results with a large number of problems as well as the total number of problems found, will be output to reandomtestcard.out and randomtestadventurer.out, respectively.
Additionally, you can run the test together using "make randomtestresuls.out", which will produce "randomtestresults.out" containing the results of both tests as well as the gcov information for dominion.c

NOTE ON OUTPUT:
Whether you select verbose output or not, the results files will contain summaries of the number of problems found. These can be used to start pinpointing problems with code. For example, the played cards pile is consistently flagged as having a problem for the adventurer card, because the function does not correctly discard the card itself at the end.

Bugs found:
- Adventurer:
* The adventurer card is not discarded at the end of the function so it stays in the user's hand.
* The function shuffles the discard pile and deck every time it is called, even it is unnecessary.
* The function searches for three treasure cards (instead of the two it should be searching for).
* If there are no treasure cards in the deck or discard pile, the function will loop indefinitely until it causes the program to crash. 

- Smithy:
* The smithy card draws 4 cards instead of 3.
* The smithy card function trashes itself (instead of discarding to the played card pile.

Developing/improving randomtestadventurer and randomtestcard:

In terms of randomizing the game state, there were some initial issues with correctly setting up the game state. After a bit of comparison with the deck initialization function in dominion.c, I realized the problem and eventually created two separate function to handle game state randomization: One function to randomly fill the supply cards and another to fill the hand/deck/discard pile/buys/coins/etc. 

In general, it is unlikely a player would have a deck or discard pile with fewer than two treasure cards in it, but it is possible if the player had trashed all the treasure card and/or held all the treasure cards in their deck in their hand. This was bug was easily discovered with random testing since the cards in the deck/discard pile were randomly assigned. However, since the bug resulted in the the program crashing, it was not possible to complete testing, so I decided to make a note of the bug and code the deck randomizer to ensure that at least three treasure cards were (cumulatively) in the deck and discard pile.

I also found that it was necessary to adjust the number of times the random test for the adveturer card ran. Due to the bug causing the card to shuffle the deck and discard pile every time it is run, testing takes much longer than expected.

In terms of coverage, adventurer had some somewhat lopsided results. For example, since the function incorrectly shuffled the deck/discard pile every time it was run, it rarely needed to shuffle the deck while looking for treasure cards. Additionally, the branch for skipping shuffling the deck was never taken, due to the bug causing the funciton to shuffle every time it is called.

In comparison, the smithy card had good coverage. It's a short function, so hitting every line and taking all the branches is relatively straight-forward. 

As for the coverage of the test functions, since both cards have bugs that occur each time the cards are used, there were some branches that were not covered in terms of checking. For example, the if-statement checking if hand sizes were different executed every time and never fellthrough since the hand size will always be different if either the smithy or adventurer card is used.

Additionally, I did not let the randomizer set the number of players to 0, as this was not a realistic scenerio for the game. Therefore, checks that there were more than 0 players always executed and never fellthrough.

Check specifications:
This proved to be more difficult that expected, since the adveturer card has a large number of problems. I ended up referring to the actual cards as documented for the game online and comparing the adveturer card's code with other cards. I also ended up tracing the code through the phases of the game to ensure that the card was supposed to be discarding itself and to ensure that there was not a clean up phase where used cards were discarded by the game.
