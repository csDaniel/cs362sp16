--------------------------------------------
--------------------------------------------
--------------------------------------------
Bugs found in Candis's dominion.c
--------------------------------------------
--------------------------------------------
--------------------------------------------


****** Smithy Card ******
Total Smithy Errors: 1

Smithy Error #1
---------------------
Severity: Moderate
Description: Smithy draws only 2 cards from the deck, not 3.


****** Embargo Card ******
Total Embargo Errors: 1

Embargo Error #1: 
-----------------------
Severity: Moderate
Description: When an embargo token is placed on a supply pile, and another player tries to buy that card, the player doesn’t receive a curse card. 
Comment: Although this would be difficult to fix within the embargo card function, which does properly place an embargo token on that supply pile, it could be fixed in the buyCard() function, where the player gains that supply card but does not also gain a curse card.  



****** Remodel Card ******
Total Remodel Errors: 1

Remodel Error #1: 
-----------------------
Severity: Moderate
Description: The Remodel card is not being played when it should be and is being played when it should not - when the card being traded for has a value more than 2 above the card to be trashed, the remodel function is played, but when the card being traded for has a value of 2 or less above the card to be trashed, the remodel function isn’t played. 


****** Adventurer Card ******
Total Adventurer Errors: 4

Adventurer Error #1:
-----------------------
Severity: Moderate
Description: Instead of adding two treasure cards, it adds 3 cards from the deck. 

Adventurer Error #2:
-----------------------
Severity: Minor
Description: Adventurer does not add silver cards, even when available from the deck.

Adventurer Error #3:
-----------------------
Severity: Minor
Description: Adventurer card is not discarded after playing.
	
Adventurer Error #4:
-----------------------
Severity: Major
Description: If there aren’t 3 treasure cards in the discard pile and deck, the game ends up discarding all the cards in the hand and sometimes causing a segmentation fault (it keeps drawing from an empty hand into an out-of-bounds array). 





--------------------------------------------
--------------------------------------------
--------------------------------------------
Bugs found in Marta’s dominion.c
--------------------------------------------
--------------------------------------------
--------------------------------------------

****** Smithy Card ******
Total Smithy Errors: 1

Smithy Error #1
---------------------
Severity: Moderate
Description: Instead of drawing up to 3 cards, Smithy draws up to 4 cards. 


****** Embargo Card ******
Total Embargo Errors: 1

Embargo Error #1: 
-----------------------
Severity: Moderate
Description: When an embargo token is placed on a supply pile, and another player tries to buy that card, the player doesn’t receive a curse card.  
Comment: Although this would be difficult to fix within the embargo card function, which does properly place an embargo token on that supply pile, it could be fixed in the buyCard() function, where the player gains that supply card but does not also gain a curse card.  


****** Remodel Card ******
Total Remodel Errors: 1

Remodel Error #1: 
-----------------------
Severity: Moderate
Description: The Remodel card is not being played when it should be and is being played when it should not - when the card being traded for has a value more than 2 above the card to be trashed, the remodel function is played, but when the card being traded for has a value of 2 or less above the card to be trashed, the remodel function isn’t played. 


****** Adventurer Card ******
Total Adventurer Errors: 2

Adventurer Error #1:
-----------------------
Severity: Moderate
Description: The adventurer card has no effect when played – there is no change in the deck, discard pile, and hand other than that the adventurer card is no longer in the player’s hand. 

Adventurer Error #2:
-----------------------
Severity: Minor
Description: Adventurer card is not discarded after playing.