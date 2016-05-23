//
// Gunnar Martin
// CS362
// Spring 2016
//
// Assignment 5
// Bugs in Teammates' code
//
// Note: I slightly altered my test files from assignment 4. My new files are called
// `randomtestadventurer_a05.c` and `randomtestcard_a05.c` to avoid confusion.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug report for brewbakl smithy card
// Teammate: brewbakl
// Card: smithy
// File: dominion.c
// Date: 22 MAY 2016
// Desc: 
//
// In order to test brewbakl's smithy card, I used my the random smithy test I had designed.
// I ran 10 random tests and they all failed. Looking at the output of the tests, I noticed
// that every single time, the following pieces of the state were in positions that were incorrect:
//	1) `playedCardCount` was 1 card too high from expected results
//	2) `handCount` was 2 cards too high from expected results
//	3) `deckCount` was was 3 too low from expected results
//
// To further investigate these bugs, I opened `dominion.c` and looked within the `cardEffect` function
// at what the smithy card was doing. I found that the code was actually instructing smithy
// to draw 6 cards (instead of 3) and discarding twice (should only discard once). These two bugs
// were causing the 3 state errors above.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug report for brewbakl adventurer card
// Teammate: brewbakl
// Card: adventurer
// File: dominion.c
// Date: 22 MAY 2016
// Desc: 
//
// In order to test brewbakl's adventurer card, I used my the random adventurer test I had designed.
// I ran 10 random tests and they all succeeded. To be more thorough, I ran 1000 tests and started
// Sorting through the failures to look for patterns. Looking at the output of the tests, I noticed
// a failure that I hadn't seen before for this test. The failure was that the test was showing that
// adventurer would execute a shuffle, even though there was more than 2 treasure cards in the deck.
// I called this issue the "shuffle anomaly".
//	
// To further investigate these bugs, I opened `dominion.c` and looked within the `cardEffect` function
// at what the adventurer card was doing. I found that the adventurer card was only pulling gold and silver
// treasure cards from the deck, but ignoring copper. This is why shuffles were happening even though they
// should not. Since copper was being skipped, the end-of-deck was being reached and then the shuffle would happen.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug report for brownjoh smithy card
// Teammate: brownjoh
// Card: smithy
// File: dominion.c
// Date: 22 MAY 2016
// Desc: 
//
// In order to test brownjoh's smithy card, I used my the random smithy test I had designed.
// I ran 10 random tests and they all failed. Looking at the output of the tests, I noticed
// that every single time, the following piece of the state were in positions that were incorrect:
//	1) `playedCardCount` was 1 card too low from expected results
//
// To further investigate these bugs, I opened `dominion.c` and looked within the `cardEffect` function
// at what the smithy card was doing. I found that the code was actually instructing smithy
// to set the trash flag to 1, which was causing the card to be trashed, when it should have been
// going into the `playedCard` pile. This bug was causing the state error above.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug report for brownjoh adventurer card
// Teammate: brownjoh
// Card: adventurer
// File: dominion.c
// Date: 22 MAY 2016
// Desc: 
//
// In order to test brownjoh's adventurer card, I used my the random adventurer test I had designed.
// I ran 10 random tests and they all failed. Looking at the output of the tests, I noticed
// that every single time, the following piece of the state were in positions that were incorrect:
//	1) `handCount` was 1 card too high from expected results
//
// To further investigate these bugs, I opened `dominion.c` and looked within the `cardEffect` function
// at what the adventurer card was doing. I found that the code was actually instructing adventurer
// to draw 3 treasures cards, instead of 2. This bug was causing the state error above, since too many
// card were being drawn into the hand.
//
//
