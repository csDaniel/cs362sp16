********************************************************************************
* File:		BugsInTeammates.c
*
* Author:	Jarrad Favre
*
* Date:		5-22-2016
*
* Assignment 5 Part 1: Test Teammates codes
********************************************************************************

Teammate 1:
Upon testing teammate 1's Smithy card with my tests, only one of my test cases 
returned as a failure, which tested for the expected hand count for player 1 and
with the actual count of player 1's hand. The expect hand for player 1 was 7,
but the hand only showed 0 in player 1's hand. The bug that is present obviously
does not draw the three cards it's suppose to, but it doesn't keep the cads it 
had on hand. To exam why this was happening, I took a closer look at my teammate's
code. Upon expectation of her code, I found that there is an if condition that 
encased around the for loop that draws the 3 cards required. This condition will
let the for loop work only if the next player is greater than the number of 
players. Since this can never happen, the for loop will never be called, thus
Smithy will never draw the 3 required cards

For teammate 1's Adventurer card, several of my test cases came back as failures.
It seems that all the treasure cards are being ignored and all cards from the 
deck are being drawn and discarded in a temp hand. Examining the code, this
seems to be the case, as the while loop that draws cards continues until
the hand is less than 0.


Teammate 2:
For teammate 2's Smithy card, only one of my test cases came back as a failure.
Player 1's hand is expected to have 7 cards, but it shows an actual hand of 6.
Upon examination of teammate 1's code, I found the minor bug in the for loop 
that is to draw the 3 cards. In the initialization of i for the loop, 1 is
assigned. This would be fine if it were to loop until i was less than 4 or equal
to 3. However, the loop ends when i is less than 3, which means that only 2 
cards are only be drawn.

Upon my tests for teammate 2's Adverturer card, none of my test cases returned
a failure. To make sure that the code is indeed free of bugs, I examined the 
code to find potential bugs. I quickly found that there was a bug in the code:
The while loop that draws cards till 2 treasure cards are found continues until
3 are found. As none of my test cases test for this, it explains why my tests
came back showing zero failures. 

