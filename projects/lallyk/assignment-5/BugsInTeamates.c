/*
Kara Franco
Assignment #5 Part 1
Due Date: May 22, 2016

---- Sam Nelson (nelsons3) Bug Report ---

Bug #1: Sam’s refactored dominion.c failed my card test #1 test for adventurer(), which tested if adventurer() card gave 
player 2 new treasure cards. Upon looking at Sam’s results from this test, and reviewing his refactored function, his 
adventurer() card is returning the player 3 treasure cards.  

Bug #2: Sam’s refactored dominion.c failed my card test#2 test for smithy() which, tested if smithy() card removed 3 cards 
from the deck. Sam’s results from this test show that the cards are not correctly removed from the deck (compared to what 
the expected behavior is of the smithy()) .   

Note: I had to change my dominion.h to match Sam’s in order to compile and run my card tests for him. The reason why was 
because I did not alter my header function declarations, playSmithy, playAdventurer or playVillage. I simply changed the 
header function declarations to match his (with parameters, and naming) and then the test compiled. 


--- Rosa Tung (tungr) Bug Report ---

Bug #1: Rosa’s refactored dominion.c failed my card test #2 for adventurer(), which tested if adventurer() card gave player 
2 treasure cards. This was a tricky bug to understand. Rosa did not alter the adventurer() function. After running through her 
dominion.c I realized that the break; statement after adventurer() was removed. This appears to have at trickle down effect to 
the behaviour of the other cards. What I suspect is that the removal of break makes the card counts inaccurate. 

Bug#2: Rosa’s refactored domonion.c failed my card test #1 test for adventurer(), which tested if adventurer() card removed 2 
cards from the deck. Like above, this was a tricky bug to understand. Rosa did not alter the adventurer() function. After running 
through her dominion.c I realized that the break; statement after adventurer() was removed. This appears to have at trickle down 
effect to the behaviour of the other cards. What I suspect is that the removal of break makes the card counts inaccurate. 

Note: Rosa’s refactored dominion.c did not cause any compiling issues. I did not have to change any of my files or Makefile. 

*/