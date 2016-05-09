/*
 Brandon Swanson
 Assignment 4  Random Testing

 /////////////////////////////////////////////////////
 RandomtestingAdventurer.c:
 /////////////////////////////////////////////////////

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


 /////////////////////////////////////////////////////
 RandomtestingCard.c:
 /////////////////////////////////////////////////////

 In this file I tested the playSmithy() function.

 Method for Testing:
 I used similar techniques for generating random game states, and checking that they didn't interfere with the operation
 of the playSmithy function and the playSmithy function only affected the expected parts of the game state.
 I also generated random decks that were were randomly distributed between the draw pile and discard pile.
 Once again I used a bias to test for edge cases in which the draw pile did not contain sufficient cards and a shuffle
 of the discard pile would be necessary, about half the time the draw pile would contain either 0,1,2,3 cards and the
 other half it would contain a random amount.
 I also added additional test to check if the cards in the players hand came from the top of their draw pile, but
 Only if a shuffle of the discard was not necessary.

 Findings:
 There of course was the bug I introduced in the first assignment set, playSmithy transposes two int parameters of
 discardCard function call,  handPos and curPlayer are switched which causes a segmentation fault in some of the testing
 functions.  Those testing functions were adjusted to check for card values outside of the range of the counting arrays
 and the randomly initialized game was more carefully controlled.  initializing all of the players handouts.
 While the segfaults in discardCard() caused by the bug in smithy are certainly valuable testing information, It causes
 only one test to be executed and because we are aware of the bugs I introduced I modified the tests to avoid halting as
 a result of this bug.

 I also introduced a bug into smithy that it would draw 4 cards instead of 3,  but in 4000 tests 993 of them only 3
 cards were drawn even though the for loop calling drawCard must always execute 4 times.  In that case there must be
 a bug in the draw card function.

 Coverage:
 File 'dominion.c'
 Lines executed:14.91% of 570
 Branches executed:9.11% of 417
 Taken at least once:8.63% of 417
 Calls executed:9.80% of 102
 Creating 'dominion.c.gcov'

 Function 'playSmithy'
 Lines executed:100.00% of 7
 Branches executed:100.00% of 2
 Taken at least once:100.00% of 2
 Calls executed:100.00% of 3

 Once again the coverage of the playSmithy function has not increased.  The overall file coverage is much lower than
 on the unit tests,  This is due to the fact that in the unit test the initializeGame and endTurn functions were used
 to prepare a game state, but in these random tests the game state was generated entirely randomly.
 */