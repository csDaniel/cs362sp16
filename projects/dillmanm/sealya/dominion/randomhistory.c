As I began to work on the random tester for adventurer, I realized that there
were a few branches that were not being taken because I was not correctly
weighting the probabilities or forcing integration of edge unit tests integration
into my random test routines.

For instance, I was not getting sufficient coverage for the logical branch that
involves reincorporating the discard pile and then shuffling the deck. I added
test cases to the end of the routine (default trials 50,000) which took into
account the following edge cases:

empty deck and discard
deck with no treasures: discard with two
deck with 1 treasure: discard with none
deck with no treasures: discard with 1

This budged the needle on the forking of the reshuffle path to 1%, but it was
enough for a bug to realize itself. The shuffling of the deck alone does not
reincorporate the discard into the deck, so treasures were staying stuck in the
discard. Additionally, when there were no treasures there would be an infinite
loop. I corrected these bugs in adventurer and got complete coverage with no
observed bugs.

Some guiding principles that I followed:
- random valeus would follow defined interfaces and constant maximums
- boundaries would be tested by the law of large numbers, not forced edge cases
- there would be no test cases for empty hands - the target card will always
  be paid.
- any player and card stock not involved in the card play will still be checked
  for consistency.