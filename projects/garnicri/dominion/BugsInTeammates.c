/*Rick Garnica
* Assignment 5--BugsInTeammates.c
* Reports bugs found in teammates' files 
*---------------------------------------*/
/*

#############################
Bugs Found, Teammate 1 - blumen
#############################


The follwing cardstests results are based on the error tests that compiled correctly: 

1.cardtest2.c   Smithy card:  all tests failed.  Four cards were always added to the players hand and no card was ever discarded.  This was either
							  due to Nathalie changing the code so that a card is never discarded in addition to adding one more card to the overall
							  total of what Smithy usually receives.  
                        
2.cardtest3.c  Council Room: Neither player receives the four cards they are supposed to as it relates to the original code for Council Room.  Nathalie
							 did indeed change the coding to bypass this function.  So in some ways, the test was accurate in measuring that the change
							 she made did indeed occur in addition to verifying that the rest of the gaming logic was correct.
							 
3. cardtest4.c  Feast card:  all tests failed.  The card in play is not discarded and the card selected is not added to the player's hand. I had to 
							 my original test to ensure this was the case as I hadn't accounted for the fact that the card selected would not be added but after reviewing Nathalie's changes, she changed the code so this would not be the case.
							 
4. unittest1-4.c:  all unit tests passed suggesting that only the refactored cards were changed and altered from the original coding.

                        
####################################
Bugs Found, Teammate 2 - brouilld 
####################################

The follwing cardstests results are based on the error tests that compiled correctly: 

1. cardtest2.c  Smith card:  only the first part of the test failed, that is, when the Smithy card is the first hand played in the deck.  I looked at
							 David's changes and the trash card field has been changed so Smithy removes a card before it should (at least that was
							 my understanding.)  When more hands were played, the code functioned correctly leading me to the conclusion that the 
							 trash flag was incorrect when playing the first hand.
							 
2.  cardtest1.c  Adventure card:  I had to make some changes to my original test just to get a working test but I know there's a bug in there because
								  the wrong hand count was present after the changes were made.  Either a card is not discarded or the wrong number of cards is added when the card is played.  
								  
3.  unittest1-4.c:  all unit tests passed suggesting that only the refactored cards were changed and altered from the original coding.

*/