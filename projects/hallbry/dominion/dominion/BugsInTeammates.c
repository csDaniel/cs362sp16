
The following reports documents the errors found in dominion.c while running my unit tests. 
My tests were able to detect several errors without refactoring the tests.  



/********************************************************************************************
Teammate1: Tiffany Chiou
********************************************************************************************/
Error1
==============================

Title: Smithy Function Error  

Class: Minor Bug


Date: 5/18/2016          
Reported By:   Bryant Hall
Email:  hallbry@oregonstate.edu    


Product:   Dominion.c                 
Platform:  Linux
    

Is it reproducible: Yes 

Description
===========
The smithy card pulls out 3 cards from the deck and adds them to a players hand. A unit test was created that evaluated the gamestate struct in domion.c before and after the card was played. 
Unit tests showed that the number of cards and expected coin count after playing the smithy card did not agree with expected values. 


Steps to Produce/Reproduce
--------------------------
Run card test2 Or 
Store gamestate in separate struct 
Run Card effect with Smithy function 
Check original number of cards + 3 and deck count in stored value with newly generated values 


Expected Results
----------------
Expected Deck Count 2
Expected HandCount: 2

Actual Results
--------------
new Deck Count 1
new HandCount: 3, 

Workarounds
-----------



Attachments
-----------
N/A


Other Information
-----------------




Error 2 
==============================

Title:  Adventurer Card Error    

Class: 
e.g. "Feature Request", "System Error", "Serious Bug"

Date:  5/18/2016         
Reported By: Bryant Hall   
Email: hallbry@oregonstate.edu       


Product: dominion.c 
Platform: Linux 

Is it reproducible: Yes 

Description
===========
Adventurer card has the effect of drawing cards from a deck until two additional treasure cards have been pulled and added to the players deck. 
A unit test was created to test the effects of this in dominion.c. Test results from this 
indicted that coin count from adventurer is off and the number of card is also off after this
card has been played.  


Steps to Produce/Reproduce
--------------------------
Run Cardtest1 Or Record values stored in gamestate before playing card
Set deck to entirely copper coins. 
Run cardeffect with Adventurer value. 
Compare expected results with actual values. 


Expected Results
----------------
Expected Coint Count: 6
Expected Hand Count: 7

Actual Results
--------------
New Coin Count: 7 
New Hand Count: 8 


Workarounds
-----------
N/A


Attachments
-----------
N/A 


Other Information
-----------------
We seem to have a bug in two different areas as this is affecting two different properties in gamestate. 

/********************************************************************************************
Teammate2: Derek Wong 
********************************************************************************************/
Error1
==============================

Title: Smithy Function Error  

Class: Minor Bug


Date: 5/18/2016          
Reported By:   Bryant Hall
Email:  hallbry@oregonstate.edu    


Product:   Dominion.c                 
Platform:  Linux
    

Is it reproducible: Yes 

Description
===========
The smithy card pulls out 3 cards from the deck and adds them to a players hand. A unit test was created that evaluated the gamestate struct in dominion.c before and after the card was played. 
Unit tests showed that the played card count did not agree with expected values after playing this test. 



Steps to Produce/Reproduce
--------------------------
Run card test2 Or 
Store gamestate in separate struct 
Run Card effect with Smithy function 
Check the played card count in the original gamestate + 1 compared with the new value in the gamestate
after playing the Smithy Card 




Expected Results
----------------
Expected Played Card Count: 1

Actual Results
--------------
New Played Card Count:  0


Workarounds
-----------
N/A


Attachments
-----------
N/A


Other Information
-----------------




Error 2 
==============================

Title:  Adventurer Card Error    

Class: Minor bug 


Date:  5/18/2016         
Reported By: Bryant Hall   
Email: hallbry@oregonstate.edu       


Product: dominion.c 
Platform: Linux 

Is it reproducible: Yes 

Description
===========
Adventurer card has the effect of drawing cards from a deck until two additional treasure cards have been pulled and added to the players deck. 
A unit test was created to test the effects of this in dominion.c. Test results from this 
indicted that coin count from adventurer is off and the number of card is also off after this
card has been played.


Steps to Produce/Reproduce
--------------------------
Run Cardtest1 Or Record values stored in gamestate before playing card
Set deck to entirely copper coins. 
Run cardeffect with Adventurer value. 
Compare expected results with actual values. 


Expected Results
----------------
 Expected Coint Count: 6
 Expected Hand Count: 7
 
Actual Results
--------------
New Coin Count: 4 
New Hand Count: 5


Workarounds
-----------
N/A


Attachments
-----------
N/A 


Other Information
-----------------
We seem to have a bug in two different areas as this is affecting two different properties in gamestate. 





