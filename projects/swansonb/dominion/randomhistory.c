/*
 Brandon Swanson
 Assignment 4  Random Testing

 RandomtestingAdventurer.c:

 Method for Testing:
 For testing the adventurer card I implemented methods for creating a random deck of cards for the player to draw from.
 I wanted to have careful control over the number of coin cards available within the deck because having no coin cards
 or only 1 treasure card were important edge cases.  So I determine a random bias number from 0 to 4,  if it is 0,1 then
 there are 1 or 2 coin cards in the deck.  If the it is 2 or 3 than a random number of coin cards are placed in the deck
 and it if is 4 then the entire deck is filled with coins.  these randomly chosen coin cards are then randomly shuffled
 into the deck of cards chosen that excluded coin cards.

 For each deck that is generated this way the adventurer card function is tested exhaustively with the deck of chosen
 cards being divided up between being in the players deck and and discard pile, moving from all of the cards being in
 the players discard to all of the cards being in the players deck.

 Additionally before placing these cards in the players deck, and discard, and randomly generating a hand for the player
 as well as initializing any necessary game variables for the player,  the game state is generated randomly filling
 the struct with random bytes.  The game state resulting from this randomization is not playable by the games functions
 but before making calls to playAdventurer() the minimum number of variables needed for the function to operate are
 initialized.  This allows me to test not only that the rest of the games state was not affected inadvertently by the
 playAdventurer() function but also that that function is not affected by the state of the game struct in unexpected
 ways.

 Findings:
 I had believed that the playAdventurer() function contained a bug that would cause the loop to never exit if the player
 had fewer than 2 coin cards in their deck/discard piles combined.  because of these lines
  while(drawCardsRemaining){
       ////////////////////////////////////////////
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
        //top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawCardsRemaining--;
        /////////////////////////////////////////////////////////
    }
 Random testing revealed that this part of the code behaved differently than I expected,  In the case that there are no
 coin cards in the players deck or discard the program halts with a segmentation fault (from one of the functions
 further down the stack)
 but if there is only 1 coin card available in the players deck/discard the function will exit with only 1 extra coin
 card in their hand.  This is the intention of the game rules but occurs not through intentional code design but through
 a logic error,  that the top card of hand is the most recently drawn card.  if the drawCard returns error because
 there are no more cards available the top card of the players hand is not a newly drawn card and a discovered coin
 card will get counted twice.
 This also means that the function would exit after discarding all the players cards if the last card in the players
 hand was a coin card and their deck/discard contained no coin cards (a Corner case, combining two edge cases)

 Coverage:
 File 'dominion.c'
 Lines executed:13.51% of 570
 Branches executed:8.63% of 417
 Taken at least once:7.91% of 417
 Calls executed:6.86% of 102

 Function 'playAdventurer'
 Lines executed:100.00% of 20
 Branches executed:100.00% of 12
 Taken at least once:100.00% of 12
 Calls executed:100.00% of 4

 As we can see the coverage has not changed for the playAdventurer() function when counting lines and branches
 But given the enormous amount of testing scenarios that this random testing routine generates I believe that the
 behavior of the function has been more thoroughly tested then the measly number of hand generated testing arrays from
 my unit tests.

 */