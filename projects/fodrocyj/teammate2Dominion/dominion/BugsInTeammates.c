**************************************
**Team Member: Rob Tan

**************************************
***Bug Report One*********************
**************************************

Bug: 001 - Adventurer Card

Description of Bug:
  The cardEffect() function doesn't execute correctly when the card is the adventurer card.
	The specifications from the game state that the player plays the adventurer card and
	takes the first two treasure cards from the deck, meaning the player should end up with
	one extra card in total.
	
Causes of Bug:
	This bug seems to be caused anytime we run the cardEffect() function with the adventurer
	card. It is not difficult to duplicate the failure caused by this bug.
	
Potential Location of Bug:
	It is most likely that the fault is located in the playAdventurer() function.

Severity of Bug:
	As this is a bug that effects the gameplay of Dominion, it is high severity.
	
Priority of Bug:
	The bug doesn't seem difficult to fix. Combined with its high severity, this makes
	it a high priority bug.
	

**************************************
***Bug Report Two*********************
**************************************

Bug: 002 - Village Card

Description of Bug:
	The cardEffect() function doesn't execute correctly when the card is the village card.
	It is likely that this bug is in the playVillage() function which is run when
	cardEffect() is given the village card. The specifications say that the village card
	gives the player one extra card from the deck and two extra actions. However, the
	player ends up with three extra actions.
	
Cause of Bug:
	The bug occurs every time the playVillage() function is called and is not difficult
	to duplicate the failure.
	
Potential Location of Bug:
	The fault is most likely located in the playVillage() function.
	
Severity of Bug:
	As a bug that alters the gameplay in undesireable ways, this is of high severity.
	
Priority of Bug:
	The failure isn't difficult to duplicate and is probably located in the playVillage()
	function so it shouldn't be difficult to fix. Since it is of importance to the value
	of the software and easy to fix, it is of high priority.