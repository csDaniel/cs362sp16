/*BugFixes.c

Bugs Found by Teammates:

Emily Snyder

Bug 1: Adventurer
When the treasure card is either silver or gold, the correct cards are not 
removed from the hand, discarded or played:
  Input: one silver or gold card anywhere in the deck or an entire deck full of 
         either silver or gold cards.
  Results:
    -  Hand after is -1 (instead of previous hand + number of treasure cards)
    -  Discard pile now includes all of the deck cards, all of the hand cards 
       and 1 additional card
    -  No treasure cards are found in the hand after playing the adventurer card 
       although there should be.

Bug 2: Adventurer
When the deck has no treasure cards, the number of cards in the hand, the discard 
pile and the played card pile are not correct.
  Input: deck full of cards that are not treasure cards
  Results:
    -  Two cards removed from the hand (none should be removed) and moved to the 
       discard pile.
    -  Entire deck moved to the played card pile (none should be there)
    -  3 treasure cards in the hand after the play, when no treasure cards 
       should have been found

Jens Bodal

---

## William George (georgew)

*(see actual test for bug documentation)*

1. Bug in discardCard method
2. Bug in Smithy card
3. Bug in Adventurer card
4. Bug in Village card (random tests)

### 1. Unit Test: `shuffle`

All tests passed.

### 2. Unit Test: `getCost`

All tests passed.

### 3. Unit Test: `discardCard`

Some tests failed.

* Testing discard non trash card
  * cardPlayedCount should be 1 but was 0
  * playedCardCount should be 1 but was 0
  * discard card not correctly discarding non trash cards
* Testing discard trash card
  * cardDiscardCount should be 1 but was 0
  * discardCount should be 1 but was 0
  * discard card is not correctly discarding a trash card
* Testing discard hand (not trash)
  * Hand is not correctly discarded, there is a major issue with discarding cards

### 4. Unit Test: `whoseTurn`

All tests passed.

### 5. Card Test: `smithy`

* Wrong number of cards in hand after playing Smithy

### 6. Card Test: `adventurer`

Not all paths were taken at least once. This is likely due to the bugs that were found.

* Adventurer card not being discarded
* Not gaining correct number of treasure cards in some instances

### 7. Card Test: `village`

All tests passed.

### 8. Card Test: `great_hall`

All tests passed.

### 9. Random Test: `adventurer`

* Adventurer card was not discarded
* Segmentation fault occurred.  Likely an infinite loop or some other issue with previously described bug.

### 10. Random Test: `village`

* The village card was not discarded correctly in some of the tests.  This could be an issue with the discard
function or an issue with the random test itself.

My Bugs Introduced:
Adventurer:
	Can only draw copper cards

Smithy:
	Only draws two cards instead of 3

Great_Hall:
	No Bugs

Steward:
	Both choices are the same, so no reaction to choice 2

Council_Room
	Make it so each player doesn't get a card. Player zero is left out.
	
Bugs Fixed:
Adventurer:
	The first bug that Emily found and I introduced in Adventurer would have prevented the player from choosing any gold or silver 
	cards as such the player will not gain the correct number of treasure cards in some instances, especially if only silver or gold cards
	are in the deck. This could have also caused the error in Jen's tests with the segmentation fault and infinite loop as two drawn cards may not
	be selected.

Discard Card:
	Jens and Emily both mention an issue with the discard card function as some of the cards are not discarded properly in some tests. In looking at the tests and the 
	results I cannot find the bug/bugs that are causing this issue. I feel a new test suite with more coverage would need to be created to find why discardCard is not working
	properly. To update my tests I ran the function against several of the functions in the interface.h domain to see more clearly what was causing the issue. When I did this
	I noticed the printDiscard function does not return anything, but the rest of the functions worked correctly and the correct card was played from the players hand. AS I'm 
	sure you can surmise, this brings me no closer to figuring out the bug.

Smithy:
	Jens also found an issue with smithy not having the correct number of cards. The bug I introduced originally drew 1 card fewer than it was supposed to.
	I adjusted the function so that it now draws the cards correctly.
