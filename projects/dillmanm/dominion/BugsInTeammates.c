For all of my tests, I used the methodology of introducing the target card randomly
into the hand of the player prior to taking counts of treasures or any other
pertinent hand counts, searching for the position of the card, and then using the 
dominion playCard() method with the handposition argument of the card being tested.
This gives a clean interface, since all refactored calls are made from the playCard()
argument. Therefore, I did not have to modify any of my test routines to adjust for function
name or argument differences in either of my teammate's code.

All tests reside in subdirectories with named by my teammate's ONID ID's. 

#############Aaron Sealy:

Unit tests:

Test for smithy card effect
===================
	Test that hand increase is correct.
	##TEST FAILED##. Target handcount: 7, Actual: 6
	Test that empty deck will reshuffle for smithy.
	Discard count: 5, Deck count: 0

Test for adventurer card effect
===================
	Test that Adventurer card discard is correct.
	##TEST FAIL## Adventurer not present in final discard.
	Test that Adventurer gets 2 new treasure cards in hand.
	##TEST FAIL## Adventurer postcondition not met. Cards other than treasure in hand.

Comments:

As you can see, the unit tests each had a failure for a designed test case. This led me
to Aaron's two introducted bugs. The smithy bug manifested as being a card short of the
intended amount for the handcoutn check. This was the result of the loop iteration variable
being initialized to 1 and running until less than 3, so only two cards were drawn instead
of three.

The bugs discovered in adventurer were related to the fact that Aaron did not discard the
Adventurer card, which was a bug present in the original version of the Adventurer effect
in Dominion. My unit tests did not detect his introduced bugs, but my random tests did.

Random test adventurer:

#####FAILED: : Expected hand size: 125, actual: 121
#####FAILED: : Played card count expected: 1, Actual: 0.
SUCCESS: : Total card count expected: 499, Actual: 499.
SUCCESS: : Supply pile check.
SUCCESS: : Other player card counts check.

This pseudorandom unit test that tested whether two golds in an otherwise
treasureless deck showed a 2 treasure shortcoming plus the shortfall for not discarding
the adventurer. This failure was not present in similar tests for silver and gold, and
therefore it uncovered Aaron's introduced bug that did not add gold to the treasure
count. No cards were drawn since only gold existed in the deck and discard.

###############Lucile Behmer:

Test for smithy card effect
===================
	Test that hand increase is correct.
    ##TEST FAILED##. Target handcount: 7, Actual: 5
	Test that empty deck will reshuffle for smithy.
	Discard count: 5, Deck count: 0

Test for adventurer card effect
===================
	Test that Adventurer card discard is correct.
	Test succeeds. Adventurer present in discard.
	Test that Adventurer gets 2 new treasure cards in hand.
 	##TEST FAIL## Adventurer postcondition not met. Cards other than treasure in hand.

Comments:

My unittests unveiled both introduced bugs in Lucile's code. Random tests revealed no
further bugs in commonly tested and refactored cards.

The smithy test observed that no cards were actually gained when the Smithy was played,
and then the smithy itself was discarded. This caught the bug that the card at hand index
handPos for each card that was drawn and no cards were gained from playing smithy.

The adventurer postcondition that two additional treasure cards be somewhere in the hand
was not passed. The function only permits treasure cards to be added to the hand, so it was
easy to notice that the hand increase was the result of additional treasures being added
because the treasureCount loop termination condition was too high. This interestingly manifested
itself in random tests by passing every concocted condition where the deck and discard were all
curses except for two randomly placed treasures, but almost every deck and discard condition with
over 2 treasures failed. Observing this would also indicate a problem with the treasureCount
termination condition.

For common cards tested, I got complete block coverage for commonly refactored and tested cards.
I also got complete branch coverage with minor splits for cases of reshuffling.
I did not get total path coverage between unit tests and random tests, however. For instance, 
I did not test cases in Adventurer where only treasures in deck and discard are gold and there 
is a forced reshuffle. There cases would probably be advantageous and would pick up more insidious bugs
such as a compound bug where the reshuffle resets treasure counts and gold are not counted as
treasure.


