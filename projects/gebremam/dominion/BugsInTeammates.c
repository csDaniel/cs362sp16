/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 5
 * Description:  bugs you found in teammates' code 
 * -----------------------------------------------------------------------
 */

/*
Teammate1: rechstee
-------------------
unittest1 (test updateCoins()): Passed!

unittest2 (test isGameOver()): Failed!
	Classification: Minor Bug
   	Description: isGameOver method failed the test because it does not check all card values. 
  	 			Game is over when stack of Province cards is empty or when three of the supply piles are at 0.
   				When checking for supply piles, it misses to check the last 2 kingdom card pils.
   	Expected Results: return 1 when supplyCont of 3 of the kingdom card piles are set to 0
   	Actual Results: returns 0

unittest3 (test getCost()) : Passed!

unittest4 (test fullDeckCount()): Passed!


cardtest1 (test adventurer) : Failed!
	Classification: Minor
	Description: Test failed although I did not expect it to. When analyzing Evan's payAdventurer function, I realized my
				unit test was not sufficient. It only checks the handCount to verify validity of function. The error in 
				Evan's refactored playAdventurer function would have been caught if test also checked the discardCount.
				That being said, since my cardTest was checking handCount only and Evan's function is expected give the correct
				handCount, I did not expect it to Fail. 
				It took me some time to figure out why test was failing. It looks like Evan is not returning after each card in 
				cardEffect.
   	Expected Results: handCount for player increased by 2 (draw 2 treasure cards)
   	Actual Results: handCount for player increased by 4
	Recommendation: put a return 0 statement at the end of each case rerouting to refactored functions in cardEffect function.
	Right now, code is not ending after executing playAdventurer and coming back to cardEffect.

cardtest2 (test smithy): Passed!
	Test passed although I did not expect it to.
	Evan's playSmithy function sets the trash flag when discarding the smithy card.
	My test does not check playedCardCount so did not catch it.

cardtest3 (test village): Passed!


cardtest4 (test council_room): Passed!


randomtestadventurer : Failed!
	My random test is better my unit test because it doesn't only check handCount.
	it also checks the sum of hand, deck, and discard counts 
	Classification: Minor
	Description: Test failed because of an incorrect discard pile. Evan's playAdventurer function does not discard correctly (misses 1).
   	Expected Results: Expected same number for (handCount+deckCount+discardCount) of player before and after calling playAdventurer
   	Actual Results: number reduced by 1

randomtestcard (random test smithy): Passed!



Teammate2: Bamesbem
--------------------
unittest1 (test updateCoins()): Passed!

unittest2 (test isGameOver()): Failed!
	Classification: Minor Bug
   	Description: isGameOver method failed the test because it does not check all card values. 
  	 			Game is over when stack of Province cards is empty or when three of the supply piles are at 0.
   				When checking for supply piles, it misses to check the last 2 kingdom card pils.
   	Expected Results: return 1 when supplyCont of 3 of the kingdom card piles are set to 0
   	Actual Results: returns 0

unittest3 (test getCost()) : Passed!

unittest4 (test fullDeckCount()): Passed!

cardtest1 (unittest adventurer): Failed!
	Classification: Minor Bug
	Description: Test failed because Michael's playAdventurer function does not draw correct number of treasure cards. 
				This function stops drawing cards when one treasure card is pulled.  It is supposed to keep 
				drawing cards until 2 treasure cards are pulled. 
   	Expected Results: handCount for player increased by 2 (draw 2 treasure cards)
   	Actual Results: handCount for player increased by 1 only


cardtest2 (unit test smithy): Failed!
	Classification: Minor Bug
	Description: Test failed because Michael's playSmithy function draws and extra card from deck.
   	Expected Results: handCount for player increased by 2 (draw 3 cards and discard smithy)
   	Actual Results: handCount of player increased by 3

cardtest3 (unit test village): Failed!
	Classification: Minor Bug
	Description: Test failed because Michael's playVillage function decrements numActions by one instead of 
	incrementing it by 2.
   	Expected Results: numActions to be increased by 2
   	Actual Results: numActions reduced by 1

cardtest4 (unit test council_room): Passed!


randomtestadventurer : Failed!
	Classification: Minor Bug
	Description: Test failed because playAdventurer function does not draw correct number of treasure cards. 
				This function stops drawing cards when one treasure card is pulled.  It is supposed to keep 
				drawing cards until 2 treasure cards are pulled. 
   	Expected Results: handCount for player increased by 2 (draw 2 treasure cards)
   	Actual Results: handCount for player increased by 1 only

randomtestcard (random test smithy): Failed!
	Classification: Minor Bug
	Description: Test failed because Michael's playSmithy function draws and extra card from deck.
   	Expected Results: handCount for player increased by 2 (draw 3 cards and discard smithy)
   	Actual Results: handCount of player increased by 3


*Note: 	For both teammates, I did not have any issue testing the card methods even though the names of the refactored functions 
		and arguments passed were different because my unit tests were calling cardEffect function not the 
		actual refactored functions.
*/
//