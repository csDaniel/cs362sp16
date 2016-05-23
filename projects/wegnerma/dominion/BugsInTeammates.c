TeamMate: Candis Pike
________________________________________________________________
Bug #1
Title: playAdventurer() does not count silver as treasure

Class: Minor Bug

Date: 5/20/2016          
Reported By: Marta Wegner   
Email: wegnerma@oregonstate.edu             
       
Is it reproducible: Yes 

Description
===========
When drawing cards only copper and gold (not silver) cards increase
the drawnTreasure count. 

Steps to Produce/Reproduce
--------------------------
1. Set whoseTurn
3. Create hand and deck piles, deck with at least 2 cards
4. Place two silver cards and no other treasure cards in deck
5. Call playSmithy function

Expected Results
----------------
Two treasure cards are added to hand

Actual Results
--------------
No treasures are added to hand


Bug #2
Title: playAdventurer() adventurer card is not discarded  

Class: Moderate Bug 

Date: 5/20/2016          
Reported By: Marta Wegner 
Email: wegnerma@oregonstate.edu               
       
Is it reproducible: Yes  

Description
===========
When playing the adventurer card the card is not discarded at the 
end of the turn

Steps to Produce/Reproduce
--------------------------
1. Initialize the game - hand, deck, discard, deck, and playedCards
2. Call playAdventurer() function
3. Check the playedCards array to see if card is discarded

Expected Results
----------------
Expect the adventurer card to be in the playedCard array

Actual Results
--------------
The adventurer card is not in the playedCard array


Bug #3
Title: playVillage() Number of actions added incorrectly  

Class: Minor Bug 

Date: 5/20/2016          
Reported By: Marta Wegner 
Email: wegnerma@oregonstate.edu               
       
Is it reproducible: Yes  

Description
===========
When playing the smithy card, only one action is added instead of 2

Steps to Produce/Reproduce
--------------------------
1. Set the number of actions
2. Initialize the card in hand and place village card in hand
3. Call playVillage() function
4. Check the number of actions 

Expected Results
----------------
The number of actions should be initial # of actions + 2

Actual Results
--------------
The number of actions is initial # of actions + 1


Bug #4
Title: playVillage() Village card is trashed  

Class: Moderate Bug 

Date: 5/20/2016          
Reported By: Marta Wegner 
Email: wegnerma@oregonstate.edu               
       
Is it reproducible: Yes  

Description
===========
When village card is played it is trashed

Steps to Produce/Reproduce
--------------------------
1. Initialize the card in hand, deck, playedCards, and place village 
card in hand
2. Call playVillage() function
3. Check the playedCards array for village card and the number of card 
in hand

Expected Results
----------------
Village card should be in playedCards array and the number of cards
in hand should be the same as the number of cards before the card 
was played


Actual Results
--------------
The number of cards in hand is correct but the village card is not in the 
playedCard pile


Bug #5
Title: playSmithy() Does not draw the right number of cards 

Class: Moderate Bug 

Date: 5/20/2016          
Reported By: Marta Wegner 
Email: wegnerma@oregonstate.edu               
       
Is it reproducible: Yes  

Description
===========
When smithy card is played 3 cards are not drawn

Steps to Produce/Reproduce
--------------------------
1. Initialize the card in hand, deck, playedCards, and place smithy 
card in hand
2. Call playSmithy() function
3. Check the number of cards in hand

Expected Results
----------------
The number of cards in hand should be original card count + 2

Actual Results
--------------
The number of cards in hand is original count + 1


TeamMate: Miranda Huey
________________________________________________________________
Bug #1
Title: playAdventurer() adventurer card is not discarded  

Class: Moderate Bug 

Date: 5/20/2016          
Reported By: Marta Wegner 
Email: wegnerma@oregonstate.edu               
       
Is it reproducible: Yes  

Description
===========
When playing the adventurer card the card is not discarded at the 
end of the turn

Steps to Produce/Reproduce
--------------------------
1. Initialize the game - hand, deck, discard, deck, and playedCards
2. Call playAdventurer() function
3. Check the playedCards array to see if card is discarded

Expected Results
----------------
Expect the adventurer card to be in the playedCard array

Actual Results
--------------
The adventurer card is not in the playedCard array


Bug #2
Title: playAdventurer() cards are being trashed

Class: Moderate Bug

Date: 5/20/2016          
Reported By: Marta Wegner  
Email: wegnerma@oregonstate.edu
                       
Is it reproducible: Yes 

Description
===========
 Some card(s) are being trashed when the function is called

Steps to Produce/Reproduce
--------------------------
1. Initialize the hand, deck, discard, playedCards - note total number 
of cards
2. Place adventurer card in hand
3. Call playAdventurer()
4. Compare original number to final number of cards

Expected Results
----------------
The final number of cards should be equal to the original number of cards

Actual Results
--------------
The final number of cards is not equal to the original number of cards


Bug #3
Title: playAdventurer() incorrect number of cards drawn 

Class: Minor Bug

Date: 5/20/2016          
Reported By: Marta Wegner  
Email: wegnerma@oregonstate.edu                 
       
Is it reproducible: Yes 

Description
===========
The playAdventurer card does not draw 2 treasures

Steps to Produce/Reproduce
--------------------------
1. Initialize the game: hand, deck
2. Place at least 2 treasures in the deck  
3. Play adventurer card
4. Count number of treasures in the hand and compare to 
previous number of treasures in the hand

Expected Results
----------------
Number of treasures in hand should be +2 more than original number

Actual Results
--------------
Number of tresures in hand is not +2 more than original number


Bug #4
Title: playSmithy() incorrect number of cards drawn 

Class: Moderate Bug

Date: 5/20/2016          
Reported By: Marta Wegner  
Email: wegnerma@oregonstate.edu                 
       
Is it reproducible: Yes 

Description
===========
The playSmithy card does not draw the correct number of cards

Steps to Produce/Reproduce
--------------------------
1. Initialize the game: hand, deck
2. Place at least 3 cards in deck  
3. Play smithy card
4. Compare number of cards in hand to previous number of cards in 
hand

Expected Results
----------------
The number of cards in hand should be two more than the previous 
number of cards in hand

Actual Results
--------------
The number of cards in hand is not two more than the previous number of 
cards in hand