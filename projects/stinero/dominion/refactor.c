/*

Added a function definition for for Smithy named "Smith Play" int he dominion.h file

Added a smithy function to dominion.c
This function will first check to see if the hand has enough cards to draw for the smithy. If it doesnt
it will draw enough cards to be used.
After this, it will discard the Smithy and return a "0"
There is a major bug/logic error here.

int adventurerPlay(int currentPlayer, int handPos, struct gameState *state);

Primarily used a very similar implementation of the adventure card.
I added a few bugs to the implementation to screw everything up.
Implementation took function from switch statement and added into own function
I still use a while loop to find out when enough treasure has been drawn and add a way to break out of an infinite loop
I use a for loop to discard cards from temp hand to discard pile.
There is a bug here.


Remodel
There is a bug in the original implementation of the remodel card. I have kept the code as is.
The bug is in relation to how the card is trashed.
I moved the logic from above into its own function, below.
it makes a note of the store card to be trashed(choice1) and makes sure that it fits within the cost of choice 2 before putting
the selected card in the deck and then discarding the trash card.


Baron:

The code before implemented the discard function. I cleaned it up and used the function already had.
card_not_discarded is a boolean to see if it goes through (as if it doesn't it will have to draw an available estate.).
At this point it checks to see if the choice is not 0 (give up an estate for money) or  if  the card has not been discarded.
This card is implemented correctly with no bugs.



Sea_Hag

Sea Hag is re-factored to use the function "discard Card"
I have it so it will do a for loop for all the players and an if statement that will discard the top card from the deck of the person.
It will then replace it with a curse card.
The error here is it does not take into account what to do if a person doesnt have a card in their hand.


 * */