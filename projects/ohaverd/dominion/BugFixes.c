// Diana O'Haver
// Assignment 5: BugFixes.c

// Fix all the bugs that are found in your code.. First, fix the bugs that your teammate found then fix the bugs that you introduced.
// Use GDB to debug your code and fix it. Provide a documentation file to discuss which bugs you fix and mention your code changes.
// Provide a documentation file BugFixes.c.

// Bugs found by STRAMELM:

// The first bug report from Cash caught a bug introduced in an earlier assignment. I had modified the function for the council_room
// switch to increase the number of buys for the game by 2, instead of the increase of 1 buys the game rules call for. The fix for this
// was as simple as changing the 2 back to a 1.

// The second bug report from Cash again caught a bug introduced in an earlier assignment. I had modified the function for the smithy
// switch to increase the number of cards drawn to 4, instead of the expected draw of 3 cards. This resulted in a net increase of 3
// cards in the player's hand (4 drawn + smithy discarded) instead of the expected net increase of 2. The fix for this was again
// as simple as changing the 4 in the drawCard loop back to 3.

// Bugs found by FAESSLEK:

// The first bug report from Kelby caught two bugs. One of them was the bug caught as well by Cash, wherein playing the smithy card drew
// a different number of cards than expected. The second bug, however, was not one that I had intentionally introduced. Kelby noted
// that the return value from cardEffect was not 0. This was puzzling, as I had made sure to return 0 from my drawSmithy function.
// Tracing the code further, however, I found that I didn't do anything with that return value once back inside cardEffect, so 0 was not
// actually being returned fully. This was fixed by  not just calling drawSmithy, but returning the call.
// The second bug report from Kelby also caught the return value issue. I fixed this inside cardEffect also by returning the result of
// drawAdventurer, rather than just calling it. The report also found that my adventurer function did not increase the player's hand by
// 2 cards. This was because of a bug introduced previously, which increased drawnTreasure by 2 instead of 1, so the parts of the function
// that were dependent upon the drawn treasure being correctly tracked were misled. This was fixed by reverting the drawnTreasure back to
// increasing by 1.

// The final bug report from Kelby again caught the return value issue, which I fixed in the same way as described above. He also found that
// using the council_room card did not correctly increment the number of cards by 1, which had been fixed while reviewing Cash's bug report.
// Kelby also caught that I had modified the number of cards drawn in this function, decrease it to 3 cards from 4 cards. This was fixed by
// returning the counter in the loop back to the appropriate number.

// Discussion:

// It was interesting seeing the differences in the scope of the tests and what they found. My own testing didn't ever cover the return
// values of the switch statements I pulled out, so I unintentionally introduced several bugs without ever noticing. This indicates a gap
// in my coverage and probably points to the bias of writing tests for your own code. There was some overlap in the bugs found between
// Cash and Kelby. Because I only went off of the bug reports and did not inspect their code to see the breadth of their tests, it is
// hard to say whether Kelby's tests were slightly more thorough, or whether the bugs selected to be sent to me simply did not include
// all of the bugs found with each card. In my own bug reports, for example, I did not elect to send each and every bug, but instead
// attempted to choose a representative sample.
