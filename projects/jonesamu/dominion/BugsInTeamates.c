

Bugs Found in Jerry's Code

	1. Bug found in isGameOver function. High Severity, can cause game to continue longer than it should.
	 Code from test:
	  TESTING with an empty salvager, sea_hag, and treasure_map stack
		         Return value: 0 Expected Value: 1

	 This bug originates from the fact that when isGameOver is looking for 3 empty supply piles, it only checks piles 0 - 24. It does not
	 check piles 25 or 26.

	This bug was found with unittest1.c

	2. Bug found in scoreFore function. Medium Severity, only affects players that use garden card.
	 Code from test:
	  TESTING where players have 29 smithy cards and 1 gardens card

         Player 1 - Return value: 0      Expected Value: 3

         Player 2 - Return value: 0      Expected Value: 3

         Player 3 - Return value: 0      Expected Value: 3

         Player 4 - Return value: 0      Expected Value: 3

	 This bug originates from the fact that when calculating a score with the gardens card, the function calls fullDeckCount with 0 as its second parameter.
	 This means that it will only return a count of how many curse cards are in each deck, not the total card count which is what is needed based on the
	 purpose of the gardens card. I believe this is a misinterpretation of the fullDeckCount function based on its name.

	3. Bug found in Adventurer Card. Low severity. High priority due to easy fix.
	 Code from test:
	  TESTING that hand count for current player is 1 more than it started at (Gain 2 treasures, but lose adventurer card)
         Hand Count: 7   Expected: 6

	 This bug stems from the fact that the adventure card, as it is written, does not call the discardCard function at the end of its execution.
