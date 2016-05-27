Sam Schultz
Bug Fixes
5/22/2016

Bug Title: Specific game state causes faulty return value
Fix: In checkGameOver there is a for loop that iterates over 25 of the card values instead of up to treasure_map+1.

Bug: No deck size check in smithy function
Fix: Add a case to make sure deck size is greater than 3, if deck size is not greater than 3 a shuffle needs to happen.

Bug: does not manage deck size in playAdventurer function
Fix: Add a case to make sure the deck size is sufficient in order to keep drawing.

Bug: playVillage is trashed instead of discarded.
Fix: On the discard call in the playVillage function, the trashed flag needs to be switched so it is placed in the discard pile instead.


Bug: No checks on cost of card gained with playRemodel
Fix: Add a case to make sure the card is within the cost limits based off of what card was trashed.


