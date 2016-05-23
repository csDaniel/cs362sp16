playSmithy:
1. Fixed error in drawing cards. Changed for (i = 0; i <= 3; i++) 
   to be for (i = 0; i <= 3; i++) so 3 cards are drawn correctly 
   instead of 4.
		This bug was found by both my teammates and my own unit test.
		It was a pretty easy bug to find. I found by simply comparing
		the number of cards in the hand to the expected number of 
		cards in the hand after the smithy card was played. Since the
		number was +1 more than expected I could easily look over the 
		code and see that the for loop was the culprit for this problem.
		Another possible way to spot this bug would be to look at the 
		code coverage. The loop should run 3 times, one for each card
		drawn. Since the coverage results show how many times a line
		runs I could have see that this loop was running once more
		than expected.

playAdventurer:
1. Fixed the bug that caused most of the draw treasure function to not
	execute. Changed if(drawntreasure > 2) to be drawtreasure < 2 so 
	that two treasure cards are drawn instead of skipping over this 
	section ofteh code.
		This bug was a pretty obvious one because, since it caused 
		most of the function to not run, it almost always caused
		both unit and random tests to fail. The easiest way to see 
		where this bug occurs is to look at the coverage results.
		I looked at where in the functions the lines of code stop
		being run and was able to find where this bug was located.

2. Fixed the bug that caused the adventurer card to not be discarded.
   Added a line in the playAdventurer function to discard adventurer 
   card after it is played.
		This was an easy bug to find and fix. When the tests reported
		that the card was not being discarded my first response was 
		to check to see if the discardCard() function was being called.

playVillage:
1. Fixed the draw card bug. Added  a line to draw a card int the 
	playVillage function so that a card is drawn when village card is 
	played
		Similar to the discard card bug discussed previously. This 
		bug was spotted and fixed by simply looking for the drawCard
		function in the playVillage function.

playGreatHall:
1. Fixed the discard card bug. Added a line to the playGreatHall
	function to discard the great_hall card after it is played.
	The process of finding and fixing this bug was the same as 
	the same bug in the adventurer card.

emabargo:
1. Fixed the bug that cause the embargo card to not get played when it
	should be and alternatively to get played when it should not.
	Changed getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) ) 
	to getCost(state->hand[currentPlayer][choice1]) + 2) < getCost(choice2) )
	so that the card is played if the cost of the trashed card + 2 is greater
	than the cost of the card the user selects.
		This bug was reported to me by my teammate Miranda. She provided a 
		very thourough report of the problem so I was easily able to spot 
		it by just looking at the code. If she had not spelled things out 
		so clearly for me, coverage results would have been helpful here.
		I could have looked at the code coverage for this test and seen that
		when trying to play the card correctly the lines for an error in play
		run and conversely when trying to play the card incorrectly  the lines
		to actually play the card run.
2. Fixed the trash card bug. The card chosen to be trashed was not originally
	trashed. Changed the trashed flag to 1 in the discardCard function
	for this card to fix this bug.
		The card chosen by the user to be trashed was actually put into the
		playedCards pile. This could be seen in the code coverage. The 
		lines that should run for a card being trashed do not get run and 
		the line to put a card into the playedCards run more times than 
		expected.