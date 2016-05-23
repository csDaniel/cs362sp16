/****************************************************************************
Author: Kelby Faessler
Class: CS362
Assignment: #4, part2

============================================================================
-------------------             Bug Fixes:            ---------------------
============================================================================
Bug Description: smithy card results in net hand increase of 3 cards when
   increase of 2 is expected.
Reported by: teammate ohaverd
Fix: I found this bug by looking at the smithy card implementation. In the
   implementation it loops for an incorrect number of times in the for loop.
   Inside the for loop, it calls drawCard so however many times are looped
   is how many cards will be drawn. I changed the number of times the loop 
   will go and this fixed the issue. 

Bug Description: council room card does not have the expected result of a 
   net increase of 3 cards (4 drawn, 1 discarded).
Reported by: teammate ohaverd
Fix: There were two issues here. First, the councilRoomCardEffect() function
   that I created when I refactored some of the dominion card effects was
   not being called from the main cardEffect() function. That was an easy
   fix to just call the councilRoomCardEffect() function in the correct
   spot within the cardEffect() switch statement. The second problem was
   that this card should have the current player draw 4 cards and discard 1
   card. Those two things were happening correctly, but a secondard effect
   of the card is to have all other players draw 1 card. It loops over all
   the players in the game to have each of those players draw a card, but 
   it doesn't check to make sure the player drawing the card isn't the 
   current player (since we already drew the necessary 4 cards for the 
   current player). I added a check to make sure the current player didn't
   end up with this extra card and that completes the fixes for this bug.

Bug Description: adventurer card does not result in treasure being added to
   current player's total.
Reported by: teammate stramelm
Fix: This took some investigation because the bug report does correctly find
   that something is wrong, but it doesn't report the root cause. The problem
   is that, while the adventurer card DOES add treasure for copper and silver,
   it DOESN'T add treasure for gold. The gold check was missing from a 
   conditional statement. Once that was added back in then the bug was 
   corrected.

Bug Description: isGameOver() does not always return the correct result. In
   other words, in certain cases it should detect a game over state and it
   does not.
Reported by: teammate stramelm
Fix: The isGameOver() function loops over all of the cards to figure out how
   many of them have 0 left. If it finds that at least 3 different cards have
   0 left then the game should end. The problem is the loop doesn't actually
   loop over all the cards. So, I updated the loop bounds so that all cards
   would be taken into consideration and this fixed the problem.

Bug Description: great hall card adds too many actions to the current player's
   hand.
Reported by: myself
Fix: in the greatHallCardEffect() function add's actions to the current state.
   It was adding the wrong number of actions in that statement, so changing
   it by reducing the number of actions being added from 2 to 1 fixed the bug.

Bug Description: steward card not adding 2 cards for choice 1 and not adding
   2 coins for choice 2.
Reported by: myself
Fix: the steward card offers the player a choice between 3 different outcomes.
   The problem here was that choice 1 and choice 2 were mixed up. The
   outcomes necessary for choice 1 were happening when choice 1 was picked, 
   and vice-versa. Simply reversing these sets of statements fixed the bug.

General thoughts: I didn't have to rely on code coverage to help me very much
   because the bug reports were very specific and the code involved was 
   neither long nor complicated. Therefore, it wasn't much trouble to locate
   the defect in the code and fix the bug.

============================================================================


*****************************************************************************/