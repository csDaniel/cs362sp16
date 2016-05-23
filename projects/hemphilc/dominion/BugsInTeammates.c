/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 5
 * May 22, 2016
 * BugsInTeammates.c
 */


/*********************** Teammate 1 Bugs (Cherie) ***********************/

/*
 * Title: smithy card draws too many cards
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Is it reproducible: Yes

 * Description:
 * ----------------
 * smithy card should only draw 3 cards. It currently draws 4.

 * Steps to Produce/Reproduce:
 * --------------------------
 * - Set current player's handCount and deckCount to arbitrary values.
 * - Set current player's hand and deck with arbitrary cards.
 * - Play smithy card.
 * - Assert current player's handCount incremented and deckCount decremented
 *   accordingly.

 * Expected Results:
 * ----------------
 * smithy draws 3 cards.

 * Actual Results:
 * --------------
 * smithy draws 4 cards.

 */


/*
 * Title: adventurer is greedy
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Is it reproducible: Yes

 * Description:
 * ----------------
 * adventurer attempts to draw 3 treasure cards instead of just 2.

 * Steps to Produce/Reproduce:
 * --------------------------
 * - Set current player's handCount and deckCount to arbitrary values.
 * - Set current player's hand and deck with arbitrary cards.
 * - Insert 3 treasure cards into the current player's deck.
 * - Play adventurer card.
 * - Observe all 3 treasure cards get drawn from the player's deck.
 * - Assert current player's handCount incremented and deckCount decremented
 *   accordingly.

 * Expected Results:
 * ----------------
 * adventurer card draws a maximum of 2 treasure cards.

 * Actual Results:
 * --------------
 * adventurer draws 3 treasure cards.

 */


/*
 * Title: council_room not drawing enough cards 
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Is it reproducible: Yes

 * Description:
 * ----------------
 * council_room card is short-changing itself and not drawing 4
 * cards for itelf.

 * Steps to Produce/Reproduce:
 * --------------------------
 * - Set current player's handCount and deckCount to arbitrary values.
 * - Set current player's hand and deck with arbitrary cards.
 * - Play council_room card.
 * - Assert current player's handCount incremented and deckCount decremented
 *   accordingly.

 * Expected Results:
 * ----------------
 * council_room draws 4 cards.

 * Actual Results:
 * --------------
 * council_room draws only 3 cards.

 */


/*
 * Title: council_room denies draw to other players 
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Is it reproducible: Yes

 * Description:
 * ----------------
 * After current player draws, all other players should draw exactly
 * one card before the cardEffect ends.

 * Steps to Produce/Reproduce:
 * --------------------------
 * - Play council_room card.
 * - Assert all players other than the current's handCount incremented 
 *   by 1 and deckCount decremented by 1.
 
 * Expected Results:
 * ----------------
 * All other players other than current player should draw exactly 1
 * card therefore decrementing their deckCount and incrementing their
 * handCount variables by 1.

 * Actual Results:
 * --------------
 * Current player draws 4 cards, and the turn ends. Other player's do not
 * draw any cards.

 */

/************************************************************************/



/************************ Teammate 2 Bugs (Minh) ************************/

/*
 * Title: smithy card draws too many cards
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Is it reproducible: Yes

 * Description:
 * ----------------
 * smithy card should only draw 3 cards. It currently draws 4.

 * Steps to Produce/Reproduce:
 * --------------------------
 * - Set current player's handCount and deckCount to arbitrary values.
 * - Set current player's hand and deck with arbitrary cards.
 * - Play smithy card.
 * - Assert current player's handCount incremented and deckCount decremented
 *   accordingly.

 * Expected Results:
 * ----------------
 * smithy draws 3 cards.

 * Actual Results:
 * --------------
 * smithy draws 4 cards.

 */


/*
 * Title: adventurer is greedy
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Is it reproducible: Yes

 * Description:
 * ----------------
 * adventurer attempts to draw 3 treasure cards instead of just 2.

 * Steps to Produce/Reproduce:
 * --------------------------
 * - Set current player's handCount and deckCount to arbitrary values.
 * - Set current player's hand and deck with arbitrary cards.
 * - Insert 3 treasure cards into the current player's deck.
 * - Play adventurer card.
 * - Observe all 3 treasure cards get drawn from the player's deck.
 * - Assert current player's handCount incremented and deckCount decremented
 *   accordingly.

 * Expected Results:
 * ----------------
 * adventurer card draws a maximum of 2 treasure cards.

 * Actual Results:
 * --------------
 * adventurer draws 3 treasure cards.

 */


/*
 * Title: mine card knows no bounds 
 * Class: Serious Bug
 * Date: 5/21/2016
 * Reported By: Corey
 * Is it reproducible: Yes

 * Description:
 * ----------------
 * mine card accepts card enumerations less than curse (0) and greater than
 * treasure_card (26) as choice2 of cardEffect() function call.

 * Steps to Produce/Reproduce:
 * --------------------------
 * - Insert values less than 0 and greater than 26 as choice2 in cardEffect
 *   function call.
 * - Observe that mine card does not return -1 for card enumerations less 
 *   than curse and greater than treasure_card.

 * Expected Results:
 * ----------------
 * mine card should fail and return -1 for card enumerations outside the 
 * accepted domain (0 - 26).

 * Actual Results:
 * --------------
 * mine card does not fail and accepts card enumerations outside the card 
 * enumeration domain of 0 - 26, returning 0.

 */

/************************************************************************/

