/*************************************************
** Reporter: Kayla Vondy
** Filename: bugsFixed.c
** Description: This file describes all bugs fixed
** 		in my files based on reports from my 
** 		teammates and from my own test results
*************************************************/

File changed: dominion.c
Function changed: playSmithy
	Based on test results from my teammates and myself, 
	I removed the bug I placed in this function where I 
	changed a "i<3" to "i<=3". To fix this bug I simply
	deleted the excess equals sign.

Function changed: playAdventurer
	Based on test results from teammates and myself, I 
	re-inserted the call to the drawCard function. This 
	deletiong was the "bug" I made in the beginning of 
	this term.

	Further testing after fixing the only bug I introduced
	revealed that the Adventurer card was not being discarded
	in the original code. This caused the original code to 
	fail my tests. To fix this I added a call to discardCard
	at the end of the playAdventurer function. I also added a 
	line after the drawntreasure variable is incremented to 
	increment the coins for that state. **This fix continues in 
	another file described below**


File changed: cardtest2.c
Function changed: main 
	Following the discovery that the initial code for Adventurer
	was wrong, I changed my testing to reflect the coin amount
	more accurately now that I inserted the line in the function
	which incremented the coin count each time a treasure was drawn.
	Here I used a preCount variable to represent the coin count 
	before the cardEffect function was called and compared it to 
	the amount of coins after the Adventurer card was played. 
	This gave me a more accurate test of coin count and with the 
	discard added to the other file, all my tests (finally) passed.