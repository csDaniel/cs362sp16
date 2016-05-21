Bugs found in partner 1: murphet
Unit testing found bugs 1 - 5.  Random testing confirmed bug 4 and found 6.
1.	Bug in scoreFor().There is a bug in how it determines the score for gardens.When the hand, discard and deck all have only 5 cards(all gardens), it does not give the expected score of 15.
2.	Bug in scoreFor().This bug has to do with different size hands.When the hand has 4 estates, discard has 5 estates and deck have 6 estates, it does not produce the expected output of 15.
3.	Bug in Smithy.After initializing a new game and playing Smithy, there are three incorrect values.First, the players hand count is supposed to be 3 but is actual 8.  Discard count is expected to be 1 but is actual 0.  Opponent’s deck is supposed to be 0, but is actually - 1.
4.	Bug in adventurer.After initializing a new game and playing adventurer, there are two incorrect values.First, player’s hand count is expected to be 6 but is actually 7.  Secondly, discard, deck and played count(combined) is expected to be 4 but is actually 3.
5.	Bug in gardens.After initializing a new game and playing gardens, hand count is expected to be 4 but is actually 5. The sum of discard deck and played deck is expected to be 1 but is actually 0.
6.	Bug in adventurer : In random testing, 98.9% of tests had an error in the count of treasures cards in hand and count of treasure cards in discard + deck + played decks.

Bugs found in partner 2 : mailarw
Unit testing found all 6 bugs.Random testing also found bugs 4 and 6.
1.	Bug in scoreFor().There is a bug in how it determines the score for gardens.When the hand, discard and deck all have only 5 cards(all gardens), it does not give the expected score of 15.
2.	Bug in scoreFor().This bug has to do with different size hands.When the hand has 4 estates, discard has 5 estates and deck have 6 estates, it does not produce the expected output of 15.
3.	Bug in Smithy.After initializing a new game and playing Smithy, the player’s hand count is expected to be 3 but is actually 4.  The deck is count is expected to be 2 but is actually 5.
4.	Bug in Adventurer.After initializing a new game and playing adventurer, the player’s hand count is expected to be 6 but is actually 7.  The discard and played count is expected to be 4, but is actually 3.
5.	Bug in gardens.After initializing a new game and playing gardens, hand count is expected to be 4 but is actually 5. The sum of discard deck and played deck is expected to be 1 but is actually 0.
6.	Bug in Village.After initializing a new game and playing village, the deck count is expected to be 4 but is actually 5.  The opponents deck count is expected to be 10 but is actually 9.
