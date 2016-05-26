********************************************************************************
* File:		BugFixes.c
*
* Author:	Jarrad Favre
*	
* Date:		5-22-2016
*
* Assignment 5 Part 2: Bug Fixes in dominion.c
********************************************************************************

The following are bug fixed reported by both team mates and fixed to my dominion.c
code:

In my Smithy card, it was reported that I had a bug that was sending the Smithy
card to the test after it was played, instead of the discard pile. This is indeed
the bug that was implemented in my code, and I changed it by changed the 1 in the
fourth parameter of discardCard function to 0.

In my Adverturer, it was reported that my card was only looking for and keeping
gold and copper cards. This is indeed the bug that I implemented in my code. I
corrected my code by adding in the condition for each card drawn of drawnCard
== silver.

The following are bugs I found in debugging my own code:

In Council Room card, I found that 5 cards were being drawn instead of 4. Looking
more closely into the code, I saw that the for loop condition was coded as i <= 4,
which would explain why 5 cards were being drawn. I fixed this by removing = from 
<= and now have for (i=0; i < 4; i++).

In the Village card, I noticed that it was playing 3 action cards. The bug that is
present in the code shows pState->numActions = pState->numActions + 3. As it ends
with + 3, this explains why 3 actions cards were being played instead of 2. In
this case, it was an easy fix, as I needed to changed the 3 to 2.
