/***************************************
Ellard Gerritsen van der Hoop
BugInTeammates.c


******************************************/


/*******************************Teammate 1: Shawn Seibert**********************************************/

Bug Report 1:


Title: Incorrect number of cards drawn for Smithy
Product: dominion.c
Classification: Serious bug that alters game

Description: During testing, the players hand count was off 
			when playing the smithy card. 

Reproduction: This bug can be reproduced each time 


Steps:
		1.) Initialize deck
		2.) Play smithy card
		3.) Player draws 4 cards instead of 3 
		4.) No further actions
		
Steps to Reproduce: Play the smithy card and compare test State versus game State for hand count 
Actual Results: 4 cards drawn by player
Expected Results: 3 card drawn by player


Relevant Test Snippet:

AFTER CARD EFFECT- Smithy
Number of Cards Drawn: 8    Expected: 7
ERROR: Hand Count is off for Player 1


////////////////////////////////////////

Bug Report 2:

Title: Incorrect number of cards drawn for Adventurer
Product: dominion.c
Classification: Serious bug that alters game

Description: During testing, the amount of cards in the players hands
			was drastically off from the expected result when playing 
			the adventurer card. 

Reproduction: This bug can be reproduced each time 


Steps:
		1.) Initialize deck
		2.) Play Adventurer card
		3.) Player draws cards until 2 drawn treasures are reached
		4.) No further actions
		
Steps to Reproduce: Play the adventurer card and compare test State versus game State for hand count 
Actual Results: -196 Cards in hand for Player 1
Expected Results: 6 Cards in hand for Player 1


Relevant Test Snippet:

AFTER CARD EFFECT- Adventurer
Cards in hand: -196               Expected:6
ERROR: hand Count is off for Player 1

////////////////////////////////////////////
Bug Report 3:   

Title: Incorrect Number of Cards drawn for Council Card
Product: dominion.c
Classification: Serious bug that alters game

Description: During testing, I found that upon playing the council card,
			the number of cards in the current players hands exceeded the amount
			it should have been.

Reproduction: This bug can be reproduced each time 


Steps:
		1.) Initialize deck
		2.) Play Council card
		3.) Player draws cards 
		4.) Player receives a buy 
		5.) No futher actions

Steps to Reproduce: Play the council card and compare test State versus game State for hand count 
Actual Results: 9 Cards in hand for Player 1
Expected Results: 8 Cards in hand for Player 1


Relevant Test Snippet:

AFTER CARD EFFECT- Council Room 
Cards in hand: 9               Expected:8
ERROR: hand Count is off for Player 1







/*******************************Teammate 2: Suyana Lozada**********************************************/

Bug Report 1:


Title: Incorrect number of cards drawn for Smithy
Product: dominion.c
Classification: Serious bug that alters game

Description: During testing, I found that the smithy card resulted in an 
			incorrect number of cards to be added to players hand 

Reproduction: This bug can be reproduced each time 


Steps:
		1.) Initialize deck
		2.) Play smithy card
		3.) Player draws 2 cards instead of 3 
		4.) No further actions
		
Steps to Reproduce: Play the smithy card and compare test State versus game State for hand count 
Actual Results: 6 cards drawn by player
Expected Results: 7 card drawn by player


Relevant Test Snippet:

AFTER CARD EFFECT- Smithy
Number of Cards Drawn: 6   Expected: 7
ERROR: Hand Count is off for Player 1

///////////////////////////////////////////

Bug Report 2:

Title: Incorrect number of cards drawn for Adventurer
Product: dominion.c
Classification: Serious bug that alters game

Description: During testing, I found that the adventurer card is adding to many cards to 
			the hand for the current player. 

Reproduction: This bug can be reproduced each time 


Steps:
		1.) Initialize deck
		2.) Play Adventurer card
		3.) Player draws cards until 2 drawn treasures are reached
		4.) No further actions
		
Steps to Reproduce: Play the adventurer card and compare test State versus game State for hand count 
Actual Results: 8 Cards in hand for Player 1
Expected Results: 6 Cards in hand for Player 1


Relevant Test Snippet:

AFTER CARD EFFECT- Adventurer
Cards in hand: 8              Expected:6
ERROR: hand Count is off for Player 1

///////////////////////////////////////////////////

Bug Report 3:

Title: Incorrect number of copper cards in hand for Player and Opponent after Cutpurse
Product: dominion.c
Classification: Serious bug that alters game

Description: During testing, I found that a copper card is not being added to the players hand upon use
			of cutpurse card. I also found that the opponent is not losing one of their copper cards

Reproduction: This bug can be reproduced each time 


Steps:
		1.) Initialize deck
		2.) Play Cutpurse card
		3.) Player receives a copper card
		4.) No further actions
		
Steps to Reproduce: Play the cutpurse card and compare test State versus game State for hand count 
Actual Results: 3 Copper Cards in hand for Player 1                4 Copper Cards in hand for Player 2 
Expected Results: 4 Copper Cards in hand for Player 1				5 Copper Cards in hand for Player2


Relevant Test Snippet:

AFTER CARD EFFECT- Cutpurse
Number of Copper Cards: 3		Expected: 4
ERROR: Copper Card Count is off for Player 1
	
Number of Copper Cards: 5		Expected: 4
EROR: Copper Card Count is off for Player 2 




	

