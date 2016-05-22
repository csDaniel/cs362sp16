/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Ellard Gerritsen van der Hoop
** File:  BugsFixes.c
**
** Description:  This file discusses the
** process of fixing the bugs that I introduced into the dominion
** source code as well as what my teammates found
*************************************************************/

********Teammate 1 Reported Bugs - Shawn Seibert***************
Incorrect amount of cards drawn when Smithy is played
Adventure Card does not draw the correct number of treasures

********Teammate 2 Reported Bugs - Suyana Lozada****************
Player draws 2 cards instead of 3 cards when drawing the smithy card.
Player does not draw two treasury cards when drawing adventurer card.

/*************************************************************
Bug #1 Fix - Smithy Card not adding enough cards


My own test suite as well as the testing done by my teammates
showed that the smity card was acting incorrectly. The Smithy card
effect is resulting in too many cards being added to the current player.
The test results show that there is an off by 1 error in terms of
expected handCount and tested handCount after the smithy card
has been played.

Using GDB and debugging, I realized that the for loop was only
going through 2 iterations instead of the 3 its supposed to.
Of course this was the code that was originally refactored though so
this makes sense.




Test Results after Change:
	Number of cards Drawn: 7    Expected: 7       PASS

Interestingly enough there is still a bug occuring that I can not fully
explain. I tested the amount of cards played per turn and it always ended
up being incorrect before and after the bug fixes. It seems to say that there
are two cards being played when the smithy card effect happens which makes no sense.
The variable "playedCardCount" is reset to a 0 on a turn and is increased only when
discardCard function is called with the trash flag set to less than 1.

For the rest though, the smithy unit test passed.


Coverage:
Function 'SmithyCardEffect'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

100% coverage is pretty good so I am feeling a bit more confident
about my unit tests.
*************************************************************/




/*************************************************************
Bug #2 Fix - Adventurer card is not counting silver cards as a drawn treasure
Description:


The adventurer card was particular interesting in relation to the
tests performed on it. After performing my testing and my teammates testing,
it appears that the adventurer card might have some inherent bugs that
were not introduced when we refactored it. And I am honestly not sure
how to fix it without changing perhaps how some of the other functions work.

To illustrate my point, my unit test at one point looks at the hand of the non-current
player. Their deck count is for some reason being changed by 1 even though nothing should
be manipulated when its not their turn. In addition to this it appears that their hand count is also
increasing by one when its not their turn.

When I originally refactored the adventurer card I made it so that the silver card wouldn't be counted as
 a drawn treasure. However, this type of bug is hard to track since it doesn't necessarily break the game. However,
since I already have first hand knowledge since I introduced this bug it was easier to track with GDB. Thus using
 the debugger I noticed that it was skipping silver cards.  So I fixed that back to what it should have been.
 For the current player there is also still the issue of an incorrect hand count.
 I think the issue is that there is no call to discardCard() to remove the card from the current hand. It does perform its own form
 of removing cards that were drawn during the drawnTreasure cycle but I don't believe its effective for this.



Coverage:
Function 'adventurerCardEffect'
Lines executed:78.68% of 19
Branches executed:66.67% of 12
Taken at least once:50.00% of 12
Calls executed:100.00% of 1


In summary of this unit test, I don't honestly have much faith in it.
And honestly I don't think I will be satisfied because there is just something
off about the adventurer card in the first place. The hand count issue is a big
concern since it seems to not want to follow the rules of the card. My random testing
backs this up as well. When I randomly tested the adventurer card, all iterations had
an issue with the hand count. I suppose there are some ways to improve my test though for
the future. For instance, maybe I should look into tracking the treasure cards more carefully
and setting up test cases that have specific hand compositions.


*************************************************************/


/*************************************************************
Bug #3 Fix - Feast Card is allowing too many cards to be bought



The feast card wasn't a card that I personally performed tests on but
it was one of the cards that were refactored into being totally incorrect.
When I refactored I made a change in a variable and a while loop that would
cause issues.

Looking with the debugger, I noticed that the number of cards being bought
when the feast card effect occured was incorrect. Comparing the original dominion
source code with mine made me remember that I changed

CORRECT:

x = 1;

while (x == 1)


to


INCORRECT:

x = 2;

while (x >= 0)


Thus two cards were being bought. This was a pretty easy fix and the card seemed
to act appropriately after cleaning it up.


*************************************************************/


/*************************************************************
Bug #4 Fix - Great Hall card is not being discarded after use


The Great Hall card was another card that I refactored the code for
but did not personally test in the assignments up to this point. However,
I decided to write a little mini test just for the sake of justifying
the reason to fix this card effect.

When I originally refactored the card, I removed a certain line from the source
code.

The line:
	discardCard(handPos, currentPlayer, state, 0);

Essentially my test showed that I was gaining an extra card which was correct,
I was getting an increase in the number of actions which was correct, but my hand count
was off. This hand count issue of course was the discardCard function not being called to remove
the used great hall card.

Coveage:
Function 'testGreatHall'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

There isn't a lot of code that goes with the great hall card.
So getting 100% coverage was not difficult. I feel pretty confident
in the testing of this card.


