/*  * BugFixes.c  */
/*

Bamesbem:
"Bug 1:
 
 "Title: Adventurer card not discarding all cards
 
 A bug was discovered in the playAdventurer() function in dominion.c
 
 Classification: Minor bug
 
 Description: The bug was discovered in the while loop at the end of the function that is
 responsible for discarding the non-treasure cards that were drawn in the function's previous while loop.
 
 What's the error: The second while loop reads while (z-2 >= 0), when it should instead read
 while(z-1 >=0). The loop does not discard all the cards necessary."

 The process used to fix this:
	1) Changed the 2nd while loop in the playAdventurer() function. 
	2) Ran my original test. I found that it still returned the correctly. 
	3) Altered the test to include a comparison between my test games and normal
	games discardCount.
	4) Emailed Michael for his test of my code for verification, tried it out in my cardtest1.c. Tests were successful.
	Added Comments to distinguish eachothers code.
	5) Ran the file cardtest1.c through gcov, also still returns normally. I also 
	ran dominion through gcov. Covered 95.62 % of 92 lines. Ran test cases and checked
	to see if adventurer was ever used successfully. It was on multiple counts.

Resolution: Fixing the while loop didn't cause any errors and now the game discards the
correct amount of cards each turn.

"Bug 2:
 Title: Smithy Card not incrementing playCard after discard
 
 A bug was discovered in the playSmithy() function in dominion.c
 
 Classification: Minor bug
 
 Description: The was discovered in the discardCard() function at the end of the
 playSmithy function(). The bug is involved with the setting of the function's trashFlag.
 
 What's the error: The discard funciton reads discardCard(handPos, currentPlayer, state, 1)
 when it should read discardCard(handPos, currentPlayer, state, 0). The change in the
 trashFlag means that the discardCard function does not add the player's Smithy card to the
 playedCard pile and increment the playedCardCount."

 The process used to fix this:
	1) Changed discard function to discardCard(handPos, currentPlayer, state, 0). 
	2) Altered my test to check if the played cards were different by 1. Confirmed that they were.
	Also added a variable called playedCards and set it equal to 1 and added it to the untested version.
	4) Ran the file cardtest2.c through gcov and ran through 100%. playdom returns at 95.56% still.

gabremam:

Bug 3:
	"unittest2 (test isGameOver()): Failed!
   isGameOver method failed the test because it does not check all card values. 
   Game is over when stack of Province cards is empty or when three of the supply piles are at 0.
   When checking for supply piles, it misses to check the last 2 kingdom card piles."

   The Process Used to Fix this:
   1) Changed my unittest 2 into Martha's to test isGameOver
   2) Ran the test and looked at the prerequiremnets not met in the two tests where it failed. 
   3) Made my function return 1 with an if statement to account for the missed kingdom card piles. 
   I also added seperate if statements for the supply piles. 
   4) Ran the unittest2 multiple times, returned with 10 out of 10 tests passed. 
   5) Ran gcov. Covers 97.83% of 92 lines now.
   6) Returned my unittest2 to test for scoreFor() function. 

   Resoultion: The original dominion game did not account for those other conditions. By adding
   them each one by one I created a solution. Could be done more elegantly with a for loop
   but the straight forward apporach more than works and also has less chance for memory loss.

Bug 4: 
	"Test failed although I did not expect it to. When analyzing Evan's payAdventurer function, I realized my
	unit test was not sufficient. It only checks the handCount to verify validity of function. The error in 
	Evan's refactored playAdventurer function would have been caught if test also checked the discardCount.
	That being said, since my cardTest was checking handCount only and Evan's function is expected give the correct
	handCount, I did not expect it to Fail. 
	It took me some time to figure out why test was failing. It looks like Evan is not returning after each card in 
	cardEffect.

	Recommendation for Evan: put a return 0 statement at the end of each case rerouting to refactored functions in cardEffect function.
	Right now, code is not ending after executing playAdventurer and coming back to cardEffect."

	Process:
		1) I already solved this bug partially in Bug 1 by changing the second while
		loop to discard the correct amount.
		2) I fixed the CardEffect function as per her reccomendation by adding return 0 at the end of each case.
		3) Ran gcov. Still returns 97.83% on coverage.
	Resoultion: Very straightforward bug that built off of the one solved in Bug 1. Adding return 0 after
	my cases was a success. 

Bug 5: 
	"randomtestadventurer : Failed!
	My random test is better my unit test because it doesn't only check handCount.
	it also checks the sum of hand, deck, and discard counts 
	Test failed because of incorrect discard pile. 
	Evan's playAdventurer function does not discard correctly (misses 1)."

	resolution:
	This was Bug 1 that Michael found in my code. As the bug is already fixed, (I tested it again just
	to make sure) I will reitterate that the second while loop in my playAdventurer function was fiexed to loop
	while z -1 >= 0 rather than z-2 >= 0.


	

*/
//