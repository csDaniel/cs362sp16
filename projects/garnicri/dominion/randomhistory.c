/*

randomtestcard.c (Village card)
===============================
Two changes were made to the Village card.  They were:

	(1) - actions are not increased by two, thus actions always remain at one
	(2) - the current card is not discarded, therefore the hand count remains the same
	
The testing invovled ensuring that through each random iteration, none of these occurrences took place.

Once a game is initialized and a hand is dealt, the test determines what the current number of actions
currently is and evalutes what those actions should be if the Village card function was not changed.

Then, the test evaluates how many cards the current player has and compares that to the number of cards
the player should have.

These features are printed out, however a quick if-then checks against the numActions value AND if the
number of cards in hand match the current hand.  If both of these are true, the test passes.

Throughout all of the testing, each test was successful.  Actions did not increase by two, as they should
in a correct game and the current card is not discarded, thus preserving the hand count size at all times.


randomtestadventurer.c (Adventurer card)
========================================
Two changes were made to the Adventurer card but I was curious if the change of not allowing gold coins
to be selected would work.  (Having already tested card count and hand count in the previous test, I wanted
to see if something more intricate as a specific card selection would work.)  In this case, it did.

As before, once a game is initialized and a hand is selected, a for-loop runs through all available cards
in the current hand to ensure that none of them contain a gold card.

If a gold card does exists in the hand, then the test has failed.  After all the various iterations in the
random testing, all tests passed as no gold cards were issued throughout all the various hands.

What to test in the future:
===========================
One thing I did not test for with regards to the Adventure card was to make sure that each card in the hand was random, 
rather than contiually the same card as this would be an error that would nullify the above test.

For the Village card, I should keep a smaller sample size and always play the same hand to always ensure that
the actions truly never increase and the hand count always increases.  Since each hand is different in testing,
it does not provide a thorough enough evaluation to verify that the refactored functions are operating correctly.

*/