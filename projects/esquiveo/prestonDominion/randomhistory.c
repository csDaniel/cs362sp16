// Osbaldo Esquivel
// CS 362
// 06MAY2016
// Assignment 4

I approached these random card tests similar to how I approached the unit tests we did previously. The best way I found to test these cards was to randomize the state of the game where I set each aspect of the game state to a random value. This would have the effect of testing each part of the game state as many times as the test was run. My hope was that this would provide plenty of coverage for executed blocks. I decided to set the number of players to a random number of at least 2 players. Then, the deck would also hold a random value for the number of cards in each hand. The hands were filled with random cards and set the random deck size for each player.

For the randomtestcard.c program, I chose the cutpurse card which was different than the previous cards I had chosen. This card will make all other players discard one copper and if they do not have a copper, they must reveal their hand to the other player(s) and it also gives +2 (essentially like a silver). Using the strategy above, I was able to create a random test that would loop and create a random game state to test against expected values. The following is the result of coverage for my test:

File 'randomtestcard.c'
Lines executed: 100.00% of 48

Now, when I first wrote this test, I forgot to test the other players hands at the end of round which was not testing to see if cutpurse worked correctly. At this point, coverage was 66% instead of 100% and I couldn't really figure out why coverage was so low. It took a bit for me to realize that I needed to make sure to test the other hands to ensure the cutpurse card was effective. Once I added the loop to check the players hand, I was able to acheive 100% coverage.

For the randomtestadventurer.c program, I followed the same strategy to randomize the state of the game and the number of players. Then, I ensured that the program would check that once two treasure cards were shown, all other cards would be discarded. I believe I found a bug, though, in the adventurer function as it does not discard a card as it should. Initially, I would receive a Segmentation fault when trying to run the program and I could not see why it would continue to error. Then, I remembered that I introduced a bug in the adventurer function which I wrote about in refactor.c. The bug was to set the last while loop to continue to loop while z was greater than or equal to 0. It should actually be that it loops while z-1 is less than or equal to 0.