/******************************************************************
 * Carolyn Cheung
 * CS 362
 * Assignment 5
 * Description: Bug fixes to dominion.c
 ******************************************************************/

smithy bug fixes:
    found: Deck count was not the correct amount, 1 less than what was expected.
    fix: Went through the code line by line in GDB. When I foudn out that all the values
        were correct, saw that the code did not break out of the switch statement at
        the correct time. Added 'return 0' after all card call functions.
        
adventurer bug fixes:
    found: deck count and hand count are not the correct amount
    fix: changed drawnTreasure, which is initialized in playAdventurer(), from 1 to 0
    
council room bug fixes:
    found: Hand count and deck count are not the correct values
    fix: Going through in GDB, found out only currently player draws cards, not any other
    player. Fixed bug that makes sure it is NOT just the currently player drawing a card.
    
great hall bug fixes:
    found: p0 played count is not what is expected.
    fixed: fixed cardtest4.c to check gamestate playedCardCount instead of playedCards[]. changed
    drawcard changed from always drawing for player 0 to drawing for current player.
    
unittest4:
    found: Did not properly calculate how many cards were in the player hands. Changed it to
    use built in function to calculate the cards in the player hand
    
dominion.c
    found: Forgot to include the return statement after changing certain cards to
    functions.
    fix: added return statements, code executes properly and breaks off after finishing
    the card's actions.
    
GDB was a very useful tool in finding bugs within my own code. I had unknowningly forgotten
to update my git repository's dominion.c to include the return 0 statements after refactoring the code
to include functions for certain action cards. I used GDB to go through line by line and discovered
that my code was running fine, until it finished the function and went on to do something else.
Coverage was useful too, but I felt it was not as useful as it could have been because
the tests we wrote only cover one certain card, and each card is in the dominion.c file, so the file is
huge. We can only cover a small portion of it, so I think it would be better to split dominion.c
up into further individual files per card, in order to properly determine how much of each card's
actions were covered.