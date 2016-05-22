/*

Author:James Taylor
Date: 5/21/16

Assignment 5: Run my test suite on my teammates refactored code.



Teammate 1 results: cuellarj

Bug report:
        smithy card: cards in hand did not match expected count.
            Bug 1: From test results: FAIL: Player hand count of 9 not equal to 7

            code inspection revealed that 6 cards were being drawn instead of the expected 3 resulting in count discrepancy.

            int callSmithyCard(struct gameState *state, int currentPlayer, int handPos){
            int i;

            //+3 Cards
        --> for (i = 0; i < 6; i++){
            drawCard(currentPlayer, state);
            }

            //discard card from hand
            discardCard(handPos, currentPlayer, state, 0);
            return 0;
            }

            All other tests passed.

        adventurer card: Treasure count did not match expected result
            Bug 2: From test results: FAIL: treasure count is not 2 higher then previous count

            possible issue with hand position counter, secondary test of discard pile passed but visual inspection of the discard with built-in
            print statements within the test code showed far more discards the expected.

            possible location:
            code:
                cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]];



Teammate 2 results: weldonmi
        Adventurer card:
            Bug 1: from test results: FAIL: Discard contains incorrect discards
            This indicates that the code to discard drawn, non-treasure cards is incorrect. Further testing required
            Possible location:
                      while(z-1>=0){
                        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
                        z=z-1;
                        }

        Smithy card: compiling error, i not declared within function.
            Bug 1: variable i not declared
            After altering code to declare i and make the file able to compile:
            Bug 2: FAIL: Player hand count of 5 not equal to 7
            i is passed to drawcard() instead of currentPlayer resulting in only one card being drawn for 3 different players instead of 3 cards for one player
                code location:

                    for (i = 0; i < 3; i++)
                    drawCard(i, state);

        all other tests for smithy passed.


Tests were runnable with only one change to each called function name. Otherwise all tests are usable as is, indicating fairly reasonable maintainability. While
the found bugs were straight forward the tests did reveal all introduced bugs.















*/
