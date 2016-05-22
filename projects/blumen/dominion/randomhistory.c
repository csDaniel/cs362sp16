Nathalie Blume
CS362
Assignment 4: randomhistory.c


*GOAL AND DEVELOPMENT OF THE TEST SUITES

General Principle of "Random Testing":
    A random tester generates random input from across the population of possible input.
    Sampling biases may be introduced to ensure that specific subpopulations are sufficiently tested.

Assignment: Two random testers were implemented to target the adventure and the remodel cards.
    Each runs through 100,000 loops. In each loop, a new seed is selected and is saved to file
    so that interesting results may be reproduced. At each iteration, random input is generated
    as indicated in the function. The card is then played and the outcome of the play is compared
    to the programmer's expectations. Successes and failures to pass these tests are printed to
    the file for later examination.

testSuite1.c calls the test function randomtestadventurer(), which tests thes adventure card.
    The command make randomtestadventurer.out generates a file that displays the results of
    running the function.

    Random input for the remodel card:
        - the size & composition of the player's hand, deck and discard are randomized + discard pile is stuffed with 2 treasury cards
        - the size & composition of the other player's hand, deck and discard are randomized
        - the number of buys, actions and coins are randomized
        - the sizes of the kingdom, treasury, curse and victory piles are randomized

testSuite2.c calls the test function randomtestcard(), which tests the remodel card.
    The command make randomtestcard.out generates a file that displays the results of
    running the function.

    Random input for the remodel card:
        - the size & composition of the player's hand, deck and discard are randomized
        - the size & composition of the other player's hand, deck and discard are randomized
        - the number of buys, actions and coins are randomized
        - the sizes of the kingdom, treasury, curse and victory piles are randomized
        - the place in hand of choice1, the card to trash (include error positions)
        - the type of card to trash (incl. its cost, treasury vs. etc., cost relative to choice2) --> this is achieved indirectly through combo random hand + choice1= random place in hand
        - choice2 (incl. its cost, treasury vs. etc.)
        //ALT: I could have set specific choice1 and 2 and their cost dif, but would lost the benefit of the randomization scheme

testSuite.c calls 10 test functions. Two of these are random tests of the adventure and remodel cards.
The others are from Assignment 3: Four test methods and 4 test card implementations in cardEffect().
The purpose of this test suite is to consider how much coverage is achieved across all tests I;ve written
so far for the class.

call: make unittestresults.out

The following cards are tested through random testing:
    adventurer              implemented in randomtestadventurer.c
    remodel                 implemented in randomtestcard.c

The following methods are tested:
    updateCoins()          implemented in unittest1.c
    discardCard()          implemented in unittest2.c
    buyCard()              implemented in unittest3.c
    isGameOver()           implemented in unittest4.c

The following cards are tested:
    smithy                 implemented in cardtest1.c
    adventurer             implemented in cardtest1.c
    feast                  implemented in cardtest1.c
    council_room           implemented in cardtest1.c


*COVERAGE ACHIEVEVED BY TEST SUITE: OVERVIEW

The cummulative code coverage of dominion.c achieved by testSuite.c is:

File 'dominion.c'
Lines executed:37.57% of 559
Branches executed:39.17% of 411
Taken at least once:27.74% of 411
Calls executed:28.87% of 90

The cummulative code coverage of dominion.c achieved by testSuite.c WITHOUT the random testing of
the adventure card and WITHOUT any testing of the remodel card is (ref: Assignment 3):

File 'dominion.c'
Lines executed:34.49% of 548
Branches executed:40.53% of 417
Taken at least once:26.38% of 417
Calls executed:25.56% of 90

* DISCUSSION

--Line count

Differences in line count may be due to slight changes to the master dominion.c file (admitedly I
haven't checked).

--Coverage

The important figures are the percentages. Was coverage increased much through the introduction
of random testing? Not much. There was little opportunity for random testing to change the number
of lines, branches and function calls executed during a trial. In the remodel function, some play
input would mimic a player who selected too expensive a card in exchange for one in his or her hand,
which would set off an error-catching conditional branch. In the adventurer function, some play input
would mimic a player whose deck was exhausted, which would set off a discard-shuffling conditional
branch. These two branches only account for 2 additional lines of coverage, and 1 of these is from
the remodel card, whose code was not covered at all previously. The bulk of the increase in coverage
(from 34.49 to 37.57%) comes from testing the remodel code, independently from random testing.

--Specifications

Random testing was valuable in detecting failures of the dominion.c code.

In particular, in remodel, it uncovered a faulty implementation of a conditional that aims to catch whether the
card the player requests is too expensive. This is the faulty code:

    if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
	{
	  return -1;
	}

choice1 is the card in hand and choice2 is the card desired. The remodel card requires that choice2
cost no more than 2 coins more than choice1. However the conditional returns an error code (-1)
whenever choice2 costs less than 2 coins more than choice1. The comparitor is in error.

This error was revealed in trials such as one with seed 1793632003. The return value of cardEffect()
was expected to be -1, denoting an error; instead it was 0, denoting no error. Other tests failed
in a predicttable way given that the play was completed when it was expected to be aborted.

Another error uncovered by the test in remodel is a failure to trash the card that corresponds to choice1.
This is the faulty code:

    	      discardCard(i, currentPlayer, state, 0);

The flag is set to 0, which leads the card to be discarded. The correct flag should be -1, leading
it to be trashed.

A third error, in Adventurer this time, is that drawCard()'s return value is never tested in the
implementation of Adventurer. When the deck is empty, this is not detected and the play is erroneous.

