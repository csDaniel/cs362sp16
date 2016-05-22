/* 
Charles Siebert
Assignment 5
BugsInTeammates.c

Description: Uses my previously made tests to test my teammates code wherein
they created some bugs in their code. My tests should reveal the bugs that they
had introduced.

This file includes test results of the code, and an analysis of what the bug is.

------------------------------------------
Teammate 1 (batese)
./siebertc/bateseDominion/
------------------------------------------

cardtest1.c:

----------------- START TESTING: Smithy ----------------
cardSmithy TEST#1: PASS smithy executes without errors.
cardSmithy TEST#2: FAIL Expected HandSize: 5 - Result 2
cardSmithy TEST#3: PASS Expected PlayedCount: 1 - Result 1
----------------- END TESTING: Smithy ----------------

Handsize is not proper, seemingly it looks like that the card is played, and then
discarded, but it shows that no cards were actually drawn into the player's hand.

cardtest2.c:

----------------- START TESTING: Village ----------------
cardVillage TEST#1: PASS village executes without errors.
cardVillage TEST#2: FAIL Expected numActions: 2 - result: 1
cardVillage TEST#3: PASS Expected CardHand: 3 - result: 3
cardVillage TEST#4: PASS Cards Played: 1 - result: 1
cardVillage TEST#5: PASS Cards discarded: 1 - result: 1
----------------- END TESTING: Village ----------------

The bug found in this test was that the numActions weren't updated properly, it shows
that only one numAction was added to the current player, instead of the expected 2.

cardtest4.c:

----------------- START TESTING: Council Room ----------------
cardCouncilRoom TEST#1: PASS Council Room executes without errors.
cardCouncilRoom TEST#2: PASS Council Room - Expected Buys: 1 - Result: 1
cardCouncilRoom TEST#3: PASS Council Room - Expected PlayedCount: 1 - Result: 1
cardCouncilRoom TEST#4: FAIL Council Room - Expected Player#2 Cards in Hand: 2 - Result: 1
cardCouncilRoom TEST#5: PASS Council Room - Expected Player#1 Cards in Hand: 4 - Result: 4
----------------- END TESTING: Council Room ----------------

The bug found in this test is that a card was not given to all other players, as the card states

------------------------------------------
Teammate 2 (pattejon)
./siebertc/pattejonDominion/
------------------------------------------

cardtest1.c:

----------------- START TESTING: Smithy ----------------
cardSmithy TEST#1: PASS smithy executes without errors.
cardSmithy TEST#2: FAIL Expected HandSize: 5 - Result 6
cardSmithy TEST#3: PASS Expected PlayedCount: 1 - Result 1
----------------- END TESTING: Smithy ----------------

There is a one-off error with drawing a card. The function seems to be drawing one extra card
for the current player than they are supposed to.

cardtest2.c:

----------------- START TESTING: Village ----------------
cardVillage TEST#1: PASS village executes without errors.
cardVillage TEST#2: PASS Expected numActions: 2 - result: 2
cardVillage TEST#3: PASS Expected CardHand: 3 - result: 3
cardVillage TEST#4: PASS Cards Played: 1 - result: 1
cardVillage TEST#5: FAIL Cards discarded: 1 - result: 2
----------------- END TESTING: Village ----------------

This card ended up discarding more than one card when the card is played. In the implementation,
the cardEffect ends up discarding an extra card, as well as in the function refactoring.

cardtest4.c:

----------------- START TESTING: Council Room ----------------
cardCouncilRoom TEST#1: PASS Council Room executes without errors.
cardCouncilRoom TEST#2: PASS Council Room - Expected Buys: 1 - Result: 1
cardCouncilRoom TEST#3: FAIL Council Room - Expected PlayedCount: 1 - Result: 0
cardCouncilRoom TEST#4: FAIL Council Room - Expected Player#2 Cards in Hand: 2 - Result: 1
cardCouncilRoom TEST#5: PASS Council Room - Expected Player#1 Cards in Hand: 4 - Result: 4
----------------- END TESTING: Council Room ----------------

Bug encountered is that the player was didn't add PlayedCount correctly. Other player wasn't
allowed to draw a card into their hand. I suspect PlayedCount didn't update properly due to
different implementation of the card and their state.

*/