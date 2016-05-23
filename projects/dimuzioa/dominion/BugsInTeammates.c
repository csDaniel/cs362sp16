/*******************************

smithjoe bug report:

Two bugs found through my cardtests, one in adventurer and one in smithy. My tests found no other excessive bugs in smithjoe's code.

Title: Drawntreasure Only Incremented by One in Adventure Card
Classification: Minor Bug
Can It Be Reproduced?: Every time
Description: According to Dominion game logic, the player should draw cards until two two treasure cards are drawn, but only one is drawn after playing
	the Adventure card. The error produce by my Cardtest1 is "Fail - Player %d has not received the proper amount of cards"
Steps to Reproduce: Call the Adventure card, check to see if handCount was incremented by two after adventurer is discarded.
Expected Results: handCount(via drawnTreasure) should be incremented by two.



Title: Smithy Draws Only Two Additional Cards
Classification: Minor Bug
Can It Be Reproduced?: Every time
Description: According to Dominion game logic, the player should receive three cards after playing a Smithy, but only one two are drawn after
	playing the card. The error produce by my Cardtest2 is "Fail - Player %d has not received 3 new cards."
Steps to Reproduce: Call the Smithy card, check to see if handCount was incremented by three after Smithy is discarded.
Expected Results: handCount(via three newly drawn cards) should be incremented by three.


hardmanj bug report:

For this teammate, I also found two bugs. 

Title: Smithy Adds Four Cards
Classification: Minor Bug
Can It Be Reproduced?: Every time
Description: According to Dominion game logic, the player should receive three cards after playing a Smithy, but four are drawn instead.
	The error produce by my Cardtest2 is "Fail - Player %d has not received 3 new cards."
Steps to Reproduce: Call the Smithy card, check to see if handCount was incremented by three after Smithy is discarded.
Expected Results: handCount(via three newly drawn cards) should be incremented by three.

Title: Adventurer Adds Way Too Many Cards
Classification: Minor Bug
Can It Be Reproduced?: Every time
Description: According to Dominion game logic, the player should draw cards until two two treasure cards are drawn, but this implementation of
	Adventurer has many cards being drawn. The error produce by my Cardtest1 is "Fail - Player %d has not received the proper amount of cards"
Steps to Reproduce: Call the Adventure card, check to see if handCount was incremented by two after adventurer is discarded.
Expected Results: handCount(via drawnTreasure) should be incremented by two.


Since my random tests pinpointed how many passed vs. failed tests occurred based on certain conditions, I mostly utilized my cardTests to produce
this bug report. 

*********************************/


