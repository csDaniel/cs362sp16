/*
David DeRisi
CS362 - 400
Assignment 5
BugsinTeammates.c
5/17/2016

Adventurer, Smithy and randomtestadventurer test were the only tests executed as they were the only commonly refactored cards across
all three team members.  randomtestcard.c was also not executed as my version tests the council room card, which neither of the other members refactored.

Robert Brauer:  brauerr dominion.c and dominion.h were refactored to accommodate cardtest method name and arguments parameters
				New functions were simply added to the end of dominion.c and contain direct copies of code written by the original owner

	Smithy Card:  Test 1: Player should have 3+ cards - FAILED
					May be related to a missing line of code around line 680


	Adventurer Card:  Test 1:  Player hand card count should increase by two - FAILED
					  Test 4:  Difference in deck amount should reflect discard + 2 - FAILED
					  May be related to defect at line 659

	randomtestadventurer:  20 iterations. Single execution.
		Iterations 1 - 20: Test 1:  Player hand card count should increase by two - FAILED
						   Test 4:  Difference in deck amount should reflect discard + 2 - FAILED
							May be related to defect at line 659




Michael Dambacher: dambachm dominion.c and dominion.h were refactored to accommodate cardtest method name and arguments parameters
					New functions were simply added to the end of dominion.c and contain direct copies of code written by the original owner

	Smithy Card:  Test 1:  Player should have +3 cards - FAILED
				  Test 2:  Player pile should have 3 fewer cards - FAILED
				  May have to do with an error in the for loop @ line 675
	Adventurer Card:  All tests passed

	randomtestadventurer:  20 iterations.  Single execution.
		Iterations  1, 3, 8, 10, 13, 14, 19:  Test 1:  Player hand card count should increase by 2 - FAILED  
											  Test 4:  Difference in deck amount should reflect discard + 2 - FAILED
											  May be related to missing value in the if statement at line 658




*/