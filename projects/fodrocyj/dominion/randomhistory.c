Development Progress
John Fodrocy

I started my development without any randomization and slowly added more.
I think this is especially true in my Adventurer card tests.

For both tests, I added randomization for things like the number of players
and which cards where in the deck.
From there I added the card to be tested in the deck in a random position.
Finally, I added randomization for whose turn it is and who would play the
card.

For the Adventurer card specifically, I added more randomization to
variables that I thought would be changed by playing the card. For example
to the hand and deck count of each player. Then I added randomization to
where the card would turn up the first two treasure cards in the deck.
This randomization was helpful, but I added quite a bit of overhead to
the code and took a while to implement.



Here are results from my randomtestcard.out.
------------------------------
Council Room Random Tests Finished
--Total Tests:  10000
--Passed Tests: 10000
--Failed Tests: 0
------------------------------
File 'dominion.c'
Lines executed:30.84% of 548
Branches executed:30.94% of 417
Taken at least once:22.78% of 417
Calls executed:20.00% of 90
Creating 'dominion.c.gcov'


Here are results from my randomtestadventurer.out.
------------------------------
Adventurer Random Tests Finished
--Total Tests:  5000
--Passed Tests: 5000
--Failed Tests: 0
------------------------------
File 'dominion.c'
Lines executed:30.84% of 548
Branches executed:30.94% of 417
Taken at least once:22.78% of 417
Calls executed:20.00% of 90
Creating 'dominion.c.gcov'