Susan Eldridge
CS 361
Spring 2016
randomhistory.c

randomtestadventurer.c:
For this test, I am getting segmentation faults about 1 in 20 times.  I was unable to pinpoint where this is happening.
Branch coverage for the function is high, but one branch usually far outweighs the other (example: branch  0 taken 82%
branch  1 taken 18%).  This happened where the cards needed to shuffle.  Since the deckcount was set to randomize between
0 and 500, I could see where the cards would often not require shuffling (if larger numbers were in the deck already).
Maybe, it would make sense to randomize subsets of hand and deckcounts, so that the lower numbers (which actually seem more
realistic for the actual game) have a broader chance of being selected and tested.  This never saw any testing on the
last couple of lines where the temphand is discarded.  Perhaps this is a bug.  This was returning the wrong number of cards
in hand fairly consistently.  I also saw the message that the other players had gained cards as well.  I felt like this
also needed to be skewed away from always having enough treasure cards to draw- a way to test for the correct behavior when
there are 0 or only 1 treasure cards to be drawn.

randomtestcard.c
Here, I was testing the council_room card.  Every line of the council_room was hit with this.  This was catching a bug that
indicates the number of coins was changing and it should not have been doing so.

I was unsure on both of these tests what would happen if shuffle was called.  This would obviously make it harder to
track and make sure the appropriate cards were being drawn or discarded because the saved gameState would shuffle differently
than the gameState being tested.
