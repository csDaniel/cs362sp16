/*Joseph Cuellar
CS 362 Assignment 5
Both unittestresults.out files for each teammate will be located in their teammate1/2Dominion folders.

Teammate 1: Miranda Weldon

Notes: Most editing that needed to be done was to match up function names. For example, my code used callAdventurerCard 
and her's used adventurerCard. Easy fix.

Location: int smithyCard function. Line 676, 677. Found this because it caused a segmentation fault in my card test.
Bug1: 'i' was not declared. drawCard is passing 'i' and state, rather than currentPlayer and state. 
Code:  for (i = 0; i < 3; i++)
	  drawCard(i, state);

Location: int ambassadorCard function. Many lines. 
Bug2: The variables 'choice1' and 'choice2' are switched everytime they appear in the code.
Code: All throughout the function, lines 738 - 768

Location: int adventurerCard. Line 664ish. This passed my card test, but caused a seg faults on my random test.
Bug3: 'z' is not incremented after state->handCount[currentPlayer]--
Code: else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	}

Teammate 2: James Taylor

Notes: The first 2 bugs were found using my card tests! So that was encouraging. The last one I found while doing a code inspection.

Location: smithy_ref function. Line 709
Bug4: 'i' was set to begin at 1 in the for loop rather than 0, so it drew one less card. This threw off my 
test for deckCount/handCount.
Code:	 for (i = 1; i < 3; i++)

Location: adventurer_ref function. Line 656. This failed both my unit test and random test.
Bug5: The deckCount test condition was > instead of <. This caused a shuffle function to be called whenever there was more than 1 
card in the deckCount.
Code: if (state->deckCount[currentPlayer] >1)

Location: council_room_ref function. Before line 697.
Bug6: The discardCard function is completely missing. So nothing is discarded.
Code: Code is missing.


Conclusion:
Luckily, the only things I needed to change where the function names in my tests in order to match the names my 
teammates used. I suppose this showed good maintainability in my tests. Both times I found, if I remember correctly,
the required bugs in Adventurer and Smithy. My card tests came through and pointed out the flaws, or at least tripped
up and made me investigate those cards closer.
*/