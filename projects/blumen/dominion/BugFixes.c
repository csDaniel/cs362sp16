BugFixes.c

Provide a documentation file to discuss which bugs you fix and mention
your code changes.

Adventurer

* Gold treasure is discarded

Using my test suite, I manually changed the composition of the player's
deck (note: I should have used fuzzing rather than manually changing but
I took a short-cut here, knowing the bug in advance). According to test #3,
gold treasure is discarded. No treasure should be discarded during this play.

Given that other treasure was properly placed into the player's hand, I
hypothesized that the bug concerned a block of code within playAdventurer()
where treasure is identified. playAdventurer() is as follows:

int playAdventurer(struct gameState *state){

    int drawntreasure=0;
    int currentPlayer = whoseTurn(state);
    int temphand[MAX_HAND];// moved above the if statement
    int cardDrawn;
    int z = 0;// this is the counter for the temp hand

    while(drawntreasure<2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
          shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
          drawntreasure++;
        else{
          temphand[z]=cardDrawn;
          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
          z++;
        }
    }
    while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
    }
    return 0;
}

I reasoned backwards: a discarded Gold had to be in temphand. To be placed into temphand,
the condition: (cardDrawn == copper || cardDrawn == silver) had to evaluate to False.
This would indeed always happen with Gold. However I want NOT to place Gold in temphand.
Therefore I want the condition to evaluate to True. By changing the condition to:
    (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
gold is never placed into temphand. This makes sense: the condition wants to capture all
treasure. Omitting Gold was an error.

Test 3 now passed.

Smithy

* Four cards are added instead of three.
Using my test suite: when playing the smithy card, a player ended up with 4 cards according
to test #1. According to test #2, 4 cards were taken from the player's deck. According to
tests #3 & 4, there were no changes to other piles (except discard pile). This suggests
that 4 rather than 3 cards were taken from the player's deck and put in the player's hand.
I hypothesized that the bug was in the smithy block of code and concerned lines that were
responsible for counting the cards that were placed in the player's hand. I examined the following
lines:
    for (i = 0; i <= 3; i++)
    {
        drawCard(currentPlayer, state);
    }
Variable i takes on 4 rather than the intended 3 values. This is caused
by the use of "<=" instead of "<" (other fixes possible).

I fixed this by changing the code to:
for (i = 0; i < 3; i++)
    {
        drawCard(currentPlayer, state);
    }

Test 1 now passed.

Feast

* Only cards of value 3 coins or less were gained.

When the requested card costs 4  or 5 coins, playFeast() returns a "-1"
error code indicating an invalid play and test 4-7 (which test for expected
changes in a valid play) failed.

Plausible hypotheses were (1) too little money was added to coins and
(2) the card's value was improperly evaluated against coins.

I looked into the lines of code that updated coins. Specifically I
found that: updateCoins(currentPlayer, state, 2); only added 2 coins.
I changed the line to updateCoins(currentPlayer, state, 5);

I ran the test suite again. It still failed. So I considered the 2nd
hypothesis stated above.

I looked at the line else if (state->coins <= getCost(choice1)). This is the
only line that compares coins to the cost of a card. It suggests that even
a card that costs exactly the number of coins the player has will result in
an error statement that the card is too expensive. Changing the comparitor
from <= to < removes this bug.

* The player does not gain the card that was purchased.
This may only show up by looking at the deck post-play.

council_room
* Opponents do not gain a card even though they should.

Any hypothesis that may explain this involves the variable otherPlayer.
Upon examining the council_room function it appears that there is no codecvt
at all involving that variable. Therefore a whole block of code needed to
be written in:
    for (i = 0; i < state->numPlayers; i++)
	{
        if ( i != currentPlayer )
	    {
            drawCard(i, state);
	    }
	}
