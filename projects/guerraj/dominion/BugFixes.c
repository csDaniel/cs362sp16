/*

James Guerra Assignment 5 bug fixes

Bugs found by teammates: 
Ryan Peters: 

Adventurer Card - The player did not draw two treasure cards when the adventurer card was played.
Council Room Card - The other players did not draw cards.

Michael Loom:
 Smithy doesnt add the correct number of cards
 Great Hall card doesn't add an action
 
 Documentation of Bugs Fixed:  
 
Adventurer Card function: Bug wrong number of treasure cards drawn fixed.  
	While loop counter decreased from 4 to 2 in function callAdventureCard.  
Council Room Card function: Bug, does not enter state where players draw cards, error in for loop.
	For loop fixed to correctly enter when prerequesists are met in function callCouncilRoom.  
Smithy Card function: incorrect number of cards drawn during action.  
	i initialized to 0 instead of 1 in order to add additional card in loop in function callSmithy.
Great Hall function: incorrect number of actions added to gamestate.  
	added inclement of numActions in the game state when function callGreatHall is called.  
	
End of reported bugs from teammates.

Bugs reported by own unittests:  
remodel card: incorrect operator used in if statement > changed to <

Bugs MISSED by all tests due to insufficent code coverage and a insufficent test suite
Village card function: bug fixed that caused wrong number of cards to be drawn. extra call to drawcard function
Adventurer: Additional bug that of function that was not tested by any tests, buf fixed for shuffle of deck if empty.  

Knowing the Code coverage of each test helped me understand as a programmer that there were functions,
in this case entire cards, that were not tested by the test suite, which meant that there was 
code that was untested and not run.  This means that bugs could potentially slip thorugh,
as I saw with the Village card, which none of my teammates nor I tested.  Furthermore,
even when code is tested, as in the case of the Adventuerer card, that doe snot mean that bugs do not exist.
None of the tests looked at how the Adventurer card acted when a deck was empty, which allowed a bug which
skipped the desired call to the suffle feature to be missed.  Further proof that while important, code coverage has
limits, and complete testing of functions is needed during the testing phase of development.  */  
 
 