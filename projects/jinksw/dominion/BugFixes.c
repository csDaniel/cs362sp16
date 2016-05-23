Bug Fixes

Bug 1: 
Title: Segmentation Fault (core dump) error due to poor construction of cardEffect
case loop. 
Classification: Severe 
Description: Overall gameplay and testing are effected when any of the refactored code is
played.

Fix: Added break; statements in switch cases for playing refactored cards.
Fixed: Yes.

Bug 2:
Title: Adventurer test fail.  Hand count, card count, discard tests all fail. 
Random test runs into segmentation fault at 17th iteration 
Classification: Severe
Description: The cardDrawn variable has been refactored which causes a nearly complete fail for the 
adventurer card.

Fix:
cardDrawn should be:
	cardDrawn = state->hand[currentPlayer][state->handCount[CurrentPlayer]-1];
	
	instead of:
	cardDrawn = state->hand[currentPlayer][0];
The correct version gets the top card in the hand, the incorrect(2nd) version gets the bottom card in the hand.

Fixed:Yes

Bug 3:
Title: council_room fail: Assertion `p1startHand == p1endHand - 3' failed.
Hand contains +3 cards: Abort (core dumped)
Classification: Severe
Description: Cards drawn fails. Refactored code by author has changed loops that corrupt 
the number of cards drawn for council_room play 

Fix: changed loops to be < instead of <= so that they terminate correctly

Fixed: yes

Bug 4:
Description: Card Draw Sub Test: 3 Drawn, 1 Discarded, Net +2 
Cards to Hand: FAIL, expected Net +2 Cards, Result +0 cards
Classification: Severe
Description: Incorrect number of cards drawn for Smithy gameplay
Author corrputed draw cards and changed internal functions in their playSmithy() function

Fix: changed loops to be < instead of <= so that they terminate correctly

Fixed: yes


BUG 5: smithy is not discarded
LOCATION: playSmithyCard()
SUMMARY: Player's discard pile should be incremented by 1 but is not,
	in fact it appears that many more than 1 card is discarded
 EXPECTED RESULTS: Calling player's discard should be +1
 ACTUAL RESULTS: Calling player's discard is much higher than 1; it appears
		that drawn cards may all be discarded

Fix: Set trashflag to 0 instead of 1. discardCard() is called correctly and if
it still is working incorrectly, then the error must be in the discardCard() function.

Fixed: No, issue with the discardCard() function
