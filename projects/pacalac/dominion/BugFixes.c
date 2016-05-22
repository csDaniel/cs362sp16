Bugs fixed:

playAdventurer:
Based on the bugs found by my teammates, I fixed the following:
	* I added a call to discardCard to correctly discard the Adventurer card after being played. This also required adding
		a handPos argument to the function
Based on my own bugs I found:
	* The while loop that was set to discard drawn cards was failing to discard the last card. Replaced while(z - 1 > 0)
		with while(z - 1 >= 0).
	
playSmithy:
Based on the bugs found by my teammates, I fixed the following:
	* I added a call to discardCard to correctly discard the Smithy card after being played

	
playCouncil:
Based on the bugs found by my teammates, I fixed the following:
	* Increment the numBuys for the current round after playing the card (didn't increment before)
	* Added a check for currentPlayer in the for loop that draws cards for other players. The player was incorrectly getting
		a card.
		
playSteward:
Based on bugs I found:
	* coins weren't updating correctly, only one coing was being added.
	* if third choice selected, cards were not being discarded from hand (no calls to discard card and no arguments passed
		for the two cards to discard).
		
		
Results:
	This appeared to fix all of the bugs I caught with my tests and (hopefully) all of the tests my group members caught.
	Code coverage was similar to previous tests with the slight differences possibly being caused by the increased number
		of calls to other functions (like discardCard) and a few added lines of code as a result of my bug fixes.