/*

Lisa Scheibner- BugFixes.c

*******************Bugs Chris Found:*************************


	Fixed Bug # 1: 
	
	Both Chris and Kayla have noted this bug that I introduced.
	This bug exsits is because I added in an additional = to the comparison, 
	so instead of it running until i < 3, it ran until i <= 3. I have fixed this bug, and it has caused my
	related tests (such as Chris's here) to pass.

		/************************************************************
		** Bug #1A Title:  Smithy Card Draws an Additional Card
		** Reporter: Chris McLaughlin - mclauchr
		** Product: dominion.c
		** Component: cardEffect() - smithyAction()
		** Priority: P3
		** Severity: Minor - Give's slight advantage to the user who
		** 			 plays the cardEffect

		** Description: Each time the smithy card is played an extra
		** card is added to the players hand
		** 
		** Reproduction: In order to produce the bug I used my 
		** unit/card test suite.  cardtest1 was able to reproduce the 
		** bug.
		**
		** Test Results: 
		**
		** Test1: Appropriate Cards Add/Subtract (+3 - 1 = +2) Total: FAIL
		** Expected: 7, Test: 8
		*************************************************************/

		
/*	Fixed Bug #2: 
	
	As Chris has noticed, the adventurer function does not discard at the end 
	of the turn like the smithy card does. I added in a discard at the end of my function
	in order to fix this.
	
	Then, this caused a secondary problem. Now, I was discarding a treasure card instead of
	an adventurer card. I could tell because my treasure card count was one less than expected.
	It turns out, however, that this was more of a problem with my test methods than it was with
	the code itself. Although I called cardEffect with adventurer as a parameter, I never actually
	set a card in the player's hand as an adventurer card. So, without doing that, it discards a
	treasure card instead.
	
	By adding in a couple of lines to my cardtest2.c to set one of the players actual cards to an adventurer
	card before calling cardEffect, I was able to fix this problem.
	
	
*/
	
		
		/************************************************************
		** Bug #1B Title:  Adventurer Card Produces Error in handCount
		** Reporter: Chris McLaughlin - mclauchr
		** Product: dominion.c
		** Component: cardEffect() - adventurerAction()
		** Priority: P3
		** Severity: Minor - Give's slight advantage to the user who
		** 			 plays the cardEffect

		** Description: Each time the adventurer card is played, the 
		** player should draw cards until two treasure cards are drawn
		** all cards that were not treasure cards are discarded in
		** addition to the adventurer card itself.  This should result
		** in a +1 handCount for the current player. Tests have 
		** revealed that there is an additional card in the player's
		** handCount after the adventurer card is played.  
		** 
		** Reproduction: In order to produce the bug I used my 
		** unit/card test suite.  cardtest2 was able to
		** reproduce the bug.
		**
		** Test Results: 
		**
		** Test1: New Hand Count Should be +1: FAIL
		** Expected: 6, Tested: 7
		*************************************************************/

/*

********************Bugs Kayla Found:***********************

	Fixed Bug # 1 again:
	
	As Kayla notes below, this bug was, indeed, caused by a loop in my Smithy card running four
	times instead of the intended three. This is because I added in an additional = to the comparison, 
	so instead of it running until i < 3, it ran until i <= 3. I have fixed this bug, and it has caused my
	related tests (such as Kayla's here) to pass.

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

			
	Fixed Bug #3:
	
	I already fixed Kayla's second failed test by fixing what Chris mentioned earlier. I added a call
	to discard at the end of the adventurer function to match what smithy has. Although this is a bit
	confusing, since the player has a discard pile, discard adds the cards to the played cards stack in
	this case.
	
	As for the first mentioned bug, when I undid the bad code I introduced at the beginning of the semester
	(adding a subtraction of one back to a while statement's conditions), it only partially fixed the problem.
	However, this was not because of a bug in the actual code. It was because my tests weren't 100% perfect and 
	this wasn't obvious when they were failing for other reasons.
	
	First, I was calling cardEffect with an adventurer card when it was not certain that the current player's hand
	actually had an adventurer card in it. I was faking that there was an adventurer card there when this may not have
	been the case. So, if there was a coin card in this spot (the spot where I was faking an adventurer card), it would
	now be discarded at the end of the turn and mess up my coin count. So, instead of just calling cardEffect, I had to
	actually change the card at handpos to an adventurer card first.
	
	Second, I did think about adding in adventurer cards at one point in my tests, but this was causing troubles.
	I noticed that, when games first started, players were likely to have mostly coin cards on hand. I wanted to change
	this up to see how adventurer would act if the player didn't have coin cards in the last couple of spaces of their 
	hand, so it would have to draw some non-coin cards first. However, in doing so, I overwrote too many coin cards and
	only left one in the player's hand. This caused my discard counts to be off and my asserts to fail. I had to more carefully
	place my non-coin cards so as to leave at least two coin cards in the hand. I did this by placing one at the front of the
	hand and one at the back.
	
	Then, all of my adventurer tests were running smoothly.
	
			
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
			
			
	Fixed Bug #4:
	
		I was having the following test fail in my cutpurse function:
		
			TEST 4: Current player has same amount of cards on hand and in deck

			hand count = 3, expected = 4
			Assertion failed: testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded, file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\dominion\cardtest3.c, line 99
		
		In my cutpurse function, I originally introduced a bug so that the bad effects of cutpurse applied to the 
		current player instead of the other players in the game (by changing a != to a ==). After fixing this, 
		all of my tests	passed as expected.
		
	Fixed Bug #5:
	
		According to my tests, my player's hand was 3 cards too small after playing the sea_hag card. The following was
		the failing test:
		
			TEST 1: Each player (besides current) discards top card of deck and gains curse card, so deck size remains the same and discard is one

			Player 1 deck size= 7, expected = 10
			Assertion failed: testG.deckCount[i] == G.deckCount[i], file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\dominion\cardtest4.c, line 49
				
		
		Two of the lost cards were caused by bad references in the sea_hag function. Two times, the function used -- instead
		of subtracting 1, thus lowering the card count by two on accident. However, this only took card of two cards.
		
		For the third card, it appears that my understanding of what the card should do was different than what was actually
		implemented. My thought was that the card was supposed to simply replace a card with a curse card. However, it appears
		that the programmers decided to implement it so that it removes one card and replaces a card that is left with a curse
		card. So, instead of the hand count remaining the same, the player would lose one card.
		
	Fixed Bug #6:
	
		Like the adventurer function, the sea_hag function never discards at the end of the turn. So it was causing the following test
		to fail:
		
			TEST 4: Current player discards one card

			hand count = 5, expected = 4
			Assertion failed: testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded, file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\dominion\cardtest4.c, line 99
		
		This bug was easily fixed by adding in a call to the discard function before returning.
		
	Fixed Bug #7:
	
		Those who wrote the sea_hag function didn't take into consideration that the curse card needs to come from somewhere.
		Therefore, the stack of available curse cards should shrink by one. I found the following test failing as well:
		
			TEST 6: Curse pile should shrink by number of other players

			curse card count = 10, expected = 9
			Assertion failed: testG.supplyCount[0] == (G.supplyCount[0] - (numPlayers - 1)), file c:\users\lisa\documents\beaver nation\spring 2016\software engineering ii\dominion\cardtest4.c, line 133

		This was fixed by simply decrementing the curse card pile count after replacing a card with a curse card.	
*/