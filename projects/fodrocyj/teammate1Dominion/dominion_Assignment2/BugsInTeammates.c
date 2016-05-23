**************************************
**Team Member: Nick Martin

**************************************
***Bug Report One*********************
**************************************

Bug: 001 - Adventurer Card

Description of Bug:
  Adventurer card, when used by the cardEffect() function causes an undesireable state.
	The specifications from the game state that the player plays the adventurer card and
	takes the first two treasure cards from the deck, meaning the player should end up with
	one extra card in total. Testing shows that the player ends up with the same number
	of cards they started with. Also, random testing shows that other players are in the 
	game have values that don't match what they should in their game state variables. Specifically
	in their hand count and deck count.
	
Causes of Bug:
	This bug seems to be caused anytime we run the cardEffect() function with the adventurer
	card meaning whenever we run the playAdventurer() function. It is not difficult to
	duplicate the failure caused by this bug.
	
Potential Location of Bug:
	It is most likely that the fault is located in the playAdventurer() function.

Severity of Bug:
	As this is a bug that effects the gameplay of Dominion, it is high severity. It causes
	segmentation fault crashes in the random tester from time to time.
	
Priority of Bug:
	The bug doesn't seem difficult to fix. Combined with its high severity, this makes
	it a high priority bug.
	

**************************************
***Bug Report Two*********************
**************************************

Bug: 002 - Smithy Card

Description of Bug:
	When playSmithy() is called by the cardEffect() function, there is an undesireable state
	in the game. The specifications for Dominion say that the smithy card should give the
	player who delt it three cards. However, testing shows that the player ends up with
	an extra seven cards.
	
Cause of Bug:
	The failure occurs every time the playSmithy() function is called. The failure is
	easy to duplicate.
	
Potential Location of Bug:
	The fault is most likely located in the playSmithy() function.
	
Severity of Bug:
	Since the bug alters one of the core components of the program, it is of high severity.
	
Priority of Bug:
	The failure isn't difficult to duplicate and is probably located in the playSmithy()
	function which only contains a few lines of code. Since it is of importance to the value
	of the software and easy to fix, this is a high priority bug.