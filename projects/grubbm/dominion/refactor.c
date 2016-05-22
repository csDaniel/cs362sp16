int playSmithy(struct gameState *state, int handPos)
Refactored to draw 4 cards instead of 3

int playAdventurer(struct gameState *state, int handPos) {
refactored while (z - 1 >= 0) to while (z - 1 > 0) to keep one card instead of discarding it 


int playFeast(struct gameState *state, int choice1)
Refactored to update update coins to 4 instead of 5



int playEmbargo(struct gameState *state, int handPos, int choice1)
Refactored to increase coins + 3 instead of + 2 

  


int playGreatHall(struct gameState *state, int handPos, int currentPlayer)
Refactored actions to +=2 rather than ++