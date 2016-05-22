/************************
Teammate - Gunnar Martin

I was able to find two bugs when running my tests on this code.

The first bug I found was in the smithy card.  The smithy card is supposed to give the player +3 cards.  My test checks to see if +3 cards have been added to the players hand.  The test failed when running.  When I checked this team mates refactor.c it appears that 4 cards get added to the players hand, as apposed to the correct amount of 3. Using a printf statement to check the number of cards added before and after it does appear to give the user +4 cards.

The second bug I found was in the adventurer card function.  I found it running my randomtestadventurer.c.  This test randomly tests the adventurer card several thousand times, and it seemed to uniformly fail when checking hadncount, deckcount, and discardcount after playing the card.  Here is just a sample of one failure from the card:



Adventurer Card Test:

 Hand count = 1, expected = 3
 FAIL on handcount does not change on current player
 Deck count = 0, expected = 2
 FAIL on deckcount does not change
 Discard count count = 17, expected = 14
 FAIL on discardcount does not change
 Hand count = 0, expected = 0
 PASS on handcount does not change on next player
Deck count = 10, expected = 10
 PASS on deckcount does not change on next player
 Estate = 8, expected = 8, duchy = 8, expected = 8, province = 8, expected = 8
 PASS on estate count does not change
 PASS on duchy count does not change
 PASS on province count does not change
 adventurer = 10, expected = 10
 PASS on adventurer count does not change

 
 As we can see, it fails in the areas noted above.  However, when I run cardtest2.c, which tests this same card, it passes.  However, cardtest2.c is not as thorough a test, since it only tests if the player recieves the treasure cards.  
 
 When checking refactor.c for this teammate, it does appear that the adventurer card discards extra cards, which accounts for that discrepency.



************************/

/************************
Teammate - John Brown

Unforunately, I was unable to get this teammates code to compile at all on flip.  I suspect there is an error with dominion.h, but even when I used the original dominion.h I get the same compile time errors.  I am currently working on trying to get it to compile.  Here is a sample of the errors i'm getting: http://i.imgur.com/Ks5FbYn.png

Note, that this is using his makefile.  I also tried with my makefile and getting the same errors.

************************/