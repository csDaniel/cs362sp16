----------------------------------
  Teammate 1
  Name: John Peter Fodrocy
----------------------------------

Test #: 1
Card Tested: Smithy Card
Expected Results: Smithy is supposed to add +3 cards to the hand.
Bug: Card adds twice as much (+6) to a player's hand
Causes: Could be an issue with a loop adding cards to a players hand. It could have a problem with the number of times it is looping.
Severity of Bug: Medium. Although affecting gameplay, a player can still play the game.
Priority of Bug: Medium. Since a player can still play, bugs that stop the game from running should have a higher priority.

Test Results:
----------------- Testing Card: smithy ----------------
TEST: +3 cards
Add smity Cards to user decks; handcount = 5handcount = 0handcount = 0handcount = 0
Start: Player Turn: 3; handcount: 1; handpos: 2;
Before:card=13;
After:card=13; card=4; card=4; card=1; card=1; card=4;
newCards=3
hand count before=1; hand count after=6; expected=3 FAILED

Start: Player Turn: 2; handcount: 1; handpos: 2;
Before:card=13;
After:card=13; card=1; card=4; card=4; card=4; card=4;
newCards=3
hand count before=1; hand count after=6; expected=3 FAILED


Test #: 2
Card Tested: Adventurer
Expected Results: Smithy is supposed to add +2 treasure cards to the hand.
Bug: Function adds +3 treasure cards to the hand
Causes: Could be an issue with a loop adding cards to a players hand. It could have a problem with the number of times it is looping.
Severity of Bug: Medium. Although affecting gameplay, a player can still play the game.
Priority of Bug: Medium. Since a player can still play, bugs that stop the game from running should have a higher priority.

Test Results:
----------------- Testing Card: adventurer ----------------
TEST: +2 treasure cards
Add Adventure Cards to user decks; 
Start: Player Turn: 2; handcount: 1; before_deckTreasureCount=3; handpos: 2; 
Before:card=7; 
After:card=7; card=4; card=4; card=4; newCards=2
hand count before=1; hand count after=4; expected=3 FAILED
treaure card count before =0; treaure card count after=3; expected=2 FAILED