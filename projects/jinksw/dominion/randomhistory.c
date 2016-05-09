
Random Tests for Adventurer
File 'dominion.c'
Lines executed:21.85% of 563
Branches executed:18.80% of 415
Taken at least once:16.39% of 415
Calls executed:10.10% of 99
Creating 'dominion.c.gcov'

We called drawCard 174078 times. Treasure was drawn 4000 times.

Random Tests for Smithy
File 'dominion.c'
Lines executed:4.45% of 562
Branches executed:2.41% of 415
Taken at least once:1.45% of 415
Calls executed:5.10% of 98
Creating 'dominion.c.gcov'


I implemented a function to mimic playAdventurer() from dominion in my test file to function as an oracle. It drew cards until two treasure cards were
drawn, using drawCard() from dominion. Since drawCard() checks to see if the deck is empty, and shuffles if it is, then I didn't implement a check for an
empty deck or shuffling in my function. I added any treasure cards found to the player's hand, and put any non-treasure cards into a temphand where they
were held until two treasure cards were drawn. Then the temp-hand cards were added to the discard pile. 

I then compared the results from my Oracle to the results form playAdventurer() in dominion. The correct specification of adventurer says to draw cards until two treasure cards are drawn, discarding any non-treasure cards, and shuffling once if the deck is empty. It says that more than one shuffle should not be allowed which we can see because at that point we would have been through all cards in the deck and wouldn't find any more treasure cards by going through it again. To meet specification, playAdventurer() should match the Oracle, and by looking at differences, we can find potential bugs for when that test fails..

I noticed that all of my tests failed. I flagged the failing state if memcmp did not equal 0 when comparing my oracle( Test ) function versus the
implmentation in dominion. I printed the cards discarded, cards in hand, and cards in deck as well as the counts of each for both the oracle and
dominion implementation. When looking through the results, I noticed that a high number of curse cards were drawn almost every time for the dominion
implementation. I also noticed that the player always seemed to have an estate card and then curse cards in the discard pile.

For playSmithy, my function implementation was to draw three cards and then compare the playSmithy() game state to my oracle game state. I found that there were differences in the number of cards in hand, deck, and discard for the two game states. In looking at the code coverage, for playSmithy(), gainCard() is called 8000 times on 2000 runs. We would expect only 6000 calls to gain card as it should be called 3 times per run. 

I also noticed differences in which cards were drawn. To check this, I printed the enum value for each card in hand, deck, and discard if they differed between game states. Prior to running each iteration, the cards were set randomly and then copied so that the two game states shared them. I think a difference could be that playSmithy is calling gainCard(), which I believe is meant to draw cards from available stacks in the game. This also helps explain why I noticed playSmithy() seemed to have an overabundance of curse cards.  
