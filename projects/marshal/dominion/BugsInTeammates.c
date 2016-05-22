/**
Alex Marsh
CS362 Assignment 5


Bugs For Teammate1: Christina Nock

Bug#1
Title: Played Smithy Card gives player’s hand extra two cards

Severity: High
Priority: High

Assigned to: Christina Nock
Reported By: Alex Marsh

Reported on: 5/18/16
Status: Active

Environment: Flip Server (flip3.engr.oregonstate.edu) / Linux

Description:
	The intent of a played smithy card should result in a players hand gaining two cards.  The player picks three cards and discards the smithy card, leaving their hand to only increase by two. In my test, after the player implements the Smithy card their hand count should be a total of 7.  Instead the actual return was a count of 9. 
	This error occurs on line 1264:
	“for (i=0; i<=4; i++)” should be changed to “for (i=0; i<4; i++)”

Steps to reproduce:
1.) Navigate to 
	https://github.com/aburasali/cs362sp/tree/master/projects/marshal/NockC_Dominion

2.) Run below commands in current directory
$make clean
$make cardtest1
$./cardtest1
3.) Review Test Results


Bug#2
Title: Played Adventure Card gives player’s hand wrong count of treasure cards

Severity: High
Priority: High

Assigned to: Christina Nock
Reported By: Alex Marsh

Reported on: 5/18/16
Status: Active

Environment: Flip Server (flip3.engr.oregonstate.edu) / Linux
Description:
	When played the adventure card allows the player to draw cards until two Treasure cards are found.  Those treasure cards are then placed in the player’s hand and the drawn cards are discarded.  The error occurs in the count of treasure cards in the player’s hand. The player should have two cards then discount the played adventure card resulting in the player’s hand being increased by only one card. Here the error is the incorrect count of treasure cards.  The expected result is a count being increased by two.   Instead of the actual count of only 1. 
	This error occurs on line 1236:
	drawntreasure is set to 1.  Instead it should be initialized to 0. 


Steps to reproduce:
1.) Navigate to 
	https://github.com/aburasali/cs362sp/tree/master/projects/marshal/NockC_Dominion

2.) Run below commands in current directory
$make clean
$make cardtest2
$./cardtest2
3.) Review Test Results

__________________________________________________________________________________

Bugs For Teammate2: Tatsiana Clifton

Bug#1
Title: Played Smithy Card gives player’s hand extra card

Severity: High
Priority: High

Assigned to: Tatsiana Clifton
Reported By: Alex Marsh

Reported on: 5/18/16
Status: Active
Environment: Flip Server (flip3.engr.oregonstate.edu) / Linux

Description:
	The intent of a played smithy card should result in a players hand gaining two cards.  The player picks three cards and discards the smithy card, leaving their hand to only increase by two. In my test, after the player implements the Smithy card their hand count should be a total of 7.  Instead the actual return was a count of 8. This error occurs in the for loop on line 43. 
The code:
	for(i=0; i<=3; i++)
should be changed to
	for(i=0; i<3; i++)


Steps to reproduce:
1.) Navigate to 
	https://github.com/aburasali/cs362sp/tree/master/projects/marshal/CliftonT_Dominion

2.) Run below commands in current directory
$make clean
$make cardtest1
$./cardtest1
3.) Review Test Results


Bug#2
Title: scoreFor() returns an incorrect score of deck 

Severity: High
Priority: High

Assigned to: Tatsiana Clifton
Reported By: Alex Marsh

Reported on: 5/18/16
Status: Active

Environment: Flip Server (flip3.engr.oregonstate.edu) / Linux

Description:
	The scoreFor function is intended to count the number of estate cards in the deck, discard pile, and hand.  The score is added according to the type of estate card. 
This error occurs when calling the scoreFor function. The deck score is always returned as 0 despite the input. The error occurs in the 3rd for loop (line 577) in the scoreFor function.  The code:
	  for (i = 0; i < state->discardCount[player]; i++)
should be changed to
	  for (i = 0; i < state->deckCount[player]; i++)


Steps to reproduce:
1.) Navigate to 
	https://github.com/aburasali/cs362sp/tree/master/projects/marshal/CliftonT_Dominion

2.) Run below commands in current directory
$make clean 
$make unittest1
$./unittest1
3.) Review Test Results



**/