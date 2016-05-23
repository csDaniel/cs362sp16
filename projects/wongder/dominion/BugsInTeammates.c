//Derek Wong
//5/18/2016
//CS362

Teammate 1 - Tiffany Chiou

Smithy Card:
The hand count and deck count unit test failed. Your smithy card function is calling drawCard 4 times
instead of 3 times, so the current player is drawing an extra card.

Steward Card:
When player chooses choice 1 the played card does not go into the played pile.
When player chooses choice 2 the player gains 3 coins instead of 2 and the played card does not go into the played pile as well.
When player chooses choice 3 the played card count is 2 instead of 1.
In the steward card function you are adding +3 coin instead of 2.
The flag for the else statement should be 1 because they are trashed.
The flag for the discardCard at the very end should be 0 because it should be in the played pile.

Village Card:
No Bug

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Teammate 2 - Bryant Hall

Smithy Card: 
The unit test that I check for deck count and hand count failed. It looks like this failed because the for 
loop in your smithy function is wrong. Instead of calling the draw function 3 times you're calling it 6 times.

Council Room:
The deck count and hand count also failed in this function. The council room card lets the current player draw 4 cards
but you're calling the draw card function 8 times instead.

Village Card:
No Bug

Steward Card:
When the player chooses choice 2 they are suppose to gain +2 gold but instead 2 of their cards are trashed.
When the player chooses chooice 3 they are suppose to trash 2 cards but instead they gain 2 coins.
It looks like the if statement in your steward card function is incorrect.