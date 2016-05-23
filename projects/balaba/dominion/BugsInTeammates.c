/*---------------------------------------
* Aleksandr Balab
* 5/18/16
* CS362_400 Software Engineering II
* Assignment 5--BugsInTeammates.c
* Reports bugs found in teammates' files 
*---------------------------------------*/
/*

#############################
Bugs Found, Teammate 1 - Breet Irivin/irvind 
#############################


The follwing cardstests results are based on the matching refactored cards(3 out of 4 cardtests): 

1.cardtest1.c    Adventurer card: Failed for every single itteration. The number of cards on player's  expected and 
                        actual was always different. Particullary the actual number of handCount was always  higher by 2 cards. 
                        First i thought that the cards are not being discarded or not being trashed. My tester only checks if the
                        game.handcount is equals to the expected handCount, but doesn't point out where specifically the test is failing.
                        Most likely the issue is with my tester, since he didn't introduce the bug in this card.
                        
2.cardtest2.c   Smithy card:  Failed for every single itteration. The number of cards on player's  expected and 
                        actual was always different. The number of cards on hand is always 1 smaller then expected, leading  me to conclusion
                        that the bug is in the loop for the drawCard function.  Indeed the bug was introduced by Breet  in the loop. 
                        
3.cardtest3.c  Village card: Failed for every single itteration. Number of cards on hand was 1 more then expected while the number of actions
                        expected is the same as number of  actual actions.  Leading me to believe that the bug is not in the  card's logic but in its 
                        trash/discard action. Indeed the bug was introduced by Breet in the logic responsible for discarding the played card from the current
                        hand. 
                        
4. Unittest1 (updateCoins) - Worked correctly. No bugs encountered. 

5. Unittest2 (discardCard) - Worked correctly. No bugs encountered. 

6. Unittest 3 (whoseTurn) - Didn't initiate  whos turn correctly. 
						 Even thou the test run and was successful, i do believe 
						 there are bugs. 
                         
7. Unittest4 (fullDeckCount) - Worked correctly. No bugs encountered.                     
                        

    Random Tests: 
    (Only adventurer card applied)
                        
8. Randomtestadventurer.c: 				
                    Since testing this card I decided to randomilly assign values to as many variable within
					1. Randomize numPlayer ( non card specific , but allows to see wether the number of players would change the output)
					2. Random hand Card ( number of cards on hand)
					3. Current Player ( randomly assign who is current player)
					4. Randomize number of cards to trash.
                    
                    The results were the same as cardtest1.c. The number of cards on player's  expected and 
                        actual was always different. Particullary the actual number of handCount was always  higher by 2 cards. 
                        The number of players did not effect the outcome. 


                        
####################################
Bugs Found, Teammate 2 - Dane Schoonover/schoonod 
####################################

The follwing cardstests results are based on the matching refactored cards(2 out of 4 cardtests): 



1.cardtest1.c    Adventurer card:  Similarly to Teammate1 results. Failed for every single itteration. The number of cards on player's  expected and 
                        actual was always different. Particullary the actual number of handCount was always  higher by 2 cards. 
                        Even thou Dane introduced a bug to the Adventurer where the player gets an extra tresure card, the difference should've
                        been only 1 card and not 2 cards.  Most likely the issue is with my tester.

2. cardtest2.c Smithy card: Failed for every single itteration. The number of cards on player's  expected and 
                        actual was always different. The number of cards on hand is always 1 bigger (unlike Teammate1 code where it was always smaller) then expected,
                        leading  me to conclusion that the bug is in the loop for the drawCard function.  Indeed the bug was introduced by Dane in the loop. 





4. Unittest1 (updateCoins) - Worked correctly. No bugs encountered. 

5. Unittest2 (discardCard) - Worked correctly. No bugs encountered. 

6. Unittest 3 (whoseTurn) - Didn't initiate  whos turn correctly. 
						 Even thou the test run and was successful, i do believe 
						 there are bugs. 
                         
7. Unittest4 (fullDeckCount) - Worked correctly. No bugs encountered.   



    Random Tests: 
    (Only adventurer card applied)
                        
8. Randomtestadventurer.c: 				
                    Since testing this card I decided to randomilly assign values to as many variable within
					1. Randomize numPlayer ( non card specific , but allows to see wether the number of players would change the output)
					2. Random hand Card ( number of cards on hand)
					3. Current Player ( randomly assign who is current player)
					4. Randomize number of cards to trash.
                    
                    The results were the same as cardtest1.c. The number of cards on player's  expected and 
                        actual was always different. Particullary the actual number of handCount was always  higher by 2 cards. 
                        The number of players did not effect the outcome.

*/