/*
Miranda Weldon
May 8, 2016
CS 362 Spring 2016
Assignment 4
randomhistory.c

I started the development of my random testers by first deciding what needed to be tested. Primarally, it was important to check that the after a particular card was played (Adventurer and Smithy in this case) there were the correct number of cardsin the player's deck, the player's hand, and that there were the correct number of coins when playing the Adventurer. Next came deciding which variables to randomize for each test. These were decided and the tests were made. I believe that the use of random testing led to improvements in coverage, as more branches were taken in several functions, most notably in shuffle() and updateCoins(). There will always be room for improvement when looking for bugs in a program, but I was more able to see the mistakes in the cards I tested using this method then I had previously.

Function 'main'
Lines executed:88.46% of 26
Branches executed:100.00% of 8
Taken at least once:62.50% of 8
Calls executed:83.33% of 18

File 'randomtestcard.c'
Lines executed:88.46% of 26
Branches executed:100.00% of 8
Taken at least once:62.50% of 8
Calls executed:83.33% of 18
Creating 'randomtestcard.c.gcov'
------------------------------------------
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
Lines executed:11.02% of 236
Branches executed:18.59% of 199
Taken at least once:7.54% of 199
Calls executed:6.25% of 64

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
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
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
Lines executed:24.64% of 548
Branches executed:26.62% of 417
Taken at least once:18.47% of 417
Calls executed:12.22% of 90
Creating 'dominion.c.gcov'

--------------------------------------------
Function 'main'
Lines executed:88.46% of 26
Branches executed:100.00% of 8
Taken at least once:62.50% of 8
Calls executed:83.33% of 18

File 'randomtestadventurer.c'
Lines executed:88.46% of 26
Branches executed:100.00% of 8
Taken at least once:62.50% of 8
Calls executed:83.33% of 18
Creating 'randomtestadventurer.c.gcov'

-------------------------------------------

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
Lines executed:11.02% of 236
Branches executed:18.59% of 199
Taken at least once:7.54% of 199
Calls executed:6.25% of 64

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
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
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
Lines executed:24.64% of 548
Branches executed:26.62% of 417
Taken at least once:18.47% of 417
Calls executed:12.22% of 90
Creating 'dominion.c.gcov'

*/