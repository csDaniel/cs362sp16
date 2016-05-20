/*

 Brandon Swanson
 Assignment 5  CS - 362

 crawleya Bug #3  and  sakamosa bug# 1
 ---------------------------------------

 I first addressed the smithy bug that caused it to:
 - draw 4 cards instead of 3
 - not discard the smithy card (and in fact discard a different players card)
 This bug was filed by both of my teammates.

 After correcting the off-by-one error in the draw loop and the transposed
 discardCard parameters that I introduced I recompiled and ran the card tests
 for the smithy card function and ensured that the failed tests were now
 passing.
 I also used GDB and set a break point on entering and exiting the playSmithy()
 function and output the game state before and after the function ran. here is
 a sample output of this debugging process

(gdb) b playSmithy
Breakpoint 1 at 0x406f23: file dominion.c, line 1260.
(gdb) b dominion.c:1273
Breakpoint 2 at 0x406fab: file dominion.c, line 1273.
(gdb) run
Starting program: /home/brandon/SOFTWAREII/cs362sp16/projects/swansonb/dominion/cardtest1.out
--------------------------------------------------------------
--------------------------------------------------------------
Testing dominion.c int playSmithy()
--------------------------------------------------------------
--------------------------------------------------------------
Playing smithy card player: 0  testRound: 0

Breakpoint 1, playSmithy (state=0x7ffffffea9e0, handPos=0) at dominion.c:1260
1260	    const int CARDS_TO_DRAW = 3;
(gdb) p *state
$1 = {numPlayers = 4, supplyCount = {30, 12, 12, 12, 32, 40, 30, 10, 10, -1,
    -1, 10, -1, 10, 10, -1, -1, 10, -1, 10, -1, 10, 10, -1, -1, 10, -1},
  embargoTokens = {0 <repeats 27 times>}, outpostPlayed = 0, outpostTurn = 0,
  whoseTurn = 0, phase = 0, numActions = 1, coins = 4, numBuys = 1, hand = {{
      13, 4, 1, 4, 4, 0 <repeats 495 times>}, {0 <repeats 500 times>}, {
      0 <repeats 500 times>}, {0 <repeats 500 times>}}, handCount = {5, 0, 0,
    0}, deck = {{1, 1, 4, 4, 4, 12, 6, 14, 24, 9, 22, 17, 22, 15, 9,
      0 <repeats 485 times>}, {4, 4, 1, 4, 4, 4, 4, 1, 1, 4, 25, 8, 18, 3, 8,
      0 <repeats 485 times>}, {1, 1, 4, 4, 4, 4, 4, 4, 4, 1, 3, 21, 25, 23, 7,
      0 <repeats 485 times>}, {1, 4, 4, 4, 4, 4, 1, 1, 4, 4, 1, 23, 13, 22,
      20, 0 <repeats 485 times>}}, deckCount = {15, 15, 15, 15}, discard = {{
      0 <repeats 500 times>}, {0 <repeats 500 times>}, {
      0 <repeats 500 times>}, {0 <repeats 500 times>}}, discardCount = {0, 0,
    0, 0}, playedCards = {0 <repeats 500 times>}, playedCardCount = 0}
(gdb) c
Continuing.

Breakpoint 2, playSmithy (state=0x7ffffffea9e0, handPos=0) at dominion.c:1273
1273	    return 0;
(gdb) p *state
$2 = {numPlayers = 4, supplyCount = {30, 12, 12, 12, 32, 40, 30, 10, 10, -1,
    -1, 10, -1, 10, 10, -1, -1, 10, -1, 10, -1, 10, 10, -1, -1, 10, -1},
  embargoTokens = {0 <repeats 27 times>}, outpostPlayed = 0, outpostTurn = 0,
  whoseTurn = 0, phase = 0, numActions = 1, coins = 4, numBuys = 1, hand = {{
      22, 4, 1, 4, 4, 9, 15, -1, 0 <repeats 492 times>}, {
      0 <repeats 500 times>}, {0 <repeats 500 times>}, {
      0 <repeats 500 times>}}, handCount = {7, 0, 0, 0}, deck = {{1, 1, 4, 4,
      4, 12, 6, 14, 24, 9, 22, 17, 22, 15, 9, 0 <repeats 485 times>}, {4, 4,
      1, 4, 4, 4, 4, 1, 1, 4, 25, 8, 18, 3, 8, 0 <repeats 485 times>}, {1, 1,
      4, 4, 4, 4, 4, 4, 4, 1, 3, 21, 25, 23, 7, 0 <repeats 485 times>}, {1, 4,
      4, 4, 4, 4, 1, 1, 4, 4, 1, 23, 13, 22, 20, 0 <repeats 485 times>}},
  deckCount = {12, 15, 15, 15}, discard = {{0 <repeats 500 times>}, {
      0 <repeats 500 times>}, {0 <repeats 500 times>}, {
      0 <repeats 500 times>}}, discardCount = {0, 0, 0, 0}, playedCards = {13,
    0 <repeats 499 times>}, playedCardCount = 1}
(gdb)

here we can see that the player was player 0,  and after playSmithy has been
called the players hand has 3 new cards and the smithy card has been placed
in the playedCard pile.



 crawleya Bug #4
 -------------------------
 This bug was due to the bug i introduced where the playVillage function was
 accepting a struct instead of a pointer to a struct, therefore changes were
 not persisting in global game state.  I updated the function signature and
 all calls to it (including the card test) to accept a pointer to the game
 state.
 Afterwards the card tests now pass,  the function is correctly making the
 changes to the game state defined by the game rules and not making any other
 inadvertent changes.


 sakamosa Bug #2
 -------------------------
 To investigate this bug I wrote a unit test that could check the behavior
 described in that bug.  unitTest5.c I replicated the steps described in the
 bug and initialized a game with 2 players.  the bug was not specific about
 if the players had a mismatch of cards in their deck or total so i wrote
 a test that would output the size and contents of each players deck,hand and
 discard piles.

 This is the output of that unit test:
Game is initialized
player 0 has 5 cards in their deck: {1,4,4,4,4,}
player 0 has 5 cards in their hand: {4,4,1,1,4,}
player 0 has 0 cards in their discard: {}
total cards for player 0: 10
----------------------------------------------
player 1 has 10 cards in their deck: {4,1,1,4,4,4,4,4,1,4,}
player 1 has 0 cards in their hand: {}
player 1 has 0 cards in their discard: {}
total cards for player 1: 10

 It appears that there is in fact not a bug, after initializing each players
 deck the function also initializes first players turn and there is a for loop
 that draws 5 cards into the first players hand.



 Fixing Bugs I Introduced
 ------------------------------------------------------

 I corrected the problem I spotted when originally implementing adventurer
 where if the players deck and discard contained 0 coin cards it would loop
 infinitely. I changed the loop conditional for drawing cards from
 while(drawCardsRemaining)
 to
 while(drawCardsRemaining &&
       (state->deckCount[currentPlayer] + state->discardCount[currentPlayer]))
 The function will now stop iterating after the deck and discard pile have
 been exhausted.  I adjusted my random tester for the the adventurer card to
 include test cases with no coin cards in the players deck or discard to
 confirm that the bug had been fixed.


 */