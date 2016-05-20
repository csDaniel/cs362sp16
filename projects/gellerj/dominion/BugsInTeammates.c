/*
Daniel O'farrel
 
    Smithy failed tests:

        Test that hand count is incremented by 2 (+3 new cards, -1 existing smithy)...
        Initial hand count was 5, new hand count is 8, expected 7...FAILED.

        Check new cards came from player 1's deck...
        Deck count was 5, new deck count is 1, expected 2...FAILED.

        Check smithy card was added to played pile...FAILED.

    Adventurer failed tests:

        Check new card #2 is a treasure card...
        Card #2 is 1, expected 4, 5, or 6...FAILED.

        Check that hand count is incremented by 2 (+2 new treasure cards)...
        Initial hand count was 5, new hand count is 6, expected 7...FAILED.

        Check that copper treasure cards are gained by adventurer...
        Initial hand count was 5, new hand count is 6, expected 7...FAILED.

    Village failed tests:

        Check number of actions is +2...
        Num actions is -1, expected 3...FAILED.


Alex Samuel

    Smithy failed tests:

        Test that hand count is incremented by 2 (+3 new cards, -1 existing smithy)...
        Initial hand count was 5, new hand count is 8, expected 7...FAILED.

        Check new cards came from player 1's deck...
        Deck count was 5, new deck count is 0, expected 2...FAILED.

        Check smithy card was added to played pile...FAILED.

    Adventurer failed tests:

        Check new card #1 is a treasure card...
        Card #1 is 1, expected 4, 5, or 6...FAILED.

        Check that hand count is incremented by 2 (+2 new treasure cards)...
        Initial hand count was 5, new hand count is 9, expected 7...FAILED.

        Check new treasure cards came from player 1's deck...
        Net difference in deck treasure card supply is 3, expected 2...FAILED.


    Great Hall failed tests:

        Check that hand count is incremented by 0 (+1 new draw cards, -1 discard)...
        Initial hand count was 5, new hand count is 6, expected 5...FAILED.

        Check number of actions was incremented by 1...
        Initial action count was 1, new action count is 3, expected 2...FAILED.
 */