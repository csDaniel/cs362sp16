/*

My teammates noticed that in the effectAdventurer function the number of 
actions weren't decrementing, the handCount wasn't increasing correctly, 
and the playedCardCount wasn't increasing. I had introduced one of these 
bugs that was causing the player's handCount to increase incorrectly. 
The other two had already been there. I first fixed those three bugs. I 
had to pass some more variables into the effectAdventurer function so 
that I could call the discard card function which would increment the 
cardsPlayed. I decremented the number of actions inside the function and 
I fixed the error I introduced in the loop counter that added a third 
treasure card.

My teamates also found that the number of actions wasn't being decremented, 
the deckCount wasn't decreasing correctly, and handCount wasn't increasing 
correctly in the effectSmithy function. I changed the number of cards drawn 
by the function which caused the last two errors. The first bug was already 
there. I then fixed those three bugs by fixing the loop error that I 
introduced, and decrementing the number of actions inside the function.

Afterwards I fixed the bugs that I had introduced to the other card effect
functions.


*/