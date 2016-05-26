Bugs:

Smithy card:

Both teammates found the error that I had introduced:  that rather than choose three cards, the refactored code chose four.

	-this was due to a change in the for-loop by changing the value of 3 to 4
	-once the fix was made, the Smithy card function as it did in the original code
	
Adventurer card:

The following errors were discovered:
	
	-only two cards were selected instead of three
		-the while-loop was changed to only allow for one selection
		
	-no gold card was ever part of the selection
		-the cardDrawn option omits the gold card selection, therefore never allowing gold to be a choice
	
	These were indeed the two errors that I had introduced into the refactored code and fixed them to match the correct coding
	
Village card:

The following errors were discovered:

	-only one action is allowed instead of two
		-the numActions was never incremented to 2 to allow for the increase in actions
		
	-2 cards are added when the card is played instead of one
		-this was due to a change in the trash flag when the discardCard function is called
		-the flag is never triggered, thus a card is never discarded giving the illusion that an extra card was added
	
	These were indeed the two errors that I had introduced into the refactored code and fixed them to match the correct coding
	
	
Bugs not resolved:

-Only David B. reported an error with the Council Room card, however that code was never refactored and when tested on my end,
I never did receive or find the bugs in question.  (Although, our fellow teammate changed their coding so this could be in 
reference to their changes and not mine.  I know becaue the errors in question were ones that actually both teammates had.)

Resolution:

The changes that were introduced in the refactored code were caught by both teammates and each error was found out to be "working"
as it was supposed to.  I did not run/use coverage after I got back their results since they each found out all sets of errors as it
related to the refactored code. The changes were not to the point of needing to use further testing documentation since the errors
that were introduced were immediately found by my teammates testing. 

The Minion card changes were not tested and still remain refactored from their original settings.

