/*
    FOR KARA FRANCO-
    ERRORS DISCOVERED IN CODE:
    1.) Kara has mistakenly understood OR has made a typo in her Smithy refactored code.
    The Smithy card by default gives the player 3 cards.  When card is played, card results in 
    1 less card in hand than expected due to drawCard() being called one less time than should be.
    Kara implemented her bug in this function as I implemented mine...by changing the 
    Initialization from 0 to 1 but kept the condition the same.  IE, for(i=1; i<3; i++) effectively
    only giving the player 2 cards or 1 less than what should have been obtained from such a card play.
    
    These revelations were discovered by manual code review as I had a pre conceived notion of expecting my 
    test functions to return 6 but they returned 7 instead.  Upon further review of her code and my test function
    I noticed my function was actually incorrect.  What is occuring is that my test function keeps track of a pre card
    played value of 5...then plays the card for the normal deck and hand...then adds 2 to the pre value and compares what
    cardPlayed() returns (which when smithy adds 3 is 7 (5+3-1(for card played)))...when you add the pre value of
    5 plus a normal play of smithy which is 2, you also get 7.  My function has been falsely claiming true for everything
    when in fact it is false.  I forgot to discard in my pre value.  The pre value should be 5+2-1(for card played)=6.
    This will trigger an error message every single time.
    
    2.) Kara has mistakenly understood OR has made a typo in her Adventurer refactored code.
    The Adventurer card by default gives the player 2 treasure cards.  In Kara's implementation
    I am getting a third card which suggests that the loop that is calling the drawCard() one more
    time than it should.  Indeed it is as the while loop has been tampered with by adding a '=' sign.
    Additionally, when I play my card, I never get any silver...this is due to the function incorrectly 
    registering silver as not a treasure card but instead just copper and gold.  Kara's bugs are almost 
    identical to the ones I implemented myself.
    
    Again these revelations were made by manual code review and I have made, again, the wrong error in my 
    test code.  I forget to discard in my pre values.  
    
    No errors discovered with unit tests.
    
    FOR ROSA TUNG-
    ERRORS DISCOVERED IN CODE:
    
    1.) Gardens card tested out fine.  
    
    2.) Smithy card tests out fine...which makes sense as Rosa did not tamper with the amount of 
    cards were given.  We expect 7 cards to remain in the players hand (5+3-1)=7.

    No errors discovered with unit tests.
*/