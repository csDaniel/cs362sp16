/******************************************************************************
* ASSIGNMENT 5 - BugsInTeammates.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 05/22/2016
* NOTES: bug reports for teammates
*	- Max Grubb (grubbm@oregonstate.edu)
*	- Wesley Jinks (jinksw@oregonstate.edu)
******************************************************************************/

/******************************************************************************
* TEAMMATE 1 - Max Grubb (grubbm@oregonstate.edu)
* 
* BUG 1: smithy not found in discard pile
* LOCATION: cardEffect() function (smithy case)
* SEVERITY: Serious bug
* REPRODUCABLE: Yes, appears in 9909 of 10000 random tests
* SUMMARY: Playing player's discard pile is not one card higher in the
* 	bulk of test performed on cardEffect() function when passed the smithy
* 	case.
* STEPS TO REPRODUCE: Call cardEffect(smithy, 0, 0, 0, &GameState, handPos, 0),
*	check to make sure that player indicated as current player's discard pile
* 	is incremented by 1.
* EXPECTED RESULTS: Discard pile for playing player is +1 card after calloc
* ACTUAL RESULTS: Discard pile is not +1 card
* 
* BUG 2: adventurer not adding enough cards to handPos
* LOCATION: cardEffect() function (adventurer case)
* SEVERITY: Serious bug
* REPRODUCALBE: Yes, appears in 9991 of 10000 random tests
* SUMMARY: Playing player's hand should have one more card after calling the
* 	cardEffect() function when passed the adventurer case, but does not.
* STEPS TO REPRODUCE: Call cardEffect(adventurer, 0, 0, 0, &TestState, 
* 	handPos, 0), check to make sure that player indicated as current player
* 	has handCount incremented by 1 (+2 treasure cards, -1 adventurer card).
* EXPECTED RESULTS: Calling player's hand should have +1 card (+2 treasure 
* 	cards, -1 adventurer card).
* ACTUAL RESULTS: Calling player's hand does not have +1 card.
******************************************************************************/

/******************************************************************************
* TEAMMATE 2 - Wesley Jinks (jinksw@oregonstate.edu)
* 
* BUG 1: smithy not drawing 3 cards
* LOCATION: playSmithyCard()
* SEVERITY: Serious bug
* REPRODUCABLE: Yes, appears in 9923 of 10000 random tests
* SUMMARY: Playing player's hand should be +2 cards after calling 
* 	playSmithyCard(), but does not
* STEPS TO REPRODUCE: Call playSmithyCard(), and check calling player's hand
* 	size. 
* EXPECTED RESULTS: Calling player's hand should have +2 cards
* ACTUAL RESULTS: Calling player does not have +2 cards
* SPECIAL NOTES: See Bug 2
* 
* BUG 2: smithy is not discarded
* LOCATION: playSmithyCard()
* SEVERITY: Serious bug
* REPRODUCALBE: Yes, appears in 9923 of 10000 random tests
* SUMMARY: Player's discard pile should be incremented by 1 but is not,
* 	in fact it appears that many more than 1 card is discarded
* STEPS TO REPRODUCE: Call playSmithyCard() and check calling player's
* 	discard size.
* EXPECTED RESULTS: Calling player's discard should be +1
* ACTUAL RESULTS: Calling player's discard is much higher than 1; it appears
* 	that drawn cards may all be discarded
******************************************************************************/