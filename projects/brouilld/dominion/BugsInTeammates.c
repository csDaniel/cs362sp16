

Teammate: blumen
	Results from Unit tests and Random Unit Tests being ran:
		The following unit tests passed:
			- 'UpdateCoins()': All unit tests passed
			- 'getCost()': All unit tests passed
			- 'playCard()': All unit tests passed
			- 'buyCard()': All unit tests passed 
			- 'Council Room' adds 1 buy to player
			- 'Village' adds two actions

		The following unit tests failed:
			-'Smithy' : 'smithy' adds 3 cards
			Result : Result was 4. Expected 3

			-'Smithy' : 'smithy' is discarded after play
			Result: 'smithy' is not discarded after play

			- 'Adventurer' : 'adventurer' adds 2 treasure cards to hand
			Result : Result was -487. Expected 2

			- 'Adventurer' : 'adventurer' adds 2 treasure cards to hand with copper deck
			Result : Result was -487. Expected 2

			- 'Adventurer' : 'adventurer' adds 2 treasure cards to hand with silver deck
			Result : Result was 5. Expected 2

			- 'Adventurer' : 'adventurer' adds 2 treasure cards to hand with gold deck
			Result : Result was 5. Expected 2

			- 'Council Room' : 'Council Room' adds 1 card to other player's hand
			Result : Result was 0. Expected 1


	Bug Report
		1.) 'Smithy' adds 4 cards, not 3
		2.) 'Adventurer' isn't discarded after play
		3.) 'Adventurer' doesn't include copper as a treasure
		4.) 'Adventurer' doesn't add the correct number of cards based on silver or gold treasures
		5.) 'Council Room' adds 0 cards to opponent's hand, not 1
		

/**********************************************************************************************/

Teammate: garnicri
	Results from Unit tests and Random Unit Tests being ran:
		The following unit tests passed:
			- 'UpdateCoins()': All unit tests passed
			- 'getCost()': All unit tests passed
			- 'playCard()': All unit tests passed
			- 'buyCard()': All unit tests passed 
			- 'Council Room' adds 1 buy to player


		The following unit tests failed:
			- 'Smithy' : 'smithy' adds 3 cards to hand
			Result : Result was 4. Expected 3.

			- 'Adventurer' : 'adventurer' adds 2 treasure cards to hand
			Result : Result was 1. Expected 2.

			- 'Adventurer' : 'adventurer' adds 2 treasure cards to hand with copper deck
			Result : Result was 1. Expected 2.

			- 'Adventurer' : 'adventurer' adds 2 treasure cards to hand with silver deck
			Result : Result was 1. Expected 2.

			- 'Adventurer' : 'adventurer' adds 2 treasure cards to hand with gold deck
			Result : Result was 0. Expected 2.

			- 'Council Room' : 'Council Room' adds 4 cards to hand
			Result : Result was 3. Expected 4

			- 'Council Room' : 'Council Room' adds 1 card to other player's hand
			Result : Result was 0. Expected 1

			- 'Village' : 'village' adds one card to hand
			Result: Result was 2. Expected 1

			- 'Village' : 'village' adds two actions
			Result: Result was 1. Expected 2

	Bug Report based on testing:
		1.) 'Smithy' selects four cards, not 3
		2.) 'Adventurer' results in only 1 card being drawn for either copper or silver, not 2
		3.) 'Adventurer' doesn't include gold as a treasure
		4.) 'Council Room' adds 3 cards to hand, not 4
		5.) 'Council Room' adds 0 cards to opponent's hand, not 1
		6.) 'Village' adds 2 cards to hand, not 1
		7.) 'Village' adds 1 action, not 2