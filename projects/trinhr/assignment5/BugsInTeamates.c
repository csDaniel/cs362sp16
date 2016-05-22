Noverse Bug Reporting Template
==============================
TeamMate: Lauren Miller
________________________________________________________________
Bug #1
Title: playSmithy() Adds Incorrect Number of Cards to Hand

Class: Minor Bug

Date: 5/20/2016          
Reported By: Runa Trinh   
Email: trinhr@oregonstate.edu

Product: smithy_card(currentPlayer, &state, handPos, bonus);                 
       
Is it reproducible: Yes 

Description
===========
Playing the smithy card resulted in the incorrect
hand and deck count for the player. 

Steps to Produce/Reproduce
--------------------------
1. Set the number of players to two.
2. The player turn was set to 1.
3. The smithy card was in hand position 0.
4. Player's Hand Count was only 1.
5. Player's Deck Count was 10 cards.
6. Called the playSmithy function card.

Expected Results
----------------
End Deck Count: 7
End Hand Count: 3
Player's deck count would be decremented by three cards.
Player's hand count would be two higher because of three drawn cards
and a discarded smithy.

Actual Results
--------------
End Deck Count: 6
End Hand Count: 4
Player's deck count was decremented by four.
Player's hand count was three higher. 

Smithy card is probably drawing four cards from the deck
instead of three.


Bug #2
Title: adventurer_card() not Discarding Cards Correctly  

Class: Moderate Bug 

Date: 5/20/2016          
Reported By: Runa Trinh   
Email: trinhr@oregonstate.edu

Product: adventurer_card(player, &actual, temphand);                
       
Is it reproducible: Yes  

Description
===========
 Playing the adv

Steps to Produce/Reproduce
--------------------------
Steps to Produce/Reproduce
--------------------------
1. Set the number of players to two.
2. Initialize the game.
3. The player's deck(5): village, gold, smithy, feast, copper.
4. The player's hand(2): adventurer, mine.
5. The player's discard count was 0.
6. The player's discard: 0. 
7. Play the adventurer card.

Expected Results
----------------
Expected Deck Count: 0
Expected Discard Count: 4 (Village, Smithy, Feast, Adventurer)
Expected Hand Count: 3
-Player Hand Count will only increase by one with a discarded 
adventurer card and addition of two treasure cards.
-The Discard Count: three drawn unused cards and discarded adventurer. 
-The Deck Count will be empty since last card is the second treasure card.


Actual Results
--------------
Actual Deck Count: 1
Actual Discard Count: 0
Actual Hand Count: 4
-The adventurer card is most likely not being discarded.
-Drawn non-treasure cards are likely not being put back in the discard
pile. 
-Can't tell what is affecting the incorrect deck count. Maybe
a card is being read as a treasure card when it isn't.


TeamMate: Dave Martinez
________________________________________________________________
Bug #1
Title: playSmithy() Draws Incorrect Number of Cards

Class: Minor Bug

Date: 5/20/2016          
Reported By: Runa Trinh   
Email: trinhr@oregonstate.edu

Product: playSmithy(state, handPos);                   
       
Is it reproducible: Yes 
Description
===========
Playing the smithy card resulted in the incorrect
deck count and hand count for the player. 

Steps to Produce/Reproduce
--------------------------
1. Set the number of players to two.
2. The player turn was set to 1.
3. The smithy card was in hand position 0.
4. Player's Hand Count was only 1.
5. Player's Deck Count was 10 cards.
6. Called the playSmithy function card.

Expected Results
----------------
End Deck Count: 7
End Hand Count: 3
Player's deck count would be decremented by three cards.
Player's hand count would be two higher because of three drawn cards
and a discarded smithy.

Actual Results
--------------
End Deck Count: 5
End Hand Count: 5
Player's deck count was decremented by five.
Player's hand count was four higher.


Bug #2
Title: playAdventurer() Hand Count & Discard Count Is Off. 

Class: Minor Bug

Date: 5/20/2016          
Reported By: Runa Trinh   
Email: trinhr@oregonstate.edu

Product: playAdventurer(state);                   
       
Is it reproducible: Yes 
Description
===========
 The player's discard count is one less than it should be
 and the player's hand count is one more than it should be.

Steps to Produce/Reproduce
--------------------------
1. Set the number of players to two.
2. Initialize the game.
3. The player's deck(5): village, gold, smithy, feast, copper.
4. The player's hand(2): adventurer, mine.
5. The player's discard count was 0.
6. The player's discard: 0. 
7. Play the adventurer card.

Expected Results
----------------
Expected Hand Count: 3
Expected Discard Count: 4 (Village, Smithy, Feast, Adventurer)
Player's Hand should only increase by one because of the two drawn treasure cards and a discarded adventurer card.

Actual Results
--------------
Actual Hand Count: 4
Actual Discard Count: 3
Player's Hand has either drawn an extra card, the adventurer card was
not discarded, combination of both, or some other error.


Bug #3
Title: playVillage() adds Incorrect Number of Actions 

Class: Minor Bug

Date: 5/20/2016          
Reported By: Runa Trinh   
Email: trinhr@oregonstate.edu

Product: playVillage(state,handPos);                   
       
Is it reproducible: Yes 
Description
===========
The playVillage only increases the number of actions by one
instead of two.

Steps to Produce/Reproduce
--------------------------
1. Set the number of players to two.
2. Initialize the game.
3. The player's hand(2): village, gold. 
4. The number of actions for the player starts at 0.
5. Play the village card.

Expected Results
----------------
Expected Number of Actions: 2
The player's number of actions should have increased by 2.

Actual Results
--------------
Actual Number of Actions: 1
The player's number of actions only increased by 1.