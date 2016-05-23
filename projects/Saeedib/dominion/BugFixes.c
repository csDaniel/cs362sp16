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
