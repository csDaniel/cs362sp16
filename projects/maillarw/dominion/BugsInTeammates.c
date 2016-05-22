William Maillard
5/20/16
CS 362
	
The following is a description of bugs found in teammate 1 (murphet) and teammate 2 (chrijohn)'s 
code.  In addition to the description of bugs found, there is also a full test report and coverage 
information included at the end of this document.


******************Bugs in teammate 1's code(murphet)

The unit and random tests were run against teammate 1's code.  The full test report can be found at 
the end of this document.  Some small changes needed to be made so that tests ran correctly 
(function name changes and 1 parameter needed to be added to the adventurer_function() when it was 
run in the tests.

***  Teammate 1: Bug 1. ***
	
Number: 1.1
Function: smithy_function()
Effect: The player's hand count does not match the expected hand count after playing the smithy card
Possible location: Line 717: the discardCard function is being passed the incorrect player's 
location

This was determined based on the fact that the smithy_function() failed the following test:

--------Card Test 1: Test 1: Play Smithy and Check that 3 Cards are Drawn and 1 (Smithy) is 
Discarded---------

Failed


*** Teammate 1: Bug 2.  ***

Number: 1.2
Function: council_room_function()
Effect: The player's number of buys does not increase by 1
Possible location: Line 658: The number of buys is incremented by a predetermined amount that may 
not equal 1

This was determined based on the fact that the council_room_function() failed the following test:


--------Card Test 4: Test 4: Play CouncilRoom. Number of buys should be increased by 1 ------------

Failed
	
	
*******************Bugs in teammate 2's code (chrijohn)

The unit and random tests were run against teammate 2's code.  The full test report can be found at 
the end of this document.  Some small changes needed to be made so that tests ran correctly 
(several of the functions had a different number of parameter than those originally tested, but 
this was easily remedied).

*** Teammate 2: Bug 1 ***

Number: 2.1
Function: scoreFor()
Effect: The score of having one of every card in the player's deck and an empty hand and discard 
pile returns a value of 0 when it should be 11
Possible location: Line 444: The deck is iterated through up to state->discardCount[player] when it 
should
	go up to state->deckCount[player]
	
This was determined based on the fact that the scoreFor() failed the following test:

--------Unit Test 3: Test 4: Deck that has one of every card ---------

Failed
Count is 0 but should be 11
	
*** Teammate 2: Bug 2 ***

Number: 2.2
Function: playSmithy()
Effect: Player's hand count does not match what it should be. 
Possible location: Line 649: The comment says that 3 cards are added to the hand upon playing 
smithy, but the iterator that adds the cards only goes up to 2.
	
This was determined based on the fact that the playSmithy() failed the following test:

--------Card Test 1: Test 2:	Play Smithy with an empty player deck and empty discard pile---------

Failed
	
	


Here are the results and coverage information for running tests against teammate 1 (murphet) and 
teammate 2(chrijohn)'s code:
	

************************           Teammate 1 Testing              **********************
	
	
************************    Unit Test 1: Testing updateCoins()     **********************


--------Test 1: Zero Treasure Cards in Player's Hand---------

Passed

--------Test 2: Full Hand of All Copper Cards---------

Passed

--------Test 3: Full Hand of All Silver Cards---------

Passed

--------Test 4: Full Hand of All Gold Cards---------

Passed

--------Test 5: Large Hand with 5 Copper, 5 Silver, and 5 Gold---------

Passed

--------Test 6: One Gold Card and a bonus of 1---------

Passed

************************    Unit Test 2: Testing isGameOver()     **********************


--------Test 1: Newly Initialized Game---------

Passed

--------Test 2: 3 Supply Stacks are Empty and 2 players---------

Passed

--------Test 3: 3 Supply Stacks are Empty and 5 players---------

Failed

--------Test 4:  Stack of Province Cards is Empty---------

Passed

************************    Unit Test 3: Testing scoreFor()     **********************


--------Test 1: Empty Deck, Hand, and Discard---------

Passed

--------Test 2: Hand that has one of every card, empty deck ---------

Failed
Count is 10 but should be 11

--------Test 3: Discard that has one of every card, empty deck ---------

Failed
Count is -7 but should be 11

--------Test 4: Deck that has one of every card ---------

Failed
Count is 0 but should be 11


************************    Unit Test 4: Testing fullDeckCount()     **********************


--------Test 1: Newly Initialized Game, Check for Every Card---------

Passed

--------Test 2: One of the desired card in the Deck, the Hand, and the Discard ---------

Passed

--------Test 3: One of the desired cards in the hand but not the others ---------

Passed

--------Test 4: One of the desired cards in the discard but not the others ---------

Passed

--------Test 4: One of the desired cards in the deck but not the others ---------

Passed

************************    Card Test 1: Testing smithy_function()     **********************


--------Test 1: Play Smithy and Check that 3 Cards are Drawn and 1 (Smithy) is Discarded---------

Failed

--------Test 2:	Play Smithy with an empty player deck and empty discard pile---------

Failed

--------Test 3:	Play Smithy with an empty player deck and full discard pile---------

Failed

************************    Card Test 2: Testing adventurer_function()     **********************


--------Test 1: Play Adventurer with a deck full of Gold and check that -----------------
-------- two Gold Cards are added to the player's hand---------

Passed

--------Test 2: Play Adventurer with a deck full of Gold and check that -----------------
-------- one card is discarded (Adventurer)---------

Failed

--------Test 3: Play Adventurer with a deck of 10 with the last 2 being silver cards, check 
-----------------
-------- that 9 cards are discarded (viewed cards + Adventurer)---------

Failed

--------Test 4: Play Adventurer with an empty deck and discard pile of all Copper-----------------
-------- Check that two Copper Cards are added to the player's hand ---------

Passed

************************    Card Test 3: Testing council_room_function()     **********************


--------Test 1: Play CouncilRoom. 4 Cards should be added to player's hand and the CouncilRoom 
should be in Played Cards ------------

Failed

--------Test 2: Play CouncilRoom with 2 players. 1 Card should be added to every other player's 
hand------------

Failed

--------Test 3: Play CouncilRoom with 4 players. 1 Card should be added to every other player's 
hand------------

Failed

--------Test 4: Play CouncilRoom. Number of buys should be increased by 1 ------------

Failed

********************   Random Testing of Adventurer Card  ******************

Here is an example of one failed test: 
Test failed:

Before Adventurer is Played:
Starting Deck Count: 115
Starting Hand Count: 105
Starting Discard Count: 126

After Adventurer is Played:
Expected Deck Count: 113, Actual Deck Count: 113
Expected Hand Count: 106, Actual Hand Count: 107
Expected Discard Count: 127, Actual Discard Count: 126

Total number of tests: 100000
Number of tests passed: 0
Number of tests failed: 100000
Percent passed: 0.000000

********************   Random Testing of Smithy Card  ******************

Here is an example of one failed test: 
Test failed:

Before Adventurer is Played:
Starting Deck Count: 128
Starting Hand Count: 143
Starting Discard Count: 73

After Adventurer is Played:
Expected Deck Count: 125, Actual Deck Count: 125
Expected Hand Count: 145, Actual Hand Count: 146
Expected Discard Count: 74, Actual Discard Count: 73

Total number of tests: 10
Number of tests passed: 0
Number of tests failed: 10
Percent passed: 0.000000

************************    Begin Coverage Information   **********************

Function 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'gainCard'
Lines executed:61.54% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:100.00% of 1

Function 'discardCard'
Lines executed:92.31% of 13
Branches executed:100.00% of 6
Taken at least once:83.33% of 6
No calls

Function 'cardEffect'
Lines executed:0.00% of 208
Branches executed:0.00% of 173
Taken at least once:0.00% of 173
Calls executed:0.00% of 58

Function 'salvager_function'
Lines executed:0.00% of 8
Branches executed:0.00% of 2
Taken at least once:0.00% of 2
Calls executed:0.00% of 5

Function 'sea_hag_function'
Lines executed:0.00% of 8
Branches executed:0.00% of 4
Taken at least once:0.00% of 4
Calls executed:0.00% of 1

Function 'smithy_function'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 3

Function 'adventurer_function'
Lines executed:100.00% of 19
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 3

Function 'council_room_function'
Lines executed:100.00% of 10
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 4

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

Function 'getWinners'
Lines executed:0.00% of 24
Branches executed:0.00% of 22
Taken at least once:0.00% of 22
Calls executed:0.00% of 2

Function 'scoreFor'
Lines executed:100.00% of 24
Branches executed:100.00% of 42
Taken at least once:88.10% of 42
Calls executed:66.67% of 3

Function 'isGameOver'
Lines executed:100.00% of 10
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
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
Lines executed:100.00% of 9
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
No calls

Function 'supplyCount'
Lines executed:100.00% of 2
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
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:100.00% of 3
No branches
No calls

Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

File 'dominion.c'
Lines executed:38.35% of 571
Branches executed:39.81% of 417
Taken at least once:36.69% of 417
Calls executed:21.00% of 100
	
	
**********************  Here are the results for testing teammate 2's code **************

************************    Unit Test 1: Testing updateCoins()     **********************


--------Test 1: Zero Treasure Cards in Player's Hand---------

Passed

--------Test 2: Full Hand of All Copper Cards---------

Passed

--------Test 3: Full Hand of All Silver Cards---------

Passed

--------Test 4: Full Hand of All Gold Cards---------

Passed

--------Test 5: Large Hand with 5 Copper, 5 Silver, and 5 Gold---------

Passed

--------Test 6: One Gold Card and a bonus of 1---------

Passed

************************    Unit Test 2: Testing isGameOver()     **********************


--------Test 1: Newly Initialized Game---------

Passed

--------Test 2: 3 Supply Stacks are Empty and 2 players---------

Passed

--------Test 3: 3 Supply Stacks are Empty and 5 players---------

Failed

--------Test 4:  Stack of Province Cards is Empty---------

Passed

************************    Unit Test 3: Testing scoreFor()     **********************


--------Test 1: Empty Deck, Hand, and Discard---------

Passed

--------Test 2: Hand that has one of every card, empty deck ---------

Failed
Count is 10 but should be 11

--------Test 3: Discard that has one of every card, empty deck ---------

Failed
Count is -7 but should be 11

--------Test 4: Deck that has one of every card ---------

Failed
Count is 0 but should be 11


************************    Unit Test 4: Testing fullDeckCount()     **********************


--------Test 1: Newly Initialized Game, Check for Every Card---------

Passed

--------Test 2: One of the desired card in the Deck, the Hand, and the Discard ---------

Passed

--------Test 3: One of the desired cards in the hand but not the others ---------

Passed

--------Test 4: One of the desired cards in the discard but not the others ---------

Passed

--------Test 4: One of the desired cards in the deck but not the others ---------

Passed

************************    Card Test 1: Testing playSmithy()     **********************


--------Test 1: Play Smithy and Check that 3 Cards are Drawn and 1 (Smithy) is Discarded---------

Failed

--------Test 2:	Play Smithy with an empty player deck and empty discard pile---------

Failed

--------Test 3:	Play Smithy with an empty player deck and full discard pile---------

Failed

************************    Card Test 2: Testing playAdventurer()     **********************


--------Test 1: Play Adventurer with a deck full of Gold and check that -----------------
-------- two Gold Cards are added to the player's hand---------

Passed

--------Test 2: Play Adventurer with a deck full of Gold and check that -----------------
-------- one card is discarded (Adventurer)---------

Failed

--------Test 3: Play Adventurer with a deck of 10 with the last 2 being silver cards, check 
-----------------
-------- that 9 cards are discarded (viewed cards + Adventurer)---------


Stuck in an infinite loop

--------Test 4: Play Adventurer with an empty deck and discard pile of all Copper-----------------
-------- Check that two Copper Cards are added to the player's hand ---------

Passed

************************    Card Test 3: Testing playCouncilRoom()     **********************


--------Test 1: Play CouncilRoom. 4 Cards should be added to player's hand and the CouncilRoom 
should be in Played Cards ------------

Failed

--------Test 2: Play CouncilRoom with 2 players. 1 Card should be added to every other player's 
hand------------

Passed

--------Test 3: Play CouncilRoom with 4 players. 1 Card should be added to every other player's 
hand------------

Passed

--------Test 4: Play CouncilRoom. Number of buys should be increased by 1 ------------

Failed

********************   Random Testing of Adventurer Card  ******************

Here is an example of one failed test: 
Test failed:

Before Adventurer is Played:
Starting Deck Count: 143
Starting Hand Count: 135
Starting Discard Count: 142

After Adventurer is Played:
Expected Deck Count: 141, Actual Deck Count: 136
Expected Hand Count: 136, Actual Hand Count: 137
Expected Discard Count: 143, Actual Discard Count: 147

Total number of tests: 100000
Number of tests passed: 0
Number of tests failed: 100000
Percent passed: 0.000000

********************   Random Testing of Smithy Card  ******************

Here is an example of one failed test: 
Test failed:

Before Adventurer is Played:
Starting Deck Count: 74
Starting Hand Count: 93
Starting Discard Count: 111

After Adventurer is Played:
Expected Deck Count: 71, Actual Deck Count: 72
Expected Hand Count: 95, Actual Hand Count: 95
Expected Discard Count: 112, Actual Discard Count: 111

Total number of tests: 10
Number of tests passed: 0
Number of tests failed: 10
Percent passed: 0.000000

************************    Begin Coverage Information   **********************

Function 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'gainCard'
Lines executed:61.54% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:100.00% of 1

Function 'discardCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
No calls

Function 'cardEffect'
Lines executed:0.00% of 205
Branches executed:0.00% of 165
Taken at least once:0.00% of 165
Calls executed:0.00% of 57

Function 'playMine'
Lines executed:0.00% of 15
Branches executed:0.00% of 14
Taken at least once:0.00% of 14
Calls executed:0.00% of 5

Function 'playGardens'
Lines executed:0.00% of 4
Branches executed:0.00% of 2
Taken at least once:0.00% of 2
No calls

Function 'playCouncil_Room'
Lines executed:100.00% of 9
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 2

Function 'playAdventurer'
Lines executed:100.00% of 17
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 2

Function 'playSmithy'
Lines executed:100.00% of 4
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 1

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

Function 'getWinners'
Lines executed:0.00% of 24
Branches executed:0.00% of 22
Taken at least once:0.00% of 22
Calls executed:0.00% of 2

Function 'scoreFor'
Lines executed:100.00% of 24
Branches executed:100.00% of 42
Taken at least once:88.10% of 42
Calls executed:66.67% of 3

Function 'isGameOver'
Lines executed:100.00% of 10
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'endTurn'
Lines executed:0.00% of 20
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 3

Function 'whoseTurn'
Lines executed:0.00% of 2
No branches
No calls

Function 'fullDeckCount'
Lines executed:100.00% of 9
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
No calls

Function 'supplyCount'
Lines executed:100.00% of 2
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
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:100.00% of 3
No branches
No calls

Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

File 'dominion.c'
Lines executed:35.34% of 566
Branches executed:38.19% of 419
Taken at least once:35.32% of 419
Calls executed:17.20% of 93
