Susan Eldridge
Spring 2016
CS 362
BugsInTeammates.c

beckermb:
    Smithy-Unit Test (cardtest1) found that Smithy was discarded inocorrectly.

    Adventurer-Unit Test (cardtest2) found that the wrong card was added to the played pile.
        -Random Testing showed that the wrong number of cards was in the player's hand after the card
        was played for all three (0, 1, >=2) treasure card availability.

poolj:
    Smithy-No bugs were found for unit testing.

    Adventurer-Unit Test found failures when making sure that 2 treasure cards were added to the hand.
        -Unit Test also found that the wrong ccard was discarded from the hand and that the wrong card
        was added to the played pile.
        -Random Testing showed the same as with beckermb.  The wrong number of cards was in the player's hand
        after the card was played whether the player was able to draw 0, 1, 2, or more treasure cards.




For both members, I ended up having to greatly reduce (from 500 to 5) the draw card pile to test the
adventurer card.  This was because most of the time 2+treasure cards were available to draw.
I had to reduce the size to test what was happening when only 1 or 0 treasure cards were present
in the draw card pile.
I realized, when I was looking at what my teammates had found wrong with my code, that I had a logical
flaw with my test cases.  I only considered the draw pile, not the discard pile.  Since the discardCard
pile can be shuffled and added back into the draw pile, I should have set this up better.
