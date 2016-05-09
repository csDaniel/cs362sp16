/*Brianna Carter
Assignment 4
5/9/16

	The cards being tested are Adventurer and Smithy. First thing I did was
figure out what things I should be looking for in my tests. Playing Adventurer
allows the player to draw from his or her deck until they find two treasure cards.
The player then adds those two treasure cards to his or her and and then discards the
other cards that were drawn. Knowing this I saw that the only things that change are 
the current player's hand count, the player's card played pile, the player's deck count,
and the total number of coins the player has. I test to make sure these changes occur 
and make sure no changes occur where they shouldn't. The other player's hands shouldn't change
and the number of cards in the supply piles shouldn't change. 

	Smithy allows the player to draw three cards from his or her deck and place them in 
his or her hand. Following the same process as the Adventurer card I see that the player's 
hand count and deck count are the only two things that should change. So I have tests that 
make sure the player only draws three cards and the other player's cards and the supply 
cards don't change.

	I decided to create a completely random game environment for both of my tests. So before 
the card is played, I randomly generate values for the number of players, deck size, hand 
size, player hand count. To be sure I am comparing the values correctly, I copy the game 
state and manually manipulate one while the other is passed into the card effect function.

	I used the f and b flags with gcov to get both branch and function summaries. At first glance
it doesn't seem like the coverage is very high but since each file is only testing one card, 
most of the functions in dominion.c aren't called. 

randomtestadventurer.out: Run tests 1000 times

	When testing the adventurer card, two tests failed every time: Checking coin amount, the 
bug I introduced causes the coin cards not to be added to the player's hand so the values
never match what is expected and the . The second failure is when checking if the Adventurer card 
is placed in the played pile. Another bug I introduced prevents it from being discarded. 
All other tests pass.

COVERAGE FOR DOMINION.C RUNS 1000 TIMES:
File 'dominion.c'
Lines executed:27.27% of 572
Branches executed:27.45% of 419
Taken at least once:19.57% of 419
Calls executed:15.84% of 101

	In the test files I call card effect with the adventurer and smithy cards and those
switch statements only have one line, the call to playAdventurer() and playSmithy(). 
Looking at lines executed, the value seems very low but when you understand 
only two of the cases are being tested, that means over a quarter of the code is executed
by only testing two cards. There are 20 action cards in the game so Smithy and Adventurer
make up 10% of the cards. 

	The playSmithy() test is affected by the bug I created. I made it so the cards are only added
if the current player is the last in the list. This gives the function only had 50% branch coverage 
because the player is never the last player in the array, meaning the for loop never executed. This 
means the cards are never added to the player's hand. Adding a layer of randomness to the test would
solve this issue. If the current player number was randomized, there would be some cases where the 
for loop would execute, increasing the branch coverage to 100%.

	The playAdventurer() functiton had 100% coverage across the board which shows that the shuffle 
function is called at least once. Examining the gcov results further, the shuffle function is called 3% 
of the time. This coverage can be improved by increasing the number of times the test is run. If we need 
to see that branch taken more often, this would be the best solution. 