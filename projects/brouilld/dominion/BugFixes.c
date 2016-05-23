
Bugs:
	1.) When one of the first treasury cards in the player's deck is either copper or silver, the card ends up in the discard pile.
		Resolution: 
			This issue brought to light that the if-conditional that was checking for copper, silver, 
				or gold was incorrectly setup like so:
					
					if (cardDrawn == copper && cardDrawn == silver || cardDrawn == gold)

				Because of the order of operations, the cards had to be copper AND silver, OR gold in 
				order for the conditional to resolve true.

	2.) The player's hand contains 3 more cards after playing Adventure. It should only have 2 more cards.
		Resolution:
			This bug as well as bug #1 and #3 all strongly related to each other. In this case, there was one more
				card received by the player than expected. This was due to the while-conditional statement looking
				for drawntreasue to be less than OR equal to 2, rather than the expected less than.

	3.) The player's hand contains 1 more card after playing Adventure. It should have 2 more cards.
		Resolution:
			Again, this was related to the two previous bugs. Because of the incorrect if-conditional,
				this allowed drawntreasure to be incremented, but nothing added to the player's hand

	4.) The desired card is not found in discard pile. Meanwhile the remodeled card is not fund in trash.
		Resolution:
			This occured due to 'choice2' being passed to the function responsible for trashing rather
				than 'choice1', which was expected.