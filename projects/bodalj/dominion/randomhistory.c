/*************************************************************************************************************
 * Filename: randomhistory.c
 * Author: Jens Bodal
 * Date: May 08, 2016
 * Description: 
 ************************************************************************************************************/

# Random Testing of Adventurer Card

		randomtestadventurer.c

		Adventurer effect: Draw cards until 2 treasure cards drawn into hand; discard non-treasure cards

The random tests resulted in the following test coverage in dominon.c for the playAdventurer function

		Function 'playAdventurer'
		Lines executed:100.00% of 18
		Branches executed:100.00% of 12
		Taken at least once:100.00% of 12
		Calls executed:100.00% of 2

Our tests needed to ensure the following:

* Check that drawing silver, gold, and copper cause original hand size to only change by two
* Check that drawing non-treasure cards are discarded
* Check that if deck is empty we will shuffle discard and gain two treasure
* Check that different players can all play adventurer card properly
* Check that random seeds don't affect the outcome of the tests
* Check than random combinations of treasure cards being used don't affect how adventurer plays

The game was ran over 50 iterations with random players, random seeds, and random treasure cards. We see that the
adventurer is not being idscarded after being played and that an incorrect number of treasure cards are drawn after 
playing adventurer. These were bugs that I introduced. 

The player is printed to the screen as well as the result of the test to help track which combination of
random input would lead to test success.  

The adventurer card did not gain two treasure cards, was not discarded properly, and seems to be affected
no matter the combination of treasures used.

**Bugs Found**

* Adventurer is not discarded
* Incorrect number of treasure cards is drawn after playing adventurer


# Random Testing of Village Card

    randomtestcard.c

		Village effect: +1 Card +2 Actions

The random tests resulted in the following test coverage in dominion.c for the playVillage function

		Function 'playVillage'
		Lines executed:100.00% of 5
		No branches
		Calls executed:100.00% of 2

Our tests needed to ensure the following:

* Check that we drew only 1 card
* Check that we gained only 2 actions
* Check that the card was discarded
* Check that numBuys is the same
* Check that random seeds don't affect outcome
* Check that different players can all play card
* Check that game state remains intact after playing village card

The game was ran over 50 iterations with random players and random seeds. We tested the affects of the card
with each player and with various seeds.  The output showed a bug that the village card was not being discarded
but that it would happen no matter which player was playing the card.  

This test would help track if other players could have an affect on other players playing the village card, and
it helps show the bug that I introduced where the card is not properly being discarded.

## Bugs Found

* The village card is not properly being discarded (this was a bug I introduced)
