/*
CS 362 ASSIGNMENT 5
JONATHAN HARIJANTO

This file is the documentations of the bugs found by my teammates in my dominion.c file.
GDB really helpful for this assignment since it helps in locating which line cause the 
problem.

Based on Sarah's tests, below are the report.

1. cardtest1 -> Testing Smithy Card
	
	Failed test location:
	
		Checking handCount:
		hand count = 9, expected = 7
		Checking deckCount:
		deck count = 0, expected = 2
		Checking discardCount:
		discard count = 0, expected = 1
	
	Explanation:
	1st bug: Smithy draws additional 2 cards than it should. 
			 Automatically, deckCount shows 0 because smithy 
			 grabs 5 cards instead of 2.

	2nd bug: Smithy card doesn't go to discard pile.

	Solution
	1st bug: Modified the 'for-loop' in dominion.c for smithy
			 function. 
			 Changed it from:
			 	for (i = 0; i < 5; i++) {
    				drawCard(currentPlayer, state);
  				} 
			 into
				for (i = 0; i < 3; i++) {
	    			drawCard(currentPlayer, state);
	  			} 

2. cardtest2 -> Testing Adventurer Card
	
	Failed test location:
		
		Treasures in hand before playing Adventurer: 4
		handcount: 6
		deckcount: 0
		Checking +2 treasure:
		Treasures in hand after: 5
		Checking discardCount:
		discard count = 4, expected = 2
		Checking that a smithy and village are in the discard pile:
		Discarded card: 14
		Discarded card: 4
		Discarded card: 17
		Discarded card: 13
		Checking that Adventurer has been discarded:
		Played cards: 0

	
	Explanation:
	14 is village, 4 is copper, 17 is minion, 13 is smithy
	1st bug: Treasure card in hand doesn't increase by 2 since copper (apparently)
			 at discard pile.

	2nd bug: Based on 1st bug solution, a new bug introduced. Discard piles count
			 there are 3 cards instead of 2.

	Solution:
	1st bug: Modified the "if statement" to consider copper as a treasure card. From
			 	if (cardDrawn == silver || cardDrawn == gold)
      				drawntreasure++;
      		 into
      		 	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      				drawntreasure++;

      		 Results:

				Testing Adventurer Card
				Treasures in hand before playing Adventurer: 4
				handcount: 7
				deckcount: 0
				Checking +2 treasure:
				Treasures in hand after: 6
				Checking discardCount:
				discard count = 3, expected = 2
				Checking that a smithy and village are in the discard pile:
				Discarded card: 14
				Discarded card: 17
				Discarded card: 13
				Checking that Adventurer has been discarded:
				Played cards: 0

      		 * apparently discard count still shows incorrect!

    2nd bug: Adventurer card is looking for 3 treasure cards instead of only 2 cards.
    		 Thus, it draws more card from deck to search for additional 1 treasure card.
    		 Apparently no more treasure, so all non-treasure will be discarded.
    		 Suspected there is some "bug" with adventurer, it suppose to shuffle discard and
    		 add to deck when the deck is empty. Further trace will be done in random test. 

3. cardtest3 -> Testing Council Room Card
	
	Failed test location:
		
		Checking handCount
		hand count = 6, expected = 8
		Checking deckCount
		deck count = 3, expected = 1
		Checking buys
		buys = 3, expected = 2

	Explanation:
	1st bug: Player only draws +2 cards instead of +4 
	2nd bug: Player gets +2 buys instead of +1

	Solution:
	1st bug: Modified the 'for-loop' from
				for (i = 0; i < 2; i++) {
    				drawCard(currentPlayer, state);
  				}
  				into
  				for (i = 0; i < 4; i++) {
    				drawCard(currentPlayer, state);
  				}
  	2nd bug: Modified state->numBuys from
  			 state->numBuys = state->numBuys + 2;
  			 into
  			 state->numBuys = state->numBuys + 1;

	Result:

		Testing Council Room Card
		Checking handCount
		hand count = 8, expected = 8
		Checking deckCount
		deck count = 1, expected = 1
		Checking buys
		buys = 2, expected = 2


4. cardtest4 -> Testing Feast Card

	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

5. unittest1 -> Testing checkWhoseTurn()

	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

6. unittest2 -> Testing checkSupplyCount()

	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

7. unittest3 -> Testing checkBuyCard()

	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

8. unittest4 -> Testing checkGainCard()
	
	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

9. randomtestadventurer -> Testing adventurer card (RANDOM)

	Number of test: 2000

	Note: Player is randomly assigned. It can be either 0, 1, or 2.

	Failed test location:

		TEST NUMBER 1990

		Player: 1
		Checking that cardEffect returns 0:
		RESULT: PASSED
		Checking +2 treasure:
		RESULT: FAILED
		Checking discardCount and deckCount:
		RESULT: FAILED
		Checking that Adventurer has been added to played pile:
		RESULT: FAILED
		Checking that playedCardCount has been incremented by 1:
		RESULT: FAILED
		Number of failures during this function call: 4
		.
		.
		.
		.
		.
		TEST NUMBER 2000

		Player: 1
		Checking that cardEffect returns 0:
		RESULT: PASSED
		Checking +2 treasure:
		RESULT: FAILED
		Checking discardCount and deckCount:
		RESULT: FAILED
		Checking that Adventurer has been added to played pile:
		RESULT: FAILED
		Checking that playedCardCount has been incremented by 1:
		RESULT: FAILED
		Number of failures during this function call: 4

		Total Number of Failures: 7996

	Explanation:


	Failed test location:

		TEST NUMBER 1994

		Player: 2
		Checking that cardEffect returns 0:
		RESULT: PASSED
		Checking +2 treasure:
		RESULT: PASSED
		Checking discardCount and deckCount:
		RESULT: PASSED
		Checking that Adventurer has been added to played pile:
		RESULT: FAILED
		Checking that playedCardCount has been incremented by 1:
		RESULT: FAILED
		
		Total Number of Failures: 4000 

	Method: 
	

	Solution:
	I noticed that for adventurerCard() didn't even bother to
	call discardCard(). Trus I added discardCard(handPos, currentPlayer, state, 0)
	after the last 'while-loop'. Since discardCard() includes handPos,
	thus I also realized that adventurerCard only has one parameter
	which is "struct gameState *state". I added another parameter 
	"int handPos" in order to be used by discardCard().

	Failed test location:

		TEST NUMBER 2000

		Player: 0
		Checking that cardEffect returns 0:
		RESULT: PASSED
		Checking +2 treasure:
		RESULT: PASSED
		Checking discardCount and deckCount:
		RESULT: PASSED
		Checking that Adventurer has been added to played pile:
		RESULT: FAILED
		Checking that playedCardCount has been incremented by 1:
		RESULT: PASSED
		
		Total Number of Failures: 2100

	Solution:
	I noticed that the number of failures reduced by half (2000).
	
	(gdb) print game->playedCards[0]
	$5 = 21 
	
	As we know, Adventurer is 7, thus the one that's been put into
	played pile is not an adventurer card.

	Conclusion: It's a bug from dominion, and I couldn't find the source
				of the bug.


10.randomtestcard -> Testing council room (RANDOM)

	Number of test: 2000

	Note: Player is randomly assigned. It can be either 0, 1, or 2.

	Failed test location:
		
		TEST NUMBER 1991

		Player: 1
		Checking that cardEffect returns 0:
		RESULT: PASSED
		Checking handCount:
		RESULT: FAILED
		deckCount now = 128
		Checking deckCount:
		RESULT: FAILED
		Checking discardCount:
		RESULT: PASSED
		Checking buys:
		RESULT: FAILED
		Checking that the card has been added to played pile:
		RESULT: PASSED
		Number of failures during this function call: 3
		.
		.
		.
		.
		.
		TEST NUMBER 2000

		Player: 0
		Checking that cardEffect returns 0:
		RESULT: PASSED
		Checking handCount:
		RESULT: FAILED
		deckCount now = 128
		Checking deckCount:
		RESULT: FAILED
		Checking discardCount:
		RESULT: PASSED
		Checking buys:
		RESULT: FAILED
		Checking that the card has been added to played pile:
		RESULT: PASSED
		Number of failures during this function call: 3

		Total Number of Failures: 6000

	Explanation:
	1st bug: Checking handCount & deckCount obviously FAILED because
			 as the unittest tells that council room draws +2 cards
			 only instead of 4.
	2nd bug: Checking buys FAILED as well because as the unittest
			 tells that council room gives +2 buys instead of 1.

	Solution:
	Since the unittest for CouncilRoom all passed then 
	it passed all the random tests as well. Below is the 
	print statement from the randomtestcard

		.
		.
		.
		.
		TEST NUMBER 2000

		Player: 0
		Checking that cardEffect returns 0:
		RESULT: PASSED
		Checking handCount:
		RESULT: PASSED
		deckCount now = 128
		Checking deckCount:
		RESULT: PASSED
		Checking discardCount:
		RESULT: PASSED
		Checking buys:
		RESULT: PASSED
		Checking that the card has been added to played pile:
		RESULT: PASSED
		Number of failures during this function call: 0

		Total Number of Failures: 0

-----------------------------------------------------------------------

Based on Behn's tests, below are the report.

1. cardtest1 -> Testing Smithy
	
	Failed test location:

		None
	
	Solution: No other failed test for Smithy because the testing
			  are both similar, thus once the bug been detected (draw 4 instead of 3)
			  any test for smithy must show not failed.

2. cardtest2 -> Testing Adventurer

	Note: This test files check treasure card before and after "adventurer" card
	
	Failed test location:
	
		None

	Solution: Since Adventurer() being fixed from previous test, thus when this test
			  file is testing for the number of treasure card in hand, it passed the test.

3. cardtest3 -> Testing Adventurer
	
	Failed test location:

		???

	No Explanation & Solution.
	When test file being executed, it only prints "Not enough time: Adventurer".
	My teammate lost his test file due to github repository problem that overwrite
	the whole class file.

4. cardtest4 -> Testing Adventurer

	Failed test location:

		???

	No Explanation & Solution.
	When test file being executed, it only prints "Not enough time: Adventurer".
	My teammate lost his test file due to github repository problem that overwrite
	the whole class file.

5. unittest1 -> Testing updateCoins()

	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

6. unittest2 -> Testing isGameOver()

	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

7. unittest3 -> Testing kindgomCards

	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

8. unittest4 -> Testing scoreFor()
	
	Failed test location:

		None

	No Explanation and Solution since no bugs detected.

9. randomtestadventurer -> Testing adventurer card (RANDOM)

	Number of test: 1000

	Note: This test files check treasure card before and after "adventurer" card.
		  Similar to the unit test, but this one using random testing implementation.

	Failed test location:
		
			None

	Explanation: Since test unit and random test for adventurer pretty similar, thus
				 both of these tests yield no FAILED result.
	

10.randomtestcard -> Testing Smithy (RANDOM)

	Number of test: 1000

	Note: The test basically testing handCount before&after smithy
		  also discard pile. Pretty similar with previous test that I
		  already tested and fixed.

	Failed test location:

		None

	Solution: No other failed test from Smithy because the testing
			  are both similar, thus once the bug been detected (draw 4 instead of 3)
			  any test for smithy must show not failed.
*/