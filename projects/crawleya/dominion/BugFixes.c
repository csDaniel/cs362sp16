Alisha Crawley-Davis
CS 362 Assignment 5
5/22/2016
BugFixes.c

********************************************************************************
Fix Bugs Your Teammates Found
********************************************************************************

********************************************************************************
Bug with Council Room Card
********************************************************************************
Bug #1 from swansonb:

doCouncilRoom() fails to draw correct number of cards
When player plays council room, that player has too many cards
and other players have not drawn a card.

There was a bug in the function (that I introduced):

In the loop where every other player is supposed to
draw a card,there is a bug in the conditional statement.

Original (with my bug):
for (i=0; i < state->numPlayers;i++)
{
  if (i == currentPlayer)
  {
    drawCard(i, state);
  }
}

I corrected the conditional statement so now the loop reads:
for (i=0; i < state->numPlayers; i++)
{
  if (i != currentPlayer)
  {
    drawCard(i, state);
  }
}

Note that this is not one of the cards that I had written a
test for earlier, so I wrote a unit test for the card. It
originally failed (in the same way my teammate's unit test
failed). After I fixed the bug, it passed.

********************************************************************************
Bug with initializeGame() function
********************************************************************************
Bug #2 from sakamosa:
Problem in initializeGame() function.
There is an error that gives the players an incorrect number
of cards. In a 2-player game, the first player is given 5 cards
while the second player is given 10 cards.

Note that this is not one of the functions that I had written a
test for earlier, so I wrote a unit test for the function. I was
unable to reproduce the error. I found that at the end of
the initializeGame() function, Player 1 had 5 cards in the hand,
5 cards in the deck, and 0 cards in the discard pile. All other
players had 0 cards in the hand, 10 cards in the deck, and 0
cards in the discard pile. I believe this is by design. During
the initializeGame() function, all players are given 10 cards into
their decks. Then 5 cards are drawn for the first player only. This
is because, when it is the next player's turn, that is when the five
cards will be drawn from that player's deck into that player's hand.

********************************************************************************
Bugs with Adventurer Card - #1
********************************************************************************
Bug #1 from sakamosa
Problem in cardEffect() function when adventurer card is played
sakamosa Bug 1C: An incorrect number of treasure cards were added to
the player's hand. We would expect 2 new cards but there are 3.
I also found this error (Bug #4 in bug1.c)

There was a bug in the function (that I introduced):
In the while loop where cards are drawn until there are two treasure
cards, I introduced an error in the conditional.

Original (with my bug)
while (drawntreasure <=2)

Fix:
while (drawntreasure < 2)

When I fixed this bug, my unit test still did not pass. In fact,
I was still getting the wrong number of treasure cards (see next bug)

********************************************************************************
Bugs with Adventurer Card - #2
********************************************************************************
I had introduced a second bug where in the refactoring, I just called
my function doAdventurer() but did not return from the cardEffect() function.

Original (with my bug):
case adventurer:
  doAdventurer(state, handPos, currentPlayer);

Fix:
case adventurer:
  return doAdventurer(state, handPos, currentPlayer);

When I fixed this bug, my unit test for the number of treasure cards passed.
Now sakamosa Bug 1C/my Bug #4 was taken care of.

********************************************************************************
Bugs with Adventurer Card - #3
********************************************************************************
sakamosa Bug 1B Current player's hand count should increase by 1
sakamosa Bug 1D Number of cards in current player's discard pile should
increase by 1
swansonb Bug #2 Player's hand contains same number of adventurer cards
I also had written a unit test for this and also found the wrong number
of adventurer cards in hand (Bug #4 in Bug1.c).

All three of these findings pointed to the same conclusion - the adventurer
card was not properly discarded, so was still in the player's hand. I added a
discard statement to the end of the function so that the adventurer card could
be discarded.

Original:
(no discard statement)

Fix:
discardCard(handPos, currentPlayer, state, 0);

When I fixed this bug, all of my unit tests for the adventurer card passed
(which included what my teammates had found).

********************************************************************************
Bugs with Adventurer Card - #4
********************************************************************************
sakamosa Bug 1A: The current player's deck count was reduced by 4 and not
by 3 as expected.

I was not able to reproduce this issue. In my unit testing, the player's deck
was reduced by the appropriate amount.

********************************************************************************
Fix Bugs that You Introduced
********************************************************************************

********************************************************************************
Bug with Smithy Card
********************************************************************************
My unit test on the Smithy card found a bug where there was one
more card than expected in the current player's hand (Bug #3 in
bug1.c).

I introduced a bug in the for loop so that 4 cards would be placed
in the player's hand, instead of three.

Original (with my bug):
for (i = 0; i <=3; i++)

Fix:
for (i = 0; i < 3; i++)

After this fix, my unit tests for the Smithy card all passed.

********************************************************************************
Bug with Adventurer Card
********************************************************************************
My teammates found all of the bugs that I had found with my
tests on the Adventurer card (see above for details). After 
fixing the bugs my teammates found, all of my unit tests for
the Adventurer card passed.

********************************************************************************
Bug with Village Card
********************************************************************************
My unit test on the Village card caught the bug I introduced
(Bug #5 in bug1.c). I expected the number of actions to 
increase by 2, but the bug I introduced made it only increase
by 1.

Original (with my bug):
state->numActions = state->numActions++

Fix:
state->numActions = state->numActions + 2

After I fixed the bug I introduced, my unit tests passed.

********************************************************************************
Bug with Great Hall Card
********************************************************************************
I had not originally written a unit test for this so I wrote
one. This caught the bug I introduced. I expected the number
of cards in the player's played card pile to increase by 1,
but it did not. The trashFlag in the call to discardCard
was set incorrectly.

Original (with my bug):
discardCard(handPos, currentPlayer, state, 1)

Fix:
discardCard(handPos, currentPlayer, state, 0)

After I fixed the bug I introduced, my unit tests passed.

********************************************************************************
Bug with Council Room Card
********************************************************************************
My teammates found all of the bugs that I had found with my
tests on the Council Room card (see above for details). After 
fixing the bugs my teammates found, and writing unit tests
for it, all of my unit tests for the Council Room card passed.

********************************************************************************
Fix Bugs My Other Tests Found
********************************************************************************
I wrote unit tests for numHandCards(), getCost(), and isGameOver()
and found no bugs.

I wrote a unit test for scoreFor() and found bugs #1 and #2,
which are discussed below.

I wrote unit tests for the smithy card, and found Bug #3,
which was fixed above.

I wrote unit tests for the adventurer card, and found Bug #4,
which was fixed above.

I wrote unit tests for the village card, and found Bug #5,
which was fixed above.

I wrote unit tests for the gardens card, and found Bug #6
and Bug #7, which is discussed below.


********************************************************************************
Fix Bugs My Other Tests Found - scoreFor()
********************************************************************************
My own Bug #1: The score for a player at the beginning of a
test game was incorrect.
My own Bug #2: The score for a player's deck in the middle
of a test game was incorrect.
These bugs were both related to one bug in the conditional
of a loop that loops through the deck:

Original
for (i = 0; i < state->discardCount[player]; i++)

Fix
for (i = 0; i < state->deckCount[player];i++)

After I fixed this bug, my unit tests for this function passed.

********************************************************************************
Fix Bugs My Other Tests Found - gardens
********************************************************************************
My own Bug #6: The number of cards in hand after gardens
was played was incorrect.
My Own Bug #7: The gardens card remained in the player's hand
after the turn was over.

Original:
(no discard statement)

Fix:
discardCard(handPos, currentPlayer, state, 0);

After I fixed this bug, all of my unit tests passed.

********************************************************************************
Discussion
********************************************************************************
Because my teammates sent me bugs on functions that I had
not tested, I wrote more unit tests in order to ensure that
I really took care of the bugs that they caught. Because of
this, the overall coverage of my tests increased a bit. After
Assignment 4, I was at 44.44% line coverage, but after I had
gone through all of my tests for Assignment 5, I had increased
to 45.71% line coverage.

Using GDB was helpful in debugging my code. It was especially
useful to look at the increment variable (i) in the
scoreFor() function. I stepped through and found that the 
function was incrementing through the deck incorrectly. That is
how I found the bug in that function.

All of the unit tests and random tests that I wrote for the
class now pass, which gives me some confidence in the code.

However, I still feel like there are lots of bugs in the code
that I missed (even in lines that were covered). And there is also
about half the program that I have not yet touched.

Overall, though, I am confident that this version of the program
is less buggy and more playable than what we started with at the
beginning of the quarter.