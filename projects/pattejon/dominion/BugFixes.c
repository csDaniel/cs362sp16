/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 5
* BugFixes.c
* Discussion of Bugs found in my code
*----------------------------------------------------------------------*/

My teammates managed to catch almost all of the bugs that I introduced, by 
coincidence we wound up as a team choosing all of the same cards that I had
edited. They found the following bugs:

Smithy Card:
The smithy card implementation was drawing the incorrect number of cards. I fixed
this by reverting the change that I had made previously in dominion.c to clean up 
the bug.

Council Room Card:
The Council room card had two bugs, my teammate's tests caught both of them. The
first of which was drawing the incorrect number of cards. The second of which 
was noting that the other players were not allowed to draw a card when the card 
was played. I fixed both of the bugs, as these were introduced by me.

Village Card:
My teammates noticed that the function was drawing the correct number of cards,
but due to their well-designed test they were able to catch the fact that an 
unexpeced number of cards was in the discard pile. This was a deliberate bug
that I introduced at the start, so it was good that their test was checking for
both hand size and discard pile size.

Adventurer Card:
They did not, however, find the bug that I introduced into the Adventurer card,
being another "off by one" error where the function should draw one too many
treasure cards almost every time. Somewhat unexpected for me was the fact that
when I ran my test, I got about a 90% fail rate for the function, which should
have been 100%. I'm not sure how this slipped through, or what had changed, in
order for this to occur. Nonetheless, I fixed the bug in the code and recompiled
and the error went away. So although I know that the bug I introduced was the
problem, there was still a path that could cause the program to not return an 
error.