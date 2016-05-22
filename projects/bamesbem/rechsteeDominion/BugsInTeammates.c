/*
 Michael Bamesberger
 CS 362
 Assignment 4
 BugsInTeammates - rechstee (Evan Rechsteiner)
 
 
 
----------------- Bug 1 -------------------
 
Title: Adventurer card not discarding all cards
 
A bug was discovered in the playAdventurer() function in dominion.c
 
Classification: Minor bug
 
Description: The bug was discovered in the while loop at the end of the function that is
 responsible for discarding the non-treasure cards that were drawn in the function's previous while loop.

What's the error: The second while loop reads while (z-2 >= 0), when it should instead read
 while(z-1 >=0). The loop does not discard all the cards necessary.

Steps to reproduce: 
 
1. Initialize two gamestates
2. Run one gamestate through the playAdventurer() function
3. Compare the discardCount of the test gamestate against the original
 The difference should be 2 (the number of treasure cards) + the difference in the deckCount
 of the two gamestates

Additional notes about testing process:

It was necessary for me to add a fourth test to my test suite to catch the bug. The test, found in
 cardtest2.c, is labeled Test 3.
 
Additionally, during the process of testing, I discovered errors in my own unit tests. My second test originally tested to see if the deckCount in the test game state was decremented by two (the amount of treasure cards drawn). However, this was wrong — the change in deckCount comes from both treasure and non-treasure cards. I rewrote the test; it now tests if the test gamestate has fewer cards in the deck than it did previously. In addition, the last of my three tests always failed because of a typo.
 
 
 ---------------- Bug 2 ---------------------
 
 Title: Smithy Card not incrementing playCard after discard
 
 A bug was discovered in the playSmithy() function in dominion.c
 
 Classification: Minor bug
 
 Description: The was discovered in the discardCard() function at the end of the
 playSmithy function(). The bug is involved with the setting of the function's trashFlag.
 
 What's the error: The discard funciton reads discardCard(handPos, currentPlayer, state, 1)
 when it should read discardCard(handPos, currentPlayer, state, 0). The change in the
 trashFlag means that the discardCard function does not add the player's Smithy card to the
 playedCard pile and increment the playedCardCount.
 
 Steps to reproduce:
 
 1. Initialize two gamestates
 2. Run one gamestate through the playAdventurer() function
 3. Compare the playedCardCount of the test gamestate against the original
 The difference should be one.
 
 Additional notes about testing process:
 
 It was necessary for me to add a third test to my test suite to catch the bug.
 The test is found in cardtest1.c.
 
 
 
 
 
 
 
 */
