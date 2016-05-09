
Random Tests for Adventurer
File 'dominion.c'
Lines executed:21.85% of 563
Branches executed:18.80% of 415
Taken at least once:16.39% of 415
Calls executed:10.10% of 99
Creating 'dominion.c.gcov'

We called drawCard 174078 times. Treasure was drawn 4000 times.

I implemented a function to mimic playAdventurer() from dominion in my test file to function as an oracle. It drew cards until two treasure cards were
drawn, using drawCard() from dominion. Since drawCard() checks to see if the deck is empty, and shuffles if it is, then I didn't implement a check for an
empty deck or shuffling in my function. I added any treasure cards found to the player's hand, and put any non-treasure cards into a temphand where they
were held until two treasure cards were drawn. Then the temp-hand cards were added to the discard pile. 

I then compared the results from my Oracle to the results form playAdventurer() in dominion. The correct specification of adventurer says to draw cards until two treasure cards are drawn, discarding any non-treasure cards, and shuffling once if the deck is empty. It says that more than one shuffle should not be allowed which we can see because at that point we would have been through all cards in the deck and wouldn't find any more treasure cards by going through it again. To meet specification, playAdventurer() should match the Oracle, and by looking at differences, we can find potential bugs for when that test fails..

I noticed that all of my tests failed. I flagged the failing state if memcmp did not equal 0 when comparing my oracle( Test ) function versus the
implmentation in dominion. I printed the cards discarded, cards in hand, and cards in deck as well as the counts of each for both the oracle and
dominion implementation. When looking through the results, I noticed that a high number of curse cards were drawn almost every time for the dominion
implementation. I also noticed that the player always seemed to have an estate card and then curse cards in the discard pile. 
