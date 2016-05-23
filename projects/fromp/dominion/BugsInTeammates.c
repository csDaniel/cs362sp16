Preston From


General notes on debugging teammates' code:
-- The original unit tests I had written did not require too much in the way of refactoring to use them and they did find the bugs I was looking for. However, I do not believe the found all of the bugs that were in teammates' code -- errors were found, but the unit tests were not designed to pinpiont the sources of those problems. More work with gdb and gcov might have helped, but a full rewrite of the unit test probably would have helped find and localize more issues than those noted below.

Of the problems I found, some were problems that were similar to or related to problems that were also in my code, such as those related to the number of cards drawn, etc. and the exact cards in decks, hand, etc. I think overall these unit tests were a solid starting point for debugging as they allowed me to find multiple problems and with the large amount of information related to states provided, they made looking for errors easier. However, I think they could use a bit more work on looking for unexpected errors.

X-- Bug Reports for loomisja@oregonstate.edu --X

Bug Report 1
Title: Smithy draws incorrect number of cards
Preston From (fromp@oregonstate.edu)
Date: 5/19/2015

Classification: Severe (game rules violated)

Product: dominion.c
Tested on: Ubuntu 16.04

Unit test used: cardtest1.c
Modifications required to use unit test: The call to the smithy card had a different function name.

Description:
Playing the smithy card results in the player drawing 4 cards instead of the expected 3.
Reproducible: Yes
To reproduce:
1. Initialize a game state with random seed of 10 and a hand for player 2 consisting of a smithy card in the first place and 4 copper cards.
2. Call cardEffectSmithy with 1 for the player, 0 for the hand position, and the game state.

Expected results: 
3 cards are drawn and added to player 2's hand (2 copper cards and 1 estate)
Actual results: 
4 cards are drawn and added to player 2's hand (2 copper cards, 1 estate card, and another copper card)

Fixing/debugging:
The for-loop for drawing cards appears to be incorrect and reads as below.

for (i = 0; i <= 3; i++)

Instead of i <= 3, the loop should continue only while i < 3.


Bug Report 2
Title: Adventurer draws incorrect number of cards
Preston From (fromp@oregonstate.edu)
Date: 5/19/2015

Classification: Severe (game rules violated)

Product: dominion.c
Tested on: Ubuntu 16.04

Unit test used: cardtest2.c
Modifications required to use unit test: The call to the adventurer card had a different function name. Additionally, it also required the passing of an additional parameter (the position of the adventurer card in the player's hand).

Description:
Playing the adventurer card results in the player drawing 3 coin cards instead of the expected 2.
Reproducible: Yes
To reproduce:
1. Initialize a game state with random seed of 900 and a hand for player 2 consisting of a adventurer card in the first place and 4 copper cards.
2. Call cardEffectAdventurer with 1 for the player, 0 for the hand position, and the game state.

Expected results: 
4 cards are drawn and 2 copper cards are added to the player's hand while 2 estate cards are discarded
Actual results: 
5 cards are drawn and 3 copper cards are added to the player's hand while 2 estate cards are discarded.

Fixing/debugging:
The for-loop for drawing cards appears to be incorrect and reads as below.

while (drawntreasure <= 2)

Instead of i <= 2, the loop should continue only while i < 2.




X-- Bug Reports for esquiveo@oregonstate.edu --X

Bug Report 1
Title: Adventurer card discards inappropriate number of cards
Preston From (fromp@oregonstate.edu)
Date: 5/19/2015

Classification: Severe (game rules violated)

Product: dominion.c
Tested on: Ubuntu 16.04

Unit test used: cardtest2.c
Modifications required to use unit test: The call to the adventurer card had a different function name. Additionally, it also required the passing of  additional parameters (including a temporary hand array, a counter, the position of adventurer in the player's hand, and so on).

Description:
Playing the adventurer card results in the player discarding more cards than should be discarded.
Reproducible: Yes
To reproduce:
1. Initialize a game state with random seed of 900 and a hand for player 2 consisting of an adventurer card in the first place and 4 copper cards.
2. Call adventurerPlay with: adventurerPlay(0, &game, 1, 0, temphand, 0).

Expected results: 
4 cards are drawn and 2 (copper) are added to player 2's hand and 2 (estate) are discarded.
Actual results: 
4 cards are drawn and 2 (copper) are added to player 2's hand and 3 (2 estate and 1 curse) are discarded.

Fixing/debugging:
The while for discarding cards appears to be incorrect and reads as below.

while(z >= 0) 

Instead of z >= 0, the loop should continue only while z - 1 >= 0.



Bug Report 2
Title: Adventurer card is not discarded after use
Preston From (fromp@oregonstate.edu)
Date: 5/19/2015

Classification: Severe (game rules violated)

Product: dominion.c
Tested on: Ubuntu 16.04

Unit test used: cardtest2.c
Modifications required to use unit test: The call to the adventurer card had a different function name. Additionally, it also required the passing of  additional parameters (including a temporary hand array, a counter, the position of adventurer in the player's hand, and so on).

Description:
The adventurer card is not discarded after it is used.
Reproducible: Yes
To reproduce:
1. Initialize a game state with random seed of 900 and a hand for player 2 consisting of an adventurer card in the first place and 4 copper cards.
2. Call adventurerPlay with: adventurerPlay(0, &game, 1, 0, temphand, 0).

Expected results: 
Adventurer card is added to the played cards pile
Actual results: 
Adventurer card remains in player 2's hand.

Fixing/debugging:
A call to discardCard should be added at the end of the adventurerPlay function as below:
discardCard(0, 1, &compareGame, 0);
