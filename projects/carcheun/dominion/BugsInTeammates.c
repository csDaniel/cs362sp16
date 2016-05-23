/******************************************************************
 * Carolyn Cheung
 * CS 362
 * Assignment 5
 * Description: Bugs found in team mates code.
 ******************************************************************/

leemi:

cardtest1: Testing smithy
    A bug was found in smithy, the player hand count has 1 extra card than expected after playing smithy
    
cardtest2: Testing adventurer
    A bug was found in adventurer. The player hand count is one higher than expected, and the deck count
    is 2 less than expected. 
    
cardtest3: Testing council room
    A bug was found where the hand count was one higher than expected. The dec count was one less than expected.
    
randomtestadventurer: Testing adventurer
    A bug was found while using randomtestadventurer. The player did not remove the treasure from the deck, so 
    the correct amount of treasures was not removed from the deck.
    
randomtestcard: Testing Smithy
    A bug was found in that the current player handcount was one more than what it should have been, and
    the deckcount was one less than it should have been. The player is drawing an extra card.
    
orabii:

cardtest1: Testing smithy
    A bug was found where the player does not recieve the correct amount of cards. There is 1 less card than
    expected
    
cardtest2: Testing adventurer
    A bug was found where the player did not recieve both cards, instead only 1 was drawn from the deck and
    added to the hand
    
cardtest3: testing council room
    A bug was found where the player hand was not equal to the real hand. Player only drew 3 cards.
    
randomtestadventurer: Testing adventurer
    unit test states that current player did not remove treasures from deck.
    
randomtestcard: testing smithy
    unit test states that the current player handcount has failed. It is one less than expected.
 
    
Notes:
    
All tests ran fine without any sort of modification, my tests were very maintainable.