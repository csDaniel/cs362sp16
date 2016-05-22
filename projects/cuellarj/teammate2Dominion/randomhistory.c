/***************
Author: James Taylor
Date: 10/25/15
Updated: 4/10/16

***************/


randomadventurer.c :
	My random tester for this card attempts to randomize the hands available and subsequently drawn for particular player. I ensure at least one adventurer card is added to a players deck
	and then add a random number of additional cards up to 10. I chose 10 as it seems to create typical use cases during the normal course of a game. I then end the turn of the player multiple times to attempt to force
	randomly needed shuffles of the players deck. I then had my tester draw hands and test them for the availablity of an adventurer card. If one was present, it saves the game state and notes the current number of 
	treasure cards. My tester calls adventurer_ref and then counts the treasure cards currently in the players hands. A passed test indicates that a correct number of two additional treasure cards were added to the players
	hand. 
	I utilized the techniques from the lecture of taking smaller pieces of the main code and using them to creat my oracle for testing the function. In this case I used a similar version of the code for counting treasure cards
	and used that to validate the function and its results. I left the drawing of an adventure card random so as to not accidentally influence the result of my test. If an adventure card is not drawn, it discards the current gamestate/hand
	and starts again. 
	
	My current tester found no issues with the adventurer_ref() correctly detecting the additional treasure cards needed to satisfy the requirements of the card, stopping the drawing of additional cards and returning to the calling
	function.
	
	Futher Development Opportunities: To round out the testing of this function two additional pieces could be useful. Adding validation of the discard pile would determine if treasure cards were being incorrectly discarded and that
	non-treasure cards are correctly being discarded. Lastly, adding validation of the entire gamestate would potentially identify incorrect calls to shuffle (my introduced bug) and validate various card/deck/supply counts to make
	sure they are properly updated and the function is called. 
	

		