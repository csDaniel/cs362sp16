/*************************************************************************************************************
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: BugsInTeammates.c
 * Description: This file will document the bugs found in my team-mates
 * dominion.c code.
 *************************************************************************************************************
 *************************************************************************************************************
 Kristen Dhuse
 I found that Kristen had fixed the discardCard function by using the trashCount
 variable.  This required me to update my test cases so that they initialized
 the trashCount varaible when building a test case.  I also found alot of my tests were broken when runing
 against Kristen's code.  In my code I didn't update the playedCards deck pre and post call, which threw off
 many tests.  The code coverage of my tests were similar to what I found with my tests, dominion code
 coverage was around 41% and my dominion code coverage was around 40%. 

 
 Bugs Found in Kristens code:
 
 unittest1.c
 Tested updateCoins function.
 Found no bugs.
 
 unittest2.c
 Tested drawCard function.
 Found no bugs
 
 unittest3.c
 Tested discardCard function.
 2 test cases failed
 Test 0 failed- Discard counts preCall + 1 was not equal to postCall
 Test 4 failed- There was a difference in the game states preCall and postCall
 
 unittest4.c
 Tested getCost function.
 Found no bugs.
 
 cardTest1.c
 Tested smithy card.
 Test 1 failed- the hand counts or deck counts are off
 Test 3 failed- there is a difference in the game states preCall and postCall
 
 cardTest2.c
 Tested adventurer card.
 Test 3 failed- TEST WITH EMPTY HAND EMPTY DISCARD DECK AND ALL TREASURE DECKS
              - there is a difference in the game states preCall and postCall
 Test 8 failed- TEST WITH NON EMPTY HAND AND NON EMPTY DISCARD DECK AND 2 TREASURE CARDS AT START OF DECK
			  - there is a difference in the game states preCall and postCall
 Test12 failed- TEST WITH NO TREASURE CARDS IN DECK
			  - Hand counts are off	
 
 cardTest3.c
 Tested village card.
 Test 4 failed- the playedCard counts are off
 Test 5 failed- there is a difference in the game states preCall and postCall
 
 cardTest4.c
 Tested greatHall card.
 Found no bugs
 
 randomtestcard.c
 Test smithy card with random testing
 Test 1 failed- hand count are not the same
 Test 2 failed- deckcounts are not the same
 Test 5 failed- smithy card was not discarded properly
 Test 6 failed- the hands are different for unshuffled deck
 Test 7 failed- unexpected changes to game state
 Test 9 failed- there are changes to other players
 Test 10 failed- there are changes to victory cards
 Test 11 failed- there are changes to the deck
 
 randomtestadventurer.c
 Test adventurer card with random testing
 Test 2 failed- deck counts are off preCall and postCall
 Test 7 failed- unexpected changes to game state
 Test 10 failed- Changes in victory cards
 Test 11 failed- found changes to the decks
 
 *************************************************************************************************************
 *************************************************************************************************************
 Discussion: David Hite
 I found that the playVillage function call from the cardEffect function had the arguments in the wrong order
 which was causing a seg fault.  I swtiched the handPos and currentPlayer in the call which resolved the seg
 fault.  I also found the playSmithy was incrementing the handPos variable in the function which also caused a 
 seg fault, removing this resolved the issue. The code coverage of my tests were similar to what I found with 
 my tests, dominion code coverage was around 41% and my dominion code coverage was around 40%.

 
 unittest1.c
 Tested updateCoins function.
 Found no bugs.
 
 unittest2.c
 Tested drawCard function.
 Found no bugs
 
 unittest3.c
 Tested discardCard function.
 2 test cases failed
 Test 0 failed- Discard counts preCall + 1 was not equal to postCall
 
 unittest4.c
 Tested getCost function.
 Found no bugs.
 
 cardTest1.c
 Tested smithy card. 
 Test 3 failed- there is a difference in the game states preCall and postCall
 
 cardTest2.c
 Tested adventurer card.
 Test 1 failed- TEST WITH EMPTY HAND EMPTY DISCARD DECK AND ALL TREASURE DECKS
              - hand counts are off or deck counts are off
 Test 2 failed- TEST WITH EMPTY HAND EMPTY DISCARD DECK AND ALL TREASURE DECKS
              - discard counts are off
 Test 3 failed- TEST WITH EMPTY HAND EMPTY DISCARD DECK AND ALL TREASURE DECKS
              - there is a difference in the game states preCall and postCall  
 Test 4 failed- TEST ADVENTURER CARD IS DISCARDED PROPERLY 
              - played card count is off
 Test 5 failed- TEST ADVENTURER CARD IS DISCARDED PROPERLY 
              - card not discarded properly
 Test 7 failed- TEST WITH NON EMPTY HAND AND NON EMPTY DISCARD DECK AND 2 TREASURE CARDS AT START OF DECK
			  - discard counts are off
 Test 8 failed- TEST WITH NON EMPTY HAND AND NON EMPTY DISCARD DECK AND 2 TREASURE CARDS AT START OF DECK
			  - there is a difference in the game states preCall and postCall
 Test10 failed- TEST WITH NON EMPTY HAND AND NON EMPTY DISCARD DECK AND 2 TREASURE CARDS AT START OF DECK
              -	Victory card changes		
 Test12 failed- TEST WITH NO TREASURE CARDS IN DECK
			  - Hand counts are off	
 
 cardTest3.c
 Tested village card.
 Test 3 failed- the numActions variable is off
 Test 5 failed- there is a difference in the game states preCall and postCall
 
 cardTest4.c
 Tested greatHall card.
 Found no bugs
 
 randomtestcard.c
 Test smithy card with random testing
 Test 5 failed- smithy card was not discarded properly
 Test 7 failed- unexpected changes to game state
 
 randomtestadventurer.c
 Test adventurer card with random testing
 Test 1 failed- hand counts are off
 Test 2 failed- deck counts are off preCall and postCall
 Test 3 failed- discard counts are off
 Test 4 failed- played card counts are off
 Test 5 failed- adventurer card was not discarded properly
 Test 6 failed- unexpected changes to the game state found for unshuffled deck
 Test 7 failed- unexpected changes to game state
 Test 9 failed- changes found t o other players
 Test 10 failed- Changes in victory cards
 Test 11 failed- found changes to the decks
