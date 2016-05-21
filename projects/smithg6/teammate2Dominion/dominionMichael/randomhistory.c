/******************************************************************************

Michael Hueter
CS 362 Assignment 4
randomhistory.c - Analyzing random test ideas for cards

1. Overall Process

Random testing is hard! I learned just how difficult it is to select which
inputs are appropriate / testable. The random tests I wrote were extensions
of the unit tests in some ways because they used similar assertions, however,
my goal was to randomly generate different game state variables to see what kind
of scenarios would result. The results were startling!

The specific states I manipulated were: number of players, size of deck / hand,
random seed, and which cards were in play for each game. This should have
generated a truly random set of game states. I decided that 9000 tests would be
sufficient to generate significant variety in a short amount of time. I used a
pseudo-random seed based on ctime for each iteration.

2. randomtestadventurer

Over the 9000 times I ran this, I got about 25000 assertion errors. The treasure
card assertion errors were expected, but it is interesting that it did not fail
each time. There were 2 treasure assertions so it should have failed 18000 times
but it only failed ~17964 times. This must be due to coincidence of the hand positions
having treasure cards, not due to actually having drawn treasures because I broke
the code. If I were to improve this test I would account for testing only things
that were actually drawn.

Strangely, there were about 7100 player 2 failures and 13 discard failures. This
is startling because my code shouldn't have broken this part of the program.
These results are things that the unit test did not find last week and must be
therefore due to varying states being less stable.

3. randomtestcard

I also tested the playVillageCard function that I wrote, and it did not fail
perfectly all the time. The actionFailures should be consistent at 9000, but
there were only 1800 or so. Likewise, there were a similar amount of player 2
and discard failures like in the last test. There must be something unusual
about my tests setting up different states of the game. Further investigation is
needed.

4. coverage

Compared to the 2 unit tests, the coverage improved slightly, by about ~5%. This
is very interesting and probably due to the different states of the game. I
suspect the additional branches taken may reveal some of the infrequent bugs I
discovered. For example, there was a return -1 branch executed 13% of the time
in shuffleCard(), and some of the sort functions therein were not executed each
time. Regarding the state, I believe my tests either have a faulty premise
somewhere or the game cannot handle them properly. 


******************************************************************************/
