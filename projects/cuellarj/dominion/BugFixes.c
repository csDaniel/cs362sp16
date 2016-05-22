/*Joseph Cuellar
CS 362 Assignment 5

BUGS: 
	BUG1:
		callAdventurerCard() - cardDrawn condition is wrong & returns the wrong value
	CODE:
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]]
	FIX1:
		Needs to be cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1]

	BUG2:
		callVillageCard() did not call drawCard()
	CODE:
		N/A
	FIX2:
		Add drawCard(currentPlayer, state);

	BUG3:
		callEmbargoCard() was not correctly adding coins to the state
	CODE:
		state->coins = state->coins;
	FIX3:
		state->coins = state->coins + 2;
		
	BUG4:
		callSmithyCard() - for loop gives 6 cards instead of 3
	CODE:
		for (i = 0; i < 6; i++){
	FIX4:
		for (i = 0; i < 3; i++){
			
Notes:
GDB helped quite a bit to find the bugs in my dominion code. It pinpointed the location of each bug,
or at least which function the bug belonged to. One bug was causing a segmentation fault, so it was
very helpful to have a debugger that pointed out the location rather than the usual print statement
debugging I'm used to. That being said, the whole debugging process took less time than it usually 
does, so I will definitely return to GDB again. If I could, I would probably have put bugs in that
were harder to find. GDB made my bugs seem pretty weak.
*/