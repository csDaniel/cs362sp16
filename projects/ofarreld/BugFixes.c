/* ****************************
*
*		Name: 												Daniel Ofarrell
*		Date Created:									22 May 2016
*		Last Modification Date:				22 May 2016
*		FileName: 										BugFixes.c
*
*		Overview:
*       This is the followup bug Report for Assignment05.
*       My Teammates, Alex Samuel and Josh Geller have returned their 
*				bug reports to me. 
*
*
***************************** */

/*
		1. Smithy Card 
			A. Fixes:
				Line 1358, changed the for loop to iterate from 4 to 3. This should return 
				the desired amount of cards now. 
			B. Coverage:
				Function '_cardSmithy'
				Lines executed:100.00% of 5
				Branches executed:100.00% of 2
				Taken at least once:100.00% of 2
				Calls executed:100.00% of 2
			C. Results
				Test 01: handCount = handCount + 3 (-1, smithy) 
				initial hand count = 5
				hand count = 7, expected = 7
				deck count = 2, expected = 2
				coins = 4, expected = 4
			D. Rationale
				All tests passed accordingly with 100% coverage 
		2. Adventurer Card 
			A. Fixes: 
				Line 1414, changed or statement to include "cardDrawn == copper"
			B. Coverage	
				Function '_cardAdventurer'
				Lines executed:100.00% of 18
				Branches executed:100.00% of 12
				Taken at least once:100.00% of 12
				Calls executed:100.00% of 4			
			C. Results
				Test 01: draw cards until 2 treasures are found 
				Player hand = 5
				hand count = 6, expected = 6
				deck count = 3, expected = 3
				coins = 4, expected = 4
			D. Rationale
				All tests passed accordingly with 100% coverage.
		3. Village Card
			A. Fixes 
				Line 1372, changed "state->numActions - 2" to read "state->numActions +2"
			B. Coverage
				Function '_cardVillage'
				Lines executed:0.00% of 5
				No branches
				Calls executed:0.00% of 2			
			C. Results
				n/a 
			D. Rationale
				The card did not require excessive testing. This is due to the great coverage 
				provided by my teammates in their initial testing to isolate the very specific 
				problem with the card. It was an error I originally inserted and therefore was
				easily fixable.
		4. ScoreFor() Function 
			A. Fixes
				Line 445, changed the method how gardens calculates points 
				Line 430, changed the method how gardens calculates points 
				Line 464, changed the method how gardens calculates points
				Line 456, changed "state->discardCount[player]" to "state->deckCount[player]"
			B. Coverage
				Function 'scoreFor'
				Lines executed:100.00% of 26
				Branches executed:100.00% of 42
				Taken at least once:95.24% of 42
				No calls
			C. Results
				Test 17: gardens in discard
					Fulldeck = 0
					Testing Score for gardens in discard...	ERROR
					Player score: 0, expected: 5
				Test 18: gardens in deck
					Testing Score for gardens in deck...	ERROR
					Player score: 1, expected: 5
			D. Rationale
				95.24% paths taken at leats once. The coverage satisfies the testing requirements. 
				However, with regards to fixing the score for garden in deck and discard, the problem
				is must more serious. There seems to be no easy fix for calculating that score, based 
				on the current implementation of dominion.c. With how the garden card calculates scores,
				the reason lies with the a lack of the card being in the deck or discard. This means that
				perhaps the garden card is not being handled properly in other functions.
				However, it is important to note that all other bugs have been squashed in this problematic
				function.

























*/