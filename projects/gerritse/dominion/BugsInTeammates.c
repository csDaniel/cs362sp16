/***************************************
Ellard Gerritsen van der Hoop
BugInTeammates.c


******************************************/


/*******************************Teammate 1: Shawn Seibert**********************************************/


Card Test 1(Smithy):   FAILED

	-The number of cards drawn appears to be off by 1 for the player.

Card Test 2(Adventurer): FAILED

	- Number of cards drawn is off and thus the hand count for the player is off. For some reason this number was even negative. 
		Card in hand: -196          Expected: 6

	
Card Test 3(Council Card): FAILED

	-Number of cards in hand off by 1
	-Incorrect number of buys
		Number of Buys: 1           Expected: 2



Card Test 4(Cutpurse): PASSED

	-No bugs were found here 

	
Unit Test 1(endTurn()):   PASSED
	
	-No bugs were found here 

Unit Test 2(updateCoins()): PASSED
	
	-No bugs were found here 


Unit Test 3(getCost()): PASSED
	
	-No bugs were found here 


Unit Test 4(supplyCount()):	PASSED
	
	-No bugs were found here 	

RandomTestCard(Council Room): FAILED

	-The hand count is off for all the iterations
	-The number of buys seems to be incorrect for all the iterations 
	- All other tests passed



RandomTestAdventurer: FAILED

	- Treasure Card Count is off on all iterations. 
	- Hand count appears to be off on all iterations by 1. 
	- All other tests passed








/*******************************Teammate 2: Suyana Lozada**********************************************/

Card Test 1(Smithy):   FAILED

	-The number of cards drawn appears to be off by 1 for the player.

Card Test 2(Adventurer): FAILED

	- Number of cards drawn is off and thus the hand count for the player is off.
		Card in hand: 8       Expected: 6

	

Card Test 3(Council Card): FAILED

	-Number of cards in hand off by 1:
		Cards in Hand:9				Expected: 8 



Card Test 4(Cutpurse): FAILED

	-Copper Cards in hand changed for P1
		Number of Copper Cards: 3		Expected: 4

	-One copper card should have been removed from P2
		Number of Copper Cards: 5		Expected: 4
	
Unit Test 1(endTurn()):   PASSED
	
	-No bugs were found here 

Unit Test 2(updateCoins()): PASSED
	
	-No bugs were found here 


Unit Test 3(getCost()): PASSED
	
	-No bugs were found here 


Unit Test 4(supplyCount()):	PASSED
	
	-No bugs were found here 
	

RandomTestCard(Council Room): FAILED

	-The hand count is off for all the iterations
	-All other tests passed



RandomTestAdventurer: FAILED

	- Treasure Card Count is off on all iterations. 
	- Hand count appears to be off on all iterations by 1. 
	- All other tests passed
