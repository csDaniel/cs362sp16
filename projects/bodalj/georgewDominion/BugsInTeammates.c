/*
Jens Bodal Bugs Found:

#1
Adventurer:

When looking at the code for Jen's Adventurer function I noticed he had a variable for TREASURES_TO_DRAW which was set to 3.
This variable is actually not used anywhere in the function. After running my unit tests on the function I noticed the hand count 
increased each time but only by 1 instead of 2, as it should if the player draws the two treasure cards. This can also be seen in 
my random tests as I had 97% code coverage but every test failed, so the last line to indicate the test was a sccess was the one that
didn't run.

Bug Location: 

The bug in the code is located at 1099 in the dominion.c file. There is a logic error there where the drawnTreasure is set at 1 rather
than being set at 2 to get the correct function.

#2
Smithy

After not finding any noticable bugs in smithy I refactored my test to output the played cards in pile. When doing this I expected to 
see the smithy card in those that are played but noticed it was not. Instead an estate card was played. This indicated that the incorrect 
card was sent via the discardCard method. When looking at the code I noticed the play smithy function did not return the card at the current hand position 
(the smithy card) but the one behind it. This explains the error.

Bug Location:

The bug is located at line 1302 in the dominion.c file. In the playSmithy method. The function discardCard is called with parameted handPos = handPos - 1
rather than handPos.

*********************************************************************************************************************************************************

Emily Snyder Bugs Found:

#1 
Minion Card

When looking at the coverage  of the random test for the minion card I noticed there were a lot of failures when 
counting the number of cards when choice 2 was chosen, also when choice 1 was chosen there were a lot of failures for the count
of coins before and after. When looking at the code I noticed choices 1 and 2 were actually swapped, which would explain the
failures.

Bug Location:

The bugs for the swap are located at 1286 and 1290 respectively.

#2 Smithy Card

In the smithy card unit tests I noticed all tests failed. The functions purpose is to add three cards to the hand and discard one.
Instead the function added only two cards. In the test the deck count decreased from 5 to 3, which indicates this bug occured.
Also the players hand when the function completes should have 2 new cards, while testing there was only one new card added to the 
players hand meaning only 2 cards were added and 1 discarded. I also refactored my test suite to see played cards as the smithy card should be 
discarded. The function shows that no cards were played meaning the smithy card was not discarded properly. 

Looking at the function I noticed two bugs. One in the discardCard function. The trashflag was set meaning instead of the card going into
the played pile it was trashed. This would explain the second bug. Also there was an error in the for loop for drawing cards. Instead of starting at 0 the loop starts at 1,
meaning it will only draw two cards rather than drawing three as it was supposed to.

Bug Locations:

The bug for the discardCard function is located at 1204, the bug for the error in the drawCard loop is on line 1199.



