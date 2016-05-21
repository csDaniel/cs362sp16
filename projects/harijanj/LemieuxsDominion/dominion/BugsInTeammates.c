/*
CS 362 TEAMMATE'S BUG REPORT
Jonathan Harijanto
Teammates: Behnam Saeedi & Sarah Lemieux

TESTED from my (jonathan) testunit1 - 4, cardtest1 - 4, randomtestcard, randomtestadventurer files.

First Teammate: Sarah Lemieux

1. First test: Cardtest 1 - Smithy Card

	Result:
	My TEST 1 (Check current player's hand card) - Not Passed
	My TEST 2 (Check current player's deck size) - Not Passed
	My TEST 3 (Check opponent's hand & deck size) - Passed
	My TEST 4 (Check victory piles) - Passed
	My TEST 5 (Check kingdom piles) - Passed

	Bug report:
	TEST 1: Check current player's hand card.
	Player's hand card = 8, Expected = 7
	Test 1 Passed: + 3 cards.

	TEST 2: Check current player's deck size.
	Player's deck = 1, expected = 2
	Test 2 Failed: More / Less than (-3) cards FROM deck.

	Smithy function is calling another "drawCard()" after 
	it draws three cards from deck. There is a small flaw 
	in "cardtest1.c", such that it said "test passed" even though
	it is not. 

	Comparison: 
	After looking at the refactor.c, it is indeed
	the bug is with the additional drawCard() that she added intentionally.

2. Second test: Cardtest 2 - Adventurer Card
	
	Result:
	My TEST 1 (Check current player's hand card, when 2 treasure cards at top) - Passed
	My TEST 2 (Check current player's hand card, when 2 treasure cards not at top so expect a card in discard pile) - Not Passed
	My TEST 3 (Check opponent's hand & deck size) - Passed
	My TEST 4 (Check victory piles) - Passed
	My TEST 5 (Check kingdom piles) - Passed

	Bug report:
	TEST 2: Check current player's hand card (2 treasure cards not at top, expect a card in discard pile).
        -->BEFORE 'adventurer': <--
	Player's hand card = 5, Expected = 5
	    -->AFTER 'adventurer': <--
	Player's hand card = 7, Expected = 6
	Player's deck = 3, Expected = 2
	Player's discard = 0, Expected = 1
	Test 2 Failed: DRAW total of MORE/LESS than 3 cards -- 2 Treasure cards not to HAND and 1 card not to DISCARD.

	Adventurer function 

	Comparison: 
	After looking at the refactor.c, this is not the bug she intentionally added.
	What she did is assuming "smithy" card to be treated as treasure card.
	Thus, failed test in "Bug Report" is considered as new unexpected bug.

3. Third test: Cardtest 3 - Village Card

	Result:
	My TEST 1 (Check current player's hand card)- Passed
	My TEST 2 (Check current player's action) - Passed
	My TEST 3 (Check opponent's hand & deck size) - Passed
	My TEST 4 (Check victory piles) - Passed
	My TEST 5 (Check kingdom piles) - Passed

	Bug report:
	None

	Village function has no bug.

	Comparison: 
	After looking at the refactor.c, she didn't modify this function.
	Thus, village function works as it supposed to do.

4. Fourth test: Cardtest 4 - Council Room card

	Result:
	My TEST 1 (Check current player's hand card)- Passed
	My TEST 2 (Check current player's buy) - Passed
	My TEST 3 (Check opponent's hand & deck size) - Passed
	My TEST 4 (Check victory piles) - Passed
	My TEST 5 (Check kingdom piles) - Passed

	Bug report:
	None

	Council Room function has no bug.

	Comparison: 
	After looking at the refactor.c, she didn't modify this function.
	Thus, Council Room function works as it supposed to do.

5. Fifth test: Unittest 1 - scoreFor()

	Result:
	My TEST 1 (Test score for all zero)- Passed
	My TEST 2 (Test score combining positive & negative) - Passed
	My TEST 3 (Test score combining positive value only) - Passed

	Bug report:
	None

	scoreFor function has no bug.


6. Sixth test: Unittest 2 - updateCoins()

	Result:
	My TEST 1 (Test if no coins)- Passed
	My TEST 2 (Test if all coopers) - Passed
	My TEST 3 (Test if coopers, silvers, golds are mixed) - Passed
	My TEST 4 (Test if bonus exist) - Passed

	Bug report:
	None

	updateCoins function has no bug.


7. Seventh test: Unittest 3 - isGameOver()

	Result:
	My TEST 1 (Test if province stack is negative)- Not Passed
	My TEST 2 (Test if dutchy empty) - Passed
	My TEST 3 (Test if estate empty) - Passed
	My TEST 4 (Test when 4 supplies zero) - Passed
	My TEST 5 (Test when 2 supplies zero but 1 with province) - Passed

	Bug report:
	TEST 1: Test if province is negative.
	# of province card in supply: -8. Dominion need condition state->supplyCount[province] =< 0!
	Result value: 0. Expected value: 0 (Game Not Over).
	Test 1 Failed.

	isGameOver function doesn't end the game when the supply of province
	card is negative. Even though it rarely happened (maybe never), but
	special condition still should be added as precaution.


8. Eighth test : Unittest 4 - fullDeckCount()

	Assumption: Specific card for this test - Adventurer
	
	Result:
	My TEST 1 (Test when no Adventurer card at hand, deck and discard)- Passed
	My TEST 2 (Test when 1 Adventurer at hand but 0 at deck & discard) - Passed
	My TEST 3 (Test when 1 Adventurer at player & opponent, but 0 at player deck & discard) - Passed
	My TEST 4 (Test when 1 Adventurer at hand, deck and discard) - Passed

	Bug report:
	None

	fullDeckCount function has no bug.


9. Ninth test: Randomtestadventurer

	Result:
	Within 2000 tests, Adventurer function failed to put exactly 2
	Treasure Cards from deck to hand. This is shown by the printed 
	test results :
	
	HAND: Treasure Cards didn't increase by 2
	DECK: Treasure Cards didn't decrease by 2.
	HAND: Treasure Cards didn't increase by 2
	DECK: Treasure Cards didn't decrease by 2.
	HAND: Treasure Cards didn't increase by 2
	DECK: Treasure Cards didn't decrease by 2.
	HAND: Treasure Cards didn't increase by 2
	.
	.
	.
	.
	
	Bug Report:
	Since this is using random testing, in order to detect the bug,
	a further investigation (read the code line by line) must be done.
	Further update for this bug will be provided in BugFixes.c

	play_adventurer function definitely need to be reconstructured.


10. Tenth test: Randomcardadventurer - Smithy Card

	Result:
	Within 2000 tests, Smithy function failed to reduce 3 cards 
	from the deck. 	This is shown by the printed 
	test results :
	
	Number of player playing: 2
	YOU are playing as player number : 0
	<----- BEFORE SMITHY ----->
	Your total hand cards: 326
	Your total deck cards: 482
	Player 0 hand cards: 326
	Player 1 hand cards: 4
	<----- AFTER SMITHY ----->
	Your total hand cards: 329
	Your total deck cards: 478
	Player 0 hand cards: 329
	Player 1 hand cards: 4
	Current player's deck FAILS to reduced by 3 cards!
	There are 1 players from 1 number of players (exclude YOU) that's not effected by smithy.

	Number of player playing: 3
	YOU are playing as player number : 0
	<----- BEFORE SMITHY ----->
	Your total hand cards: 310
	Your total deck cards: 359
	Player 0 hand cards: 310
	Player 1 hand cards: 362
	Player 2 hand cards: 321
	<----- AFTER SMITHY ----->
	Your total hand cards: 313
	Your total deck cards: 355
	Player 0 hand cards: 313
	Player 1 hand cards: 362
	Player 2 hand cards: 321
	Current player's deck FAILS to reduced by 3 cards!
	There are 2 players from 2 number of players (exclude YOU) that's not effected by smithy.
	.
	.
	.
	.
	
	Bug Report:
	"Cardtest1" test file tells that there is a bug in drawing extra
	card from the deck. Thus, this explains why over 2000 test in
	"randomtestcard.c" printed "Current player's deck FAILS to reduced by 3 cards!".

	The extra line of code that calls "drawCard" function needs to be remove
	from play_smithy function. After that line removed, it is guarantee that 
	randomtestcard.c and cardtest1.c will both give a test passed result.

-------------------------------------------------------------------------------------------------------

Second Teammate: Behnam Saeedi

1. First test: Cardtest 1 - Smithy Card

	Result:
	My TEST 1 (Check current player's hand card) - Not Passed
	My TEST 2 (Check current player's deck size) - Not Passed
	My TEST 3 (Check opponent's hand & deck size) - Passed
	My TEST 4 (Check victory piles) - Passed
	My TEST 5 (Check kingdom piles) - Passed

	Bug report:
	TEST 1: Check current player's hand card.
	Player's hand card = 6, Expected = 7
	Test 1 Failed: More / Less than 3 cards.

	TEST 2: Check current player's deck size.
	Player's deck = 3, expected = 2
	Test 2 Failed: More / Less than (-3) cards FROM deck.

	Smithy function only draws 2 cards instead of 3.
	Therefore, the deck also doesn't decrease by 3.

	Comparison: 
	After looking at the refactor.c, it is indeed
	the bug is with the additional for-loop that he intentionally modified.

2. Second test: Cardtest 2 - Adventurer Card
	
	Result:
	My TEST 1 (Check current player's hand card, when 2 treasure cards at top) - Passed
	My TEST 2 (Check current player's hand card, when 2 treasure cards not at top so expect a card in discard pile) - Passed
	My TEST 3 (Check opponent's hand & deck size) - Passed
	My TEST 4 (Check victory piles) - Passed
	My TEST 5 (Check kingdom piles) - Passed

	Bug report:
	TEST 1: Check current player's hand card (2 treasure cards at top).
        --> BEFORE 'adventurer':
	Player's hand card = 5, Expected = 5
	        --> AFTER 'adventurer':
	Player's hand card = 7, Expected = 6
	Player's deck = 3, Expected = 3
	Player's discard = 1, Expected = 0
	Test 1 Passed: DRAW total of 2 cards -- 2 Treasure cards go to HAND and 0 card go to DISCARD.

	Even though it passed the test, but noticed that something is not right with the discard.
	Test 1 assumes that 2 treasure cards already on top, thus no card should be on discard.
	However, this shows that there is one card at discard. Therefore, there is a bug that 
	that slipped away from the test.

	Comparison: 
	

3. Third test: Cardtest 3 - Village Card

	Result:
	My TEST 1 (Check current player's hand card)- Passed
	My TEST 2 (Check current player's action) - Not Passed
	My TEST 3 (Check opponent's hand & deck size) - Passed
	My TEST 4 (Check victory piles) - Passed
	My TEST 5 (Check kingdom piles) - Passed

	Bug report:
	TEST 2: Check current player's action.
	Player's action = 2, expected = 3
	Test 2 Failed: More / Less than 2 actions.

	Village function only increases the player's action by 1, instead of 2.

	Comparison: 
	After looking at the refactor.c, he modified the value added to 
	"state -> numActions".

4. Fourth test: Cardtest 4 - Council Room card

	Result:
	My TEST 1 (Check current player's hand card)- Passed
	My TEST 2 (Check current player's buy) - Passed
	My TEST 3 (Check opponent's hand & deck size) - Passed
	My TEST 4 (Check victory piles) - Passed
	My TEST 5 (Check kingdom piles) - Passed

	Bug report:
	None

	Council Room function has no bug.

	Comparison: 
	After looking at the refactor.c, he didn't modify this function.
	Thus, Council Room function works as it supposed to do.

5. Fifth test: Unittest 1 - scoreFor()

	Result:
	My TEST 1 (Test score for all zero)- Passed
	My TEST 2 (Test score combining positive & negative) - Passed
	My TEST 3 (Test score combining positive value only) - Passed

	Bug report:
	None

	scoreFor function has no bug.


6. Sixth test: Unittest 2 - updateCoins()

	Result:
	My TEST 1 (Test if no coins)- Passed
	My TEST 2 (Test if all coopers) - Passed
	My TEST 3 (Test if coopers, silvers, golds are mixed) - Passed
	My TEST 4 (Test if bonus exist) - Passed

	Bug report:
	None

	updateCoins function has no bug.


7. Seventh test: Unittest 3 - isGameOver()

	Result:
	My TEST 1 (Test if province stack is negative)- Not Passed
	My TEST 2 (Test if dutchy empty) - Passed
	My TEST 3 (Test if estate empty) - Passed
	My TEST 4 (Test when 4 supplies zero) - Passed
	My TEST 5 (Test when 2 supplies zero but 1 with province) - Passed

	Bug report:
	TEST 1: Test if province is negative.
	# of province card in supply: -8.
	Result value: 0. Expected value: 0 (Game Not Over).
	Test 1 Failed.

	isGameOver function doesn't end the game when the supply of province
	card is negative. Even though it rarely happened (maybe never), but
	special condition still should be added as precaution.


8. Eighth test : Unittest 4 - fullDeckCount()

	Assumption: Specific card for this test - Adventurer
	
	Result:
	My TEST 1 (Test when no Adventurer card at hand, deck and discard)- Passed
	My TEST 2 (Test when 1 Adventurer at hand but 0 at deck & discard) - Passed
	My TEST 3 (Test when 1 Adventurer at player & opponent, but 0 at player deck & discard) - Passed
	My TEST 4 (Test when 1 Adventurer at hand, deck and discard) - Passed

	Bug report:
	None

	fullDeckCount function has no bug.


9. Ninth test: Randomtestadventurer

	Result:
	Within 1000 tests, Adventurer function failed to put exactly 2
	Treasure Cards from deck to hand. This is shown by the printed 
	test results :
	
	HAND: Treasure Cards didn't increase by 2
	DECK: Treasure Cards didn't decrease by 2.
	HAND: Treasure Cards didn't increase by 2
	FAIL to draw 2 cards!
	DECK: Treasure Cards didn't decrease by 2.
	HAND: Treasure Cards didn't increase by 2
	DECK: Treasure Cards didn't decrease by 2.
	HAND: Treasure Cards didn't increase by 2
	.
	.
	.
	.
	
	Bug Report:
	Since this is using random testing, in order to detect the bug,
	a further investigation (read the code line by line) must be done.
	Further update for this bug will be provided in BugFixes.c

	play_adventurer function definitely need to be reconstructured.


10. Tenth test: Randomcardadventurer - Smithy Card

	Result:
	Within 1000 tests, Smithy function failed to reduce 3 cards 
	from the deck. 	This is shown by the printed 
	test results :
	
	Number of player playing: 4
	YOU are playing as player number : 2
	<----- BEFORE SMITHY ----->
	Your total hand cards: 186
	Your total deck cards: 296
	Player 0 hand cards: 356
	Player 1 hand cards: 142
	Player 2 hand cards: 186
	Player 3 hand cards: 335
	<----- AFTER SMITHY ----->
	Your total hand cards: 187
	Your total deck cards: 294
	Player 0 hand cards: 356
	Player 1 hand cards: 142
	Player 2 hand cards: 187
	Player 3 hand cards: 335
	Current player FAILS to gain 3 cards!
	Current player's deck FAILS to reduced by 3 cards!
	There are 3 players from 3 number of players (exclude YOU) that's not effected by smithy.

	
	Bug Report:
	"Cardtest1" test file tells that there is a bug in drawing less
	card from the deck. Thus, this explains why over 2000 test in
	"randomtestcard.c" printed "Current player's deck FAILS to reduced by 3 cards!".

	There is also another undected bug, player card after smithy being called showed
	only increased by 1 instead of 2. However, the deck still decreased by 2 cards.
	Thus, for every smithy call, 1 card is moved somewhere else other than hand.
*/