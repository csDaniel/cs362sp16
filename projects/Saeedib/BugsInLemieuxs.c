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
