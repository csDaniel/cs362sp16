/* BUG REPORT

BUG LM001

SUBMITTED BY
Dave Martinez
martind2@oregonstate.edu
5/19/2016 4:50 PM PST

SEVERITY
High

LOCATION
dominion.c:54 council_room_card()

EXPECTATION
Player 1 should receive a card after Player 0 draws four 
after playing a councilroom. Player 1's handcount begins
at zero and should iterate to 1. 

STEPS TO REPRODUCE
1. Set up game with 2 players
2. Give player 0 a council room card
3. Execute council_room_card(state, 0, state->handLen[0]-1)

TEST OUTPUT
CARD TEST 4: council_room_card
TEST 3: Does each other player get a card?
Player 1 hand count = 0, expected 1

POSSIBLE CAUSE
dominion.c:66 for loop
The condition of the 'for' loop at this line is the likely
culprit. Rather than iteration over the number of players, 
the function only iterates to the current player. Thus, if
player 0 played a councilroom, only players in memory at 
indexes less than 0 (impossible) will recieve an extra card.

This should instead iterate up to gameState->numPlayers 
and guard against providing gameState->whoseTurn an extra
card. This guard is already in place at dominion.c:68 if.

*/