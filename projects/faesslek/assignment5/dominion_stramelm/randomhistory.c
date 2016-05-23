--------------------------------------------------------------------------------
Stramel CS362 Assignment 4 Results
--------------------------------------------------------------------------------

For this assignment I wrote random testers for two dominion kingdom cards:
  - smithy
  - adventurer

The testers are included in files randomtestcard.c (smithy) and
randomtestadventurer.c.  The makefile was udpated to faciliate this testing.
The code can be compiled and run by typing the following command at the prompt:
  "make randomtestresults"

I had previously written unit tests for these same cards.  Therefore, I treated
these new tests as an expansion of previous work.  I already knew the types of
card behavior that I would be testing for.  These include the following:
  - does the function complete successfully
  - does the current player end up with correct number and type of cards
  - do the new cards come from the current player's pile
  - does the function change the state of other players hands or piles
  - does the function change the state of victory or kingdom card piles

Given that I knew what behavior I'd be testing for, the challenge was more
about how to create random inputs instead of the fixed inputs from my unit
testing.  Additionally, I needed a way to report the inputs that drove test
failures since they were being generated on the fly.  The developer cannot
be expected to fix and error I detect if I cannot tell him what caused it.

There were two primary methods that I used to generate the state of the game
prior to calls to the cards:
  - I could use the initializeGame() function as coded to setup the game.  This
    method required that I randomize the inputs to the initializeGame() function
    which include a list of kingdom cards, number of players in the game, and
    see value.

    This method has the advantage of having a gamestate that is somewhat more
    rational because initializeGame() uses the actual rules of the game to
    ensure that the proper number of types of cards are in place.  The
    disadvantage is that the state isn't as random as the next method.

  - I could allocate a memory buffer for a gameState struct and then fill it
    with randomnly generated bytes.
    
    The advantage of this method is that the game state is significantly more
    random, however it may consists of sub-states which are outside the realm
    of the rules of the game.  For example, very large numbers of cards,
    negative numbers of cards, etc.  This is okay though because we are testing
    the code for a particular function and we can't guarantee the validity
    of the inputs passed to it.

    The biggest disadvantage of this method is that it drives a large number
    of inputs that create memory read errors (segmentation faults).  Segfaults
    by definition shut down the process an impede our ability to continue
    testing.  Therefore, some additional (but still random) massaging of select
    substates was necessary after the random byte generation.

Ultimately I used both methods described above and alternated back and forth as
I iterated through the test loops.

Individual error reports, summary error reports, and coverage summaries are
included in the files randomtestcard.out and randomtestadventurer.out.  Because
I was running a large number of tests that could generate a significant number
of errors, I set up the code to only print the individual error reports for the
first detected error of a particular type.  For example, there is a check in
smithy for "no state change for other players" that failed 58 times.  Only the
report for the 1st of these 58 failures is included.  This is primarily to keep
the file manageable.

Individual error reports consist of the particular error that was detected and
the specific inputs that drove the error.  In terms of the gameState, I
initially wrote a function printMemory() that would print the first N bytes of
the gameState struct.  But later I decided it would be useful to just print
the actual struct values.  I did this with a different function I wrote called
printState().

In terms of coverage, I was able to achieve 100% coverage with the smithy card
in just one test.  That's to be expected because it's a very simple card.  I
was also able to achieve a high percentage of coverage with the adventurer card
with a relatively low number of tests.  In the end, after adding game states
built on randomly generated bytes I was able to acheive 100% coverage for the
adventurer card.  During the unit testing assignment I was only able to achieve
83% coverage for adventurer so this is definitely an improvement.

Because I was able to achieve high coverage with a relatively low number of
tests for each card I wondered how many tests should I actually run.  I then
experimented with running 10^1, 10^2, 10^3, 10^4, 10^5, and 10^6 tests per card.
The primary thing of interest is that I noted that some errors would appear only
intermittently if I was running 10^4 or less tests - meaning that I would run
the tests and get a particular type of error and then run the same suite and not
get that same type of error.  I knew I need to run enough tests to consistently
trigger each type of error.  Running 10^5 tests per card was enough to get
consistent error triggering.  10^6 tests per card provided no additional
benefit.

The other thing I noted was that I was able through random testing to detect
all of the same errors I had detected through unit testing plus a few new ones.

For the smithy card, my unit tests had detected an error with the placement
of cards from hand into discard pile.  My random testing detected the same
error which occurred in all 10^5 tests due a basic flaw in the function logic.
However, my random tests also generated an error related to leaving the other
players' states unchanged.  58 individual failures out of close to 5*10^5 tests
were generated using random testing.  The number of tests in this case is
larger than 10^5 due to the variable number of "other players" during each
iteration.

For the adventurer card, four types of errors were detected.  Similar to the
smithy card, one of these was new and was related to leaving other players
states unchanged.
