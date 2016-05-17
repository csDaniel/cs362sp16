/*
Aaron Sealy
Assignment 4
CS 362
Spring 2016

randomhistory.c

I started out by using the card requirements and basic sequence of tests
from the previous unit tests for the Great Hall and Adventurer card.

I changed the tests to make them random by placing everything in the previous
functions inside of a larger for loop that will cycle through several thousand
iterations, each of which will have a different randomly generated seed.

This went well with the Great Hall Card.  The test had 100% coverage of the
function and the results were the same as with the unit tests. I.e. Tests 1
and 4 consistently fail, while Tests 2 and 3 pass.  Failures may be due to my
bug (see refactor.c).

Everything worked fine with 5000 random tests of the Great Hall Card (see below)
, but today flip is hanging during this test, and even modifications with a few
thousand less attempts.  Nothing has changed.  I am not sure if this is due to
flip having problems or if it is a problem with the code.  It worked before, so
I will move on for now.

(Here is what was produced earlier today:
Testing Great Hall card:
TEST #1 failed 5000 of 5000 tries
TEST #2 failed 0 of 5000 tries
TEST #3 failed 0 of 5000 tries
TEST #4 failed 5000 of 5000 tries
...Function 'greatHallCard'
Lines executed:100.00% of 6
No branches
Calls executed:100.00% of 2
...File 'dominion.c'
Lines executed:20.92% of 564
Branches executed:22.89% of 415
Taken at least once:14.46% of 415
Calls executed:11.58% of 95 )

Trying to narrow it down...
It still works with 1000 iterations.
It still works with 1500 iterations.
It still  works for 1900 iterations
... It hangs at 1990 iterations
... It hangs at 2000 iterations
BUT it ran fine with 2500 iterations.
And now it does not run with 2500..
I am assuming there is a flip problem or high usage that is causing the issue.
I will just leave it at 1900 iterations and include the section of the .out
results above that show it had the same results earlier with 5000 iteration
(Test 1 and Test 4 fail each iteration and Test 2 and 3 pass each iteration).

With the adventurer card, however, there was the same problem as with the
previous tests.  The original bug and my added bug discussed in refactor.c
make the function so buggy that it crashes every time and I can't even get a
make file to run because the function crashes everything as it is.
We never got proper explanations of what to do in this case.

I guess I will temporarily remove my bug so the make file can run and it
should still catch the other bug.

It is still crashing and giving segmentation faults when I try to make it.
I am not sure how to resolve this.  Related questions were asked on Piazza
with no instructor response.

I re-wrote randomtestadventurer.c so it compiles.  It has 3 minimum tests
and the following output is produced:

Testing Adventurer card:
TEST A failed 2000 of 2000 tries
TEST B failed 2000 of 2000 tries
TEST C failed 2000 of 2000 tries

Function 'adventurerCard'
Lines executed:94.12% of 17
Branches executed:100.00% of 12
Taken at least once:75.00% of 12
Calls executed:50.00% of 2
...
File 'dominion.c'
Lines executed:20.74% of 564
Branches executed:24.22% of 417
Taken at least once:15.83% of 417
Calls executed:10.53% of 95

The fails are expected due to the numerous errors with this card, including
discard issues and my errors, discussed in refactor.c







*/
