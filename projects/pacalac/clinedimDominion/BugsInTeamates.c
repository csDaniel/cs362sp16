/*
	********** Introduction **********
	In this document, I will be describing the bugs that I have found in my teammates' code from
	their respective dominion folders.  Specifically, I will be describing bugs that I have found
	in the code of my following two teammates:

			Connor Pacala (ONID: pacalac)
			Eugene Andrew Pak (ONID: pake)

	I have created the following two directories in my own directory, which contain the code that
	was written by my teammates, along with the tests that I used to find the bugs described herein:

			/cs362sp16/projects/clinedim/pacalac_code/
			/cs362sp16/projects/clinedim/pake_code/

	For each of my teammates, I ran their code against my full suite of tests, which are listed below:

			cardtest1.c
			cardtest2.c
			cardtest3.c
			cardtest4.c
			randomtestadventurer.c
			randomtestcard.c
			unittest1.c
			unittest2.c
			unittest3.c
			unittest4.c

	In the next two sections, I will report the bugs that I found in each of my teammate's code.

	********** Bugs found in Connor Pacala's Code **********
	Bug #1:  Adventurer Leaves Too Many Cards in Current Player's Hand
	After running Connor's code against my test quite, I quickly spotted a couple of errors in the results
	of the randomTestAdventurer test:

			FAILED:  Player 0 should have 6 cards in hand but has 7.
			FAILED:  Played card count should be 1 but is 0.

	I quickly realized that there was a bug in Connor's code that was causing the Adventurer card to leave
	one too many cards in the current player's hand.  I examined Connor's playAdventurer card and realized 
	that the code for the the playAdventurer function never calls the discardCard function.  This left one
	too many cards in the current player's hands.  

	Bug #2:  Smithy Card Results in Incorrect Number of Cards in Current Player's Hand and Deck
	In addition to the bug with the Adventurer card, I also found a bug with Smithy card.  Specifically, my
	unit tests returned the following errors: 

			Error: Player 0 should have 7 cards in hand after playing smithy.
			Error: Expected 1 played card count.

	This is another bug caused by the lack of a call to discardCard in the function for playSmithy.  I examined
	the code and located where this call should appear; this will be described in the BugFixes.c file that
	accompanies this file.

	Bug #3:  Council Room Card Results in Incorrect Number of Cards in Hand and Deck and Incorrect Number of
	Buys
	Finally, my test quite returned the following errors related to Connor's implementation of the Council
	Room card:

			Error: Player 0 should have 8 cards in hand after playing council_room.
			Error: Player 0 should have 1 cards in deck after playing council_room.
			Error: There should be 2 buys after playing council_room.

	There is clearly an issue with the number of cards the player has in his hand and deck after playing the
	Council Room card; in addition, the player has an incorrect number of buys.  The fixes for these bugs are
	described in the BugFixes.c file that accompanies this one.

	In addition to the bug I found, I also examined the GCOV information for my unittests. 

			Lines executed:38.05% of 565
			Branches executed:39.28% of 415
			Taken at least once:30.36% of 415
			Calls executed:28.57% of 98

	My card tests and unit tests were testing only eight functions, so these results while low are not all that
	surprising.  As I mentioned in an earlier writeup, the most obvious way to improve the test coverage that 
	I currently have would be to implement unit tests for all of the functions within dominion.c and implement 
	tests for all of the cards in the dominion game.

	********** Bugs found in Andrew Pak's Code **********
	Bug #1:  Player Has Incorrect Number of Played Cards and Cards in Deck and Hand After Playing Treasure
	After running Andrew's code through my unit test suite, I spotted the following errors in his implementation
	of the Adventurer card:

			Error: Player 0 should have 3 cards in deck after playing adventurer.
			Error: Player 0 should have 6 treasure in hand after playing adventurer.
			Error: Expected 1 played card count.

	In examining Andrew's code, I noticed that there were a couple of things that were causing these bugs.  Firstly,
	he never calls the discardCard function to get rid of the Adventurer card after it is played.  Secondly, the
	loop counter that controls the loop that draws cards until the correct number of treasure has been drawn is
	incorrect; it's currently looping while the number of drawn treasure is less than 1 but it should loop until the
	number of drawn treasure is 2.  The fixes for these bugs can be found in the BugFixes.c file that accompanies
	this file.

	Bug #2:  Player Has Incorrect Number of Actions after Playing Village Card
	I also noticed the following error in my unit test results:

		Error: Number of actions should be 3.

	It is fairly clear from this message that the player has an incorrect number of actions after playing the Village
	card.  The player should have three actions but only has two.  Once I looked over Andrew's code, I saw that he was 
	only adding one action to the player's action count instead of two after the player plays the Village card. I have
	included my fixes for this bug in the BugFixes.c file which accompanies this file.

	In addition to the bug I found, I also examined the GCOV information for my unittests.

		Lines executed:37.97% of 561
		Branches executed:39.57% of 417
		Taken at least once:30.70% of 417
		Calls executed:27.08% of 96

	These levels of coverage are roughly the same as those for Connor's code, and the same observations I made in the
	section regarding Connor's code apply here.

	********** Final Thoughts *********
	My test suite found bugs in my own implementation of several of the cards in the Dominion card set, and found three
	bugs in Connor's implmenetation, as well as two bugs in Andrew Pak's code.  In addition, my test suite required no
	refactoring to find the bugs in Connor's and Andrew's implmentations.  The only thing that I really needed to do was
	drop my Makefile along with my tests into the directories that I created, and the tests ran without issue and shined
	light on issues that existed within their code.

	The biggest issue with my code is that the level of coverage is somewhat low.  This is due to the fact that I only
	test certain cards within the deck, however.  If I increased my tests to test all cards in the deck, the level of
	coverage would get much higher.  This would be a solid area of improvement for future test development.

	In addition to this file, I have included a BugFixes.c file which includes information regarding fixes for the bugs
	in my code, as well as fixes for Connor's and Andrew's bugs.
*/