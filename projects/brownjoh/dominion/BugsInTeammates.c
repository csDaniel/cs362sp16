Errors: brewbakl.  Note, cards were refactored in the actual cardEffect function rather than into a new function

Title:    Smithy Wrong Number of Cards Drawn

Class:
Serious Bug

Date: 5/22/16

Is it reproducible: Yes 

Description
===========
Player Draws 6 instead of 3 cards.


Expected Results
----------------
When Smith Card is played, 3 cards should be drawn.


Actual Results
--------------
When Smith Card is played, 6 cards are drawn.


Title:   Adveturer ignores copper

Class:
Serious Bug

Date: 5/22/16


Is it reproducible: Yes 

Description
===========
Adventure card does not find copper cards, only gold and silver.


Expected Results
----------------
When adventurer is played, deck is searched one card at a time until three treasures are found.


Actual Results
--------------
As above, except the only gold and silver cards are taken into account, copper cards are ignored.



**********




Errors: MartiGun

Title:    useSmithy, wrong number of cards drawn

Class:
Serious Bug

Date: 5/22/16


Is it reproducible: Yes 

Description
===========
Function useSmithy
Four cards drawn instead of three.


Expected Results
----------------
When the useSmithy function is called, player draws three cards and one card is discarded.


Actual Results
--------------
When the useSmithy function is called, 4 cards drawn rather then three.


Title:    useAdventure trashed after play rather than being discarded

Class:
Serious Bug

Date: 5/22/16


Is it reproducible: Yes 

Description
===========
Function useAdventurer
Adventure card is trashed instead of discarded.


Expected Results
----------------
When adventurer is played, deck is searched one card at a time until three treasures are found.


Actual Results
--------------
As above but the adventure card is trashed instead of discarded after being played.