/*
Tested my unittests, cardtests, and randomtests with wongder's dominion.c

Bugs Found -
 
Bug #1 - 
 Title - Card from hand being trashed instead of discarded in smithy card
 Date - 5/19/16
 Reported by - Tiffany Chiou
 Email - chiout@oregonstate.edu
 Product - dominion.c
 Platform - OSU flip server
 Unit test(s) that identified error: cardtest2.c
 Description - Ran cardtest2.c, which consists of 4 testcases. The 4 testcases (program runs) showed 2 failures where the current player's played card count either did not change or decreased, and the player's total card count is incorrect. Testcases 1, 3, and 4 showed success that the player's hand had a net gain of 2 cards, the deck+discard pile lost 3 cards, and those 3 cards are in the hand+played card pile. Testcase 2 showed success in that the player's hand had a net gain of 2 cards, the deck+discard pile lost 3 cards, but showed failure in that less than 3 cards from deck+discard pile are in the player's hand + played card pile. These failues lead me to deduce that 3 cards are being drawn but 1 card is being trashed instead of being discarded into the played card pile. The card being trashed in testcases 1, 3, and 4 was not one of the 3 drawn cards, but it was one of the 3 drawn cards in testcase 2.
 Bug is in line - Line 682 (smithyCard function). discardCard function call in smithyCard function call. The trashFlag parameter is passed into discardCard should be 0, not 2.
 Steps to produce/reproduce - Run "make cardtest2", then call cardtest2 executable. View test results.
 Expected Results - All 4 testcases pass
 Actual Results - Failures as described in description
 Reproduceable - Yes
 Severity - High
 Priority - High

Bug #2 -
 Title - Current player is drawing more than 4 cards in council room card
 Date - 5/19/16
 Reported by - Tiffany Chiou
 Email - chiout@oregonstate.edu
 Product - dominion.c
 Platform - OSU flip server
 Unit test(s) that identified error: cardtest4.c
 Description - Ran cardtest4.c, which consists of 4 testcases. All 4 testcases showed the same failures. The current player's hand count increases by more than 3, the deck+discard pile lost more than 4 cards (reflected by both the count and array evaluation), and that 4 drawn cards are not all in the hand+played card pile. The total card count is correct though. The tests lead me to deduce that the current player is drawing more than 4 cards from the deck+discard pile as this would describe the three failures.
 Bug is in line - Lines 700-703 (council_roomCard function).  The drawCard function in the second for loop should not apply to the current player; only players that are not the current player should draw a card.
 Reproduceable - Yes
 Steps to produce/reproduce - Run "make cardtest4", then call cardtest4 executable. View test results.
 Expected Results - All 4 testcases pass
 Actual Results - Failures as described in description
 Severity - High
 Priority - High
 
 Bug #3 -
 Title - Less than 2 treasure cards in deck+discard piles scenario not accounted for in adventurer card
 Date - 5/19/16
 Reported by - Tiffany Chiou
 Email - chiout@oregonstate.edu
 Product - dominion.c
 Platform - OSU flip server
 Unit test(s) that identified error: randomtestadventurer.c
 Description - 1 out of 5000 testcases in randomtestadventurer.c found this failure, which was that the deck+ discard piles were not missing 2 cards, and at the end of the turn the deck count was 0. This is a boundary case issue that I identified and recorded previously in randomhistory.c; if the deck+discard pile has less than 2 treasure cards, then only 0 or 1 treasure cards are drawn. The adventurer card does not explicitly handle this boundary case scenario. This may or may not be a bug, depending on if it is correct behavior to allow the user to attempt to carry out the directions of the adventurer card even though it cannot be correctly completed. If so, it would be helpful to notify the user of the situation at least.
 Bug is in line - adventurerCard function; can also be found in not refactored dominion.c
 Reproduceable - Yes
 Steps to produce/reproduce - Run "make randomTestAdventurer", then call randomTestAdventurer executable. View test results.
 Expected Results - All 5000 testcases pass
 Actual Results - Failures as described in description
 Severity - Low (may not actually happen in a real game, and potentially may not be a bug)
 Priority - Low (may not be an issue in a real game or may not be an actual bug so not a high priority to fix)

------------------------------------------------------------------------

Testing my unittests and cardtests with hallbry's dominion.c

Bugs Found -

Bug #1 -
 Title - Wrong number of cards added to discard pile in adventurer card
 Date - 5/19/16
 Reported by - Tiffany Chiou
 Email - chiout@oregonstate.edu
 Product - dominion.c
 Platform - OSU flip server
 Unit test(s) that identified error: cardtest1.c, randomtestadventurer.c
 Description - All 4 testcases of cardtest1.c identified the same failures. The current player's total card count is incorrect, the total cards in deck+discard is not missing 2 cards and the deck+discard arrays are either missing or containing invalid cards. The current player's hand array has correctly increased by 2 treasure cards though. The failures and successes related to the current player leads me to believe that after the cards are drawn, the non-treasure cards that the player draws are somehow not properly added back into the discard pile. Since the total card count is incorrect, either some of the non-treasure cards are being lost or additional cards are wrongfully introduced to the discard pile. The random test, randomtestadventurer.c, showed 5000/5000 testcases failed - and they all failed on the first test which was that the deck+discard count did not increase by 2 cards, which supports the idea the discard pile may not be receiving the right number of non-treasure cards. Acting on this knowledge, the bug can be found in the last while loop condition where z+1 is supposed to be z-1. This bug causes 2 additional cards to be added to the discard pile.
 Bug is in line - Line 1287 (playAdventurer function) - z+1 >= 0 should be z-1 >= 0
 Steps to produce/reproduce - Run "make cardtest1", then call cardtest1 executable. View test results. Then Run "make randomTestAdventurer" and run "randomTestAdventurer". View test results.
 Expected Results - All testcases pass
 Actual Results - Failures as described in description
 Reproduceable - Yes
 Severity - High
 Priority - High
 
Bug #2 -
 Title - Current player draws more than 3 cards in smithy card
 Date - 5/19/16
 Reported by - Tiffany Chiou
 Email - chiout@oregonstate.edu
 Product - dominion.c
 Platform - OSU flip server
 Unit test(s) that identified error: cardtest2.c
 Description - The 4 testcases of cardtest2.c all found the same failures. The current player's hand count had a net gain of greater than 2 cards, the deck+discard pile lost more than 3 cards, and more than 3 cards from the deck+discard pile are in the hand or played cards pile. The played card count is correct and the total card count for the current player is correct. This leads me to deduce that the current player drew more than 3 cards and then correctly discarded one card to the played card pile. With this information, the bug can be identified in the for loop condition which monitors the number of cards that is drawn.
 Bug is in line - Line 1300 (playSmithy function) - for loop condition should be i < 3 instead of i < 6
 Steps to produce/reproduce - Run "make cardtest2", then call cardtest2 executable. View test results.
 Expected Results - All 4 testcases pass
 Actual Results - Failures as described in description
 Reproduceable - Yes
 Severity - High
 Priority - High

Bug #3 -
 Title - Current player draws more than 4 cards in council room card
 Date - 5/19/16
 Reported by - Tiffany Chiou
 Email - chiout@oregonstate.edu
 Product - dominion.c
 Platform - OSU flip server
 Unit test(s) that identified error: cardtest4.c
 Description - All 4 test cases of cardtest4.c identified the same failures. The current player's hand count increases by more than 3 cards, the discard+deck is missing more than 4 cards, and 4 drawn cards are not all in the hand+played card pile. The total card count for the current player is correct. These results lead me to deduce that the bug must be that the current player draws more than 4 cards. Using this information, the bug can be identified in the for loop that controls how many cards the current player draws.
 Bug is in line - Line 1344 (playCouncil_Room function), where the for loop condition should be i < 4 instead of i < 8
 Steps to produce/reproduce - Run "make cardtest4", then call cardtest4 executable. View test results.
 Expected Results - All 4 testcases pass
 Actual Results - Failures as described in description
 Reproduceable - Yes
 Severity - High
 Priority - High






*/