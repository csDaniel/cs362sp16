Sam schultz
Bugs found in teammates code
5/22/2016

**NOTE I had similar test cases fail for smithy and adventurer for both sets of code. Which means that the there may be a bug in my tests or the bug is in shared underlying code between the functions.
**NOTE Another important thing about my tests, I was not able to run my unit tests against either sets of code based off of the way I set my unit tests up, and I ran out of time to completely rewrite them so I was only able to run my random testers against both sets of code.
**Sorry if these bugs do not help that much.


Vlaskint Bugs:

Smithy Bug found: Assertion failed with propper handsize.
Description: When testing the hand size after the playing the smithy card. The correct hand size should be +2 hand count compared to the non-played smithy game state and this is not happening.

Adventurer Bugs:
Played adventurer card is not being placed into the playedCards pile.
Description: Test failed when checking state->playedCards[0] = adventurer. This may be a possible bug with my test assuming that playedCards[0] is the most recent played card.

Test failed when checking if the played state has more coins than the previous unplayed copy.
Description: This test being failed implies that the adventurer card is not updating the coins correctly. The played state should have more coins that the unplayed state because of adventurers effect.

Test failed when checking that the numActions is - 1 than before the card was played.
Description: The number of actions after a card is played should be one less than before a card is played. The number of actions is not being decremented propperly.

Test failed with expected hand size
Description: The actual hand size is 1 less than the expected hand size. The cause of this may lie in the discard section of the function.


Smithy Bugs:
Test failed with playedCard[] being updated
Description: Test failed when checking state->playedCards[0] = smithy. This may be a possible bug with my test assuming that playedCards[0] is the most recent played card.

Test failed with numActions being decremented
Description: numAction is not being decremented after the card is being played.

Test failed with discardCount being updated
Description: after the played smithy card is put into the discard pile the discard count needs to be updated. It appears this is not happening.





Mulholls Bugs:

Adventurer Bugs:
Test failed with state->playedCards[0] is not adventurer
Description: The adventurer card is not being placed onto the top of the discard pile after being played. The root of this error might be in the discard funtion.

Test failed with played state having more coins than unplayed state.
Description: The played state should have more coins after adventurer is played and this is not the case. The error may be in the update coins function.

Test failed with numActions being decremented.
Description: the number of actions after adventurer is played should be one less than the uplayed state. This did not happen which means the numActions is not being decremented when the card is played.

Test failed with expected hand size.
Description: The actual hand size is 1 less than the expected hand size.

Smithy Bugs:


Test Failed!
State->playedCards[0] != Smithy.
Description: The played card pile is not being updated with smithy after it is played.

Test Failed!
State->numActions != cpyState->numActions-1.
Description: The played state is not decrementing after smithy is played.

Test Failed!
Actual hand size = 5, Expected hand size = 7.
Description: The hand size is not being updated propperly with smithies draw 3 card effect.

