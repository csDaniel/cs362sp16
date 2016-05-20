# Random test report

---adventurer------
Random Testing
File 'dominion.c'
Lines executed:53.52% of 568
Branches executed:60.19% of 417
Taken at least once:42.69% of 417
Calls executed:36.36% of 99

compares with cardtest1.c

File 'dominion.c'
Lines executed:33.63% of 568
Branches executed:42.45% of 417
Taken at least once:24.94% of 417
Calls executed:22.22% of 99

----village----------
Random Testing
File 'dominion.c'
Lines executed:53.52% of 568
Branches executed:60.19% of 417
Taken at least once:42.69% of 417
Calls executed:36.36% of 99

compares with cardtest3.c

File 'dominion.c'
Lines executed:38.03% of 568
Branches executed:44.36% of 417
Taken at least once:26.86% of 417
Calls executed:28.28% of 99

/*
	Percentage of coverage almost double since the number of iteration for random testing is increased.
Before, unit testing only targets extreme scenarios where it's assumed to be the quickest way to find bugs.
With random testing, more test cases need to be run to cover the interactions between different configuration,
in this case, contexts. 
	However, for adventurer card, random testing does not cover in situation when there is not
less than 2 treasure cards on the deck. The only configuration that it test is the position where it stops 
drawing cards from the deck (So it always guarantees that there's more than 2 treasure cards). And for each 
iteration, currentPlayer is cycle through each hand. 
	Comparison between card effect results and expected results are also marked up to narrow faulty code section.
	Random testing for village card applies the same strategy. Village card is inserted into current player's 
hand at random position. Again, all the concerned changes like number of actions, added cards are evaluated against
expected outcomes to zone it the error.
*/