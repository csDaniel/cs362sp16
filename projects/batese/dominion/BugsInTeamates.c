/*
File: BugsInTeamates.c
Author: Elliot Bates
Description: In this document I will discuss the results of running my previously written unit and random tests. This did not require any refactoring of code and could be run against teamates code using just 
'make unittestresults.out', 'make randomtestadventurer.out', and 'make randomtestcard.out'. The tests test the following card implementations:
cardtest1 - adventurer
cardtest2 - smithy
cardtest3 - village
cardtest4 - council room
randomtestadventurer - adventurer
randomtestcard - village

==========++++++++++ TEAMATE 1 ++++++++++==========
// Bugs found in teamate 1 (pattejon) //
-cardtest1 revealed no bugs in my teamates code as all tests passed.
-cardtest2 revealed a bug in my teamates code. The tests failed show that there are too many cards in the players hand after the card has been played. Inspection of the code shows that
 this is caused by the adventurer card not being discarded after it is played.
-cardtest3 revealed a bug in my teamates code. The tests failed show that there is one too many cards being discarded from the players hand. Inspeaction of the code shows that discard is called twice; once
 in the playVillage function, and once again in the switch statment in cardEffect.
-cardtest4 revealed 2 bugs in my teamates code. The tests failed show that the player playing the card gains one too many cards. Inspection of the code shows that the for loop contains a <= instead of a <, causing it 
 to loop oine too many times. The other bug revealed was that other other player does not draw a card. Inspeaction of the code shows that the for loop for other players to pick up cards starts at i = 1 whereas it should
 start at i = 0;
-randomtestadventurer revelaed no bugs in my teamates code as all tests passed.
-randomtestcard revealed bugs in my teammates code. The code repeatedly fails tests relating to the number of cards in the players hand. This is due to discardCard being called twice. This bug also causes the failure of 
 another test; testing whether the top card from the players deck is actually added to their hand, and this card is sometimes discarded by the second call to discard card.


==========++++++++++ TEAMATE 2 ++++++++++==========
// Bugs found in teamate 2 (sibertc) //
-cardtest1 revealed a bug in my teamates code. The tests failed show that the player is gaining a card that is not a treasure, more specifically an estate card. Inspection of the code reveals that '|| cardDrawn == estate'
 is allowing estate cards to be counted as treasure in the function.
-cardtest2 revealed a bug in my teamates code. The tests failed show that the player is gaining one too many cards in their hand. Inspection of the code reveals that the for loop where the player draws additional cards contains 
 a <= instead of a <, leading to one too many cards being drawn.
-cardtest3 revealed a bug in my teamates code. Running the tests caused a segmentation fault. Inspection of the code revealed that 'drawCard(state->whoseTurn + 1, state);' contains an unnecessary +1, leading to the program
 sometimes attempting to make a player that does not exist draw a card.
-cardtest4 revealed a bug in my teamates code. The tests failed reveal that the player playing the card gains one too many cards. Inspection of the code reveals that the for loop where all other players draw a card also causes the 
 player to played the card to draw one additional card.
-randomtestadventurer revealed a bug in my teamates code. The tests failed show that the player is drawing cards that are not treasures. Inspection of the code reveals that '|| cardDrawn == estate' is allowing estate cards to be 
 counted as treasure in the function.
-randomtestcard revealed a bug in my teamates code. Running the tests caused a segmentation fault. Inspection of the code revealed that 'drawCard(state->whoseTurn + 1, state);' contains an unnecessary +1, leading to the program
 sometimes attempting to make a player that does not exist draw a card.
*/