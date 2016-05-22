/***********************************
* Name: Trent Richardson
* Assignment 4 - BugsInTeammates.c
* CS362-400
***********************************/


Teammate 1:

Upon running my tests in my teammate's code, I found the following:

All of my unit tests that test card game functions passed.  I did not find any errors or bugs in that part
of my teammate's code.  However, upon running the card tests, not all of my tests passed.  The first bug
I found in my teammate's code was the Smithy card.  Upon closer investiagion, I found that the cards were
clearly not being drawn correctly and thus failing the tests (the discard was passing the test).
Upon opening my teammate's code and looking at the Smithy card function, I found that there is a conditional
statement that only draws cards when the next player number is greater than the number of players in the game.
If this statement is removed, the Smithy card function should perform as expected.  The second bug I found was in
testing the Adventurer card.  Upon a closer examination, I found that the player handcount and discard tests were failing.
After examining the code, I found that there is a conditional loop in the code that allows the player to continue to
draw cards as long as the handcount is greater than or equal to 0.  Because the player has cards in hand, the
player will continue to draw cards until every card is in the players hand.  If this loop condition is removed,
the card should function as expected.  Upon testing my teammate's Village card, I did notice that two tests were failing;
however, I could not fully determine why.  I believe there is an issue with this particular card test, as I could not
find any bug in a simple code review.  The same applies to my Salvager test.


Teammate 2:

Upon running my tests in my teammate's code, I found the following:

All of my unit tests that test game functions passed.  I did not find any errors or bugs in that part of
my teammate's code.  However, upon funning the card tests, not all of my tests passed.  The first bug I
found in my teammate's code was the Smithy card.  Upon closer investigation, I found that there appeared
to be an issue with the discard pile test.  The card was not being added to the discard pile.  After looking
over the code, it looks like the trash flag on the discard function in the Smithy card has been changed from 0
to 1.  I believe this is causing the issue.  The second bug I found was in the Village card.  Although my Village
test appears to always fail 2 tests (an issue in my code I believe), I did find an bug with this card that allows
the player to play 3 action cards instead of 2 action cards.  The main reason I found this was my code review, not
so much my card test.  I did not find any other errors in my teammate's code.

**Update:  I found that my Adventurer card test passed completely, which it should have not.  After looking closer,
I found that my Adventurer card test for gold and copper cards.  I also found that my teammate's Adventurer card code
only flags copper and gold as treasure.  I believe this is why all my tests are passing.  My teammate removed the
silver logic, and I never had the silver logic to begin with in my test.
