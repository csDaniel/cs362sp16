Susan Eldridge
Spring 2016
CS 362
BugFixes.c

First, I fixed the switch statement so that all the cases had return values and updated my dominion.h file.


SMITHY:
I removed: if (handPos == 2)
           {
                handPos--;
           }
I changed the trash flag to 0 in Smithy, so that the card is placed in discard instead of trash.



ADVENTURER:
I removed cardDrawn == smithy from the if() statement regarding tallying treasures drawn in pAdventurer.
This bug remained unnoticed, but it is clearly wrong.

I changed temphand[0] to temphand[z], in the else statement.  This was another bug that remained unnoticed
by my teammates, but the temphand cards should not just be disappearing because they need to be discarded.

I also initialized the int z to be zero in pAdventurer.

I removed:
    if (state->deckCount[currentPlayer] <3){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
because when you use the drawCard() function, it shuffles for itself when needed.  Cards are supposed
to be shuffled there are none left to shuffle, not when there are less than 3.  This also went unnoticed
by my teammate's tests.



Overall, I think coverage is very important, but it is clear that even with good coverage, if you are
not asking the right questions, then you will still miss bugs such as the ones I introduced (temphand[0]
instead of temphand[z], the extra shuffling, smithy card counting as a treasure).
In testing my teammates code, I found that having too much coverage on one branch of my random test
case had a negative effect because I was unable to see what was happening with the other branches
because statistically it was practically always going to the one branch.
