/*Lucile Behmer
 *CS 362
 *Assignment 5
 *Bug Fixes


 ***Bug 1
 *I first fixed the bug that I had in the Smithy function.
 *This allowed for the correct number of cards to drawn and the 
 *discard function was no longer accidently called in the for loop.

 ***Bug 2
 *The next bug was in the GreatHall function. This had the wrong 
 *amount of number of actions because it was decreasing instead of 
 *increasing. This was a simple change to: state->numActions++; instead of
 *state->numActions--;

 ***Bug 3
 *Minion had a bug that while it was small it still would cause a lot 
 *of trouble. Now it is back to other players who have four or more cards 
 *instead of 2 or more. The bug actually have the other players an advantage 
 *of getting more cards so fixing this bug helps to keep the balance of the 
 *game.

 ***Bug 4
 *Remodel had a bug that discarded the wrong card. Instead of getting rid
 *of the card that the player selected it was accidently getting rid of 
 *the first card that was not the selected card. This could be 
 *catastrophic and game changing.

***Having my teammates run their tests against my code really helped 
  *in terms of coverage. I think that, that it helped because I had forgotten
  *about the bugs but it showed that having multiple tests and discussing 
  *the results will help to make sure that all of the bugs get caught. I wish
  *that I could have found some bugs that were not introduced on purpose though.
  */
