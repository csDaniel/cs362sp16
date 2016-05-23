/******************************************************************************

Bug 1: Minion Card 
  - Choice 1 and Choice 2 were swapped
       This bug is a low priority, since it is easy to play the game with
       the code as is, as long as the players know that the choices are swapped
       and play accordingly.
     FIX: swapped the variables in the if / else if statement to put the 
          appropriate chioce in the correct statement.

Bug 2: Smithy Card
  - Trash flag set when it should not be and only two cards added. 
      This bug is a medium priority since the player gets to draw one card
      less than they should for the card, giving the card less benefit in
      the game.
    FIX: trash flag set to 0 to indicate a discard. For loop set to start at 0
         instead of 1, so that three cards are drawn instead of two.

Bug 3: isGameOver()
  - Game is not ended if one of the empty supply piles is Sea Hag or Treasure
    Map, positions 25 and 26 in the dominion.h CARD enum.
      This bug is a medium priority since there small chance that one of these 
      two cards supplies will be empty and the game will continue when it should
      end (1/27 chance for each card).
    FIX: change for loop that loops through all of cards checking if three
         supply piles are empty to loop from 0 through the last card 
         (treasure_map). 

Bugs 4 - 7: Adventurer Card
  - All cards in hand are discarded
			This bug was a high priority since it affected other cards in the player's 
			hand by discarding cards at the incorrect.
  - Treasure cards are not added to the hand
      This bug is a medium priority since it means the card does not have the
      desired effect when it is played.
  - Played cards is not incremented when there are cards in the hand
  - Played cards is increased too much if the card is played with an empty deck. 
    FIXES:
      - Set if statement to check for all three types of treasure cards instead 
        of just copper and silver. Gold was previously missed.
      - Set the index for the cardDrawn variable so that it is pulling the most
        recently drawn card instead of the secondd most recently drawn card.
        state->handCount[currentPlayer - 1] instead of [currentPlayer - 2]. 
      - Changed function adventurerEffect() to also take the position of the 
        current card (the adventurer card that is being played) so that it is
        discarded. 

  After reading about how this program is supposed to work on Piazza, I realized
  that my tests were set up incorrectly. Based on discussions on Piazza it seems
  like the intent is for cards to be moved into the played card pile until the
  end of the turn, at which point they are moved into the discard pile. This 
  means that the results of my tests still say this card fails although the 
  discard has been fixed.

  Similarly this means that the unit tests run on the discardCard() function
  were not giving the correct results. 

Having thorough test coverage and easily maintainable tests made this assignment
straightforward. In order to run my tests against my teammates' code, I only
had to make a few changes to the names of function called and in one case add
a variable. This made the refactoring portion of the assignment very easy.
