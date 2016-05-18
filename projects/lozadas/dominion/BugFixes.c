############################################################
#Suyana Lozada
#Assignment #5
#Date: 05/16/2016
#Description: BugFixes.c bug fixed in projects/lozadas/dominion
#############################################################


***Bug Fix 1: Incorrect number of cards drawn for smithy card.***

The incorrect number of cards are drawn for smithy card. Player draws 2 cards
instead of 3. This bug was encored by both of my teammates unit tests.

In order to fix this bug, the for loop utilized to draw cards f was modified. Initially, the loop started at i=1 and ended when i < 3. The for loop was modified to start at i=0.
Incorrect code:
int i=0;
for (i = 1; i < 3; i++)
{
	drawCard(currentPlayer, state);
}
Correct code:
int i=0;
for (i = 0; i < 3; i++)
{
	drawCard(currentPlayer, state);
}

The unit test cardtest1.c was run to verify that smithy card has the correct effect. 

Testing smithy()
Test 1: player 0 draws the correct number of cards (3 cards)
PASS: test = 7, expected = 7
Test 2: correct number of cards in player 0 deck (1 card discarted)
PASS: test = 2, expected = 2
Test 3: player 0 draws cards from the correct pile
PASS: test = 2, expected = 2
Test 4: player 1 deck remains unchanged
PASS: test = 10, expected = 10


***Bug Fix 2: AdventurerCard function does not count gold as a treasury card.***

The refactored AdventurerCard does not count gold card as a treasury card. This caused the 
player to obtain more than 2 treasury cards.

Incorrect code:
if (cardDrawn == copper || cardDrawn == silver)
	drawntreasure++;
Correct code: 
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;

The unit test cardtest2.c was run to verify that adventurer card has the correct effect. 

Test 1: player draws two treasury cards from deck
PASS: test = 6, expected = 6
Test 2: determine if deck count is decreased by at least 2 cards
PASS: test = 7 <= expected = 302
Test 3: determine if other players hands remain unchanged.
PASS: test = 143 , expected = 143


***Bug Fix 3: Adventurer card functions continue two draw cards after two treasure cards are drawn by
the player**

The refactored AdventurerCard carries a while loop to draw treasury cards until draw treasure <= 2

Incorrect code:
 while(drawntreasure<=2)
Correct code: 
 while(drawntreasure<2)

The unit test cardtest1.c was run to verify that adventurer card has the correct effect. 

Test 1: player draws two treasury cards from deck
PASS: test = 6, expected = 6
Test 2: determine if deck count is decreased by at least 2 cards
PASS: test = 7 <= expected = 302
Test 3: determine if other players hands remain unchanged.
PASS: test = 143 , expected = 143


***Bug fix 4: Incorrect number of copper cards in hand for player and opponent for cutpurse card.***

The cutpurse cards causes the current player to discard a copper card or reveal a hand with no copper. 
My teammate was able to identify this bug I introduced during one of the previous assignments.

incorrect code:
if (i == currentPlayer)

correct code:
if (i != currentPlayer)

The unit test cardtest4.c was run to verify that smithy card has the correct effect. 

Testing cutpurseCard()
Test 1: player 0 update coins by 2
PASS: test = 4, expected = 4
Test 2:Each other player in the game discards a copper card from hand
PASS: test = 0, expected = 0

*** Bug fix 5: Council Room Card does not draw the correct number of cards.****
When the council room card is played, four cards should be drawn. However, five cards are drawn by the player. In order to correct this bug, the for loop that draws cards from the deck was modified to draw just four cards from the deck.

Incorrect code:
int i=0;
for (i = 0; i <= 4; i++)
{
       drawCard(currentPlayer, state);
}

Correct code:
int i=0;
for (i = 0; i < 4; i++)
{
       drawCard(currentPlayer, state);
}


The unit test cardtest1.c was run to verify that council_card card has the correct effect. 
Testing council_room ()
Test 1: player 0 draws 4 cards from deck
PASS: test = 8, expected = 8
Test 2: 1 buy is added to the state of the game
PASS: test = 2, expected = 2
Test 3:Each other player in the game draws one card
PASS: test = 1, expected = 1

