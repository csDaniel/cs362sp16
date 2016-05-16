/********************************
Name: Shawn Seibert
Date: 05/16/2016
File: BugsInTeammates.c
*********************************/

/************************************
Teammate 1: Ellard
*************************************/
Bug Report 1:
Title: Incorrect amount of cards drawn when Smithy is played
Product: dominion.c
Classification: Serious bug that alters the outcome of the game
Platform: Windows 10, putty (beta 0.67)
Can it be reproduced: This can be reproduced every time.
Description:  When the smithy card is played, I found that only two cards are drawn when it should be three.
What happened:
1)	Play smithy card
2)	1st card is drawn by the player
3)	2nd Card is drawn by the player
4)	No further cards are drawn
What’s the error: There is no error associated with this bug.
Supporting Information: When running my card tests on the smithy card, my tests showed that each iteration of a card being drawn. The final result of this card test is set to three cards drawn. When I compare the actual number of cards drawn by the final result, the test fails.
Step to reproduce: Run the smithy card and compare the number of cards drawn.
Expected Results: 3 Cards drawn by the player
Actual Results: 2 Cards drawn by the player.
Work around: There is no work around that I have found.
Attachements: Below is a snippet of my card test.
 
 Smithy:
Start Test:
Drawing card: 1 
Drawing Card from Draw Card() 
Drawing card: 2 
Drawing Card from Draw Card()
End Test: 
Test Failed: LoopCount = 2  |   Draw total should be: 3


Bug Report 2:
Title: Adventure Card does not draw the correct number of treasures
Product: dominion.c
Classification: Serious bug that alters the outcome of the game
Platform: Windows 10, putty (beta 0.67)
Can it be reproduced: This can be reproduced every time.
 Description:  When the adventure card is played, and a silver card is drawn, it does not count as a treasure.
What happened:
1)	Play adventure card
2)	Player draws a copper card
3)	The players treasure amount goes up by one
4)	Player draws a silver card
5)	The players treasure amount goes up by two
6)	Player stops drawing when another gold or copper card draw or repeat step 4 if another silver card is drawn.
What’s the error: There is no error associated with this bug.
Supporting Information: When running my card tests on the adventure card, my tests shows that when either a gold or copper card is drawn twice, the card works correctly. However, when a silver card is drawn, an additional treasure card can be drawn. My card test prompts the user if a treasure card is drawn but does not account for an increment in number of treasures drawn.
Step to reproduce: Run the adventure card until a silver card is drawn. Check your treasure card amount 
Expected Results: When a player draws 2 copper, silver, or gold (in any combination), then that is the amount of treasure cards they receive.
Actual Results: When a player draws a silver card they draw an additional treasure card.
Work around: There is no work around that I have found.
Attachements: Below is a snippet of my card test.

Adventure Card:
Test Passed: Card Drawn is top card. 
COPPER 4 | SILVER 5 | GOLD 6  
Test Passed: Draw Treasure: 4 
Test Passed: Card Drawn is top card. 
COPPER 4 | SILVER 5 | GOLD 6  
Test Failed: Draw Treasure: 5



/************************************
Teammate 2: Suyana
*************************************/
Bug Report 1:
Title: Incorrect amount of cards drawn when Smithy is played
Product: dominion.c
Classification: Serious bug that alters the outcome of the game
Platform: Windows 10, putty (beta 0.67)
Can it be reproduced: This can be reproduced every time.
 Description:  When the smithy card is played, I found that only two cards are drawn when it should be three.
What happened:
1)	Play smithy card
2)	1st card is drawn by the player
3)	2nd Card is drawn by the player
4)	No further cards are drawn
What’s the error: There is no error associated with this bug.
Supporting Information: When running my card tests on the smithy card, my tests showed that each iteration of a card being drawn. The final result of this card test is set to three cards drawn. When I compare the actual number of cards drawn by the final result, the test fails.
Step to reproduce: Run the smithy card and compare the number of cards drawn.
Expected Results: 3 Cards drawn by the player
Actual Results: 2 Cards drawn by the player.
Work around: There is no work around that I have found.
Attachements: Below is a snippet of my card test.

Start Test:
Drawing card: 1
Drawing card: 2
End Test:
Test Failed: LoopCount = 2  |   Draw total should be: 3








Bug Report 2:
Title: Council Room Card does not draw the correct number of cards
Product: dominion.c
Classification: Serious bug that alters the outcome of the game
Platform: Windows 10, putty (beta 0.67)
Can it be reproduced: This can be reproduced every time.
 Description:  When the council room card is played, four cards should be drawn. However, five cards are drawn by the player
What happened:
1)	Play council room card
2)	Player begins drawing cards
3)	After the fourth card is drawn, an additional card is drawn.
What’s the error: There is no error associated with this bug.
Supporting Information: When running my card tests on the council room card, my tests shows each iteration of a card being drawn. After the test is run, the actual result is compared against the expected results
Step to reproduce: Run the council card with 0 cards in your hand. You will find that the player draws 5 cards instead of 4. 
Expected Results: Player draws 4 cards
Actual Results: Player draws 5 cards
Work around: There is no work around that I have found.
Attachements: Below is a snippet of my card test.

CHECKING CARD DRAW AMOUNT.
Drawing card: 1
Drawing card: 2
Drawing card: 3
Drawing card: 4
Drawing card: 5
Test Failed: LoopCount = 5  |   Draw total should be: 4
CHECK BUY AMOUNT:
Number of buys before: 1
Number of buys after: 2
Test Passed: Buy amount increased by 1
CHECKING DISCARD.
Current player hand count: 5
Current player hand count: 4
Test Passed: Player discarded.
