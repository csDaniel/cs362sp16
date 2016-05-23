Teammate 1: HarijaniJ
Bug Number: 1
--
Bug name: Smithy hand count bug
--
Bug Description: It adds two extra cards to the deck
--
Bug File:Dominion.c
--
Bug Line: 615
--
Bug Fix: change the <5 to <3
_________________________
Bug Number: 2
--
Bug name: Adventurer drawn treasure bug
--
Bug Description: it draws 3 instead of 2
--
Bug File: Dominion.c
--
Bug Line: 591
--
Bug Fix: the number got modified back to 2
_________________________

Bug Number: 3
--
Bug name: Adventurer copper count bug
--
Bug Description: Copper does not trigger the count
--
Bug File:Dominion.c
--
Bug Line: 597
--
Bug Fix: Copper got added to the if statement
_________________________

Comments:
Bugs were as reported This is the report of all bugs found and other tests ran fine.
Card test 3,4,5 and unittest 1,2,3,4 and 5 ran with no error there was how ever a bug which was overflow problem in unittest1.c

Raw report from card test on :

Testing card: Smithy

Test 1: Checking the function.
smithy function should return cost of smithy card : 4.
New Hand count is: 9.
Test 1 Passed
Test 2: Discard Pile.
Discard count is: 0.
Test 2 failed, discard count is not correct.

And,


Testing card: Adventurer

Test 1: Checking the function.
This should return Adventurer new coins in card: 6 (should be 6)
This should return the value of Adventurer card: 6
This should return Adventurer new coins in card: 5 (should be 8)

Random test's Log was too large, please look at randomtestResults-HarijanJ.c
_________________________________________________________________________________

Testing Unit updateCoins

Test 1: Checking validity of value (in range).
getting initial handCount
coinUpdate returned: 0
bonus is: 0
Number of playing player is: 0
coinUpdate set the coin value to: 6 (expected value is: 6)
handCount is: 5 (5 is expected)
Test 1 Passed

Test 2: Checking addition of coins (all the possible ways to add coin, bonus and cards).
bonus is: 1
coinUpdate set the coin value to: 6 (expected value is: 6)
coinUpdate set the coin value to: 7 (expected value is: 7)
Test 2 Passed

Test 3: Checking looking for copper, silver and gold coins.
bonus is: 0
coinUpdate set the coin value to: 6 (expected value is: 6)
adding an aditional gold card...
coinUpdate set the coin value to: 6 (expected value is: 9)
cards are:
gold, silver, copper, gold and Empty
Test 3 Passed

Test 4: Checking unexpected input
coinUpdate set the coin value to: -1304428536 (expected value is: -1304428536)
Test 4 failed: Failed to return a positive value.
_________________________________________________________
_________________________________________________________


Testing Unit isGameOver

Test 1: Checking the function.
Game is not over(expected)
Setting the province cards to 0
Game is over(expected)
Test 1 Passed

Test 2: testing decrease in province cards.
value of 0: 0
value of 1: 0
value of 2: 0
value of 3: 0
value of 4: 1
Test 2 Passed

Test 3: Testing 3 piles are at 0.
supply count of 0 was 10.
supply count of 0 now is 0.
supply count of 1 was 10.
supply count of 1 now is 0.
supply count of 2 was 10.
supply count of 2 now is 0.
Test 3 Passed

Test 4: Checking unexpected input/Output
Supplies 20, 13 and 9 are set to 0
Supplies 15, 5 and 3 are set to 0
Supplies 24, 9 and 13 are set to 0
Supplies 18, 21 and 18 are set to 0
Supplies 11, 18 and 16 are set to 0
Supplies 19, 19 and 23 are set to 0
Supplies 24, 2 and 14 are set to 0
Supplies 15, 10 and 7 are set to 0
Supplies 6, 16 and 5 are set to 0
Supplies 23, 5 and 3 are set to 0
Test 4 Passed
_________________________________________________________
_________________________________________________________


Testing Unit kingdomCards

Test 1: cecking for match between two copies.
Member 0 holds value of 7.
Member 1 holds value of 22.
Member 2 holds value of 14.
Member 3 holds value of 17.
Member 4 holds value of 11.
Member 5 holds value of 21.
Member 6 holds value of 25.
Member 7 holds value of 19.
Member 8 holds value of 13.
Member 9 holds value of 8.
Test 1 Passed
_________________________________________________________
_________________________________________________________


Testing Unit scoreFor

Test 1: Checking the function.
ScoreFor returned: 12(expected 12).
new ScoreFor returned: 17 (expected 17).
Test 1 Passed

Test 2: discarding a card.
new ScoreFor returned: 10 (expected 10).
Test 2 Passed
_________________________________________________________
_________________________________________________________


Testing card: Smithy

Test 1: Checking the function.
smithy function should return cost of smithy card : 4.
New Hand count is: 9.
Test 1 Passed
Test 2: Discard Pile.
Discard count is: 0.
Test 2 failed, discard count is not correct.
_________________________________________________________
_________________________________________________________


Testing card: Adventurer

Test 1: Checking the function.
This should return Adventurer new coins in card: 6 (should be 6)
This should return the value of Adventurer card: 6
This should return Adventurer new coins in card: 5 (should be 8)
_____________________________________________________________________________________________________
Teammate 2: LemieuxS:

Bug Number: 1
--
Bug name: Smithy Draw card Bug
--
Bug Description: The function draws 1 extra card due to a repeatition in the call to drawCard()
--
Bug File:Dominion.c
--
Bug Line: 1246
--
Bug Fix: The extra call to drawcard() was commented out
_________________________
Bug Number: 2
--
Bug name: Adventurer Smithy card Bug
--
Bug Description: This if statement gets triggered on smithy card as well as copper, gold and silver
--
Bug File: Dominion.c
--
Bug Line: 1261
--
Bug Fix: The part that was accepting smithy card "|| Smithy" was commented out
_________________________

Comments:
Bugs were as reported This is the report of all bugs found and other tests ran fine.
Card test 3,4,5 and unittest 1,2,3,4 and 5 ran with no error there was how ever a bug which was overflow problem in unittest1.c

Results on cardtests:


Testing card: Smithy

Test 1: Checking the function.
smithy function should return cost of smithy card : 4.
New Hand count is: 8.
Test 1 Passed
Test 2: Discard Pile.
Discard count is: 0.
Test 2 failed, discard count is not correct.

And,


Testing card: Adventurer

Test 1: Checking the function.
This should return Adventurer new coins in card: 6 (should be 6)
This should return the value of Adventurer card: 6
This should return Adventurer new coins in card: 8 (should be 8)
Test 1 Passed

Random test's Log was too large, please look at randomtestResults-LemieuxS.c
_________________________________________________________________________________
Testing Unit updateCoins

Test 1: Checking validity of value (in range).
getting initial handCount
coinUpdate returned: 0
bonus is: 0
Number of playing player is: 0
coinUpdate set the coin value to: 6 (expected value is: 6)
handCount is: 5 (5 is expected)
Test 1 Passed

Test 2: Checking addition of coins (all the possible ways to add coin, bonus and cards).
bonus is: 1
coinUpdate set the coin value to: 6 (expected value is: 6)
coinUpdate set the coin value to: 7 (expected value is: 7)
Test 2 Passed

Test 3: Checking looking for copper, silver and gold coins.
bonus is: 0
coinUpdate set the coin value to: 6 (expected value is: 6)
adding an aditional gold card...
coinUpdate set the coin value to: 6 (expected value is: 9)
cards are:
gold, silver, copper, gold and Empty
Test 3 Passed

Test 4: Checking unexpected input
coinUpdate set the coin value to: -1304428536 (expected value is: -1304428536)
Test 4 failed: Failed to return a positive value.
_________________________________________________________
_________________________________________________________


Testing Unit isGameOver

Test 1: Checking the function.
Game is not over(expected)
Setting the province cards to 0
Game is over(expected)
Test 1 Passed

Test 2: testing decrease in province cards.
value of 0: 0
value of 1: 0
value of 2: 0
value of 3: 0
value of 4: 1
Test 2 Passed

Test 3: Testing 3 piles are at 0.
supply count of 0 was 10.
supply count of 0 now is 0.
supply count of 1 was 10.
supply count of 1 now is 0.
supply count of 2 was 10.
supply count of 2 now is 0.
Test 3 Passed

Test 4: Checking unexpected input/Output
Supplies 1, 14 and 15 are set to 0
Supplies 16, 6 and 18 are set to 0
Supplies 15, 18 and 17 are set to 0
Supplies 7, 6 and 15 are set to 0
Supplies 21, 17 and 21 are set to 0
Supplies 15, 4 and 20 are set to 0
Supplies 1, 20 and 19 are set to 0
Supplies 7, 9 and 8 are set to 0
Supplies 24, 2 and 11 are set to 0
Supplies 15, 21 and 21 are set to 0
Test 4 Passed
_________________________________________________________
_________________________________________________________


Testing Unit kingdomCards

Test 1: cecking for match between two copies.
Member 0 holds value of 7.
Member 1 holds value of 22.
Member 2 holds value of 14.
Member 3 holds value of 17.
Member 4 holds value of 11.
Member 5 holds value of 21.
Member 6 holds value of 25.
Member 7 holds value of 19.
Member 8 holds value of 13.
Member 9 holds value of 8.
Test 1 Passed
_________________________________________________________
_________________________________________________________


Testing Unit scoreFor

Test 1: Checking the function.
ScoreFor returned: 12(expected 12).
new ScoreFor returned: 17 (expected 17).
Test 1 Passed

Test 2: discarding a card.
new ScoreFor returned: 10 (expected 10).
Test 2 Passed
_________________________________________________________
_________________________________________________________


Testing card: Smithy

Test 1: Checking the function.
smithy function should return cost of smithy card : 4.
New Hand count is: 8.
Test 1 Passed
Test 2: Discard Pile.
Discard count is: 0.
Test 2 failed, discard count is not correct.
_________________________________________________________
_________________________________________________________


Testing card: Adventurer

Test 1: Checking the function.
This should return Adventurer new coins in card: 6 (should be 6)
This should return the value of Adventurer card: 6
This should return Adventurer new coins in card: 8 (should be 8)
Test 1 Passed
_________________________________________________________

