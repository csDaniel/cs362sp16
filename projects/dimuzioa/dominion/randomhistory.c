/***
In order to increase coverage for Assignment 4, I took the following steps:

-Randomly generated the seed value for initializeGame
-Randomly generated the amount of players for both random tests
-Randomly chose currentPlayer

I studied both cards in my refactored dominion.c file, and tailored my random 
tests accordingly. 

Adventurer Card: The tests mostly fail as I set the test parameters against my
refactored dominion.c, but you get anywhere from 0-7 passes each time I run 
randomtestadventurer, which is about how many fails a random tester may expect 
on 1,000 runs of code that they expect to WORK.

I only ran a couple different tests on the adventurer card, but still got pretty good 
coverage, all things considered. For the entire dominion.c file, I got 24.01% line 
coverage and 25.66% branch coverage. For my 'playAdvCard'(adventurer), I achieved
100% line and branch coverage


Village Card: The tests completely passed, as I tested to ensure that the village
card appropriately updated actions + 2 and that handCount remained the same 
across 1,000 random test runs(since after being played, the newly drawn card would
be offset by discarding the village itself).  

The village random tester achieved only 22.04% line coverage and 24% branch
coverage across dominion.c, which I feel is pretty good for a random tester on a
single card. Once again, 100% coverage was achieved for the playVillageCard.


The coverage results for both random testing files are pasted below. 
***/

--------------------Random Testing: Adventurer Card-------------------------

Total number of PASSED tests out of 2,000: 5
Total number of FAILED tests out of 2,000: 1995
------------------gcov Test Results----------------------
Function 'playCouncilRoom'
Lines executed:0.00% of 8
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 2

Function 'playVillageCard'
Lines executed:0.00% of 5
No branches
Calls executed:0.00% of 2

Function 'playGreatHall'
Lines executed:0.00% of 4
No branches
Calls executed:0.00% of 1

Function 'playSmithyCard'
Lines executed:0.00% of 5
Branches executed:0.00% of 2
Taken at least once:0.00% of 2
Calls executed:0.00% of 2

Function 'playAdvCard'
Lines executed:100.00% of 17
Branches executed:100.00% of 12
Taken at least once:83.33% of 12
Calls executed:100.00% of 2

Function 'updateCoins'
Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

Function 'gainCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 1

Function 'discardCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
No calls

Function 'cardEffect'
Lines executed:4.83% of 207
Branches executed:12.85% of 179
Taken at least once:1.68% of 179
Calls executed:3.45% of 58

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

Function 'drawCard'
Lines executed:77.27% of 22
Branches executed:100.00% of 6
Taken at least once:66.67% of 6
Calls executed:100.00% of 1

Function 'getWinners'
Lines executed:0.00% of 24
Branches executed:0.00% of 22
Taken at least once:0.00% of 22
Calls executed:0.00% of 2

Function 'scoreFor'
Lines executed:0.00% of 24
Branches executed:0.00% of 42
Taken at least once:0.00% of 42
Calls executed:0.00% of 3

Function 'isGameOver'
Lines executed:0.00% of 10
Branches executed:0.00% of 8
Taken at least once:0.00% of 8
No calls

Function 'endTurn'
Lines executed:0.00% of 20
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 3

Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

Function 'fullDeckCount'
Lines executed:0.00% of 9
Branches executed:0.00% of 12
Taken at least once:0.00% of 12
No calls

Function 'supplyCount'
Lines executed:0.00% of 2
No branches
No calls

Function 'handCard'
Lines executed:0.00% of 3
No branches
Calls executed:0.00% of 1

Function 'numHandCards'
Lines executed:0.00% of 2
No branches
Calls executed:0.00% of 1

Function 'buyCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 4

Function 'playCard'
Lines executed:0.00% of 14
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 3

Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:93.55% of 62
Branches executed:100.00% of 46
Taken at least once:89.13% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:0.00% of 3
No branches
No calls

Function 'compare'
Lines executed:83.33% of 6
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
No calls

File 'dominion.c'
Lines executed:24.01% of 558
Branches executed:25.66% of 417
Taken at least once:17.99% of 417
Calls executed:12.90% of 93
Creating 'dominion.c.gcov'






------------------Random Testing: Village card---------------

--------------------Random Testing: Village Card-------------------------

Total number of PASSED tests out of 2,000: 2000
Total number of FAILED tests out of 2,000: 0
------------------gcov Test Results----------------------
Function 'playCouncilRoom'
Lines executed:0.00% of 8
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 2

Function 'playVillageCard'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

Function 'playGreatHall'
Lines executed:0.00% of 4
No branches
Calls executed:0.00% of 1

Function 'playSmithyCard'
Lines executed:0.00% of 5
Branches executed:0.00% of 2
Taken at least once:0.00% of 2
Calls executed:0.00% of 2

Function 'playAdvCard'
Lines executed:0.00% of 17
Branches executed:0.00% of 12
Taken at least once:0.00% of 12
Calls executed:0.00% of 2

Function 'updateCoins'
Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

Function 'gainCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 1

Function 'discardCard'
Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
No calls

Function 'cardEffect'
Lines executed:4.83% of 207
Branches executed:12.85% of 179
Taken at least once:1.68% of 179
Calls executed:3.45% of 58

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

Function 'drawCard'
Lines executed:36.36% of 22
Branches executed:33.33% of 6
Taken at least once:16.67% of 6
Calls executed:0.00% of 1

Function 'getWinners'
Lines executed:0.00% of 24
Branches executed:0.00% of 22
Taken at least once:0.00% of 22
Calls executed:0.00% of 2

Function 'scoreFor'
Lines executed:0.00% of 24
Branches executed:0.00% of 42
Taken at least once:0.00% of 42
Calls executed:0.00% of 3

Function 'isGameOver'
Lines executed:0.00% of 10
Branches executed:0.00% of 8
Taken at least once:0.00% of 8
No calls

Function 'endTurn'
Lines executed:0.00% of 20
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 3

Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

Function 'fullDeckCount'
Lines executed:0.00% of 9
Branches executed:0.00% of 12
Taken at least once:0.00% of 12
No calls

Function 'supplyCount'
Lines executed:0.00% of 2
No branches
No calls

Function 'handCard'
Lines executed:0.00% of 3
No branches
Calls executed:0.00% of 1

Function 'numHandCards'
Lines executed:0.00% of 2
No branches
Calls executed:0.00% of 1

Function 'buyCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 4

Function 'playCard'
Lines executed:0.00% of 14
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 3

Function 'shuffle'
Lines executed:93.75% of 16
Branches executed:100.00% of 8
Taken at least once:87.50% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:93.55% of 62
Branches executed:100.00% of 46
Taken at least once:89.13% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:0.00% of 3
No branches
No calls

Function 'compare'
Lines executed:83.33% of 6
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
No calls

File 'dominion.c'
Lines executed:22.04% of 558
Branches executed:23.26% of 417
Taken at least once:15.35% of 417
Calls executed:11.83% of 93
Creating 'dominion.c.gcov'

