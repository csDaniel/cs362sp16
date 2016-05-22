/****************************************************************************************

Bugs Found in Jerry's Code

	1. Bug found in isGameOver function.
	 Code from test:
	  TESTING with an empty salvager, sea_hag, and treasure_map stack:(last 3 'action cards')         Return value: 0 Expected Value: 1
	  
	 This bug originates from the fact that when isGameOver is looking for 3 empty supply piles, it only checks piles 0 - 24. It does not
	 check piles 25 or 26. 
	 
	This bug was found with unittest1.c
	
	2. Bug found in scoreFore function
	 Code from test:
	  TESTING where players have 29 smithy cards and 1 gardens card

         Player 1 - Return value: 0      Expected Value: 3

         Player 2 - Return value: 0      Expected Value: 3

         Player 3 - Return value: 0      Expected Value: 3

         Player 4 - Return value: 0      Expected Value: 3

	 This bug originates from the fact that when calculating a score with the gardens card, the function calls fullDeckCount with 0 as its second parameter.
	 This means that it will only return a count of how many curse cards are in each deck, not the total card count which is what is needed based on the 
	 purpose of the gardens card. I believe this is a misinterpretation of the fullDeckCount function based on its name.
	 
	3. Bug found in Adventurer Card
	 Code from test:
	  TESTING that hand count for current player is 1 more than it started at (Gain 2 treasures, but lose adventurer card)
         Hand Count: 7   Expected: 6
	
	 This bug stems from the fact that the adventure card, as it is written, does not call the discardCard function at the end of its execution.
	 
	 
	 
	 
Bugs Found in Samuel's Code

	1. Bug found in isGameOver function.
	 Code from test:
	  TESTING with an empty salvager, sea_hag, and treasure_map stack:(last 3 'action cards')         Return value: 0 Expected Value: 1
	  
	 This bug originates from the fact that when isGameOver is looking for 3 empty supply piles, it only checks piles 0 - 24. It does not
	 check piles 25 or 26. 
	 
	This bug was found with unittest1.c
	
	2. Bug found in scoreFore function
	 Code from test:
	  TESTING where players have 29 smithy cards and 1 gardens card

         Player 1 - Return value: 0      Expected Value: 3

         Player 2 - Return value: 0      Expected Value: 3

         Player 3 - Return value: 0      Expected Value: 3

         Player 4 - Return value: 0      Expected Value: 3

	 This bug originates from the fact that when calculating a score with the gardens card, the function calls fullDeckCount with 0 as its second parameter.
	 This means that it will only return a count of how many curse cards are in each deck, not the total card count which is what is needed based on the 
	 purpose of the gardens card. I believe this is a misinterpretation of the fullDeckCount function based on its name.
	 
	3. Bug found in Adventurer Card
	 Code from test:
	  TESTING that hand count for current player is 1 more than it started at (Gain 2 treasures, but lose adventurer card)
         Hand Count: 9   Expected: 6

	
	 This bug stems from the fact that the adventure card, as it is written, does not call the discardCard function at the end of its execution. Also, the 
	 adventure card function is supposed to provide two treasures, but as it is written, it gives 4 treasure cards and doesn't count a gold card as a treasure.
	 
	 
	4. Bug found in Smithy Card
	 Code from test:
	  TESTING that hand count for current player is 2 more than it started at (Gain 3 cards, but lose smithy card)
         Hand Count: 6   Expected: 7
	
	 This bug stems from the fact that the smithy card, as it is written, only has the player draw two cards when they are supposed to draw 3. 
	
	5. Bug found in Great Hall Card
	 Code from test:
	  TESTING that current player has received another Action point
         Action Count: 2 Expected: 1

	 This bug stems from the fact that the great hall card is only supposed to add 1 action to the player, but as it is written, it adds 2.
	 
	 
****************************************************************************************/