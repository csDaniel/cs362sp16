/*
                    -----History of development of random testers by Elliot Bates-----

-Development of the random testers was done by fir of all deciding how to randomise the game state before testing.
-I decided it was best to randomise as much as possible, including the number of player, contents and size of their decks,
 contents and size of their hands, whose turn it is, and the position of the card to be played in the players hand.
-randomtestadventurer.c was written first. I wrote the random tester by first studying the cource code, and working back from
 there trying to write tests that would get good coverage and test boundary values.
-I assumed that given the large number of tests (20000) that the random number generation method used would evenutally result
 in the testing of boundary values.
-The statement/branch that I had identified from my usit tests as not being covered was the if statement that determined whether
 the user had cards in their deck and therfore needed to shuffle.
-Because of this, randomtestadventurer.c has a section of code to randomise the number of cards in the player who will play the adventurer
 card's deck from 0 up to some arbitrary maximum value, meaning that at times a small enough deck will be used triggering the shuffle.
-Finally I added a function to the tester to compare the game state before and after the card was played to check for discrepancies.
-By studying the results of the tests it can be seen that my random testing of the adventurer function gains 100% statement and branch coverage
-My random tester was not, however, able to pick up on the bug that I added in a previous week. In order for this to have been picked up my state
 testing function would need to identify the position in the deck of the next two treasure and check that it was these treasures added to the player's
 hand. In reality though, if I had not known the bug was there I would not have made my state checker check for this. This bug would be caught by 
 inspection much quicker.
-The code used to randomly test the adventurer card was mostly reusable to randomly test the village card, with just some minor adjustments to the
 way that it randomises the state before playing the card, and to the state checking function after it has been played.
-By studying the results it can be seen that randomtestcard.c also gets 100% statement and branch coverage of the village fuinction in dominion.c.
-This random tester was able to pick up on the bug that I had intoriduced in a previous week.

*/