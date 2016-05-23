Bugs found in partner 1: murphet
Unit testing found bugs 1 - 5.  Random testing confirmed bug 4 and found 6.
1.	Bug in scoreFor().There is a bug in how it determines the score for gardens.When the hand, discard and deck all have only 5 cards(all gardens), it does not give the expected score of 15.
2.	Bug in scoreFor().This bug has to do with different size hands.When the hand has 4 estates, discard has 5 estates and deck have 6 estates, it does not produce the expected output of 15.
3.	Bug in Smithy.After initializing a new game and playing Smithy, there are three incorrect values.First, the players hand count is supposed to be 3 but is actual 8.  Discard count is expected to be 1 but is actual 0.  Opponent’s deck is supposed to be 0, but is actually - 1.
4.	Bug in adventurer.After initializing a new game and playing adventurer, there are two incorrect values.First, player’s hand count is expected to be 6 but is actually 7.  Secondly, discard, deck and played count(combined) is expected to be 4 but is actually 3.
5.	Bug in gardens.After initializing a new game and playing gardens, hand count is expected to be 4 but is actually 5. The sum of discard deck and played deck is expected to be 1 but is actually 0.
6.	Bug in adventurer : In random testing, 98.9% of tests had an error in the count of treasures cards in hand and count of treasure cards in discard + deck + played decks.

Bugs found in partner 2 : mailarw
Unit testing found all 6 bugs.Random testing also found bugs 4 and 6.
1.	Bug in scoreFor().There is a bug in how it determines the score for gardens.When the hand, discard and deck all have only 5 cards(all gardens), it does not give the expected score of 15.
2.	Bug in scoreFor().This bug has to do with different size hands.When the hand has 4 estates, discard has 5 estates and deck have 6 estates, it does not produce the expected output of 15.
3.	Bug in Smithy.After initializing a new game and playing Smithy, the player’s hand count is expected to be 3 but is actually 4.  The deck is count is expected to be 2 but is actually 5.
4.	Bug in Adventurer.After initializing a new game and playing adventurer, the player’s hand count is expected to be 6 but is actually 7.  The discard and played count is expected to be 4, but is actually 3.
5.	Bug in gardens.After initializing a new game and playing gardens, hand count is expected to be 4 but is actually 5. The sum of discard deck and played deck is expected to be 1 but is actually 0.
6.	Bug in Village.After initializing a new game and playing village, the deck count is expected to be 4 but is actually 5.  The opponents deck count is expected to be 10 but is actually 9.


_____****** Raw Testing Results for murphet ******_____
TESTING updateCoins() :
	All tests passed!
	File 'dominion.c'
	Lines executed : 15.94% of 571
	Branches executed : 15.83% of 417
	Taken at least once : 13.43% of 417
	Calls executed : 7.00% of 100
	Creating 'dominion.c.gcov'

	Testing getCost()All Tests Past!File 'dominion.c'
	Lines executed : 21.19% of 571
	Branches executed : 22.54% of 417
	Taken at least once : 20.14% of 417
	Calls executed : 7.00% of 100
	Creating 'dominion.c.gcov'

	TESTING isGameOver :
All tests passed!
File 'dominion.c'
Lines executed : 22.94% of 571
Branches executed : 24.46% of 417
Taken at least once : 22.06% of 417
Calls executed : 7.00% of 100
Creating 'dominion.c.gcov'

TESTING compare()
All test passed
File 'dominion.c'
Lines executed : 23.12% of 571
Branches executed : 24.46% of 417
Taken at least once : 22.30% of 417
Calls executed : 7.00% of 100
Creating 'dominion.c.gcov'

TESTING scoreFor()
Error on gardens!
Error on different size decks!
File 'dominion.c'
Lines executed : 28.90% of 571
Branches executed : 37.41% of 417
Taken at least once : 34.53% of 417
Calls executed : 10.00% of 100
Creating 'dominion.c.gcov'

TESTING smithy :
Error with hand count : Expected: 3.  Actual : 8
Error with discard count : Expected: 1.  Actual : 0
Error with opponents deck : Expected: 0.  Actual : -1
File 'dominion.c'
Lines executed : 33.63% of 571
Branches executed : 44.84% of 417
Taken at least once : 36.21% of 417
Calls executed : 15.00% of 100
Creating 'dominion.c.gcov'

TESTING adventurer :
Error with hand count : Expected: 6.  Actual : 7
Error with discard and deck count and played : Expected : 4.  Actual : 3
File 'dominion.c'
Lines executed : 36.08% of 571
Branches executed : 46.76% of 417
Taken at least once : 37.65% of 417
Calls executed : 18.00% of 100
Creating 'dominion.c.gcov'

TESTING Gardens :
Error with hand count : Expected: 4.  Actual : 5
Error with discard count and played card : Expected: 1.  Actual : 0
File 'dominion.c'
Lines executed : 36.25% of 571
Branches executed : 46.76% of 417
Taken at least once : 37.89% of 417
Calls executed : 18.00% of 100
Creating 'dominion.c.gcov'

TESTING Village :
All tests passed!
File 'dominion.c'
Lines executed : 37.30% of 571
Branches executed : 46.76% of 417
Taken at least once : 38.37% of 417
Calls executed : 20.00% of 100
Creating 'dominion.c.gcov'

- : 0 : Source : dominion.c
- : 0 : Graph : dominion.gcno
- : 0 : Data : dominion.gcda
- : 0 : Runs : 9
- : 0 : Programs : 9
- : 1 : #include "dominion.h"
- : 2 : #include "dominion_helpers.h"
- : 3 : #include "rngs.h"
- : 4 : #include <stdio.h>
- : 5 : #include <math.h>
- : 6 : #include <stdlib.h>
- : 7 :
	function compare called 3757 returned 100 % blocks executed 100 %
	3757 : 8 : int compare(const void* a, const void* b) {
	3757:    9 : if (*(int*)a > *(int*)b)
		branch  0 taken 1 % (fallthrough)
		branch  1 taken 99 %
		3 : 10 : return 1;
	3754:   11 : if (*(int*)a < *(int*)b)
		branch  0 taken 27 % (fallthrough)
		branch  1 taken 73 %
		1003 : 12 : return -1;
	2751:   13 : return 0;
	-:   14 :
}
-:   15 :
	function newGame called 0 returned 0 % blocks executed 0 %
#####:   16:struct gameState* newGame() {
#####:   17:  struct gameState* g = malloc(sizeof(struct gameState));
#####:   18:  return g;
	-:   19 : }
-: 20 :
	function kingdomCards called 0 returned 0 % blocks executed 0 %
#####:   21:int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
	-:   22 : int k8, int k9, int k10) {
#####:   23:  int* k = malloc(10 * sizeof(int));
#####:   24:  k[0] = k1;
#####:   25:  k[1] = k2;
#####:   26:  k[2] = k3;
#####:   27:  k[3] = k4;
#####:   28:  k[4] = k5;
#####:   29:  k[5] = k6;
#####:   30:  k[6] = k7;
#####:   31:  k[7] = k8;
#####:   32:  k[8] = k9;
#####:   33:  k[9] = k10;
#####:   34:  return k;
	-:   35 :
}
-:   36 :
	function initializeGame called 125 returned 100 % blocks executed 88 %
	125 : 37 : int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
		-:   38 : struct gameState *state) {
	-:   39 :
		-: 40 : int i;
	-:   41 : int j;
	-:   42 : int it;
	-:   43 :  //set up random number generator
		125 : 44 : SelectStream(1);
	call    0 returned 100 %
		125:   45 : PutSeed((long)randomSeed);
	call    0 returned 100 %
		-:   46 :
		-: 47 :  //check number of players
		125 : 48 : if (numPlayers > MAX_PLAYERS || numPlayers < 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		branch  2 taken 0 % (fallthrough)
		branch  3 taken 100 %
		-: 49 : {
#####:   50:      return -1;
		-:   51 : }
	-: 52 :
		-: 53 :  //set number of players
		125 : 54 : state->numPlayers = numPlayers;
	-:   55 :
		-: 56 :  //check selected kingdom cards are different
		1375 : 57 : for (i = 0; i < 10; i++)
		branch  0 taken 91 %
		branch  1 taken 9 % (fallthrough)
		-: 58 : {
		13750:   59 : for (j = 0; j < 10; j++)
			branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			-: 60 : {
			12500:   61 : if (j != i && kingdomCards[j] == kingdomCards[i])
				branch  0 taken 90 % (fallthrough)
				branch  1 taken 10 %
				branch  2 taken 0 % (fallthrough)
				branch  3 taken 100 %
				-: 62 : {
#####:   63:	      return -1;
				-:   64 : }
			-: 65 : }
		-:   66 : }
	-:   67 :
		-: 68 :
		-: 69 :  //initialize supply
		-: 70 :  ///////////////////////////////
		-: 71 :
		-: 72 :  //set number of Curse cards
		125 : 73 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 74 : {
		125:   75 : state->supplyCount[curse] = 10;
		-:   76 : }
#####:   77:  else if (numPlayers == 3)
	branch  0 never executed
		branch  1 never executed
		- :   78 : {
#####:   79:      state->supplyCount[curse] = 20;
		-:   80 : }
	-: 81 : else
		- :   82 : {
#####:   83:      state->supplyCount[curse] = 30;
		-:   84 : }
	-: 85 :
		-: 86 :  //set number of Victory cards
		125 : 87 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 88 : {
		125:   89 : state->supplyCount[estate] = 8;
		125:   90 : state->supplyCount[duchy] = 8;
		125:   91 : state->supplyCount[province] = 8;
		-:   92 : }
	-: 93 : else
		- :   94 : {
#####:   95:      state->supplyCount[estate] = 12;
#####:   96:      state->supplyCount[duchy] = 12;
#####:   97:      state->supplyCount[province] = 12;
		-:   98 : }
	-: 99 :
		-: 100 :  //set number of Treasure cards
		125 : 101 : state->supplyCount[copper] = 60 - (7 * numPlayers);
	125:  102 : state->supplyCount[silver] = 40;
	125:  103 : state->supplyCount[gold] = 30;
	-:  104 :
		-: 105 :  //set number of Kingdom cards
		2625 : 106 : for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
		branch  0 taken 95 %
		branch  1 taken 5 % (fallthrough)
		-: 107 : {
		20625:  108 : for (j = 0; j < 10; j++)           		//loop chosen cards
			branch  0 taken 94 %
			branch  1 taken 6 % (fallthrough)
			-: 109 : {
			19375:  110 : if (kingdomCards[j] == i)
				branch  0 taken 6 % (fallthrough)
				branch  1 taken 94 %
				-: 111 : {
				-:  112 :	      //check if card is a 'Victory' Kingdom card
					1250 : 113 : if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
					branch  0 taken 90 % (fallthrough)
					branch  1 taken 10 %
					branch  2 taken 11 % (fallthrough)
					branch  3 taken 89 %
					-: 114 : {
					500:  115 : if (numPlayers == 2) {
						branch  0 taken 100 % (fallthrough)
							branch  1 taken 0 %
							250:  116 : state->supplyCount[i] = 8;
						-:  117 :
					}
#####:  118:		  else{ state->supplyCount[i] = 12; }
					-:  119 : }
				-:  120 : else
					- :  121 : {
					1000:  122 : state->supplyCount[i] = 10;
					-:  123 : }
				1250 : 124 : break;
				-:  125 : }
			-:  126 : else    //card is not in the set choosen for the game
				- :  127 : {
				18125:  128 : state->supplyCount[i] = -1;
				-:  129 : }
			-: 130 : }
		-:  131 :
			-: 132 : }
	-:  133 :
		-: 134 :  ////////////////////////
		-: 135 :  //supply intilization complete
		-: 136 :
		-: 137 :  //set player decks
		375 : 138 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 139 : {
		250:  140 : state->deckCount[i] = 0;
		1000:  141 : for (j = 0; j < 3; j++)
			branch  0 taken 75 %
			branch  1 taken 25 % (fallthrough)
			-: 142 : {
			750:  143 : state->deck[i][j] = estate;
			750:  144 : state->deckCount[i]++;
			-:  145 : }
		2000 : 146 : for (j = 3; j < 10; j++)
			branch  0 taken 88 %
			branch  1 taken 13 % (fallthrough)
			-: 147 : {
			1750:  148 : state->deck[i][j] = copper;
			1750:  149 : state->deckCount[i]++;
			-:  150 : }
		-: 151 : }
	-:  152 :
		-: 153 :  //shuffle player decks
		375 : 154 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 155 : {
		250:  156 : if (shuffle(i, state) < 0)
			call    0 returned 100 %
			branch  1 taken 0 % (fallthrough)
			branch  2 taken 100 %
			-: 157 : {
#####:  158:	  return -1;
			-:  159 : }
		-: 160 : }
	-:  161 :
		-: 162 :  //draw player hands
		375 : 163 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 164 : {
		-:  165 :      //initialize hand size to zero
			250 : 166 : state->handCount[i] = 0;
		250:  167 : state->discardCount[i] = 0;
		-:  168 :      //draw 5 cards
			-: 169 :      // for (j = 0; j < 5; j++)
			-: 170 :      //	{
			-: 171 :      //	  drawCard(i, state);
			-: 172 :      //	}
			-: 173 : }
	-:  174 :
		-: 175 :  //set embargo tokens to 0 for all supply piles
		3500 : 176 : for (i = 0; i <= treasure_map; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 177 : {
		3375:  178 : state->embargoTokens[i] = 0;
		-:  179 : }
	-: 180 :
		-: 181 :  //initialize first player's turn
		125 : 182 : state->outpostPlayed = 0;
	125:  183 : state->phase = 0;
	125:  184 : state->numActions = 1;
	125:  185 : state->numBuys = 1;
	125:  186 : state->playedCardCount = 0;
	125:  187 : state->whoseTurn = 0;
	125:  188 : state->handCount[state->whoseTurn] = 0;
	-:  189 :  //int it; move to top
		-: 190 :
		-: 191 :  //Moved draw cards to here, only drawing at the start of a turn
		750 : 192 : for (it = 0; it < 5; it++) {
		branch  0 taken 83 %
			branch  1 taken 17 % (fallthrough)
			625:  193 : drawCard(state->whoseTurn, state);
		call    0 returned 100 %
			-:  194 :
	}
	-:  195 :
		125 : 196 : updateCoins(state->whoseTurn, state, 0);
	call    0 returned 100 %
		-:  197 :
		125 : 198 : return 0;
	-:  199 :
}
-:  200 :
	function shuffle called 250 returned 100 % blocks executed 94 %
	250 : 201 : int shuffle(int player, struct gameState *state) {
	-:  202 :
		-: 203 :
		-: 204 : int newDeck[MAX_DECK];
	250:  205 : int newDeckPos = 0;
	-:  206 : int card;
	-:  207 : int i;
	-:  208 :
		250 : 209 : if (state->deckCount[player] < 1)
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
#####:  210:    return -1;
		250:  211 : qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
	call    0 returned 100 %
		-:  212 :  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
		-: 213 :
		3000 : 214 : while (state->deckCount[player] > 0) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			2500:  215 : card = floor(Random() * state->deckCount[player]);
		call    0 returned 100 %
			2500:  216 : newDeck[newDeckPos] = state->deck[player][card];
		2500:  217 : newDeckPos++;
		8750:  218 : for (i = card; i < state->deckCount[player] - 1; i++) {
			branch  0 taken 71 %
				branch  1 taken 29 % (fallthrough)
				6250:  219 : state->deck[player][i] = state->deck[player][i + 1];
			-:  220 :
		}
		2500:  221 : state->deckCount[player]--;
		-:  222 :
	}
	2750:  223 : for (i = 0; i < newDeckPos; i++) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			2500:  224 : state->deck[player][i] = newDeck[i];
		2500:  225 : state->deckCount[player]++;
		-:  226 :
	}
	-:  227 :
		250 : 228 : return 0;
	-:  229 :
}
-:  230 :
	function playCard called 0 returned 0 % blocks executed 0 %
#####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
	- : 232 : {
	-:  233 : int card;
#####:  234:  int coin_bonus = 0; 		//tracks coins gain from actions
	-:  235 :
		-: 236 :  //check if it is the right phase
#####:  237:  if (state->phase != 0)
		branch  0 never executed
		branch  1 never executed
		- : 238 : {
#####:  239:      return -1;
		-:  240 : }
	-: 241 :
		-: 242 :  //check if player has enough actions
#####:  243:  if ( state->numActions < 1 )
		branch  0 never executed
		branch  1 never executed
		- : 244 : {
#####:  245:      return -1;
		-:  246 : }
	-: 247 :
		-: 248 :  //get card played
#####:  249:  card = handCard(handPos, state);
		call    0 never executed
		- :  250 :
		-: 251 :  //check if selected card is an action
#####:  252:  if ( card < adventurer || card > treasure_map )
		branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 253 : {
#####:  254:      return -1;
		-:  255 : }
	-: 256 :
		-: 257 :  //play card
#####:  258:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 259 : {
#####:  260:      return -1;
		-:  261 : }
	-: 262 :
		-: 263 :  //reduce number of actions
#####:  264:  state->numActions--;
		-:  265 :
		-: 266 :  //update coins (Treasure cards may be added with card draws)
#####:  267:  updateCoins(state->whoseTurn, state, coin_bonus);
		call    0 never executed
		- :  268 :
#####:  269:  return 0;
		-:  270 : }
-:  271 :
	function buyCard called 0 returned 0 % blocks executed 0 %
#####:  272:int buyCard(int supplyPos, struct gameState *state) {
	-:  273 : int who;
-:  274 : if (DEBUG) {
	-:  275 : printf("Entering buyCard...\n");
	-:  276 :
}
-: 277 :
	-: 278 :  // I don't know what to do about the phase thing.
	-: 279 :
#####:  280:  who = state->whoseTurn;
	-:  281 :
#####:  282:  if (state->numBuys < 1){
	branch  0 never executed
	branch  1 never executed
	- :  283 : if (DEBUG)
	-: 284 : printf("You do not have any buys left\n");
#####:  285:    return -1;
#####:  286:  } else if (supplyCount(supplyPos, state) <1){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  287 : if (DEBUG)
-: 288 : printf("There are not any of that type of card left\n");
#####:  289:    return -1;
#####:  290:  } else if (state->coins < getCost(supplyPos)){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  291 : if (DEBUG)
-: 292 : printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
#####:  293:    return -1;
-:  294 : }
else {
#####:  295:    state->phase=1;
	-:  296 :    //state->supplyCount[supplyPos]--;
#####:  297:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
		call    0 never executed
		- :  298 :
#####:  299:    state->coins = (state->coins) - (getCost(supplyPos));
		call    0 never executed
#####:  300:    state->numBuys--;
		-:  301 : if (DEBUG)
		-: 302 : printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
	-:  303 :
}
-:  304 :
	-: 305 :  //state->discard[who][state->discardCount[who]] = supplyPos;
	-: 306 :  //state->discardCount[who]++;
	-: 307 :
#####:  308:  return 0;
	-:  309 : }
-:  310 :
	function numHandCards called 0 returned 0 % blocks executed 0 %
#####:  311:int numHandCards(struct gameState *state) {
#####:  312:  return state->handCount[ whoseTurn(state) ];
	call    0 never executed
	- :  313 : }
-: 314 :
	function handCard called 0 returned 0 % blocks executed 0 %
#####:  315:int handCard(int handPos, struct gameState *state) {
#####:  316:  int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  317:  return state->hand[currentPlayer][handPos];
	-:  318 : }
-: 319 :
	function supplyCount called 0 returned 0 % blocks executed 0 %
#####:  320:int supplyCount(int card, struct gameState *state) {
#####:  321:  return state->supplyCount[card];
	-:  322 : }
-: 323 :
	function fullDeckCount called 15 returned 100 % blocks executed 82 %
	15 : 324 : int fullDeckCount(int player, int card, struct gameState *state) {
	-:  325 : int i;
	15:  326 : int count = 0;
	-:  327 :
		90 : 328 : for (i = 0; i < state->deckCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 329 : {
		75:  330 : if (state->deck[player][i] == card) count++;
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-:  331 : }
	-: 332 :
		90 : 333 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 334 : {
		75:  335 : if (state->hand[player][i] == card) count++;
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-:  336 : }
	-: 337 :
		90 : 338 : for (i = 0; i < state->discardCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 339 : {
		75:  340 : if (state->discard[player][i] == card) count++;
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-:  341 : }
	-: 342 :
		15 : 343 : return count;
	-:  344 :
}
-:  345 :
	function whoseTurn called 6 returned 100 % blocks executed 100 %
	6 : 346 : int whoseTurn(struct gameState *state) {
	6:  347 : return state->whoseTurn;
	-:  348 :
}
-: 349 :
	function endTurn called 0 returned 0 % blocks executed 0 %
#####:  350:int endTurn(struct gameState *state) {
	-:  351 : int k;
-:  352 : int i;
#####:  353:  int currentPlayer = whoseTurn(state);
call    0 never executed
- :  354 :
	-: 355 :  //Discard hand
#####:  356:  for (i = 0; i < state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####:  357:    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
#####:  358:    state->hand[currentPlayer][i] = -1;//Set card to -1
	-:  359 : }
#####:  360:  state->handCount[currentPlayer] = 0;//Reset hand count
-:  361 :
	-: 362 :  //Code for determining the player
#####:  363:  if (currentPlayer < (state->numPlayers - 1)){ 
	branch  0 never executed
	branch  1 never executed
#####:  364:    state->whoseTurn = currentPlayer + 1;//Still safe to increment
	-:  365 : }
-: 366 : else {
#####:  367:    state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
	-:  368 :
}
-:  369 :
#####:  370:  state->outpostPlayed = 0;
#####:  371:  state->phase = 0;
#####:  372:  state->numActions = 1;
#####:  373:  state->coins = 0;
#####:  374:  state->numBuys = 1;
#####:  375:  state->playedCardCount = 0;
#####:  376:  state->handCount[state->whoseTurn] = 0;
	-:  377 :
	-: 378 :  //int k; move to top
	-: 379 :  //Next player draws hand
#####:  380:  for (k = 0; k < 5; k++){
	branch  0 never executed
	branch  1 never executed
#####:  381:    drawCard(state->whoseTurn, state);//Draw a card
	call    0 never executed
	- :  382 : }
-:  383 :
	-: 384 :  //Update money
#####:  385:  updateCoins(state->whoseTurn, state , 0);
	call    0 never executed
	- :  386 :
#####:  387:  return 0;
	-:  388 : }
-:  389 :
	function isGameOver called 7 returned 100 % blocks executed 100 %
	7 : 390 : int isGameOver(struct gameState *state) {
	-:  391 : int i;
	-:  392 : int j;
	-:  393 :
		-: 394 :  //if stack of Province cards is empty, the game ends
		7 : 395 : if (state->supplyCount[province] == 0)
		branch  0 taken 29 % (fallthrough)
		branch  1 taken 71 %
		-: 396 : {
		2:  397 : return 1;
		-:  398 : }
	-: 399 :
		-: 400 :  //if three supply pile are at 0, the game ends
		5 : 401 : j = 0;
	130:  402 : for (i = 0; i < 25; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 403 : {
		125:  404 : if (state->supplyCount[i] == 0)
			branch  0 taken 8 % (fallthrough)
			branch  1 taken 92 %
			-: 405 : {
			10:  406 : j++;
			-:  407 : }
		-: 408 : }
	5:  409 : if (j >= 3)
		branch  0 taken 40 % (fallthrough)
		branch  1 taken 60 %
		-: 410 : {
		2:  411 : return 1;
		-:  412 : }
	-: 413 :
		3 : 414 : return 0;
	-:  415 :
}
-:  416 :
	function scoreFor called 9 returned 100 % blocks executed 100 %
	9 : 417 : int scoreFor(int player, struct gameState *state) {
	-:  418 :
		-: 419 : int i;
	9:  420 : int score = 0;
	-:  421 :  //score from hand
		48 : 422 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 81 %
		branch  1 taken 19 % (fallthrough)
		-: 423 : {
		39:  424 : if (state->hand[player][i] == curse) { score = score - 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			39:  425 : if (state->hand[player][i] == estate) { score = score + 1; };
		branch  0 taken 23 % (fallthrough)
			branch  1 taken 77 %
			39:  426 : if (state->hand[player][i] == duchy) { score = score + 3; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			39:  427 : if (state->hand[player][i] == province) { score = score + 6; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			39:  428 : if (state->hand[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			39:  429 : if (state->hand[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			call    2 returned 100 %
			-:  430 : }
	-:  431 :
		-: 432 :  //score from discard
		49 : 433 : for (i = 0; i < state->discardCount[player]; i++)
		branch  0 taken 82 %
		branch  1 taken 18 % (fallthrough)
		-: 434 : {
		40:  435 : if (state->discard[player][i] == curse) { score = score - 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  436 : if (state->discard[player][i] == estate) { score = score + 1; };
		branch  0 taken 25 % (fallthrough)
			branch  1 taken 75 %
			40:  437 : if (state->discard[player][i] == duchy) { score = score + 3; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  438 : if (state->discard[player][i] == province) { score = score + 6; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  439 : if (state->discard[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  440 : if (state->discard[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			call    2 returned 100 %
			-:  441 : }
	-:  442 :
		-: 443 :  //score from deck
		49 : 444 : for (i = 0; i < state->discardCount[player]; i++)
		branch  0 taken 82 %
		branch  1 taken 18 % (fallthrough)
		-: 445 : {
		40:  446 : if (state->deck[player][i] == curse) { score = score - 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  447 : if (state->deck[player][i] == estate) { score = score + 1; };
		branch  0 taken 25 % (fallthrough)
			branch  1 taken 75 %
			40:  448 : if (state->deck[player][i] == duchy) { score = score + 3; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  449 : if (state->deck[player][i] == province) { score = score + 6; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  450 : if (state->deck[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  451 : if (state->deck[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			call    2 returned 100 %
			-:  452 : }
	-:  453 :
		9 : 454 : return score;
	-:  455 :
}
-:  456 :
	function getWinners called 0 returned 0 % blocks executed 0 %
#####:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
	-:  458 : int i;
-:  459 : int j;
-:  460 : int highScore;
-:  461 : int currentPlayer;
-:  462 :
	-: 463 :  //get score for each player
#####:  464:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 465 : {
	-:  466 :      //set unused player scores to -9999
#####:  467:      if (i >= state->numPlayers)
		branch  0 never executed
		branch  1 never executed
		- : 468 : {
#####:  469:	  players[i] = -9999;
		-:  470 : }
	-: 471 : else
		- :  472 : {
#####:  473:	  players[i] = scoreFor (i, state);
		call    0 never executed
			- :  474 : }
	-: 475 : }
-:  476 :
	-: 477 :  //find highest score
#####:  478:  j = 0;
#####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 480 : {
#####:  481:      if (players[i] > players[j])
	branch  0 never executed
		branch  1 never executed
		- : 482 : {
#####:  483:	  j = i;
		-:  484 : }
	-: 485 : }
#####:  486:  highScore = players[j];
-:  487 :
	-: 488 :  //add 1 to players who had less turns
#####:  489:  currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 491 : {
#####:  492:      if ( players[i] == highScore && i > currentPlayer )
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 493 : {
#####:  494:	  players[i]++;
		-:  495 : }
	-: 496 : }
-:  497 :
	-: 498 :  //find new highest score
#####:  499:  j = 0;
#####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 501 : {
#####:  502:      if ( players[i] > players[j] )
	branch  0 never executed
		branch  1 never executed
		- : 503 : {
#####:  504:	  j = i;
		-:  505 : }
	-: 506 : }
#####:  507:  highScore = players[j];
-:  508 :
	-: 509 :  //set winners in array to 1 and rest to 0
#####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 511 : {
#####:  512:      if ( players[i] == highScore )
	branch  0 never executed
		branch  1 never executed
		- : 513 : {
#####:  514:	  players[i] = 1;
		-:  515 : }
	-: 516 : else
		- :  517 : {
#####:  518:	  players[i] = 0;
		-:  519 : }
	-: 520 : }
-:  521 :
#####:  522:  return 0;
	-:  523 : }
-:  524 :
	function drawCard called 631 returned 100 % blocks executed 38 %
	631 : 525 : int drawCard(int player, struct gameState *state)
	- : 526 : {	int count;
-:  527 : int deckCounter;
631:  528 : if (state->deckCount[player] <= 0) {//Deck is empty
	branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-:  529 :
		-: 530 :    //Step 1 Shuffle the discard pile back into a deck
		-: 531 : int i;
	-:  532 :    //Move discard to deck
#####:  533:    for (i = 0; i < state->discardCount[player];i++){
		branch  0 never executed
		branch  1 never executed
#####:  534:      state->deck[player][i] = state->discard[player][i];
#####:  535:      state->discard[player][i] = -1;
		-:  536 : }
	-:  537 :
#####:  538:    state->deckCount[player] = state->discardCount[player];
#####:  539:    state->discardCount[player] = 0;//Reset discard
		-:  540 :
		-: 541 :    //Shufffle the deck
#####:  542:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
		call    0 never executed
		- :  543 :
		-: 544 : if (DEBUG) {//Debug statements
		-:  545 : printf("Deck count now: %d\n", state->deckCount[player]);
		-:  546 :
	}
	-: 547 :
#####:  548:    state->discardCount[player] = 0;
		-:  549 :
		-: 550 :    //Step 2 Draw Card
#####:  551:    count = state->handCount[player];//Get current player's hand count
		-:  552 :
		-: 553 : if (DEBUG) {//Debug statements
		-:  554 : printf("Current hand count: %d\n", count);
		-:  555 :
	}
	-: 556 :
#####:  557:    deckCounter = state->deckCount[player];//Create a holder for the deck count
		-:  558 :
#####:  559:    if (deckCounter == 0)
		branch  0 never executed
		branch  1 never executed
#####:  560:      return -1;
		-:  561 :
#####:  562:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
#####:  563:    state->deckCount[player]--;
#####:  564:    state->handCount[player]++;//Increment hand count
		-:  565 :
}
-:  566 :
	-: 567 : else {
	631:  568 : int count = state->handCount[player];//Get current hand count for player
	-:  569 : int deckCounter;
	-:  570 : if (DEBUG) {//Debug statements
		-:  571 : printf("Current hand count: %d\n", count);
		-:  572 :
	}
	-: 573 :
		631 : 574 : deckCounter = state->deckCount[player];//Create holder for the deck count
	631:  575 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
	631:  576 : state->deckCount[player]--;
	631:  577 : state->handCount[player]++;//Increment hand count
	-:  578 :
}
-:  579 :
	631 : 580 : return 0;
-:  581 : }
-:  582 :
	function getCost called 29 returned 100 % blocks executed 100 %
	29 : 583 : int getCost(int cardNumber)
	- : 584 : {
	29:  585 : switch (cardNumber)
		branch  0 taken 3 %
		branch  1 taken 3 %
		branch  2 taken 3 %
		branch  3 taken 3 %
		branch  4 taken 3 %
		branch  5 taken 3 %
		branch  6 taken 3 %
		branch  7 taken 3 %
		branch  8 taken 3 %
		branch  9 taken 3 %
		branch 10 taken 3 %
		branch 11 taken 3 %
		branch 12 taken 3 %
		branch 13 taken 3 %
		branch 14 taken 3 %
		branch 15 taken 3 %
		branch 16 taken 3 %
		branch 17 taken 3 %
		branch 18 taken 3 %
		branch 19 taken 3 %
		branch 20 taken 3 %
		branch 21 taken 3 %
		branch 22 taken 3 %
		branch 23 taken 3 %
		branch 24 taken 3 %
		branch 25 taken 3 %
		branch 26 taken 3 %
		branch 27 taken 7 %
		-:  586 : {
		-:  587 : case curse:
			1 : 588 : return 0;
			-:  589 : case estate:
				1 : 590 : return 2;
				-:  591 : case duchy:
					1 : 592 : return 5;
					-:  593 : case province:
						1 : 594 : return 8;
						-:  595 : case copper:
							1 : 596 : return 0;
							-:  597 : case silver:
								1 : 598 : return 3;
								-:  599 : case gold:
									1 : 600 : return 6;
									-:  601 : case adventurer:
										1 : 602 : return 6;
										-:  603 : case council_room:
											1 : 604 : return 5;
											-:  605 : case feast:
												1 : 606 : return 4;
												-:  607 : case gardens:
													1 : 608 : return 4;
													-:  609 : case mine:
														1 : 610 : return 5;
														-:  611 : case remodel:
															1 : 612 : return 4;
															-:  613 : case smithy:
																1 : 614 : return 4;
																-:  615 : case village:
																	1 : 616 : return 3;
																	-:  617 : case baron:
																		1 : 618 : return 4;
																		-:  619 : case great_hall:
																			1 : 620 : return 3;
																			-:  621 : case minion:
																				1 : 622 : return 5;
																				-:  623 : case steward:
																					1 : 624 : return 3;
																					-:  625 : case tribute:
																						1 : 626 : return 5;
																						-:  627 : case ambassador:
																							1 : 628 : return 3;
																							-:  629 : case cutpurse:
																								1 : 630 : return 4;
																								-:  631 : case embargo:
																									1 : 632 : return 2;
																									-:  633 : case outpost:
																										1 : 634 : return 5;
																										-:  635 : case salvager:
																											1 : 636 : return 4;
																											-:  637 : case sea_hag:
																												1 : 638 : return 4;
																												-:  639 : case treasure_map:
																													1 : 640 : return 4;
																													-:  641 : }
	-:  642 :
		2 : 643 : return -1;
	-:  644 : }
-:  645 :
	-: 646 :
	function council_room_function called 0 returned 0 % blocks executed 0 %
#####:  647:int council_room_function( struct gameState *state, int handPos )
	- : 648 : {
#####:  649:  int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  650 :   //+4 Cards
		-: 651 : int i;
#####:  652:      for (i = 0; i < 4; i++)
	branch  0 never executed
		branch  1 never executed
		- : 653 : {
#####:  654:	  drawCard(currentPlayer, state);
		call    0 never executed
			- :  655 : }
	-: 656 :
		-: 657 :      //+1 Buy
#####:  658:      state->numBuys = state->numBuys + state->numBuys;
		-:  659 :
		-: 660 :      //Each other player draws a card
#####:  661:      for (i = 1; i < state->numPlayers; i++)
		branch  0 never executed
		branch  1 never executed
		- : 662 : {
#####:  663:	  if ( i != currentPlayer )
		branch  0 never executed
			branch  1 never executed
			- : 664 : {
#####:  665:	      drawCard(i, state);
			call    0 never executed
				- :  666 : }
		-: 667 : }
	-:  668 :
		-: 669 :      //put played card in played card pile
#####:  670:      discardCard(handPos, currentPlayer+1 , state, 0);
		call    0 never executed
#####:  671:      return 0;
		-:  672 : }
-:  673 :
	function adventurer_function called 1 returned 100 % blocks executed 69 %
	1 : 674 : int adventurer_function(struct gameState *state, int handPos)
	- : 675 : {
	1:  676 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		-:  677 : int temphand[MAX_HAND];// moved above the if statement
	1:  678 : int drawntreasure = 0;
	-:  679 : int cardDrawn;
	1:  680 : int z = 0;// this is the counter for the temp hand
	-:  681 :
		4 : 682 : while (drawntreasure<2) {
		branch  0 taken 67 %
			branch  1 taken 33 % (fallthrough)
			2:  683 : if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			branch  0 taken 0 % (fallthrough)
				branch  1 taken 100 %
#####:  684:	  shuffle(currentPlayer, state);
				call    0 never executed
				- :  685 :
		}
		2:  686 : drawCard(currentPlayer, state);
		call    0 returned 100 %
			2:  687 : cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		2:  688 : if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			branch  2 never executed
			branch  3 never executed
			branch  4 never executed
			branch  5 never executed
			2:  689 : drawntreasure++;
		-:  690 : else {
#####:  691:	  temphand[z]=cardDrawn;
#####:  692:	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
#####:  693:	  z++;
#####:  694:         drawntreasure--;
			-:  695 :
		}
		-:  696 :
	}
	2:  697 : while (z - 1 >= 0) {
		branch  0 taken 0 %
			branch  1 taken 100 % (fallthrough)
#####:  698:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
#####:  699:	z=z-1;
			-:  700 :
	}
	-:  701 :
		1 : 702 : return 0;
	-:  703 : }
-:  704 :
	-: 705 :
	function smithy_function called 1 returned 100 % blocks executed 100 %
	1 : 706 : int smithy_function(struct gameState *state, int handPos)
	- : 707 : {
	1:  708 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		-:  709 : int i;
	-:  710 : //+3 Cards
		4 : 711 : for (i = 0; i < 3; i++)
		branch  0 taken 75 %
		branch  1 taken 25 % (fallthrough)
		-: 712 : {
		3:  713 : drawCard(currentPlayer, state);
		call    0 returned 100 %
			-:  714 : }
	-: 715 :      //discard card from hand
		1 : 716 : discardCard(handPos, currentPlayer + 1, state, 1);
	call    0 returned 100 %
		1:  717 : return 0;
	-:  718 : }
-:  719 :
	function sea_hag_function called 0 returned 0 % blocks executed 0 %
#####:  720:int sea_hag_function( struct gameState *state, int handPos )
	- : 721 : {
	-:  722 : int i;
#####:  723: int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  724:     for (i = 0; i < state->numPlayers; i++){
		branch  0 never executed
		branch  1 never executed
#####:  725:	if (i == currentPlayer){
		branch  0 never executed
		branch  1 never executed
#####:  726:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####:  727:	  state->discardCount[i]++;
#####:  728:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
		-:  729 : }
		-:  730 : }
#####:  731:      return 0;
		-:  732 : }
function salvager_function called 0 returned 0 % blocks executed 0 %
#####:  733:int salvager_function( struct gameState *state, int handPos, int choice1 )
- : 734 : {
#####:  735: int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  736 :     //+1 buy
#####:  737:      state->numBuys++;
		-:  738 :
#####:  739:      if (choice1)
		branch  0 never executed
		branch  1 never executed
		- : 740 : {
		-:  741 :	  //gain coins equal to trashed card
#####:  742:	  state->coins = state->coins + getCost( handCard(choice1, state) );
			call    0 never executed
			call    1 never executed
			- :  743 :	  //trash card
#####:  744:	  discardCard(choice1, currentPlayer, state, 0);	
			call    0 never executed
			- :  745 : }
	-:  746 :
		-: 747 :      //discard card
#####:  748:      discardCard(handPos, currentPlayer, state, 1);
		call    0 never executed
#####:  749:      return 0;
		-:  750 : }
-:  751 :
	function cardEffect called 4 returned 100 % blocks executed 6 %
	4 : 752 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	- : 753 : {
	-:  754 : int i;
	-:  755 : int j;
	-:  756 : int k;
	-:  757 : int x;
	-:  758 : int index;
	4:  759 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		4:  760 : int nextPlayer = currentPlayer + 1;
	-:  761 :
		4 : 762 : int tributeRevealedCards[2] = { -1, -1 };
	-:  763 : int temphand[MAX_HAND];// moved above the if statement
	4:  764 : int drawntreasure = 0;
	-:  765 : int cardDrawn;
	4:  766 : int z = 0;// this is the counter for the temp hand
	4:  767 : if (nextPlayer > (state->numPlayers - 1)) {
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
#####:  768:    nextPlayer = 0;
			-:  769 :
	}
	-:  770 :
		-: 771 :
		-: 772 :  //uses switch to select card and perform actions
		4 : 773 : switch (card)
		branch  0 taken 25 %
		branch  1 taken 0 %
		branch  2 taken 0 %
		branch  3 taken 25 %
		branch  4 taken 0 %
		branch  5 taken 0 %
		branch  6 taken 25 %
		branch  7 taken 25 %
		branch  8 taken 0 %
		branch  9 taken 0 %
		branch 10 taken 0 %
		branch 11 taken 0 %
		branch 12 taken 0 %
		branch 13 taken 0 %
		branch 14 taken 0 %
		branch 15 taken 0 %
		branch 16 taken 0 %
		branch 17 taken 0 %
		branch 18 taken 0 %
		branch 19 taken 0 %
		branch 20 taken 0 %
		-:  774 : {
		-:  775 : case adventurer:
			1 : 776 : adventurer_function(state, handPos);
			call    0 returned 100 %
				-:  777 ://      while(drawntreasure<2){
				-: 778 ://	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
				-: 779 ://	  shuffle(currentPlayer, state);
				-: 780 ://	}
				-: 781 ://	drawCard(currentPlayer, state);
				-: 782 ://	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
				-: 783 ://	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				-: 784 ://	  drawntreasure++;
				-: 785 ://	else{
				-: 786 ://	  temphand[z]=cardDrawn;
				-: 787 ://	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
				-: 788 ://	  z++;
				-: 789 ://	}
				-: 790 ://      }
				-: 791 ://      while(z-1>=0){
				-: 792 ://	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
				-: 793 ://	z=z-1;
				-: 794 ://      }
				1 : 795 : return 0;
			-:  796 :
				-: 797 : case council_room:
#####:  798:    council_room_function(state, handPos );
					call    0 never executed
						- :  799 :     //+4 Cards
						-: 800 :     // for (i = 0; i < 4; i++)
						-: 801 ://	{
						-: 802 ://	  drawCard(currentPlayer, state);
						-: 803 ://	}
						-: 804 :
						-: 805 :      //+1 Buy
						-: 806 :  //    state->numBuys++;
						-: 807 :
						-: 808 :      //Each other player draws a card
						-: 809 :    //  for (i = 0; i < state->numPlayers; i++)
						-: 810 ://	{
						-: 811 ://	  if ( i != currentPlayer )
						-: 812 ://	    {
						-: 813 ://	      drawCard(i, state);
						-: 814 ://	    }
						-: 815 ://	}
						-: 816 :
						-: 817 :      //put played card in played card pile
						-: 818 :  //    discardCard(handPos, currentPlayer, state, 0);
						-: 819 :
#####:  820:      return 0;
						-:  821 :
						-: 822 : case feast:
							-: 823 :      //gain card with cost up to 5
								-: 824 :      //Backup hand
#####:  825:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
								branch  0 never executed
								branch  1 never executed
#####:  826:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####:  827:	state->hand[currentPlayer][i] = -1;//Set to nothing
								-:  828 : }
							-:  829 :      //Backup hand
								-: 830 :
								-: 831 :      //Update Coins for Buy
#####:  832:      updateCoins(currentPlayer, state, 5);
								call    0 never executed
#####:  833:      x = 1;//Condition to loop on
#####:  834:      while( x == 1) {//Buy one card
								branch  0 never executed
								branch  1 never executed
#####:  835:	if (supplyCount(choice1, state) <= 0){
								call    0 never executed
								branch  1 never executed
								branch  2 never executed
								- :  836 : if (DEBUG)
								-: 837 : printf("None of that card left, sorry!\n");
							-:  838 :
								-: 839 : if (DEBUG) {
								-:  840 : printf("Cards Left: %d\n", supplyCount(choice1, state));
								-:  841 :
							}
							-: 842 : }
#####:  843:	else if (state->coins < getCost(choice1)){
								call    0 never executed
								branch  1 never executed
								branch  2 never executed
#####:  844:	  printf("That card is too expensive!\n");
								call    0 never executed
								- :  845 :
								-: 846 : if (DEBUG) {
								-:  847 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
								-:  848 :
							}
							-: 849 : }
							-:  850 : else {
								-:  851 :
									-: 852 : if (DEBUG) {
									-:  853 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
									-:  854 :
								}
								-: 855 :
#####:  856:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
									call    0 never executed
#####:  857:	  x = 0;//No more buying cards
									-:  858 :
									-: 859 : if (DEBUG) {
									-:  860 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
									-:  861 :
								}
								-: 862 :
									-: 863 :
							}
							-:  864 : }
								-:  865 :
								-: 866 :      //Reset Hand
#####:  867:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
								branch  0 never executed
								branch  1 never executed
#####:  868:	state->hand[currentPlayer][i] = temphand[i];
#####:  869:	temphand[i] = -1;
								-:  870 : }
							-:  871 :      //Reset Hand
								-: 872 :
#####:  873:      return 0;
								-:  874 :
								-: 875 : case gardens:
									1 : 876 : return -1;
									-:  877 :
										-: 878 : case mine:
#####:  879:      j = state->hand[currentPlayer][choice1];  //store card we will trash
											-:  880 :
#####:  881:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 882 : {
#####:  883:	  return -1;
												-:  884 : }
											-: 885 :
#####:  886:      if (choice2 > treasure_map || choice2 < curse)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 887 : {
#####:  888:	  return -1;
												-:  889 : }
											-: 890 :
#####:  891:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
												call    0 never executed
												call    1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 892 : {
#####:  893:	  return -1;
												-:  894 : }
											-: 895 :
#####:  896:      gainCard(choice2, state, 2, currentPlayer);
												call    0 never executed
												- :  897 :
												-: 898 :      //discard card from hand
#####:  899:      discardCard(handPos, currentPlayer, state, 0);
												call    0 never executed
												- :  900 :
												-: 901 :      //discard trashed card
#####:  902:      for (i = 0; i < state->handCount[currentPlayer]; i++)
												branch  0 never executed
												branch  1 never executed
												- : 903 : {
#####:  904:	  if (state->hand[currentPlayer][i] == j)
												branch  0 never executed
													branch  1 never executed
													- : 905 : {
#####:  906:	      discardCard(i, currentPlayer, state, 0);			
													call    0 never executed
#####:  907:	      break;
														-:  908 : }
												-: 909 : }
											-:  910 :
#####:  911:      return 0;
												-:  912 :
												-: 913 : case remodel:
#####:  914:      j = state->hand[currentPlayer][choice1];  //store card we will trash
													-:  915 :
#####:  916:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
														call    0 never executed
														call    1 never executed
														branch  2 never executed
														branch  3 never executed
														- : 917 : {
#####:  918:	  return -1;
														-:  919 : }
													-: 920 :
#####:  921:      gainCard(choice2, state, 0, currentPlayer);
														call    0 never executed
														- :  922 :
														-: 923 :      //discard card from hand
#####:  924:      discardCard(handPos, currentPlayer, state, 0);
														call    0 never executed
														- :  925 :
														-: 926 :      //discard trashed card
#####:  927:      for (i = 0; i < state->handCount[currentPlayer]; i++)
														branch  0 never executed
														branch  1 never executed
														- : 928 : {
#####:  929:	  if (state->hand[currentPlayer][i] == j)
														branch  0 never executed
															branch  1 never executed
															- : 930 : {
#####:  931:	      discardCard(i, currentPlayer, state, 0);			
															call    0 never executed
#####:  932:	      break;
																-:  933 : }
														-: 934 : }
													-:  935 :
														-: 936 :
#####:  937:      return 0;
														-:  938 :
														-: 939 : case smithy:
															1 : 940 : smithy_function(state, handPos);
															call    0 returned 100 %
																-:  941 :
																-: 942 :     //+3 Cards
																-: 943 ://      for (i = 0; i < 3; i++)
																-: 944 ://	{
																-: 945 ://	  drawCard(currentPlayer, state);
																-: 946 ://	}
																-: 947 ://			
																-: 948 :      //discard card from hand
																-: 949 ://      discardCard(handPos, currentPlayer, state, 0);
																1 : 950 : return 0;
															-:  951 :
																-: 952 : case village:
																	-: 953 :      //+1 Card
																		1 : 954 : drawCard(currentPlayer, state);
																	call    0 returned 100 %
																		-:  955 :
																		-: 956 :      //+2 Actions
																		1 : 957 : state->numActions = state->numActions + 2;
																	-:  958 :
																		-: 959 :      //discard played card from hand
																		1 : 960 : discardCard(handPos, currentPlayer, state, 0);
																	call    0 returned 100 %
																		1:  961 : return 0;
																	-:  962 :
																		-: 963 : case baron:
#####:  964:      state->numBuys++;//Increase buys by 1!
#####:  965:      if (choice1 > 0){//Boolean true or going to discard an estate
																			branch  0 never executed
																				branch  1 never executed
#####:  966:	int p = 0;//Iterator for hand!
#####:  967:	int card_not_discarded = 1;//Flag for discard set!
#####:  968:	while(card_not_discarded){
																				branch  0 never executed
																				branch  1 never executed
#####:  969:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																				branch  0 never executed
																				branch  1 never executed
#####:  970:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  971:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  972:	    state->discardCount[currentPlayer]++;
#####:  973:	    for (;p < state->handCount[currentPlayer]; p++){
																				branch  0 never executed
																				branch  1 never executed
#####:  974:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																				-:  975 : }
#####:  976:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  977:	    state->handCount[currentPlayer]--;
#####:  978:	    card_not_discarded = 0;//Exit the loop
																				-:  979 : }
#####:  980:	  else if (p > state->handCount[currentPlayer]){
																				branch  0 never executed
																				branch  1 never executed
																				- :  981 : if (DEBUG) {
																				-:  982 : printf("No estate cards in your hand, invalid choice\n");
																				-:  983 : printf("Must gain an estate if there are any\n");
																				-:  984 :
																			}
#####:  985:	    if (supplyCount(estate, state) > 0){
																			call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  986:	      gainCard(estate, state, 0, currentPlayer);
																				call    0 never executed
#####:  987:	      state->supplyCount[estate]--;//Decrement estates
#####:  988:	      if (supplyCount(estate, state) == 0){
																				call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  989:		isGameOver(state);
																				call    0 never executed
																				- :  990 : }
																				-:  991 : }
#####:  992:	    card_not_discarded = 0;//Exit the loop
																				-:  993 : }
																			-:  994 :
																				-: 995 : else {
#####:  996:	    p++;//Next card
																				-:  997 :
																			}
																			-:  998 : }
																				-:  999 : }
																	-: 1000 :
																		-: 1001 : else {
#####: 1002:	if (supplyCount(estate, state) > 0){
																		call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####: 1003:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																			call    0 never executed
#####: 1004:	  state->supplyCount[estate]--;//Decrement Estates
#####: 1005:	  if (supplyCount(estate, state) == 0){
																			call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####: 1006:	    isGameOver(state);
																			call    0 never executed
																			- : 1007 : }
																			-: 1008 : }
																	-: 1009 :
																	}
																	-: 1010 :
																		-: 1011 :
#####: 1012:      return 0;
																		-: 1013 :
																		-: 1014 : case great_hall:
																			-: 1015 :      //+1 Card
#####: 1016:      drawCard(currentPlayer, state);
																				call    0 never executed
																				- : 1017 :
																				-: 1018 :      //+1 Actions
#####: 1019:      state->numActions++;
																				-: 1020 :
																				-: 1021 :      //discard card from hand
#####: 1022:      discardCard(handPos, currentPlayer, state, 0);
																				call    0 never executed
#####: 1023:      return 0;
																				-: 1024 :
																				-: 1025 : case minion:
																					-: 1026 :      //+1 action
#####: 1027:      state->numActions++;
																						-: 1028 :
																						-: 1029 :      //discard card from hand
#####: 1030:      discardCard(handPos, currentPlayer, state, 0);
																						call    0 never executed
																						- : 1031 :
#####: 1032:      if (choice1)		//+2 coins
																						branch  0 never executed
																						branch  1 never executed
																						- : 1033 : {
#####: 1034:	  state->coins = state->coins + 2;
																						-: 1035 : }
																					-: 1036 :
#####: 1037:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																						branch  0 never executed
																						branch  1 never executed
																						- : 1038 : {
																						-: 1039 :	  //discard hand
#####: 1040:	  while(numHandCards(state) > 0)
																							call    0 never executed
																							branch  1 never executed
																							branch  2 never executed
																							- : 1041 : {
#####: 1042:	      discardCard(handPos, currentPlayer, state, 0);
																							call    0 never executed
																								- : 1043 : }
																						-: 1044 :
																							-: 1045 :	  //draw 4
#####: 1046:	  for (i = 0; i < 4; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 1047 : {
#####: 1048:	      drawCard(currentPlayer, state);
																							call    0 never executed
																								- : 1049 : }
																						-: 1050 :
																							-: 1051 :	  //other players discard hand and redraw if hand size > 4
#####: 1052:	  for (i = 0; i < state->numPlayers; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 1053 : {
#####: 1054:	      if (i != currentPlayer)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1055 : {
#####: 1056:		  if ( state->handCount[i] > 4 )
																								branch  0 never executed
																									branch  1 never executed
																									- : 1057 : {
																									-: 1058 :		      //discard hand
#####: 1059:		      while( state->handCount[i] > 0 )
																										branch  0 never executed
																										branch  1 never executed
																										- : 1060 : {
#####: 1061:			  discardCard(handPos, i, state, 0);
																										call    0 never executed
																											- : 1062 : }
																									-: 1063 :
																										-: 1064 :		      //draw 4
#####: 1065:		      for (j = 0; j < 4; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1066 : {
#####: 1067:			  drawCard(i, state);
																										call    0 never executed
																											- : 1068 : }
																									-: 1069 : }
																								-: 1070 : }
																							-: 1071 : }
																						-: 1072 :
																							-: 1073 : }
#####: 1074:      return 0;
																					-: 1075 :
																						-: 1076 : case steward:
#####: 1077:      if (choice1 == 1)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1078 : {
																								-: 1079 :	  //+2 cards
#####: 1080:	  drawCard(currentPlayer, state);
																									call    0 never executed
#####: 1081:	  drawCard(currentPlayer, state);
																									call    0 never executed
																									- : 1082 : }
#####: 1083:      else if (choice1 == 2)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1084 : {
																								-: 1085 :	  //+2 coins
#####: 1086:	  state->coins = state->coins + 2;
																									-: 1087 : }
																							-: 1088 : else
																								- : 1089 : {
																								-: 1090 :	  //trash 2 cards in hand
#####: 1091:	  discardCard(choice2, currentPlayer, state, 1);
																									call    0 never executed
#####: 1092:	  discardCard(choice3, currentPlayer, state, 1);
																									call    0 never executed
																									- : 1093 : }
																							-: 1094 :
																								-: 1095 :      //discard card from hand
#####: 1096:      discardCard(handPos, currentPlayer, state, 0);
																								call    0 never executed
#####: 1097:      return 0;
																								-: 1098 :
																								-: 1099 : case tribute:
#####: 1100:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																									branch  0 never executed
																										branch  1 never executed
#####: 1101:	if (state->deckCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####: 1102:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1103:	  state->deckCount[nextPlayer]--;
																										-: 1104 : }
#####: 1105:	else if (state->discardCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####: 1106:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####: 1107:	  state->discardCount[nextPlayer]--;
																										-: 1108 : }
																									-: 1109 : else {
																										-: 1110 :	  //No Card to Reveal
																											-: 1111 : if (DEBUG) {
																											-: 1112 : printf("No cards to reveal\n");
																											-: 1113 :
																										}
																										-: 1114 :
																									}
																									-: 1115 : }
																							-: 1116 :
																								-: 1117 : else {
#####: 1118:	if (state->deckCount[nextPlayer] == 0){
																								branch  0 never executed
																									branch  1 never executed
#####: 1119:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																									branch  0 never executed
																									branch  1 never executed
#####: 1120:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####: 1121:	    state->deckCount[nextPlayer]++;
#####: 1122:	    state->discard[nextPlayer][i] = -1;
#####: 1123:	    state->discardCount[nextPlayer]--;
																									-: 1124 : }
																									-: 1125 :
#####: 1126:	  shuffle(nextPlayer,state);//Shuffle the deck
																									call    0 never executed
																									- : 1127 : }
#####: 1128:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1129:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1130:	state->deckCount[nextPlayer]--;
#####: 1131:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1132:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1133:	state->deckCount[nextPlayer]--;
																							-: 1134 :
																							}
																							-: 1135 :
#####: 1136:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																								branch  0 never executed
																								branch  1 never executed
#####: 1137:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####: 1138:	state->playedCardCount++;
#####: 1139:	tributeRevealedCards[1] = -1;
																								-: 1140 : }
																							-: 1141 :
#####: 1142:      for (i = 0; i <= 2; i ++){
																								branch  0 never executed
																								branch  1 never executed
#####: 1143:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
#####: 1144:	  state->coins += 2;
																								-: 1145 : }
																								-: 1146 :
#####: 1147:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
																								branch  6 never executed
																								branch  7 never executed
																								branch  8 never executed
																								branch  9 never executed
#####: 1148:	  drawCard(currentPlayer, state);
																								call    0 never executed
#####: 1149:	  drawCard(currentPlayer, state);
																								call    0 never executed
																								- : 1150 : }
																							-: 1151 : else {//Action Card
#####: 1152:	  state->numActions = state->numActions + 2;
																								-: 1153 :
																							}
																							-: 1154 : }
																							-: 1155 :
#####: 1156:      return 0;
																								-: 1157 :
																								-: 1158 : case ambassador:
#####: 1159:      j = 0;		//used to check if player has enough cards to discard
																									-: 1160 :
#####: 1161:      if (choice2 > 2 || choice2 < 0)
																										branch  0 never executed
																										branch  1 never executed
																										branch  2 never executed
																										branch  3 never executed
																										- : 1162 : {
#####: 1163:	  return -1;				
																										-: 1164 : }
																									-: 1165 :
#####: 1166:      if (choice1 == handPos)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1167 : {
#####: 1168:	  return -1;
																										-: 1169 : }
																									-: 1170 :
#####: 1171:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1172 : {
#####: 1173:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																										branch  0 never executed
																											branch  1 never executed
																											branch  2 never executed
																											branch  3 never executed
																											branch  4 never executed
																											branch  5 never executed
																											- : 1174 : {
#####: 1175:	      j++;
																											-: 1176 : }
																										-: 1177 : }
#####: 1178:      if (j < choice2)
																									branch  0 never executed
																										branch  1 never executed
																										- : 1179 : {
#####: 1180:	  return -1;				
																										-: 1181 : }
																									-: 1182 :
																										-: 1183 : if (DEBUG)
																										-: 1184 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																									-: 1185 :
																										-: 1186 :      //increase supply count for choosen card by amount being discarded
#####: 1187:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																										-: 1188 :
																										-: 1189 :      //each other player gains a copy of revealed card
#####: 1190:      for (i = 0; i < state->numPlayers; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1191 : {
#####: 1192:	  if (i != currentPlayer)
																										branch  0 never executed
																											branch  1 never executed
																											- : 1193 : {
#####: 1194:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																											call    0 never executed
																												- : 1195 : }
																										-: 1196 : }
																									-: 1197 :
																										-: 1198 :      //discard played card from hand
#####: 1199:      discardCard(handPos, currentPlayer, state, 0);			
																										call    0 never executed
																										- : 1200 :
																										-: 1201 :      //trash copies of cards returned to supply
#####: 1202:      for (j = 0; j < choice2; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1203 : {
#####: 1204:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																											branch  1 never executed
																											- : 1205 : {
#####: 1206:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																											branch  0 never executed
																												branch  1 never executed
																												- : 1207 : {
#####: 1208:		  discardCard(i, currentPlayer, state, 1);
																												call    0 never executed
#####: 1209:		  break;
																													-: 1210 : }
																											-: 1211 : }
																										-: 1212 : }
																									-: 1213 :
#####: 1214:      return 0;
																										-: 1215 :
																										-: 1216 : case cutpurse:
																											-: 1217 :
#####: 1218:      updateCoins(currentPlayer, state, 2);
																												call    0 never executed
#####: 1219:      for (i = 0; i < state->numPlayers; i++)
																												branch  0 never executed
																												branch  1 never executed
																												- : 1220 : {
#####: 1221:	  if (i != currentPlayer)
																												branch  0 never executed
																													branch  1 never executed
																													- : 1222 : {
#####: 1223:	      for (j = 0; j < state->handCount[i]; j++)
																													branch  0 never executed
																														branch  1 never executed
																														- : 1224 : {
#####: 1225:		  if (state->hand[i][j] == copper)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1226 : {
#####: 1227:		      discardCard(j, i, state, 0);
																															call    0 never executed
#####: 1228:		      break;
																																-: 1229 : }
#####: 1230:		  if (j == state->handCount[i])
																														branch  0 never executed
																															branch  1 never executed
																															- : 1231 : {
#####: 1232:		      for (k = 0; k < state->handCount[i]; k++)
																															branch  0 never executed
																																branch  1 never executed
																																- : 1233 : {
																																-: 1234 : if (DEBUG)
																																	-: 1235 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																-: 1236 : }
#####: 1237:		      break;
																															-: 1238 : }
																														-: 1239 : }
																													-: 1240 :
																														-: 1241 : }
																												-: 1242 :
																													-: 1243 : }
																											-: 1244 :
																												-: 1245 :      //discard played card from hand
#####: 1246:      discardCard(handPos, currentPlayer, state, 0);			
																												call    0 never executed
																												- : 1247 :
#####: 1248:      return 0;
																												-: 1249 :
																												-: 1250 :
																												-: 1251 : case embargo:
																													-: 1252 :      //+2 Coins
#####: 1253:      state->coins = state->coins + 2;
																														-: 1254 :
																														-: 1255 :      //see if selected pile is in play
#####: 1256:      if ( state->supplyCount[choice1] == -1 )
																														branch  0 never executed
																														branch  1 never executed
																														- : 1257 : {
#####: 1258:	  return -1;
																														-: 1259 : }
																													-: 1260 :
																														-: 1261 :      //add embargo token to selected supply pile
#####: 1262:      state->embargoTokens[choice1]++;
																														-: 1263 :
																														-: 1264 :      //trash card
#####: 1265:      discardCard(handPos, currentPlayer, state, 1);		
																														call    0 never executed
#####: 1266:      return 0;
																														-: 1267 :
																														-: 1268 : case outpost:
																															-: 1269 :      //set outpost flag
#####: 1270:      state->outpostPlayed++;
																																-: 1271 :
																																-: 1272 :      //discard card
#####: 1273:      discardCard(handPos, currentPlayer, state, 0);
																																call    0 never executed
#####: 1274:      return 0;
																																-: 1275 :
																																-: 1276 : case salvager:
#####: 1277:       salvager_function( state, handPos, choice1 ) ;
																																	call    0 never executed
																																		- : 1278 :      //+1 buy
																																		-: 1279 ://      state->numBuys++;
																																		-: 1280 :
																																		-: 1281 :  //    if (choice1)
																																		-: 1282 ://	{
																																		-: 1283 :	  //gain coins equal to trashed card
																																		-: 1284 ://	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																		-: 1285 :	  //trash card
																																		-: 1286 ://	  discardCard(choice1, currentPlayer, state, 1);	
																																		-: 1287 ://	}
																																		-: 1288 :
																																		-: 1289 :      //discard card
																																		-: 1290 ://      discardCard(handPos, currentPlayer, state, 0);
#####: 1291:      return 0;
																																		-: 1292 :
																																		-: 1293 : case sea_hag:
#####: 1294:      sea_hag_function(state, handPos);
																																			call    0 never executed
																																				- : 1295 ://      for (i = 0; i < state->numPlayers; i++){
																																				-: 1296 ://	if (i != currentPlayer){
																																				-: 1297 ://	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
																																				-: 1298 ://	  state->discardCount[i]++;
																																				-: 1299 ://	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																				-: 1300 ://	}
																																				-: 1301 ://      }
#####: 1302:      return 0;
																																				-: 1303 :
																																				-: 1304 : case treasure_map:
																																					-: 1305 :      //search hand for another treasure_map
#####: 1306:      index = -1;
#####: 1307:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																						branch  0 never executed
																																						branch  1 never executed
																																						- : 1308 : {
#####: 1309:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																						branch  0 never executed
																																							branch  1 never executed
																																							branch  2 never executed
																																							branch  3 never executed
																																							- : 1310 : {
#####: 1311:	      index = i;
#####: 1312:	      break;
																																							-: 1313 : }
																																						-: 1314 : }
#####: 1315:      if (index > -1)
																																					branch  0 never executed
																																						branch  1 never executed
																																						- : 1316 : {
																																						-: 1317 :	  //trash both treasure cards
#####: 1318:	  discardCard(handPos, currentPlayer, state, 1);
																																							call    0 never executed
#####: 1319:	  discardCard(index, currentPlayer, state, 1);
																																							call    0 never executed
																																							- : 1320 :
																																							-: 1321 :	  //gain 4 Gold cards
#####: 1322:	  for (i = 0; i < 4; i++)
																																							branch  0 never executed
																																							branch  1 never executed
																																							- : 1323 : {
#####: 1324:	      gainCard(gold, state, 1, currentPlayer);
																																							call    0 never executed
																																								- : 1325 : }
																																						-: 1326 :
																																							-: 1327 :	  //return success
#####: 1328:	  return 1;
																																							-: 1329 : }
																																					-: 1330 :
																																						-: 1331 :      //no second treasure_map found in hand
#####: 1332:      return -1;
																																						-: 1333 : }
	-: 1334 :
#####: 1335:  return -1;
		-: 1336 : }
-: 1337 :
	function discardCard called 2 returned 100 % blocks executed 78 %
	2 : 1338 : int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	- : 1339 : {
	-: 1340 :
		-: 1341 :  //if card is not trashed, added to Played pile 
		2 : 1342 : if (trashFlag < 1)
		branch  0 taken 50 % (fallthrough)
		branch  1 taken 50 %
		-: 1343 : {
		-: 1344 :      //add card to played pile
			1 : 1345 : state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
		1: 1346 : state->playedCardCount++;
		-: 1347 : }
	-: 1348 :
		-: 1349 :  //set played card to -1
		2 : 1350 : state->hand[currentPlayer][handPos] = -1;
	-: 1351 :
		-: 1352 :  //remove card from player's hand
		2 : 1353 : if (handPos == (state->handCount[currentPlayer] - 1)) 	//last card in hand array is played
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-: 1354 : {
		-: 1355 :      //reduce number of cards in hand
#####: 1356:      state->handCount[currentPlayer]--;
			-: 1357 : }
	2 : 1358 : else if (state->handCount[currentPlayer] == 1) //only one card in hand
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-: 1359 : {
		-: 1360 :      //reduce number of cards in hand
#####: 1361:      state->handCount[currentPlayer]--;
			-: 1362 : }
	-: 1363 : else
		- : 1364 : {
		-: 1365 :      //replace discarded card with last card in hand
			2 : 1366 : state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
		-: 1367 :      //set last card to -1
			2 : 1368 : state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
		-: 1369 :      //reduce number of cards in hand
			2 : 1370 : state->handCount[currentPlayer]--;
		-: 1371 : }
	-: 1372 :
		2 : 1373 : return 0;
	-: 1374 : }
-: 1375 :
	function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1376:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	- : 1377 : {
	-: 1378 :  //Note: supplyPos is enum of choosen card
		-: 1379 :
		-: 1380 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1381:  if ( supplyCount(supplyPos, state) < 1 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 1382 : {
#####: 1383:      return -1;
		-: 1384 : }
	-: 1385 :
		-: 1386 :  //added card for [whoseTurn] current player:
		-: 1387 :  // toFlag = 0 : add to discard
		-: 1388 :  // toFlag = 1 : add to deck
		-: 1389 :  // toFlag = 2 : add to hand
		-: 1390 :
#####: 1391:  if (toFlag == 1)
		branch  0 never executed
		branch  1 never executed
		- : 1392 : {
#####: 1393:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1394:      state->deckCount[player]++;
		-: 1395 : }
#####: 1396:  else if (toFlag == 2)
	branch  0 never executed
		branch  1 never executed
		- : 1397 : {
#####: 1398:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1399:      state->handCount[player]++;
		-: 1400 : }
	-: 1401 : else
		- : 1402 : {
#####: 1403:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1404:      state->discardCount[player]++;
		-: 1405 : }
	-: 1406 :
		-: 1407 :  //decrease number in supply pile
#####: 1408:  state->supplyCount[supplyPos]--;
		-: 1409 :
#####: 1410:  return 0;
		-: 1411 : }
-: 1412 :
	function updateCoins called 565 returned 100 % blocks executed 100 %
	565 : 1413 : int updateCoins(int player, struct gameState *state, int bonus)
	- : 1414 : {
	-: 1415 : int i;
	-: 1416 :
		-: 1417 :  //reset coin count
		565 : 1418 : state->coins = 0;
	-: 1419 :
		-: 1420 :  //add coins for each Treasure card in player's hand
		2510 : 1421 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 77 %
		branch  1 taken 23 % (fallthrough)
		-: 1422 : {
		1945: 1423 : if (state->hand[player][i] == copper)
			branch  0 taken 43 % (fallthrough)
			branch  1 taken 57 %
			-: 1424 : {
			830: 1425 : state->coins += 1;
			-: 1426 : }
		1115 : 1427 : else if (state->hand[player][i] == silver)
			branch  0 taken 30 % (fallthrough)
			branch  1 taken 70 %
			-: 1428 : {
			330: 1429 : state->coins += 2;
			-: 1430 : }
		785 : 1431 : else if (state->hand[player][i] == gold)
			branch  0 taken 42 % (fallthrough)
			branch  1 taken 58 %
			-: 1432 : {
			330: 1433 : state->coins += 3;
			-: 1434 : }
		-: 1435 : }
	-: 1436 :
		-: 1437 :  //add bonus
		565 : 1438 : state->coins += bonus;
	-: 1439 :
		565 : 1440 : return 0;
	-: 1441 : }
-: 1442 :
	-: 1443 :
	-: 1444 ://end of dominion.c
	-: 1445 :

	---- - VILLAGE RESULTS : ---- -
	In 1000 tests...
	Success : 1000
	Error in Actions : 0
	Error in Buys : 0
	Error in Coins : 0
	Error in Hand Count : 0
	Error in Discard + Deck + Played Count : 0
	Error in Supplies : 0
	Error in Opponents Deck : 0
	Error in Opponents Discard : 0
	File 'dominion.c'
	Lines executed : 19.96% of 571
	Branches executed : 22.78% of 417
	Taken at least once : 14.15% of 417
	Calls executed : 10.00% of 100
	Creating 'dominion.c.gcov'

	- : 0 : Source : dominion.c
	- : 0 : Graph : dominion.gcno
	- : 0 : Data : dominion.gcda
	- : 0 : Runs : 1
	- : 0 : Programs : 1
	- : 1 : #include "dominion.h"
	- : 2 : #include "dominion_helpers.h"
	- : 3 : #include "rngs.h"
	- : 4 : #include <stdio.h>
	- : 5 : #include <math.h>
	- : 6 : #include <stdlib.h>
	- : 7 :
	function compare called 30000 returned 100 % blocks executed 83 %
	30000 : 8 : int compare(const void* a, const void* b) {
	30000:    9 : if (*(int*)a > *(int*)b)
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
#####:   10:    return 1;
		30000:   11 : if (*(int*)a < *(int*)b)
		branch  0 taken 27 % (fallthrough)
		branch  1 taken 73 %
		8000 : 12 : return -1;
	22000:   13 : return 0;
	-:   14 :
}
-:   15 :
	function newGame called 0 returned 0 % blocks executed 0 %
#####:   16:struct gameState* newGame() {
#####:   17:  struct gameState* g = malloc(sizeof(struct gameState));
#####:   18:  return g;
	-:   19 : }
-: 20 :
	function kingdomCards called 0 returned 0 % blocks executed 0 %
#####:   21:int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
	-:   22 : int k8, int k9, int k10) {
#####:   23:  int* k = malloc(10 * sizeof(int));
#####:   24:  k[0] = k1;
#####:   25:  k[1] = k2;
#####:   26:  k[2] = k3;
#####:   27:  k[3] = k4;
#####:   28:  k[4] = k5;
#####:   29:  k[5] = k6;
#####:   30:  k[6] = k7;
#####:   31:  k[7] = k8;
#####:   32:  k[8] = k9;
#####:   33:  k[9] = k10;
#####:   34:  return k;
	-:   35 :
}
-:   36 :
	function initializeGame called 1000 returned 100 % blocks executed 88 %
	1000 : 37 : int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
		-:   38 : struct gameState *state) {
	-:   39 :
		-: 40 : int i;
	-:   41 : int j;
	-:   42 : int it;
	-:   43 :  //set up random number generator
		1000 : 44 : SelectStream(1);
	call    0 returned 100 %
		1000:   45 : PutSeed((long)randomSeed);
	call    0 returned 100 %
		-:   46 :
		-: 47 :  //check number of players
		1000 : 48 : if (numPlayers > MAX_PLAYERS || numPlayers < 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		branch  2 taken 0 % (fallthrough)
		branch  3 taken 100 %
		-: 49 : {
#####:   50:      return -1;
		-:   51 : }
	-: 52 :
		-: 53 :  //set number of players
		1000 : 54 : state->numPlayers = numPlayers;
	-:   55 :
		-: 56 :  //check selected kingdom cards are different
		11000 : 57 : for (i = 0; i < 10; i++)
		branch  0 taken 91 %
		branch  1 taken 9 % (fallthrough)
		-: 58 : {
		110000:   59 : for (j = 0; j < 10; j++)
			branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			-: 60 : {
			100000:   61 : if (j != i && kingdomCards[j] == kingdomCards[i])
				branch  0 taken 90 % (fallthrough)
				branch  1 taken 10 %
				branch  2 taken 0 % (fallthrough)
				branch  3 taken 100 %
				-: 62 : {
#####:   63:	      return -1;
				-:   64 : }
			-: 65 : }
		-:   66 : }
	-:   67 :
		-: 68 :
		-: 69 :  //initialize supply
		-: 70 :  ///////////////////////////////
		-: 71 :
		-: 72 :  //set number of Curse cards
		1000 : 73 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 74 : {
		1000:   75 : state->supplyCount[curse] = 10;
		-:   76 : }
#####:   77:  else if (numPlayers == 3)
	branch  0 never executed
		branch  1 never executed
		- :   78 : {
#####:   79:      state->supplyCount[curse] = 20;
		-:   80 : }
	-: 81 : else
		- :   82 : {
#####:   83:      state->supplyCount[curse] = 30;
		-:   84 : }
	-: 85 :
		-: 86 :  //set number of Victory cards
		1000 : 87 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 88 : {
		1000:   89 : state->supplyCount[estate] = 8;
		1000:   90 : state->supplyCount[duchy] = 8;
		1000:   91 : state->supplyCount[province] = 8;
		-:   92 : }
	-: 93 : else
		- :   94 : {
#####:   95:      state->supplyCount[estate] = 12;
#####:   96:      state->supplyCount[duchy] = 12;
#####:   97:      state->supplyCount[province] = 12;
		-:   98 : }
	-: 99 :
		-: 100 :  //set number of Treasure cards
		1000 : 101 : state->supplyCount[copper] = 60 - (7 * numPlayers);
	1000:  102 : state->supplyCount[silver] = 40;
	1000:  103 : state->supplyCount[gold] = 30;
	-:  104 :
		-: 105 :  //set number of Kingdom cards
		21000 : 106 : for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
		branch  0 taken 95 %
		branch  1 taken 5 % (fallthrough)
		-: 107 : {
		165000:  108 : for (j = 0; j < 10; j++)           		//loop chosen cards
			branch  0 taken 94 %
			branch  1 taken 6 % (fallthrough)
			-: 109 : {
			155000:  110 : if (kingdomCards[j] == i)
				branch  0 taken 6 % (fallthrough)
				branch  1 taken 94 %
				-: 111 : {
				-:  112 :	      //check if card is a 'Victory' Kingdom card
					10000 : 113 : if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
					branch  0 taken 90 % (fallthrough)
					branch  1 taken 10 %
					branch  2 taken 11 % (fallthrough)
					branch  3 taken 89 %
					-: 114 : {
					4000:  115 : if (numPlayers == 2) {
						branch  0 taken 100 % (fallthrough)
							branch  1 taken 0 %
							2000:  116 : state->supplyCount[i] = 8;
						-:  117 :
					}
#####:  118:		  else{ state->supplyCount[i] = 12; }
					-:  119 : }
				-:  120 : else
					- :  121 : {
					8000:  122 : state->supplyCount[i] = 10;
					-:  123 : }
				10000 : 124 : break;
				-:  125 : }
			-:  126 : else    //card is not in the set choosen for the game
				- :  127 : {
				145000:  128 : state->supplyCount[i] = -1;
				-:  129 : }
			-: 130 : }
		-:  131 :
			-: 132 : }
	-:  133 :
		-: 134 :  ////////////////////////
		-: 135 :  //supply intilization complete
		-: 136 :
		-: 137 :  //set player decks
		3000 : 138 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 139 : {
		2000:  140 : state->deckCount[i] = 0;
		8000:  141 : for (j = 0; j < 3; j++)
			branch  0 taken 75 %
			branch  1 taken 25 % (fallthrough)
			-: 142 : {
			6000:  143 : state->deck[i][j] = estate;
			6000:  144 : state->deckCount[i]++;
			-:  145 : }
		16000 : 146 : for (j = 3; j < 10; j++)
			branch  0 taken 88 %
			branch  1 taken 13 % (fallthrough)
			-: 147 : {
			14000:  148 : state->deck[i][j] = copper;
			14000:  149 : state->deckCount[i]++;
			-:  150 : }
		-: 151 : }
	-:  152 :
		-: 153 :  //shuffle player decks
		3000 : 154 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 155 : {
		2000:  156 : if (shuffle(i, state) < 0)
			call    0 returned 100 %
			branch  1 taken 0 % (fallthrough)
			branch  2 taken 100 %
			-: 157 : {
#####:  158:	  return -1;
			-:  159 : }
		-: 160 : }
	-:  161 :
		-: 162 :  //draw player hands
		3000 : 163 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 164 : {
		-:  165 :      //initialize hand size to zero
			2000 : 166 : state->handCount[i] = 0;
		2000:  167 : state->discardCount[i] = 0;
		-:  168 :      //draw 5 cards
			-: 169 :      // for (j = 0; j < 5; j++)
			-: 170 :      //	{
			-: 171 :      //	  drawCard(i, state);
			-: 172 :      //	}
			-: 173 : }
	-:  174 :
		-: 175 :  //set embargo tokens to 0 for all supply piles
		28000 : 176 : for (i = 0; i <= treasure_map; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 177 : {
		27000:  178 : state->embargoTokens[i] = 0;
		-:  179 : }
	-: 180 :
		-: 181 :  //initialize first player's turn
		1000 : 182 : state->outpostPlayed = 0;
	1000:  183 : state->phase = 0;
	1000:  184 : state->numActions = 1;
	1000:  185 : state->numBuys = 1;
	1000:  186 : state->playedCardCount = 0;
	1000:  187 : state->whoseTurn = 0;
	1000:  188 : state->handCount[state->whoseTurn] = 0;
	-:  189 :  //int it; move to top
		-: 190 :
		-: 191 :  //Moved draw cards to here, only drawing at the start of a turn
		6000 : 192 : for (it = 0; it < 5; it++) {
		branch  0 taken 83 %
			branch  1 taken 17 % (fallthrough)
			5000:  193 : drawCard(state->whoseTurn, state);
		call    0 returned 100 %
			-:  194 :
	}
	-:  195 :
		1000 : 196 : updateCoins(state->whoseTurn, state, 0);
	call    0 returned 100 %
		-:  197 :
		1000 : 198 : return 0;
	-:  199 :
}
-:  200 :
	function shuffle called 2000 returned 100 % blocks executed 94 %
	2000 : 201 : int shuffle(int player, struct gameState *state) {
	-:  202 :
		-: 203 :
		-: 204 : int newDeck[MAX_DECK];
	2000:  205 : int newDeckPos = 0;
	-:  206 : int card;
	-:  207 : int i;
	-:  208 :
		2000 : 209 : if (state->deckCount[player] < 1)
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
#####:  210:    return -1;
		2000:  211 : qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
	call    0 returned 100 %
		-:  212 :  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
		-: 213 :
		24000 : 214 : while (state->deckCount[player] > 0) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			20000:  215 : card = floor(Random() * state->deckCount[player]);
		call    0 returned 100 %
			20000:  216 : newDeck[newDeckPos] = state->deck[player][card];
		20000:  217 : newDeckPos++;
		70000:  218 : for (i = card; i < state->deckCount[player] - 1; i++) {
			branch  0 taken 71 %
				branch  1 taken 29 % (fallthrough)
				50000:  219 : state->deck[player][i] = state->deck[player][i + 1];
			-:  220 :
		}
		20000:  221 : state->deckCount[player]--;
		-:  222 :
	}
	22000:  223 : for (i = 0; i < newDeckPos; i++) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			20000:  224 : state->deck[player][i] = newDeck[i];
		20000:  225 : state->deckCount[player]++;
		-:  226 :
	}
	-:  227 :
		2000 : 228 : return 0;
	-:  229 :
}
-:  230 :
	function playCard called 0 returned 0 % blocks executed 0 %
#####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
	- : 232 : {
	-:  233 : int card;
#####:  234:  int coin_bonus = 0; 		//tracks coins gain from actions
	-:  235 :
		-: 236 :  //check if it is the right phase
#####:  237:  if (state->phase != 0)
		branch  0 never executed
		branch  1 never executed
		- : 238 : {
#####:  239:      return -1;
		-:  240 : }
	-: 241 :
		-: 242 :  //check if player has enough actions
#####:  243:  if ( state->numActions < 1 )
		branch  0 never executed
		branch  1 never executed
		- : 244 : {
#####:  245:      return -1;
		-:  246 : }
	-: 247 :
		-: 248 :  //get card played
#####:  249:  card = handCard(handPos, state);
		call    0 never executed
		- :  250 :
		-: 251 :  //check if selected card is an action
#####:  252:  if ( card < adventurer || card > treasure_map )
		branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 253 : {
#####:  254:      return -1;
		-:  255 : }
	-: 256 :
		-: 257 :  //play card
#####:  258:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 259 : {
#####:  260:      return -1;
		-:  261 : }
	-: 262 :
		-: 263 :  //reduce number of actions
#####:  264:  state->numActions--;
		-:  265 :
		-: 266 :  //update coins (Treasure cards may be added with card draws)
#####:  267:  updateCoins(state->whoseTurn, state, coin_bonus);
		call    0 never executed
		- :  268 :
#####:  269:  return 0;
		-:  270 : }
-:  271 :
	function buyCard called 0 returned 0 % blocks executed 0 %
#####:  272:int buyCard(int supplyPos, struct gameState *state) {
	-:  273 : int who;
-:  274 : if (DEBUG) {
	-:  275 : printf("Entering buyCard...\n");
	-:  276 :
}
-: 277 :
	-: 278 :  // I don't know what to do about the phase thing.
	-: 279 :
#####:  280:  who = state->whoseTurn;
	-:  281 :
#####:  282:  if (state->numBuys < 1){
	branch  0 never executed
	branch  1 never executed
	- :  283 : if (DEBUG)
	-: 284 : printf("You do not have any buys left\n");
#####:  285:    return -1;
#####:  286:  } else if (supplyCount(supplyPos, state) <1){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  287 : if (DEBUG)
-: 288 : printf("There are not any of that type of card left\n");
#####:  289:    return -1;
#####:  290:  } else if (state->coins < getCost(supplyPos)){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  291 : if (DEBUG)
-: 292 : printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
#####:  293:    return -1;
-:  294 : }
else {
#####:  295:    state->phase=1;
	-:  296 :    //state->supplyCount[supplyPos]--;
#####:  297:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
		call    0 never executed
		- :  298 :
#####:  299:    state->coins = (state->coins) - (getCost(supplyPos));
		call    0 never executed
#####:  300:    state->numBuys--;
		-:  301 : if (DEBUG)
		-: 302 : printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
	-:  303 :
}
-:  304 :
	-: 305 :  //state->discard[who][state->discardCount[who]] = supplyPos;
	-: 306 :  //state->discardCount[who]++;
	-: 307 :
#####:  308:  return 0;
	-:  309 : }
-:  310 :
	function numHandCards called 0 returned 0 % blocks executed 0 %
#####:  311:int numHandCards(struct gameState *state) {
#####:  312:  return state->handCount[ whoseTurn(state) ];
	call    0 never executed
	- :  313 : }
-: 314 :
	function handCard called 0 returned 0 % blocks executed 0 %
#####:  315:int handCard(int handPos, struct gameState *state) {
#####:  316:  int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  317:  return state->hand[currentPlayer][handPos];
	-:  318 : }
-: 319 :
	function supplyCount called 0 returned 0 % blocks executed 0 %
#####:  320:int supplyCount(int card, struct gameState *state) {
#####:  321:  return state->supplyCount[card];
	-:  322 : }
-: 323 :
	function fullDeckCount called 0 returned 0 % blocks executed 0 %
#####:  324:int fullDeckCount(int player, int card, struct gameState *state) {
	-:  325 : int i;
#####:  326:  int count = 0;
-:  327 :
#####:  328:  for (i = 0; i < state->deckCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 329 : {
#####:  330:      if (state->deck[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  331 : }
-: 332 :
#####:  333:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 334 : {
#####:  335:      if (state->hand[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  336 : }
-: 337 :
#####:  338:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 339 : {
#####:  340:      if (state->discard[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  341 : }
-: 342 :
#####:  343:  return count;
	-:  344 : }
-:  345 :
	function whoseTurn called 1000 returned 100 % blocks executed 100 %
	1000 : 346 : int whoseTurn(struct gameState *state) {
	1000:  347 : return state->whoseTurn;
	-:  348 :
}
-: 349 :
	function endTurn called 0 returned 0 % blocks executed 0 %
#####:  350:int endTurn(struct gameState *state) {
	-:  351 : int k;
-:  352 : int i;
#####:  353:  int currentPlayer = whoseTurn(state);
call    0 never executed
- :  354 :
	-: 355 :  //Discard hand
#####:  356:  for (i = 0; i < state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####:  357:    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
#####:  358:    state->hand[currentPlayer][i] = -1;//Set card to -1
	-:  359 : }
#####:  360:  state->handCount[currentPlayer] = 0;//Reset hand count
-:  361 :
	-: 362 :  //Code for determining the player
#####:  363:  if (currentPlayer < (state->numPlayers - 1)){ 
	branch  0 never executed
	branch  1 never executed
#####:  364:    state->whoseTurn = currentPlayer + 1;//Still safe to increment
	-:  365 : }
-: 366 : else {
#####:  367:    state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
	-:  368 :
}
-:  369 :
#####:  370:  state->outpostPlayed = 0;
#####:  371:  state->phase = 0;
#####:  372:  state->numActions = 1;
#####:  373:  state->coins = 0;
#####:  374:  state->numBuys = 1;
#####:  375:  state->playedCardCount = 0;
#####:  376:  state->handCount[state->whoseTurn] = 0;
	-:  377 :
	-: 378 :  //int k; move to top
	-: 379 :  //Next player draws hand
#####:  380:  for (k = 0; k < 5; k++){
	branch  0 never executed
	branch  1 never executed
#####:  381:    drawCard(state->whoseTurn, state);//Draw a card
	call    0 never executed
	- :  382 : }
-:  383 :
	-: 384 :  //Update money
#####:  385:  updateCoins(state->whoseTurn, state , 0);
	call    0 never executed
	- :  386 :
#####:  387:  return 0;
	-:  388 : }
-:  389 :
	function isGameOver called 0 returned 0 % blocks executed 0 %
#####:  390:int isGameOver(struct gameState *state) {
	-:  391 : int i;
-:  392 : int j;
-:  393 :
	-: 394 :  //if stack of Province cards is empty, the game ends
#####:  395:  if (state->supplyCount[province] == 0)
	branch  0 never executed
	branch  1 never executed
	- : 396 : {
#####:  397:      return 1;
	-:  398 : }
-: 399 :
	-: 400 :  //if three supply pile are at 0, the game ends
#####:  401:  j = 0;
#####:  402:  for (i = 0; i < 25; i++)
	branch  0 never executed
	branch  1 never executed
	- : 403 : {
#####:  404:      if (state->supplyCount[i] == 0)
	branch  0 never executed
		branch  1 never executed
		- : 405 : {
#####:  406:	  j++;
		-:  407 : }
	-: 408 : }
#####:  409:  if ( j >= 3)
branch  0 never executed
branch  1 never executed
- : 410 : {
#####:  411:      return 1;
	-:  412 : }
-: 413 :
#####:  414:  return 0;
	-:  415 : }
-:  416 :
	function scoreFor called 0 returned 0 % blocks executed 0 %
#####:  417:int scoreFor (int player, struct gameState *state) {
	-:  418 :
	-: 419 : int i;
#####:  420:  int score = 0;
-:  421 :  //score from hand
#####:  422:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 423 : {
#####:  424:      if (state->hand[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  425:      if (state->hand[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  426:      if (state->hand[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  427:      if (state->hand[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  428:      if (state->hand[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  429:      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  430 : }
-:  431 :
	-: 432 :  //score from discard
#####:  433:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 434 : {
#####:  435:      if (state->discard[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  436:      if (state->discard[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  437:      if (state->discard[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  438:      if (state->discard[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  439:      if (state->discard[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  440:      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  441 : }
-:  442 :
	-: 443 :  //score from deck
#####:  444:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 445 : {
#####:  446:      if (state->deck[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  447:      if (state->deck[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  448:      if (state->deck[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  449:      if (state->deck[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  450:      if (state->deck[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  451:      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  452 : }
-:  453 :
#####:  454:  return score;
	-:  455 : }
-:  456 :
	function getWinners called 0 returned 0 % blocks executed 0 %
#####:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
	-:  458 : int i;
-:  459 : int j;
-:  460 : int highScore;
-:  461 : int currentPlayer;
-:  462 :
	-: 463 :  //get score for each player
#####:  464:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 465 : {
	-:  466 :      //set unused player scores to -9999
#####:  467:      if (i >= state->numPlayers)
		branch  0 never executed
		branch  1 never executed
		- : 468 : {
#####:  469:	  players[i] = -9999;
		-:  470 : }
	-: 471 : else
		- :  472 : {
#####:  473:	  players[i] = scoreFor (i, state);
		call    0 never executed
			- :  474 : }
	-: 475 : }
-:  476 :
	-: 477 :  //find highest score
#####:  478:  j = 0;
#####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 480 : {
#####:  481:      if (players[i] > players[j])
	branch  0 never executed
		branch  1 never executed
		- : 482 : {
#####:  483:	  j = i;
		-:  484 : }
	-: 485 : }
#####:  486:  highScore = players[j];
-:  487 :
	-: 488 :  //add 1 to players who had less turns
#####:  489:  currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 491 : {
#####:  492:      if ( players[i] == highScore && i > currentPlayer )
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 493 : {
#####:  494:	  players[i]++;
		-:  495 : }
	-: 496 : }
-:  497 :
	-: 498 :  //find new highest score
#####:  499:  j = 0;
#####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 501 : {
#####:  502:      if ( players[i] > players[j] )
	branch  0 never executed
		branch  1 never executed
		- : 503 : {
#####:  504:	  j = i;
		-:  505 : }
	-: 506 : }
#####:  507:  highScore = players[j];
-:  508 :
	-: 509 :  //set winners in array to 1 and rest to 0
#####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 511 : {
#####:  512:      if ( players[i] == highScore )
	branch  0 never executed
		branch  1 never executed
		- : 513 : {
#####:  514:	  players[i] = 1;
		-:  515 : }
	-: 516 : else
		- :  517 : {
#####:  518:	  players[i] = 0;
		-:  519 : }
	-: 520 : }
-:  521 :
#####:  522:  return 0;
	-:  523 : }
-:  524 :
	function drawCard called 6000 returned 100 % blocks executed 38 %
	6000 : 525 : int drawCard(int player, struct gameState *state)
	- : 526 : {	int count;
-:  527 : int deckCounter;
6000:  528 : if (state->deckCount[player] <= 0) {//Deck is empty
	branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-:  529 :
		-: 530 :    //Step 1 Shuffle the discard pile back into a deck
		-: 531 : int i;
	-:  532 :    //Move discard to deck
#####:  533:    for (i = 0; i < state->discardCount[player];i++){
		branch  0 never executed
		branch  1 never executed
#####:  534:      state->deck[player][i] = state->discard[player][i];
#####:  535:      state->discard[player][i] = -1;
		-:  536 : }
	-:  537 :
#####:  538:    state->deckCount[player] = state->discardCount[player];
#####:  539:    state->discardCount[player] = 0;//Reset discard
		-:  540 :
		-: 541 :    //Shufffle the deck
#####:  542:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
		call    0 never executed
		- :  543 :
		-: 544 : if (DEBUG) {//Debug statements
		-:  545 : printf("Deck count now: %d\n", state->deckCount[player]);
		-:  546 :
	}
	-: 547 :
#####:  548:    state->discardCount[player] = 0;
		-:  549 :
		-: 550 :    //Step 2 Draw Card
#####:  551:    count = state->handCount[player];//Get current player's hand count
		-:  552 :
		-: 553 : if (DEBUG) {//Debug statements
		-:  554 : printf("Current hand count: %d\n", count);
		-:  555 :
	}
	-: 556 :
#####:  557:    deckCounter = state->deckCount[player];//Create a holder for the deck count
		-:  558 :
#####:  559:    if (deckCounter == 0)
		branch  0 never executed
		branch  1 never executed
#####:  560:      return -1;
		-:  561 :
#####:  562:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
#####:  563:    state->deckCount[player]--;
#####:  564:    state->handCount[player]++;//Increment hand count
		-:  565 :
}
-:  566 :
	-: 567 : else {
	6000:  568 : int count = state->handCount[player];//Get current hand count for player
	-:  569 : int deckCounter;
	-:  570 : if (DEBUG) {//Debug statements
		-:  571 : printf("Current hand count: %d\n", count);
		-:  572 :
	}
	-: 573 :
		6000 : 574 : deckCounter = state->deckCount[player];//Create holder for the deck count
	6000:  575 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
	6000:  576 : state->deckCount[player]--;
	6000:  577 : state->handCount[player]++;//Increment hand count
	-:  578 :
}
-:  579 :
	6000 : 580 : return 0;
-:  581 : }
-:  582 :
	function getCost called 0 returned 0 % blocks executed 0 %
#####:  583:int getCost(int cardNumber)
	- : 584 : {
#####:  585:  switch( cardNumber ) 
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		branch  4 never executed
		branch  5 never executed
		branch  6 never executed
		branch  7 never executed
		branch  8 never executed
		branch  9 never executed
		branch 10 never executed
		branch 11 never executed
		branch 12 never executed
		branch 13 never executed
		branch 14 never executed
		branch 15 never executed
		branch 16 never executed
		branch 17 never executed
		branch 18 never executed
		branch 19 never executed
		branch 20 never executed
		branch 21 never executed
		branch 22 never executed
		branch 23 never executed
		branch 24 never executed
		branch 25 never executed
		branch 26 never executed
		branch 27 never executed
		- :  586 : {
		-:  587 : case curse:
#####:  588:      return 0;
			-:  589 : case estate:
#####:  590:      return 2;
				-:  591 : case duchy:
#####:  592:      return 5;
					-:  593 : case province:
#####:  594:      return 8;
						-:  595 : case copper:
#####:  596:      return 0;
							-:  597 : case silver:
#####:  598:      return 3;
								-:  599 : case gold:
#####:  600:      return 6;
									-:  601 : case adventurer:
#####:  602:      return 6;
										-:  603 : case council_room:
#####:  604:      return 5;
											-:  605 : case feast:
#####:  606:      return 4;
												-:  607 : case gardens:
#####:  608:      return 4;
													-:  609 : case mine:
#####:  610:      return 5;
														-:  611 : case remodel:
#####:  612:      return 4;
															-:  613 : case smithy:
#####:  614:      return 4;
																-:  615 : case village:
#####:  616:      return 3;
																	-:  617 : case baron:
#####:  618:      return 4;
																		-:  619 : case great_hall:
#####:  620:      return 3;
																			-:  621 : case minion:
#####:  622:      return 5;
																				-:  623 : case steward:
#####:  624:      return 3;
																					-:  625 : case tribute:
#####:  626:      return 5;
																						-:  627 : case ambassador:
#####:  628:      return 3;
																							-:  629 : case cutpurse:
#####:  630:      return 4;
																								-:  631 : case embargo:
#####:  632:      return 2;
																									-:  633 : case outpost:
#####:  634:      return 5;
																										-:  635 : case salvager:
#####:  636:      return 4;
																											-:  637 : case sea_hag:
#####:  638:      return 4;
																												-:  639 : case treasure_map:
#####:  640:      return 4;
																													-:  641 : }
	-:  642 :
#####:  643:  return -1;
		-:  644 : }
-:  645 :
	-: 646 :
	function council_room_function called 0 returned 0 % blocks executed 0 %
#####:  647:int council_room_function( struct gameState *state, int handPos )
	- : 648 : {
#####:  649:  int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  650 :   //+4 Cards
		-: 651 : int i;
#####:  652:      for (i = 0; i < 4; i++)
	branch  0 never executed
		branch  1 never executed
		- : 653 : {
#####:  654:	  drawCard(currentPlayer, state);
		call    0 never executed
			- :  655 : }
	-: 656 :
		-: 657 :      //+1 Buy
#####:  658:      state->numBuys = state->numBuys + state->numBuys;
		-:  659 :
		-: 660 :      //Each other player draws a card
#####:  661:      for (i = 1; i < state->numPlayers; i++)
		branch  0 never executed
		branch  1 never executed
		- : 662 : {
#####:  663:	  if ( i != currentPlayer )
		branch  0 never executed
			branch  1 never executed
			- : 664 : {
#####:  665:	      drawCard(i, state);
			call    0 never executed
				- :  666 : }
		-: 667 : }
	-:  668 :
		-: 669 :      //put played card in played card pile
#####:  670:      discardCard(handPos, currentPlayer+1 , state, 0);
		call    0 never executed
#####:  671:      return 0;
		-:  672 : }
-:  673 :
	function adventurer_function called 0 returned 0 % blocks executed 0 %
#####:  674:int adventurer_function( struct gameState *state, int handPos )
	- : 675 : {
#####:  676:  int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  677 : int temphand[MAX_HAND];// moved above the if statement
#####:  678:  int drawntreasure=0;
	-:  679 : int cardDrawn;
#####:  680:  int z = 0;// this is the counter for the temp hand
	-:  681 :
#####:  682:    while(drawntreasure<2){
		branch  0 never executed
		branch  1 never executed
#####:  683:	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
		branch  0 never executed
		branch  1 never executed
#####:  684:	  shuffle(currentPlayer, state);
		call    0 never executed
		- :  685 : }
#####:  686:	drawCard(currentPlayer, state);
		call    0 never executed
#####:  687:	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
#####:  688:	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
		branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		branch  4 never executed
		branch  5 never executed
#####:  689:	 drawntreasure++;
		-:  690 : else {
#####:  691:	  temphand[z]=cardDrawn;
#####:  692:	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
#####:  693:	  z++;
#####:  694:         drawntreasure--;
		-:  695 :
	}
	-:  696 : }
#####:  697:      while(z-1>=0){
	branch  0 never executed
		branch  1 never executed
#####:  698:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
#####:  699:	z=z-1;
		-:  700 : }
	-:  701 :
#####:  702:   return 0;
		-:  703 : }
-:  704 :
	-: 705 :
	function smithy_function called 0 returned 0 % blocks executed 0 %
#####:  706:int smithy_function( struct gameState *state, int handPos )
	- : 707 : {
#####:  708:int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  709 : int i;
	-:  710 : //+3 Cards
#####:  711:      for (i = 0; i < 3; i++)
		branch  0 never executed
		branch  1 never executed
		- : 712 : {
#####:  713:	  drawCard(currentPlayer, state);
		call    0 never executed
			- :  714 : }
	-: 715 :      //discard card from hand
#####:  716:      discardCard(handPos, currentPlayer + 1 , state, 1 );
		call    0 never executed
#####:  717:      return 0;
		-:  718 : }
-:  719 :
	function sea_hag_function called 0 returned 0 % blocks executed 0 %
#####:  720:int sea_hag_function( struct gameState *state, int handPos )
	- : 721 : {
	-:  722 : int i;
#####:  723: int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  724:     for (i = 0; i < state->numPlayers; i++){
		branch  0 never executed
		branch  1 never executed
#####:  725:	if (i == currentPlayer){
		branch  0 never executed
		branch  1 never executed
#####:  726:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####:  727:	  state->discardCount[i]++;
#####:  728:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
		-:  729 : }
		-:  730 : }
#####:  731:      return 0;
		-:  732 : }
function salvager_function called 0 returned 0 % blocks executed 0 %
#####:  733:int salvager_function( struct gameState *state, int handPos, int choice1 )
- : 734 : {
#####:  735: int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  736 :     //+1 buy
#####:  737:      state->numBuys++;
		-:  738 :
#####:  739:      if (choice1)
		branch  0 never executed
		branch  1 never executed
		- : 740 : {
		-:  741 :	  //gain coins equal to trashed card
#####:  742:	  state->coins = state->coins + getCost( handCard(choice1, state) );
			call    0 never executed
			call    1 never executed
			- :  743 :	  //trash card
#####:  744:	  discardCard(choice1, currentPlayer, state, 0);	
			call    0 never executed
			- :  745 : }
	-:  746 :
		-: 747 :      //discard card
#####:  748:      discardCard(handPos, currentPlayer, state, 1);
		call    0 never executed
#####:  749:      return 0;
		-:  750 : }
-:  751 :
	function cardEffect called 1000 returned 100 % blocks executed 3 %
	1000 : 752 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	- : 753 : {
	-:  754 : int i;
	-:  755 : int j;
	-:  756 : int k;
	-:  757 : int x;
	-:  758 : int index;
	1000:  759 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		1000:  760 : int nextPlayer = currentPlayer + 1;
	-:  761 :
		1000 : 762 : int tributeRevealedCards[2] = { -1, -1 };
	-:  763 : int temphand[MAX_HAND];// moved above the if statement
	1000:  764 : int drawntreasure = 0;
	-:  765 : int cardDrawn;
	1000:  766 : int z = 0;// this is the counter for the temp hand
	1000:  767 : if (nextPlayer > (state->numPlayers - 1)) {
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
#####:  768:    nextPlayer = 0;
			-:  769 :
	}
	-:  770 :
		-: 771 :
		-: 772 :  //uses switch to select card and perform actions
		1000 : 773 : switch (card)
		branch  0 taken 0 %
		branch  1 taken 0 %
		branch  2 taken 0 %
		branch  3 taken 0 %
		branch  4 taken 0 %
		branch  5 taken 0 %
		branch  6 taken 0 %
		branch  7 taken 100 %
		branch  8 taken 0 %
		branch  9 taken 0 %
		branch 10 taken 0 %
		branch 11 taken 0 %
		branch 12 taken 0 %
		branch 13 taken 0 %
		branch 14 taken 0 %
		branch 15 taken 0 %
		branch 16 taken 0 %
		branch 17 taken 0 %
		branch 18 taken 0 %
		branch 19 taken 0 %
		branch 20 taken 0 %
		-:  774 : {
		-:  775 : case adventurer:
#####:  776:      adventurer_function(state, handPos );
			call    0 never executed
				- :  777 ://      while(drawntreasure<2){
				-: 778 ://	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
				-: 779 ://	  shuffle(currentPlayer, state);
				-: 780 ://	}
				-: 781 ://	drawCard(currentPlayer, state);
				-: 782 ://	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
				-: 783 ://	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				-: 784 ://	  drawntreasure++;
				-: 785 ://	else{
				-: 786 ://	  temphand[z]=cardDrawn;
				-: 787 ://	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
				-: 788 ://	  z++;
				-: 789 ://	}
				-: 790 ://      }
				-: 791 ://      while(z-1>=0){
				-: 792 ://	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
				-: 793 ://	z=z-1;
				-: 794 ://      }
#####:  795:      return 0;
				-:  796 :
				-: 797 : case council_room:
#####:  798:    council_room_function(state, handPos );
					call    0 never executed
						- :  799 :     //+4 Cards
						-: 800 :     // for (i = 0; i < 4; i++)
						-: 801 ://	{
						-: 802 ://	  drawCard(currentPlayer, state);
						-: 803 ://	}
						-: 804 :
						-: 805 :      //+1 Buy
						-: 806 :  //    state->numBuys++;
						-: 807 :
						-: 808 :      //Each other player draws a card
						-: 809 :    //  for (i = 0; i < state->numPlayers; i++)
						-: 810 ://	{
						-: 811 ://	  if ( i != currentPlayer )
						-: 812 ://	    {
						-: 813 ://	      drawCard(i, state);
						-: 814 ://	    }
						-: 815 ://	}
						-: 816 :
						-: 817 :      //put played card in played card pile
						-: 818 :  //    discardCard(handPos, currentPlayer, state, 0);
						-: 819 :
#####:  820:      return 0;
						-:  821 :
						-: 822 : case feast:
							-: 823 :      //gain card with cost up to 5
								-: 824 :      //Backup hand
#####:  825:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
								branch  0 never executed
								branch  1 never executed
#####:  826:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####:  827:	state->hand[currentPlayer][i] = -1;//Set to nothing
								-:  828 : }
							-:  829 :      //Backup hand
								-: 830 :
								-: 831 :      //Update Coins for Buy
#####:  832:      updateCoins(currentPlayer, state, 5);
								call    0 never executed
#####:  833:      x = 1;//Condition to loop on
#####:  834:      while( x == 1) {//Buy one card
								branch  0 never executed
								branch  1 never executed
#####:  835:	if (supplyCount(choice1, state) <= 0){
								call    0 never executed
								branch  1 never executed
								branch  2 never executed
								- :  836 : if (DEBUG)
								-: 837 : printf("None of that card left, sorry!\n");
							-:  838 :
								-: 839 : if (DEBUG) {
								-:  840 : printf("Cards Left: %d\n", supplyCount(choice1, state));
								-:  841 :
							}
							-: 842 : }
#####:  843:	else if (state->coins < getCost(choice1)){
								call    0 never executed
								branch  1 never executed
								branch  2 never executed
#####:  844:	  printf("That card is too expensive!\n");
								call    0 never executed
								- :  845 :
								-: 846 : if (DEBUG) {
								-:  847 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
								-:  848 :
							}
							-: 849 : }
							-:  850 : else {
								-:  851 :
									-: 852 : if (DEBUG) {
									-:  853 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
									-:  854 :
								}
								-: 855 :
#####:  856:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
									call    0 never executed
#####:  857:	  x = 0;//No more buying cards
									-:  858 :
									-: 859 : if (DEBUG) {
									-:  860 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
									-:  861 :
								}
								-: 862 :
									-: 863 :
							}
							-:  864 : }
								-:  865 :
								-: 866 :      //Reset Hand
#####:  867:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
								branch  0 never executed
								branch  1 never executed
#####:  868:	state->hand[currentPlayer][i] = temphand[i];
#####:  869:	temphand[i] = -1;
								-:  870 : }
							-:  871 :      //Reset Hand
								-: 872 :
#####:  873:      return 0;
								-:  874 :
								-: 875 : case gardens:
#####:  876:      return -1;
									-:  877 :
										-: 878 : case mine:
#####:  879:      j = state->hand[currentPlayer][choice1];  //store card we will trash
											-:  880 :
#####:  881:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 882 : {
#####:  883:	  return -1;
												-:  884 : }
											-: 885 :
#####:  886:      if (choice2 > treasure_map || choice2 < curse)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 887 : {
#####:  888:	  return -1;
												-:  889 : }
											-: 890 :
#####:  891:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
												call    0 never executed
												call    1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 892 : {
#####:  893:	  return -1;
												-:  894 : }
											-: 895 :
#####:  896:      gainCard(choice2, state, 2, currentPlayer);
												call    0 never executed
												- :  897 :
												-: 898 :      //discard card from hand
#####:  899:      discardCard(handPos, currentPlayer, state, 0);
												call    0 never executed
												- :  900 :
												-: 901 :      //discard trashed card
#####:  902:      for (i = 0; i < state->handCount[currentPlayer]; i++)
												branch  0 never executed
												branch  1 never executed
												- : 903 : {
#####:  904:	  if (state->hand[currentPlayer][i] == j)
												branch  0 never executed
													branch  1 never executed
													- : 905 : {
#####:  906:	      discardCard(i, currentPlayer, state, 0);			
													call    0 never executed
#####:  907:	      break;
														-:  908 : }
												-: 909 : }
											-:  910 :
#####:  911:      return 0;
												-:  912 :
												-: 913 : case remodel:
#####:  914:      j = state->hand[currentPlayer][choice1];  //store card we will trash
													-:  915 :
#####:  916:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
														call    0 never executed
														call    1 never executed
														branch  2 never executed
														branch  3 never executed
														- : 917 : {
#####:  918:	  return -1;
														-:  919 : }
													-: 920 :
#####:  921:      gainCard(choice2, state, 0, currentPlayer);
														call    0 never executed
														- :  922 :
														-: 923 :      //discard card from hand
#####:  924:      discardCard(handPos, currentPlayer, state, 0);
														call    0 never executed
														- :  925 :
														-: 926 :      //discard trashed card
#####:  927:      for (i = 0; i < state->handCount[currentPlayer]; i++)
														branch  0 never executed
														branch  1 never executed
														- : 928 : {
#####:  929:	  if (state->hand[currentPlayer][i] == j)
														branch  0 never executed
															branch  1 never executed
															- : 930 : {
#####:  931:	      discardCard(i, currentPlayer, state, 0);			
															call    0 never executed
#####:  932:	      break;
																-:  933 : }
														-: 934 : }
													-:  935 :
														-: 936 :
#####:  937:      return 0;
														-:  938 :
														-: 939 : case smithy:
#####:  940:    smithy_function( state, handPos );
															call    0 never executed
																- :  941 :
																-: 942 :     //+3 Cards
																-: 943 ://      for (i = 0; i < 3; i++)
																-: 944 ://	{
																-: 945 ://	  drawCard(currentPlayer, state);
																-: 946 ://	}
																-: 947 ://			
																-: 948 :      //discard card from hand
																-: 949 ://      discardCard(handPos, currentPlayer, state, 0);
#####:  950:      return 0;
																-:  951 :
																-: 952 : case village:
																	-: 953 :      //+1 Card
																		1000 : 954 : drawCard(currentPlayer, state);
																	call    0 returned 100 %
																		-:  955 :
																		-: 956 :      //+2 Actions
																		1000 : 957 : state->numActions = state->numActions + 2;
																	-:  958 :
																		-: 959 :      //discard played card from hand
																		1000 : 960 : discardCard(handPos, currentPlayer, state, 0);
																	call    0 returned 100 %
																		1000:  961 : return 0;
																	-:  962 :
																		-: 963 : case baron:
#####:  964:      state->numBuys++;//Increase buys by 1!
#####:  965:      if (choice1 > 0){//Boolean true or going to discard an estate
																			branch  0 never executed
																				branch  1 never executed
#####:  966:	int p = 0;//Iterator for hand!
#####:  967:	int card_not_discarded = 1;//Flag for discard set!
#####:  968:	while(card_not_discarded){
																				branch  0 never executed
																				branch  1 never executed
#####:  969:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																				branch  0 never executed
																				branch  1 never executed
#####:  970:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  971:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  972:	    state->discardCount[currentPlayer]++;
#####:  973:	    for (;p < state->handCount[currentPlayer]; p++){
																				branch  0 never executed
																				branch  1 never executed
#####:  974:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																				-:  975 : }
#####:  976:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  977:	    state->handCount[currentPlayer]--;
#####:  978:	    card_not_discarded = 0;//Exit the loop
																				-:  979 : }
#####:  980:	  else if (p > state->handCount[currentPlayer]){
																				branch  0 never executed
																				branch  1 never executed
																				- :  981 : if (DEBUG) {
																				-:  982 : printf("No estate cards in your hand, invalid choice\n");
																				-:  983 : printf("Must gain an estate if there are any\n");
																				-:  984 :
																			}
#####:  985:	    if (supplyCount(estate, state) > 0){
																			call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  986:	      gainCard(estate, state, 0, currentPlayer);
																				call    0 never executed
#####:  987:	      state->supplyCount[estate]--;//Decrement estates
#####:  988:	      if (supplyCount(estate, state) == 0){
																				call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  989:		isGameOver(state);
																				call    0 never executed
																				- :  990 : }
																				-:  991 : }
#####:  992:	    card_not_discarded = 0;//Exit the loop
																				-:  993 : }
																			-:  994 :
																				-: 995 : else {
#####:  996:	    p++;//Next card
																				-:  997 :
																			}
																			-:  998 : }
																				-:  999 : }
																	-: 1000 :
																		-: 1001 : else {
#####: 1002:	if (supplyCount(estate, state) > 0){
																		call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####: 1003:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																			call    0 never executed
#####: 1004:	  state->supplyCount[estate]--;//Decrement Estates
#####: 1005:	  if (supplyCount(estate, state) == 0){
																			call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####: 1006:	    isGameOver(state);
																			call    0 never executed
																			- : 1007 : }
																			-: 1008 : }
																	-: 1009 :
																	}
																	-: 1010 :
																		-: 1011 :
#####: 1012:      return 0;
																		-: 1013 :
																		-: 1014 : case great_hall:
																			-: 1015 :      //+1 Card
#####: 1016:      drawCard(currentPlayer, state);
																				call    0 never executed
																				- : 1017 :
																				-: 1018 :      //+1 Actions
#####: 1019:      state->numActions++;
																				-: 1020 :
																				-: 1021 :      //discard card from hand
#####: 1022:      discardCard(handPos, currentPlayer, state, 0);
																				call    0 never executed
#####: 1023:      return 0;
																				-: 1024 :
																				-: 1025 : case minion:
																					-: 1026 :      //+1 action
#####: 1027:      state->numActions++;
																						-: 1028 :
																						-: 1029 :      //discard card from hand
#####: 1030:      discardCard(handPos, currentPlayer, state, 0);
																						call    0 never executed
																						- : 1031 :
#####: 1032:      if (choice1)		//+2 coins
																						branch  0 never executed
																						branch  1 never executed
																						- : 1033 : {
#####: 1034:	  state->coins = state->coins + 2;
																						-: 1035 : }
																					-: 1036 :
#####: 1037:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																						branch  0 never executed
																						branch  1 never executed
																						- : 1038 : {
																						-: 1039 :	  //discard hand
#####: 1040:	  while(numHandCards(state) > 0)
																							call    0 never executed
																							branch  1 never executed
																							branch  2 never executed
																							- : 1041 : {
#####: 1042:	      discardCard(handPos, currentPlayer, state, 0);
																							call    0 never executed
																								- : 1043 : }
																						-: 1044 :
																							-: 1045 :	  //draw 4
#####: 1046:	  for (i = 0; i < 4; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 1047 : {
#####: 1048:	      drawCard(currentPlayer, state);
																							call    0 never executed
																								- : 1049 : }
																						-: 1050 :
																							-: 1051 :	  //other players discard hand and redraw if hand size > 4
#####: 1052:	  for (i = 0; i < state->numPlayers; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 1053 : {
#####: 1054:	      if (i != currentPlayer)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1055 : {
#####: 1056:		  if ( state->handCount[i] > 4 )
																								branch  0 never executed
																									branch  1 never executed
																									- : 1057 : {
																									-: 1058 :		      //discard hand
#####: 1059:		      while( state->handCount[i] > 0 )
																										branch  0 never executed
																										branch  1 never executed
																										- : 1060 : {
#####: 1061:			  discardCard(handPos, i, state, 0);
																										call    0 never executed
																											- : 1062 : }
																									-: 1063 :
																										-: 1064 :		      //draw 4
#####: 1065:		      for (j = 0; j < 4; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1066 : {
#####: 1067:			  drawCard(i, state);
																										call    0 never executed
																											- : 1068 : }
																									-: 1069 : }
																								-: 1070 : }
																							-: 1071 : }
																						-: 1072 :
																							-: 1073 : }
#####: 1074:      return 0;
																					-: 1075 :
																						-: 1076 : case steward:
#####: 1077:      if (choice1 == 1)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1078 : {
																								-: 1079 :	  //+2 cards
#####: 1080:	  drawCard(currentPlayer, state);
																									call    0 never executed
#####: 1081:	  drawCard(currentPlayer, state);
																									call    0 never executed
																									- : 1082 : }
#####: 1083:      else if (choice1 == 2)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1084 : {
																								-: 1085 :	  //+2 coins
#####: 1086:	  state->coins = state->coins + 2;
																									-: 1087 : }
																							-: 1088 : else
																								- : 1089 : {
																								-: 1090 :	  //trash 2 cards in hand
#####: 1091:	  discardCard(choice2, currentPlayer, state, 1);
																									call    0 never executed
#####: 1092:	  discardCard(choice3, currentPlayer, state, 1);
																									call    0 never executed
																									- : 1093 : }
																							-: 1094 :
																								-: 1095 :      //discard card from hand
#####: 1096:      discardCard(handPos, currentPlayer, state, 0);
																								call    0 never executed
#####: 1097:      return 0;
																								-: 1098 :
																								-: 1099 : case tribute:
#####: 1100:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																									branch  0 never executed
																										branch  1 never executed
#####: 1101:	if (state->deckCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####: 1102:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1103:	  state->deckCount[nextPlayer]--;
																										-: 1104 : }
#####: 1105:	else if (state->discardCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####: 1106:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####: 1107:	  state->discardCount[nextPlayer]--;
																										-: 1108 : }
																									-: 1109 : else {
																										-: 1110 :	  //No Card to Reveal
																											-: 1111 : if (DEBUG) {
																											-: 1112 : printf("No cards to reveal\n");
																											-: 1113 :
																										}
																										-: 1114 :
																									}
																									-: 1115 : }
																							-: 1116 :
																								-: 1117 : else {
#####: 1118:	if (state->deckCount[nextPlayer] == 0){
																								branch  0 never executed
																									branch  1 never executed
#####: 1119:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																									branch  0 never executed
																									branch  1 never executed
#####: 1120:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####: 1121:	    state->deckCount[nextPlayer]++;
#####: 1122:	    state->discard[nextPlayer][i] = -1;
#####: 1123:	    state->discardCount[nextPlayer]--;
																									-: 1124 : }
																									-: 1125 :
#####: 1126:	  shuffle(nextPlayer,state);//Shuffle the deck
																									call    0 never executed
																									- : 1127 : }
#####: 1128:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1129:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1130:	state->deckCount[nextPlayer]--;
#####: 1131:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1132:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1133:	state->deckCount[nextPlayer]--;
																							-: 1134 :
																							}
																							-: 1135 :
#####: 1136:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																								branch  0 never executed
																								branch  1 never executed
#####: 1137:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####: 1138:	state->playedCardCount++;
#####: 1139:	tributeRevealedCards[1] = -1;
																								-: 1140 : }
																							-: 1141 :
#####: 1142:      for (i = 0; i <= 2; i ++){
																								branch  0 never executed
																								branch  1 never executed
#####: 1143:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
#####: 1144:	  state->coins += 2;
																								-: 1145 : }
																								-: 1146 :
#####: 1147:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
																								branch  6 never executed
																								branch  7 never executed
																								branch  8 never executed
																								branch  9 never executed
#####: 1148:	  drawCard(currentPlayer, state);
																								call    0 never executed
#####: 1149:	  drawCard(currentPlayer, state);
																								call    0 never executed
																								- : 1150 : }
																							-: 1151 : else {//Action Card
#####: 1152:	  state->numActions = state->numActions + 2;
																								-: 1153 :
																							}
																							-: 1154 : }
																							-: 1155 :
#####: 1156:      return 0;
																								-: 1157 :
																								-: 1158 : case ambassador:
#####: 1159:      j = 0;		//used to check if player has enough cards to discard
																									-: 1160 :
#####: 1161:      if (choice2 > 2 || choice2 < 0)
																										branch  0 never executed
																										branch  1 never executed
																										branch  2 never executed
																										branch  3 never executed
																										- : 1162 : {
#####: 1163:	  return -1;				
																										-: 1164 : }
																									-: 1165 :
#####: 1166:      if (choice1 == handPos)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1167 : {
#####: 1168:	  return -1;
																										-: 1169 : }
																									-: 1170 :
#####: 1171:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1172 : {
#####: 1173:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																										branch  0 never executed
																											branch  1 never executed
																											branch  2 never executed
																											branch  3 never executed
																											branch  4 never executed
																											branch  5 never executed
																											- : 1174 : {
#####: 1175:	      j++;
																											-: 1176 : }
																										-: 1177 : }
#####: 1178:      if (j < choice2)
																									branch  0 never executed
																										branch  1 never executed
																										- : 1179 : {
#####: 1180:	  return -1;				
																										-: 1181 : }
																									-: 1182 :
																										-: 1183 : if (DEBUG)
																										-: 1184 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																									-: 1185 :
																										-: 1186 :      //increase supply count for choosen card by amount being discarded
#####: 1187:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																										-: 1188 :
																										-: 1189 :      //each other player gains a copy of revealed card
#####: 1190:      for (i = 0; i < state->numPlayers; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1191 : {
#####: 1192:	  if (i != currentPlayer)
																										branch  0 never executed
																											branch  1 never executed
																											- : 1193 : {
#####: 1194:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																											call    0 never executed
																												- : 1195 : }
																										-: 1196 : }
																									-: 1197 :
																										-: 1198 :      //discard played card from hand
#####: 1199:      discardCard(handPos, currentPlayer, state, 0);			
																										call    0 never executed
																										- : 1200 :
																										-: 1201 :      //trash copies of cards returned to supply
#####: 1202:      for (j = 0; j < choice2; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1203 : {
#####: 1204:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																											branch  1 never executed
																											- : 1205 : {
#####: 1206:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																											branch  0 never executed
																												branch  1 never executed
																												- : 1207 : {
#####: 1208:		  discardCard(i, currentPlayer, state, 1);
																												call    0 never executed
#####: 1209:		  break;
																													-: 1210 : }
																											-: 1211 : }
																										-: 1212 : }
																									-: 1213 :
#####: 1214:      return 0;
																										-: 1215 :
																										-: 1216 : case cutpurse:
																											-: 1217 :
#####: 1218:      updateCoins(currentPlayer, state, 2);
																												call    0 never executed
#####: 1219:      for (i = 0; i < state->numPlayers; i++)
																												branch  0 never executed
																												branch  1 never executed
																												- : 1220 : {
#####: 1221:	  if (i != currentPlayer)
																												branch  0 never executed
																													branch  1 never executed
																													- : 1222 : {
#####: 1223:	      for (j = 0; j < state->handCount[i]; j++)
																													branch  0 never executed
																														branch  1 never executed
																														- : 1224 : {
#####: 1225:		  if (state->hand[i][j] == copper)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1226 : {
#####: 1227:		      discardCard(j, i, state, 0);
																															call    0 never executed
#####: 1228:		      break;
																																-: 1229 : }
#####: 1230:		  if (j == state->handCount[i])
																														branch  0 never executed
																															branch  1 never executed
																															- : 1231 : {
#####: 1232:		      for (k = 0; k < state->handCount[i]; k++)
																															branch  0 never executed
																																branch  1 never executed
																																- : 1233 : {
																																-: 1234 : if (DEBUG)
																																	-: 1235 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																-: 1236 : }
#####: 1237:		      break;
																															-: 1238 : }
																														-: 1239 : }
																													-: 1240 :
																														-: 1241 : }
																												-: 1242 :
																													-: 1243 : }
																											-: 1244 :
																												-: 1245 :      //discard played card from hand
#####: 1246:      discardCard(handPos, currentPlayer, state, 0);			
																												call    0 never executed
																												- : 1247 :
#####: 1248:      return 0;
																												-: 1249 :
																												-: 1250 :
																												-: 1251 : case embargo:
																													-: 1252 :      //+2 Coins
#####: 1253:      state->coins = state->coins + 2;
																														-: 1254 :
																														-: 1255 :      //see if selected pile is in play
#####: 1256:      if ( state->supplyCount[choice1] == -1 )
																														branch  0 never executed
																														branch  1 never executed
																														- : 1257 : {
#####: 1258:	  return -1;
																														-: 1259 : }
																													-: 1260 :
																														-: 1261 :      //add embargo token to selected supply pile
#####: 1262:      state->embargoTokens[choice1]++;
																														-: 1263 :
																														-: 1264 :      //trash card
#####: 1265:      discardCard(handPos, currentPlayer, state, 1);		
																														call    0 never executed
#####: 1266:      return 0;
																														-: 1267 :
																														-: 1268 : case outpost:
																															-: 1269 :      //set outpost flag
#####: 1270:      state->outpostPlayed++;
																																-: 1271 :
																																-: 1272 :      //discard card
#####: 1273:      discardCard(handPos, currentPlayer, state, 0);
																																call    0 never executed
#####: 1274:      return 0;
																																-: 1275 :
																																-: 1276 : case salvager:
#####: 1277:       salvager_function( state, handPos, choice1 ) ;
																																	call    0 never executed
																																		- : 1278 :      //+1 buy
																																		-: 1279 ://      state->numBuys++;
																																		-: 1280 :
																																		-: 1281 :  //    if (choice1)
																																		-: 1282 ://	{
																																		-: 1283 :	  //gain coins equal to trashed card
																																		-: 1284 ://	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																		-: 1285 :	  //trash card
																																		-: 1286 ://	  discardCard(choice1, currentPlayer, state, 1);	
																																		-: 1287 ://	}
																																		-: 1288 :
																																		-: 1289 :      //discard card
																																		-: 1290 ://      discardCard(handPos, currentPlayer, state, 0);
#####: 1291:      return 0;
																																		-: 1292 :
																																		-: 1293 : case sea_hag:
#####: 1294:      sea_hag_function(state, handPos);
																																			call    0 never executed
																																				- : 1295 ://      for (i = 0; i < state->numPlayers; i++){
																																				-: 1296 ://	if (i != currentPlayer){
																																				-: 1297 ://	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
																																				-: 1298 ://	  state->discardCount[i]++;
																																				-: 1299 ://	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																				-: 1300 ://	}
																																				-: 1301 ://      }
#####: 1302:      return 0;
																																				-: 1303 :
																																				-: 1304 : case treasure_map:
																																					-: 1305 :      //search hand for another treasure_map
#####: 1306:      index = -1;
#####: 1307:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																						branch  0 never executed
																																						branch  1 never executed
																																						- : 1308 : {
#####: 1309:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																						branch  0 never executed
																																							branch  1 never executed
																																							branch  2 never executed
																																							branch  3 never executed
																																							- : 1310 : {
#####: 1311:	      index = i;
#####: 1312:	      break;
																																							-: 1313 : }
																																						-: 1314 : }
#####: 1315:      if (index > -1)
																																					branch  0 never executed
																																						branch  1 never executed
																																						- : 1316 : {
																																						-: 1317 :	  //trash both treasure cards
#####: 1318:	  discardCard(handPos, currentPlayer, state, 1);
																																							call    0 never executed
#####: 1319:	  discardCard(index, currentPlayer, state, 1);
																																							call    0 never executed
																																							- : 1320 :
																																							-: 1321 :	  //gain 4 Gold cards
#####: 1322:	  for (i = 0; i < 4; i++)
																																							branch  0 never executed
																																							branch  1 never executed
																																							- : 1323 : {
#####: 1324:	      gainCard(gold, state, 1, currentPlayer);
																																							call    0 never executed
																																								- : 1325 : }
																																						-: 1326 :
																																							-: 1327 :	  //return success
#####: 1328:	  return 1;
																																							-: 1329 : }
																																					-: 1330 :
																																						-: 1331 :      //no second treasure_map found in hand
#####: 1332:      return -1;
																																						-: 1333 : }
	-: 1334 :
#####: 1335:  return -1;
		-: 1336 : }
-: 1337 :
	function discardCard called 1000 returned 100 % blocks executed 78 %
	1000 : 1338 : int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	- : 1339 : {
	-: 1340 :
		-: 1341 :  //if card is not trashed, added to Played pile 
		1000 : 1342 : if (trashFlag < 1)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 1343 : {
		-: 1344 :      //add card to played pile
			1000 : 1345 : state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
		1000: 1346 : state->playedCardCount++;
		-: 1347 : }
	-: 1348 :
		-: 1349 :  //set played card to -1
		1000 : 1350 : state->hand[currentPlayer][handPos] = -1;
	-: 1351 :
		-: 1352 :  //remove card from player's hand
		1000 : 1353 : if (handPos == (state->handCount[currentPlayer] - 1)) 	//last card in hand array is played
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-: 1354 : {
		-: 1355 :      //reduce number of cards in hand
#####: 1356:      state->handCount[currentPlayer]--;
			-: 1357 : }
	1000 : 1358 : else if (state->handCount[currentPlayer] == 1) //only one card in hand
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-: 1359 : {
		-: 1360 :      //reduce number of cards in hand
#####: 1361:      state->handCount[currentPlayer]--;
			-: 1362 : }
	-: 1363 : else
		- : 1364 : {
		-: 1365 :      //replace discarded card with last card in hand
			1000 : 1366 : state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
		-: 1367 :      //set last card to -1
			1000 : 1368 : state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
		-: 1369 :      //reduce number of cards in hand
			1000 : 1370 : state->handCount[currentPlayer]--;
		-: 1371 : }
	-: 1372 :
		1000 : 1373 : return 0;
	-: 1374 : }
-: 1375 :
	function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1376:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	- : 1377 : {
	-: 1378 :  //Note: supplyPos is enum of choosen card
		-: 1379 :
		-: 1380 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1381:  if ( supplyCount(supplyPos, state) < 1 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 1382 : {
#####: 1383:      return -1;
		-: 1384 : }
	-: 1385 :
		-: 1386 :  //added card for [whoseTurn] current player:
		-: 1387 :  // toFlag = 0 : add to discard
		-: 1388 :  // toFlag = 1 : add to deck
		-: 1389 :  // toFlag = 2 : add to hand
		-: 1390 :
#####: 1391:  if (toFlag == 1)
		branch  0 never executed
		branch  1 never executed
		- : 1392 : {
#####: 1393:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1394:      state->deckCount[player]++;
		-: 1395 : }
#####: 1396:  else if (toFlag == 2)
	branch  0 never executed
		branch  1 never executed
		- : 1397 : {
#####: 1398:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1399:      state->handCount[player]++;
		-: 1400 : }
	-: 1401 : else
		- : 1402 : {
#####: 1403:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1404:      state->discardCount[player]++;
		-: 1405 : }
	-: 1406 :
		-: 1407 :  //decrease number in supply pile
#####: 1408:  state->supplyCount[supplyPos]--;
		-: 1409 :
#####: 1410:  return 0;
		-: 1411 : }
-: 1412 :
	function updateCoins called 1000 returned 100 % blocks executed 82 %
	1000 : 1413 : int updateCoins(int player, struct gameState *state, int bonus)
	- : 1414 : {
	-: 1415 : int i;
	-: 1416 :
		-: 1417 :  //reset coin count
		1000 : 1418 : state->coins = 0;
	-: 1419 :
		-: 1420 :  //add coins for each Treasure card in player's hand
		6000 : 1421 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 1422 : {
		5000: 1423 : if (state->hand[player][i] == copper)
			branch  0 taken 80 % (fallthrough)
			branch  1 taken 20 %
			-: 1424 : {
			4000: 1425 : state->coins += 1;
			-: 1426 : }
		1000 : 1427 : else if (state->hand[player][i] == silver)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1428 : {
#####: 1429:	  state->coins += 2;
			-: 1430 : }
		1000 : 1431 : else if (state->hand[player][i] == gold)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1432 : {
#####: 1433:	  state->coins += 3;
			-: 1434 : }
		-: 1435 : }
	-: 1436 :
		-: 1437 :  //add bonus
		1000 : 1438 : state->coins += bonus;
	-: 1439 :
		1000 : 1440 : return 0;
	-: 1441 : }
-: 1442 :
	-: 1443 :
	-: 1444 ://end of dominion.c
	-: 1445 :

	---- - ADVENTURER RESULTS : ---- -
	In 1000 tests...
	Success : 0
	Error in Actions : 0
	Error in Buys : 0
	Error in Coins : 0
	Error in Hand Count : 1000
	Error in Discard + Deck + Played Count : 1000
	Error in Treasure Cards in Hand : 989
	Error in Treausre Cards in Discard + Deck + Played : 989
	Error in Supplies : 0
	Error in Opponents Deck : 0
	Error in Opponents Discard : 0
	File 'dominion.c'
	Lines executed : 23.82% of 571
	Branches executed : 25.18% of 417
	Taken at least once : 17.99% of 417
	Calls executed : 13.00% of 100
	Creating 'dominion.c.gcov'

	- : 0 : Source : dominion.c
	- : 0 : Graph : dominion.gcno
	- : 0 : Data : dominion.gcda
	- : 0 : Runs : 1
	- : 0 : Programs : 1
	- : 1 : #include "dominion.h"
	- : 2 : #include "dominion_helpers.h"
	- : 3 : #include "rngs.h"
	- : 4 : #include <stdio.h>
	- : 5 : #include <math.h>
	- : 6 : #include <stdlib.h>
	- : 7 :
	function compare called 274342 returned 100 % blocks executed 100 %
	274342 : 8 : int compare(const void* a, const void* b) {
	274342:    9 : if (*(int*)a > *(int*)b)
		branch  0 taken 45 % (fallthrough)
		branch  1 taken 55 %
		123468 : 10 : return 1;
	150874:   11 : if (*(int*)a < *(int*)b)
		branch  0 taken 55 % (fallthrough)
		branch  1 taken 45 %
		83301 : 12 : return -1;
	67573:   13 : return 0;
	-:   14 :
}
-:   15 :
	function newGame called 0 returned 0 % blocks executed 0 %
#####:   16:struct gameState* newGame() {
#####:   17:  struct gameState* g = malloc(sizeof(struct gameState));
#####:   18:  return g;
	-:   19 : }
-: 20 :
	function kingdomCards called 0 returned 0 % blocks executed 0 %
#####:   21:int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
	-:   22 : int k8, int k9, int k10) {
#####:   23:  int* k = malloc(10 * sizeof(int));
#####:   24:  k[0] = k1;
#####:   25:  k[1] = k2;
#####:   26:  k[2] = k3;
#####:   27:  k[3] = k4;
#####:   28:  k[4] = k5;
#####:   29:  k[5] = k6;
#####:   30:  k[6] = k7;
#####:   31:  k[7] = k8;
#####:   32:  k[8] = k9;
#####:   33:  k[9] = k10;
#####:   34:  return k;
	-:   35 :
}
-:   36 :
	function initializeGame called 1000 returned 100 % blocks executed 88 %
	1000 : 37 : int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
		-:   38 : struct gameState *state) {
	-:   39 :
		-: 40 : int i;
	-:   41 : int j;
	-:   42 : int it;
	-:   43 :  //set up random number generator
		1000 : 44 : SelectStream(1);
	call    0 returned 100 %
		1000:   45 : PutSeed((long)randomSeed);
	call    0 returned 100 %
		-:   46 :
		-: 47 :  //check number of players
		1000 : 48 : if (numPlayers > MAX_PLAYERS || numPlayers < 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		branch  2 taken 0 % (fallthrough)
		branch  3 taken 100 %
		-: 49 : {
#####:   50:      return -1;
		-:   51 : }
	-: 52 :
		-: 53 :  //set number of players
		1000 : 54 : state->numPlayers = numPlayers;
	-:   55 :
		-: 56 :  //check selected kingdom cards are different
		11000 : 57 : for (i = 0; i < 10; i++)
		branch  0 taken 91 %
		branch  1 taken 9 % (fallthrough)
		-: 58 : {
		110000:   59 : for (j = 0; j < 10; j++)
			branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			-: 60 : {
			100000:   61 : if (j != i && kingdomCards[j] == kingdomCards[i])
				branch  0 taken 90 % (fallthrough)
				branch  1 taken 10 %
				branch  2 taken 0 % (fallthrough)
				branch  3 taken 100 %
				-: 62 : {
#####:   63:	      return -1;
				-:   64 : }
			-: 65 : }
		-:   66 : }
	-:   67 :
		-: 68 :
		-: 69 :  //initialize supply
		-: 70 :  ///////////////////////////////
		-: 71 :
		-: 72 :  //set number of Curse cards
		1000 : 73 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 74 : {
		1000:   75 : state->supplyCount[curse] = 10;
		-:   76 : }
#####:   77:  else if (numPlayers == 3)
	branch  0 never executed
		branch  1 never executed
		- :   78 : {
#####:   79:      state->supplyCount[curse] = 20;
		-:   80 : }
	-: 81 : else
		- :   82 : {
#####:   83:      state->supplyCount[curse] = 30;
		-:   84 : }
	-: 85 :
		-: 86 :  //set number of Victory cards
		1000 : 87 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 88 : {
		1000:   89 : state->supplyCount[estate] = 8;
		1000:   90 : state->supplyCount[duchy] = 8;
		1000:   91 : state->supplyCount[province] = 8;
		-:   92 : }
	-: 93 : else
		- :   94 : {
#####:   95:      state->supplyCount[estate] = 12;
#####:   96:      state->supplyCount[duchy] = 12;
#####:   97:      state->supplyCount[province] = 12;
		-:   98 : }
	-: 99 :
		-: 100 :  //set number of Treasure cards
		1000 : 101 : state->supplyCount[copper] = 60 - (7 * numPlayers);
	1000:  102 : state->supplyCount[silver] = 40;
	1000:  103 : state->supplyCount[gold] = 30;
	-:  104 :
		-: 105 :  //set number of Kingdom cards
		21000 : 106 : for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
		branch  0 taken 95 %
		branch  1 taken 5 % (fallthrough)
		-: 107 : {
		165000:  108 : for (j = 0; j < 10; j++)           		//loop chosen cards
			branch  0 taken 94 %
			branch  1 taken 6 % (fallthrough)
			-: 109 : {
			155000:  110 : if (kingdomCards[j] == i)
				branch  0 taken 6 % (fallthrough)
				branch  1 taken 94 %
				-: 111 : {
				-:  112 :	      //check if card is a 'Victory' Kingdom card
					10000 : 113 : if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
					branch  0 taken 90 % (fallthrough)
					branch  1 taken 10 %
					branch  2 taken 11 % (fallthrough)
					branch  3 taken 89 %
					-: 114 : {
					4000:  115 : if (numPlayers == 2) {
						branch  0 taken 100 % (fallthrough)
							branch  1 taken 0 %
							2000:  116 : state->supplyCount[i] = 8;
						-:  117 :
					}
#####:  118:		  else{ state->supplyCount[i] = 12; }
					-:  119 : }
				-:  120 : else
					- :  121 : {
					8000:  122 : state->supplyCount[i] = 10;
					-:  123 : }
				10000 : 124 : break;
				-:  125 : }
			-:  126 : else    //card is not in the set choosen for the game
				- :  127 : {
				145000:  128 : state->supplyCount[i] = -1;
				-:  129 : }
			-: 130 : }
		-:  131 :
			-: 132 : }
	-:  133 :
		-: 134 :  ////////////////////////
		-: 135 :  //supply intilization complete
		-: 136 :
		-: 137 :  //set player decks
		3000 : 138 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 139 : {
		2000:  140 : state->deckCount[i] = 0;
		8000:  141 : for (j = 0; j < 3; j++)
			branch  0 taken 75 %
			branch  1 taken 25 % (fallthrough)
			-: 142 : {
			6000:  143 : state->deck[i][j] = estate;
			6000:  144 : state->deckCount[i]++;
			-:  145 : }
		16000 : 146 : for (j = 3; j < 10; j++)
			branch  0 taken 88 %
			branch  1 taken 13 % (fallthrough)
			-: 147 : {
			14000:  148 : state->deck[i][j] = copper;
			14000:  149 : state->deckCount[i]++;
			-:  150 : }
		-: 151 : }
	-:  152 :
		-: 153 :  //shuffle player decks
		3000 : 154 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 155 : {
		2000:  156 : if (shuffle(i, state) < 0)
			call    0 returned 100 %
			branch  1 taken 0 % (fallthrough)
			branch  2 taken 100 %
			-: 157 : {
#####:  158:	  return -1;
			-:  159 : }
		-: 160 : }
	-:  161 :
		-: 162 :  //draw player hands
		3000 : 163 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 164 : {
		-:  165 :      //initialize hand size to zero
			2000 : 166 : state->handCount[i] = 0;
		2000:  167 : state->discardCount[i] = 0;
		-:  168 :      //draw 5 cards
			-: 169 :      // for (j = 0; j < 5; j++)
			-: 170 :      //	{
			-: 171 :      //	  drawCard(i, state);
			-: 172 :      //	}
			-: 173 : }
	-:  174 :
		-: 175 :  //set embargo tokens to 0 for all supply piles
		28000 : 176 : for (i = 0; i <= treasure_map; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 177 : {
		27000:  178 : state->embargoTokens[i] = 0;
		-:  179 : }
	-: 180 :
		-: 181 :  //initialize first player's turn
		1000 : 182 : state->outpostPlayed = 0;
	1000:  183 : state->phase = 0;
	1000:  184 : state->numActions = 1;
	1000:  185 : state->numBuys = 1;
	1000:  186 : state->playedCardCount = 0;
	1000:  187 : state->whoseTurn = 0;
	1000:  188 : state->handCount[state->whoseTurn] = 0;
	-:  189 :  //int it; move to top
		-: 190 :
		-: 191 :  //Moved draw cards to here, only drawing at the start of a turn
		6000 : 192 : for (it = 0; it < 5; it++) {
		branch  0 taken 83 %
			branch  1 taken 17 % (fallthrough)
			5000:  193 : drawCard(state->whoseTurn, state);
		call    0 returned 100 %
			-:  194 :
	}
	-:  195 :
		1000 : 196 : updateCoins(state->whoseTurn, state, 0);
	call    0 returned 100 %
		-:  197 :
		1000 : 198 : return 0;
	-:  199 :
}
-:  200 :
	function shuffle called 166146 returned 100 % blocks executed 100 %
	166146 : 201 : int shuffle(int player, struct gameState *state) {
	-:  202 :
		-: 203 :
		-: 204 : int newDeck[MAX_DECK];
	166146:  205 : int newDeckPos = 0;
	-:  206 : int card;
	-:  207 : int i;
	-:  208 :
		166146 : 209 : if (state->deckCount[player] < 1)
		branch  0 taken 98 % (fallthrough)
		branch  1 taken 2 %
		163169 : 210 : return -1;
	2977:  211 : qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
	call    0 returned 100 %
		-:  212 :  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
		-: 213 :
		77483 : 214 : while (state->deckCount[player] > 0) {
		branch  0 taken 96 %
			branch  1 taken 4 % (fallthrough)
			71529:  215 : card = floor(Random() * state->deckCount[player]);
		call    0 returned 100 %
			71529:  216 : newDeck[newDeckPos] = state->deck[player][card];
		71529:  217 : newDeckPos++;
		928578:  218 : for (i = card; i < state->deckCount[player] - 1; i++) {
			branch  0 taken 92 %
				branch  1 taken 8 % (fallthrough)
				857049:  219 : state->deck[player][i] = state->deck[player][i + 1];
			-:  220 :
		}
		71529:  221 : state->deckCount[player]--;
		-:  222 :
	}
	74506:  223 : for (i = 0; i < newDeckPos; i++) {
		branch  0 taken 96 %
			branch  1 taken 4 % (fallthrough)
			71529:  224 : state->deck[player][i] = newDeck[i];
		71529:  225 : state->deckCount[player]++;
		-:  226 :
	}
	-:  227 :
		2977 : 228 : return 0;
	-:  229 :
}
-:  230 :
	function playCard called 0 returned 0 % blocks executed 0 %
#####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
	- : 232 : {
	-:  233 : int card;
#####:  234:  int coin_bonus = 0; 		//tracks coins gain from actions
	-:  235 :
		-: 236 :  //check if it is the right phase
#####:  237:  if (state->phase != 0)
		branch  0 never executed
		branch  1 never executed
		- : 238 : {
#####:  239:      return -1;
		-:  240 : }
	-: 241 :
		-: 242 :  //check if player has enough actions
#####:  243:  if ( state->numActions < 1 )
		branch  0 never executed
		branch  1 never executed
		- : 244 : {
#####:  245:      return -1;
		-:  246 : }
	-: 247 :
		-: 248 :  //get card played
#####:  249:  card = handCard(handPos, state);
		call    0 never executed
		- :  250 :
		-: 251 :  //check if selected card is an action
#####:  252:  if ( card < adventurer || card > treasure_map )
		branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 253 : {
#####:  254:      return -1;
		-:  255 : }
	-: 256 :
		-: 257 :  //play card
#####:  258:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 259 : {
#####:  260:      return -1;
		-:  261 : }
	-: 262 :
		-: 263 :  //reduce number of actions
#####:  264:  state->numActions--;
		-:  265 :
		-: 266 :  //update coins (Treasure cards may be added with card draws)
#####:  267:  updateCoins(state->whoseTurn, state, coin_bonus);
		call    0 never executed
		- :  268 :
#####:  269:  return 0;
		-:  270 : }
-:  271 :
	function buyCard called 0 returned 0 % blocks executed 0 %
#####:  272:int buyCard(int supplyPos, struct gameState *state) {
	-:  273 : int who;
-:  274 : if (DEBUG) {
	-:  275 : printf("Entering buyCard...\n");
	-:  276 :
}
-: 277 :
	-: 278 :  // I don't know what to do about the phase thing.
	-: 279 :
#####:  280:  who = state->whoseTurn;
	-:  281 :
#####:  282:  if (state->numBuys < 1){
	branch  0 never executed
	branch  1 never executed
	- :  283 : if (DEBUG)
	-: 284 : printf("You do not have any buys left\n");
#####:  285:    return -1;
#####:  286:  } else if (supplyCount(supplyPos, state) <1){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  287 : if (DEBUG)
-: 288 : printf("There are not any of that type of card left\n");
#####:  289:    return -1;
#####:  290:  } else if (state->coins < getCost(supplyPos)){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  291 : if (DEBUG)
-: 292 : printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
#####:  293:    return -1;
-:  294 : }
else {
#####:  295:    state->phase=1;
	-:  296 :    //state->supplyCount[supplyPos]--;
#####:  297:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
		call    0 never executed
		- :  298 :
#####:  299:    state->coins = (state->coins) - (getCost(supplyPos));
		call    0 never executed
#####:  300:    state->numBuys--;
		-:  301 : if (DEBUG)
		-: 302 : printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
	-:  303 :
}
-:  304 :
	-: 305 :  //state->discard[who][state->discardCount[who]] = supplyPos;
	-: 306 :  //state->discardCount[who]++;
	-: 307 :
#####:  308:  return 0;
	-:  309 : }
-:  310 :
	function numHandCards called 0 returned 0 % blocks executed 0 %
#####:  311:int numHandCards(struct gameState *state) {
#####:  312:  return state->handCount[ whoseTurn(state) ];
	call    0 never executed
	- :  313 : }
-: 314 :
	function handCard called 0 returned 0 % blocks executed 0 %
#####:  315:int handCard(int handPos, struct gameState *state) {
#####:  316:  int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  317:  return state->hand[currentPlayer][handPos];
	-:  318 : }
-: 319 :
	function supplyCount called 0 returned 0 % blocks executed 0 %
#####:  320:int supplyCount(int card, struct gameState *state) {
#####:  321:  return state->supplyCount[card];
	-:  322 : }
-: 323 :
	function fullDeckCount called 0 returned 0 % blocks executed 0 %
#####:  324:int fullDeckCount(int player, int card, struct gameState *state) {
	-:  325 : int i;
#####:  326:  int count = 0;
-:  327 :
#####:  328:  for (i = 0; i < state->deckCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 329 : {
#####:  330:      if (state->deck[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  331 : }
-: 332 :
#####:  333:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 334 : {
#####:  335:      if (state->hand[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  336 : }
-: 337 :
#####:  338:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 339 : {
#####:  340:      if (state->discard[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  341 : }
-: 342 :
#####:  343:  return count;
	-:  344 : }
-:  345 :
	function whoseTurn called 2000 returned 100 % blocks executed 100 %
	2000 : 346 : int whoseTurn(struct gameState *state) {
	2000:  347 : return state->whoseTurn;
	-:  348 :
}
-: 349 :
	function endTurn called 0 returned 0 % blocks executed 0 %
#####:  350:int endTurn(struct gameState *state) {
	-:  351 : int k;
-:  352 : int i;
#####:  353:  int currentPlayer = whoseTurn(state);
call    0 never executed
- :  354 :
	-: 355 :  //Discard hand
#####:  356:  for (i = 0; i < state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####:  357:    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
#####:  358:    state->hand[currentPlayer][i] = -1;//Set card to -1
	-:  359 : }
#####:  360:  state->handCount[currentPlayer] = 0;//Reset hand count
-:  361 :
	-: 362 :  //Code for determining the player
#####:  363:  if (currentPlayer < (state->numPlayers - 1)){ 
	branch  0 never executed
	branch  1 never executed
#####:  364:    state->whoseTurn = currentPlayer + 1;//Still safe to increment
	-:  365 : }
-: 366 : else {
#####:  367:    state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
	-:  368 :
}
-:  369 :
#####:  370:  state->outpostPlayed = 0;
#####:  371:  state->phase = 0;
#####:  372:  state->numActions = 1;
#####:  373:  state->coins = 0;
#####:  374:  state->numBuys = 1;
#####:  375:  state->playedCardCount = 0;
#####:  376:  state->handCount[state->whoseTurn] = 0;
	-:  377 :
	-: 378 :  //int k; move to top
	-: 379 :  //Next player draws hand
#####:  380:  for (k = 0; k < 5; k++){
	branch  0 never executed
	branch  1 never executed
#####:  381:    drawCard(state->whoseTurn, state);//Draw a card
	call    0 never executed
	- :  382 : }
-:  383 :
	-: 384 :  //Update money
#####:  385:  updateCoins(state->whoseTurn, state , 0);
	call    0 never executed
	- :  386 :
#####:  387:  return 0;
	-:  388 : }
-:  389 :
	function isGameOver called 0 returned 0 % blocks executed 0 %
#####:  390:int isGameOver(struct gameState *state) {
	-:  391 : int i;
-:  392 : int j;
-:  393 :
	-: 394 :  //if stack of Province cards is empty, the game ends
#####:  395:  if (state->supplyCount[province] == 0)
	branch  0 never executed
	branch  1 never executed
	- : 396 : {
#####:  397:      return 1;
	-:  398 : }
-: 399 :
	-: 400 :  //if three supply pile are at 0, the game ends
#####:  401:  j = 0;
#####:  402:  for (i = 0; i < 25; i++)
	branch  0 never executed
	branch  1 never executed
	- : 403 : {
#####:  404:      if (state->supplyCount[i] == 0)
	branch  0 never executed
		branch  1 never executed
		- : 405 : {
#####:  406:	  j++;
		-:  407 : }
	-: 408 : }
#####:  409:  if ( j >= 3)
branch  0 never executed
branch  1 never executed
- : 410 : {
#####:  411:      return 1;
	-:  412 : }
-: 413 :
#####:  414:  return 0;
	-:  415 : }
-:  416 :
	function scoreFor called 0 returned 0 % blocks executed 0 %
#####:  417:int scoreFor (int player, struct gameState *state) {
	-:  418 :
	-: 419 : int i;
#####:  420:  int score = 0;
-:  421 :  //score from hand
#####:  422:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 423 : {
#####:  424:      if (state->hand[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  425:      if (state->hand[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  426:      if (state->hand[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  427:      if (state->hand[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  428:      if (state->hand[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  429:      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  430 : }
-:  431 :
	-: 432 :  //score from discard
#####:  433:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 434 : {
#####:  435:      if (state->discard[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  436:      if (state->discard[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  437:      if (state->discard[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  438:      if (state->discard[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  439:      if (state->discard[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  440:      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  441 : }
-:  442 :
	-: 443 :  //score from deck
#####:  444:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 445 : {
#####:  446:      if (state->deck[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  447:      if (state->deck[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  448:      if (state->deck[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  449:      if (state->deck[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  450:      if (state->deck[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  451:      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  452 : }
-:  453 :
#####:  454:  return score;
	-:  455 : }
-:  456 :
	function getWinners called 0 returned 0 % blocks executed 0 %
#####:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
	-:  458 : int i;
-:  459 : int j;
-:  460 : int highScore;
-:  461 : int currentPlayer;
-:  462 :
	-: 463 :  //get score for each player
#####:  464:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 465 : {
	-:  466 :      //set unused player scores to -9999
#####:  467:      if (i >= state->numPlayers)
		branch  0 never executed
		branch  1 never executed
		- : 468 : {
#####:  469:	  players[i] = -9999;
		-:  470 : }
	-: 471 : else
		- :  472 : {
#####:  473:	  players[i] = scoreFor (i, state);
		call    0 never executed
			- :  474 : }
	-: 475 : }
-:  476 :
	-: 477 :  //find highest score
#####:  478:  j = 0;
#####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 480 : {
#####:  481:      if (players[i] > players[j])
	branch  0 never executed
		branch  1 never executed
		- : 482 : {
#####:  483:	  j = i;
		-:  484 : }
	-: 485 : }
#####:  486:  highScore = players[j];
-:  487 :
	-: 488 :  //add 1 to players who had less turns
#####:  489:  currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 491 : {
#####:  492:      if ( players[i] == highScore && i > currentPlayer )
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 493 : {
#####:  494:	  players[i]++;
		-:  495 : }
	-: 496 : }
-:  497 :
	-: 498 :  //find new highest score
#####:  499:  j = 0;
#####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 501 : {
#####:  502:      if ( players[i] > players[j] )
	branch  0 never executed
		branch  1 never executed
		- : 503 : {
#####:  504:	  j = i;
		-:  505 : }
	-: 506 : }
#####:  507:  highScore = players[j];
-:  508 :
	-: 509 :  //set winners in array to 1 and rest to 0
#####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 511 : {
#####:  512:      if ( players[i] == highScore )
	branch  0 never executed
		branch  1 never executed
		- : 513 : {
#####:  514:	  players[i] = 1;
		-:  515 : }
	-: 516 : else
		- :  517 : {
#####:  518:	  players[i] = 0;
		-:  519 : }
	-: 520 : }
-:  521 :
#####:  522:  return 0;
	-:  523 : }
-:  524 :
	function drawCard called 190174 returned 100 % blocks executed 100 %
	190174 : 525 : int drawCard(int player, struct gameState *state)
	- : 526 : {	int count;
-:  527 : int deckCounter;
190174:  528 : if (state->deckCount[player] <= 0) {//Deck is empty
	branch  0 taken 43 % (fallthrough)
		branch  1 taken 57 %
		-:  529 :
		-: 530 :    //Step 1 Shuffle the discard pile back into a deck
		-: 531 : int i;
	-:  532 :    //Move discard to deck
		133602 : 533 : for (i = 0; i < state->discardCount[player]; i++) {
		branch  0 taken 39 %
			branch  1 taken 61 % (fallthrough)
			51529:  534 : state->deck[player][i] = state->discard[player][i];
		51529:  535 : state->discard[player][i] = -1;
		-:  536 :
	}
	-:  537 :
		82073 : 538 : state->deckCount[player] = state->discardCount[player];
	82073:  539 : state->discardCount[player] = 0;//Reset discard
	-:  540 :
		-: 541 :    //Shufffle the deck
		82073 : 542 : shuffle(player, state);//Shuffle the deck up and make it so that we can draw
	call    0 returned 100 %
		-:  543 :
		-: 544 : if (DEBUG) {//Debug statements
		-:  545 : printf("Deck count now: %d\n", state->deckCount[player]);
		-:  546 :
	}
	-: 547 :
		82073 : 548 : state->discardCount[player] = 0;
	-:  549 :
		-: 550 :    //Step 2 Draw Card
		82073 : 551 : count = state->handCount[player];//Get current player's hand count
	-:  552 :
		-: 553 : if (DEBUG) {//Debug statements
		-:  554 : printf("Current hand count: %d\n", count);
		-:  555 :
	}
	-: 556 :
		82073 : 557 : deckCounter = state->deckCount[player];//Create a holder for the deck count
	-:  558 :
		82073 : 559 : if (deckCounter == 0)
		branch  0 taken 99 % (fallthrough)
		branch  1 taken 1 %
		81096 : 560 : return -1;
	-:  561 :
		977 : 562 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
	977:  563 : state->deckCount[player]--;
	977:  564 : state->handCount[player]++;//Increment hand count
	-:  565 :
}
-:  566 :
	-: 567 : else {
	108101:  568 : int count = state->handCount[player];//Get current hand count for player
	-:  569 : int deckCounter;
	-:  570 : if (DEBUG) {//Debug statements
		-:  571 : printf("Current hand count: %d\n", count);
		-:  572 :
	}
	-: 573 :
		108101 : 574 : deckCounter = state->deckCount[player];//Create holder for the deck count
	108101:  575 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
	108101:  576 : state->deckCount[player]--;
	108101:  577 : state->handCount[player]++;//Increment hand count
	-:  578 :
}
-:  579 :
	109078 : 580 : return 0;
-:  581 : }
-:  582 :
	function getCost called 0 returned 0 % blocks executed 0 %
#####:  583:int getCost(int cardNumber)
	- : 584 : {
#####:  585:  switch( cardNumber ) 
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		branch  4 never executed
		branch  5 never executed
		branch  6 never executed
		branch  7 never executed
		branch  8 never executed
		branch  9 never executed
		branch 10 never executed
		branch 11 never executed
		branch 12 never executed
		branch 13 never executed
		branch 14 never executed
		branch 15 never executed
		branch 16 never executed
		branch 17 never executed
		branch 18 never executed
		branch 19 never executed
		branch 20 never executed
		branch 21 never executed
		branch 22 never executed
		branch 23 never executed
		branch 24 never executed
		branch 25 never executed
		branch 26 never executed
		branch 27 never executed
		- :  586 : {
		-:  587 : case curse:
#####:  588:      return 0;
			-:  589 : case estate:
#####:  590:      return 2;
				-:  591 : case duchy:
#####:  592:      return 5;
					-:  593 : case province:
#####:  594:      return 8;
						-:  595 : case copper:
#####:  596:      return 0;
							-:  597 : case silver:
#####:  598:      return 3;
								-:  599 : case gold:
#####:  600:      return 6;
									-:  601 : case adventurer:
#####:  602:      return 6;
										-:  603 : case council_room:
#####:  604:      return 5;
											-:  605 : case feast:
#####:  606:      return 4;
												-:  607 : case gardens:
#####:  608:      return 4;
													-:  609 : case mine:
#####:  610:      return 5;
														-:  611 : case remodel:
#####:  612:      return 4;
															-:  613 : case smithy:
#####:  614:      return 4;
																-:  615 : case village:
#####:  616:      return 3;
																	-:  617 : case baron:
#####:  618:      return 4;
																		-:  619 : case great_hall:
#####:  620:      return 3;
																			-:  621 : case minion:
#####:  622:      return 5;
																				-:  623 : case steward:
#####:  624:      return 3;
																					-:  625 : case tribute:
#####:  626:      return 5;
																						-:  627 : case ambassador:
#####:  628:      return 3;
																							-:  629 : case cutpurse:
#####:  630:      return 4;
																								-:  631 : case embargo:
#####:  632:      return 2;
																									-:  633 : case outpost:
#####:  634:      return 5;
																										-:  635 : case salvager:
#####:  636:      return 4;
																											-:  637 : case sea_hag:
#####:  638:      return 4;
																												-:  639 : case treasure_map:
#####:  640:      return 4;
																													-:  641 : }
	-:  642 :
#####:  643:  return -1;
		-:  644 : }
-:  645 :
	-: 646 :
	function council_room_function called 0 returned 0 % blocks executed 0 %
#####:  647:int council_room_function( struct gameState *state, int handPos )
	- : 648 : {
#####:  649:  int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  650 :   //+4 Cards
		-: 651 : int i;
#####:  652:      for (i = 0; i < 4; i++)
	branch  0 never executed
		branch  1 never executed
		- : 653 : {
#####:  654:	  drawCard(currentPlayer, state);
		call    0 never executed
			- :  655 : }
	-: 656 :
		-: 657 :      //+1 Buy
#####:  658:      state->numBuys = state->numBuys + state->numBuys;
		-:  659 :
		-: 660 :      //Each other player draws a card
#####:  661:      for (i = 1; i < state->numPlayers; i++)
		branch  0 never executed
		branch  1 never executed
		- : 662 : {
#####:  663:	  if ( i != currentPlayer )
		branch  0 never executed
			branch  1 never executed
			- : 664 : {
#####:  665:	      drawCard(i, state);
			call    0 never executed
				- :  666 : }
		-: 667 : }
	-:  668 :
		-: 669 :      //put played card in played card pile
#####:  670:      discardCard(handPos, currentPlayer+1 , state, 0);
		call    0 never executed
#####:  671:      return 0;
		-:  672 : }
-:  673 :
	function adventurer_function called 1000 returned 100 % blocks executed 100 %
	1000 : 674 : int adventurer_function(struct gameState *state, int handPos)
	- : 675 : {
	1000:  676 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		-:  677 : int temphand[MAX_HAND];// moved above the if statement
	1000:  678 : int drawntreasure = 0;
	-:  679 : int cardDrawn;
	1000:  680 : int z = 0;// this is the counter for the temp hand
	-:  681 :
		187174 : 682 : while (drawntreasure<2) {
		branch  0 taken 99 %
			branch  1 taken 1 % (fallthrough)
			185174:  683 : if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			branch  0 taken 44 % (fallthrough)
				branch  1 taken 56 %
				82073:  684 : shuffle(currentPlayer, state);
			call    0 returned 100 %
				-:  685 :
		}
		185174:  686 : drawCard(currentPlayer, state);
		call    0 returned 100 %
			185174:  687 : cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		185174:  688 : if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			branch  0 taken 83 % (fallthrough)
			branch  1 taken 17 %
			branch  2 taken 80 % (fallthrough)
			branch  3 taken 20 %
			branch  4 taken 25 % (fallthrough)
			branch  5 taken 75 %
			93587:  689 : drawntreasure++;
		-:  690 : else {
			91587:  691 : temphand[z] = cardDrawn;
			91587:  692 : state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			91587:  693 : z++;
			91587:  694 : drawntreasure--;
			-:  695 :
		}
		-:  696 :
	}
	93587:  697 : while (z - 1 >= 0) {
		branch  0 taken 99 %
			branch  1 taken 1 % (fallthrough)
			91587:  698 : state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		91587:  699 : z = z - 1;
		-:  700 :
	}
	-:  701 :
		1000 : 702 : return 0;
	-:  703 : }
-:  704 :
	-: 705 :
	function smithy_function called 0 returned 0 % blocks executed 0 %
#####:  706:int smithy_function( struct gameState *state, int handPos )
	- : 707 : {
#####:  708:int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  709 : int i;
	-:  710 : //+3 Cards
#####:  711:      for (i = 0; i < 3; i++)
		branch  0 never executed
		branch  1 never executed
		- : 712 : {
#####:  713:	  drawCard(currentPlayer, state);
		call    0 never executed
			- :  714 : }
	-: 715 :      //discard card from hand
#####:  716:      discardCard(handPos, currentPlayer + 1 , state, 1 );
		call    0 never executed
#####:  717:      return 0;
		-:  718 : }
-:  719 :
	function sea_hag_function called 0 returned 0 % blocks executed 0 %
#####:  720:int sea_hag_function( struct gameState *state, int handPos )
	- : 721 : {
	-:  722 : int i;
#####:  723: int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  724:     for (i = 0; i < state->numPlayers; i++){
		branch  0 never executed
		branch  1 never executed
#####:  725:	if (i == currentPlayer){
		branch  0 never executed
		branch  1 never executed
#####:  726:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####:  727:	  state->discardCount[i]++;
#####:  728:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
		-:  729 : }
		-:  730 : }
#####:  731:      return 0;
		-:  732 : }
function salvager_function called 0 returned 0 % blocks executed 0 %
#####:  733:int salvager_function( struct gameState *state, int handPos, int choice1 )
- : 734 : {
#####:  735: int currentPlayer = whoseTurn(state);
	call    0 never executed
		- :  736 :     //+1 buy
#####:  737:      state->numBuys++;
		-:  738 :
#####:  739:      if (choice1)
		branch  0 never executed
		branch  1 never executed
		- : 740 : {
		-:  741 :	  //gain coins equal to trashed card
#####:  742:	  state->coins = state->coins + getCost( handCard(choice1, state) );
			call    0 never executed
			call    1 never executed
			- :  743 :	  //trash card
#####:  744:	  discardCard(choice1, currentPlayer, state, 0);	
			call    0 never executed
			- :  745 : }
	-:  746 :
		-: 747 :      //discard card
#####:  748:      discardCard(handPos, currentPlayer, state, 1);
		call    0 never executed
#####:  749:      return 0;
		-:  750 : }
-:  751 :
	function cardEffect called 1000 returned 100 % blocks executed 3 %
	1000 : 752 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	- : 753 : {
	-:  754 : int i;
	-:  755 : int j;
	-:  756 : int k;
	-:  757 : int x;
	-:  758 : int index;
	1000:  759 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		1000:  760 : int nextPlayer = currentPlayer + 1;
	-:  761 :
		1000 : 762 : int tributeRevealedCards[2] = { -1, -1 };
	-:  763 : int temphand[MAX_HAND];// moved above the if statement
	1000:  764 : int drawntreasure = 0;
	-:  765 : int cardDrawn;
	1000:  766 : int z = 0;// this is the counter for the temp hand
	1000:  767 : if (nextPlayer > (state->numPlayers - 1)) {
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
#####:  768:    nextPlayer = 0;
			-:  769 :
	}
	-:  770 :
		-: 771 :
		-: 772 :  //uses switch to select card and perform actions
		1000 : 773 : switch (card)
		branch  0 taken 100 %
		branch  1 taken 0 %
		branch  2 taken 0 %
		branch  3 taken 0 %
		branch  4 taken 0 %
		branch  5 taken 0 %
		branch  6 taken 0 %
		branch  7 taken 0 %
		branch  8 taken 0 %
		branch  9 taken 0 %
		branch 10 taken 0 %
		branch 11 taken 0 %
		branch 12 taken 0 %
		branch 13 taken 0 %
		branch 14 taken 0 %
		branch 15 taken 0 %
		branch 16 taken 0 %
		branch 17 taken 0 %
		branch 18 taken 0 %
		branch 19 taken 0 %
		branch 20 taken 0 %
		-:  774 : {
		-:  775 : case adventurer:
			1000 : 776 : adventurer_function(state, handPos);
			call    0 returned 100 %
				-:  777 ://      while(drawntreasure<2){
				-: 778 ://	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
				-: 779 ://	  shuffle(currentPlayer, state);
				-: 780 ://	}
				-: 781 ://	drawCard(currentPlayer, state);
				-: 782 ://	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
				-: 783 ://	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				-: 784 ://	  drawntreasure++;
				-: 785 ://	else{
				-: 786 ://	  temphand[z]=cardDrawn;
				-: 787 ://	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
				-: 788 ://	  z++;
				-: 789 ://	}
				-: 790 ://      }
				-: 791 ://      while(z-1>=0){
				-: 792 ://	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
				-: 793 ://	z=z-1;
				-: 794 ://      }
				1000 : 795 : return 0;
			-:  796 :
				-: 797 : case council_room:
#####:  798:    council_room_function(state, handPos );
					call    0 never executed
						- :  799 :     //+4 Cards
						-: 800 :     // for (i = 0; i < 4; i++)
						-: 801 ://	{
						-: 802 ://	  drawCard(currentPlayer, state);
						-: 803 ://	}
						-: 804 :
						-: 805 :      //+1 Buy
						-: 806 :  //    state->numBuys++;
						-: 807 :
						-: 808 :      //Each other player draws a card
						-: 809 :    //  for (i = 0; i < state->numPlayers; i++)
						-: 810 ://	{
						-: 811 ://	  if ( i != currentPlayer )
						-: 812 ://	    {
						-: 813 ://	      drawCard(i, state);
						-: 814 ://	    }
						-: 815 ://	}
						-: 816 :
						-: 817 :      //put played card in played card pile
						-: 818 :  //    discardCard(handPos, currentPlayer, state, 0);
						-: 819 :
#####:  820:      return 0;
						-:  821 :
						-: 822 : case feast:
							-: 823 :      //gain card with cost up to 5
								-: 824 :      //Backup hand
#####:  825:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
								branch  0 never executed
								branch  1 never executed
#####:  826:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####:  827:	state->hand[currentPlayer][i] = -1;//Set to nothing
								-:  828 : }
							-:  829 :      //Backup hand
								-: 830 :
								-: 831 :      //Update Coins for Buy
#####:  832:      updateCoins(currentPlayer, state, 5);
								call    0 never executed
#####:  833:      x = 1;//Condition to loop on
#####:  834:      while( x == 1) {//Buy one card
								branch  0 never executed
								branch  1 never executed
#####:  835:	if (supplyCount(choice1, state) <= 0){
								call    0 never executed
								branch  1 never executed
								branch  2 never executed
								- :  836 : if (DEBUG)
								-: 837 : printf("None of that card left, sorry!\n");
							-:  838 :
								-: 839 : if (DEBUG) {
								-:  840 : printf("Cards Left: %d\n", supplyCount(choice1, state));
								-:  841 :
							}
							-: 842 : }
#####:  843:	else if (state->coins < getCost(choice1)){
								call    0 never executed
								branch  1 never executed
								branch  2 never executed
#####:  844:	  printf("That card is too expensive!\n");
								call    0 never executed
								- :  845 :
								-: 846 : if (DEBUG) {
								-:  847 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
								-:  848 :
							}
							-: 849 : }
							-:  850 : else {
								-:  851 :
									-: 852 : if (DEBUG) {
									-:  853 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
									-:  854 :
								}
								-: 855 :
#####:  856:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
									call    0 never executed
#####:  857:	  x = 0;//No more buying cards
									-:  858 :
									-: 859 : if (DEBUG) {
									-:  860 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
									-:  861 :
								}
								-: 862 :
									-: 863 :
							}
							-:  864 : }
								-:  865 :
								-: 866 :      //Reset Hand
#####:  867:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
								branch  0 never executed
								branch  1 never executed
#####:  868:	state->hand[currentPlayer][i] = temphand[i];
#####:  869:	temphand[i] = -1;
								-:  870 : }
							-:  871 :      //Reset Hand
								-: 872 :
#####:  873:      return 0;
								-:  874 :
								-: 875 : case gardens:
#####:  876:      return -1;
									-:  877 :
										-: 878 : case mine:
#####:  879:      j = state->hand[currentPlayer][choice1];  //store card we will trash
											-:  880 :
#####:  881:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 882 : {
#####:  883:	  return -1;
												-:  884 : }
											-: 885 :
#####:  886:      if (choice2 > treasure_map || choice2 < curse)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 887 : {
#####:  888:	  return -1;
												-:  889 : }
											-: 890 :
#####:  891:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
												call    0 never executed
												call    1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 892 : {
#####:  893:	  return -1;
												-:  894 : }
											-: 895 :
#####:  896:      gainCard(choice2, state, 2, currentPlayer);
												call    0 never executed
												- :  897 :
												-: 898 :      //discard card from hand
#####:  899:      discardCard(handPos, currentPlayer, state, 0);
												call    0 never executed
												- :  900 :
												-: 901 :      //discard trashed card
#####:  902:      for (i = 0; i < state->handCount[currentPlayer]; i++)
												branch  0 never executed
												branch  1 never executed
												- : 903 : {
#####:  904:	  if (state->hand[currentPlayer][i] == j)
												branch  0 never executed
													branch  1 never executed
													- : 905 : {
#####:  906:	      discardCard(i, currentPlayer, state, 0);			
													call    0 never executed
#####:  907:	      break;
														-:  908 : }
												-: 909 : }
											-:  910 :
#####:  911:      return 0;
												-:  912 :
												-: 913 : case remodel:
#####:  914:      j = state->hand[currentPlayer][choice1];  //store card we will trash
													-:  915 :
#####:  916:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
														call    0 never executed
														call    1 never executed
														branch  2 never executed
														branch  3 never executed
														- : 917 : {
#####:  918:	  return -1;
														-:  919 : }
													-: 920 :
#####:  921:      gainCard(choice2, state, 0, currentPlayer);
														call    0 never executed
														- :  922 :
														-: 923 :      //discard card from hand
#####:  924:      discardCard(handPos, currentPlayer, state, 0);
														call    0 never executed
														- :  925 :
														-: 926 :      //discard trashed card
#####:  927:      for (i = 0; i < state->handCount[currentPlayer]; i++)
														branch  0 never executed
														branch  1 never executed
														- : 928 : {
#####:  929:	  if (state->hand[currentPlayer][i] == j)
														branch  0 never executed
															branch  1 never executed
															- : 930 : {
#####:  931:	      discardCard(i, currentPlayer, state, 0);			
															call    0 never executed
#####:  932:	      break;
																-:  933 : }
														-: 934 : }
													-:  935 :
														-: 936 :
#####:  937:      return 0;
														-:  938 :
														-: 939 : case smithy:
#####:  940:    smithy_function( state, handPos );
															call    0 never executed
																- :  941 :
																-: 942 :     //+3 Cards
																-: 943 ://      for (i = 0; i < 3; i++)
																-: 944 ://	{
																-: 945 ://	  drawCard(currentPlayer, state);
																-: 946 ://	}
																-: 947 ://			
																-: 948 :      //discard card from hand
																-: 949 ://      discardCard(handPos, currentPlayer, state, 0);
#####:  950:      return 0;
																-:  951 :
																-: 952 : case village:
																	-: 953 :      //+1 Card
#####:  954:      drawCard(currentPlayer, state);
																		call    0 never executed
																		- :  955 :
																		-: 956 :      //+2 Actions
#####:  957:      state->numActions = state->numActions + 2;
																		-:  958 :
																		-: 959 :      //discard played card from hand
#####:  960:      discardCard(handPos, currentPlayer, state, 0);
																		call    0 never executed
#####:  961:      return 0;
																		-:  962 :
																		-: 963 : case baron:
#####:  964:      state->numBuys++;//Increase buys by 1!
#####:  965:      if (choice1 > 0){//Boolean true or going to discard an estate
																			branch  0 never executed
																				branch  1 never executed
#####:  966:	int p = 0;//Iterator for hand!
#####:  967:	int card_not_discarded = 1;//Flag for discard set!
#####:  968:	while(card_not_discarded){
																				branch  0 never executed
																				branch  1 never executed
#####:  969:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																				branch  0 never executed
																				branch  1 never executed
#####:  970:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  971:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  972:	    state->discardCount[currentPlayer]++;
#####:  973:	    for (;p < state->handCount[currentPlayer]; p++){
																				branch  0 never executed
																				branch  1 never executed
#####:  974:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																				-:  975 : }
#####:  976:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  977:	    state->handCount[currentPlayer]--;
#####:  978:	    card_not_discarded = 0;//Exit the loop
																				-:  979 : }
#####:  980:	  else if (p > state->handCount[currentPlayer]){
																				branch  0 never executed
																				branch  1 never executed
																				- :  981 : if (DEBUG) {
																				-:  982 : printf("No estate cards in your hand, invalid choice\n");
																				-:  983 : printf("Must gain an estate if there are any\n");
																				-:  984 :
																			}
#####:  985:	    if (supplyCount(estate, state) > 0){
																			call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  986:	      gainCard(estate, state, 0, currentPlayer);
																				call    0 never executed
#####:  987:	      state->supplyCount[estate]--;//Decrement estates
#####:  988:	      if (supplyCount(estate, state) == 0){
																				call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  989:		isGameOver(state);
																				call    0 never executed
																				- :  990 : }
																				-:  991 : }
#####:  992:	    card_not_discarded = 0;//Exit the loop
																				-:  993 : }
																			-:  994 :
																				-: 995 : else {
#####:  996:	    p++;//Next card
																				-:  997 :
																			}
																			-:  998 : }
																				-:  999 : }
																	-: 1000 :
																		-: 1001 : else {
#####: 1002:	if (supplyCount(estate, state) > 0){
																		call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####: 1003:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																			call    0 never executed
#####: 1004:	  state->supplyCount[estate]--;//Decrement Estates
#####: 1005:	  if (supplyCount(estate, state) == 0){
																			call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####: 1006:	    isGameOver(state);
																			call    0 never executed
																			- : 1007 : }
																			-: 1008 : }
																	-: 1009 :
																	}
																	-: 1010 :
																		-: 1011 :
#####: 1012:      return 0;
																		-: 1013 :
																		-: 1014 : case great_hall:
																			-: 1015 :      //+1 Card
#####: 1016:      drawCard(currentPlayer, state);
																				call    0 never executed
																				- : 1017 :
																				-: 1018 :      //+1 Actions
#####: 1019:      state->numActions++;
																				-: 1020 :
																				-: 1021 :      //discard card from hand
#####: 1022:      discardCard(handPos, currentPlayer, state, 0);
																				call    0 never executed
#####: 1023:      return 0;
																				-: 1024 :
																				-: 1025 : case minion:
																					-: 1026 :      //+1 action
#####: 1027:      state->numActions++;
																						-: 1028 :
																						-: 1029 :      //discard card from hand
#####: 1030:      discardCard(handPos, currentPlayer, state, 0);
																						call    0 never executed
																						- : 1031 :
#####: 1032:      if (choice1)		//+2 coins
																						branch  0 never executed
																						branch  1 never executed
																						- : 1033 : {
#####: 1034:	  state->coins = state->coins + 2;
																						-: 1035 : }
																					-: 1036 :
#####: 1037:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																						branch  0 never executed
																						branch  1 never executed
																						- : 1038 : {
																						-: 1039 :	  //discard hand
#####: 1040:	  while(numHandCards(state) > 0)
																							call    0 never executed
																							branch  1 never executed
																							branch  2 never executed
																							- : 1041 : {
#####: 1042:	      discardCard(handPos, currentPlayer, state, 0);
																							call    0 never executed
																								- : 1043 : }
																						-: 1044 :
																							-: 1045 :	  //draw 4
#####: 1046:	  for (i = 0; i < 4; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 1047 : {
#####: 1048:	      drawCard(currentPlayer, state);
																							call    0 never executed
																								- : 1049 : }
																						-: 1050 :
																							-: 1051 :	  //other players discard hand and redraw if hand size > 4
#####: 1052:	  for (i = 0; i < state->numPlayers; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 1053 : {
#####: 1054:	      if (i != currentPlayer)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1055 : {
#####: 1056:		  if ( state->handCount[i] > 4 )
																								branch  0 never executed
																									branch  1 never executed
																									- : 1057 : {
																									-: 1058 :		      //discard hand
#####: 1059:		      while( state->handCount[i] > 0 )
																										branch  0 never executed
																										branch  1 never executed
																										- : 1060 : {
#####: 1061:			  discardCard(handPos, i, state, 0);
																										call    0 never executed
																											- : 1062 : }
																									-: 1063 :
																										-: 1064 :		      //draw 4
#####: 1065:		      for (j = 0; j < 4; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1066 : {
#####: 1067:			  drawCard(i, state);
																										call    0 never executed
																											- : 1068 : }
																									-: 1069 : }
																								-: 1070 : }
																							-: 1071 : }
																						-: 1072 :
																							-: 1073 : }
#####: 1074:      return 0;
																					-: 1075 :
																						-: 1076 : case steward:
#####: 1077:      if (choice1 == 1)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1078 : {
																								-: 1079 :	  //+2 cards
#####: 1080:	  drawCard(currentPlayer, state);
																									call    0 never executed
#####: 1081:	  drawCard(currentPlayer, state);
																									call    0 never executed
																									- : 1082 : }
#####: 1083:      else if (choice1 == 2)
																							branch  0 never executed
																								branch  1 never executed
																								- : 1084 : {
																								-: 1085 :	  //+2 coins
#####: 1086:	  state->coins = state->coins + 2;
																									-: 1087 : }
																							-: 1088 : else
																								- : 1089 : {
																								-: 1090 :	  //trash 2 cards in hand
#####: 1091:	  discardCard(choice2, currentPlayer, state, 1);
																									call    0 never executed
#####: 1092:	  discardCard(choice3, currentPlayer, state, 1);
																									call    0 never executed
																									- : 1093 : }
																							-: 1094 :
																								-: 1095 :      //discard card from hand
#####: 1096:      discardCard(handPos, currentPlayer, state, 0);
																								call    0 never executed
#####: 1097:      return 0;
																								-: 1098 :
																								-: 1099 : case tribute:
#####: 1100:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																									branch  0 never executed
																										branch  1 never executed
#####: 1101:	if (state->deckCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####: 1102:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1103:	  state->deckCount[nextPlayer]--;
																										-: 1104 : }
#####: 1105:	else if (state->discardCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####: 1106:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####: 1107:	  state->discardCount[nextPlayer]--;
																										-: 1108 : }
																									-: 1109 : else {
																										-: 1110 :	  //No Card to Reveal
																											-: 1111 : if (DEBUG) {
																											-: 1112 : printf("No cards to reveal\n");
																											-: 1113 :
																										}
																										-: 1114 :
																									}
																									-: 1115 : }
																							-: 1116 :
																								-: 1117 : else {
#####: 1118:	if (state->deckCount[nextPlayer] == 0){
																								branch  0 never executed
																									branch  1 never executed
#####: 1119:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																									branch  0 never executed
																									branch  1 never executed
#####: 1120:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####: 1121:	    state->deckCount[nextPlayer]++;
#####: 1122:	    state->discard[nextPlayer][i] = -1;
#####: 1123:	    state->discardCount[nextPlayer]--;
																									-: 1124 : }
																									-: 1125 :
#####: 1126:	  shuffle(nextPlayer,state);//Shuffle the deck
																									call    0 never executed
																									- : 1127 : }
#####: 1128:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1129:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1130:	state->deckCount[nextPlayer]--;
#####: 1131:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1132:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1133:	state->deckCount[nextPlayer]--;
																							-: 1134 :
																							}
																							-: 1135 :
#####: 1136:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																								branch  0 never executed
																								branch  1 never executed
#####: 1137:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####: 1138:	state->playedCardCount++;
#####: 1139:	tributeRevealedCards[1] = -1;
																								-: 1140 : }
																							-: 1141 :
#####: 1142:      for (i = 0; i <= 2; i ++){
																								branch  0 never executed
																								branch  1 never executed
#####: 1143:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
#####: 1144:	  state->coins += 2;
																								-: 1145 : }
																								-: 1146 :
#####: 1147:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
																								branch  6 never executed
																								branch  7 never executed
																								branch  8 never executed
																								branch  9 never executed
#####: 1148:	  drawCard(currentPlayer, state);
																								call    0 never executed
#####: 1149:	  drawCard(currentPlayer, state);
																								call    0 never executed
																								- : 1150 : }
																							-: 1151 : else {//Action Card
#####: 1152:	  state->numActions = state->numActions + 2;
																								-: 1153 :
																							}
																							-: 1154 : }
																							-: 1155 :
#####: 1156:      return 0;
																								-: 1157 :
																								-: 1158 : case ambassador:
#####: 1159:      j = 0;		//used to check if player has enough cards to discard
																									-: 1160 :
#####: 1161:      if (choice2 > 2 || choice2 < 0)
																										branch  0 never executed
																										branch  1 never executed
																										branch  2 never executed
																										branch  3 never executed
																										- : 1162 : {
#####: 1163:	  return -1;				
																										-: 1164 : }
																									-: 1165 :
#####: 1166:      if (choice1 == handPos)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1167 : {
#####: 1168:	  return -1;
																										-: 1169 : }
																									-: 1170 :
#####: 1171:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1172 : {
#####: 1173:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																										branch  0 never executed
																											branch  1 never executed
																											branch  2 never executed
																											branch  3 never executed
																											branch  4 never executed
																											branch  5 never executed
																											- : 1174 : {
#####: 1175:	      j++;
																											-: 1176 : }
																										-: 1177 : }
#####: 1178:      if (j < choice2)
																									branch  0 never executed
																										branch  1 never executed
																										- : 1179 : {
#####: 1180:	  return -1;				
																										-: 1181 : }
																									-: 1182 :
																										-: 1183 : if (DEBUG)
																										-: 1184 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																									-: 1185 :
																										-: 1186 :      //increase supply count for choosen card by amount being discarded
#####: 1187:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																										-: 1188 :
																										-: 1189 :      //each other player gains a copy of revealed card
#####: 1190:      for (i = 0; i < state->numPlayers; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1191 : {
#####: 1192:	  if (i != currentPlayer)
																										branch  0 never executed
																											branch  1 never executed
																											- : 1193 : {
#####: 1194:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																											call    0 never executed
																												- : 1195 : }
																										-: 1196 : }
																									-: 1197 :
																										-: 1198 :      //discard played card from hand
#####: 1199:      discardCard(handPos, currentPlayer, state, 0);			
																										call    0 never executed
																										- : 1200 :
																										-: 1201 :      //trash copies of cards returned to supply
#####: 1202:      for (j = 0; j < choice2; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 1203 : {
#####: 1204:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																											branch  1 never executed
																											- : 1205 : {
#####: 1206:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																											branch  0 never executed
																												branch  1 never executed
																												- : 1207 : {
#####: 1208:		  discardCard(i, currentPlayer, state, 1);
																												call    0 never executed
#####: 1209:		  break;
																													-: 1210 : }
																											-: 1211 : }
																										-: 1212 : }
																									-: 1213 :
#####: 1214:      return 0;
																										-: 1215 :
																										-: 1216 : case cutpurse:
																											-: 1217 :
#####: 1218:      updateCoins(currentPlayer, state, 2);
																												call    0 never executed
#####: 1219:      for (i = 0; i < state->numPlayers; i++)
																												branch  0 never executed
																												branch  1 never executed
																												- : 1220 : {
#####: 1221:	  if (i != currentPlayer)
																												branch  0 never executed
																													branch  1 never executed
																													- : 1222 : {
#####: 1223:	      for (j = 0; j < state->handCount[i]; j++)
																													branch  0 never executed
																														branch  1 never executed
																														- : 1224 : {
#####: 1225:		  if (state->hand[i][j] == copper)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1226 : {
#####: 1227:		      discardCard(j, i, state, 0);
																															call    0 never executed
#####: 1228:		      break;
																																-: 1229 : }
#####: 1230:		  if (j == state->handCount[i])
																														branch  0 never executed
																															branch  1 never executed
																															- : 1231 : {
#####: 1232:		      for (k = 0; k < state->handCount[i]; k++)
																															branch  0 never executed
																																branch  1 never executed
																																- : 1233 : {
																																-: 1234 : if (DEBUG)
																																	-: 1235 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																-: 1236 : }
#####: 1237:		      break;
																															-: 1238 : }
																														-: 1239 : }
																													-: 1240 :
																														-: 1241 : }
																												-: 1242 :
																													-: 1243 : }
																											-: 1244 :
																												-: 1245 :      //discard played card from hand
#####: 1246:      discardCard(handPos, currentPlayer, state, 0);			
																												call    0 never executed
																												- : 1247 :
#####: 1248:      return 0;
																												-: 1249 :
																												-: 1250 :
																												-: 1251 : case embargo:
																													-: 1252 :      //+2 Coins
#####: 1253:      state->coins = state->coins + 2;
																														-: 1254 :
																														-: 1255 :      //see if selected pile is in play
#####: 1256:      if ( state->supplyCount[choice1] == -1 )
																														branch  0 never executed
																														branch  1 never executed
																														- : 1257 : {
#####: 1258:	  return -1;
																														-: 1259 : }
																													-: 1260 :
																														-: 1261 :      //add embargo token to selected supply pile
#####: 1262:      state->embargoTokens[choice1]++;
																														-: 1263 :
																														-: 1264 :      //trash card
#####: 1265:      discardCard(handPos, currentPlayer, state, 1);		
																														call    0 never executed
#####: 1266:      return 0;
																														-: 1267 :
																														-: 1268 : case outpost:
																															-: 1269 :      //set outpost flag
#####: 1270:      state->outpostPlayed++;
																																-: 1271 :
																																-: 1272 :      //discard card
#####: 1273:      discardCard(handPos, currentPlayer, state, 0);
																																call    0 never executed
#####: 1274:      return 0;
																																-: 1275 :
																																-: 1276 : case salvager:
#####: 1277:       salvager_function( state, handPos, choice1 ) ;
																																	call    0 never executed
																																		- : 1278 :      //+1 buy
																																		-: 1279 ://      state->numBuys++;
																																		-: 1280 :
																																		-: 1281 :  //    if (choice1)
																																		-: 1282 ://	{
																																		-: 1283 :	  //gain coins equal to trashed card
																																		-: 1284 ://	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																		-: 1285 :	  //trash card
																																		-: 1286 ://	  discardCard(choice1, currentPlayer, state, 1);	
																																		-: 1287 ://	}
																																		-: 1288 :
																																		-: 1289 :      //discard card
																																		-: 1290 ://      discardCard(handPos, currentPlayer, state, 0);
#####: 1291:      return 0;
																																		-: 1292 :
																																		-: 1293 : case sea_hag:
#####: 1294:      sea_hag_function(state, handPos);
																																			call    0 never executed
																																				- : 1295 ://      for (i = 0; i < state->numPlayers; i++){
																																				-: 1296 ://	if (i != currentPlayer){
																																				-: 1297 ://	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
																																				-: 1298 ://	  state->discardCount[i]++;
																																				-: 1299 ://	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																				-: 1300 ://	}
																																				-: 1301 ://      }
#####: 1302:      return 0;
																																				-: 1303 :
																																				-: 1304 : case treasure_map:
																																					-: 1305 :      //search hand for another treasure_map
#####: 1306:      index = -1;
#####: 1307:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																						branch  0 never executed
																																						branch  1 never executed
																																						- : 1308 : {
#####: 1309:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																						branch  0 never executed
																																							branch  1 never executed
																																							branch  2 never executed
																																							branch  3 never executed
																																							- : 1310 : {
#####: 1311:	      index = i;
#####: 1312:	      break;
																																							-: 1313 : }
																																						-: 1314 : }
#####: 1315:      if (index > -1)
																																					branch  0 never executed
																																						branch  1 never executed
																																						- : 1316 : {
																																						-: 1317 :	  //trash both treasure cards
#####: 1318:	  discardCard(handPos, currentPlayer, state, 1);
																																							call    0 never executed
#####: 1319:	  discardCard(index, currentPlayer, state, 1);
																																							call    0 never executed
																																							- : 1320 :
																																							-: 1321 :	  //gain 4 Gold cards
#####: 1322:	  for (i = 0; i < 4; i++)
																																							branch  0 never executed
																																							branch  1 never executed
																																							- : 1323 : {
#####: 1324:	      gainCard(gold, state, 1, currentPlayer);
																																							call    0 never executed
																																								- : 1325 : }
																																						-: 1326 :
																																							-: 1327 :	  //return success
#####: 1328:	  return 1;
																																							-: 1329 : }
																																					-: 1330 :
																																						-: 1331 :      //no second treasure_map found in hand
#####: 1332:      return -1;
																																						-: 1333 : }
	-: 1334 :
#####: 1335:  return -1;
		-: 1336 : }
-: 1337 :
	function discardCard called 0 returned 0 % blocks executed 0 %
#####: 1338:int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	- : 1339 : {
	-: 1340 :
		-: 1341 :  //if card is not trashed, added to Played pile 
#####: 1342:  if (trashFlag < 1)
		branch  0 never executed
		branch  1 never executed
		- : 1343 : {
		-: 1344 :      //add card to played pile
#####: 1345:      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
#####: 1346:      state->playedCardCount++;
			-: 1347 : }
	-: 1348 :
		-: 1349 :  //set played card to -1
#####: 1350:  state->hand[currentPlayer][handPos] = -1;
		-: 1351 :
		-: 1352 :  //remove card from player's hand
#####: 1353:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
		branch  0 never executed
		branch  1 never executed
		- : 1354 : {
		-: 1355 :      //reduce number of cards in hand
#####: 1356:      state->handCount[currentPlayer]--;
			-: 1357 : }
#####: 1358:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
	branch  0 never executed
		branch  1 never executed
		- : 1359 : {
		-: 1360 :      //reduce number of cards in hand
#####: 1361:      state->handCount[currentPlayer]--;
			-: 1362 : }
	-: 1363 : else
		- : 1364 : {
		-: 1365 :      //replace discarded card with last card in hand
#####: 1366:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
			-: 1367 :      //set last card to -1
#####: 1368:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
			-: 1369 :      //reduce number of cards in hand
#####: 1370:      state->handCount[currentPlayer]--;
			-: 1371 : }
	-: 1372 :
#####: 1373:  return 0;
		-: 1374 : }
-: 1375 :
	function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1376:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	- : 1377 : {
	-: 1378 :  //Note: supplyPos is enum of choosen card
		-: 1379 :
		-: 1380 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1381:  if ( supplyCount(supplyPos, state) < 1 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 1382 : {
#####: 1383:      return -1;
		-: 1384 : }
	-: 1385 :
		-: 1386 :  //added card for [whoseTurn] current player:
		-: 1387 :  // toFlag = 0 : add to discard
		-: 1388 :  // toFlag = 1 : add to deck
		-: 1389 :  // toFlag = 2 : add to hand
		-: 1390 :
#####: 1391:  if (toFlag == 1)
		branch  0 never executed
		branch  1 never executed
		- : 1392 : {
#####: 1393:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1394:      state->deckCount[player]++;
		-: 1395 : }
#####: 1396:  else if (toFlag == 2)
	branch  0 never executed
		branch  1 never executed
		- : 1397 : {
#####: 1398:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1399:      state->handCount[player]++;
		-: 1400 : }
	-: 1401 : else
		- : 1402 : {
#####: 1403:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1404:      state->discardCount[player]++;
		-: 1405 : }
	-: 1406 :
		-: 1407 :  //decrease number in supply pile
#####: 1408:  state->supplyCount[supplyPos]--;
		-: 1409 :
#####: 1410:  return 0;
		-: 1411 : }
-: 1412 :
	function updateCoins called 1000 returned 100 % blocks executed 82 %
	1000 : 1413 : int updateCoins(int player, struct gameState *state, int bonus)
	- : 1414 : {
	-: 1415 : int i;
	-: 1416 :
		-: 1417 :  //reset coin count
		1000 : 1418 : state->coins = 0;
	-: 1419 :
		-: 1420 :  //add coins for each Treasure card in player's hand
		6000 : 1421 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 1422 : {
		5000: 1423 : if (state->hand[player][i] == copper)
			branch  0 taken 80 % (fallthrough)
			branch  1 taken 20 %
			-: 1424 : {
			4000: 1425 : state->coins += 1;
			-: 1426 : }
		1000 : 1427 : else if (state->hand[player][i] == silver)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1428 : {
#####: 1429:	  state->coins += 2;
			-: 1430 : }
		1000 : 1431 : else if (state->hand[player][i] == gold)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1432 : {
#####: 1433:	  state->coins += 3;
			-: 1434 : }
		-: 1435 : }
	-: 1436 :
		-: 1437 :  //add bonus
		1000 : 1438 : state->coins += bonus;
	-: 1439 :
		1000 : 1440 : return 0;
	-: 1441 : }
-: 1442 :
	-: 1443 :
	-: 1444 ://end of dominion.c
	-: 1445 :




	_____****** Raw Testing Results for mailarw ******_____
	TESTING updateCoins() :
	All tests passed!
	File 'dominion.c'
	Lines executed : 16.08% of 566
	Branches executed : 15.75% of 419
	Taken at least once : 13.37% of 419
	Calls executed : 7.00% of 100
	Creating 'dominion.c.gcov'

	Testing getCost()All Tests Past!File 'dominion.c'
	Lines executed : 21.38% of 566
	Branches executed : 22.43% of 419
	Taken at least once : 20.05% of 419
	Calls executed : 7.00% of 100
	Creating 'dominion.c.gcov'

	TESTING isGameOver :
All tests passed!
File 'dominion.c'
Lines executed : 23.14% of 566
Branches executed : 24.34% of 419
Taken at least once : 21.96% of 419
Calls executed : 7.00% of 100
Creating 'dominion.c.gcov'

TESTING compare()
All test passed
File 'dominion.c'
Lines executed : 23.32% of 566
Branches executed : 24.34% of 419
Taken at least once : 22.20% of 419
Calls executed : 7.00% of 100
Creating 'dominion.c.gcov'

TESTING scoreFor()
Error on gardens!
Error on different size decks!
File 'dominion.c'
Lines executed : 29.15% of 566
Branches executed : 37.23% of 419
Taken at least once : 34.37% of 419
Calls executed : 10.00% of 100
Creating 'dominion.c.gcov'

TESTING smithy :
Error with hand count : Expected: 3.  Actual : 4
Error with deck count : Expected: 2.  Actual : 5
File 'dominion.c'
Lines executed : 33.92% of 566
Branches executed : 44.63% of 419
Taken at least once : 35.80% of 419
Calls executed : 14.00% of 100
Creating 'dominion.c.gcov'

TESTING adventurer :
Error with hand count : Expected: 6.  Actual : 7
Error with discard and deck count and played : Expected : 4.  Actual : 3
File 'dominion.c'
Lines executed : 36.22% of 566
Branches executed : 46.54% of 419
Taken at least once : 37.23% of 419
Calls executed : 17.00% of 100
Creating 'dominion.c.gcov'

TESTING Gardens :
Error with hand count : Expected: 4.  Actual : 5
Error with discard count and played card : Expected: 1.  Actual : 0
File 'dominion.c'
Lines executed : 36.40% of 566
Branches executed : 46.54% of 419
Taken at least once : 37.47% of 419
Calls executed : 17.00% of 100
Creating 'dominion.c.gcov'

TESTING Village :
Error with deck count : Expected: 4.  Actual : 5
Error with opponents deck : Expected: 10.  Actual : 9
File 'dominion.c'
Lines executed : 37.81% of 566
Branches executed : 46.54% of 419
Taken at least once : 37.95% of 419
Calls executed : 21.00% of 100
Creating 'dominion.c.gcov'

- : 0 : Source : dominion.c
- : 0 : Graph : dominion.gcno
- : 0 : Data : dominion.gcda
- : 0 : Runs : 9
- : 0 : Programs : 9
- : 1 : #include "dominion.h"
- : 2 : #include "dominion_helpers.h"
- : 3 : #include "rngs.h"
- : 4 : #include <stdio.h>
- : 5 : #include <math.h>
- : 6 : #include <stdlib.h>
- : 7 :
	function compare called 3757 returned 100 % blocks executed 100 %
	3757 : 8 : int compare(const void* a, const void* b) {
	3757:    9 : if (*(int*)a > *(int*)b)
		branch  0 taken 1 % (fallthrough)
		branch  1 taken 99 %
		3 : 10 : return 1;
	3754:   11 : if (*(int*)a < *(int*)b)
		branch  0 taken 27 % (fallthrough)
		branch  1 taken 73 %
		1003 : 12 : return -1;
	2751:   13 : return 0;
	-:   14 :
}
-:   15 :
	function newGame called 0 returned 0 % blocks executed 0 %
#####:   16:struct gameState* newGame() {
#####:   17:  struct gameState* g = malloc(sizeof(struct gameState));
#####:   18:  return g;
	-:   19 : }
-: 20 :
	function kingdomCards called 0 returned 0 % blocks executed 0 %
#####:   21:int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
	-:   22 : int k8, int k9, int k10) {
#####:   23:  int* k = malloc(10 * sizeof(int));
#####:   24:  k[0] = k1;
#####:   25:  k[1] = k2;
#####:   26:  k[2] = k3;
#####:   27:  k[3] = k4;
#####:   28:  k[4] = k5;
#####:   29:  k[5] = k6;
#####:   30:  k[6] = k7;
#####:   31:  k[7] = k8;
#####:   32:  k[8] = k9;
#####:   33:  k[9] = k10;
#####:   34:  return k;
	-:   35 :
}
-:   36 :
	function initializeGame called 125 returned 100 % blocks executed 88 %
	125 : 37 : int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
		-:   38 : struct gameState *state) {
	-:   39 :
		-: 40 : int i;
	-:   41 : int j;
	-:   42 : int it;
	-:   43 :  //set up random number generator
		125 : 44 : SelectStream(1);
	call    0 returned 100 %
		125:   45 : PutSeed((long)randomSeed);
	call    0 returned 100 %
		-:   46 :
		-: 47 :  //check number of players
		125 : 48 : if (numPlayers > MAX_PLAYERS || numPlayers < 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		branch  2 taken 0 % (fallthrough)
		branch  3 taken 100 %
		-: 49 : {
#####:   50:      return -1;
		-:   51 : }
	-: 52 :
		-: 53 :  //set number of players
		125 : 54 : state->numPlayers = numPlayers;
	-:   55 :
		-: 56 :  //check selected kingdom cards are different
		1375 : 57 : for (i = 0; i < 10; i++)
		branch  0 taken 91 %
		branch  1 taken 9 % (fallthrough)
		-: 58 : {
		13750:   59 : for (j = 0; j < 10; j++)
			branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			-: 60 : {
			12500:   61 : if (j != i && kingdomCards[j] == kingdomCards[i])
				branch  0 taken 90 % (fallthrough)
				branch  1 taken 10 %
				branch  2 taken 0 % (fallthrough)
				branch  3 taken 100 %
				-: 62 : {
#####:   63:	      return -1;
				-:   64 : }
			-: 65 : }
		-:   66 : }
	-:   67 :
		-: 68 :
		-: 69 :  //initialize supply
		-: 70 :  ///////////////////////////////
		-: 71 :
		-: 72 :  //set number of Curse cards
		125 : 73 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 74 : {
		125:   75 : state->supplyCount[curse] = 10;
		-:   76 : }
#####:   77:  else if (numPlayers == 3)
	branch  0 never executed
		branch  1 never executed
		- :   78 : {
#####:   79:      state->supplyCount[curse] = 20;
		-:   80 : }
	-: 81 : else
		- :   82 : {
#####:   83:      state->supplyCount[curse] = 30;
		-:   84 : }
	-: 85 :
		-: 86 :  //set number of Victory cards
		125 : 87 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 88 : {
		125:   89 : state->supplyCount[estate] = 8;
		125:   90 : state->supplyCount[duchy] = 8;
		125:   91 : state->supplyCount[province] = 8;
		-:   92 : }
	-: 93 : else
		- :   94 : {
#####:   95:      state->supplyCount[estate] = 12;
#####:   96:      state->supplyCount[duchy] = 12;
#####:   97:      state->supplyCount[province] = 12;
		-:   98 : }
	-: 99 :
		-: 100 :  //set number of Treasure cards
		125 : 101 : state->supplyCount[copper] = 60 - (7 * numPlayers);
	125:  102 : state->supplyCount[silver] = 40;
	125:  103 : state->supplyCount[gold] = 30;
	-:  104 :
		-: 105 :  //set number of Kingdom cards
		2625 : 106 : for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
		branch  0 taken 95 %
		branch  1 taken 5 % (fallthrough)
		-: 107 : {
		20625:  108 : for (j = 0; j < 10; j++)           		//loop chosen cards
			branch  0 taken 94 %
			branch  1 taken 6 % (fallthrough)
			-: 109 : {
			19375:  110 : if (kingdomCards[j] == i)
				branch  0 taken 6 % (fallthrough)
				branch  1 taken 94 %
				-: 111 : {
				-:  112 :	      //check if card is a 'Victory' Kingdom card
					1250 : 113 : if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
					branch  0 taken 90 % (fallthrough)
					branch  1 taken 10 %
					branch  2 taken 11 % (fallthrough)
					branch  3 taken 89 %
					-: 114 : {
					500:  115 : if (numPlayers == 2) {
						branch  0 taken 100 % (fallthrough)
							branch  1 taken 0 %
							250:  116 : state->supplyCount[i] = 8;
						-:  117 :
					}
#####:  118:		  else{ state->supplyCount[i] = 12; }
					-:  119 : }
				-:  120 : else
					- :  121 : {
					1000:  122 : state->supplyCount[i] = 10;
					-:  123 : }
				1250 : 124 : break;
				-:  125 : }
			-:  126 : else    //card is not in the set choosen for the game
				- :  127 : {
				18125:  128 : state->supplyCount[i] = -1;
				-:  129 : }
			-: 130 : }
		-:  131 :
			-: 132 : }
	-:  133 :
		-: 134 :  ////////////////////////
		-: 135 :  //supply intilization complete
		-: 136 :
		-: 137 :  //set player decks
		375 : 138 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 139 : {
		250:  140 : state->deckCount[i] = 0;
		1000:  141 : for (j = 0; j < 3; j++)
			branch  0 taken 75 %
			branch  1 taken 25 % (fallthrough)
			-: 142 : {
			750:  143 : state->deck[i][j] = estate;
			750:  144 : state->deckCount[i]++;
			-:  145 : }
		2000 : 146 : for (j = 3; j < 10; j++)
			branch  0 taken 88 %
			branch  1 taken 13 % (fallthrough)
			-: 147 : {
			1750:  148 : state->deck[i][j] = copper;
			1750:  149 : state->deckCount[i]++;
			-:  150 : }
		-: 151 : }
	-:  152 :
		-: 153 :  //shuffle player decks
		375 : 154 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 155 : {
		250:  156 : if (shuffle(i, state) < 0)
			call    0 returned 100 %
			branch  1 taken 0 % (fallthrough)
			branch  2 taken 100 %
			-: 157 : {
#####:  158:	  return -1;
			-:  159 : }
		-: 160 : }
	-:  161 :
		-: 162 :  //draw player hands
		375 : 163 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 164 : {
		-:  165 :      //initialize hand size to zero
			250 : 166 : state->handCount[i] = 0;
		250:  167 : state->discardCount[i] = 0;
		-:  168 :      //draw 5 cards
			-: 169 :      // for (j = 0; j < 5; j++)
			-: 170 :      //	{
			-: 171 :      //	  drawCard(i, state);
			-: 172 :      //	}
			-: 173 : }
	-:  174 :
		-: 175 :  //set embargo tokens to 0 for all supply piles
		3500 : 176 : for (i = 0; i <= treasure_map; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 177 : {
		3375:  178 : state->embargoTokens[i] = 0;
		-:  179 : }
	-: 180 :
		-: 181 :  //initialize first player's turn
		125 : 182 : state->outpostPlayed = 0;
	125:  183 : state->phase = 0;
	125:  184 : state->numActions = 1;
	125:  185 : state->numBuys = 1;
	125:  186 : state->playedCardCount = 0;
	125:  187 : state->whoseTurn = 0;
	125:  188 : state->handCount[state->whoseTurn] = 0;
	-:  189 :  //int it; move to top
		-: 190 :
		-: 191 :  //Moved draw cards to here, only drawing at the start of a turn
		750 : 192 : for (it = 0; it < 5; it++) {
		branch  0 taken 83 %
			branch  1 taken 17 % (fallthrough)
			625:  193 : drawCard(state->whoseTurn, state);
		call    0 returned 100 %
			-:  194 :
	}
	-:  195 :
		125 : 196 : updateCoins(state->whoseTurn, state, 0);
	call    0 returned 100 %
		-:  197 :
		125 : 198 : return 0;
	-:  199 :
}
-:  200 :
	function shuffle called 250 returned 100 % blocks executed 94 %
	250 : 201 : int shuffle(int player, struct gameState *state) {
	-:  202 :
		-: 203 :
		-: 204 : int newDeck[MAX_DECK];
	250:  205 : int newDeckPos = 0;
	-:  206 : int card;
	-:  207 : int i;
	-:  208 :
		250 : 209 : if (state->deckCount[player] < 1)
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
#####:  210:    return -1;
		250:  211 : qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
	call    0 returned 100 %
		-:  212 :  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
		-: 213 :
		3000 : 214 : while (state->deckCount[player] > 0) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			2500:  215 : card = floor(Random() * state->deckCount[player]);
		call    0 returned 100 %
			2500:  216 : newDeck[newDeckPos] = state->deck[player][card];
		2500:  217 : newDeckPos++;
		8750:  218 : for (i = card; i < state->deckCount[player] - 1; i++) {
			branch  0 taken 71 %
				branch  1 taken 29 % (fallthrough)
				6250:  219 : state->deck[player][i] = state->deck[player][i + 1];
			-:  220 :
		}
		2500:  221 : state->deckCount[player]--;
		-:  222 :
	}
	2750:  223 : for (i = 0; i < newDeckPos; i++) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			2500:  224 : state->deck[player][i] = newDeck[i];
		2500:  225 : state->deckCount[player]++;
		-:  226 :
	}
	-:  227 :
		250 : 228 : return 0;
	-:  229 :
}
-:  230 :
	function playCard called 0 returned 0 % blocks executed 0 %
#####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
	- : 232 : {
	-:  233 : int card;
#####:  234:  int coin_bonus = 0; 		//tracks coins gain from actions
	-:  235 :
		-: 236 :  //check if it is the right phase
#####:  237:  if (state->phase != 0)
		branch  0 never executed
		branch  1 never executed
		- : 238 : {
#####:  239:      return -1;
		-:  240 : }
	-: 241 :
		-: 242 :  //check if player has enough actions
#####:  243:  if ( state->numActions < 1 )
		branch  0 never executed
		branch  1 never executed
		- : 244 : {
#####:  245:      return -1;
		-:  246 : }
	-: 247 :
		-: 248 :  //get card played
#####:  249:  card = handCard(handPos, state);
		call    0 never executed
		- :  250 :
		-: 251 :  //check if selected card is an action
#####:  252:  if ( card < adventurer || card > treasure_map )
		branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 253 : {
#####:  254:      return -1;
		-:  255 : }
	-: 256 :
		-: 257 :  //play card
#####:  258:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 259 : {
#####:  260:      return -1;
		-:  261 : }
	-: 262 :
		-: 263 :  //reduce number of actions
#####:  264:  state->numActions--;
		-:  265 :
		-: 266 :  //update coins (Treasure cards may be added with card draws)
#####:  267:  updateCoins(state->whoseTurn, state, coin_bonus);
		call    0 never executed
		- :  268 :
#####:  269:  return 0;
		-:  270 : }
-:  271 :
	function buyCard called 0 returned 0 % blocks executed 0 %
#####:  272:int buyCard(int supplyPos, struct gameState *state) {
	-:  273 : int who;
-:  274 : if (DEBUG) {
	-:  275 : printf("Entering buyCard...\n");
	-:  276 :
}
-: 277 :
	-: 278 :  // I don't know what to do about the phase thing.
	-: 279 :
#####:  280:  who = state->whoseTurn;
	-:  281 :
#####:  282:  if (state->numBuys < 1){
	branch  0 never executed
	branch  1 never executed
	- :  283 : if (DEBUG)
	-: 284 : printf("You do not have any buys left\n");
#####:  285:    return -1;
#####:  286:  } else if (supplyCount(supplyPos, state) <1){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  287 : if (DEBUG)
-: 288 : printf("There are not any of that type of card left\n");
#####:  289:    return -1;
#####:  290:  } else if (state->coins < getCost(supplyPos)){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  291 : if (DEBUG)
-: 292 : printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
#####:  293:    return -1;
-:  294 : }
else {
#####:  295:    state->phase=1;
	-:  296 :    //state->supplyCount[supplyPos]--;
#####:  297:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
		call    0 never executed
		- :  298 :
#####:  299:    state->coins = (state->coins) - (getCost(supplyPos));
		call    0 never executed
#####:  300:    state->numBuys--;
		-:  301 : if (DEBUG)
		-: 302 : printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
	-:  303 :
}
-:  304 :
	-: 305 :  //state->discard[who][state->discardCount[who]] = supplyPos;
	-: 306 :  //state->discardCount[who]++;
	-: 307 :
#####:  308:  return 0;
	-:  309 : }
-:  310 :
	function numHandCards called 0 returned 0 % blocks executed 0 %
#####:  311:int numHandCards(struct gameState *state) {
#####:  312:  return state->handCount[ whoseTurn(state) ];
	call    0 never executed
	- :  313 : }
-: 314 :
	function handCard called 0 returned 0 % blocks executed 0 %
#####:  315:int handCard(int handPos, struct gameState *state) {
#####:  316:  int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  317:  return state->hand[currentPlayer][handPos];
	-:  318 : }
-: 319 :
	function supplyCount called 0 returned 0 % blocks executed 0 %
#####:  320:int supplyCount(int card, struct gameState *state) {
#####:  321:  return state->supplyCount[card];
	-:  322 : }
-: 323 :
	function fullDeckCount called 15 returned 100 % blocks executed 82 %
	15 : 324 : int fullDeckCount(int player, int card, struct gameState *state) {
	-:  325 : int i;
	15:  326 : int count = 0;
	-:  327 :
		90 : 328 : for (i = 0; i < state->deckCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 329 : {
		75:  330 : if (state->deck[player][i] == card) count++;
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-:  331 : }
	-: 332 :
		90 : 333 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 334 : {
		75:  335 : if (state->hand[player][i] == card) count++;
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-:  336 : }
	-: 337 :
		90 : 338 : for (i = 0; i < state->discardCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 339 : {
		75:  340 : if (state->discard[player][i] == card) count++;
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-:  341 : }
	-: 342 :
		15 : 343 : return count;
	-:  344 :
}
-:  345 :
	function whoseTurn called 7 returned 100 % blocks executed 100 %
	7 : 346 : int whoseTurn(struct gameState *state) {
	7:  347 : return state->whoseTurn;
	-:  348 :
}
-: 349 :
	function endTurn called 0 returned 0 % blocks executed 0 %
#####:  350:int endTurn(struct gameState *state) {
	-:  351 : int k;
-:  352 : int i;
#####:  353:  int currentPlayer = whoseTurn(state);
call    0 never executed
- :  354 :
	-: 355 :  //Discard hand
#####:  356:  for (i = 0; i < state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####:  357:    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
#####:  358:    state->hand[currentPlayer][i] = -1;//Set card to -1
	-:  359 : }
#####:  360:  state->handCount[currentPlayer] = 0;//Reset hand count
-:  361 :
	-: 362 :  //Code for determining the player
#####:  363:  if (currentPlayer < (state->numPlayers - 1)){ 
	branch  0 never executed
	branch  1 never executed
#####:  364:    state->whoseTurn = currentPlayer + 1;//Still safe to increment
	-:  365 : }
-: 366 : else {
#####:  367:    state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
	-:  368 :
}
-:  369 :
#####:  370:  state->outpostPlayed = 0;
#####:  371:  state->phase = 0;
#####:  372:  state->numActions = 1;
#####:  373:  state->coins = 0;
#####:  374:  state->numBuys = 1;
#####:  375:  state->playedCardCount = 0;
#####:  376:  state->handCount[state->whoseTurn] = 0;
	-:  377 :
	-: 378 :  //int k; move to top
	-: 379 :  //Next player draws hand
#####:  380:  for (k = 0; k < 5; k++){
	branch  0 never executed
	branch  1 never executed
#####:  381:    drawCard(state->whoseTurn, state);//Draw a card
	call    0 never executed
	- :  382 : }
-:  383 :
	-: 384 :  //Update money
#####:  385:  updateCoins(state->whoseTurn, state , 0);
	call    0 never executed
	- :  386 :
#####:  387:  return 0;
	-:  388 : }
-:  389 :
	function isGameOver called 7 returned 100 % blocks executed 100 %
	7 : 390 : int isGameOver(struct gameState *state) {
	-:  391 : int i;
	-:  392 : int j;
	-:  393 :
		-: 394 :  //if stack of Province cards is empty, the game ends
		7 : 395 : if (state->supplyCount[province] == 0)
		branch  0 taken 29 % (fallthrough)
		branch  1 taken 71 %
		-: 396 : {
		2:  397 : return 1;
		-:  398 : }
	-: 399 :
		-: 400 :  //if three supply pile are at 0, the game ends
		5 : 401 : j = 0;
	130:  402 : for (i = 0; i < 25; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 403 : {
		125:  404 : if (state->supplyCount[i] == 0)
			branch  0 taken 8 % (fallthrough)
			branch  1 taken 92 %
			-: 405 : {
			10:  406 : j++;
			-:  407 : }
		-: 408 : }
	5:  409 : if (j >= 3)
		branch  0 taken 40 % (fallthrough)
		branch  1 taken 60 %
		-: 410 : {
		2:  411 : return 1;
		-:  412 : }
	-: 413 :
		3 : 414 : return 0;
	-:  415 :
}
-:  416 :
	function scoreFor called 9 returned 100 % blocks executed 100 %
	9 : 417 : int scoreFor(int player, struct gameState *state) {
	-:  418 :
		-: 419 : int i;
	9:  420 : int score = 0;
	-:  421 :  //score from hand
		48 : 422 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 81 %
		branch  1 taken 19 % (fallthrough)
		-: 423 : {
		39:  424 : if (state->hand[player][i] == curse) { score = score - 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			39:  425 : if (state->hand[player][i] == estate) { score = score + 1; };
		branch  0 taken 23 % (fallthrough)
			branch  1 taken 77 %
			39:  426 : if (state->hand[player][i] == duchy) { score = score + 3; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			39:  427 : if (state->hand[player][i] == province) { score = score + 6; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			39:  428 : if (state->hand[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			39:  429 : if (state->hand[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			call    2 returned 100 %
			-:  430 : }
	-:  431 :
		-: 432 :  //score from discard
		49 : 433 : for (i = 0; i < state->discardCount[player]; i++)
		branch  0 taken 82 %
		branch  1 taken 18 % (fallthrough)
		-: 434 : {
		40:  435 : if (state->discard[player][i] == curse) { score = score - 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  436 : if (state->discard[player][i] == estate) { score = score + 1; };
		branch  0 taken 25 % (fallthrough)
			branch  1 taken 75 %
			40:  437 : if (state->discard[player][i] == duchy) { score = score + 3; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  438 : if (state->discard[player][i] == province) { score = score + 6; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  439 : if (state->discard[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  440 : if (state->discard[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			call    2 returned 100 %
			-:  441 : }
	-:  442 :
		-: 443 :  //score from deck
		49 : 444 : for (i = 0; i < state->discardCount[player]; i++)
		branch  0 taken 82 %
		branch  1 taken 18 % (fallthrough)
		-: 445 : {
		40:  446 : if (state->deck[player][i] == curse) { score = score - 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  447 : if (state->deck[player][i] == estate) { score = score + 1; };
		branch  0 taken 25 % (fallthrough)
			branch  1 taken 75 %
			40:  448 : if (state->deck[player][i] == duchy) { score = score + 3; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  449 : if (state->deck[player][i] == province) { score = score + 6; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  450 : if (state->deck[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			40:  451 : if (state->deck[player][i] == gardens) { score = score + (fullDeckCount(player, 0, state) / 10); };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			call    2 returned 100 %
			-:  452 : }
	-:  453 :
		9 : 454 : return score;
	-:  455 :
}
-:  456 :
	function getWinners called 0 returned 0 % blocks executed 0 %
#####:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
	-:  458 : int i;
-:  459 : int j;
-:  460 : int highScore;
-:  461 : int currentPlayer;
-:  462 :
	-: 463 :  //get score for each player
#####:  464:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 465 : {
	-:  466 :      //set unused player scores to -9999
#####:  467:      if (i >= state->numPlayers)
		branch  0 never executed
		branch  1 never executed
		- : 468 : {
#####:  469:	  players[i] = -9999;
		-:  470 : }
	-: 471 : else
		- :  472 : {
#####:  473:	  players[i] = scoreFor (i, state);
		call    0 never executed
			- :  474 : }
	-: 475 : }
-:  476 :
	-: 477 :  //find highest score
#####:  478:  j = 0;
#####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 480 : {
#####:  481:      if (players[i] > players[j])
	branch  0 never executed
		branch  1 never executed
		- : 482 : {
#####:  483:	  j = i;
		-:  484 : }
	-: 485 : }
#####:  486:  highScore = players[j];
-:  487 :
	-: 488 :  //add 1 to players who had less turns
#####:  489:  currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 491 : {
#####:  492:      if ( players[i] == highScore && i > currentPlayer )
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 493 : {
#####:  494:	  players[i]++;
		-:  495 : }
	-: 496 : }
-:  497 :
	-: 498 :  //find new highest score
#####:  499:  j = 0;
#####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 501 : {
#####:  502:      if ( players[i] > players[j] )
	branch  0 never executed
		branch  1 never executed
		- : 503 : {
#####:  504:	  j = i;
		-:  505 : }
	-: 506 : }
#####:  507:  highScore = players[j];
-:  508 :
	-: 509 :  //set winners in array to 1 and rest to 0
#####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 511 : {
#####:  512:      if ( players[i] == highScore )
	branch  0 never executed
		branch  1 never executed
		- : 513 : {
#####:  514:	  players[i] = 1;
		-:  515 : }
	-: 516 : else
		- :  517 : {
#####:  518:	  players[i] = 0;
		-:  519 : }
	-: 520 : }
-:  521 :
#####:  522:  return 0;
	-:  523 : }
-:  524 :
	function drawCard called 628 returned 100 % blocks executed 38 %
	628 : 525 : int drawCard(int player, struct gameState *state)
	- : 526 : {	int count;
-:  527 : int deckCounter;
628:  528 : if (state->deckCount[player] <= 0) {//Deck is empty
	branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-:  529 :
		-: 530 :    //Step 1 Shuffle the discard pile back into a deck
		-: 531 : int i;
	-:  532 :    //Move discard to deck
#####:  533:    for (i = 0; i < state->discardCount[player];i++){
		branch  0 never executed
		branch  1 never executed
#####:  534:      state->deck[player][i] = state->discard[player][i];
#####:  535:      state->discard[player][i] = -1;
		-:  536 : }
	-:  537 :
#####:  538:    state->deckCount[player] = state->discardCount[player];
#####:  539:    state->discardCount[player] = 0;//Reset discard
		-:  540 :
		-: 541 :    //Shufffle the deck
#####:  542:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
		call    0 never executed
		- :  543 :
		-: 544 : if (DEBUG) {//Debug statements
		-:  545 : printf("Deck count now: %d\n", state->deckCount[player]);
		-:  546 :
	}
	-: 547 :
#####:  548:    state->discardCount[player] = 0;
		-:  549 :
		-: 550 :    //Step 2 Draw Card
#####:  551:    count = state->handCount[player];//Get current player's hand count
		-:  552 :
		-: 553 : if (DEBUG) {//Debug statements
		-:  554 : printf("Current hand count: %d\n", count);
		-:  555 :
	}
	-: 556 :
#####:  557:    deckCounter = state->deckCount[player];//Create a holder for the deck count
		-:  558 :
#####:  559:    if (deckCounter == 0)
		branch  0 never executed
		branch  1 never executed
#####:  560:      return -1;
		-:  561 :
#####:  562:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
#####:  563:    state->deckCount[player]--;
#####:  564:    state->handCount[player]++;//Increment hand count
		-:  565 :
}
-:  566 :
	-: 567 : else {
	628:  568 : int count = state->handCount[player];//Get current hand count for player
	-:  569 : int deckCounter;
	-:  570 : if (DEBUG) {//Debug statements
		-:  571 : printf("Current hand count: %d\n", count);
		-:  572 :
	}
	-: 573 :
		628 : 574 : deckCounter = state->deckCount[player];//Create holder for the deck count
	628:  575 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
	628:  576 : state->deckCount[player]--;
	628:  577 : state->handCount[player]++;//Increment hand count
	-:  578 :
}
-:  579 :
	628 : 580 : return 0;
-:  581 : }
-:  582 :
	function getCost called 29 returned 100 % blocks executed 100 %
	29 : 583 : int getCost(int cardNumber)
	- : 584 : {
	29:  585 : switch (cardNumber)
		branch  0 taken 3 %
		branch  1 taken 3 %
		branch  2 taken 3 %
		branch  3 taken 3 %
		branch  4 taken 3 %
		branch  5 taken 3 %
		branch  6 taken 3 %
		branch  7 taken 3 %
		branch  8 taken 3 %
		branch  9 taken 3 %
		branch 10 taken 3 %
		branch 11 taken 3 %
		branch 12 taken 3 %
		branch 13 taken 3 %
		branch 14 taken 3 %
		branch 15 taken 3 %
		branch 16 taken 3 %
		branch 17 taken 3 %
		branch 18 taken 3 %
		branch 19 taken 3 %
		branch 20 taken 3 %
		branch 21 taken 3 %
		branch 22 taken 3 %
		branch 23 taken 3 %
		branch 24 taken 3 %
		branch 25 taken 3 %
		branch 26 taken 3 %
		branch 27 taken 7 %
		-:  586 : {
		-:  587 : case curse:
			1 : 588 : return 0;
			-:  589 : case estate:
				1 : 590 : return 2;
				-:  591 : case duchy:
					1 : 592 : return 5;
					-:  593 : case province:
						1 : 594 : return 8;
						-:  595 : case copper:
							1 : 596 : return 0;
							-:  597 : case silver:
								1 : 598 : return 3;
								-:  599 : case gold:
									1 : 600 : return 6;
									-:  601 : case adventurer:
										1 : 602 : return 6;
										-:  603 : case council_room:
											1 : 604 : return 5;
											-:  605 : case feast:
												1 : 606 : return 4;
												-:  607 : case gardens:
													1 : 608 : return 4;
													-:  609 : case mine:
														1 : 610 : return 5;
														-:  611 : case remodel:
															1 : 612 : return 4;
															-:  613 : case smithy:
																1 : 614 : return 4;
																-:  615 : case village:
																	1 : 616 : return 3;
																	-:  617 : case baron:
																		1 : 618 : return 4;
																		-:  619 : case great_hall:
																			1 : 620 : return 3;
																			-:  621 : case minion:
																				1 : 622 : return 5;
																				-:  623 : case steward:
																					1 : 624 : return 3;
																					-:  625 : case tribute:
																						1 : 626 : return 5;
																						-:  627 : case ambassador:
																							1 : 628 : return 3;
																							-:  629 : case cutpurse:
																								1 : 630 : return 4;
																								-:  631 : case embargo:
																									1 : 632 : return 2;
																									-:  633 : case outpost:
																										1 : 634 : return 5;
																										-:  635 : case salvager:
																											1 : 636 : return 4;
																											-:  637 : case sea_hag:
																												1 : 638 : return 4;
																												-:  639 : case treasure_map:
																													1 : 640 : return 4;
																													-:  641 : }
	-:  642 :
		2 : 643 : return -1;
	-:  644 : }
-:  645 :
	function cardEffect called 4 returned 100 % blocks executed 4 %
	4 : 646 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	- : 647 : {
	-:  648 : int i;
	-:  649 : int j;
	-:  650 : int k;
	-:  651 : int x;
	-:  652 : int index;
	4:  653 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		4:  654 : int nextPlayer = currentPlayer + 1;
	-:  655 :
		4 : 656 : int tributeRevealedCards[2] = { -1, -1 };
	-:  657 : int temphand[MAX_HAND];// moved above the if statement
	4:  658 : int drawntreasure = 0;
	-:  659 : int cardDrawn;
	4:  660 : int z = 0;// this is the counter for the temp hand
	4:  661 : if (nextPlayer > (state->numPlayers - 1)) {
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
#####:  662:    nextPlayer = 0;
			-:  663 :
	}
	-:  664 :
		-: 665 :
		-: 666 :  //uses switch to select card and perform actions
		4 : 667 : switch (card)
		branch  0 taken 25 %
		branch  1 taken 0 %
		branch  2 taken 0 %
		branch  3 taken 25 %
		branch  4 taken 0 %
		branch  5 taken 0 %
		branch  6 taken 25 %
		branch  7 taken 25 %
		branch  8 taken 0 %
		branch  9 taken 0 %
		branch 10 taken 0 %
		branch 11 taken 0 %
		branch 12 taken 0 %
		branch 13 taken 0 %
		branch 14 taken 0 %
		branch 15 taken 0 %
		branch 16 taken 0 %
		branch 17 taken 0 %
		branch 18 taken 0 %
		branch 19 taken 0 %
		branch 20 taken 0 %
		-:  668 : {
		-:  669 : case adventurer:
			1 : 670 : return playAdventurer(state);
			call    0 returned 100 %
				-:  671 :
				-: 672 : case council_room:
#####:  673:      return playCouncil_Room(state, handPos);
					call    0 never executed
						- :  674 :
						-: 675 :
						-: 676 : case feast:
#####:  677:      return playFeast(state, choice1);
							call    0 never executed
								- :  678 :
								-: 679 :
								-: 680 : case gardens:
									1 : 681 : return -1;
									-:  682 :
										-: 683 : case mine:
#####:  684:      j = state->hand[currentPlayer][choice1];  //store card we will trash
											-:  685 :
#####:  686:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 687 : {
#####:  688:	  return -1;
												-:  689 : }
											-: 690 :
#####:  691:      if (choice2 > treasure_map || choice2 < curse)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 692 : {
#####:  693:	  return -1;
												-:  694 : }
											-: 695 :
#####:  696:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
												call    0 never executed
												call    1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 697 : {
#####:  698:	  return -1;
												-:  699 : }
											-: 700 :
#####:  701:      gainCard(choice2, state, 2, currentPlayer);
												call    0 never executed
												- :  702 :
												-: 703 :      //discard card from hand
#####:  704:      discardCard(handPos, currentPlayer, state, 0);
												call    0 never executed
												- :  705 :
												-: 706 :      //discard trashed card
#####:  707:      for (i = 0; i < state->handCount[currentPlayer]; i++)
												branch  0 never executed
												branch  1 never executed
												- : 708 : {
#####:  709:	  if (state->hand[currentPlayer][i] == j)
												branch  0 never executed
													branch  1 never executed
													- : 710 : {
#####:  711:	      discardCard(i, currentPlayer, state, 0);			
													call    0 never executed
#####:  712:	      break;
														-:  713 : }
												-: 714 : }
											-:  715 :
#####:  716:      return 0;
												-:  717 :
												-: 718 : case remodel:
#####:  719:      j = state->hand[currentPlayer][choice1];  //store card we will trash
													-:  720 :
#####:  721:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
														call    0 never executed
														call    1 never executed
														branch  2 never executed
														branch  3 never executed
														- : 722 : {
#####:  723:	  return -1;
														-:  724 : }
													-: 725 :
#####:  726:      gainCard(choice2, state, 0, currentPlayer);
														call    0 never executed
														- :  727 :
														-: 728 :      //discard card from hand
#####:  729:      discardCard(handPos, currentPlayer, state, 0);
														call    0 never executed
														- :  730 :
														-: 731 :      //discard trashed card
#####:  732:      for (i = 0; i < state->handCount[currentPlayer]; i++)
														branch  0 never executed
														branch  1 never executed
														- : 733 : {
#####:  734:	  if (state->hand[currentPlayer][i] == j)
														branch  0 never executed
															branch  1 never executed
															- : 735 : {
#####:  736:	      discardCard(i, currentPlayer, state, 0);			
															call    0 never executed
#####:  737:	      break;
																-:  738 : }
														-: 739 : }
													-:  740 :
														-: 741 :
#####:  742:      return 0;
														-:  743 :
														-: 744 : case smithy:
															1 : 745 : return playSmithy(state, handPos);
															call    0 returned 100 %
																-:  746 :
																-: 747 : case village:
																	1 : 748 : return playVillage(state, handPos);
																	call    0 returned 100 %
																		-:  749 :
																		-: 750 : case baron:
#####:  751:      state->numBuys++;//Increase buys by 1!
#####:  752:      if (choice1 > 0){//Boolean true or going to discard an estate
																			branch  0 never executed
																				branch  1 never executed
#####:  753:	int p = 0;//Iterator for hand!
#####:  754:	int card_not_discarded = 1;//Flag for discard set!
#####:  755:	while(card_not_discarded){
																				branch  0 never executed
																				branch  1 never executed
#####:  756:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																				branch  0 never executed
																				branch  1 never executed
#####:  757:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  758:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  759:	    state->discardCount[currentPlayer]++;
#####:  760:	    for (;p < state->handCount[currentPlayer]; p++){
																				branch  0 never executed
																				branch  1 never executed
#####:  761:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																				-:  762 : }
#####:  763:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  764:	    state->handCount[currentPlayer]--;
#####:  765:	    card_not_discarded = 0;//Exit the loop
																				-:  766 : }
#####:  767:	  else if (p > state->handCount[currentPlayer]){
																				branch  0 never executed
																				branch  1 never executed
																				- :  768 : if (DEBUG) {
																				-:  769 : printf("No estate cards in your hand, invalid choice\n");
																				-:  770 : printf("Must gain an estate if there are any\n");
																				-:  771 :
																			}
#####:  772:	    if (supplyCount(estate, state) > 0){
																			call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  773:	      gainCard(estate, state, 0, currentPlayer);
																				call    0 never executed
#####:  774:	      state->supplyCount[estate]--;//Decrement estates
#####:  775:	      if (supplyCount(estate, state) == 0){
																				call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  776:		isGameOver(state);
																				call    0 never executed
																				- :  777 : }
																				-:  778 : }
#####:  779:	    card_not_discarded = 0;//Exit the loop
																				-:  780 : }
																			-:  781 :
																				-: 782 : else {
#####:  783:	    p++;//Next card
																				-:  784 :
																			}
																			-:  785 : }
																				-:  786 : }
																	-:  787 :
																		-: 788 : else {
#####:  789:	if (supplyCount(estate, state) > 0){
																		call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####:  790:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																			call    0 never executed
#####:  791:	  state->supplyCount[estate]--;//Decrement Estates
#####:  792:	  if (supplyCount(estate, state) == 0){
																			call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####:  793:	    isGameOver(state);
																			call    0 never executed
																			- :  794 : }
																			-:  795 : }
																	-:  796 :
																	}
																	-:  797 :
																		-: 798 :
#####:  799:      return 0;
																		-:  800 :
																		-: 801 : case great_hall:
																			-: 802 :      //+1 Card
#####:  803:      drawCard(currentPlayer, state);
																				call    0 never executed
																				- :  804 :
																				-: 805 :      //+1 Actions
#####:  806:      state->numActions++;
																				-:  807 :
																				-: 808 :      //discard card from hand
#####:  809:      discardCard(handPos, currentPlayer, state, 0);
																				call    0 never executed
#####:  810:      return 0;
																				-:  811 :
																				-: 812 : case minion:
																					-: 813 :      //+1 action
#####:  814:      state->numActions++;
																						-:  815 :
																						-: 816 :      //discard card from hand
#####:  817:      discardCard(handPos, currentPlayer, state, 0);
																						call    0 never executed
																						- :  818 :
#####:  819:      if (choice1)		//+2 coins
																						branch  0 never executed
																						branch  1 never executed
																						- : 820 : {
#####:  821:	  state->coins = state->coins + 2;
																						-:  822 : }
																					-: 823 :
#####:  824:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																						branch  0 never executed
																						branch  1 never executed
																						- :  825 : {
																						-:  826 :	  //discard hand
#####:  827:	  while(numHandCards(state) > 0)
																							call    0 never executed
																							branch  1 never executed
																							branch  2 never executed
																							- : 828 : {
#####:  829:	      discardCard(handPos, currentPlayer, state, 0);
																							call    0 never executed
																								- :  830 : }
																						-: 831 :
																							-: 832 :	  //draw 4
#####:  833:	  for (i = 0; i < 4; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 834 : {
#####:  835:	      drawCard(currentPlayer, state);
																							call    0 never executed
																								- :  836 : }
																						-: 837 :
																							-: 838 :	  //other players discard hand and redraw if hand size > 4
#####:  839:	  for (i = 0; i < state->numPlayers; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 840 : {
#####:  841:	      if (i != currentPlayer)
																							branch  0 never executed
																								branch  1 never executed
																								- : 842 : {
#####:  843:		  if ( state->handCount[i] > 4 )
																								branch  0 never executed
																									branch  1 never executed
																									- : 844 : {
																									-:  845 :		      //discard hand
#####:  846:		      while( state->handCount[i] > 0 )
																										branch  0 never executed
																										branch  1 never executed
																										- : 847 : {
#####:  848:			  discardCard(handPos, i, state, 0);
																										call    0 never executed
																											- :  849 : }
																									-: 850 :
																										-: 851 :		      //draw 4
#####:  852:		      for (j = 0; j < 4; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 853 : {
#####:  854:			  drawCard(i, state);
																										call    0 never executed
																											- :  855 : }
																									-: 856 : }
																								-:  857 : }
																							-:  858 : }
																						-:  859 :
																							-: 860 : }
#####:  861:      return 0;
																					-:  862 :
																						-: 863 : case steward:
#####:  864:      if (choice1 == 1)
																							branch  0 never executed
																								branch  1 never executed
																								- : 865 : {
																								-:  866 :	  //+2 cards
#####:  867:	  drawCard(currentPlayer, state);
																									call    0 never executed
#####:  868:	  drawCard(currentPlayer, state);
																									call    0 never executed
																									- :  869 : }
#####:  870:      else if (choice1 == 2)
																							branch  0 never executed
																								branch  1 never executed
																								- :  871 : {
																								-:  872 :	  //+2 coins
#####:  873:	  state->coins = state->coins + 2;
																									-:  874 : }
																							-: 875 : else
																								- :  876 : {
																								-:  877 :	  //trash 2 cards in hand
#####:  878:	  discardCard(choice2, currentPlayer, state, 1);
																									call    0 never executed
#####:  879:	  discardCard(choice3, currentPlayer, state, 1);
																									call    0 never executed
																									- :  880 : }
																							-:  881 :
																								-: 882 :      //discard card from hand
#####:  883:      discardCard(handPos, currentPlayer, state, 0);
																								call    0 never executed
#####:  884:      return 0;
																								-:  885 :
																								-: 886 : case tribute:
#####:  887:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																									branch  0 never executed
																										branch  1 never executed
#####:  888:	if (state->deckCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####:  889:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  890:	  state->deckCount[nextPlayer]--;
																										-:  891 : }
#####:  892:	else if (state->discardCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####:  893:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####:  894:	  state->discardCount[nextPlayer]--;
																										-:  895 : }
																									-:  896 : else {
																										-:  897 :	  //No Card to Reveal
																											-: 898 : if (DEBUG) {
																											-:  899 : printf("No cards to reveal\n");
																											-:  900 :
																										}
																										-: 901 :
																									}
																									-:  902 : }
																							-:  903 :
																								-: 904 : else {
#####:  905:	if (state->deckCount[nextPlayer] == 0){
																								branch  0 never executed
																									branch  1 never executed
#####:  906:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																									branch  0 never executed
																									branch  1 never executed
#####:  907:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####:  908:	    state->deckCount[nextPlayer]++;
#####:  909:	    state->discard[nextPlayer][i] = -1;
#####:  910:	    state->discardCount[nextPlayer]--;
																									-:  911 : }
																									-:  912 :
#####:  913:	  shuffle(nextPlayer,state);//Shuffle the deck
																									call    0 never executed
																									- :  914 : }
#####:  915:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  916:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####:  917:	state->deckCount[nextPlayer]--;
#####:  918:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  919:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####:  920:	state->deckCount[nextPlayer]--;
																							-:  921 :
																							}
																							-:  922 :
#####:  923:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																								branch  0 never executed
																								branch  1 never executed
#####:  924:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####:  925:	state->playedCardCount++;
#####:  926:	tributeRevealedCards[1] = -1;
																								-:  927 : }
																							-:  928 :
#####:  929:      for (i = 0; i <= 2; i ++){
																								branch  0 never executed
																								branch  1 never executed
#####:  930:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
#####:  931:	  state->coins += 2;
																								-:  932 : }
																								-:  933 :
#####:  934:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
																								branch  6 never executed
																								branch  7 never executed
																								branch  8 never executed
																								branch  9 never executed
#####:  935:	  drawCard(currentPlayer, state);
																								call    0 never executed
#####:  936:	  drawCard(currentPlayer, state);
																								call    0 never executed
																								- :  937 : }
																							-:  938 : else {//Action Card
#####:  939:	  state->numActions = state->numActions + 2;
																								-:  940 :
																							}
																							-:  941 : }
																							-:  942 :
#####:  943:      return 0;
																								-:  944 :
																								-: 945 : case ambassador:
#####:  946:      j = 0;		//used to check if player has enough cards to discard
																									-:  947 :
#####:  948:      if (choice2 > 2 || choice2 < 0)
																										branch  0 never executed
																										branch  1 never executed
																										branch  2 never executed
																										branch  3 never executed
																										- : 949 : {
#####:  950:	  return -1;				
																										-:  951 : }
																									-: 952 :
#####:  953:      if (choice1 == handPos)
																										branch  0 never executed
																										branch  1 never executed
																										- : 954 : {
#####:  955:	  return -1;
																										-:  956 : }
																									-: 957 :
#####:  958:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 959 : {
#####:  960:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																										branch  0 never executed
																											branch  1 never executed
																											branch  2 never executed
																											branch  3 never executed
																											branch  4 never executed
																											branch  5 never executed
																											- :  961 : {
#####:  962:	      j++;
																											-:  963 : }
																										-: 964 : }
#####:  965:      if (j < choice2)
																									branch  0 never executed
																										branch  1 never executed
																										- : 966 : {
#####:  967:	  return -1;				
																										-:  968 : }
																									-: 969 :
																										-: 970 : if (DEBUG)
																										-: 971 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																									-:  972 :
																										-: 973 :      //increase supply count for choosen card by amount being discarded
#####:  974:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																										-:  975 :
																										-: 976 :      //each other player gains a copy of revealed card
#####:  977:      for (i = 0; i < state->numPlayers; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 978 : {
#####:  979:	  if (i != currentPlayer)
																										branch  0 never executed
																											branch  1 never executed
																											- : 980 : {
#####:  981:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																											call    0 never executed
																												- :  982 : }
																										-: 983 : }
																									-:  984 :
																										-: 985 :      //discard played card from hand
#####:  986:      discardCard(handPos, currentPlayer, state, 0);			
																										call    0 never executed
																										- :  987 :
																										-: 988 :      //trash copies of cards returned to supply
#####:  989:      for (j = 0; j < choice2; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 990 : {
#####:  991:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																											branch  1 never executed
																											- : 992 : {
#####:  993:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																											branch  0 never executed
																												branch  1 never executed
																												- : 994 : {
#####:  995:		  discardCard(i, currentPlayer, state, 1);
																												call    0 never executed
#####:  996:		  break;
																													-:  997 : }
																											-: 998 : }
																										-:  999 : }
																									-: 1000 :
#####: 1001:      return 0;
																										-: 1002 :
																										-: 1003 : case cutpurse:
																											-: 1004 :
#####: 1005:      updateCoins(currentPlayer, state, 2);
																												call    0 never executed
#####: 1006:      for (i = 0; i < state->numPlayers; i++)
																												branch  0 never executed
																												branch  1 never executed
																												- : 1007 : {
#####: 1008:	  if (i != currentPlayer)
																												branch  0 never executed
																													branch  1 never executed
																													- : 1009 : {
#####: 1010:	      for (j = 0; j < state->handCount[i]; j++)
																													branch  0 never executed
																														branch  1 never executed
																														- : 1011 : {
#####: 1012:		  if (state->hand[i][j] == copper)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1013 : {
#####: 1014:		      discardCard(j, i, state, 0);
																															call    0 never executed
#####: 1015:		      break;
																																-: 1016 : }
#####: 1017:		  if (j == state->handCount[i])
																														branch  0 never executed
																															branch  1 never executed
																															- : 1018 : {
#####: 1019:		      for (k = 0; k < state->handCount[i]; k++)
																															branch  0 never executed
																																branch  1 never executed
																																- : 1020 : {
																																-: 1021 : if (DEBUG)
																																	-: 1022 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																-: 1023 : }
#####: 1024:		      break;
																															-: 1025 : }
																														-: 1026 : }
																													-: 1027 :
																														-: 1028 : }
																												-: 1029 :
																													-: 1030 : }
																											-: 1031 :
																												-: 1032 :      //discard played card from hand
#####: 1033:      discardCard(handPos, currentPlayer, state, 0);			
																												call    0 never executed
																												- : 1034 :
#####: 1035:      return 0;
																												-: 1036 :
																												-: 1037 :
																												-: 1038 : case embargo:
																													-: 1039 :      //+2 Coins
#####: 1040:      state->coins = state->coins + 2;
																														-: 1041 :
																														-: 1042 :      //see if selected pile is in play
#####: 1043:      if ( state->supplyCount[choice1] == -1 )
																														branch  0 never executed
																														branch  1 never executed
																														- : 1044 : {
#####: 1045:	  return -1;
																														-: 1046 : }
																													-: 1047 :
																														-: 1048 :      //add embargo token to selected supply pile
#####: 1049:      state->embargoTokens[choice1]++;
																														-: 1050 :
																														-: 1051 :      //trash card
#####: 1052:      discardCard(handPos, currentPlayer, state, 1);		
																														call    0 never executed
#####: 1053:      return 0;
																														-: 1054 :
																														-: 1055 : case outpost:
																															-: 1056 :      //set outpost flag
#####: 1057:      state->outpostPlayed++;
																																-: 1058 :
																																-: 1059 :      //discard card
#####: 1060:      discardCard(handPos, currentPlayer, state, 0);
																																call    0 never executed
#####: 1061:      return 0;
																																-: 1062 :
																																-: 1063 : case salvager:
																																	-: 1064 :      //+1 buy
#####: 1065:      state->numBuys++;
																																		-: 1066 :
#####: 1067:      if (choice1)
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 1068 : {
																																		-: 1069 :	  //gain coins equal to trashed card
#####: 1070:	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																			call    0 never executed
																																			call    1 never executed
																																			- : 1071 :	  //trash card
#####: 1072:	  discardCard(choice1, currentPlayer, state, 1);	
																																			call    0 never executed
																																			- : 1073 : }
																																	-: 1074 :
																																		-: 1075 :      //discard card
#####: 1076:      discardCard(handPos, currentPlayer, state, 0);
																																		call    0 never executed
#####: 1077:      return 0;
																																		-: 1078 :
																																		-: 1079 : case sea_hag:
#####: 1080:      for (i = 0; i < state->numPlayers; i++){
																																			branch  0 never executed
																																				branch  1 never executed
#####: 1081:	if (i != currentPlayer){
																																				branch  0 never executed
																																				branch  1 never executed
#####: 1082:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####: 1083:	  state->discardCount[i]++;
#####: 1084:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																				-: 1085 : }
																																				-: 1086 : }
#####: 1087:      return 0;
																																	-: 1088 :
																																		-: 1089 : case treasure_map:
																																			-: 1090 :      //search hand for another treasure_map
#####: 1091:      index = -1;
#####: 1092:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																				branch  0 never executed
																																				branch  1 never executed
																																				- : 1093 : {
#####: 1094:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																				branch  0 never executed
																																					branch  1 never executed
																																					branch  2 never executed
																																					branch  3 never executed
																																					- : 1095 : {
#####: 1096:	      index = i;
#####: 1097:	      break;
																																					-: 1098 : }
																																				-: 1099 : }
#####: 1100:      if (index > -1)
																																			branch  0 never executed
																																				branch  1 never executed
																																				- : 1101 : {
																																				-: 1102 :	  //trash both treasure cards
#####: 1103:	  discardCard(handPos, currentPlayer, state, 1);
																																					call    0 never executed
#####: 1104:	  discardCard(index, currentPlayer, state, 1);
																																					call    0 never executed
																																					- : 1105 :
																																					-: 1106 :	  //gain 4 Gold cards
#####: 1107:	  for (i = 0; i < 4; i++)
																																					branch  0 never executed
																																					branch  1 never executed
																																					- : 1108 : {
#####: 1109:	      gainCard(gold, state, 1, currentPlayer);
																																					call    0 never executed
																																						- : 1110 : }
																																				-: 1111 :
																																					-: 1112 :	  //return success
#####: 1113:	  return 1;
																																					-: 1114 : }
																																			-: 1115 :
																																				-: 1116 :      //no second treasure_map found in hand
#####: 1117:      return -1;
																																				-: 1118 : }
	-: 1119 :
#####: 1120:  return -1;
		-: 1121 : }
-: 1122 :
	function playAdventurer called 1 returned 100 % blocks executed 69 %
	1 : 1123 : int playAdventurer(struct gameState *state) {
	1: 1124 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		-: 1125 : int temphand[MAX_HAND];
	1: 1126 : int z = 0;
	1: 1127 : int drawntreasure = 0;
	-: 1128 : int cardDrawn;
	-: 1129 :
		-: 1130 :
		4 : 1131 : while (drawntreasure<2) {
		branch  0 taken 67 %
			branch  1 taken 33 % (fallthrough)
			2: 1132 : if (state->deckCount[currentPlayer] < 1) {//if the deck is empty we need to shuffle discard and add to deck
			branch  0 taken 0 % (fallthrough)
				branch  1 taken 100 %
#####: 1133:      shuffle(currentPlayer, state);
				call    0 never executed
				- : 1134 :
		}
		2: 1135 : drawCard(currentPlayer, state);
		call    0 returned 100 %
			2: 1136 : cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		2: 1137 : if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			branch  2 never executed
			branch  3 never executed
			branch  4 never executed
			branch  5 never executed
			2: 1138 : drawntreasure++;
		-: 1139 : else {
#####: 1140:      temphand[z]=cardDrawn;
#####: 1141:      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
#####: 1142:      z++;
			-: 1143 :
		}
		-: 1144 :
	}
	2: 1145 : while (z - 1 >= 0) {
		branch  0 taken 0 %
			branch  1 taken 100 % (fallthrough)
#####: 1146:    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
#####: 1147:    z=z-3;
			-: 1148 :
	}
	1: 1149 : return 0;
	-: 1150 :
}
-: 1151 :
	function playSmithy called 1 returned 100 % blocks executed 75 %
	1 : 1152 : int playSmithy(struct gameState *state, int handPos) {
	1: 1153 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		-: 1154 : int i;
	-: 1155 :  //draw three cards
		1 : 1156 : for (i; i < 3; i++)
		branch  0 taken 0 %
		branch  1 taken 100 % (fallthrough)
		-: 1157 : {
#####: 1158:	  drawCard(currentPlayer, state);
		call    0 never executed
			- : 1159 : }
	-: 1160 :
		-: 1161 :      //discard card from hand
		1 : 1162 : discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100 %
		1: 1163 : return 0;
	-: 1164 :
}
-: 1165 :
	function playVillage called 1 returned 100 % blocks executed 100 %
	1 : 1166 : int playVillage(struct gameState *state, int handPos) {
	1: 1167 : int currentPlayer = whoseTurn(state) + 1;
	call    0 returned 100 %
		-: 1168 :      //+1 Card
		1 : 1169 : drawCard(currentPlayer, state);
	call    0 returned 100 %
		-: 1170 :
		-: 1171 :      //+2 Actions
		1 : 1172 : state->numActions = state->numActions + 2;
	-: 1173 :
		-: 1174 :      //discard played card from hand
		1 : 1175 : discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100 %
		1: 1176 : return 0;
	-: 1177 :
}
-: 1178 :
	function playFeast called 0 returned 0 % blocks executed 0 %
#####: 1179:int playFeast(struct gameState *state, int choice1){
#####: 1180:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1181 : int temphand[MAX_HAND];
-: 1182 : int i;
-: 1183 : int x;
-: 1184 :    //gain card with cost up to 5
	-: 1185 :      //Backup hand
#####: 1186:  for (i = 0; i <= state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####: 1187:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####: 1188:	state->hand[currentPlayer][i] = -1;//Set to nothing
	-: 1189 : }
-: 1190 :      //Backup hand
	-: 1191 :
	-: 1192 :      //Update Coins for Buy
#####: 1193:      updateCoins(currentPlayer, state, 5);
	call    0 never executed
#####: 1194:      x = 1;//Condition to loop on
#####: 1195:  while( x == 1) {//Buy one card
	branch  0 never executed
	branch  1 never executed
#####: 1196:    if (supplyCount(choice1, state) <= 0){
	call    0 never executed
	branch  1 never executed
	branch  2 never executed
	- : 1197 : if (DEBUG)
	-: 1198 : printf("None of that card left, sorry!\n");
-: 1199 :
	-: 1200 : if (DEBUG) {
	-: 1201 : printf("Cards Left: %d\n", supplyCount(choice1, state));
	-: 1202 :
}
-: 1203 : }
#####: 1204:    else if (state->coins < getCost(choice1)){
	call    0 never executed
	branch  1 never executed
	branch  2 never executed
#####: 1205:      printf("That card is too expensive!\n");
	call    0 never executed
	- : 1206 :
	-: 1207 : if (DEBUG) {
	-: 1208 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
	-: 1209 :
}
-: 1210 : }
-: 1211 : else {
	-: 1212 :
		-: 1213 : if (DEBUG) {
		-: 1214 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
		-: 1215 :
	}
	-: 1216 :
		-: 1217 :
#####: 1218:      for(i = 0; i < 5; i++){
		branch  0 never executed
		branch  1 never executed
#####: 1219:      gainCard(choice1, state, 0, currentPlayer);//Gain the card
		call    0 never executed
		- : 1220 : }
#####: 1221:      x = 0;//No more buying cards
	-: 1222 :
		-: 1223 : if (DEBUG) {
		-: 1224 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
		-: 1225 :
	}
	-: 1226 :
		-: 1227 :
}
-: 1228 : }
-: 1229 :
	-: 1230 :      //Reset Hand
#####: 1231:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####: 1232:	state->hand[currentPlayer][i] = temphand[i];
#####: 1233:	temphand[i] = -1;
	-: 1234 : }
-: 1235 :      //Reset Hand
	-: 1236 :
#####: 1237:      return 0;
	-: 1238 :
	-: 1239 : };
-: 1240 :
	function playCouncil_Room called 0 returned 0 % blocks executed 0 %
#####: 1241:int playCouncil_Room(struct gameState *state, int handPos){
#####: 1242:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1243 : int i;
-: 1244 :  //+4 Cards
#####: 1245:  for (i = 0; i < 4; i++)
	branch  0 never executed
	branch  1 never executed
	- : 1246 : {
#####: 1247:	  drawCard(currentPlayer, state);
	call    0 never executed
		- : 1248 : }
-: 1249 :
	-: 1250 :      //+1 Buy
#####: 1251:      state->numBuys++;
	-: 1252 :
	-: 1253 :      //Each other player draws a card
#####: 1254:      for (i = 0; i < state->numPlayers; i++)
	branch  0 never executed
	branch  1 never executed
	- : 1255 : {
#####: 1256:	  if ( i != currentPlayer )
	branch  0 never executed
		branch  1 never executed
		- : 1257 : {
#####: 1258:	      drawCard(i, state);
		call    0 never executed
			- : 1259 : }
	-: 1260 : }
-: 1261 :
	-: 1262 :      //put played card in played card pile
#####: 1263:      discardCard(handPos, currentPlayer, state, 0);
	call    0 never executed
	- : 1264 :
#####: 1265:      return 0;
	-: 1266 :
	-: 1267 :
	-: 1268 : }
-: 1269 :
	function discardCard called 2 returned 100 % blocks executed 89 %
	2 : 1270 : int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	- : 1271 : {
	-: 1272 :
		-: 1273 :  //if card is not trashed, added to Played pile 
		2 : 1274 : if (trashFlag < 1)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 1275 : {
		-: 1276 :      //add card to played pile
			2 : 1277 : state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
		2: 1278 : state->playedCardCount++;
		-: 1279 : }
	-: 1280 :
		-: 1281 :  //set played card to -1
		2 : 1282 : state->hand[currentPlayer][handPos] = -1;
	-: 1283 :
		-: 1284 :  //remove card from player's hand
		2 : 1285 : if (handPos == (state->handCount[currentPlayer] - 1)) 	//last card in hand array is played
		branch  0 taken 50 % (fallthrough)
		branch  1 taken 50 %
		-: 1286 : {
		-: 1287 :      //reduce number of cards in hand
			1 : 1288 : state->handCount[currentPlayer]--;
		-: 1289 : }
	1 : 1290 : else if (state->handCount[currentPlayer] == 1) //only one card in hand
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-: 1291 : {
		-: 1292 :      //reduce number of cards in hand
#####: 1293:      state->handCount[currentPlayer]--;
			-: 1294 : }
	-: 1295 : else
		- : 1296 : {
		-: 1297 :      //replace discarded card with last card in hand
			1 : 1298 : state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
		-: 1299 :      //set last card to -1
			1 : 1300 : state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
		-: 1301 :      //reduce number of cards in hand
			1 : 1302 : state->handCount[currentPlayer]--;
		-: 1303 : }
	-: 1304 :
		2 : 1305 : return 0;
	-: 1306 : }
-: 1307 :
	function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1308:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	- : 1309 : {
	-: 1310 :  //Note: supplyPos is enum of choosen card
		-: 1311 :
		-: 1312 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1313:  if ( supplyCount(supplyPos, state) < 1 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 1314 : {
#####: 1315:      return -1;
		-: 1316 : }
	-: 1317 :
		-: 1318 :  //added card for [whoseTurn] current player:
		-: 1319 :  // toFlag = 0 : add to discard
		-: 1320 :  // toFlag = 1 : add to deck
		-: 1321 :  // toFlag = 2 : add to hand
		-: 1322 :
#####: 1323:  if (toFlag == 1)
		branch  0 never executed
		branch  1 never executed
		- : 1324 : {
#####: 1325:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1326:      state->deckCount[player]++;
		-: 1327 : }
#####: 1328:  else if (toFlag == 2)
	branch  0 never executed
		branch  1 never executed
		- : 1329 : {
#####: 1330:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1331:      state->handCount[player]++;
		-: 1332 : }
	-: 1333 : else
		- : 1334 : {
#####: 1335:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1336:      state->discardCount[player]++;
		-: 1337 : }
	-: 1338 :
		-: 1339 :  //decrease number in supply pile
#####: 1340:  state->supplyCount[supplyPos]--;
		-: 1341 :
#####: 1342:  return 0;
		-: 1343 : }
-: 1344 :
	function updateCoins called 565 returned 100 % blocks executed 100 %
	565 : 1345 : int updateCoins(int player, struct gameState *state, int bonus)
	- : 1346 : {
	-: 1347 : int i;
	-: 1348 :
		-: 1349 :  //reset coin count
		565 : 1350 : state->coins = 0;
	-: 1351 :
		-: 1352 :  //add coins for each Treasure card in player's hand
		2510 : 1353 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 77 %
		branch  1 taken 23 % (fallthrough)
		-: 1354 : {
		1945: 1355 : if (state->hand[player][i] == copper)
			branch  0 taken 43 % (fallthrough)
			branch  1 taken 57 %
			-: 1356 : {
			830: 1357 : state->coins += 1;
			-: 1358 : }
		1115 : 1359 : else if (state->hand[player][i] == silver)
			branch  0 taken 30 % (fallthrough)
			branch  1 taken 70 %
			-: 1360 : {
			330: 1361 : state->coins += 2;
			-: 1362 : }
		785 : 1363 : else if (state->hand[player][i] == gold)
			branch  0 taken 42 % (fallthrough)
			branch  1 taken 58 %
			-: 1364 : {
			330: 1365 : state->coins += 3;
			-: 1366 : }
		-: 1367 : }
	-: 1368 :
		-: 1369 :  //add bonus
		565 : 1370 : state->coins += bonus;
	-: 1371 :
		565 : 1372 : return 0;
	-: 1373 : }
-: 1374 :
	-: 1375 :
	-: 1376 ://end of dominion.c
	-: 1377 :


	---- - VILLAGE RESULTS : ---- -
	In 1000 tests...
	Success : 0
	Error in Actions : 0
	Error in Buys : 0
	Error in Coins : 0
	Error in Hand Count : 0
	Error in Discard + Deck + Played Count : 1000
	Error in Supplies : 0
	Error in Opponents Deck : 1000
	Error in Opponents Discard : 0
	File 'dominion.c'
	Lines executed : 20.14% of 566
	Branches executed : 22.20% of 419
	Taken at least once : 13.84% of 419
	Calls executed : 12.00% of 100
	Creating 'dominion.c.gcov'

	- : 0 : Source : dominion.c
	- : 0 : Graph : dominion.gcno
	- : 0 : Data : dominion.gcda
	- : 0 : Runs : 1
	- : 0 : Programs : 1
	- : 1 : #include "dominion.h"
	- : 2 : #include "dominion_helpers.h"
	- : 3 : #include "rngs.h"
	- : 4 : #include <stdio.h>
	- : 5 : #include <math.h>
	- : 6 : #include <stdlib.h>
	- : 7 :
	function compare called 30000 returned 100 % blocks executed 83 %
	30000 : 8 : int compare(const void* a, const void* b) {
	30000:    9 : if (*(int*)a > *(int*)b)
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
#####:   10:    return 1;
		30000:   11 : if (*(int*)a < *(int*)b)
		branch  0 taken 27 % (fallthrough)
		branch  1 taken 73 %
		8000 : 12 : return -1;
	22000:   13 : return 0;
	-:   14 :
}
-:   15 :
	function newGame called 0 returned 0 % blocks executed 0 %
#####:   16:struct gameState* newGame() {
#####:   17:  struct gameState* g = malloc(sizeof(struct gameState));
#####:   18:  return g;
	-:   19 : }
-: 20 :
	function kingdomCards called 0 returned 0 % blocks executed 0 %
#####:   21:int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
	-:   22 : int k8, int k9, int k10) {
#####:   23:  int* k = malloc(10 * sizeof(int));
#####:   24:  k[0] = k1;
#####:   25:  k[1] = k2;
#####:   26:  k[2] = k3;
#####:   27:  k[3] = k4;
#####:   28:  k[4] = k5;
#####:   29:  k[5] = k6;
#####:   30:  k[6] = k7;
#####:   31:  k[7] = k8;
#####:   32:  k[8] = k9;
#####:   33:  k[9] = k10;
#####:   34:  return k;
	-:   35 :
}
-:   36 :
	function initializeGame called 1000 returned 100 % blocks executed 88 %
	1000 : 37 : int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
		-:   38 : struct gameState *state) {
	-:   39 :
		-: 40 : int i;
	-:   41 : int j;
	-:   42 : int it;
	-:   43 :  //set up random number generator
		1000 : 44 : SelectStream(1);
	call    0 returned 100 %
		1000:   45 : PutSeed((long)randomSeed);
	call    0 returned 100 %
		-:   46 :
		-: 47 :  //check number of players
		1000 : 48 : if (numPlayers > MAX_PLAYERS || numPlayers < 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		branch  2 taken 0 % (fallthrough)
		branch  3 taken 100 %
		-: 49 : {
#####:   50:      return -1;
		-:   51 : }
	-: 52 :
		-: 53 :  //set number of players
		1000 : 54 : state->numPlayers = numPlayers;
	-:   55 :
		-: 56 :  //check selected kingdom cards are different
		11000 : 57 : for (i = 0; i < 10; i++)
		branch  0 taken 91 %
		branch  1 taken 9 % (fallthrough)
		-: 58 : {
		110000:   59 : for (j = 0; j < 10; j++)
			branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			-: 60 : {
			100000:   61 : if (j != i && kingdomCards[j] == kingdomCards[i])
				branch  0 taken 90 % (fallthrough)
				branch  1 taken 10 %
				branch  2 taken 0 % (fallthrough)
				branch  3 taken 100 %
				-: 62 : {
#####:   63:	      return -1;
				-:   64 : }
			-: 65 : }
		-:   66 : }
	-:   67 :
		-: 68 :
		-: 69 :  //initialize supply
		-: 70 :  ///////////////////////////////
		-: 71 :
		-: 72 :  //set number of Curse cards
		1000 : 73 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 74 : {
		1000:   75 : state->supplyCount[curse] = 10;
		-:   76 : }
#####:   77:  else if (numPlayers == 3)
	branch  0 never executed
		branch  1 never executed
		- :   78 : {
#####:   79:      state->supplyCount[curse] = 20;
		-:   80 : }
	-: 81 : else
		- :   82 : {
#####:   83:      state->supplyCount[curse] = 30;
		-:   84 : }
	-: 85 :
		-: 86 :  //set number of Victory cards
		1000 : 87 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 88 : {
		1000:   89 : state->supplyCount[estate] = 8;
		1000:   90 : state->supplyCount[duchy] = 8;
		1000:   91 : state->supplyCount[province] = 8;
		-:   92 : }
	-: 93 : else
		- :   94 : {
#####:   95:      state->supplyCount[estate] = 12;
#####:   96:      state->supplyCount[duchy] = 12;
#####:   97:      state->supplyCount[province] = 12;
		-:   98 : }
	-: 99 :
		-: 100 :  //set number of Treasure cards
		1000 : 101 : state->supplyCount[copper] = 60 - (7 * numPlayers);
	1000:  102 : state->supplyCount[silver] = 40;
	1000:  103 : state->supplyCount[gold] = 30;
	-:  104 :
		-: 105 :  //set number of Kingdom cards
		21000 : 106 : for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
		branch  0 taken 95 %
		branch  1 taken 5 % (fallthrough)
		-: 107 : {
		165000:  108 : for (j = 0; j < 10; j++)           		//loop chosen cards
			branch  0 taken 94 %
			branch  1 taken 6 % (fallthrough)
			-: 109 : {
			155000:  110 : if (kingdomCards[j] == i)
				branch  0 taken 6 % (fallthrough)
				branch  1 taken 94 %
				-: 111 : {
				-:  112 :	      //check if card is a 'Victory' Kingdom card
					10000 : 113 : if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
					branch  0 taken 90 % (fallthrough)
					branch  1 taken 10 %
					branch  2 taken 11 % (fallthrough)
					branch  3 taken 89 %
					-: 114 : {
					4000:  115 : if (numPlayers == 2) {
						branch  0 taken 100 % (fallthrough)
							branch  1 taken 0 %
							2000:  116 : state->supplyCount[i] = 8;
						-:  117 :
					}
#####:  118:		  else{ state->supplyCount[i] = 12; }
					-:  119 : }
				-:  120 : else
					- :  121 : {
					8000:  122 : state->supplyCount[i] = 10;
					-:  123 : }
				10000 : 124 : break;
				-:  125 : }
			-:  126 : else    //card is not in the set choosen for the game
				- :  127 : {
				145000:  128 : state->supplyCount[i] = -1;
				-:  129 : }
			-: 130 : }
		-:  131 :
			-: 132 : }
	-:  133 :
		-: 134 :  ////////////////////////
		-: 135 :  //supply intilization complete
		-: 136 :
		-: 137 :  //set player decks
		3000 : 138 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 139 : {
		2000:  140 : state->deckCount[i] = 0;
		8000:  141 : for (j = 0; j < 3; j++)
			branch  0 taken 75 %
			branch  1 taken 25 % (fallthrough)
			-: 142 : {
			6000:  143 : state->deck[i][j] = estate;
			6000:  144 : state->deckCount[i]++;
			-:  145 : }
		16000 : 146 : for (j = 3; j < 10; j++)
			branch  0 taken 88 %
			branch  1 taken 13 % (fallthrough)
			-: 147 : {
			14000:  148 : state->deck[i][j] = copper;
			14000:  149 : state->deckCount[i]++;
			-:  150 : }
		-: 151 : }
	-:  152 :
		-: 153 :  //shuffle player decks
		3000 : 154 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 155 : {
		2000:  156 : if (shuffle(i, state) < 0)
			call    0 returned 100 %
			branch  1 taken 0 % (fallthrough)
			branch  2 taken 100 %
			-: 157 : {
#####:  158:	  return -1;
			-:  159 : }
		-: 160 : }
	-:  161 :
		-: 162 :  //draw player hands
		3000 : 163 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 164 : {
		-:  165 :      //initialize hand size to zero
			2000 : 166 : state->handCount[i] = 0;
		2000:  167 : state->discardCount[i] = 0;
		-:  168 :      //draw 5 cards
			-: 169 :      // for (j = 0; j < 5; j++)
			-: 170 :      //	{
			-: 171 :      //	  drawCard(i, state);
			-: 172 :      //	}
			-: 173 : }
	-:  174 :
		-: 175 :  //set embargo tokens to 0 for all supply piles
		28000 : 176 : for (i = 0; i <= treasure_map; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 177 : {
		27000:  178 : state->embargoTokens[i] = 0;
		-:  179 : }
	-: 180 :
		-: 181 :  //initialize first player's turn
		1000 : 182 : state->outpostPlayed = 0;
	1000:  183 : state->phase = 0;
	1000:  184 : state->numActions = 1;
	1000:  185 : state->numBuys = 1;
	1000:  186 : state->playedCardCount = 0;
	1000:  187 : state->whoseTurn = 0;
	1000:  188 : state->handCount[state->whoseTurn] = 0;
	-:  189 :  //int it; move to top
		-: 190 :
		-: 191 :  //Moved draw cards to here, only drawing at the start of a turn
		6000 : 192 : for (it = 0; it < 5; it++) {
		branch  0 taken 83 %
			branch  1 taken 17 % (fallthrough)
			5000:  193 : drawCard(state->whoseTurn, state);
		call    0 returned 100 %
			-:  194 :
	}
	-:  195 :
		1000 : 196 : updateCoins(state->whoseTurn, state, 0);
	call    0 returned 100 %
		-:  197 :
		1000 : 198 : return 0;
	-:  199 :
}
-:  200 :
	function shuffle called 2000 returned 100 % blocks executed 94 %
	2000 : 201 : int shuffle(int player, struct gameState *state) {
	-:  202 :
		-: 203 :
		-: 204 : int newDeck[MAX_DECK];
	2000:  205 : int newDeckPos = 0;
	-:  206 : int card;
	-:  207 : int i;
	-:  208 :
		2000 : 209 : if (state->deckCount[player] < 1)
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
#####:  210:    return -1;
		2000:  211 : qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
	call    0 returned 100 %
		-:  212 :  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
		-: 213 :
		24000 : 214 : while (state->deckCount[player] > 0) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			20000:  215 : card = floor(Random() * state->deckCount[player]);
		call    0 returned 100 %
			20000:  216 : newDeck[newDeckPos] = state->deck[player][card];
		20000:  217 : newDeckPos++;
		70000:  218 : for (i = card; i < state->deckCount[player] - 1; i++) {
			branch  0 taken 71 %
				branch  1 taken 29 % (fallthrough)
				50000:  219 : state->deck[player][i] = state->deck[player][i + 1];
			-:  220 :
		}
		20000:  221 : state->deckCount[player]--;
		-:  222 :
	}
	22000:  223 : for (i = 0; i < newDeckPos; i++) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			20000:  224 : state->deck[player][i] = newDeck[i];
		20000:  225 : state->deckCount[player]++;
		-:  226 :
	}
	-:  227 :
		2000 : 228 : return 0;
	-:  229 :
}
-:  230 :
	function playCard called 0 returned 0 % blocks executed 0 %
#####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
	- : 232 : {
	-:  233 : int card;
#####:  234:  int coin_bonus = 0; 		//tracks coins gain from actions
	-:  235 :
		-: 236 :  //check if it is the right phase
#####:  237:  if (state->phase != 0)
		branch  0 never executed
		branch  1 never executed
		- : 238 : {
#####:  239:      return -1;
		-:  240 : }
	-: 241 :
		-: 242 :  //check if player has enough actions
#####:  243:  if ( state->numActions < 1 )
		branch  0 never executed
		branch  1 never executed
		- : 244 : {
#####:  245:      return -1;
		-:  246 : }
	-: 247 :
		-: 248 :  //get card played
#####:  249:  card = handCard(handPos, state);
		call    0 never executed
		- :  250 :
		-: 251 :  //check if selected card is an action
#####:  252:  if ( card < adventurer || card > treasure_map )
		branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 253 : {
#####:  254:      return -1;
		-:  255 : }
	-: 256 :
		-: 257 :  //play card
#####:  258:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 259 : {
#####:  260:      return -1;
		-:  261 : }
	-: 262 :
		-: 263 :  //reduce number of actions
#####:  264:  state->numActions--;
		-:  265 :
		-: 266 :  //update coins (Treasure cards may be added with card draws)
#####:  267:  updateCoins(state->whoseTurn, state, coin_bonus);
		call    0 never executed
		- :  268 :
#####:  269:  return 0;
		-:  270 : }
-:  271 :
	function buyCard called 0 returned 0 % blocks executed 0 %
#####:  272:int buyCard(int supplyPos, struct gameState *state) {
	-:  273 : int who;
-:  274 : if (DEBUG) {
	-:  275 : printf("Entering buyCard...\n");
	-:  276 :
}
-: 277 :
	-: 278 :  // I don't know what to do about the phase thing.
	-: 279 :
#####:  280:  who = state->whoseTurn;
	-:  281 :
#####:  282:  if (state->numBuys < 1){
	branch  0 never executed
	branch  1 never executed
	- :  283 : if (DEBUG)
	-: 284 : printf("You do not have any buys left\n");
#####:  285:    return -1;
#####:  286:  } else if (supplyCount(supplyPos, state) <1){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  287 : if (DEBUG)
-: 288 : printf("There are not any of that type of card left\n");
#####:  289:    return -1;
#####:  290:  } else if (state->coins < getCost(supplyPos)){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  291 : if (DEBUG)
-: 292 : printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
#####:  293:    return -1;
-:  294 : }
else {
#####:  295:    state->phase=1;
	-:  296 :    //state->supplyCount[supplyPos]--;
#####:  297:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
		call    0 never executed
		- :  298 :
#####:  299:    state->coins = (state->coins) - (getCost(supplyPos));
		call    0 never executed
#####:  300:    state->numBuys--;
		-:  301 : if (DEBUG)
		-: 302 : printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
	-:  303 :
}
-:  304 :
	-: 305 :  //state->discard[who][state->discardCount[who]] = supplyPos;
	-: 306 :  //state->discardCount[who]++;
	-: 307 :
#####:  308:  return 0;
	-:  309 : }
-:  310 :
	function numHandCards called 0 returned 0 % blocks executed 0 %
#####:  311:int numHandCards(struct gameState *state) {
#####:  312:  return state->handCount[ whoseTurn(state) ];
	call    0 never executed
	- :  313 : }
-: 314 :
	function handCard called 0 returned 0 % blocks executed 0 %
#####:  315:int handCard(int handPos, struct gameState *state) {
#####:  316:  int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  317:  return state->hand[currentPlayer][handPos];
	-:  318 : }
-: 319 :
	function supplyCount called 0 returned 0 % blocks executed 0 %
#####:  320:int supplyCount(int card, struct gameState *state) {
#####:  321:  return state->supplyCount[card];
	-:  322 : }
-: 323 :
	function fullDeckCount called 0 returned 0 % blocks executed 0 %
#####:  324:int fullDeckCount(int player, int card, struct gameState *state) {
	-:  325 : int i;
#####:  326:  int count = 0;
-:  327 :
#####:  328:  for (i = 0; i < state->deckCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 329 : {
#####:  330:      if (state->deck[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  331 : }
-: 332 :
#####:  333:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 334 : {
#####:  335:      if (state->hand[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  336 : }
-: 337 :
#####:  338:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 339 : {
#####:  340:      if (state->discard[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  341 : }
-: 342 :
#####:  343:  return count;
	-:  344 : }
-:  345 :
	function whoseTurn called 2000 returned 100 % blocks executed 100 %
	2000 : 346 : int whoseTurn(struct gameState *state) {
	2000:  347 : return state->whoseTurn;
	-:  348 :
}
-: 349 :
	function endTurn called 0 returned 0 % blocks executed 0 %
#####:  350:int endTurn(struct gameState *state) {
	-:  351 : int k;
-:  352 : int i;
#####:  353:  int currentPlayer = whoseTurn(state);
call    0 never executed
- :  354 :
	-: 355 :  //Discard hand
#####:  356:  for (i = 0; i < state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####:  357:    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
#####:  358:    state->hand[currentPlayer][i] = -1;//Set card to -1
	-:  359 : }
#####:  360:  state->handCount[currentPlayer] = 0;//Reset hand count
-:  361 :
	-: 362 :  //Code for determining the player
#####:  363:  if (currentPlayer < (state->numPlayers - 1)){ 
	branch  0 never executed
	branch  1 never executed
#####:  364:    state->whoseTurn = currentPlayer + 1;//Still safe to increment
	-:  365 : }
-: 366 : else {
#####:  367:    state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
	-:  368 :
}
-:  369 :
#####:  370:  state->outpostPlayed = 0;
#####:  371:  state->phase = 0;
#####:  372:  state->numActions = 1;
#####:  373:  state->coins = 0;
#####:  374:  state->numBuys = 1;
#####:  375:  state->playedCardCount = 0;
#####:  376:  state->handCount[state->whoseTurn] = 0;
	-:  377 :
	-: 378 :  //int k; move to top
	-: 379 :  //Next player draws hand
#####:  380:  for (k = 0; k < 5; k++){
	branch  0 never executed
	branch  1 never executed
#####:  381:    drawCard(state->whoseTurn, state);//Draw a card
	call    0 never executed
	- :  382 : }
-:  383 :
	-: 384 :  //Update money
#####:  385:  updateCoins(state->whoseTurn, state , 0);
	call    0 never executed
	- :  386 :
#####:  387:  return 0;
	-:  388 : }
-:  389 :
	function isGameOver called 0 returned 0 % blocks executed 0 %
#####:  390:int isGameOver(struct gameState *state) {
	-:  391 : int i;
-:  392 : int j;
-:  393 :
	-: 394 :  //if stack of Province cards is empty, the game ends
#####:  395:  if (state->supplyCount[province] == 0)
	branch  0 never executed
	branch  1 never executed
	- : 396 : {
#####:  397:      return 1;
	-:  398 : }
-: 399 :
	-: 400 :  //if three supply pile are at 0, the game ends
#####:  401:  j = 0;
#####:  402:  for (i = 0; i < 25; i++)
	branch  0 never executed
	branch  1 never executed
	- : 403 : {
#####:  404:      if (state->supplyCount[i] == 0)
	branch  0 never executed
		branch  1 never executed
		- : 405 : {
#####:  406:	  j++;
		-:  407 : }
	-: 408 : }
#####:  409:  if ( j >= 3)
branch  0 never executed
branch  1 never executed
- : 410 : {
#####:  411:      return 1;
	-:  412 : }
-: 413 :
#####:  414:  return 0;
	-:  415 : }
-:  416 :
	function scoreFor called 0 returned 0 % blocks executed 0 %
#####:  417:int scoreFor (int player, struct gameState *state) {
	-:  418 :
	-: 419 : int i;
#####:  420:  int score = 0;
-:  421 :  //score from hand
#####:  422:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 423 : {
#####:  424:      if (state->hand[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  425:      if (state->hand[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  426:      if (state->hand[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  427:      if (state->hand[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  428:      if (state->hand[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  429:      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  430 : }
-:  431 :
	-: 432 :  //score from discard
#####:  433:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 434 : {
#####:  435:      if (state->discard[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  436:      if (state->discard[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  437:      if (state->discard[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  438:      if (state->discard[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  439:      if (state->discard[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  440:      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  441 : }
-:  442 :
	-: 443 :  //score from deck
#####:  444:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 445 : {
#####:  446:      if (state->deck[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  447:      if (state->deck[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  448:      if (state->deck[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  449:      if (state->deck[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  450:      if (state->deck[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  451:      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  452 : }
-:  453 :
#####:  454:  return score;
	-:  455 : }
-:  456 :
	function getWinners called 0 returned 0 % blocks executed 0 %
#####:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
	-:  458 : int i;
-:  459 : int j;
-:  460 : int highScore;
-:  461 : int currentPlayer;
-:  462 :
	-: 463 :  //get score for each player
#####:  464:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 465 : {
	-:  466 :      //set unused player scores to -9999
#####:  467:      if (i >= state->numPlayers)
		branch  0 never executed
		branch  1 never executed
		- : 468 : {
#####:  469:	  players[i] = -9999;
		-:  470 : }
	-: 471 : else
		- :  472 : {
#####:  473:	  players[i] = scoreFor (i, state);
		call    0 never executed
			- :  474 : }
	-: 475 : }
-:  476 :
	-: 477 :  //find highest score
#####:  478:  j = 0;
#####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 480 : {
#####:  481:      if (players[i] > players[j])
	branch  0 never executed
		branch  1 never executed
		- : 482 : {
#####:  483:	  j = i;
		-:  484 : }
	-: 485 : }
#####:  486:  highScore = players[j];
-:  487 :
	-: 488 :  //add 1 to players who had less turns
#####:  489:  currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 491 : {
#####:  492:      if ( players[i] == highScore && i > currentPlayer )
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 493 : {
#####:  494:	  players[i]++;
		-:  495 : }
	-: 496 : }
-:  497 :
	-: 498 :  //find new highest score
#####:  499:  j = 0;
#####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 501 : {
#####:  502:      if ( players[i] > players[j] )
	branch  0 never executed
		branch  1 never executed
		- : 503 : {
#####:  504:	  j = i;
		-:  505 : }
	-: 506 : }
#####:  507:  highScore = players[j];
-:  508 :
	-: 509 :  //set winners in array to 1 and rest to 0
#####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 511 : {
#####:  512:      if ( players[i] == highScore )
	branch  0 never executed
		branch  1 never executed
		- : 513 : {
#####:  514:	  players[i] = 1;
		-:  515 : }
	-: 516 : else
		- :  517 : {
#####:  518:	  players[i] = 0;
		-:  519 : }
	-: 520 : }
-:  521 :
#####:  522:  return 0;
	-:  523 : }
-:  524 :
	function drawCard called 6000 returned 100 % blocks executed 38 %
	6000 : 525 : int drawCard(int player, struct gameState *state)
	- : 526 : {	int count;
-:  527 : int deckCounter;
6000:  528 : if (state->deckCount[player] <= 0) {//Deck is empty
	branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-:  529 :
		-: 530 :    //Step 1 Shuffle the discard pile back into a deck
		-: 531 : int i;
	-:  532 :    //Move discard to deck
#####:  533:    for (i = 0; i < state->discardCount[player];i++){
		branch  0 never executed
		branch  1 never executed
#####:  534:      state->deck[player][i] = state->discard[player][i];
#####:  535:      state->discard[player][i] = -1;
		-:  536 : }
	-:  537 :
#####:  538:    state->deckCount[player] = state->discardCount[player];
#####:  539:    state->discardCount[player] = 0;//Reset discard
		-:  540 :
		-: 541 :    //Shufffle the deck
#####:  542:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
		call    0 never executed
		- :  543 :
		-: 544 : if (DEBUG) {//Debug statements
		-:  545 : printf("Deck count now: %d\n", state->deckCount[player]);
		-:  546 :
	}
	-: 547 :
#####:  548:    state->discardCount[player] = 0;
		-:  549 :
		-: 550 :    //Step 2 Draw Card
#####:  551:    count = state->handCount[player];//Get current player's hand count
		-:  552 :
		-: 553 : if (DEBUG) {//Debug statements
		-:  554 : printf("Current hand count: %d\n", count);
		-:  555 :
	}
	-: 556 :
#####:  557:    deckCounter = state->deckCount[player];//Create a holder for the deck count
		-:  558 :
#####:  559:    if (deckCounter == 0)
		branch  0 never executed
		branch  1 never executed
#####:  560:      return -1;
		-:  561 :
#####:  562:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
#####:  563:    state->deckCount[player]--;
#####:  564:    state->handCount[player]++;//Increment hand count
		-:  565 :
}
-:  566 :
	-: 567 : else {
	6000:  568 : int count = state->handCount[player];//Get current hand count for player
	-:  569 : int deckCounter;
	-:  570 : if (DEBUG) {//Debug statements
		-:  571 : printf("Current hand count: %d\n", count);
		-:  572 :
	}
	-: 573 :
		6000 : 574 : deckCounter = state->deckCount[player];//Create holder for the deck count
	6000:  575 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
	6000:  576 : state->deckCount[player]--;
	6000:  577 : state->handCount[player]++;//Increment hand count
	-:  578 :
}
-:  579 :
	6000 : 580 : return 0;
-:  581 : }
-:  582 :
	function getCost called 0 returned 0 % blocks executed 0 %
#####:  583:int getCost(int cardNumber)
	- : 584 : {
#####:  585:  switch( cardNumber ) 
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		branch  4 never executed
		branch  5 never executed
		branch  6 never executed
		branch  7 never executed
		branch  8 never executed
		branch  9 never executed
		branch 10 never executed
		branch 11 never executed
		branch 12 never executed
		branch 13 never executed
		branch 14 never executed
		branch 15 never executed
		branch 16 never executed
		branch 17 never executed
		branch 18 never executed
		branch 19 never executed
		branch 20 never executed
		branch 21 never executed
		branch 22 never executed
		branch 23 never executed
		branch 24 never executed
		branch 25 never executed
		branch 26 never executed
		branch 27 never executed
		- :  586 : {
		-:  587 : case curse:
#####:  588:      return 0;
			-:  589 : case estate:
#####:  590:      return 2;
				-:  591 : case duchy:
#####:  592:      return 5;
					-:  593 : case province:
#####:  594:      return 8;
						-:  595 : case copper:
#####:  596:      return 0;
							-:  597 : case silver:
#####:  598:      return 3;
								-:  599 : case gold:
#####:  600:      return 6;
									-:  601 : case adventurer:
#####:  602:      return 6;
										-:  603 : case council_room:
#####:  604:      return 5;
											-:  605 : case feast:
#####:  606:      return 4;
												-:  607 : case gardens:
#####:  608:      return 4;
													-:  609 : case mine:
#####:  610:      return 5;
														-:  611 : case remodel:
#####:  612:      return 4;
															-:  613 : case smithy:
#####:  614:      return 4;
																-:  615 : case village:
#####:  616:      return 3;
																	-:  617 : case baron:
#####:  618:      return 4;
																		-:  619 : case great_hall:
#####:  620:      return 3;
																			-:  621 : case minion:
#####:  622:      return 5;
																				-:  623 : case steward:
#####:  624:      return 3;
																					-:  625 : case tribute:
#####:  626:      return 5;
																						-:  627 : case ambassador:
#####:  628:      return 3;
																							-:  629 : case cutpurse:
#####:  630:      return 4;
																								-:  631 : case embargo:
#####:  632:      return 2;
																									-:  633 : case outpost:
#####:  634:      return 5;
																										-:  635 : case salvager:
#####:  636:      return 4;
																											-:  637 : case sea_hag:
#####:  638:      return 4;
																												-:  639 : case treasure_map:
#####:  640:      return 4;
																													-:  641 : }
	-:  642 :
#####:  643:  return -1;
		-:  644 : }
-:  645 :
	function cardEffect called 1000 returned 100 % blocks executed 3 %
	1000 : 646 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	- : 647 : {
	-:  648 : int i;
	-:  649 : int j;
	-:  650 : int k;
	-:  651 : int x;
	-:  652 : int index;
	1000:  653 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		1000:  654 : int nextPlayer = currentPlayer + 1;
	-:  655 :
		1000 : 656 : int tributeRevealedCards[2] = { -1, -1 };
	-:  657 : int temphand[MAX_HAND];// moved above the if statement
	1000:  658 : int drawntreasure = 0;
	-:  659 : int cardDrawn;
	1000:  660 : int z = 0;// this is the counter for the temp hand
	1000:  661 : if (nextPlayer > (state->numPlayers - 1)) {
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
#####:  662:    nextPlayer = 0;
			-:  663 :
	}
	-:  664 :
		-: 665 :
		-: 666 :  //uses switch to select card and perform actions
		1000 : 667 : switch (card)
		branch  0 taken 0 %
		branch  1 taken 0 %
		branch  2 taken 0 %
		branch  3 taken 0 %
		branch  4 taken 0 %
		branch  5 taken 0 %
		branch  6 taken 0 %
		branch  7 taken 100 %
		branch  8 taken 0 %
		branch  9 taken 0 %
		branch 10 taken 0 %
		branch 11 taken 0 %
		branch 12 taken 0 %
		branch 13 taken 0 %
		branch 14 taken 0 %
		branch 15 taken 0 %
		branch 16 taken 0 %
		branch 17 taken 0 %
		branch 18 taken 0 %
		branch 19 taken 0 %
		branch 20 taken 0 %
		-:  668 : {
		-:  669 : case adventurer:
#####:  670:      return playAdventurer(state);
			call    0 never executed
				- :  671 :
				-: 672 : case council_room:
#####:  673:      return playCouncil_Room(state, handPos);
					call    0 never executed
						- :  674 :
						-: 675 :
						-: 676 : case feast:
#####:  677:      return playFeast(state, choice1);
							call    0 never executed
								- :  678 :
								-: 679 :
								-: 680 : case gardens:
#####:  681:      return -1;
									-:  682 :
										-: 683 : case mine:
#####:  684:      j = state->hand[currentPlayer][choice1];  //store card we will trash
											-:  685 :
#####:  686:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 687 : {
#####:  688:	  return -1;
												-:  689 : }
											-: 690 :
#####:  691:      if (choice2 > treasure_map || choice2 < curse)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 692 : {
#####:  693:	  return -1;
												-:  694 : }
											-: 695 :
#####:  696:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
												call    0 never executed
												call    1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 697 : {
#####:  698:	  return -1;
												-:  699 : }
											-: 700 :
#####:  701:      gainCard(choice2, state, 2, currentPlayer);
												call    0 never executed
												- :  702 :
												-: 703 :      //discard card from hand
#####:  704:      discardCard(handPos, currentPlayer, state, 0);
												call    0 never executed
												- :  705 :
												-: 706 :      //discard trashed card
#####:  707:      for (i = 0; i < state->handCount[currentPlayer]; i++)
												branch  0 never executed
												branch  1 never executed
												- : 708 : {
#####:  709:	  if (state->hand[currentPlayer][i] == j)
												branch  0 never executed
													branch  1 never executed
													- : 710 : {
#####:  711:	      discardCard(i, currentPlayer, state, 0);			
													call    0 never executed
#####:  712:	      break;
														-:  713 : }
												-: 714 : }
											-:  715 :
#####:  716:      return 0;
												-:  717 :
												-: 718 : case remodel:
#####:  719:      j = state->hand[currentPlayer][choice1];  //store card we will trash
													-:  720 :
#####:  721:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
														call    0 never executed
														call    1 never executed
														branch  2 never executed
														branch  3 never executed
														- : 722 : {
#####:  723:	  return -1;
														-:  724 : }
													-: 725 :
#####:  726:      gainCard(choice2, state, 0, currentPlayer);
														call    0 never executed
														- :  727 :
														-: 728 :      //discard card from hand
#####:  729:      discardCard(handPos, currentPlayer, state, 0);
														call    0 never executed
														- :  730 :
														-: 731 :      //discard trashed card
#####:  732:      for (i = 0; i < state->handCount[currentPlayer]; i++)
														branch  0 never executed
														branch  1 never executed
														- : 733 : {
#####:  734:	  if (state->hand[currentPlayer][i] == j)
														branch  0 never executed
															branch  1 never executed
															- : 735 : {
#####:  736:	      discardCard(i, currentPlayer, state, 0);			
															call    0 never executed
#####:  737:	      break;
																-:  738 : }
														-: 739 : }
													-:  740 :
														-: 741 :
#####:  742:      return 0;
														-:  743 :
														-: 744 : case smithy:
#####:  745:      return playSmithy(state, handPos);
															call    0 never executed
																- :  746 :
																-: 747 : case village:
																	1000 : 748 : return playVillage(state, handPos);
																	call    0 returned 100 %
																		-:  749 :
																		-: 750 : case baron:
#####:  751:      state->numBuys++;//Increase buys by 1!
#####:  752:      if (choice1 > 0){//Boolean true or going to discard an estate
																			branch  0 never executed
																				branch  1 never executed
#####:  753:	int p = 0;//Iterator for hand!
#####:  754:	int card_not_discarded = 1;//Flag for discard set!
#####:  755:	while(card_not_discarded){
																				branch  0 never executed
																				branch  1 never executed
#####:  756:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																				branch  0 never executed
																				branch  1 never executed
#####:  757:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  758:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  759:	    state->discardCount[currentPlayer]++;
#####:  760:	    for (;p < state->handCount[currentPlayer]; p++){
																				branch  0 never executed
																				branch  1 never executed
#####:  761:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																				-:  762 : }
#####:  763:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  764:	    state->handCount[currentPlayer]--;
#####:  765:	    card_not_discarded = 0;//Exit the loop
																				-:  766 : }
#####:  767:	  else if (p > state->handCount[currentPlayer]){
																				branch  0 never executed
																				branch  1 never executed
																				- :  768 : if (DEBUG) {
																				-:  769 : printf("No estate cards in your hand, invalid choice\n");
																				-:  770 : printf("Must gain an estate if there are any\n");
																				-:  771 :
																			}
#####:  772:	    if (supplyCount(estate, state) > 0){
																			call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  773:	      gainCard(estate, state, 0, currentPlayer);
																				call    0 never executed
#####:  774:	      state->supplyCount[estate]--;//Decrement estates
#####:  775:	      if (supplyCount(estate, state) == 0){
																				call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  776:		isGameOver(state);
																				call    0 never executed
																				- :  777 : }
																				-:  778 : }
#####:  779:	    card_not_discarded = 0;//Exit the loop
																				-:  780 : }
																			-:  781 :
																				-: 782 : else {
#####:  783:	    p++;//Next card
																				-:  784 :
																			}
																			-:  785 : }
																				-:  786 : }
																	-:  787 :
																		-: 788 : else {
#####:  789:	if (supplyCount(estate, state) > 0){
																		call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####:  790:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																			call    0 never executed
#####:  791:	  state->supplyCount[estate]--;//Decrement Estates
#####:  792:	  if (supplyCount(estate, state) == 0){
																			call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####:  793:	    isGameOver(state);
																			call    0 never executed
																			- :  794 : }
																			-:  795 : }
																	-:  796 :
																	}
																	-:  797 :
																		-: 798 :
#####:  799:      return 0;
																		-:  800 :
																		-: 801 : case great_hall:
																			-: 802 :      //+1 Card
#####:  803:      drawCard(currentPlayer, state);
																				call    0 never executed
																				- :  804 :
																				-: 805 :      //+1 Actions
#####:  806:      state->numActions++;
																				-:  807 :
																				-: 808 :      //discard card from hand
#####:  809:      discardCard(handPos, currentPlayer, state, 0);
																				call    0 never executed
#####:  810:      return 0;
																				-:  811 :
																				-: 812 : case minion:
																					-: 813 :      //+1 action
#####:  814:      state->numActions++;
																						-:  815 :
																						-: 816 :      //discard card from hand
#####:  817:      discardCard(handPos, currentPlayer, state, 0);
																						call    0 never executed
																						- :  818 :
#####:  819:      if (choice1)		//+2 coins
																						branch  0 never executed
																						branch  1 never executed
																						- : 820 : {
#####:  821:	  state->coins = state->coins + 2;
																						-:  822 : }
																					-: 823 :
#####:  824:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																						branch  0 never executed
																						branch  1 never executed
																						- :  825 : {
																						-:  826 :	  //discard hand
#####:  827:	  while(numHandCards(state) > 0)
																							call    0 never executed
																							branch  1 never executed
																							branch  2 never executed
																							- : 828 : {
#####:  829:	      discardCard(handPos, currentPlayer, state, 0);
																							call    0 never executed
																								- :  830 : }
																						-: 831 :
																							-: 832 :	  //draw 4
#####:  833:	  for (i = 0; i < 4; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 834 : {
#####:  835:	      drawCard(currentPlayer, state);
																							call    0 never executed
																								- :  836 : }
																						-: 837 :
																							-: 838 :	  //other players discard hand and redraw if hand size > 4
#####:  839:	  for (i = 0; i < state->numPlayers; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 840 : {
#####:  841:	      if (i != currentPlayer)
																							branch  0 never executed
																								branch  1 never executed
																								- : 842 : {
#####:  843:		  if ( state->handCount[i] > 4 )
																								branch  0 never executed
																									branch  1 never executed
																									- : 844 : {
																									-:  845 :		      //discard hand
#####:  846:		      while( state->handCount[i] > 0 )
																										branch  0 never executed
																										branch  1 never executed
																										- : 847 : {
#####:  848:			  discardCard(handPos, i, state, 0);
																										call    0 never executed
																											- :  849 : }
																									-: 850 :
																										-: 851 :		      //draw 4
#####:  852:		      for (j = 0; j < 4; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 853 : {
#####:  854:			  drawCard(i, state);
																										call    0 never executed
																											- :  855 : }
																									-: 856 : }
																								-:  857 : }
																							-:  858 : }
																						-:  859 :
																							-: 860 : }
#####:  861:      return 0;
																					-:  862 :
																						-: 863 : case steward:
#####:  864:      if (choice1 == 1)
																							branch  0 never executed
																								branch  1 never executed
																								- : 865 : {
																								-:  866 :	  //+2 cards
#####:  867:	  drawCard(currentPlayer, state);
																									call    0 never executed
#####:  868:	  drawCard(currentPlayer, state);
																									call    0 never executed
																									- :  869 : }
#####:  870:      else if (choice1 == 2)
																							branch  0 never executed
																								branch  1 never executed
																								- :  871 : {
																								-:  872 :	  //+2 coins
#####:  873:	  state->coins = state->coins + 2;
																									-:  874 : }
																							-: 875 : else
																								- :  876 : {
																								-:  877 :	  //trash 2 cards in hand
#####:  878:	  discardCard(choice2, currentPlayer, state, 1);
																									call    0 never executed
#####:  879:	  discardCard(choice3, currentPlayer, state, 1);
																									call    0 never executed
																									- :  880 : }
																							-:  881 :
																								-: 882 :      //discard card from hand
#####:  883:      discardCard(handPos, currentPlayer, state, 0);
																								call    0 never executed
#####:  884:      return 0;
																								-:  885 :
																								-: 886 : case tribute:
#####:  887:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																									branch  0 never executed
																										branch  1 never executed
#####:  888:	if (state->deckCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####:  889:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  890:	  state->deckCount[nextPlayer]--;
																										-:  891 : }
#####:  892:	else if (state->discardCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####:  893:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####:  894:	  state->discardCount[nextPlayer]--;
																										-:  895 : }
																									-:  896 : else {
																										-:  897 :	  //No Card to Reveal
																											-: 898 : if (DEBUG) {
																											-:  899 : printf("No cards to reveal\n");
																											-:  900 :
																										}
																										-: 901 :
																									}
																									-:  902 : }
																							-:  903 :
																								-: 904 : else {
#####:  905:	if (state->deckCount[nextPlayer] == 0){
																								branch  0 never executed
																									branch  1 never executed
#####:  906:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																									branch  0 never executed
																									branch  1 never executed
#####:  907:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####:  908:	    state->deckCount[nextPlayer]++;
#####:  909:	    state->discard[nextPlayer][i] = -1;
#####:  910:	    state->discardCount[nextPlayer]--;
																									-:  911 : }
																									-:  912 :
#####:  913:	  shuffle(nextPlayer,state);//Shuffle the deck
																									call    0 never executed
																									- :  914 : }
#####:  915:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  916:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####:  917:	state->deckCount[nextPlayer]--;
#####:  918:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  919:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####:  920:	state->deckCount[nextPlayer]--;
																							-:  921 :
																							}
																							-:  922 :
#####:  923:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																								branch  0 never executed
																								branch  1 never executed
#####:  924:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####:  925:	state->playedCardCount++;
#####:  926:	tributeRevealedCards[1] = -1;
																								-:  927 : }
																							-:  928 :
#####:  929:      for (i = 0; i <= 2; i ++){
																								branch  0 never executed
																								branch  1 never executed
#####:  930:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
#####:  931:	  state->coins += 2;
																								-:  932 : }
																								-:  933 :
#####:  934:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
																								branch  6 never executed
																								branch  7 never executed
																								branch  8 never executed
																								branch  9 never executed
#####:  935:	  drawCard(currentPlayer, state);
																								call    0 never executed
#####:  936:	  drawCard(currentPlayer, state);
																								call    0 never executed
																								- :  937 : }
																							-:  938 : else {//Action Card
#####:  939:	  state->numActions = state->numActions + 2;
																								-:  940 :
																							}
																							-:  941 : }
																							-:  942 :
#####:  943:      return 0;
																								-:  944 :
																								-: 945 : case ambassador:
#####:  946:      j = 0;		//used to check if player has enough cards to discard
																									-:  947 :
#####:  948:      if (choice2 > 2 || choice2 < 0)
																										branch  0 never executed
																										branch  1 never executed
																										branch  2 never executed
																										branch  3 never executed
																										- : 949 : {
#####:  950:	  return -1;				
																										-:  951 : }
																									-: 952 :
#####:  953:      if (choice1 == handPos)
																										branch  0 never executed
																										branch  1 never executed
																										- : 954 : {
#####:  955:	  return -1;
																										-:  956 : }
																									-: 957 :
#####:  958:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 959 : {
#####:  960:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																										branch  0 never executed
																											branch  1 never executed
																											branch  2 never executed
																											branch  3 never executed
																											branch  4 never executed
																											branch  5 never executed
																											- :  961 : {
#####:  962:	      j++;
																											-:  963 : }
																										-: 964 : }
#####:  965:      if (j < choice2)
																									branch  0 never executed
																										branch  1 never executed
																										- : 966 : {
#####:  967:	  return -1;				
																										-:  968 : }
																									-: 969 :
																										-: 970 : if (DEBUG)
																										-: 971 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																									-:  972 :
																										-: 973 :      //increase supply count for choosen card by amount being discarded
#####:  974:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																										-:  975 :
																										-: 976 :      //each other player gains a copy of revealed card
#####:  977:      for (i = 0; i < state->numPlayers; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 978 : {
#####:  979:	  if (i != currentPlayer)
																										branch  0 never executed
																											branch  1 never executed
																											- : 980 : {
#####:  981:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																											call    0 never executed
																												- :  982 : }
																										-: 983 : }
																									-:  984 :
																										-: 985 :      //discard played card from hand
#####:  986:      discardCard(handPos, currentPlayer, state, 0);			
																										call    0 never executed
																										- :  987 :
																										-: 988 :      //trash copies of cards returned to supply
#####:  989:      for (j = 0; j < choice2; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 990 : {
#####:  991:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																											branch  1 never executed
																											- : 992 : {
#####:  993:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																											branch  0 never executed
																												branch  1 never executed
																												- : 994 : {
#####:  995:		  discardCard(i, currentPlayer, state, 1);
																												call    0 never executed
#####:  996:		  break;
																													-:  997 : }
																											-: 998 : }
																										-:  999 : }
																									-: 1000 :
#####: 1001:      return 0;
																										-: 1002 :
																										-: 1003 : case cutpurse:
																											-: 1004 :
#####: 1005:      updateCoins(currentPlayer, state, 2);
																												call    0 never executed
#####: 1006:      for (i = 0; i < state->numPlayers; i++)
																												branch  0 never executed
																												branch  1 never executed
																												- : 1007 : {
#####: 1008:	  if (i != currentPlayer)
																												branch  0 never executed
																													branch  1 never executed
																													- : 1009 : {
#####: 1010:	      for (j = 0; j < state->handCount[i]; j++)
																													branch  0 never executed
																														branch  1 never executed
																														- : 1011 : {
#####: 1012:		  if (state->hand[i][j] == copper)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1013 : {
#####: 1014:		      discardCard(j, i, state, 0);
																															call    0 never executed
#####: 1015:		      break;
																																-: 1016 : }
#####: 1017:		  if (j == state->handCount[i])
																														branch  0 never executed
																															branch  1 never executed
																															- : 1018 : {
#####: 1019:		      for (k = 0; k < state->handCount[i]; k++)
																															branch  0 never executed
																																branch  1 never executed
																																- : 1020 : {
																																-: 1021 : if (DEBUG)
																																	-: 1022 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																-: 1023 : }
#####: 1024:		      break;
																															-: 1025 : }
																														-: 1026 : }
																													-: 1027 :
																														-: 1028 : }
																												-: 1029 :
																													-: 1030 : }
																											-: 1031 :
																												-: 1032 :      //discard played card from hand
#####: 1033:      discardCard(handPos, currentPlayer, state, 0);			
																												call    0 never executed
																												- : 1034 :
#####: 1035:      return 0;
																												-: 1036 :
																												-: 1037 :
																												-: 1038 : case embargo:
																													-: 1039 :      //+2 Coins
#####: 1040:      state->coins = state->coins + 2;
																														-: 1041 :
																														-: 1042 :      //see if selected pile is in play
#####: 1043:      if ( state->supplyCount[choice1] == -1 )
																														branch  0 never executed
																														branch  1 never executed
																														- : 1044 : {
#####: 1045:	  return -1;
																														-: 1046 : }
																													-: 1047 :
																														-: 1048 :      //add embargo token to selected supply pile
#####: 1049:      state->embargoTokens[choice1]++;
																														-: 1050 :
																														-: 1051 :      //trash card
#####: 1052:      discardCard(handPos, currentPlayer, state, 1);		
																														call    0 never executed
#####: 1053:      return 0;
																														-: 1054 :
																														-: 1055 : case outpost:
																															-: 1056 :      //set outpost flag
#####: 1057:      state->outpostPlayed++;
																																-: 1058 :
																																-: 1059 :      //discard card
#####: 1060:      discardCard(handPos, currentPlayer, state, 0);
																																call    0 never executed
#####: 1061:      return 0;
																																-: 1062 :
																																-: 1063 : case salvager:
																																	-: 1064 :      //+1 buy
#####: 1065:      state->numBuys++;
																																		-: 1066 :
#####: 1067:      if (choice1)
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 1068 : {
																																		-: 1069 :	  //gain coins equal to trashed card
#####: 1070:	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																			call    0 never executed
																																			call    1 never executed
																																			- : 1071 :	  //trash card
#####: 1072:	  discardCard(choice1, currentPlayer, state, 1);	
																																			call    0 never executed
																																			- : 1073 : }
																																	-: 1074 :
																																		-: 1075 :      //discard card
#####: 1076:      discardCard(handPos, currentPlayer, state, 0);
																																		call    0 never executed
#####: 1077:      return 0;
																																		-: 1078 :
																																		-: 1079 : case sea_hag:
#####: 1080:      for (i = 0; i < state->numPlayers; i++){
																																			branch  0 never executed
																																				branch  1 never executed
#####: 1081:	if (i != currentPlayer){
																																				branch  0 never executed
																																				branch  1 never executed
#####: 1082:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####: 1083:	  state->discardCount[i]++;
#####: 1084:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																				-: 1085 : }
																																				-: 1086 : }
#####: 1087:      return 0;
																																	-: 1088 :
																																		-: 1089 : case treasure_map:
																																			-: 1090 :      //search hand for another treasure_map
#####: 1091:      index = -1;
#####: 1092:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																				branch  0 never executed
																																				branch  1 never executed
																																				- : 1093 : {
#####: 1094:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																				branch  0 never executed
																																					branch  1 never executed
																																					branch  2 never executed
																																					branch  3 never executed
																																					- : 1095 : {
#####: 1096:	      index = i;
#####: 1097:	      break;
																																					-: 1098 : }
																																				-: 1099 : }
#####: 1100:      if (index > -1)
																																			branch  0 never executed
																																				branch  1 never executed
																																				- : 1101 : {
																																				-: 1102 :	  //trash both treasure cards
#####: 1103:	  discardCard(handPos, currentPlayer, state, 1);
																																					call    0 never executed
#####: 1104:	  discardCard(index, currentPlayer, state, 1);
																																					call    0 never executed
																																					- : 1105 :
																																					-: 1106 :	  //gain 4 Gold cards
#####: 1107:	  for (i = 0; i < 4; i++)
																																					branch  0 never executed
																																					branch  1 never executed
																																					- : 1108 : {
#####: 1109:	      gainCard(gold, state, 1, currentPlayer);
																																					call    0 never executed
																																						- : 1110 : }
																																				-: 1111 :
																																					-: 1112 :	  //return success
#####: 1113:	  return 1;
																																					-: 1114 : }
																																			-: 1115 :
																																				-: 1116 :      //no second treasure_map found in hand
#####: 1117:      return -1;
																																				-: 1118 : }
	-: 1119 :
#####: 1120:  return -1;
		-: 1121 : }
-: 1122 :
	function playAdventurer called 0 returned 0 % blocks executed 0 %
#####: 1123:int playAdventurer(struct gameState *state){
#####: 1124:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1125 : int temphand[MAX_HAND];
#####: 1126:  int z = 0;
#####: 1127:  int drawntreasure = 0;
-: 1128 : int cardDrawn;
-: 1129 :
	-: 1130 :
#####: 1131:  while(drawntreasure<2){
	branch  0 never executed
	branch  1 never executed
#####: 1132:    if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
	branch  0 never executed
	branch  1 never executed
#####: 1133:      shuffle(currentPlayer, state);
	call    0 never executed
	- : 1134 : }
#####: 1135:    drawCard(currentPlayer, state);
	call    0 never executed
#####: 1136:    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
#####: 1137:    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	branch  0 never executed
	branch  1 never executed
	branch  2 never executed
	branch  3 never executed
	branch  4 never executed
	branch  5 never executed
#####: 1138:      drawntreasure++;
	-: 1139 : else {
#####: 1140:      temphand[z]=cardDrawn;
#####: 1141:      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
#####: 1142:      z++;
	-: 1143 :
}
-: 1144 : }
#####: 1145:  while(z-1>=0){
branch  0 never executed
branch  1 never executed
#####: 1146:    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
#####: 1147:    z=z-3;
-: 1148 : }
#####: 1149:  return 0;
-: 1150 : }
-: 1151 :
	function playSmithy called 0 returned 0 % blocks executed 0 %
#####: 1152:int playSmithy(struct gameState *state, int handPos){
#####: 1153:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1154 : int i;
-: 1155 :  //draw three cards
#####: 1156:  for (i; i < 3; i++)
	branch  0 never executed
	branch  1 never executed
	- : 1157 : {
#####: 1158:	  drawCard(currentPlayer, state);
	call    0 never executed
		- : 1159 : }
-: 1160 :
	-: 1161 :      //discard card from hand
#####: 1162:      discardCard(handPos, currentPlayer, state, 0);
	call    0 never executed
#####: 1163:      return 0;
	-: 1164 : }
-: 1165 :
	function playVillage called 1000 returned 100 % blocks executed 100 %
	1000 : 1166 : int playVillage(struct gameState *state, int handPos) {
	1000: 1167 : int currentPlayer = whoseTurn(state) + 1;
	call    0 returned 100 %
		-: 1168 :      //+1 Card
		1000 : 1169 : drawCard(currentPlayer, state);
	call    0 returned 100 %
		-: 1170 :
		-: 1171 :      //+2 Actions
		1000 : 1172 : state->numActions = state->numActions + 2;
	-: 1173 :
		-: 1174 :      //discard played card from hand
		1000 : 1175 : discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100 %
		1000: 1176 : return 0;
	-: 1177 :
}
-: 1178 :
	function playFeast called 0 returned 0 % blocks executed 0 %
#####: 1179:int playFeast(struct gameState *state, int choice1){
#####: 1180:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1181 : int temphand[MAX_HAND];
-: 1182 : int i;
-: 1183 : int x;
-: 1184 :    //gain card with cost up to 5
	-: 1185 :      //Backup hand
#####: 1186:  for (i = 0; i <= state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####: 1187:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####: 1188:	state->hand[currentPlayer][i] = -1;//Set to nothing
	-: 1189 : }
-: 1190 :      //Backup hand
	-: 1191 :
	-: 1192 :      //Update Coins for Buy
#####: 1193:      updateCoins(currentPlayer, state, 5);
	call    0 never executed
#####: 1194:      x = 1;//Condition to loop on
#####: 1195:  while( x == 1) {//Buy one card
	branch  0 never executed
	branch  1 never executed
#####: 1196:    if (supplyCount(choice1, state) <= 0){
	call    0 never executed
	branch  1 never executed
	branch  2 never executed
	- : 1197 : if (DEBUG)
	-: 1198 : printf("None of that card left, sorry!\n");
-: 1199 :
	-: 1200 : if (DEBUG) {
	-: 1201 : printf("Cards Left: %d\n", supplyCount(choice1, state));
	-: 1202 :
}
-: 1203 : }
#####: 1204:    else if (state->coins < getCost(choice1)){
	call    0 never executed
	branch  1 never executed
	branch  2 never executed
#####: 1205:      printf("That card is too expensive!\n");
	call    0 never executed
	- : 1206 :
	-: 1207 : if (DEBUG) {
	-: 1208 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
	-: 1209 :
}
-: 1210 : }
-: 1211 : else {
	-: 1212 :
		-: 1213 : if (DEBUG) {
		-: 1214 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
		-: 1215 :
	}
	-: 1216 :
		-: 1217 :
#####: 1218:      for(i = 0; i < 5; i++){
		branch  0 never executed
		branch  1 never executed
#####: 1219:      gainCard(choice1, state, 0, currentPlayer);//Gain the card
		call    0 never executed
		- : 1220 : }
#####: 1221:      x = 0;//No more buying cards
	-: 1222 :
		-: 1223 : if (DEBUG) {
		-: 1224 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
		-: 1225 :
	}
	-: 1226 :
		-: 1227 :
}
-: 1228 : }
-: 1229 :
	-: 1230 :      //Reset Hand
#####: 1231:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####: 1232:	state->hand[currentPlayer][i] = temphand[i];
#####: 1233:	temphand[i] = -1;
	-: 1234 : }
-: 1235 :      //Reset Hand
	-: 1236 :
#####: 1237:      return 0;
	-: 1238 :
	-: 1239 : };
-: 1240 :
	function playCouncil_Room called 0 returned 0 % blocks executed 0 %
#####: 1241:int playCouncil_Room(struct gameState *state, int handPos){
#####: 1242:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1243 : int i;
-: 1244 :  //+4 Cards
#####: 1245:  for (i = 0; i < 4; i++)
	branch  0 never executed
	branch  1 never executed
	- : 1246 : {
#####: 1247:	  drawCard(currentPlayer, state);
	call    0 never executed
		- : 1248 : }
-: 1249 :
	-: 1250 :      //+1 Buy
#####: 1251:      state->numBuys++;
	-: 1252 :
	-: 1253 :      //Each other player draws a card
#####: 1254:      for (i = 0; i < state->numPlayers; i++)
	branch  0 never executed
	branch  1 never executed
	- : 1255 : {
#####: 1256:	  if ( i != currentPlayer )
	branch  0 never executed
		branch  1 never executed
		- : 1257 : {
#####: 1258:	      drawCard(i, state);
		call    0 never executed
			- : 1259 : }
	-: 1260 : }
-: 1261 :
	-: 1262 :      //put played card in played card pile
#####: 1263:      discardCard(handPos, currentPlayer, state, 0);
	call    0 never executed
	- : 1264 :
#####: 1265:      return 0;
	-: 1266 :
	-: 1267 :
	-: 1268 : }
-: 1269 :
	function discardCard called 1000 returned 100 % blocks executed 67 %
	1000 : 1270 : int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	- : 1271 : {
	-: 1272 :
		-: 1273 :  //if card is not trashed, added to Played pile 
		1000 : 1274 : if (trashFlag < 1)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 1275 : {
		-: 1276 :      //add card to played pile
			1000 : 1277 : state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
		1000: 1278 : state->playedCardCount++;
		-: 1279 : }
	-: 1280 :
		-: 1281 :  //set played card to -1
		1000 : 1282 : state->hand[currentPlayer][handPos] = -1;
	-: 1283 :
		-: 1284 :  //remove card from player's hand
		1000 : 1285 : if (handPos == (state->handCount[currentPlayer] - 1)) 	//last card in hand array is played
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 1286 : {
		-: 1287 :      //reduce number of cards in hand
			1000 : 1288 : state->handCount[currentPlayer]--;
		-: 1289 : }
#####: 1290:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
	branch  0 never executed
		branch  1 never executed
		- : 1291 : {
		-: 1292 :      //reduce number of cards in hand
#####: 1293:      state->handCount[currentPlayer]--;
			-: 1294 : }
	-: 1295 : else
		- : 1296 : {
		-: 1297 :      //replace discarded card with last card in hand
#####: 1298:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
			-: 1299 :      //set last card to -1
#####: 1300:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
			-: 1301 :      //reduce number of cards in hand
#####: 1302:      state->handCount[currentPlayer]--;
			-: 1303 : }
	-: 1304 :
		1000 : 1305 : return 0;
	-: 1306 : }
-: 1307 :
	function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1308:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	- : 1309 : {
	-: 1310 :  //Note: supplyPos is enum of choosen card
		-: 1311 :
		-: 1312 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1313:  if ( supplyCount(supplyPos, state) < 1 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 1314 : {
#####: 1315:      return -1;
		-: 1316 : }
	-: 1317 :
		-: 1318 :  //added card for [whoseTurn] current player:
		-: 1319 :  // toFlag = 0 : add to discard
		-: 1320 :  // toFlag = 1 : add to deck
		-: 1321 :  // toFlag = 2 : add to hand
		-: 1322 :
#####: 1323:  if (toFlag == 1)
		branch  0 never executed
		branch  1 never executed
		- : 1324 : {
#####: 1325:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1326:      state->deckCount[player]++;
		-: 1327 : }
#####: 1328:  else if (toFlag == 2)
	branch  0 never executed
		branch  1 never executed
		- : 1329 : {
#####: 1330:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1331:      state->handCount[player]++;
		-: 1332 : }
	-: 1333 : else
		- : 1334 : {
#####: 1335:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1336:      state->discardCount[player]++;
		-: 1337 : }
	-: 1338 :
		-: 1339 :  //decrease number in supply pile
#####: 1340:  state->supplyCount[supplyPos]--;
		-: 1341 :
#####: 1342:  return 0;
		-: 1343 : }
-: 1344 :
	function updateCoins called 1000 returned 100 % blocks executed 82 %
	1000 : 1345 : int updateCoins(int player, struct gameState *state, int bonus)
	- : 1346 : {
	-: 1347 : int i;
	-: 1348 :
		-: 1349 :  //reset coin count
		1000 : 1350 : state->coins = 0;
	-: 1351 :
		-: 1352 :  //add coins for each Treasure card in player's hand
		6000 : 1353 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 1354 : {
		5000: 1355 : if (state->hand[player][i] == copper)
			branch  0 taken 80 % (fallthrough)
			branch  1 taken 20 %
			-: 1356 : {
			4000: 1357 : state->coins += 1;
			-: 1358 : }
		1000 : 1359 : else if (state->hand[player][i] == silver)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1360 : {
#####: 1361:	  state->coins += 2;
			-: 1362 : }
		1000 : 1363 : else if (state->hand[player][i] == gold)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1364 : {
#####: 1365:	  state->coins += 3;
			-: 1366 : }
		-: 1367 : }
	-: 1368 :
		-: 1369 :  //add bonus
		1000 : 1370 : state->coins += bonus;
	-: 1371 :
		1000 : 1372 : return 0;
	-: 1373 : }
-: 1374 :
	-: 1375 :
	-: 1376 ://end of dominion.c
	-: 1377 :


	---- - ADVENTURER RESULTS : ---- -
	In 1000 tests...
	Success : 0
	Error in Actions : 0
	Error in Buys : 0
	Error in Coins : 0
	Error in Hand Count : 1000
	Error in Discard + Deck + Played Count : 1000
	Error in Treasure Cards in Hand : 0
	Error in Treausre Cards in Discard + Deck + Played : 0
	Error in Supplies : 0
	Error in Opponents Deck : 0
	Error in Opponents Discard : 0
	File 'dominion.c'
	Lines executed : 23.50% of 566
	Branches executed : 25.06% of 419
	Taken at least once : 17.66% of 419
	Calls executed : 13.00% of 100
	Creating 'dominion.c.gcov'

	- : 0 : Source : dominion.c
	- : 0 : Graph : dominion.gcno
	- : 0 : Data : dominion.gcda
	- : 0 : Runs : 1
	- : 0 : Programs : 1
	- : 1 : #include "dominion.h"
	- : 2 : #include "dominion_helpers.h"
	- : 3 : #include "rngs.h"
	- : 4 : #include <stdio.h>
	- : 5 : #include <math.h>
	- : 6 : #include <stdlib.h>
	- : 7 :
	function compare called 71146 returned 100 % blocks executed 100 %
	71146 : 8 : int compare(const void* a, const void* b) {
	71146:    9 : if (*(int*)a > *(int*)b)
		branch  0 taken 29 % (fallthrough)
		branch  1 taken 71 %
		20894 : 10 : return 1;
	50252:   11 : if (*(int*)a < *(int*)b)
		branch  0 taken 41 % (fallthrough)
		branch  1 taken 59 %
		20436 : 12 : return -1;
	29816:   13 : return 0;
	-:   14 :
}
-:   15 :
	function newGame called 0 returned 0 % blocks executed 0 %
#####:   16:struct gameState* newGame() {
#####:   17:  struct gameState* g = malloc(sizeof(struct gameState));
#####:   18:  return g;
	-:   19 : }
-: 20 :
	function kingdomCards called 0 returned 0 % blocks executed 0 %
#####:   21:int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
	-:   22 : int k8, int k9, int k10) {
#####:   23:  int* k = malloc(10 * sizeof(int));
#####:   24:  k[0] = k1;
#####:   25:  k[1] = k2;
#####:   26:  k[2] = k3;
#####:   27:  k[3] = k4;
#####:   28:  k[4] = k5;
#####:   29:  k[5] = k6;
#####:   30:  k[6] = k7;
#####:   31:  k[7] = k8;
#####:   32:  k[8] = k9;
#####:   33:  k[9] = k10;
#####:   34:  return k;
	-:   35 :
}
-:   36 :
	function initializeGame called 1000 returned 100 % blocks executed 88 %
	1000 : 37 : int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
		-:   38 : struct gameState *state) {
	-:   39 :
		-: 40 : int i;
	-:   41 : int j;
	-:   42 : int it;
	-:   43 :  //set up random number generator
		1000 : 44 : SelectStream(1);
	call    0 returned 100 %
		1000:   45 : PutSeed((long)randomSeed);
	call    0 returned 100 %
		-:   46 :
		-: 47 :  //check number of players
		1000 : 48 : if (numPlayers > MAX_PLAYERS || numPlayers < 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		branch  2 taken 0 % (fallthrough)
		branch  3 taken 100 %
		-: 49 : {
#####:   50:      return -1;
		-:   51 : }
	-: 52 :
		-: 53 :  //set number of players
		1000 : 54 : state->numPlayers = numPlayers;
	-:   55 :
		-: 56 :  //check selected kingdom cards are different
		11000 : 57 : for (i = 0; i < 10; i++)
		branch  0 taken 91 %
		branch  1 taken 9 % (fallthrough)
		-: 58 : {
		110000:   59 : for (j = 0; j < 10; j++)
			branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			-: 60 : {
			100000:   61 : if (j != i && kingdomCards[j] == kingdomCards[i])
				branch  0 taken 90 % (fallthrough)
				branch  1 taken 10 %
				branch  2 taken 0 % (fallthrough)
				branch  3 taken 100 %
				-: 62 : {
#####:   63:	      return -1;
				-:   64 : }
			-: 65 : }
		-:   66 : }
	-:   67 :
		-: 68 :
		-: 69 :  //initialize supply
		-: 70 :  ///////////////////////////////
		-: 71 :
		-: 72 :  //set number of Curse cards
		1000 : 73 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 74 : {
		1000:   75 : state->supplyCount[curse] = 10;
		-:   76 : }
#####:   77:  else if (numPlayers == 3)
	branch  0 never executed
		branch  1 never executed
		- :   78 : {
#####:   79:      state->supplyCount[curse] = 20;
		-:   80 : }
	-: 81 : else
		- :   82 : {
#####:   83:      state->supplyCount[curse] = 30;
		-:   84 : }
	-: 85 :
		-: 86 :  //set number of Victory cards
		1000 : 87 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 88 : {
		1000:   89 : state->supplyCount[estate] = 8;
		1000:   90 : state->supplyCount[duchy] = 8;
		1000:   91 : state->supplyCount[province] = 8;
		-:   92 : }
	-: 93 : else
		- :   94 : {
#####:   95:      state->supplyCount[estate] = 12;
#####:   96:      state->supplyCount[duchy] = 12;
#####:   97:      state->supplyCount[province] = 12;
		-:   98 : }
	-: 99 :
		-: 100 :  //set number of Treasure cards
		1000 : 101 : state->supplyCount[copper] = 60 - (7 * numPlayers);
	1000:  102 : state->supplyCount[silver] = 40;
	1000:  103 : state->supplyCount[gold] = 30;
	-:  104 :
		-: 105 :  //set number of Kingdom cards
		21000 : 106 : for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
		branch  0 taken 95 %
		branch  1 taken 5 % (fallthrough)
		-: 107 : {
		165000:  108 : for (j = 0; j < 10; j++)           		//loop chosen cards
			branch  0 taken 94 %
			branch  1 taken 6 % (fallthrough)
			-: 109 : {
			155000:  110 : if (kingdomCards[j] == i)
				branch  0 taken 6 % (fallthrough)
				branch  1 taken 94 %
				-: 111 : {
				-:  112 :	      //check if card is a 'Victory' Kingdom card
					10000 : 113 : if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
					branch  0 taken 90 % (fallthrough)
					branch  1 taken 10 %
					branch  2 taken 11 % (fallthrough)
					branch  3 taken 89 %
					-: 114 : {
					4000:  115 : if (numPlayers == 2) {
						branch  0 taken 100 % (fallthrough)
							branch  1 taken 0 %
							2000:  116 : state->supplyCount[i] = 8;
						-:  117 :
					}
#####:  118:		  else{ state->supplyCount[i] = 12; }
					-:  119 : }
				-:  120 : else
					- :  121 : {
					8000:  122 : state->supplyCount[i] = 10;
					-:  123 : }
				10000 : 124 : break;
				-:  125 : }
			-:  126 : else    //card is not in the set choosen for the game
				- :  127 : {
				145000:  128 : state->supplyCount[i] = -1;
				-:  129 : }
			-: 130 : }
		-:  131 :
			-: 132 : }
	-:  133 :
		-: 134 :  ////////////////////////
		-: 135 :  //supply intilization complete
		-: 136 :
		-: 137 :  //set player decks
		3000 : 138 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 139 : {
		2000:  140 : state->deckCount[i] = 0;
		8000:  141 : for (j = 0; j < 3; j++)
			branch  0 taken 75 %
			branch  1 taken 25 % (fallthrough)
			-: 142 : {
			6000:  143 : state->deck[i][j] = estate;
			6000:  144 : state->deckCount[i]++;
			-:  145 : }
		16000 : 146 : for (j = 3; j < 10; j++)
			branch  0 taken 88 %
			branch  1 taken 13 % (fallthrough)
			-: 147 : {
			14000:  148 : state->deck[i][j] = copper;
			14000:  149 : state->deckCount[i]++;
			-:  150 : }
		-: 151 : }
	-:  152 :
		-: 153 :  //shuffle player decks
		3000 : 154 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 155 : {
		2000:  156 : if (shuffle(i, state) < 0)
			call    0 returned 100 %
			branch  1 taken 0 % (fallthrough)
			branch  2 taken 100 %
			-: 157 : {
#####:  158:	  return -1;
			-:  159 : }
		-: 160 : }
	-:  161 :
		-: 162 :  //draw player hands
		3000 : 163 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 164 : {
		-:  165 :      //initialize hand size to zero
			2000 : 166 : state->handCount[i] = 0;
		2000:  167 : state->discardCount[i] = 0;
		-:  168 :      //draw 5 cards
			-: 169 :      // for (j = 0; j < 5; j++)
			-: 170 :      //	{
			-: 171 :      //	  drawCard(i, state);
			-: 172 :      //	}
			-: 173 : }
	-:  174 :
		-: 175 :  //set embargo tokens to 0 for all supply piles
		28000 : 176 : for (i = 0; i <= treasure_map; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 177 : {
		27000:  178 : state->embargoTokens[i] = 0;
		-:  179 : }
	-: 180 :
		-: 181 :  //initialize first player's turn
		1000 : 182 : state->outpostPlayed = 0;
	1000:  183 : state->phase = 0;
	1000:  184 : state->numActions = 1;
	1000:  185 : state->numBuys = 1;
	1000:  186 : state->playedCardCount = 0;
	1000:  187 : state->whoseTurn = 0;
	1000:  188 : state->handCount[state->whoseTurn] = 0;
	-:  189 :  //int it; move to top
		-: 190 :
		-: 191 :  //Moved draw cards to here, only drawing at the start of a turn
		6000 : 192 : for (it = 0; it < 5; it++) {
		branch  0 taken 83 %
			branch  1 taken 17 % (fallthrough)
			5000:  193 : drawCard(state->whoseTurn, state);
		call    0 returned 100 %
			-:  194 :
	}
	-:  195 :
		1000 : 196 : updateCoins(state->whoseTurn, state, 0);
	call    0 returned 100 %
		-:  197 :
		1000 : 198 : return 0;
	-:  199 :
}
-:  200 :
	function shuffle called 2272 returned 100 % blocks executed 100 %
	2272 : 201 : int shuffle(int player, struct gameState *state) {
	-:  202 :
		-: 203 :
		-: 204 : int newDeck[MAX_DECK];
	2272:  205 : int newDeckPos = 0;
	-:  206 : int card;
	-:  207 : int i;
	-:  208 :
		2272 : 209 : if (state->deckCount[player] < 1)
		branch  0 taken 6 % (fallthrough)
		branch  1 taken 94 %
		136 : 210 : return -1;
	2136:  211 : qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
	call    0 returned 100 %
		-:  212 :  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
		-: 213 :
		32756 : 214 : while (state->deckCount[player] > 0) {
		branch  0 taken 93 %
			branch  1 taken 7 % (fallthrough)
			28484:  215 : card = floor(Random() * state->deckCount[player]);
		call    0 returned 100 %
			28484:  216 : newDeck[newDeckPos] = state->deck[player][card];
		28484:  217 : newDeckPos++;
		217483:  218 : for (i = card; i < state->deckCount[player] - 1; i++) {
			branch  0 taken 87 %
				branch  1 taken 13 % (fallthrough)
				188999:  219 : state->deck[player][i] = state->deck[player][i + 1];
			-:  220 :
		}
		28484:  221 : state->deckCount[player]--;
		-:  222 :
	}
	30620:  223 : for (i = 0; i < newDeckPos; i++) {
		branch  0 taken 93 %
			branch  1 taken 7 % (fallthrough)
			28484:  224 : state->deck[player][i] = newDeck[i];
		28484:  225 : state->deckCount[player]++;
		-:  226 :
	}
	-:  227 :
		2136 : 228 : return 0;
	-:  229 :
}
-:  230 :
	function playCard called 0 returned 0 % blocks executed 0 %
#####:  231:int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 
	- : 232 : {
	-:  233 : int card;
#####:  234:  int coin_bonus = 0; 		//tracks coins gain from actions
	-:  235 :
		-: 236 :  //check if it is the right phase
#####:  237:  if (state->phase != 0)
		branch  0 never executed
		branch  1 never executed
		- : 238 : {
#####:  239:      return -1;
		-:  240 : }
	-: 241 :
		-: 242 :  //check if player has enough actions
#####:  243:  if ( state->numActions < 1 )
		branch  0 never executed
		branch  1 never executed
		- : 244 : {
#####:  245:      return -1;
		-:  246 : }
	-: 247 :
		-: 248 :  //get card played
#####:  249:  card = handCard(handPos, state);
		call    0 never executed
		- :  250 :
		-: 251 :  //check if selected card is an action
#####:  252:  if ( card < adventurer || card > treasure_map )
		branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 253 : {
#####:  254:      return -1;
		-:  255 : }
	-: 256 :
		-: 257 :  //play card
#####:  258:  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 259 : {
#####:  260:      return -1;
		-:  261 : }
	-: 262 :
		-: 263 :  //reduce number of actions
#####:  264:  state->numActions--;
		-:  265 :
		-: 266 :  //update coins (Treasure cards may be added with card draws)
#####:  267:  updateCoins(state->whoseTurn, state, coin_bonus);
		call    0 never executed
		- :  268 :
#####:  269:  return 0;
		-:  270 : }
-:  271 :
	function buyCard called 0 returned 0 % blocks executed 0 %
#####:  272:int buyCard(int supplyPos, struct gameState *state) {
	-:  273 : int who;
-:  274 : if (DEBUG) {
	-:  275 : printf("Entering buyCard...\n");
	-:  276 :
}
-: 277 :
	-: 278 :  // I don't know what to do about the phase thing.
	-: 279 :
#####:  280:  who = state->whoseTurn;
	-:  281 :
#####:  282:  if (state->numBuys < 1){
	branch  0 never executed
	branch  1 never executed
	- :  283 : if (DEBUG)
	-: 284 : printf("You do not have any buys left\n");
#####:  285:    return -1;
#####:  286:  } else if (supplyCount(supplyPos, state) <1){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  287 : if (DEBUG)
-: 288 : printf("There are not any of that type of card left\n");
#####:  289:    return -1;
#####:  290:  } else if (state->coins < getCost(supplyPos)){
call    0 never executed
branch  1 never executed
branch  2 never executed
- :  291 : if (DEBUG)
-: 292 : printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
#####:  293:    return -1;
-:  294 : }
else {
#####:  295:    state->phase=1;
	-:  296 :    //state->supplyCount[supplyPos]--;
#####:  297:    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
		call    0 never executed
		- :  298 :
#####:  299:    state->coins = (state->coins) - (getCost(supplyPos));
		call    0 never executed
#####:  300:    state->numBuys--;
		-:  301 : if (DEBUG)
		-: 302 : printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
	-:  303 :
}
-:  304 :
	-: 305 :  //state->discard[who][state->discardCount[who]] = supplyPos;
	-: 306 :  //state->discardCount[who]++;
	-: 307 :
#####:  308:  return 0;
	-:  309 : }
-:  310 :
	function numHandCards called 0 returned 0 % blocks executed 0 %
#####:  311:int numHandCards(struct gameState *state) {
#####:  312:  return state->handCount[ whoseTurn(state) ];
	call    0 never executed
	- :  313 : }
-: 314 :
	function handCard called 0 returned 0 % blocks executed 0 %
#####:  315:int handCard(int handPos, struct gameState *state) {
#####:  316:  int currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  317:  return state->hand[currentPlayer][handPos];
	-:  318 : }
-: 319 :
	function supplyCount called 0 returned 0 % blocks executed 0 %
#####:  320:int supplyCount(int card, struct gameState *state) {
#####:  321:  return state->supplyCount[card];
	-:  322 : }
-: 323 :
	function fullDeckCount called 0 returned 0 % blocks executed 0 %
#####:  324:int fullDeckCount(int player, int card, struct gameState *state) {
	-:  325 : int i;
#####:  326:  int count = 0;
-:  327 :
#####:  328:  for (i = 0; i < state->deckCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 329 : {
#####:  330:      if (state->deck[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  331 : }
-: 332 :
#####:  333:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 334 : {
#####:  335:      if (state->hand[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  336 : }
-: 337 :
#####:  338:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 339 : {
#####:  340:      if (state->discard[player][i] == card) count++;
	branch  0 never executed
		branch  1 never executed
		- :  341 : }
-: 342 :
#####:  343:  return count;
	-:  344 : }
-:  345 :
	function whoseTurn called 2000 returned 100 % blocks executed 100 %
	2000 : 346 : int whoseTurn(struct gameState *state) {
	2000:  347 : return state->whoseTurn;
	-:  348 :
}
-: 349 :
	function endTurn called 0 returned 0 % blocks executed 0 %
#####:  350:int endTurn(struct gameState *state) {
	-:  351 : int k;
-:  352 : int i;
#####:  353:  int currentPlayer = whoseTurn(state);
call    0 never executed
- :  354 :
	-: 355 :  //Discard hand
#####:  356:  for (i = 0; i < state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####:  357:    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = state->hand[currentPlayer][i];//Discard
#####:  358:    state->hand[currentPlayer][i] = -1;//Set card to -1
	-:  359 : }
#####:  360:  state->handCount[currentPlayer] = 0;//Reset hand count
-:  361 :
	-: 362 :  //Code for determining the player
#####:  363:  if (currentPlayer < (state->numPlayers - 1)){ 
	branch  0 never executed
	branch  1 never executed
#####:  364:    state->whoseTurn = currentPlayer + 1;//Still safe to increment
	-:  365 : }
-: 366 : else {
#####:  367:    state->whoseTurn = 0;//Max player has been reached, loop back around to player 1
	-:  368 :
}
-:  369 :
#####:  370:  state->outpostPlayed = 0;
#####:  371:  state->phase = 0;
#####:  372:  state->numActions = 1;
#####:  373:  state->coins = 0;
#####:  374:  state->numBuys = 1;
#####:  375:  state->playedCardCount = 0;
#####:  376:  state->handCount[state->whoseTurn] = 0;
	-:  377 :
	-: 378 :  //int k; move to top
	-: 379 :  //Next player draws hand
#####:  380:  for (k = 0; k < 5; k++){
	branch  0 never executed
	branch  1 never executed
#####:  381:    drawCard(state->whoseTurn, state);//Draw a card
	call    0 never executed
	- :  382 : }
-:  383 :
	-: 384 :  //Update money
#####:  385:  updateCoins(state->whoseTurn, state , 0);
	call    0 never executed
	- :  386 :
#####:  387:  return 0;
	-:  388 : }
-:  389 :
	function isGameOver called 0 returned 0 % blocks executed 0 %
#####:  390:int isGameOver(struct gameState *state) {
	-:  391 : int i;
-:  392 : int j;
-:  393 :
	-: 394 :  //if stack of Province cards is empty, the game ends
#####:  395:  if (state->supplyCount[province] == 0)
	branch  0 never executed
	branch  1 never executed
	- : 396 : {
#####:  397:      return 1;
	-:  398 : }
-: 399 :
	-: 400 :  //if three supply pile are at 0, the game ends
#####:  401:  j = 0;
#####:  402:  for (i = 0; i < 25; i++)
	branch  0 never executed
	branch  1 never executed
	- : 403 : {
#####:  404:      if (state->supplyCount[i] == 0)
	branch  0 never executed
		branch  1 never executed
		- : 405 : {
#####:  406:	  j++;
		-:  407 : }
	-: 408 : }
#####:  409:  if ( j >= 3)
branch  0 never executed
branch  1 never executed
- : 410 : {
#####:  411:      return 1;
	-:  412 : }
-: 413 :
#####:  414:  return 0;
	-:  415 : }
-:  416 :
	function scoreFor called 0 returned 0 % blocks executed 0 %
#####:  417:int scoreFor (int player, struct gameState *state) {
	-:  418 :
	-: 419 : int i;
#####:  420:  int score = 0;
-:  421 :  //score from hand
#####:  422:  for (i = 0; i < state->handCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 423 : {
#####:  424:      if (state->hand[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  425:      if (state->hand[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  426:      if (state->hand[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  427:      if (state->hand[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  428:      if (state->hand[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  429:      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  430 : }
-:  431 :
	-: 432 :  //score from discard
#####:  433:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 434 : {
#####:  435:      if (state->discard[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  436:      if (state->discard[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  437:      if (state->discard[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  438:      if (state->discard[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  439:      if (state->discard[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  440:      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  441 : }
-:  442 :
	-: 443 :  //score from deck
#####:  444:  for (i = 0; i < state->discardCount[player]; i++)
	branch  0 never executed
	branch  1 never executed
	- : 445 : {
#####:  446:      if (state->deck[player][i] == curse) { score = score - 1; };
	branch  0 never executed
		branch  1 never executed
#####:  447:      if (state->deck[player][i] == estate) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  448:      if (state->deck[player][i] == duchy) { score = score + 3; };
		branch  0 never executed
		branch  1 never executed
#####:  449:      if (state->deck[player][i] == province) { score = score + 6; };
		branch  0 never executed
		branch  1 never executed
#####:  450:      if (state->deck[player][i] == great_hall) { score = score + 1; };
		branch  0 never executed
		branch  1 never executed
#####:  451:      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
		branch  0 never executed
		branch  1 never executed
		call    2 never executed
		- :  452 : }
-:  453 :
#####:  454:  return score;
	-:  455 : }
-:  456 :
	function getWinners called 0 returned 0 % blocks executed 0 %
#####:  457:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
	-:  458 : int i;
-:  459 : int j;
-:  460 : int highScore;
-:  461 : int currentPlayer;
-:  462 :
	-: 463 :  //get score for each player
#####:  464:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 465 : {
	-:  466 :      //set unused player scores to -9999
#####:  467:      if (i >= state->numPlayers)
		branch  0 never executed
		branch  1 never executed
		- : 468 : {
#####:  469:	  players[i] = -9999;
		-:  470 : }
	-: 471 : else
		- :  472 : {
#####:  473:	  players[i] = scoreFor (i, state);
		call    0 never executed
			- :  474 : }
	-: 475 : }
-:  476 :
	-: 477 :  //find highest score
#####:  478:  j = 0;
#####:  479:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 480 : {
#####:  481:      if (players[i] > players[j])
	branch  0 never executed
		branch  1 never executed
		- : 482 : {
#####:  483:	  j = i;
		-:  484 : }
	-: 485 : }
#####:  486:  highScore = players[j];
-:  487 :
	-: 488 :  //add 1 to players who had less turns
#####:  489:  currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  490:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 491 : {
#####:  492:      if ( players[i] == highScore && i > currentPlayer )
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 493 : {
#####:  494:	  players[i]++;
		-:  495 : }
	-: 496 : }
-:  497 :
	-: 498 :  //find new highest score
#####:  499:  j = 0;
#####:  500:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 501 : {
#####:  502:      if ( players[i] > players[j] )
	branch  0 never executed
		branch  1 never executed
		- : 503 : {
#####:  504:	  j = i;
		-:  505 : }
	-: 506 : }
#####:  507:  highScore = players[j];
-:  508 :
	-: 509 :  //set winners in array to 1 and rest to 0
#####:  510:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 511 : {
#####:  512:      if ( players[i] == highScore )
	branch  0 never executed
		branch  1 never executed
		- : 513 : {
#####:  514:	  players[i] = 1;
		-:  515 : }
	-: 516 : else
		- :  517 : {
#####:  518:	  players[i] = 0;
		-:  519 : }
	-: 520 : }
-:  521 :
#####:  522:  return 0;
	-:  523 : }
-:  524 :
	function drawCard called 21220 returned 100 % blocks executed 92 %
	21220 : 525 : int drawCard(int player, struct gameState *state)
	- : 526 : {	int count;
-:  527 : int deckCounter;
21220:  528 : if (state->deckCount[player] <= 0) {//Deck is empty
	branch  0 taken 1 % (fallthrough)
		branch  1 taken 99 %
		-:  529 :
		-: 530 :    //Step 1 Shuffle the discard pile back into a deck
		-: 531 : int i;
	-:  532 :    //Move discard to deck
		8620 : 533 : for (i = 0; i < state->discardCount[player]; i++) {
		branch  0 taken 98 %
			branch  1 taken 2 % (fallthrough)
			8484:  534 : state->deck[player][i] = state->discard[player][i];
		8484:  535 : state->discard[player][i] = -1;
		-:  536 :
	}
	-:  537 :
		136 : 538 : state->deckCount[player] = state->discardCount[player];
	136:  539 : state->discardCount[player] = 0;//Reset discard
	-:  540 :
		-: 541 :    //Shufffle the deck
		136 : 542 : shuffle(player, state);//Shuffle the deck up and make it so that we can draw
	call    0 returned 100 %
		-:  543 :
		-: 544 : if (DEBUG) {//Debug statements
		-:  545 : printf("Deck count now: %d\n", state->deckCount[player]);
		-:  546 :
	}
	-: 547 :
		136 : 548 : state->discardCount[player] = 0;
	-:  549 :
		-: 550 :    //Step 2 Draw Card
		136 : 551 : count = state->handCount[player];//Get current player's hand count
	-:  552 :
		-: 553 : if (DEBUG) {//Debug statements
		-:  554 : printf("Current hand count: %d\n", count);
		-:  555 :
	}
	-: 556 :
		136 : 557 : deckCounter = state->deckCount[player];//Create a holder for the deck count
	-:  558 :
		136 : 559 : if (deckCounter == 0)
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
#####:  560:      return -1;
		-:  561 :
		136 : 562 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
	136:  563 : state->deckCount[player]--;
	136:  564 : state->handCount[player]++;//Increment hand count
	-:  565 :
}
-:  566 :
	-: 567 : else {
	21084:  568 : int count = state->handCount[player];//Get current hand count for player
	-:  569 : int deckCounter;
	-:  570 : if (DEBUG) {//Debug statements
		-:  571 : printf("Current hand count: %d\n", count);
		-:  572 :
	}
	-: 573 :
		21084 : 574 : deckCounter = state->deckCount[player];//Create holder for the deck count
	21084:  575 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
	21084:  576 : state->deckCount[player]--;
	21084:  577 : state->handCount[player]++;//Increment hand count
	-:  578 :
}
-:  579 :
	21220 : 580 : return 0;
-:  581 : }
-:  582 :
	function getCost called 0 returned 0 % blocks executed 0 %
#####:  583:int getCost(int cardNumber)
	- : 584 : {
#####:  585:  switch( cardNumber ) 
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		branch  4 never executed
		branch  5 never executed
		branch  6 never executed
		branch  7 never executed
		branch  8 never executed
		branch  9 never executed
		branch 10 never executed
		branch 11 never executed
		branch 12 never executed
		branch 13 never executed
		branch 14 never executed
		branch 15 never executed
		branch 16 never executed
		branch 17 never executed
		branch 18 never executed
		branch 19 never executed
		branch 20 never executed
		branch 21 never executed
		branch 22 never executed
		branch 23 never executed
		branch 24 never executed
		branch 25 never executed
		branch 26 never executed
		branch 27 never executed
		- :  586 : {
		-:  587 : case curse:
#####:  588:      return 0;
			-:  589 : case estate:
#####:  590:      return 2;
				-:  591 : case duchy:
#####:  592:      return 5;
					-:  593 : case province:
#####:  594:      return 8;
						-:  595 : case copper:
#####:  596:      return 0;
							-:  597 : case silver:
#####:  598:      return 3;
								-:  599 : case gold:
#####:  600:      return 6;
									-:  601 : case adventurer:
#####:  602:      return 6;
										-:  603 : case council_room:
#####:  604:      return 5;
											-:  605 : case feast:
#####:  606:      return 4;
												-:  607 : case gardens:
#####:  608:      return 4;
													-:  609 : case mine:
#####:  610:      return 5;
														-:  611 : case remodel:
#####:  612:      return 4;
															-:  613 : case smithy:
#####:  614:      return 4;
																-:  615 : case village:
#####:  616:      return 3;
																	-:  617 : case baron:
#####:  618:      return 4;
																		-:  619 : case great_hall:
#####:  620:      return 3;
																			-:  621 : case minion:
#####:  622:      return 5;
																				-:  623 : case steward:
#####:  624:      return 3;
																					-:  625 : case tribute:
#####:  626:      return 5;
																						-:  627 : case ambassador:
#####:  628:      return 3;
																							-:  629 : case cutpurse:
#####:  630:      return 4;
																								-:  631 : case embargo:
#####:  632:      return 2;
																									-:  633 : case outpost:
#####:  634:      return 5;
																										-:  635 : case salvager:
#####:  636:      return 4;
																											-:  637 : case sea_hag:
#####:  638:      return 4;
																												-:  639 : case treasure_map:
#####:  640:      return 4;
																													-:  641 : }
	-:  642 :
#####:  643:  return -1;
		-:  644 : }
-:  645 :
	function cardEffect called 1000 returned 100 % blocks executed 3 %
	1000 : 646 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	- : 647 : {
	-:  648 : int i;
	-:  649 : int j;
	-:  650 : int k;
	-:  651 : int x;
	-:  652 : int index;
	1000:  653 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		1000:  654 : int nextPlayer = currentPlayer + 1;
	-:  655 :
		1000 : 656 : int tributeRevealedCards[2] = { -1, -1 };
	-:  657 : int temphand[MAX_HAND];// moved above the if statement
	1000:  658 : int drawntreasure = 0;
	-:  659 : int cardDrawn;
	1000:  660 : int z = 0;// this is the counter for the temp hand
	1000:  661 : if (nextPlayer > (state->numPlayers - 1)) {
		branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
#####:  662:    nextPlayer = 0;
			-:  663 :
	}
	-:  664 :
		-: 665 :
		-: 666 :  //uses switch to select card and perform actions
		1000 : 667 : switch (card)
		branch  0 taken 100 %
		branch  1 taken 0 %
		branch  2 taken 0 %
		branch  3 taken 0 %
		branch  4 taken 0 %
		branch  5 taken 0 %
		branch  6 taken 0 %
		branch  7 taken 0 %
		branch  8 taken 0 %
		branch  9 taken 0 %
		branch 10 taken 0 %
		branch 11 taken 0 %
		branch 12 taken 0 %
		branch 13 taken 0 %
		branch 14 taken 0 %
		branch 15 taken 0 %
		branch 16 taken 0 %
		branch 17 taken 0 %
		branch 18 taken 0 %
		branch 19 taken 0 %
		branch 20 taken 0 %
		-:  668 : {
		-:  669 : case adventurer:
			1000 : 670 : return playAdventurer(state);
			call    0 returned 100 %
				-:  671 :
				-: 672 : case council_room:
#####:  673:      return playCouncil_Room(state, handPos);
					call    0 never executed
						- :  674 :
						-: 675 :
						-: 676 : case feast:
#####:  677:      return playFeast(state, choice1);
							call    0 never executed
								- :  678 :
								-: 679 :
								-: 680 : case gardens:
#####:  681:      return -1;
									-:  682 :
										-: 683 : case mine:
#####:  684:      j = state->hand[currentPlayer][choice1];  //store card we will trash
											-:  685 :
#####:  686:      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 687 : {
#####:  688:	  return -1;
												-:  689 : }
											-: 690 :
#####:  691:      if (choice2 > treasure_map || choice2 < curse)
												branch  0 never executed
												branch  1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 692 : {
#####:  693:	  return -1;
												-:  694 : }
											-: 695 :
#####:  696:      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
												call    0 never executed
												call    1 never executed
												branch  2 never executed
												branch  3 never executed
												- : 697 : {
#####:  698:	  return -1;
												-:  699 : }
											-: 700 :
#####:  701:      gainCard(choice2, state, 2, currentPlayer);
												call    0 never executed
												- :  702 :
												-: 703 :      //discard card from hand
#####:  704:      discardCard(handPos, currentPlayer, state, 0);
												call    0 never executed
												- :  705 :
												-: 706 :      //discard trashed card
#####:  707:      for (i = 0; i < state->handCount[currentPlayer]; i++)
												branch  0 never executed
												branch  1 never executed
												- : 708 : {
#####:  709:	  if (state->hand[currentPlayer][i] == j)
												branch  0 never executed
													branch  1 never executed
													- : 710 : {
#####:  711:	      discardCard(i, currentPlayer, state, 0);			
													call    0 never executed
#####:  712:	      break;
														-:  713 : }
												-: 714 : }
											-:  715 :
#####:  716:      return 0;
												-:  717 :
												-: 718 : case remodel:
#####:  719:      j = state->hand[currentPlayer][choice1];  //store card we will trash
													-:  720 :
#####:  721:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
														call    0 never executed
														call    1 never executed
														branch  2 never executed
														branch  3 never executed
														- : 722 : {
#####:  723:	  return -1;
														-:  724 : }
													-: 725 :
#####:  726:      gainCard(choice2, state, 0, currentPlayer);
														call    0 never executed
														- :  727 :
														-: 728 :      //discard card from hand
#####:  729:      discardCard(handPos, currentPlayer, state, 0);
														call    0 never executed
														- :  730 :
														-: 731 :      //discard trashed card
#####:  732:      for (i = 0; i < state->handCount[currentPlayer]; i++)
														branch  0 never executed
														branch  1 never executed
														- : 733 : {
#####:  734:	  if (state->hand[currentPlayer][i] == j)
														branch  0 never executed
															branch  1 never executed
															- : 735 : {
#####:  736:	      discardCard(i, currentPlayer, state, 0);			
															call    0 never executed
#####:  737:	      break;
																-:  738 : }
														-: 739 : }
													-:  740 :
														-: 741 :
#####:  742:      return 0;
														-:  743 :
														-: 744 : case smithy:
#####:  745:      return playSmithy(state, handPos);
															call    0 never executed
																- :  746 :
																-: 747 : case village:
#####:  748:      return playVillage(state, handPos);
																	call    0 never executed
																		- :  749 :
																		-: 750 : case baron:
#####:  751:      state->numBuys++;//Increase buys by 1!
#####:  752:      if (choice1 > 0){//Boolean true or going to discard an estate
																			branch  0 never executed
																				branch  1 never executed
#####:  753:	int p = 0;//Iterator for hand!
#####:  754:	int card_not_discarded = 1;//Flag for discard set!
#####:  755:	while(card_not_discarded){
																				branch  0 never executed
																				branch  1 never executed
#####:  756:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																				branch  0 never executed
																				branch  1 never executed
#####:  757:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  758:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  759:	    state->discardCount[currentPlayer]++;
#####:  760:	    for (;p < state->handCount[currentPlayer]; p++){
																				branch  0 never executed
																				branch  1 never executed
#####:  761:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																				-:  762 : }
#####:  763:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  764:	    state->handCount[currentPlayer]--;
#####:  765:	    card_not_discarded = 0;//Exit the loop
																				-:  766 : }
#####:  767:	  else if (p > state->handCount[currentPlayer]){
																				branch  0 never executed
																				branch  1 never executed
																				- :  768 : if (DEBUG) {
																				-:  769 : printf("No estate cards in your hand, invalid choice\n");
																				-:  770 : printf("Must gain an estate if there are any\n");
																				-:  771 :
																			}
#####:  772:	    if (supplyCount(estate, state) > 0){
																			call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  773:	      gainCard(estate, state, 0, currentPlayer);
																				call    0 never executed
#####:  774:	      state->supplyCount[estate]--;//Decrement estates
#####:  775:	      if (supplyCount(estate, state) == 0){
																				call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  776:		isGameOver(state);
																				call    0 never executed
																				- :  777 : }
																				-:  778 : }
#####:  779:	    card_not_discarded = 0;//Exit the loop
																				-:  780 : }
																			-:  781 :
																				-: 782 : else {
#####:  783:	    p++;//Next card
																				-:  784 :
																			}
																			-:  785 : }
																				-:  786 : }
																	-:  787 :
																		-: 788 : else {
#####:  789:	if (supplyCount(estate, state) > 0){
																		call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####:  790:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																			call    0 never executed
#####:  791:	  state->supplyCount[estate]--;//Decrement Estates
#####:  792:	  if (supplyCount(estate, state) == 0){
																			call    0 never executed
																			branch  1 never executed
																			branch  2 never executed
#####:  793:	    isGameOver(state);
																			call    0 never executed
																			- :  794 : }
																			-:  795 : }
																	-:  796 :
																	}
																	-:  797 :
																		-: 798 :
#####:  799:      return 0;
																		-:  800 :
																		-: 801 : case great_hall:
																			-: 802 :      //+1 Card
#####:  803:      drawCard(currentPlayer, state);
																				call    0 never executed
																				- :  804 :
																				-: 805 :      //+1 Actions
#####:  806:      state->numActions++;
																				-:  807 :
																				-: 808 :      //discard card from hand
#####:  809:      discardCard(handPos, currentPlayer, state, 0);
																				call    0 never executed
#####:  810:      return 0;
																				-:  811 :
																				-: 812 : case minion:
																					-: 813 :      //+1 action
#####:  814:      state->numActions++;
																						-:  815 :
																						-: 816 :      //discard card from hand
#####:  817:      discardCard(handPos, currentPlayer, state, 0);
																						call    0 never executed
																						- :  818 :
#####:  819:      if (choice1)		//+2 coins
																						branch  0 never executed
																						branch  1 never executed
																						- : 820 : {
#####:  821:	  state->coins = state->coins + 2;
																						-:  822 : }
																					-: 823 :
#####:  824:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																						branch  0 never executed
																						branch  1 never executed
																						- :  825 : {
																						-:  826 :	  //discard hand
#####:  827:	  while(numHandCards(state) > 0)
																							call    0 never executed
																							branch  1 never executed
																							branch  2 never executed
																							- : 828 : {
#####:  829:	      discardCard(handPos, currentPlayer, state, 0);
																							call    0 never executed
																								- :  830 : }
																						-: 831 :
																							-: 832 :	  //draw 4
#####:  833:	  for (i = 0; i < 4; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 834 : {
#####:  835:	      drawCard(currentPlayer, state);
																							call    0 never executed
																								- :  836 : }
																						-: 837 :
																							-: 838 :	  //other players discard hand and redraw if hand size > 4
#####:  839:	  for (i = 0; i < state->numPlayers; i++)
																							branch  0 never executed
																							branch  1 never executed
																							- : 840 : {
#####:  841:	      if (i != currentPlayer)
																							branch  0 never executed
																								branch  1 never executed
																								- : 842 : {
#####:  843:		  if ( state->handCount[i] > 4 )
																								branch  0 never executed
																									branch  1 never executed
																									- : 844 : {
																									-:  845 :		      //discard hand
#####:  846:		      while( state->handCount[i] > 0 )
																										branch  0 never executed
																										branch  1 never executed
																										- : 847 : {
#####:  848:			  discardCard(handPos, i, state, 0);
																										call    0 never executed
																											- :  849 : }
																									-: 850 :
																										-: 851 :		      //draw 4
#####:  852:		      for (j = 0; j < 4; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 853 : {
#####:  854:			  drawCard(i, state);
																										call    0 never executed
																											- :  855 : }
																									-: 856 : }
																								-:  857 : }
																							-:  858 : }
																						-:  859 :
																							-: 860 : }
#####:  861:      return 0;
																					-:  862 :
																						-: 863 : case steward:
#####:  864:      if (choice1 == 1)
																							branch  0 never executed
																								branch  1 never executed
																								- : 865 : {
																								-:  866 :	  //+2 cards
#####:  867:	  drawCard(currentPlayer, state);
																									call    0 never executed
#####:  868:	  drawCard(currentPlayer, state);
																									call    0 never executed
																									- :  869 : }
#####:  870:      else if (choice1 == 2)
																							branch  0 never executed
																								branch  1 never executed
																								- :  871 : {
																								-:  872 :	  //+2 coins
#####:  873:	  state->coins = state->coins + 2;
																									-:  874 : }
																							-: 875 : else
																								- :  876 : {
																								-:  877 :	  //trash 2 cards in hand
#####:  878:	  discardCard(choice2, currentPlayer, state, 1);
																									call    0 never executed
#####:  879:	  discardCard(choice3, currentPlayer, state, 1);
																									call    0 never executed
																									- :  880 : }
																							-:  881 :
																								-: 882 :      //discard card from hand
#####:  883:      discardCard(handPos, currentPlayer, state, 0);
																								call    0 never executed
#####:  884:      return 0;
																								-:  885 :
																								-: 886 : case tribute:
#####:  887:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																									branch  0 never executed
																										branch  1 never executed
#####:  888:	if (state->deckCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####:  889:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  890:	  state->deckCount[nextPlayer]--;
																										-:  891 : }
#####:  892:	else if (state->discardCount[nextPlayer] > 0){
																										branch  0 never executed
																										branch  1 never executed
#####:  893:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####:  894:	  state->discardCount[nextPlayer]--;
																										-:  895 : }
																									-:  896 : else {
																										-:  897 :	  //No Card to Reveal
																											-: 898 : if (DEBUG) {
																											-:  899 : printf("No cards to reveal\n");
																											-:  900 :
																										}
																										-: 901 :
																									}
																									-:  902 : }
																							-:  903 :
																								-: 904 : else {
#####:  905:	if (state->deckCount[nextPlayer] == 0){
																								branch  0 never executed
																									branch  1 never executed
#####:  906:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																									branch  0 never executed
																									branch  1 never executed
#####:  907:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####:  908:	    state->deckCount[nextPlayer]++;
#####:  909:	    state->discard[nextPlayer][i] = -1;
#####:  910:	    state->discardCount[nextPlayer]--;
																									-:  911 : }
																									-:  912 :
#####:  913:	  shuffle(nextPlayer,state);//Shuffle the deck
																									call    0 never executed
																									- :  914 : }
#####:  915:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  916:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####:  917:	state->deckCount[nextPlayer]--;
#####:  918:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####:  919:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####:  920:	state->deckCount[nextPlayer]--;
																							-:  921 :
																							}
																							-:  922 :
#####:  923:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																								branch  0 never executed
																								branch  1 never executed
#####:  924:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####:  925:	state->playedCardCount++;
#####:  926:	tributeRevealedCards[1] = -1;
																								-:  927 : }
																							-:  928 :
#####:  929:      for (i = 0; i <= 2; i ++){
																								branch  0 never executed
																								branch  1 never executed
#####:  930:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
#####:  931:	  state->coins += 2;
																								-:  932 : }
																								-:  933 :
#####:  934:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
																								branch  0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								branch  3 never executed
																								branch  4 never executed
																								branch  5 never executed
																								branch  6 never executed
																								branch  7 never executed
																								branch  8 never executed
																								branch  9 never executed
#####:  935:	  drawCard(currentPlayer, state);
																								call    0 never executed
#####:  936:	  drawCard(currentPlayer, state);
																								call    0 never executed
																								- :  937 : }
																							-:  938 : else {//Action Card
#####:  939:	  state->numActions = state->numActions + 2;
																								-:  940 :
																							}
																							-:  941 : }
																							-:  942 :
#####:  943:      return 0;
																								-:  944 :
																								-: 945 : case ambassador:
#####:  946:      j = 0;		//used to check if player has enough cards to discard
																									-:  947 :
#####:  948:      if (choice2 > 2 || choice2 < 0)
																										branch  0 never executed
																										branch  1 never executed
																										branch  2 never executed
																										branch  3 never executed
																										- : 949 : {
#####:  950:	  return -1;				
																										-:  951 : }
																									-: 952 :
#####:  953:      if (choice1 == handPos)
																										branch  0 never executed
																										branch  1 never executed
																										- : 954 : {
#####:  955:	  return -1;
																										-:  956 : }
																									-: 957 :
#####:  958:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 959 : {
#####:  960:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																										branch  0 never executed
																											branch  1 never executed
																											branch  2 never executed
																											branch  3 never executed
																											branch  4 never executed
																											branch  5 never executed
																											- :  961 : {
#####:  962:	      j++;
																											-:  963 : }
																										-: 964 : }
#####:  965:      if (j < choice2)
																									branch  0 never executed
																										branch  1 never executed
																										- : 966 : {
#####:  967:	  return -1;				
																										-:  968 : }
																									-: 969 :
																										-: 970 : if (DEBUG)
																										-: 971 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																									-:  972 :
																										-: 973 :      //increase supply count for choosen card by amount being discarded
#####:  974:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																										-:  975 :
																										-: 976 :      //each other player gains a copy of revealed card
#####:  977:      for (i = 0; i < state->numPlayers; i++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 978 : {
#####:  979:	  if (i != currentPlayer)
																										branch  0 never executed
																											branch  1 never executed
																											- : 980 : {
#####:  981:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																											call    0 never executed
																												- :  982 : }
																										-: 983 : }
																									-:  984 :
																										-: 985 :      //discard played card from hand
#####:  986:      discardCard(handPos, currentPlayer, state, 0);			
																										call    0 never executed
																										- :  987 :
																										-: 988 :      //trash copies of cards returned to supply
#####:  989:      for (j = 0; j < choice2; j++)
																										branch  0 never executed
																										branch  1 never executed
																										- : 990 : {
#####:  991:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																										branch  0 never executed
																											branch  1 never executed
																											- : 992 : {
#####:  993:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																											branch  0 never executed
																												branch  1 never executed
																												- : 994 : {
#####:  995:		  discardCard(i, currentPlayer, state, 1);
																												call    0 never executed
#####:  996:		  break;
																													-:  997 : }
																											-: 998 : }
																										-:  999 : }
																									-: 1000 :
#####: 1001:      return 0;
																										-: 1002 :
																										-: 1003 : case cutpurse:
																											-: 1004 :
#####: 1005:      updateCoins(currentPlayer, state, 2);
																												call    0 never executed
#####: 1006:      for (i = 0; i < state->numPlayers; i++)
																												branch  0 never executed
																												branch  1 never executed
																												- : 1007 : {
#####: 1008:	  if (i != currentPlayer)
																												branch  0 never executed
																													branch  1 never executed
																													- : 1009 : {
#####: 1010:	      for (j = 0; j < state->handCount[i]; j++)
																													branch  0 never executed
																														branch  1 never executed
																														- : 1011 : {
#####: 1012:		  if (state->hand[i][j] == copper)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1013 : {
#####: 1014:		      discardCard(j, i, state, 0);
																															call    0 never executed
#####: 1015:		      break;
																																-: 1016 : }
#####: 1017:		  if (j == state->handCount[i])
																														branch  0 never executed
																															branch  1 never executed
																															- : 1018 : {
#####: 1019:		      for (k = 0; k < state->handCount[i]; k++)
																															branch  0 never executed
																																branch  1 never executed
																																- : 1020 : {
																																-: 1021 : if (DEBUG)
																																	-: 1022 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																-: 1023 : }
#####: 1024:		      break;
																															-: 1025 : }
																														-: 1026 : }
																													-: 1027 :
																														-: 1028 : }
																												-: 1029 :
																													-: 1030 : }
																											-: 1031 :
																												-: 1032 :      //discard played card from hand
#####: 1033:      discardCard(handPos, currentPlayer, state, 0);			
																												call    0 never executed
																												- : 1034 :
#####: 1035:      return 0;
																												-: 1036 :
																												-: 1037 :
																												-: 1038 : case embargo:
																													-: 1039 :      //+2 Coins
#####: 1040:      state->coins = state->coins + 2;
																														-: 1041 :
																														-: 1042 :      //see if selected pile is in play
#####: 1043:      if ( state->supplyCount[choice1] == -1 )
																														branch  0 never executed
																														branch  1 never executed
																														- : 1044 : {
#####: 1045:	  return -1;
																														-: 1046 : }
																													-: 1047 :
																														-: 1048 :      //add embargo token to selected supply pile
#####: 1049:      state->embargoTokens[choice1]++;
																														-: 1050 :
																														-: 1051 :      //trash card
#####: 1052:      discardCard(handPos, currentPlayer, state, 1);		
																														call    0 never executed
#####: 1053:      return 0;
																														-: 1054 :
																														-: 1055 : case outpost:
																															-: 1056 :      //set outpost flag
#####: 1057:      state->outpostPlayed++;
																																-: 1058 :
																																-: 1059 :      //discard card
#####: 1060:      discardCard(handPos, currentPlayer, state, 0);
																																call    0 never executed
#####: 1061:      return 0;
																																-: 1062 :
																																-: 1063 : case salvager:
																																	-: 1064 :      //+1 buy
#####: 1065:      state->numBuys++;
																																		-: 1066 :
#####: 1067:      if (choice1)
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 1068 : {
																																		-: 1069 :	  //gain coins equal to trashed card
#####: 1070:	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																			call    0 never executed
																																			call    1 never executed
																																			- : 1071 :	  //trash card
#####: 1072:	  discardCard(choice1, currentPlayer, state, 1);	
																																			call    0 never executed
																																			- : 1073 : }
																																	-: 1074 :
																																		-: 1075 :      //discard card
#####: 1076:      discardCard(handPos, currentPlayer, state, 0);
																																		call    0 never executed
#####: 1077:      return 0;
																																		-: 1078 :
																																		-: 1079 : case sea_hag:
#####: 1080:      for (i = 0; i < state->numPlayers; i++){
																																			branch  0 never executed
																																				branch  1 never executed
#####: 1081:	if (i != currentPlayer){
																																				branch  0 never executed
																																				branch  1 never executed
#####: 1082:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####: 1083:	  state->discardCount[i]++;
#####: 1084:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																				-: 1085 : }
																																				-: 1086 : }
#####: 1087:      return 0;
																																	-: 1088 :
																																		-: 1089 : case treasure_map:
																																			-: 1090 :      //search hand for another treasure_map
#####: 1091:      index = -1;
#####: 1092:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																				branch  0 never executed
																																				branch  1 never executed
																																				- : 1093 : {
#####: 1094:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																				branch  0 never executed
																																					branch  1 never executed
																																					branch  2 never executed
																																					branch  3 never executed
																																					- : 1095 : {
#####: 1096:	      index = i;
#####: 1097:	      break;
																																					-: 1098 : }
																																				-: 1099 : }
#####: 1100:      if (index > -1)
																																			branch  0 never executed
																																				branch  1 never executed
																																				- : 1101 : {
																																				-: 1102 :	  //trash both treasure cards
#####: 1103:	  discardCard(handPos, currentPlayer, state, 1);
																																					call    0 never executed
#####: 1104:	  discardCard(index, currentPlayer, state, 1);
																																					call    0 never executed
																																					- : 1105 :
																																					-: 1106 :	  //gain 4 Gold cards
#####: 1107:	  for (i = 0; i < 4; i++)
																																					branch  0 never executed
																																					branch  1 never executed
																																					- : 1108 : {
#####: 1109:	      gainCard(gold, state, 1, currentPlayer);
																																					call    0 never executed
																																						- : 1110 : }
																																				-: 1111 :
																																					-: 1112 :	  //return success
#####: 1113:	  return 1;
																																					-: 1114 : }
																																			-: 1115 :
																																				-: 1116 :      //no second treasure_map found in hand
#####: 1117:      return -1;
																																				-: 1118 : }
	-: 1119 :
#####: 1120:  return -1;
		-: 1121 : }
-: 1122 :
	function playAdventurer called 1000 returned 100 % blocks executed 100 %
	1000 : 1123 : int playAdventurer(struct gameState *state) {
	1000: 1124 : int currentPlayer = whoseTurn(state);
	call    0 returned 100 %
		-: 1125 : int temphand[MAX_HAND];
	1000: 1126 : int z = 0;
	1000: 1127 : int drawntreasure = 0;
	-: 1128 : int cardDrawn;
	-: 1129 :
		-: 1130 :
		18220 : 1131 : while (drawntreasure<2) {
		branch  0 taken 94 %
			branch  1 taken 6 % (fallthrough)
			16220: 1132 : if (state->deckCount[currentPlayer] < 1) {//if the deck is empty we need to shuffle discard and add to deck
			branch  0 taken 1 % (fallthrough)
				branch  1 taken 99 %
				136: 1133 : shuffle(currentPlayer, state);
			call    0 returned 100 %
				-: 1134 :
		}
		16220: 1135 : drawCard(currentPlayer, state);
		call    0 returned 100 %
			16220: 1136 : cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		16220: 1137 : if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			branch  0 taken 96 % (fallthrough)
			branch  1 taken 4 %
			branch  2 taken 96 % (fallthrough)
			branch  3 taken 4 %
			branch  4 taken 4 % (fallthrough)
			branch  5 taken 96 %
			2000: 1138 : drawntreasure++;
		-: 1139 : else {
			14220: 1140 : temphand[z] = cardDrawn;
			14220: 1141 : state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			14220: 1142 : z++;
			-: 1143 :
		}
		-: 1144 :
	}
	7077: 1145 : while (z - 1 >= 0) {
		branch  0 taken 84 %
			branch  1 taken 16 % (fallthrough)
			5077: 1146 : state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		5077: 1147 : z = z - 3;
		-: 1148 :
	}
	1000: 1149 : return 0;
	-: 1150 :
}
-: 1151 :
	function playSmithy called 0 returned 0 % blocks executed 0 %
#####: 1152:int playSmithy(struct gameState *state, int handPos){
#####: 1153:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1154 : int i;
-: 1155 :  //draw three cards
#####: 1156:  for (i; i < 3; i++)
	branch  0 never executed
	branch  1 never executed
	- : 1157 : {
#####: 1158:	  drawCard(currentPlayer, state);
	call    0 never executed
		- : 1159 : }
-: 1160 :
	-: 1161 :      //discard card from hand
#####: 1162:      discardCard(handPos, currentPlayer, state, 0);
	call    0 never executed
#####: 1163:      return 0;
	-: 1164 : }
-: 1165 :
	function playVillage called 0 returned 0 % blocks executed 0 %
#####: 1166:int playVillage(struct gameState *state, int handPos){
#####: 1167:      int currentPlayer = whoseTurn(state) + 1;
	call    0 never executed
	- : 1168 :      //+1 Card
#####: 1169:      drawCard(currentPlayer, state);
	call    0 never executed
	- : 1170 :
	-: 1171 :      //+2 Actions
#####: 1172:      state->numActions = state->numActions + 2;
	-: 1173 :
	-: 1174 :      //discard played card from hand
#####: 1175:      discardCard(handPos, currentPlayer, state, 0);
	call    0 never executed
#####: 1176:      return 0;
	-: 1177 : }
-: 1178 :
	function playFeast called 0 returned 0 % blocks executed 0 %
#####: 1179:int playFeast(struct gameState *state, int choice1){
#####: 1180:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1181 : int temphand[MAX_HAND];
-: 1182 : int i;
-: 1183 : int x;
-: 1184 :    //gain card with cost up to 5
	-: 1185 :      //Backup hand
#####: 1186:  for (i = 0; i <= state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####: 1187:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####: 1188:	state->hand[currentPlayer][i] = -1;//Set to nothing
	-: 1189 : }
-: 1190 :      //Backup hand
	-: 1191 :
	-: 1192 :      //Update Coins for Buy
#####: 1193:      updateCoins(currentPlayer, state, 5);
	call    0 never executed
#####: 1194:      x = 1;//Condition to loop on
#####: 1195:  while( x == 1) {//Buy one card
	branch  0 never executed
	branch  1 never executed
#####: 1196:    if (supplyCount(choice1, state) <= 0){
	call    0 never executed
	branch  1 never executed
	branch  2 never executed
	- : 1197 : if (DEBUG)
	-: 1198 : printf("None of that card left, sorry!\n");
-: 1199 :
	-: 1200 : if (DEBUG) {
	-: 1201 : printf("Cards Left: %d\n", supplyCount(choice1, state));
	-: 1202 :
}
-: 1203 : }
#####: 1204:    else if (state->coins < getCost(choice1)){
	call    0 never executed
	branch  1 never executed
	branch  2 never executed
#####: 1205:      printf("That card is too expensive!\n");
	call    0 never executed
	- : 1206 :
	-: 1207 : if (DEBUG) {
	-: 1208 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
	-: 1209 :
}
-: 1210 : }
-: 1211 : else {
	-: 1212 :
		-: 1213 : if (DEBUG) {
		-: 1214 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
		-: 1215 :
	}
	-: 1216 :
		-: 1217 :
#####: 1218:      for(i = 0; i < 5; i++){
		branch  0 never executed
		branch  1 never executed
#####: 1219:      gainCard(choice1, state, 0, currentPlayer);//Gain the card
		call    0 never executed
		- : 1220 : }
#####: 1221:      x = 0;//No more buying cards
	-: 1222 :
		-: 1223 : if (DEBUG) {
		-: 1224 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
		-: 1225 :
	}
	-: 1226 :
		-: 1227 :
}
-: 1228 : }
-: 1229 :
	-: 1230 :      //Reset Hand
#####: 1231:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
	branch  0 never executed
	branch  1 never executed
#####: 1232:	state->hand[currentPlayer][i] = temphand[i];
#####: 1233:	temphand[i] = -1;
	-: 1234 : }
-: 1235 :      //Reset Hand
	-: 1236 :
#####: 1237:      return 0;
	-: 1238 :
	-: 1239 : };
-: 1240 :
	function playCouncil_Room called 0 returned 0 % blocks executed 0 %
#####: 1241:int playCouncil_Room(struct gameState *state, int handPos){
#####: 1242:  int currentPlayer = whoseTurn(state);
	call    0 never executed
	- : 1243 : int i;
-: 1244 :  //+4 Cards
#####: 1245:  for (i = 0; i < 4; i++)
	branch  0 never executed
	branch  1 never executed
	- : 1246 : {
#####: 1247:	  drawCard(currentPlayer, state);
	call    0 never executed
		- : 1248 : }
-: 1249 :
	-: 1250 :      //+1 Buy
#####: 1251:      state->numBuys++;
	-: 1252 :
	-: 1253 :      //Each other player draws a card
#####: 1254:      for (i = 0; i < state->numPlayers; i++)
	branch  0 never executed
	branch  1 never executed
	- : 1255 : {
#####: 1256:	  if ( i != currentPlayer )
	branch  0 never executed
		branch  1 never executed
		- : 1257 : {
#####: 1258:	      drawCard(i, state);
		call    0 never executed
			- : 1259 : }
	-: 1260 : }
-: 1261 :
	-: 1262 :      //put played card in played card pile
#####: 1263:      discardCard(handPos, currentPlayer, state, 0);
	call    0 never executed
	- : 1264 :
#####: 1265:      return 0;
	-: 1266 :
	-: 1267 :
	-: 1268 : }
-: 1269 :
	function discardCard called 0 returned 0 % blocks executed 0 %
#####: 1270:int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	- : 1271 : {
	-: 1272 :
		-: 1273 :  //if card is not trashed, added to Played pile 
#####: 1274:  if (trashFlag < 1)
		branch  0 never executed
		branch  1 never executed
		- : 1275 : {
		-: 1276 :      //add card to played pile
#####: 1277:      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
#####: 1278:      state->playedCardCount++;
			-: 1279 : }
	-: 1280 :
		-: 1281 :  //set played card to -1
#####: 1282:  state->hand[currentPlayer][handPos] = -1;
		-: 1283 :
		-: 1284 :  //remove card from player's hand
#####: 1285:  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
		branch  0 never executed
		branch  1 never executed
		- : 1286 : {
		-: 1287 :      //reduce number of cards in hand
#####: 1288:      state->handCount[currentPlayer]--;
			-: 1289 : }
#####: 1290:  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
	branch  0 never executed
		branch  1 never executed
		- : 1291 : {
		-: 1292 :      //reduce number of cards in hand
#####: 1293:      state->handCount[currentPlayer]--;
			-: 1294 : }
	-: 1295 : else
		- : 1296 : {
		-: 1297 :      //replace discarded card with last card in hand
#####: 1298:      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
			-: 1299 :      //set last card to -1
#####: 1300:      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
			-: 1301 :      //reduce number of cards in hand
#####: 1302:      state->handCount[currentPlayer]--;
			-: 1303 : }
	-: 1304 :
#####: 1305:  return 0;
		-: 1306 : }
-: 1307 :
	function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1308:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	- : 1309 : {
	-: 1310 :  //Note: supplyPos is enum of choosen card
		-: 1311 :
		-: 1312 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1313:  if ( supplyCount(supplyPos, state) < 1 )
		call    0 never executed
		branch  1 never executed
		branch  2 never executed
		- : 1314 : {
#####: 1315:      return -1;
		-: 1316 : }
	-: 1317 :
		-: 1318 :  //added card for [whoseTurn] current player:
		-: 1319 :  // toFlag = 0 : add to discard
		-: 1320 :  // toFlag = 1 : add to deck
		-: 1321 :  // toFlag = 2 : add to hand
		-: 1322 :
#####: 1323:  if (toFlag == 1)
		branch  0 never executed
		branch  1 never executed
		- : 1324 : {
#####: 1325:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1326:      state->deckCount[player]++;
		-: 1327 : }
#####: 1328:  else if (toFlag == 2)
	branch  0 never executed
		branch  1 never executed
		- : 1329 : {
#####: 1330:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1331:      state->handCount[player]++;
		-: 1332 : }
	-: 1333 : else
		- : 1334 : {
#####: 1335:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1336:      state->discardCount[player]++;
		-: 1337 : }
	-: 1338 :
		-: 1339 :  //decrease number in supply pile
#####: 1340:  state->supplyCount[supplyPos]--;
		-: 1341 :
#####: 1342:  return 0;
		-: 1343 : }
-: 1344 :
	function updateCoins called 1000 returned 100 % blocks executed 82 %
	1000 : 1345 : int updateCoins(int player, struct gameState *state, int bonus)
	- : 1346 : {
	-: 1347 : int i;
	-: 1348 :
		-: 1349 :  //reset coin count
		1000 : 1350 : state->coins = 0;
	-: 1351 :
		-: 1352 :  //add coins for each Treasure card in player's hand
		6000 : 1353 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 83 %
		branch  1 taken 17 % (fallthrough)
		-: 1354 : {
		5000: 1355 : if (state->hand[player][i] == copper)
			branch  0 taken 80 % (fallthrough)
			branch  1 taken 20 %
			-: 1356 : {
			4000: 1357 : state->coins += 1;
			-: 1358 : }
		1000 : 1359 : else if (state->hand[player][i] == silver)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1360 : {
#####: 1361:	  state->coins += 2;
			-: 1362 : }
		1000 : 1363 : else if (state->hand[player][i] == gold)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1364 : {
#####: 1365:	  state->coins += 3;
			-: 1366 : }
		-: 1367 : }
	-: 1368 :
		-: 1369 :  //add bonus
		1000 : 1370 : state->coins += bonus;
	-: 1371 :
		1000 : 1372 : return 0;
	-: 1373 : }
-: 1374 :
	-: 1375 :
	-: 1376 ://end of dominion.c
	-: 1377 :

