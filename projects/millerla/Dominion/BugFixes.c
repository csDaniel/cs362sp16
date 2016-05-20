Assignment 5: Bug Fixes

Name: Lauren Miller
Date: May 20, 2016

Bug 1: Other Players Not Drawing Cards After Council Room 

Report by Dave Martinez:

	CARD TEST 4: council_room_card
	TEST 3: Does each other player get a card?
	Player 1 hand count = 0, expected 1

	LOCATION
	dominion.c:54 council_room_card()

	EXPECTATION
	Player 1 should receive a card after Player 0 draws four 
	after playing a councilroom. Player 1's handcount begins
	at zero and should iterate to 1. 

	POSSIBLE CAUSE
	dominion.c:66 for loop
	The condition of the 'for' loop at this line is the likely
	culprit. Rather than iteration over the number of players, 
	the function only iterates to the current player. Thus, if
	player 0 played a councilroom, only players in memory at 
	indexes less than 0 (impossible) will recieve an extra card.

	This should instead iterate up to gameState->numPlayers 
	and guard against providing gameState->whoseTurn an extra
	card. This guard is already in place at dominion.c:68 if.

Code Changes:

	Dave correctly identified the for-loop in council_room_card, the function refactored from the original Council Room in CardEffect. This was one of the bugs I introduced for Assignment 2, and adjusting the for-loop so that it iterated over every player in a given game instead of only those with an id less than the active player's corrected this bug.





Fix all the bugs that are found in your code.. First, fix the bugs that your teammate found then fix the bugs that you introduced. Use GDB to debug your code and fix it. Provide a documentation file to discuss which bugs you fix and mention your code changes. Provide a documentation file BugFixes.c. In case your teamates already fixed the bugs and you cannot  find out any bugs, Find out the version they just submitted for assignment 2 and use that version. It will give you better practice with git repository and repository history.