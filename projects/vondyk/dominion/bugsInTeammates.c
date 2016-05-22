/*************************************************
** Reporter: Kayla Vondy
** Filename: bugsInTeammates.c
** Description: This file describes any failures
** 		in tests and subsequent bugs I found in 
**		my teammates' dominion.c code file using
** 		unit and random tests I generated in 
** 		previous assignments.
*************************************************/

/****************************************
** Reporter: Kayla Vondy
** Teammate: Lisa Scheibner (scheibnl)
** File Tested: dominion.c
****************************************/

Test card -- Smithy
Component -- cardEffect() -> smithyAction()
Failed Tests from cardtest1.c
	Test 1: Play Smithy and gain 3 cards:
		FAILED. Hand Size Start: 7   		Hand Size Finish: 8
	Test 3: Player 1 is drawing properly from own pile:
		FAILED. Expected Deck Size: 2   	Deck Size Finish: 1
Coverage for Function (cardtest1.c):
	Lines executed:100.00% of 5
	Branches executed:100.00% of 2
	Taken at least once:100.00% of 2
	Calls executed:100.00% of 2
Coverage for Function (randomtestcard.c):
	Lines executed:100.00% of 5
	Branches executed:100.00% of 2
	Taken at least once:100.00% of 2
	Calls executed:100.00% of 2
Summary:
	Based on the failed unit test of the Smithy card (cardtest1.c) it can be concluded 
	that when the Smithy card is played, the player is drawing 4 cards from their deck 
	as opposed to the 3 cards that the Smithy card *should* cause to be drawn. When 
	checking the code for this particular function, it was discovered that in the for 
	loop where the drawCard function is called, the for loop range had been altered 
	from (i=0; i<3; i++) to (i=0;i<=3;i++). This subtle change causes the for loop to 
	iterate four times instead of three and thus fail the deck size and hand size tests.

Test card -- Adventurer
Component -- cardEffect() -> adventurerAction()
Failed Tests from cardtest2.c
	Test 4: Make sure all cards that were not coins were discarded properly:
		FAILED. Expected discard amount: 1			Discarded amount: 2
	Test 8: Adventurer card added to played pile after use:
		FAILED. Expected increase in played pile: 1   	 	Actual increase to played pile: 0
Coverage for Function (cardtest2.c):
	Lines executed:93.33% of 15
	Branches executed:100.00% of 12
	Taken at least once:91.67% of 12
	Calls executed:50.00% of 2
Coverage for Function (randomtestcard.c):
	Lines executed:100.00% of 15
	Branches executed:100.00% of 12
	Taken at least once:100.00% of 12
	Calls executed:100.00% of 2
Summary: 
	Based on the failed unit test of the Adventurer card (cardtest2.c) it can be concluded 
	that there is a bug preventing the Adventurer card from being discarded properly to the 
	played pile after it has been played. Also, it appears that the amount discarded by 
	playing the Adventurer card was more than what it should be, based on the rules of the 
	card. This leads me to believe that the bug lies in the part of the function where the 
	discard occurs. This occurs in a while loop which uses a temp hand counter to discard 
	all cards in play that have been drawn. The problem in this loop is that the counter 
	should be z-1 instead of just z to properly discard the cards drawn.

/****************************************
** Reporter: Kayla Vondy
** Teammate: Chris McLaughlin (mclauchr)
** File Tested: dominion.c
****************************************/

Test card -- Smithy
Component -- cardEffect() -> smithyFunction()
Failed Tests from cardtest1.c
	Test 1: Play Smithy and gain 3 cards:
		FAILED. Hand Size Start: 7   		Hand Size Finish: 8
	Test 3: Player 1 is drawing properly from own pile:
		FAILED. Expected Deck Size: 2   	Deck Size Finish: 1
Coverage for Function (cardtest1.c):
	Lines executed:100.00% of 6
	Branches executed:100.00% of 2
	Taken at least once:100.00% of 2
	Calls executed:100.00% of 2
Coverage for Function (randomtestcard.c):
	Lines executed:100.00% of 6
	Branches executed:100.00% of 2
	Taken at least once:100.00% of 2
	Calls executed:100.00% of 2
Summary:
	Based on the failed unit test of the Smithy card (cardtest1.c) it can be concluded 
	that when the Smithy card is played, the player is drawing 4 cards from their deck 
	as opposed to the 3 cards that the Smithy card *should* cause to be drawn. When 
	checking the code for this particular function, it was discovered that in the for 
	loop where the drawCard function is called, the for loop range had been altered 
	from (i=0; i<3; i++) to (i=0;i<=3;i++). This subtle change causes the for loop to 
	iterate four times instead of three and thus fail the deck size and hand size tests.

Test card -- Adventurer
Component -- cardEffect() -> adventurerFunction()
Failed Tests from cardtest2.c
	Test 1: Play Adventurer and draw until two coins are drawn:
		FAILED. Coin card amount expected: 2   	Coin count finish: 1
		Coin cards Found: silver, 
	Test 3: Check test one again, but force gold to be drawn:
		FAILED. Coin card amount expected: 2   	Hand Size: 1
		Coin cards Found: gold,
	Test 7: Player is drawing and keeping only two cards from own pile:
		FAILED. Expected Deck size: 2   	Deck size finish: 3
	Test 8: Adventurer card added to played pile after use:
		FAILED. Expected increase in played pile: 1   	 	Actual increase to played pile: 0
Coverage for Function (cardtest2.c):
	Lines executed:94.44% of 18
	Branches executed:100.00% of 12
	Taken at least once:91.67% of 12
	Calls executed:50.00% of 2
Coverage for Function (randomtestcard.c):
	Lines executed:100.00% of 18
	Branches executed:100.00% of 12
	Taken at least once:100.00% of 12
	Calls executed:100.00% of 2
Summary: 
	Based on the failed tests, the Adventurer card should draw two coin cards, but is 
	only drawing one. This also causes the deck size and played pile size to be different
	from what is expected if the card was performing properly. We can confirm that the 
	player is in fact drawing a coin card, as seen in the coin cards found lines. Looking 
	at the code, we can see the result reflected where the drawntreasure is compared to 1 
	instead of 2. This means the code is only looking for one coin card as opposed to two like 
	it should.