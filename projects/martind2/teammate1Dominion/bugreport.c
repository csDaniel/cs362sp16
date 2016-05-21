/* BUG REPORT

BUG RT001

SUBMITTED BY
Dave Martinez
martind2@oregonstate.edu
5/19/2016 4:50 PM PST

SEVERITY
Moderate

LOCATION
dominion.c:662 adventurerCard() 

EXPECTATION
Test expects the last card to be adventurer card, but is not.

STEPS TO REPRODUCE
1. Set up game with 2 players
2. Give player 0 an adventuer card
3. Execute adventurerCard(0, state)

TEST OUTPUT
CARD TEST 4: Adventurer
TEST 4: Does adventurer card go to played pile?
Player 0's played card count = 0, expected 1
Player 0's last played card = 0, expected 7

POSSIBLE CAUSE
It appears each card in the temp hand is being discaded on lines
dominion.c:864 - 690. However, no mention of the adventurerCard
being of the discarded is included in this function. This could
be due to a problem of specifications: is it the responsibility 
of the adventurerCard() to discard itself, or main()? 

Other cards do discard themselves, see dominion.c:696 
villageCard()

*/