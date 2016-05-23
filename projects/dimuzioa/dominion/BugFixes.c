/**********

According to the bug reports created by teammates, and knowledge of my own code, I made the following changes to fix my Dominion code:

On line 1284, I once again make 'copper' an OR condition of incrementing drawnTreasure.

On line 1307, I changed the for loop condition back to 'i < 3' so that Smithy correctly draws 3 cards rather than 4.

On line 1326, I added back the discard statement so that the Great Hall card is properly discarded after playing.

On line 1354, I change the playCouncilRoom function back to incrementing numBuys by only 1, rather than 2. 

**********/