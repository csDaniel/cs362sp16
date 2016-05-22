/**************************************************************************************************
* Mark Rushmere
* CS 362
* Assignment 5
**************************************************************************************************/

/*************************************************************************************************/
// Bugs found in Rob Stine's code

BUG 1 (Adventurer)

DESCRIPTION:
This bug was found by the cardtest2.c. The 5th test failed which checks the case that the
adventurer card is played when there is only one treasure card in the deck. 

STEPS TO REPRODUCE:
NOTE: Assumes tests and makefile written Mark Rushmere and dominion.c file modified by Robert
1. Compile all files by running "make all"
2. Run "cardtest2"
3. Check test 6

FIX:
In the function "adventurerPlay" there is a while loop that continues until the treasuredrawn variable
is greater than or equal to 2. If there is only 1 treasure card in the deck, than this will fail.




/*************************************************************************************************/



//Bugs found in Saie Kurakula's code
BUG 1 (Smithy)

DESCRIPTION:
This bug was found by cardtest1.c. The first test failed which checks to see if the correct
number of cards were drawn. There were 8 hands in the players hand after the card was played,
when 7 cards was expected.

STEPS TO REPRODUCE:
NOTE: Assumes tests written by Mark Rushmere and dominion.c file modified by Saie.
1. Compile all tests by running "make all".
2. Run cardtest1 
3. The first test in this set tests that the correct number of cards is drawn
4. After the card is played there are 8 cards in the players hand and only 7 are expected.

FIX:
In the function playMySmithy there is a for loop that starts with i=0 and 
goes to i <=3. This causes 4 cards to be drawn and shoudl be changed to 
i < 3

BUG 2 (Village)

DESCRIPTION:
This bug was found by cardtest4.c The first test failed which checks that one card was drawn.

STEPS TO REPRODUCE:
1. Compile all tests by running "make all".
2. Run "cardtest4"

FIX:
In the function playMyVillage there is a duplcate call of the drawcard() function that shoudl
be deleted.

