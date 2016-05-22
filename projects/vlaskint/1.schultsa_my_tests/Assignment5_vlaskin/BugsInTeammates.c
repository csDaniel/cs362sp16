
%****************************PLEASE NOTE THAT MY RANDOM TESTING WORKS ACCURATELY ONLY FOR player # 0,
so in case you decide to take a look at the randomtestestcard.out and randomtestadventure.out
only look at the results for PLAYER #0

DETECTED BUG #1: ADVENTURE card HANCOUNT has failed

After the adventure card is played, the handcount is higher than
exprected, it looks like that more than 2 treasures are added to the deck of the player
or some of the revealed cards that are not treasures are placed in the deck of the
player instead of the discard pile.

Here is the output my test [ card2.c] for the Sam's adventure card.

%****************************ADVENTURE CARD TEST****************************%

Unit Test for ADVENTURE
Hand Count before Adventure Card is Played: 5

Hand Count after Adventure Card is Played:

ERROR: Hand Count Should be: 7. Instead Hand Count is: 9


DETECTED BUG #2: SMITHY CARD RANDOM TESTING HANCOUNT has failed

After the smithy card is played the handcount of the player is lower than expected. Please note that
my test works accurately only for player 0.


Here is the output my test [ randomtestcard.c] for the Sam Schultzs Smithy card.

%****************************SMITHY CARD RANDOM TESTING****************************%

Test #: 0

Player #: 0
 steward,  adventurer,  gardens,  sea_hag,  remodel,  outpost,  smithy,  treasure_map,  adventurer,  baron,  council_room,  duchy,  steward,  ambassador,  mine,  smithy,  remodel,  copper,  baron,  gold,  cutpurse,  feast,  silver,  embargo,  embargo,  steward,  sea_hag,  province,  tribute,  salvager,  cutpurse,  curse,  silver,  ambassador,  village,  minion,  minion,  curse,  great_hall,  smithy,  copper,  village,  copper,  mine,  outpost,  great_hall,  salvager,  salvager,  ambassador,  duchy,  province,  province,  mine,  feast,  treasure_map,  embargo,  great_hall,  salvager,  village,  sea_hag,  cutpurse,  council_room,  village,  treasure_map,  minion,  estate,  silver,  outpost,  steward,  mine,  feast,  mine,  sea_hag,  province,  outpost,  cutpurse,  tribute,  feast,  steward,  estate,  mine,  embargo,  silver,  mine,  ambassador,  copper,  gold,  feast,  estate,  ambassador,  adventurer,  mine,  minion,  cutpurse,  curse,  salvager,  remodel,  silver,  ambassador,  province,  great_hall,  tribute,  province,  province,  embargo,  treasure_map,  salvager,  village,  feast,  silver,  copper,  feast,  great_hall,  feast,  cutpurse,  feast,  smithy,  curse,  adventurer,  province,  gardens,  copper,  copper,  great_hall,  village,  copper,  smithy,  treasure_map,  feast,  outpost,  steward,  baron,  baron,  embargo,  steward,  gardens,  gardens,  silver,  smithy,  tribute,  gardens,  gold,  duchy,  treasure_map,  great_hall,  remodel,  salvager,  steward,  estate,  copper,  mine,  mine,  salvager,  baron,  minion,  remodel,  tribute,  tribute,  curse,  minion,  baron,  council_room,  silver,  tribute,  province,  smithy,  steward,  duchy,  steward,  ambassador,  embargo,  estate,  curse,  smithy,  great_hall,  great_hall,  sea_hag,  smithy,  outpost,  treasure_map,  gold,  adventurer,  curse,  copper,  embargo,  gold,  great_hall,  province,  village,  silver,  cutpurse,  province,  smithy,  baron,  mine,  silver,  estate,  province,  council_room,  tribute,  remodel,  tribute,  feast,  remodel,  silver,  sea_hag,  minion,  tribute,  mine,  province,  adventurer,  adventurer,  gardens,  outpost,  mine,  embargo,  steward,  great_hall,  village,  gold,  cutpurse,  council_room,  sea_hag,  council_room,  smithy,  feast,  smithy,  village,  estate,  cutpurse,  outpost,  province,  smithy,  silver,  baron,  adventurer,  ambassador,  embargo,  baron,  ambassador,  sea_hag,  remodel,  curse,  salvager,  curse,
Handcount Before: 245
Handcount After: 246
	HANDCOUNT TEST FAILED




DETECTED BUG #3: ADVENTURE CARD RANDOM TESTING HANCOUNT and TREASUARE COUNTS have failed

After the adventure card is played the handcount of the player is higher than expected [the handcount should be +2]. This bug
has aready been detected and mention above when I ran my card1 test. However, my random test for the
adventure card is more thorough. I also check for the treasure counts. When i ran the randomtestadventure card
test, the teasure count has failed after the adventure card was played.
Please note that my test works accurately only for player 0.


Here is the output of my test [ randomtestadventure.c] for the Sams Adventure card.

%****************************ADVENTURE CARD RANDOM TESTING****************************%

ADVENTURE CARD RANDOM TESTING



Test #: 0

Player #: 0
Treasures Before: 28
Treasures After: 31
	TREASURE COUNT TEST FAILED
Handcount Before: 245
Handcount After: 250
	HANDCOUNT TEST FAILED










DETECTED BUG #4: COUNCIL_ROOM card HANCOUNT has failed --- I THINK THERE IS A BUG IN MY TEST

After the council_room card is played the handcount of the CURRENT player is
not accurate [its lower than expected].This was an interesting finding because when
I looked at Sams refacto.c file, this card was not changed. However, maybe there was a bug in the
original code or maybe my unit test is wrong, however, I got expected results whne I tested my code

Here is the output my test [ card3.c] for the Sams council_room card.
%****************************COUNCIL_ROOM CARD TEST****************************%


Unit Test for council_room
Hand Count of the CURRENT player before council_room Card is Played: 5
Hand Count of the OTHER player before council_room Card is Played: 0

Hand Count Of the CURRENT Player after council_room Card is Played:

ERROR: Hand Count Should be: 9. Instead Hand Count is: 8

Hand Count Of the OTHER Player after council_room Card is Played:

No Errors were detected in the Council_room card. Hand Count is: 1

Here is the




