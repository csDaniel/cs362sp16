TeamMate 1: willian2

Smithy Card:
Bug 1.
Description:  Handcount is higher 8, expected 7. Deckcount is 1, expected 2. Discard count is 0, expected 1
Location: cardEffect() ->smithy
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with Smithy
	
Bug 2. 
Description: Action count isn't decremented
Location: cardEffect() ->smithy
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with Smithy
	

Adventurer Card:
Bug 1.
Description  Adventurer is kept in hand and isn't discarded, affecting hand count and discard count
Location: cardEffect() -> adventurer
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with adventurer
	

Bug 2.
Description  Action count isn't decremented
Location: cardEffect() -> adventurer
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with adventurer
	

Bug 3.
Description  treasure cards are lower than expected when reshuffling isn't needed and is higher when reshuffling and discarding is needed
Location: cardEffect() -> adventurer
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with adventurer
	


TeamMate 2: grubbm
Smithy Bugs

Bug1.
Description: Discard count is 0, expected 1 from discarding Smithy Card
Location: cardEffect() ->smithy
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with Smithy
	
Bug 2.
Description Action count is 1, expected action count to be 0. 
Location: cardEffect() ->smithy
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with Smithy
	

Adventurer Bugs
Bug 1.
Description Handcount and discard count different than expected. Adventurer doesn't seem to be discarded
Location: cardEffect() -> adventurer
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with adventurer
	

Bug 2.
Description Adventurer card is still in hand, verified in Test 3
Location: cardEffect() -> adventurer
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with adventurer
	

Bug 3.
Description Action count isn't decremented
Location: cardEffect() -> adventurer
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with adventurer
	

Bug 4.
Description Not enough treasure cards are drawn if shuffling and discarding isn't needed
Location: cardEffect() -> adventurer
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with adventurer
	

Bug 5.
Description 4 treasure cards are drawn if shuffling and discarding is needed
Location: cardEffect() -> adventurer
Reproducable: Yes
Severity: Serious, effects game play
To Reproduce: call cardEffect or playCard with adventurer
	

