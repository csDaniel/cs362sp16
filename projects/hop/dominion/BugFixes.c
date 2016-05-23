Author: Patrick Ho
Assignment 5
Due May 22, 2016
File: BugFixes.c
Description: Documentation of fixes to dominion.c based on bug reports and by using GDB.

Files Changed:
   dominion.c

Details:

Fixes to playAdventurer() function:

+ Bug 1: Noticed first for loop was not exiting when drawntreasure reaches 2. 
	In GDB, set watchpoint to drawntreasure and loop was not exiting until 
	drawntreasure has a value of 3.  Fixed post-increment of drawntreasure to 
	pre-increment. Bug fixed.

Fixes to playSmithy() function:

+ Bug 2: Teammate Hong lin noticed my smithy card play draws only 1 card. 
	Bug was found at the loop controlling the draw card procedure. A ';' was
	terminating the for loop pre-maturely. Removed the ';' and 3 cards are now 
	drawn as expected.

+ Bug 3: Teammate Jordan White noticed the number of actions changed while
	playing smithy card. While using GDB to trace the state.numActions[currentPlayer]
	variable, found that playSmithy() was inproperly terminated via a break statement
	in the switch structure. This caused playSmithy() to fall thru and execute 
	playVillage(), which gives the player extra actions to play. After adding the break
	statement immediately after playSmithy(), the number of actions do not change.


Fixes to playFeast() function:

+ Bug 4: Fixed the for loop conditional. i.e. "for (i=0; i <= state->handCount[currentPlayer]; i++)"
	My unit tests, random tests, nor card test caught this induced bug. Coverage for the bug is 
	one statement less than when it's fixed. The coverage information gives a hint, but it's subtle and
	if I did not keep a record of its change, I don't think I would have noticed it.

+ Bug 5: Fixed the condition to "if (supplyCount(choice1, state) <= 0)". Again, my unit test,
	card tests, and random tests do not reveal this as a bug. Coverage information also does not provide
	a clue that this is a bug.


Fixes to playCouncil_Room() function:

+ Bug 6: The final call to discardCard() was removed entirely in playCouncil_Room(). This appears to 
	be an unnecessary statement. Gcov coverage statistics does not help much with this bug because one
	line removed as a percentage of the entire code changes 1/643 or 0.1% of the statements.
