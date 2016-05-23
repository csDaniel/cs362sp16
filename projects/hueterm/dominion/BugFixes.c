/******************************************************************************
Michael Hueter
CS 362 Assignment 5
BugFixes.c - documentation of bugs in my code that I fixed

Card Bugs:

-- Fix #1 playAdventurerCard()
    The bug here was introduced in assignment 2. It consisted of me failing to
    initialize 'drawntreasure' to zero. This was successfully reported by both
    Jessica and Grant. I used GDB to step into the function and measure the
    value of 'drawntreasure', and it definitely was referencing a memory
    location because it was in hexadecimal. I fixed this card function and
    now the relevant unit tests are all passing.

-- Fix #2 playSmithyCard()
  The bug here was introduced in assignment 2. It was me flipping the i < 3
  iterator to i > 3. I put a break point at this place with GDB and it skipped
  right past it, as expected. So I flipped it back and all my assertions pass
  now. This was successfully reported by Jessica and Grant.

-- Fix #3 playFeastCard()
  The bug here was introduced in assignment 2. I had manipulated the gainCard()
  function call to be outside of an else statement. I stepped into the function
  with GDB but it did not really help indicate what was going on. I moved the
  statement back into the original order, and the cardtests passed.
  This bug was not reported by my teammates because they did  not have card
  tests which covered the feast card.

-- Fix #4 playVillageCard()
  The bug here was introduced in assignment 2. I changed the number of actions
  that the player gets from 2 to 3. Jessica reported this because she had a
  card test on village. After fixing the bug, my assertions passed successfully.

-- Fix #5 playMinionCard()
  The bug here was introduced in assignment 2. The bug was to discard the hand
  after drawing instead of vice versa (normal function). I fixed the order and
  my assertions passed successfully. Neither of my teammates reported this
  because they did not have card tests for the minion card.

Additional Bugs Report:

After fixing the introduced bugs in dominion.c, there were still issues with the
fuzzers from assignment 4. Specifically, even with the adventurer function
"fixed", the randomtestadventurer.out still reported several thousand assertion
errors. These were reported by both my teammates, and I reported it to them as
well. However, I don't think we introduced these bugs. I suspect there are bugs
or vulnerabilities in the core dominion code regarding handling different states
and random seeds. Unfortunately, GDB was unable to help with the segfault
because it did not show the offending code when I typed "where" and "list".
I think we would need to do more unit tests to increase the coverage for all
functions, then we could use GDB more effectively. Right now the coverage is
only ~37%, and for my teammates test suites' it was between 20-40% of my code,
so it follows that we do not have enough coverage to pinpoint the exact location
of the failure. However, together we hypothesize that there is something wrong
with 'discardCard', or potentially 'discardCard' in the context of the
adventurer, because the random tests are indicating more cards are discarded
than there are  in the hand. More research is needed to pinpoint the exact 
location.

******************************************************************************/
