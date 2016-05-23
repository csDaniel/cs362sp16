Carcheon

Bugs:

The Adventurer card does not draw the proper amount of coins, as noted by cardtest2.c:
	assertion `coinNum + 2 == helpCoinNum(game,p)' fails the test.

The council card does not have other players draw a card, instead they it only draws
for the current player as noted by cardtest3.c
	assertion `game.handCount[i] == handCount[i] + 1' fails the test.

Orabii

Bugs:

The Smithy card does not draw three cards and discard the smithy card, it only draws 2 cards and discard the Smithy resulting in one additional card in hand: cardtest1,
	assertion `game.handCount[p] == handCount + 2' failed 

The Adventurer card only draws one extra treasure not the two coins it needs and fails cardtest2.c
	assertion `game.handCount[p] == handCount + 3' failed


discussion in BugFixes.c




