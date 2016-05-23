John Brown
Fixed the following bugs

Title:   Smithy  trashed instead of discarded.

Class:
Serious Bug

Date: 5/22/16

Is it reproducible: Yes 

Description
===========
After playSmithy is called the Smithy card is trashed rather than discarded


Expected Results
----------------
When Smithy Card is played, 3 cards should be drawn and card discarded.


Actual Results
--------------
When Smithy Card is played, trash flag is set to one causing the card to be trashed instead of discarded.


****************************************

Title:   Adventurer wrong number of treasures drawn, wrong number of cards discarded.

Class:
Serious Bug

Date: 5/22/16

Is it reproducible: Yes 

Description
===========
when playAdventurer is called, 3 treasures drawn rather then 2 and discard of temp hand is based on drawn treasurs - 2 rather than the size of the temp hand.


Expected Results
----------------
When playAdventure is called, deck drawn into temp hand until 2 treasure cards are drawn.  Treasue cards are kept, temp hand is discarded.


Actual Results
--------------
when playAdventurer is called, 3 treasures drawn rather then 2 and discard of temp hand is based on drawn treasurs - 2 rather than the size of the temp hand.


***************************************

Title:   playVillage adds the incorrect number of actions 

Class:
Serious Bug

Date: 5/22/16

Is it reproducible: Yes 

Description
===========
playVillage adds the incorrect number of actions to the player.  Also the card takes effect on next player rather than current player.


Expected Results
----------------
When playVillage is called, the player gains two actions


Actual Results
--------------
When playVillage is called, the cardPos (where the village is in the hand) is added to the actions rather than the literal 2. Also the card takes effect on next player rather than current player.




**************************************

Title:   playSalvager Error
Class:
Serious Bug

Date: 5/22/16

Is it reproducible: Yes 



Expected Results
----------------
Allows you to trash one card in your hand and gain coins to purchase that turn.


Actual Results
--------------
In playSalvager
function, the first if checks for true on handPos instead of choice1.  In
cardeffect error checking for playSalveger call is wrong. Checks that returned
in is > 0 instead of < 0.
