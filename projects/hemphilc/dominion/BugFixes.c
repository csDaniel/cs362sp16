/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 5
 * May 22, 2016
 * BugFixes.c
 */


/*********************** Fixed Bugs (dominion.c) ***********************/

/*
 * Title: Incorrect variable usage in smithy
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * smithy card incorrectly used handPos as the passed in variable
 * to drawCard function instead of correctly using currentPlayer.
 * As a result, drawCard function is drawing cards to the wrong
 * players, and potentially to invalid player values. I swapped 
 * the variables.

 * Expected Results:
 * ----------------
 * smithy draws cards to the current player.

 * Actual Results:
 * --------------
 * smithy now correctly draws cards to the currentPlayer.

 */


/* 
 * Title: smithy discards the wrong card
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * smithy discards the card before it in the current player's
 * hand when played instead of discarding itself. I removed the -1
 * from discardCard(handPos - 1, ...) statement. 

 * Expected Results:
 * ----------------
 * smithy discards itself when played.

 * Actual Results:
 * --------------
 * smithy now discards itself when played.

 */


/*
 * Title: adventurer does draw enough treasure cards
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Minh
 * Fixed By: Corey

 * Description:
 * ----------------
 * adventurer card is only drawing 1 treasure card from the current
 * player's deck instead of trying to draw 2. When a treasure card
 * is found, the counter is increased by two, thus ending the loop
 * after only finding 1 treasure card. I fixed the count statement
 * to count by 1 instead of 2.

 * Expected Results:
 * ----------------
 * adventurer draws 2 treasure cards from current player's deck.

 * Actual Results:
 * --------------
 * adventurer draws up to two treasure cards from the current
 * player's deck.

 */


/* 
 * Title: adventurer does not discard itself when played
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Cherie
 * Fixed By: Corey

 * Description:
 * ----------------
 * adventurer card fails to discard itself from the current
 * player's hand when played. I added the missing discardCard()
 * function call statement to the end of adventurer.

 * Expected Results:
 * ----------------
 * adventurer discards itself after being played.

 * Actual Results:
 * --------------
 * adventurer now discards itself after play.

 */


/* 
 * Title: adventurer temphand assignment is off by 1
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * When adventurer places a card into the current player's temporary 
 * hand, it does so at the wrong position. If the temphand is empty,
 * adventurer places the new temphand card at index position 1 instead
 * of 0. I removed the + 1 from the temphand[z + 1] = ... assignment 
 * statement.

 * Expected Results:
 * ----------------
 * adventurer should place new cards into the temphand beginning at 
 * index position 0.

 * Actual Results:
 * --------------
 * adventurer now places cards into the temphand at the correct 
 * positions.

 */


/* 
 * Title: village fails to do book keeping
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Minh
 * Fixed By: Corey

 * Description:
 * ----------------
 * village card fails to transfer the current player's new card from
 * the deck to the hand. This is actually a bug within the drawCard()
 * function, not village card directly.

 * Expected Results:
 * ----------------
 * When played, village card properly adds 1 to hand, removes 1 from 
 * deck.

 * Actual Results:
 * --------------
 * village card makes the proper call to drawCard() function, however,
 * the drawCard() function is currently bugged and does not perform
 * the necessary book keeping.

 */


/*
 * Title: Incorrect variable usage in village
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * village card incorrectly used handPos as the passed in variable
 * to drawCard function instead of correctly using currentPlayer.
 * As a result, drawCard function is drawing cards to the wrong
 * players, and potentially to invalid player values. I swapped 
 * the variables.

 * Expected Results:
 * ----------------
 * village draws cards to the current player.

 * Actual Results:
 * --------------
 * village now correctly draws cards to the currentPlayer.

 */


/* 
 * Title: village discards the wrong card
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * village discards the card before it in the current player's
 * hand when played instead of discarding itself. I removed the -1
 * from discardCard(handPos - 1, ...) statement. 

 * Expected Results:
 * ----------------
 * village discards itself when played.

 * Actual Results:
 * --------------
 * village now discards itself when played.

 */


/* 
 * Title: feast is way too generous 
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * feast should update the current player's coin coint by 5. feast
 * currently updates the current player's coin coiunt by 10. I
 * fixed the number of coins to be updated in the updateCoins() 
 * function call to be 5 instead of 10.

 * Expected Results:
 * ----------------
 * feast gives the current player 5 coins.

 * Actual Results:
 * --------------
 * feast now gives the player the correct number of coins.

 */


/* 
 * Title: feast is a cheap-skate 
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * feast card returns "card is too expensive" when in actuality, it
 * is not. The state->coins variable is being decremented by 1 for no
 * apparent reason. I fixed by removing the -1 from the conditional 
 * statement that compares current state->coins to the cost of the 
 * player's choice.

 * Expected Results:
 * ----------------
 * feast should not fail if the state->coins is more than the cost of
 * the player's card choice 

 * Actual Results:
 * --------------
 * feast no longer fails the comparison state->coins > getCost(choice1)

 */


/* 
 * Title: feast favors player 1 
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * feast card only gains cards for player 1 rather than for the current
 * player. I fixed by changing the value 1 from the gainCard() function
 * call to currentPlayer so that it always updates for the current
 * player and not just player 1.

 * Expected Results:
 * ----------------
 * feast gains a card for the current player.

 * Actual Results:
 * --------------
 * feast now gains a card for the current player.

 */


/* 
 * Title: feast does not discard itself when played
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * feast card fails to discard itself from the current
 * player's hand when played. I added the missing discardCard()
 * function call statement to the end of feast.

 * Expected Results:
 * ----------------
 * feast discards itself after being played.

 * Actual Results:
 * --------------
 * feast now discards itself after play.

 */


/* 
 * Title: remodel only gains cards costing 1 more than trashed 
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By:
 * Fixed By: Corey

 * Description:
 * ----------------
 * remodel should gain cards that cost up to 2 gold more than
 * the card that the current player chose to trash. Currently,
 * it only gains cards that cost 1 gold more than the trashed
 * card. I fixed it by adding 2 to the card value of the 
 * player's choice of card to trash rather than 1. 

 * Expected Results:
 * ----------------
 * remodel should gain cards costing up to 2 more gold than
 * the card that was just trashed.

 * Actual Results:
 * --------------
 * remodel now gains cards costing up to 2 more gold than the
 * trashed card.

 */


/* 
 * Title: remodel gains the incorrect card 
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By:
 * Fixed By: Corey

 * Description:
 * ----------------
 * remodel is not gaining the current player's chosen card. I fixed
 * it by changing the variable passed into gainCard() function call
 * from choice1 to choice2.

 * Expected Results:
 * ----------------
 * remodel gains the current player's chosen card.

 * Actual Results:
 * --------------
 * remodel now correctly gains the chosen card.

 */


/* 
 * Title: remodel discards the wrong card
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * remodel discards the card before it in the current player's
 * hand when played instead of discarding itself. I removed the -1
 * from discardCard(handPos - 1, ...) statement. 

 * Expected Results:
 * ----------------
 * remodel discards itself when played.

 * Actual Results:
 * --------------
 * remodel now discards itself when played.

 */


/* 
 * Title: remodel doesn't take the trash out
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Fixed By: Corey

 * Description:
 * ----------------
 * remodel does not trash the proper card from the current player's
 * hand. I fixed by changing the argument passed into discardCard()
 * function call in the bottom for loop from choice2 to i so that
 * the card is trashed from the correct spot on the correct iteration
 * through the loop.

 * Expected Results:
 * ----------------
 * remodel trashes the current player's chosen card to trash.

 * Actual Results:
 * --------------
 * remodel now properly disposes of the chosen card.

 */

/***********************************************************************/
