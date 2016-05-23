BugFixes.c


Fix all the bugs that are found in your code. First, fix the bugs that your teammate found then fix the bugs that you introduced. Use GDB to debug your code and fix it. Provide a documentation file to discuss which bugs you fix and mention your code changes.

playSmithy()
	
	-Changed bug that caused player to trash the card instead of discarding it
	-Changed bug that always cause the first player to discard from the hand-position of Smithy, regardless of whose turn it is

playAdventurer()
	-Reset initial drawn treasure count to 0 so that only two treasures are drawn instead of three

playMinion()
	-Changed code for player to gain two coins (bug caused him/her to lose two coins)
	-Changed bug that left one card in player's hand before drawing four new cards
	-Changed bug that caused the player to draw four cards as well as the other players

playCutpurse()
	-Removed bug that caused player to discard all coppers in hand rather than just one.