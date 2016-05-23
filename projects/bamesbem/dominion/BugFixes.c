/*
Michael Bamesberger
BugFixes.c
Assignment 5
May 22, 2016
 

Martha Gebremariam:
 
Using both random and unit tests Martha found bugs in my adventurer,
 smithy and village cards.
 
 -------  Adventurer -----------
In the adventurer card, her tests found that my
function did not draw the correct number of cards.
 
This bug is one I introduced into my program originally. Instead
of incrementing the drawnTreasure variable by 1, my bug caused
the variable to be incremented by two. 
 
Fix: 
 Inside a while loop, nstead of the line: 
 drawntreasure = drawntreasure + 2, I will change it to
 drawntreasure++;


--------- Smithy --------------
 In the adventurer card, Marth found that my function
 draws one too many cards.
 
 This is a bug I introduced at the beginning of the class.
 I inserted an unneccesary statement that forces another card
 to be drawn.
 
 if (state->deckCount[currentPlayer] > 1){
 drawCard(currentPlayer,state);
 }
 
 Fix: The statement was removed.
 

--------- Village ---------------
 In the village card, Martha's test found that my function
 actually decrement the player's numActions by 1 instead of
 increments it by two.

This is a bug I introduced at the beginning of the class.
 I changed the statement:
 state->numActions = state->numActions + 2 to:
 
 state->numActions = state->numActions - 1
 
 Fix: The -1 at the end of the statement was changed to +2
 

Evan Rechsteiner:
--------- Makefile --------------
 Evan actually found a bug inside my makefile. For cardtest4,
 my code in the makefile actually ended up compiling cardtest1 again.
 Therefore, cardtest4 was not running. 
 
 This is an error I was not previously aware of.
 
 Fix: I replaced cardtest1.c in the cardtest4 makefile line with 
 cardtest4.c


 ------- Smithy ----------------
Evan also found an error in my smithy card. He claimed my function did not
 discard cards back into the deck. I believe he is mistaken about how the
 discardCard function works. As I understand it, the cards are not actually
 dicarded until the end of the turn. So therefore, this would not actually
 be a bug.




*/