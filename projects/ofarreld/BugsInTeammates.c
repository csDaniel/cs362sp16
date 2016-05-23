/* ****************************
*
*		Name: 												Daniel Ofarrell
*		Date Created:									18 May 2016
*		Last Modification Date:				19 May 2016
*		FileName: 										bugReport.c
*
*		Overview:
*			This is a bug report for cs362. The files tested are those found in:
*					- dominion.c
*
*			With respect to the teammates:
*					- 01 gellerj, Josh Geller
*					- 02 samuelal, alex Samuel
*
***************************** */

/*

	01: gellerj:
	Summary:
		A. Card Test 01 ... pass 
		B. Card Test 02 ... pass 
		C. Card Test 03 ... pass 
		D. Card Test 04 ... FAIL
			On each attempt, the number of cards returned to the user was incorrect. Results show that
			where (n) cards should be in the hand, (n-1) was shown each time. 
		E. Unit Test 01 ... pass  
		F. Unit Test 02 ... pass 
		G. Unit Test 03 ... FAILS 
			scoreFor() fails when attemping to calculate the score for cards found in the deck.
			scoreFor() fails when calculating garden cards.
		H. Unit Test 04 ... pass 
		I. Random Test 01 ... FAILS 
			See notes for D.
		J. Random Test 02 ... pass 
	
	Card Test 01: Smithy
		Results:
			Test 01: handCount = handCount + 3 (-1, smithy) 
			initial hand count = 5
			hand count = 7, expected = 7
			deck count = 2, expected = 2
			coins = 4, expected = 4
			SUPPLEMENTARY TESTING COMPLETE	
		Coverage:
			Function 'playSmithy'
			Lines executed:100.00% of 6
			Branches executed:100.00% of 2
			Taken at least once:100.00% of 2
			Calls executed:100.00% of 2

	Card Test 02: Great_Hall
		Results:
			Test 01: +1 card, +1 action 
			hand count = 5, expected = 5
			deck count = 4, expected = 4
			coins = 4, expected = 4
			player actions = 2, expected = 2
			SUPPLEMENTARY TESTING COMPLETE	
	Coverage: 
			According to the switch statement:
			Coverage: 100% 
			
	Card Test 03: Council_Room
		Results: 
			Test 01: coins += 2, +1 buy 
			hand count = 8, expected = 8
			deck count = 1, expected = 1
			coins = 4, expected = 4
			Player Buys = 2, expected = 2
			SUPPLEMENTARY TESTING COMPLETE	
		Coverage:
			Function 'playCouncil_Room'
			Lines executed:100.00% of 10
			Branches executed:100.00% of 6
			Taken at least once:100.00% of 6
			Calls executed:100.00% of 3

	Card Test 04: Adventurer
		Results:
			Test 01: draw cards until 2 treasures are found 
			Player hand = 5
			hand count = 7, expected = 6
			deck count = 3, expected = 3
			coins = 4, expected = 4
			ERROR: handCount does not match ... TEST FAILED
			SUPPLEMENTARY TESTING COMPLETE	
		Coverage:
			Function 'playAdventurer'
			Lines executed:100.00% of 18
			Branches executed:100.00% of 10
			Taken at least once:100.00% of 10
			Calls executed:100.00% of 2

	Unit Test 01: shuffle()
		Results:
			Test 01: Run Shuffle and check positions 
			Testing Player 1 Deck Size...	PASS
			Testing Player 1 deck integrity...	PASS
			Testing Player 1 Hand Size...	PASS
			SUPPLEMENTARY TESTING COMPLETE	
		Coverage:
			Function 'shuffle'
			Lines executed:100.00% of 16
			Branches executed:100.00% of 8
			Taken at least once:100.00% of 8
			Calls executed:100.00% of 2

	Unit Test 02: getCost()
		Results:
			Testing return values for all cards...	PASS
			SUPPLEMENTARY TESTING COMPLETE	
		Coverage:
			Lines executed:96.67% of 30
			Branches executed:100.00% of 28
			Taken at least once:96.43% of 28
			No calls

	Unit Test 03:scoreFor()
		Results:
			Test 03: Curse in deck
			Testing Score for Curse in deck...	ERROR
			Player score: 0, expected: -1
			Test 06: Estate in deck
			Testing Score for estate in deck...	ERROR
			Player score: 0, expected: 1
			Test 09: Duchy in deck
			Testing Score for duchy in deck...	ERROR
			Player score: 0, expected: 3
			Test 12: province in deck
			Testing Score for province in deck...	ERROR
			Player score: 0, expected: 6
			Test 15: great_hall in deck
			Testing Score for great_hall in deck...	ERROR
			Player score: 0, expected: 1
			Test 16: gardens in hand
			Testing Score for gardens in hand...	ERROR
			Player score: 4, expected: 5
			Test 17: gardens in discard
			Testing Score for gardens in discard...	ERROR
			Player score: 0, expected: 5
			Test 18: gardens in deck
			Testing Score for gardens in deck...	ERROR
			Player score: 0, expected: 5
		Coverage:
			Lines executed:100.00% of 24
			Branches executed:100.00% of 42
			Taken at least once:83.33% of 42
			Calls executed:33.33% of 3

	Unit Test 04: updateCoins()
		Results:
			Test 01: one copper to hand
			Testing coin with one copper in hand...	PASS
			SUPPLEMENTARY TESTING COMPLETE	
			Test 02: one silver to hand
			Testing coin with one silver in hand...	PASS
			SUPPLEMENTARY TESTING COMPLETE	
			Test 03: one gold to hand
			Testing coin with one silver in hand...	PASS
			Test 04: one gold to hand and -1 bonus
			Testing coin with one silver in hand...	PASS
			SUPPLEMENTARY TESTING COMPLETE	
		Coverage:
			Lines executed:100.00% of 11
			Branches executed:100.00% of 8
			Taken at least once:100.00% of 8
			No calls

	Random Test 01: Adventurer 
		Results:
			Error: Card Counts are incorrect where:
			EXECTED: 120, 	RESULT: 119
			Deck EXP 11, 	RES 5
			Discard EXP 0, 	RES 2
			HandDeck EXP 108, 	RES 112
		Coverage:
			Lines executed:100.00% of 18
			Branches executed:100.00% of 10
			Taken at least once:100.00% of 10
			Calls executed:100.00% of 2

	Random Test 02: Salvager
		Results:
			Testing Completed. All tests passed.
		Coverage: 
			According to the switch statement:
			Coverage: 100% 

02: samuelal:
	Summary:
		A. Card Test 01 ...  FAIL
			The smithy card is not increasing handCount +1, and deckCount +2. 
		B. Card Test 02 ...  FAIL 
			great_hall card is not increasing handCount +1, deckCount +1, and playerActions +1
		C. Card Test 03 ...  pass 
		D. Card Test 04 ...  FAIL 
			adventurer is not changing handCount, resulting in 9 cards where should be 6. deckCount is 
			showing 0, when should be +3. Moreover, player2 is shown to have +1 handCount and -1 deckCount 
		E. Unit Test 01 ... pass 
		F. Unit Test 02 ... pass 
		G. Unit Test 03 ... FAIL  
			scoreFor() fails when attemping to calculate the score for cards found in the deck.
			scoreFor() fails when calculating garden cards.
		H. Unit Test 04 ... pass 
		I. Random Test 01 ... FAIL   
			see notes fo D.
		J. Random Test 02 ... pass 
	
	Card Test 01: Smithy
		Results:
			Test 01: handCount = handCount + 3 (-1, smithy) 
			initial hand count = 5
			hand count = 8, expected = 7
			deck count = 0, expected = 2
			coins = 4, expected = 4
			ERROR: handCount does not match ... TEST FAILED
			ERROR: deckCount does not match ... TEST FAILED		
		Coverage:
			Lines executed:100.00% of 5
			Branches executed:100.00% of 2
			Taken at least once:100.00% of 2
			Calls executed:100.00% of 2

	Card Test 02: Great_Hall
		Results:
			Test 01: +1 card, +1 action 
			hand count = 6, expected = 5
			deck count = 3, expected = 4
			coins = 4, expected = 4
			player actions = 3, expected = 2
			ERROR: handCount does not match ... TEST FAILED
			ERROR: deckCount does not match ... TEST FAILED
			ERROR: player's actions do not match ... TEST FAILED
		Coverage: 
			Lines executed:100.00% of 5
			No branches
			Calls executed:100.00% of 2
						
	Card Test 03: Council_Room
		Results: 
			Test 01: coins += 2, +1 buy 
			hand count = 8, expected = 8
			deck count = 1, expected = 1
			coins = 4, expected = 4
			Player Buys = 2, expected = 2		
		Coverage:
			branch  0 taken 80%
			branch  1 taken 20% (fallthrough)
			call    0 returned 100%

	Card Test 04: Adventurer
		Results:
			Test 01: draw cards until 2 treasures are found 
			Player hand = 5
			hand count = 9, expected = 6
			deck count = 0, expected = 3
			coins = 4, expected = 4
			ERROR: handCount does not match ... TEST FAILED
			ERROR: deckCount does not match ... TEST FAILED
			ERROR: Player 2 hand count = 1, expected = 0
			ERROR: Player 2 deck count = 9, expected = 10
		Coverage:
			Lines executed:100.00% of 15
			Branches executed:100.00% of 12
			Taken at least once:100.00% of 12
			Calls executed:100.00% of 2

	Unit Test 01: shuffle()
		Results:
			Test 01: Run Shuffle and check positions 
			Testing Player 1 Deck Size...	PASS
			Testing Player 1 deck integrity...	PASS
			Testing Player 1 Hand Size...	PASS
		Coverage:
			Lines executed:100.00% of 16
			Branches executed:100.00% of 8
			Taken at least once:100.00% of 8
			Calls executed:100.00% of 2

	Unit Test 02: getCost()
		Results:
			Testing return values for all cards...	PASS
		Coverage:
			Lines executed:96.67% of 30
			Branches executed:100.00% of 28
			Taken at least once:96.43% of 28
			No calls

	Unit Test 03:scoreFor()
		Results:
			Test 03: Curse in deck
			Testing Score for Curse in deck...	ERROR
			Player score: 0, expected: -1
			Test 06: Estate in deck
			Testing Score for estate in deck...	ERROR
			Player score: 0, expected: 1
			Test 09: Duchy in deck
			Testing Score for duchy in deck...	ERROR
			Player score: 0, expected: 3
			Test 12: province in deck
			Testing Score for province in deck...	ERROR
			Player score: 0, expected: 6
			Test 15: great_hall in deck
			Testing Score for great_hall in deck...	ERROR
			Player score: 0, expected: 1
			Test 16: gardens in hand
			Testing Score for gardens in hand...	ERROR
			Player score: 4, expected: 5
			Test 17: gardens in discard
			Testing Score for gardens in discard...	ERROR
			Player score: 0, expected: 5
			Test 18: gardens in deck
			Testing Score for gardens in deck...	ERROR
			Player score: 0, expected: 5
		Coverage:
			Lines executed:100.00% of 24
			Branches executed:100.00% of 42
			Taken at least once:83.33% of 42
			Calls executed:33.33% of 3

	Unit Test 04: updateCoins()
		Results:
			Test 01: one copper to hand
			Testing coin with one copper in hand...	PASS
			Test 02: one silver to hand
			Testing coin with one silver in hand...	PASS
			Test 03: one gold to hand
			Testing coin with one silver in hand...	PASS
			Test 04: one gold to hand and -1 bonus
			Testing coin with one silver in hand...	PASS
		Coverage:
			Lines executed:100.00% of 11
			Branches executed:100.00% of 8
			Taken at least once:100.00% of 8
			No calls

	Random Test 01: Adventurer 
		Results:
			Error: Card Counts are incorrect where:
			EXECTED: 801, 	RESULT: 799
			Deck EXP 385, 	RES 352
			Discard EXP 92, 	RES 98
			HandDeck EXP 323, 	RES 349
			...
			Error: Card Counts are incorrect where:
			EXECTED: 589, 	RESULT: 587
			Deck EXP 50, 	RES 34
			Discard EXP 86, 	RES 92
			HandDeck EXP 452, 	RES 461
		Coverage:
			Lines executed:100.00% of 15
			Branches executed:100.00% of 12
			Taken at least once:100.00% of 12
			Calls executed:100.00% of 2

	Random Test 02: Salvager
		Results:
			Testing Completed. All tests passed.
		Coverage: 
			According to the switch statement:
			Coverage: 100% 



*/



