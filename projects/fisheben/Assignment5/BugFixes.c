/*************************************************************************************************************
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: BugsFixes.c
 * Description: This file will document the bugs fixed in my team-mates
 * dominion.c code.
 * Note: Fixing the discardCard function threw off my unittests and they need to be updated 
 *************************************************************************************************************
 *************************************************************************************************************
 
 Discussion: Kristen Dhuse
 I found that Kristen had fixed the discardCard function be using the trashCount
 variable.  This required me to update my test cases so that they initialize
 the trashCount varaible when building a test case. I didn't use code coverage at all
 to help find bugs in Kristens code.  I found that I've spent enough time getting familiar
 with the code that I could read and follow along fairly well and spotted the bugs this
 way.  I could see for larger projects where code coverage would very helpful, if I for
 example wanted to implement Tarantula to help narrow down a hard to find bug.
 Bugs Found in Kristens code:
 
 unittest1.c
 Bugs fixed in updateCoins function.
 Found no bugs.
 
 unittest2.c
 Bugs fixed in drawCard function.
 Found no bugs
 
 unittest3.c
 Bugs fixed discardCard function.
 Fix: 	added the card discarded to the discard deck and then incremented the discardcount.
		i also need to fix the unit test 0 so that it correctly the discard counts		
 Fix: 	Need to copy the discard deck and the played card deck from the postCall into the preCall
 
 unittest4.c
 Bugs fixed in getCost function.
 Found no bugs.
 
 cardTest1.c
 Bugs fixed in smithy card.
 Fix: Change smithy to add only 3 cards to the hand instead of 3
	: This fixed all the bugs for the smithy card.
 
 
 cardTest2.c
 Bugs fixed in adventurer card.
 Fix:	Added a reshuffled variable so that while loop breaks if there are no treasure cards in deck
    : 	dominion line 1239 dominion.c 
 Fix:	The counter that kept track of the non treasure cards was off by one and too many cards were being discarded			  
		Line 1146 in dominion.c code
		* Need to change the tests to account for the fixes made in the discardCard function
		* Need to fix the discardCount and the playedCardCount, and also the discard array and playedCard array
 
 cardTest3.c
 Bugs fixed in village card.
 Fix:	found that the trash flag was set when discarding the card, set it to 0
	:	Changed code on line 1178 of dominion.c
	:	* Need to change the tests to account for the fixes made in the discardCard function
	:	* Need to fix the discardCount and the playedCardCount, and also the discard array and playedCard array
 
 cardTest4.c
 Bugs fixed in greatHall card.
 Found no bugs
 Fix:	* Need to change the tests to account for the fixes made in the discardCard function
	:	* Need to fix the discardCount and the playedCardCount, and also the discard array and playedCard array
 
 
 *************************************************************************************************************
 *************************************************************************************************************
 Discussion: David Hite
 I found that the playVillage function call from the cardEffect function had the arguments in the wrong order
 which was causing a seg fault.  I swtiched the handPos and currentPlayer in the call which resolved the seg
 fault.  I also found the playSmithy was incrementing the handPos variable in the function which also caused a 
 seg fault, removing this resolved the issue. I used GDB to help find the line that was causing the seg fault.
 I didn't use code coverage at all to help find bugs in David's code either.  I found that I've spent enough
 time getting familiar with the code that I could read and follow along fairly well and spotted the bugs this
 way.  I could see for larger projects where code coverage would very helpful, if I for example wanted to 
 implement Tarantula to help narrow down a hard to find bug.
 Bugs Found in Kristens code:
 
 unittest1.c
 Bugs fixed in updateCoins function.
 Found no bugs.
 
 unittest2.c
 Bugs fixed in drawCard function.
 Found no bugs
 
 unittest3.c
 Bugs fixed in discardCard function. 
 Fix: 	added the card discarded to the discard deck and then incremented the discardcount.
		i also need to fix the unit test 0 so that it correctly the discard counts		
	
 
 unittest4.c
 Bugs fixed in getCost function.
 Found no bugs.
 
 cardTest1.c
 Bugs fixed in smithy card.
 playSmithy was incrementing the handPos variable in the function which also caused a 
 seg fault, removing this resolved the issue on line 1272 dominion.c
 
 cardTest2.c
 Tested adventurer card.
 Fix: 	Set counter z to 0, line 1236 dominion.c
    :	Incremented z properly line 1252 dominion.c
	:	Added a reshuffled variable so that while loop breaks if there are no treasure cards in deck
	: 	dominion line 1239 dominion.c
 
 cardTest3.c
 Tested village card.
 Fix:   Change the numActions variable so that it increments the number of action by 2 instead of 1146
    :	line 1286 dominion.c
 
 cardTest4.c
 Tested greatHall card.
 Found no bugs
 
 
