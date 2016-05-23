ALL TEST ARE RUN BY COMPILING TEST CODE USING THE FOLLOWING AS AN EXAMPLE:

markcardtest: markcardtest.c dominion.o rngs.o
	gcc -o markcardtest -g  markcardtest.c dominion.o rngs.o $(CFLAGS)

Bugs for Mark:

1) Smithy Test Bugs:

Major Bug: (Same as Saie's bug. Implementation incorrect in same way).

Smithy is drawn and there is always one more card in the hand then their should be.
Follow up test drawing Smithy from hands of various sizes shows That one additional card
is drawn OR smithy is not being discarded correctly.

After review of smithy code I found that in the for loop there is a bug where i<= 3 when
i starts at 0. This will always draw an additional card.

2)

Adventure Card:

Too many cards are drawn when adventurer card is called.

Data is:

Original Hand:
7   4   4   1   4

Hand After Card Played:
4   4   4   1   4   4   4   4   1   1

There are 4 new cards drawn instead of the 2.

Initial Treasure Count: 3
New Treasure Count: 7
Expected Treasure Count: 5

This shows that 2 more copper are drawn instead of the expected 2. 


**************----------------------**********************
Bugs for Saie:

1) Smithy Test Bugs:

Major Bug:

Smithy is drawn and there is always one more card in the hand then their should be.
Follow up test drawing Smithy from hands of various sizes shows That one additional card
is drawn OR smithy is not being discarded correctly.

After review of smithy code I found that in the for loop there is a bug where i<= 3 when
i starts at 0. This will always draw an additional card.

Other Bug:

Victory points registered as Incorrect after smithy is played. After reviewing code I am not sure why.

2) Adventure Test Bugs:

Adventure has a bug where it does not give enough treasure. It incorrectly adds one treasure
instead of two.

The original hand is:

7 4 4 1 4 (each integer is related to a card)

The card after is:

7 4 4 1 4 4

This proves that not only is the adventure card (which is represented by integer value 7)
not discarded, but it is also not bringing in enough treasure cards to the hand.

Bug 1: Not enough treasures brought to hand
Bug 2: Adventure card appears not to be discarded.


