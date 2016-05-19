=================================================
Bug Report #1 (Teammate faesslek)
=================================================

Title: adventurerCardEffect() results in no added treasure in hand

Class: Serious bug - rule violation

Date: 18 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: Dominion game
Platform: CentOS Linux 7.2.1511
Reproducible: Yes

Description
=================================================

Summary: Adventurer card should result in a net +2
  treasure cards in player's hand.

Steps to Reproduce: Call adventurerEffect() with
  valid gameState and  currentPlayer arguments.

Expected Results: +2 treasure cards in hand

Actual Results: +0 treasure cards in hand

Workarounds: None.




=================================================
Bug Report #2 (Teammate faesslek)
=================================================

Title: isGameOver() returns incorrect value

Class: Serious bug - rule violation

Date: 18 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: Dominion game
Platform: CentOS Linux 7.2.1511
Reproducible: Yes

Description
=================================================

Summary: Game should end when three non-province
  stacks in the supply are exhausted

Steps to Reproduce: Initialize valid gameState
  and then manually set # of smith cards to 0, # of
  curse cards to 0, and # of treasure_map cards to 0,
  then call isGameOver()

  Replacing treasure_map with sea_hag in the test above
  generates the same error.

  Replacing treasure_map with salvager in the test above
  DOES NOT generate an error. 

Expected Results: Function should return 1 (TRUE)

Actual Results: Funciton returns 0 (FALSE)

Workarounds: None.




=================================================
Bug Report #3 (Teammate ohaverd)
=================================================

Title: drawCouncilRoom() results in too many added buys

Class: Serious bug - rule violation

Date: 18 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: Dominion game
Platform: CentOS Linux 7.2.1511
Reproducible: Yes

Description
=================================================

Summary: Council Room card adds too many buys

Steps to Reproduce: Call drawCouncilRoom() with
  valid gameState, currentPlayer, and handPos
  arguments.

Expected Results: +1 buys

Actual Results: +2 buys

Workarounds: None.




=================================================
Bug Report #4 (Teammate ohaverd)
=================================================

Title: drawSmithy() results in too many added cards

Class: Serious bug - rule violation

Date: 18 May 2016
Reported By: stramelm
Email: stramelm@oregonstate.edu

Product: Dominion game
Platform: CentOS Linux 7.2.1511
Reproducible: Yes

Description
=================================================

Summary: Smithy card should result in 3 new cards
  added to player's hand plus the discard of the
  Smithy itself for a net +2 cards.  Bug leaves
  a net +3 cards in player's hand.

Steps to Reproduce: Call drawSmithy() with
  valid gameState, currentPlayer, and handPos
  arguments.

Expected Results: +2 cards in hand

Actual Results: +3 cards in hand

Workarounds: None.


