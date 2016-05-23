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

