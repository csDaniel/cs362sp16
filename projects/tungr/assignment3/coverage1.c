/*
	Rosa Tung
	CS362
	(40 points) Use gcov to measure code coverage for all of these tests. Report your findings by discussing your tests' coverages 
	(statement, branch, boundary, etc.), and describe their implications for the tests in a file called coverage1.c, also checked 
	in to your dominion directory. I want you to look at the dominion code coverage and find out what parts of your code are not 
	covered so that in future you can improve your test suite. 
*/

/* * * * * * * * * * * OVERALL (functions not there were 0%) * * * * * * * * * * */

File 'dominion.c'
Lines executed:35.15% of 569
Branches executed:34.29% of 417
Taken at least once:25.90% of 417
Calls executed:27.00% of 100

Function 'updateCoins'
Lines executed:81.82% of 11
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
No calls

Function 'discardCard'
Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
No calls

Function 'playCouncil_Room'
Lines executed:100.00% of 10
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 4

Function 'playVillage'
Lines executed:100.00% of 6
No branches
Calls executed:100.00% of 3

Function 'playSmithy'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 3

Function 'playAdventurer'
Lines executed:66.67% of 18
Branches executed:66.67% of 12
Taken at least once:41.67% of 12
Calls executed:66.67% of 3

Function 'cardEffect'
Lines executed:10.00% of 200
Branches executed:13.61% of 169
Taken at least once:2.96% of 169
Calls executed:12.73% of 55

Function 'getCost'
Lines executed:96.67% of 30
Branches executed:100.00% of 28
Taken at least once:96.43% of 28
No calls

Function 'drawCard'
Lines executed:77.27% of 22
Branches executed:100.00% of 6
Taken at least once:66.67% of 6
Calls executed:100.00% of 1

Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:90.32% of 62
Branches executed:95.65% of 46
Taken at least once:82.61% of 46
Calls executed:100.00% of 5

Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

/* * * * * * * * * * * UNITTEST1 * * * * * * * * * * */

File 'unittest1.c'
Lines executed:73.68% of 57
Branches executed:100.00% of 30 //has each statement evaluated both to true and false?
Taken at least once:60.00% of 30 //# times the call returned divided by the number of times the call was executed 
Calls executed:59.46% of 37

/*
	Function 'initializeGame'
	Lines executed:90.32% of 62
	Branches executed:95.65% of 46
	Taken at least once:82.61% of 46
	Calls executed:100.00% of 5
*/

---Testing initializeGame function START---

Initialize Game...
	Testing gameState for 2 players...
		Function succeeded including all below
			1. correct number of players
			2. selected kingdom cards are different
			3. deck is shuffled
		Correct Number of Players
		Correct # of Curse Cards
		Correct # of Estate cards
		Correct # of Duchy cards
		Correct # of Province cards
		Correct # copper cards
		Correct # silver cards
		Correct # gold cards
		Correct Cards in currentPlayers Hand
		Correct Cards in currentPlayers Deck

Initialize Game...
	Testing gameState for 3 players...
		Function succeeded including all below
			1. correct number of players
			2. selected kingdom cards are different
			3. deck is shuffled
		Correct Number of Players
		Correct # of Curse Cards
		Correct # of Estate cards
		Correct # of Duchy cards
		Correct # of Province cards
		Correct # copper cards
		Correct # silver cards
		Correct # gold cards
		Correct Cards in currentPlayers Hand
		Correct Cards in currentPlayers Deck

Initialize Game...
	Testing gameState for 4 players...
		Function succeeded including all below
			1. correct number of players
			2. selected kingdom cards are different
			3. deck is shuffled
		Correct Number of Players
		Correct # of Curse Cards
		Correct # of Estate cards
		Correct # of Duchy cards
		Correct # of Province cards
		Correct # copper cards
		Correct # silver cards
		Correct # gold cards
		Correct Cards in currentPlayers Hand
		Correct Cards in currentPlayers Deck


---Testing initializeGame function COMPLETE---

/*
	Taking a look at unittest1.c.gcov and dominion.c.gcov I see that I have gotten pretty good coverage for the test and 
	function itself. Looking at unittest1.c.gcov I see around 75% lines were executed and but 100% of branches executed. It 
	makes sense since all the tests executed and all the tests passed, so the lines that were not executed in the unit test 
	were the branches left out. Taking a look at the function in dominion.c.gcov I see that around 90% of the lines and branches 
	were executed. Since this is the function I am testing I took a look at the lines that were not touched. The branches not 
	touched seem to be the edge cases of players, which I did not test. If it were an incorrect number of players or kingdom cards, 
	or shuffle did not execute correctly it would have executed with a negative signal. Looking back to improve the test I would 
	need to test the first two to see if the function to see if it correctly executes. The other standalone part that doesn't 
	count in this group is the portion of the code that checks the number of kingdom cards. I would need to add in another test 
	to cover that region. 
*/

/* * * * * * * * * * * UNITTEST2 * * * * * * * * * * */

File 'unittest2.c'
Lines executed:90.48% of 21
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:83.33% of 12

/*
	Function 'whoseTurn'
	Lines executed:100.00% of 2
	No branches
	No calls
*/

---Testing whoseTurn function START---

Initialize Game...
	Attempt to Set to Player 1's turn
		PASS
	Attempt to Set to player 2's turn
		PASS

---Testing whoseTurn function COMPLETE---

/*
	Taking a look at unittest2.c.gcov and dominion.c.gcov I see that I have gotten pretty good coverage for the test and 
	100 % coverage for the function itself. The testing file was the same as the one above, since all the tests passed the branches
	that were not executed were the fail ones. I definitely should have tested the opposite as it is necessary to see the correctness
	of that portion of the function. This was a short test but there are more ways I could have tested, such as the players stats in 
	different cases. 
*/

/* * * * * * * * * * * UNITTEST3 * * * * * * * * * * */

File 'unittest3.c'
Lines executed:83.33% of 12
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
Calls executed:62.50% of 8

/*
	Function 'getCost'
	Lines executed:96.67% of 30
	Branches executed:100.00% of 28
	Taken at least once:96.43% of 28
	No calls
*/

---Testing getCost function START---

Testing curse cost (should be 0)
	PASS
Testing estate cost (should be 2)
	PASS
Testing duchy cost (should be 5)
	PASS
Testing province cost (should be 8)
	PASS
Testing copper cost (should be 0)
	PASS
Testing silver cost (should be 3)
	PASS
Testing gold cost (should be 6)
	PASS
Testing adventurer cost (should be 6)
	PASS
Testing council_room cost (should be 5)
	PASS
Testing feast cost (should be 4)
	PASS
Testing gardens cost (should be 4)
	PASS
Testing mine cost (should be 5)
	PASS
Testing remodel cost (should be 4)
	PASS
Testing smithy cost (should be 4)
	PASS
Testing village cost (should be 3)
	PASS
Testing baron cost (should be 4)
	PASS
Testing great_hall cost (should be 3)
	PASS
Testing minion cost (should be 5)
	PASS
Testing steward cost (should be 3)
	PASS
Testing tribute cost (should be 5)
	PASS
Testing ambassador cost (should be 3)
	PASS
Testing cutpurse cost (should be 4)
	PASS
Testing embargo cost (should be 2)
	PASS
Testing outpost cost (should be 5)
	PASS
Testing salvager cost (should be 4)
	PASS
Testing sea_hag cost (should be 4)
	PASS
Testing treasure_map cost (should be 4)
	PASS

---Testing getCost function COMPLETE---

/*
	Taking a look at unittest3.c.gov and dominion.c I see that I've gotten good coverage and 100% of branches executed for
	the function. That makes sense since I essentually looped through every single card and tested the values for them. Since 
	the tests passed there were some lines that were not covered. The tricky part about this function is that the return values
	might not reflect the actual values in the game, so there would have to be an array with the actual correct values. I'm not
	sure how I would test this other than to make my own and look it up, which is what I did. All the branches in the function were
	taken equally, with the only line not executed being the error line. 
*/

/* * * * * * * * * * * UNITTEST4 * * * * * * * * * * */

File 'unittest4.c'
Lines executed:85.00% of 20
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:78.57% of 14

/*
	Function 'compare'
	Lines executed:100.00% of 6
	Branches executed:100.00% of 4
	Taken at least once:100.00% of 4
	No calls
*/

---Testing compare function START---

Testing [left < right]...
	PASS
Testing [left > right]...
	PASS
Testing [left = right]...
	PASS

---Testing compare function COMPLETE---

/*
	Taking a look at unittest4.c.gov and dominion.c I see that I've gotten good coverage and 100% of branches executed for
	the function. That makes sense since I essentually looped through every single possible outcome. Since the tests passed 
	there were some lines that were not covered. However, unlike the previous functions I don't think it is necessary to do
	more coverage for my unit test to get through the fails.
*/

/* * * * * * * * * * * CARDTEST1 * * * * * * * * * * */

File 'cardtest1.c'
Lines executed:71.93% of 57
Branches executed:100.00% of 18
Taken at least once:55.56% of 18
Calls executed:60.53% of 38

/*
	Function 'playSmithy'
	Lines executed:100.00% of 6
	Branches executed:100.00% of 2
	Taken at least once:100.00% of 2
	Calls executed:100.00% of 3
*/

---Testing Smithy Card START---

Initialize Game...
Testing smithy cardEffect function return value...
	FAIL
Testing smithy action...
	PASS
		Player received 3 new cards
		current handCount: 7, previous handCount: 5
	FAIL
		exactly 3 cards not taken from the deck
		current deckCount: 1, previous deckCount: 5
		cards in discard pile: 0
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing Smithy Card COMPLETE---

/*
	Taking a look at both the funciton and unit test I see that 100% of branches executed, and similar to all the other tests the 
	branches that were not taken were the ones that reflected the results of the test, since I only did each test once. I noticed 
	that in dominion.c.gov that not only did the smithy case execute but the village case executed as well even though it was not a 
	card that was executed, which further convinces me that it has something to do with botching up the tests. Unfortunately I forgot 
	about that bug so when I ran the tests I thought they were sufficient enough to show that there was something going on within only 
	the function itself. If i was moving forward in doing more tests I would definitely isolate each function and run tests individually
	before running them together.
*/

/* * * * * * * * * * * CARDTEST2 * * * * * * * * * * */

File 'cardtest2.c'
Lines executed:71.93% of 57
Branches executed:100.00% of 18
Taken at least once:55.56% of 18
Calls executed:60.53% of 38

/*
	Function 'playAdventurer'
	Lines executed:66.67% of 18
	Branches executed:66.67% of 12
	Taken at least once:41.67% of 12
	Calls executed:66.67% of 3
*/

---Testing Adventurer Card START---

Initialize Game...
Testing adventurer cardEffect function return value...
	FAIL
Testing Adventurer action...
	FAIL
		Player did not receive just 2 cards
		current handCount: 9, previous handCount: 5
	FAIL
		exactly 2 cards not taken from currentPlayers Deck
		current deckCount: 0, previous deckCount: 5
		cards in discard pile: 0
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing Adventurer Card COMPLETE---

/*
	Taking a look at both the function and unit test I see that 100% of branches executed for the first while not the same for 
	the second. I see here that even though I didn't test the council room the function has been executed so both cases went through 
	which explains the bugs for my test. Again I forgot that I put that bug in there and had I known at this point I would have done 
	further testing for the second function. However I do see that the lines that never execute are actually a result of the discard 
	pile always somehow being empty. That is something I defintely would consider a red flag. Another huge part that I totally missed 
	in testing is in line 1053, a copper/silver/gold card never seems to be drawn whchih means there is a huge chunk that is never tested 
	below, which is a definite direction I would want to cover, as it is an important part of the function.
*/

/* * * * * * * * * * * CARDTEST3 * * * * * * * * * * */

File 'cardtest3.c'
Lines executed:69.23% of 65
Branches executed:100.00% of 20
Taken at least once:55.00% of 20
Calls executed:56.82% of 44

/*
	Function 'cardEffect'
	Lines executed:10.00% of 200
	Branches executed:13.61% of 169
	Taken at least once:2.96% of 169
	Calls executed:12.73% of 55
*/

---Testing great_hall Card START---

Initialize Game...
Testing great_hall cardEffect function return value...
	PASS
Testing great_hall action...
	PASS
		Player received just 1 card
		current handCount: 5, previous handCount: 5
	PASS
		exactly 1 card taken from currentPlayers Deck
		current deckCount: 4, previous deckCount: 5
	PASS
		Actions increased by 1
		current actions: 2, previous actions: 1
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing great_hall Card COMPLETE---

/*
	This card effect did not have its own function so the coverage is describing the card effect function, and the coverage
	for that is pretty low since I did not test the other cases, just that one. All the tests in my unit test were successful 
	so I got 100% branch coverage for that, although going forward I would expand my test to check for the actual cards that are 
	drawn by the player to make sure they were the correct ones. This case utilizes two more functions so I would want to test 
	the outcomes of those or the pools that those two functions affected as well. 
*/

/* * * * * * * * * * * CARDTEST4 * * * * * * * * * * */

File 'cardtest4.c'
Lines executed:69.23% of 65
Branches executed:100.00% of 20
Taken at least once:55.00% of 20
Calls executed:56.82% of 44

/*
	Function 'cardEffect'
	Lines executed:10.00% of 200
	Branches executed:13.61% of 169
	Taken at least once:2.96% of 169
	Calls executed:12.73% of 55
*/

---Testing gardens Card START---

Initialize Game...
Testing gardens cardEffect function return value...
	PASS
Testing gardens action...
	PASS
		No change in player hand count
		current handCount: 5, previous handCount: 5
	PASS
		No change in currentPlayers Deck
		current deckCount: 5, previous deckCount: 5
	PASS
		Actions unchanged
		current actions: 1, previous actions: 1
	PASS
		Other player's handCount has not changed
	PASS
		Other player's deckCount has not changed
	PASS
		no state change to victory card piles
	PASS
		no state change to kingdom card piles

---Testing gardens Card COMPLETE---

/*
	Like the previous, this card effect did not have its own function so the coverage is describing the card effect function, 
	and the coverage for that is pretty low since I did not test the other cases, just that one. Again, all the tests in my unit 
	test were successful so I got 100% branch coverage for that. Given the nature of the card, I think going forward I would need 
	not to just test the case but have more tests for the state changes to make sure nothing changed in addition to what I have. 
	I might also want to test the outcome to make sure in the end game those cards are actually giving points properyl 
*/




