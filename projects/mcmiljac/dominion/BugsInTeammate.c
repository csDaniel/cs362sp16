Jacob McMillen - mcmiljac@oregonstate.edu
CS 362 - Assignment 5
22 May 2016

*** BUG REPORT ***

Teammate1: Lauren Crees - creel@oregonstate.edu

adventurerEffect()
Title: Adventurer card not decreasing number of actions
Classification: Serious Bug
Reproducibility: Every time
Description: The number of actions the current player has should decrement by 1 after the card is played, but it remains unchanged.

Title: Adventurer card not increasing played card count
Classification: Serious Bug
Reproducibility: Every time
Description: The handCount of the current player should increase by 1 after the adventurer card is played, but it does not. 

Title: Adventurer card not found in played card array after playing
Classification: Serious Bug
Reproducibility: Every time
Description: After playing, the most recent card placed in playedCards[] should be the adventurer, but it is not. Perhaps adventurer is either not being discarderd or is being trashed instead of discarded?


smithyEffect()
Title: Smithy card not decreasing number of actions
Classification: Serious Bug
Reproducibility: Every time
Description: The number of actions the current player has should decrement by 1 after the card is played, but it remains unchanged.

Title: Smithy does not register as played
Classification: Serious Bug
Reproducibility: Every time
Description: The variable playedCardCount should increase by 1 after Smithy is played, and the most recent card placed in playedCards[] should be the Smithy, but neither is true. Since hand size is correct, perhaps smithy is being trashed instead of discarded?


Teammate2: Christopher Johnson - johnchri@oregonstate.edu

effectAdventurer()
Title: Adventurer card not decreasing number of actions
Classification: Serious Bug
Reproducibility: Every time
Description: The number of actions the current player has should decrement by 1 after the card is played, but it remains unchanged.

Title: Adventurer card not increasing played card count
Classification: Serious Bug
Reproducibility: Every time
Description: The handCount of the current player should increase by 1 after the adventurer card is played, but it does not. 

Title: Adventurer card not found in played card array after playing
Classification: Serious Bug
Reproducibility: Every time
Description: After playing, the most recent card placed in playedCards[] should be the adventurer, but it is not. Perhaps adventurer is either not being discarderd or is being trashed instead of discarded?


effectSmithy()
Title: Smithy card not decreasing number of actions
Classification: Serious Bug
Reproducibility: Every time
Description: The number of actions the current player has should decrement by 1 after the card is played, but it remains unchanged.

Title: Smithy card not decreasing deck count by 3
Classification: Serious Bug
Reproducibility: Every time
Description: The variable deckCount should have decreased by 3, but it does not. Check number of cards being drawn.

Title: Smithy card not increasing hand count by 2
Classification: Serious Bug
Reproducibility: Every time
Description: The variable handCount should have increased by 2, but it does not. May also be due to drawing wrong number of cards.


effectVillage()
Title: Village card not increasing number of actions
Classification: Serious Bug
Reproducibility: Every time
Description: The number of actions the current player has should increase by 1 after the card is played, but it does not.