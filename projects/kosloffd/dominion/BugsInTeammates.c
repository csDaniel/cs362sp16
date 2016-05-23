BugsInTeammates.c 



Found bugs in Erin Donnely's code:
	

discardCard()									

	Incorrectly changed the count of cards in the player's discard pile
	Changed the count of played cards and the cards in the 'Played Cards' pile		
	

scoreFor()										

	Didn't add up the initial score to 3 (because each player starts with 3 coppers)
	Didn't correctly add values for a 'Gardens' card in hand
	Didn't subtract values for a curse card in the discard pile or deck
	Didn't properly add values for any victory-type cards in deck (curse, duchy, province, estate, great_hall)	
	

playSmithy()									

	Incorrectly changed the number of cards in the player's hand
	Incorrectly changed the deck count for the player playing the card
	Did NOT change the count of played cards (Smithy should go in the played cards pile when played)	
	

playAdventurer()								

	Did NOT change the number of cards in the players hand or in the deck + discard pile (should have 2 more in hand, 2 less in D + D)
	Did NOT change the count of played cards (Adventurer should be in the played cards pile after playing it)	
	

cardEffect() with council_room	

	Incorrectly changed the count of played cards	


cardEffect() with remodel

	Did not return an error when trying to trade for a card that cost too much
	Changed the cards in the 'Played Cards' stack







Found bugs in Baljot Singh's code:
	

discardCard()									

	Incorrectly changed the count of cards in the player's discard pile
	Changed the count of played cards and the cards in the 'Played Cards' pile		
	

scoreFor()										

	Didn't add up the initial score to 3 (because each player starts with 3 coppers)
	Didn't correctly add values for a 'Gardens' card in hand
	Didn't subtract values for a curse card in the discard pile or deck
	Didn't properly add values for any victory-type cards in deck (curse, duchy, province, estate, great_hall)	

smithyEffect()

	Did not change the coutn of played cards

adventurerEffect()

	Incorrectly changed the number of cards in the players hand and in the deck + discard pile (should have total of 2 more in hand, 2 less in D + D)
	Did NOT change the count of played cards (Adventurer should be in the played cards pile after playing it)	
	Changed the discard count when all the treasures were found in the deck (there would be no need to shuffle, so the discard shouldn't change)

cardEffect() with council_room

	Did not change the number of buy phases available (Should add 1 Buy phase)
	Incorrectly changed the count of played cards (One card should be added -the council_room card)

card_effect() with remodel

	Did not return an error when trying to trade for a card that cost too much
	Changed the cards in the 'Played Cards' stack