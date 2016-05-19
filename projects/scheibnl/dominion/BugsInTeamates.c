/*
Lisa Scheibner's BugsInTeamates.c File

************Kayla Vondy- vondyk***************

Bug 1:

	- Title: Playing Smithy Gives Four Cards Instead of Three
	
	- Function With Bug: playSmithy() in dominion.c
	
	- Description of Failed Test(s): 
	
		TEST 1: Current player receives 3 cards

		hand count = 8, expected = 7
		Assertion failed: testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded, file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\directory for github\scheibnl\teammate1dominion-vondyk\cardtest1.c, line 49

		TEST 2: 3 cards come from his/her own pile

		deck count = 1, expected = 2
		Assertion failed: testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards, file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\directory for github\scheibnl\teammate1dominion-vondyk\cardtest1.c, line 59
		
		Summary: The person who plays the Smithy card has 4 new cards in hand and 4 comes from the player's deck, while this should be 3.

Bug 2:

	-Title: Player doesn't receive two new treasure cards
	
	- Function With Bug: playAdventurer() in dominion.c
	
	- Description of Failed Test(s):
		
		TEST 1: Current player receives two cards, both of which are treasure cards

		hand count = 5, expected = 6
		Assertion failed: testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded, file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\directory for github\scheibnl\teammate1dominion-vondyk\cardtest2.c, line 48

		treasure cards on hand = 4, expected = 6
		Assertion failed: treasureCardsTest == (treasureCardsCopy + 2), file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\directory for github\scheibnl\teammate1dominion-vondyk\cardtest2.c, line 70

		Summary: These failed tests show that the player receives one new card (instead of two) and that the added card isn't a treasure card.

	

********Chris McLaughlin- mclauchr**********

Bug 1:

	-Title: Players With Copper Do Not Discard Said Copper When Cutpurse is Played
	
	- Function With Bug: cutpurseFuction() in dominion.c
	
	- Description of Failed Test(s):
	
		TEST 3: Other players all discard a copper or have none on hand
	
		Player 0: lost 0 cards and had copper = 1
		Assertion failed: ((G.handCount[i] - testG.handCount[i]) == 1) || (hadCopper == 0), file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\directory for github\scheibnl\teammate2dominion-mclauchr\randomtestcard.c, line 143
	
		Summary: When cutpurse is played, other players are supposed to discard a copper or they don't have one on hand.
		This test shows that players can have a copper on hand but don't discard it.


Bug 2:

	-Title: Current Player Receives Two Cards, But Both Aren't Treasure Cards
	
	- Function With Bug: adventurerFunction() in dominion.c
	
	- Description of Failed Test(s):
	
		TEST 1: Current player receives two cards, both of which are treasure cards

		hand count = 6, expected = 6
		treasure cards on hand = 5, expected = 6
		Assertion failed: treasureCardsTest == (treasureCardsCopy + 2), file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\directory for github\scheibnl\teammate2dominion-mclauchr\cardtest2.c, line 70
			
		Summary: This unit test shows that the player receives two cards, as expected, but they aren't both treasure cards. Only one is.

*/