Teammate 1

Bug 1
Title: Segmentation Fault (core dump) error due to poor construction of cardEffect
case loop. 
Classification: Severe 
Description: Overall gameplay and testing are effected when any of the refactored code is
played.  Teammate neglected to include break statements in cardEffect case loop after 
adding their refactored functions to case loop. Code:
switch( card ) {
    case adventurer:
			playAdventurer(state);		
			/*Should be break here*/
	
    case council_room:
			playCouncil_room(state, handPos);      
			/*Should be break here*/
			
    case feast:
			playFeast(state, choice1);
			/*Should be break here*/
			
Steps to reproduce: 
in Teammate1 folder enter commands:
$ make randomtestadventurer.out 

Bug 2
/*once Bug 1 has been fixed*/

Title: Adventurer test fail.  Hand count, card count, discard tests all fail. 
Random test runs into segmentation fault at 17th iteration 
Classification: Severe
Description: The cardDrawn variable has been refactored which causes a nearly complete fail for the 
adventurer card 

Steps to reproduce: 
in Teammate1 folder enter commands:
$ make randomtestadventurer.out 

Bug 3

Title: council_room fail: Assertion `p1startHand == p1endHand - 3' failed.
Hand contains +3 cards: Abort (core dumped)
Classification: Severe
Description: Cards drawn fails. Refactored code by author has changed loops that corrupt 
the number of cards drawn for council_room play 

Steps to reproduce: 
in Teammate1 folder enter commands: 
$ make cardtest1
$ cardtest1

Bug 4
Description: Card Draw Sub Test: 3 Drawn, 1 Discarded, Net +2 
Cards to Hand: FAIL, expected Net +2 Cards, Result +0 cards
Classification: Severe
Description: Incorrect number of cards drawn for Smithy gameplay
Author corrputed draw cards and changed internal functions in their playSmithy() function

Steps to reproduce: 
in Teammate1 folder enter commands: 
$ make cardtest2
$ cardtest2


Teammate2 

Bug 1
Title: Smithy discard fail 
Classification: Severe
Description: Author refactored playSmith() to draw four cards instead of three. Operations
are correct, but counting incorrect. 

Steps to reproduce: 
in Teammate2 folder enter commands: 
$ make cardtest2
$ cardtest2

Bug 2
Title: Deck count off after random testing adventurer
Classification: Medium
Description: I found a similar bug in in my random testing of my own code. 
About 3 in 75 runs results in a deck miscount.
I have yet to figure out why the random testing does this, and it admittedly could 
be an issue with my own testing. 

Steps to reproduce: 
in Teammate2 folder enter commands:
$ make randomtestadventurer.out 



