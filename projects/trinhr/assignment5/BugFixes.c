
My first teammate Dave Martinez was only able to find one bug which coincided
with my second teammated Lauren Miller's bug report. In the adventurer function
the adventurer card was not being discarded. This was not a bug I input, but a 
bug within the program to begin with. 

Dave was able to pinpoint the correct source of error, but his report
was lacking information and context. I understood what the card count info
meant but there was no context given for what "last played card" meant. 
Did it mean the position of the adventurer card in the hand or the last
card of the deck/hand? I would like a little more information for next time
as to what the variables meant. I also had to assume that the effect happened
all the time. I would like the frequency and conditions to recreate the error.
I did like that he included the fact that discard worked in other functions and that 
the other drawn non-treasure cards were discarded. This helped me to
narrow down the problem.

Lauren was able to catch the mistake that I had placed in the adventurer which
resulted in only one treasure card being placed in the hand or none. I had
changed it so the drawnTreasure variable would increment even if the card 
drawn wasn't a treasure. Her bug report was nice and informative. It had a
lot of detail which let me know that this bug was important to fix. 
The other bug she reported was one that I did not place in which actually
required me to debug it. I think I was able to pinpoint it and was a problem
for the other cards. In the switch statement, I did not have some of the functions
returning any values, instead I just had a break statement so this probably caused
the error with cardEffect getting a -1.

/* BUG REPORT FROM DAVE MARTINEZ

CARD TEST 4: Adventurer
TEST 4: Does adventurer card go to played pile?
Player 0's played card count = 0, expected 1
Player 0's last played card = 0, expected 7

LOCATION
dominion.c:662 adventurerCard() 

EXPECTATION
Test expects the last card to be adventurer card, but is not.

POSSIBLE CAUSE
It appears each card in the temp hand is being discaded on lines
dominion.c:864 - 690. However, no mention of the adventurerCard
being of the discarded is included in this function. This could
be due to a problem of specifications: is it the responsibility 
of the adventurerCard() to discard itself, or main()? 

Other cards do discard themselves, see dominion.c:696 
villageCard()

*/
/*
BUG REPORT FROM 
Name: Lauren Miller
Date: May 19, 2016

Bug Number: 1
Bug Title: Adventurer Card Remaining in Hand After Play, Missing Treasure Cards After Play
Severity: Moderate
Function Tested: AdventurerCard, CardEffect
Description: After using CardEffect to play Adventurer, there is either no treaasure 
card at the end of the active player's deck or there is no treasure card as the second to 
last card in the active player's deck. If there is no treasure card in the last position of 
the player's hand, there is one in the second to last position. Likewise, if there is no 
treasure card in the second to last position in the player's hand, there is one in the last
position. In both cases, where there is a missing treasure card, there is an Adventurer card. 
This might indicate that the Adventurer is not discarded. This is true even if there are 
available cards and available treasure cards. This is true for every test run, at least where 
there are sufficient treasure cards. 

Expected Results: If there are available treasure cards,
after playing Adventurer, there should be a net of 1 card added to the hand of the active 
player, 2 treasure cards previously in their deck or discard pile, and 1 card discarded, 
the Adventurer. gameState.handCount should be 1 and both gameState.hand[currentPlayer][game.handCount[currentPlayer]-1] 
gameState.hand[currentPlayer][game.handCount[currentPlayer]-2] should be gold, silver, or copper.

Actual Results: There are two possible types of outcome that seem mutually exclusive. 
There will either be  a net of 0 cards added to the hand of the active player, the last 
card in hand will be an Adventurer, and the second to last card in hand will be one of the 
treasure cards OR there will be a net of 1 card added to the hand of the active player, 
there will be a treasure card as the second to last card in the player's hand, and the 
last card will be an Adventurer. Here samples of the types of errors generated from my random tests:

ERROR IN MISSING TREASURE CARD AT END OF HAND: test: 0, player: 0, 
game.deckCount previously: 407, game.discardCount previously: 137, 
treasure in game.deckCount and game.discardCount: 58, CARD enum: 7, net game.handCount: 0

ERROR IN MISSING TREASURE CARD AT END OF HAND - 1: test: 19, player: 0, 
game.deckCount previously: 180, game.discardCount previously: 353, 
treasure in game.deckCount and game.discardCount: 57, CARD enum: 7, net game.handCount: 1

Bug Number: 2
Bug Title: AdventurerCard Returns -1
Severity: Minor
Function Tested: AdventurerCard, CardEffect
Description: In every test case, using CardEffect to play Adventurer returns -1 
when a return value of 0 is expected.
Expected Results: Calling 
playCard(gameState.handCount[currentPlayer] - 1, -1, -1, -1, &gameState)
 when the last card in hand is an Adventurer should return 0.
Actual Results: Calling playCard(gameState.handCount[currentPlayer] - 1, -1, -1, -1, &gameState) 
when the last card in hand is an Adventurer returns -1.
*/