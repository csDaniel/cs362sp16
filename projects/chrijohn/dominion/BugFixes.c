Bugs Fixed:

Bug 2.1 from maillarw:
This bug was an error in determing the score for a player when they have one of every card in their deck.  This bug was fixed by changing line 444 to iterate over the players deck count instead of discard count.  This bug was fairly easy to determine.  I actually found it through my unit testing and my partner also found it and provided the fix in the bug report.

Bug 2.2 from maillarw:
This bug was in the playsmithy() function.  The bug report states the hand count does not match what it should be.  The function is only a handful of lines so it was easy to manually review it and see the error was in line 649 where the loop only goes to 2 instead of 3.

Bug 1 from murphpet:
This was in the playadventurer function.  The bug report states the hand count is one high and the discard count is one too low.  My initital thought this is due to discarding the played card.  After reviewing the code, the card is never discarded.  This was added to line  679.

Bug 2 from murphet:
This was in the play council room function.  The bug report states the player hand is one too high, coins is 4 too high and buys is 3 too high.  After reviewing the code, the first bug is due to not discarding the played card.  Additionally, it appears that for each loop in the for loop, the player gets an additional coin and buy.  I removed the coin++ and moved the buy++ outside the for loop.

The following bugs I found in my testing:
scoreFor(): Bug1
This bug is when there are 15 cards throughout the players deck.  It turns out this bug was in lines 430, 442 and 454.  Instead of giving 1 point for every 10 cards in a players deck, it was just getting the count of card 0.  This was changed by adding the counts of deck, discard and hand and dividing by 10.

scoreFor(): Bug2
This was found by partner and fixed above

Smith(): Bug1
This was found by partner and fixed above

Smith() : Bug2
This was found by partner and fixed above

Adventurer(): Bug1/Bug2
These bugs were found by partner and fixed above

Gardens(): Bug1
The bug report states the player gets 10 extra actions!  After reviewing the code, this is due to a for loop that gives two extra actions for every hand in they players deck. This for loop was removed

Gardens(): Bug2
The bug report states hand count does not decrease by 1.  After reviewing the code, it is obvious the card is not discard.  This was added to line 709

Gardens(): Bug3
The bug report states the discard/played deck does not increase by 1.  This is due the the same issue in Bug2 and was fixed by adding the discard to line 709.

Adventurer() Random Bug
This bug was found in random testing.  This happened in 52.6% of cases where the treasure count in the hand and discard/deck were off.  Since I remember adding the bug, it was easy to spot and fix.  In line 671, silver was incorrectly smithy, meaning it went until it drew 3 copper, gold or smithy (instead of silver).  Without the knowledge of adding the bug, I suspect this minor bug would have been difficult to spot.

Discussion: Since the tests were specific to which function and each function was only a handful of lines each, it was easy to spot and fix the bugs without having to look at coverage or use GDB.  The first couple of bugs, I used GDB but it seemed like an unecessary step since the bugs were easy to spot in the small functions.  I do have quite a bit of experience using debuggers (specificially stepping through C# code in visual studio), so I understand the great value and how to use it.  Additionally, the trickiest bug I found (smithy instead of silver in adventurer) was one I introduced, I remembered it and fixed it without issue.

Below are the results of my tests after fixing the bugs:

TESTING updateCoins() :
	All tests passed!
	File 'dominion.c'
	Lines executed : 36.91% of 569
	Branches executed : 43.88% of 417
	Taken at least once : 35.97% of 417
	Calls executed : 19.15% of 94
	Creating 'dominion.c.gcov'

	Testing getCost()All Tests Past!File 'dominion.c'
	Lines executed : 36.91% of 569
	Branches executed : 43.88% of 417
	Taken at least once : 35.97% of 417
	Calls executed : 19.15% of 94
	Creating 'dominion.c.gcov'

	TESTING isGameOver :
All tests passed!
File 'dominion.c'
Lines executed : 36.91% of 569
Branches executed : 43.88% of 417
Taken at least once : 35.97% of 417
Calls executed : 19.15% of 94
Creating 'dominion.c.gcov'

TESTING compare()
All test passed
File 'dominion.c'
Lines executed : 36.91% of 569
Branches executed : 43.88% of 417
Taken at least once : 35.97% of 417
Calls executed : 19.15% of 94
Creating 'dominion.c.gcov'

TESTING scoreFor()
All tests passed!
File 'dominion.c'
Lines executed : 36.91% of 569
Branches executed : 43.88% of 417
Taken at least once : 35.97% of 417
Calls executed : 19.15% of 94
Creating 'dominion.c.gcov'

TESTING smithy :
All tests passed!
File 'dominion.c'
Lines executed : 36.91% of 569
Branches executed : 43.88% of 417
Taken at least once : 35.97% of 417
Calls executed : 19.15% of 94
Creating 'dominion.c.gcov'

TESTING adventurer :
All tests passed!
File 'dominion.c'
Lines executed : 36.91% of 569
Branches executed : 43.88% of 417
Taken at least once : 35.97% of 417
Calls executed : 19.15% of 94
Creating 'dominion.c.gcov'

TESTING Gardens :
All tests passed!
File 'dominion.c'
Lines executed : 36.91% of 569
Branches executed : 43.88% of 417
Taken at least once : 35.97% of 417
Calls executed : 19.15% of 94
Creating 'dominion.c.gcov'

TESTING Village :
All tests passed!
File 'dominion.c'
Lines executed : 36.91% of 569
Branches executed : 43.88% of 417
Taken at least once : 35.97% of 417
Calls executed : 19.15% of 94
Creating 'dominion.c.gcov'

- : 0 : Source : dominion.c
- : 0 : Graph : dominion.gcno
- : 0 : Data : dominion.gcda
- : 0 : Runs : 27
- : 0 : Programs : 12
- : 1 : #include "dominion.h"
- : 2 : #include "dominion_helpers.h"
- : 3 : #include "rngs.h"
- : 4 : #include <stdio.h>
- : 5 : #include <math.h>
- : 6 : #include <stdlib.h>
- : 7 :
	function compare called 11271 returned 100 % blocks executed 100 %
	11271 : 8 : int compare(const void* a, const void* b) {
	11271:    9 : if (*(int*)a > *(int*)b)
		branch  0 taken 1 % (fallthrough)
		branch  1 taken 99 %
		9 : 10 : return 1;
	11262:   11 : if (*(int*)a < *(int*)b)
		branch  0 taken 27 % (fallthrough)
		branch  1 taken 73 %
		3009 : 12 : return -1;
	8253:   13 : return 0;
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
	function initializeGame called 375 returned 100 % blocks executed 88 %
	375 : 37 : int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
		-:   38 : struct gameState *state) {
	-:   39 :
		-: 40 : int i;
	-:   41 : int j;
	-:   42 : int it;
	-:   43 :  //set up random number generator
		375 : 44 : SelectStream(1);
	call    0 returned 100 %
		375:   45 : PutSeed((long)randomSeed);
	call    0 returned 100 %
		-:   46 :
		-: 47 :  //check number of players
		375 : 48 : if (numPlayers > MAX_PLAYERS || numPlayers < 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		branch  2 taken 0 % (fallthrough)
		branch  3 taken 100 %
		-: 49 : {
#####:   50:      return -1;
		-:   51 : }
	-: 52 :
		-: 53 :  //set number of players
		375 : 54 : state->numPlayers = numPlayers;
	-:   55 :
		-: 56 :  //check selected kingdom cards are different
		4125 : 57 : for (i = 0; i < 10; i++)
		branch  0 taken 91 %
		branch  1 taken 9 % (fallthrough)
		-: 58 : {
		41250:   59 : for (j = 0; j < 10; j++)
			branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			-: 60 : {
			37500:   61 : if (j != i && kingdomCards[j] == kingdomCards[i])
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
		375 : 73 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 74 : {
		375:   75 : state->supplyCount[curse] = 10;
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
		375 : 87 : if (numPlayers == 2)
		branch  0 taken 100 % (fallthrough)
		branch  1 taken 0 %
		-: 88 : {
		375:   89 : state->supplyCount[estate] = 8;
		375:   90 : state->supplyCount[duchy] = 8;
		375:   91 : state->supplyCount[province] = 8;
		-:   92 : }
	-: 93 : else
		- :   94 : {
#####:   95:      state->supplyCount[estate] = 12;
#####:   96:      state->supplyCount[duchy] = 12;
#####:   97:      state->supplyCount[province] = 12;
		-:   98 : }
	-: 99 :
		-: 100 :  //set number of Treasure cards
		375 : 101 : state->supplyCount[copper] = 60 - (7 * numPlayers);
	375:  102 : state->supplyCount[silver] = 40;
	375:  103 : state->supplyCount[gold] = 30;
	-:  104 :
		-: 105 :  //set number of Kingdom cards
		7875 : 106 : for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
		branch  0 taken 95 %
		branch  1 taken 5 % (fallthrough)
		-: 107 : {
		61875:  108 : for (j = 0; j < 10; j++)           		//loop chosen cards
			branch  0 taken 94 %
			branch  1 taken 6 % (fallthrough)
			-: 109 : {
			58125:  110 : if (kingdomCards[j] == i)
				branch  0 taken 6 % (fallthrough)
				branch  1 taken 94 %
				-: 111 : {
				-:  112 :	      //check if card is a 'Victory' Kingdom card
					3750 : 113 : if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
					branch  0 taken 90 % (fallthrough)
					branch  1 taken 10 %
					branch  2 taken 11 % (fallthrough)
					branch  3 taken 89 %
					-: 114 : {
					1500:  115 : if (numPlayers == 2) {
						branch  0 taken 100 % (fallthrough)
							branch  1 taken 0 %
							750:  116 : state->supplyCount[i] = 8;
						-:  117 :
					}
#####:  118:		  else{ state->supplyCount[i] = 12; }
					-:  119 : }
				-:  120 : else
					- :  121 : {
					3000:  122 : state->supplyCount[i] = 10;
					-:  123 : }
				3750 : 124 : break;
				-:  125 : }
			-:  126 : else    //card is not in the set choosen for the game
				- :  127 : {
				54375:  128 : state->supplyCount[i] = -1;
				-:  129 : }
			-: 130 : }
		-:  131 :
			-: 132 : }
	-:  133 :
		-: 134 :  ////////////////////////
		-: 135 :  //supply intilization complete
		-: 136 :
		-: 137 :  //set player decks
		1125 : 138 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 139 : {
		750:  140 : state->deckCount[i] = 0;
		3000:  141 : for (j = 0; j < 3; j++)
			branch  0 taken 75 %
			branch  1 taken 25 % (fallthrough)
			-: 142 : {
			2250:  143 : state->deck[i][j] = estate;
			2250:  144 : state->deckCount[i]++;
			-:  145 : }
		6000 : 146 : for (j = 3; j < 10; j++)
			branch  0 taken 88 %
			branch  1 taken 13 % (fallthrough)
			-: 147 : {
			5250:  148 : state->deck[i][j] = copper;
			5250:  149 : state->deckCount[i]++;
			-:  150 : }
		-: 151 : }
	-:  152 :
		-: 153 :  //shuffle player decks
		1125 : 154 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 155 : {
		750:  156 : if (shuffle(i, state) < 0)
			call    0 returned 100 %
			branch  1 taken 0 % (fallthrough)
			branch  2 taken 100 %
			-: 157 : {
#####:  158:	  return -1;
			-:  159 : }
		-: 160 : }
	-:  161 :
		-: 162 :  //draw player hands
		1125 : 163 : for (i = 0; i < numPlayers; i++)
		branch  0 taken 67 %
		branch  1 taken 33 % (fallthrough)
		-: 164 : {
		-:  165 :      //initialize hand size to zero
			750 : 166 : state->handCount[i] = 0;
		750:  167 : state->discardCount[i] = 0;
		-:  168 :      //draw 5 cards
			-: 169 :      // for (j = 0; j < 5; j++)
			-: 170 :      //	{
			-: 171 :      //	  drawCard(i, state);
			-: 172 :      //	}
			-: 173 : }
	-:  174 :
		-: 175 :  //set embargo tokens to 0 for all supply piles
		10500 : 176 : for (i = 0; i <= treasure_map; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 177 : {
		10125:  178 : state->embargoTokens[i] = 0;
		-:  179 : }
	-: 180 :
		-: 181 :  //initialize first player's turn
		375 : 182 : state->outpostPlayed = 0;
	375:  183 : state->phase = 0;
	375:  184 : state->numActions = 1;
	375:  185 : state->numBuys = 1;
	375:  186 : state->playedCardCount = 0;
	375:  187 : state->whoseTurn = 0;
	375:  188 : state->handCount[state->whoseTurn] = 0;
	-:  189 :  //int it; move to top
		-: 190 :
		-: 191 :  //Moved draw cards to here, only drawing at the start of a turn
		2250 : 192 : for (it = 0; it < 5; it++) {
		branch  0 taken 83 %
			branch  1 taken 17 % (fallthrough)
			1875:  193 : drawCard(state->whoseTurn, state);
		call    0 returned 100 %
			-:  194 :
	}
	-:  195 :
		375 : 196 : updateCoins(state->whoseTurn, state, 0);
	call    0 returned 100 %
		-:  197 :
		375 : 198 : return 0;
	-:  199 :
}
-:  200 :
	function shuffle called 750 returned 100 % blocks executed 94 %
	750 : 201 : int shuffle(int player, struct gameState *state) {
	-:  202 :
		-: 203 :
		-: 204 : int newDeck[MAX_DECK];
	750:  205 : int newDeckPos = 0;
	-:  206 : int card;
	-:  207 : int i;
	-:  208 :
		750 : 209 : if (state->deckCount[player] < 1)
		branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
#####:  210:    return -1;
		750:  211 : qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
	call    0 returned 100 %
		-:  212 :  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
		-: 213 :
		9000 : 214 : while (state->deckCount[player] > 0) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			7500:  215 : card = floor(Random() * state->deckCount[player]);
		call    0 returned 100 %
			7500:  216 : newDeck[newDeckPos] = state->deck[player][card];
		7500:  217 : newDeckPos++;
		26250:  218 : for (i = card; i < state->deckCount[player] - 1; i++) {
			branch  0 taken 71 %
				branch  1 taken 29 % (fallthrough)
				18750:  219 : state->deck[player][i] = state->deck[player][i + 1];
			-:  220 :
		}
		7500:  221 : state->deckCount[player]--;
		-:  222 :
	}
	8250:  223 : for (i = 0; i < newDeckPos; i++) {
		branch  0 taken 91 %
			branch  1 taken 9 % (fallthrough)
			7500:  224 : state->deck[player][i] = newDeck[i];
		7500:  225 : state->deckCount[player]++;
		-:  226 :
	}
	-:  227 :
		750 : 228 : return 0;
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
	function whoseTurn called 12 returned 100 % blocks executed 100 %
	12 : 346 : int whoseTurn(struct gameState *state) {
	12:  347 : return state->whoseTurn;
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
	function isGameOver called 21 returned 100 % blocks executed 100 %
	21 : 390 : int isGameOver(struct gameState *state) {
	-:  391 : int i;
	-:  392 : int j;
	-:  393 :
		-: 394 :  //if stack of Province cards is empty, the game ends
		21 : 395 : if (state->supplyCount[province] == 0)
		branch  0 taken 29 % (fallthrough)
		branch  1 taken 71 %
		-: 396 : {
		6:  397 : return 1;
		-:  398 : }
	-: 399 :
		-: 400 :  //if three supply pile are at 0, the game ends
		15 : 401 : j = 0;
	390:  402 : for (i = 0; i < 25; i++)
		branch  0 taken 96 %
		branch  1 taken 4 % (fallthrough)
		-: 403 : {
		375:  404 : if (state->supplyCount[i] == 0)
			branch  0 taken 8 % (fallthrough)
			branch  1 taken 92 %
			-: 405 : {
			30:  406 : j++;
			-:  407 : }
		-: 408 : }
	15:  409 : if (j >= 3)
		branch  0 taken 40 % (fallthrough)
		branch  1 taken 60 %
		-: 410 : {
		6:  411 : return 1;
		-:  412 : }
	-: 413 :
		9 : 414 : return 0;
	-:  415 :
}
-:  416 :
	function scoreFor called 27 returned 100 % blocks executed 100 %
	27 : 417 : int scoreFor(int player, struct gameState *state) {
	-:  418 :
		-: 419 : int i;
	27:  420 : int score = 0;
	-:  421 :  //score from hand
		144 : 422 : for (i = 0; i < state->handCount[player]; i++)
		branch  0 taken 81 %
		branch  1 taken 19 % (fallthrough)
		-: 423 : {
		117:  424 : if (state->hand[player][i] == curse) { score = score - 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			117:  425 : if (state->hand[player][i] == estate) { score = score + 1; };
		branch  0 taken 23 % (fallthrough)
			branch  1 taken 77 %
			117:  426 : if (state->hand[player][i] == duchy) { score = score + 3; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			117:  427 : if (state->hand[player][i] == province) { score = score + 6; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			117:  428 : if (state->hand[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 87 %
			117:  429 : if (state->hand[player][i] == gardens) {
			branch  0 taken 13 % (fallthrough)
				branch  1 taken 87 %
				15:  430 : score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
			-:  431 :
		};
		-:  432 : }
	-:  433 :
		-: 434 :  //score from discard
		147 : 435 : for (i = 0; i < state->discardCount[player]; i++)
		branch  0 taken 82 %
		branch  1 taken 18 % (fallthrough)
		-: 436 : {
		120:  437 : if (state->discard[player][i] == curse) { score = score - 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			120:  438 : if (state->discard[player][i] == estate) { score = score + 1; };
		branch  0 taken 25 % (fallthrough)
			branch  1 taken 75 %
			120:  439 : if (state->discard[player][i] == duchy) { score = score + 3; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			120:  440 : if (state->discard[player][i] == province) { score = score + 6; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			120:  441 : if (state->discard[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 13 % (fallthrough)
			branch  1 taken 88 %
			120:  442 : if (state->hand[player][i] == gardens) {
			branch  0 taken 13 % (fallthrough)
				branch  1 taken 88 %
				15:  443 : score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
			-:  444 :
		};
		-:  445 : }
	-:  446 :
		-: 447 :  //score from deck
		150 : 448 : for (i = 0; i < state->deckCount[player]; i++)
		branch  0 taken 82 %
		branch  1 taken 18 % (fallthrough)
		-: 449 : {
		123:  450 : if (state->deck[player][i] == curse) { score = score - 1; };
		branch  0 taken 12 % (fallthrough)
			branch  1 taken 88 %
			123:  451 : if (state->deck[player][i] == estate) { score = score + 1; };
		branch  0 taken 27 % (fallthrough)
			branch  1 taken 73 %
			123:  452 : if (state->deck[player][i] == duchy) { score = score + 3; };
		branch  0 taken 12 % (fallthrough)
			branch  1 taken 88 %
			123:  453 : if (state->deck[player][i] == province) { score = score + 6; };
		branch  0 taken 12 % (fallthrough)
			branch  1 taken 88 %
			123:  454 : if (state->deck[player][i] == great_hall) { score = score + 1; };
		branch  0 taken 12 % (fallthrough)
			branch  1 taken 88 %
			123:  455 : if (state->hand[player][i] == gardens) {
			branch  0 taken 12 % (fallthrough)
				branch  1 taken 88 %
				15:  456 : score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
			-:  457 :
		};
		-:  458 : }
	-:  459 :
		27 : 460 : return score;
	-:  461 :
}
-:  462 :
	function getWinners called 0 returned 0 % blocks executed 0 %
#####:  463:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
	-:  464 : int i;
-:  465 : int j;
-:  466 : int highScore;
-:  467 : int currentPlayer;
-:  468 :
	-: 469 :  //get score for each player
#####:  470:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 471 : {
	-:  472 :      //set unused player scores to -9999
#####:  473:      if (i >= state->numPlayers)
		branch  0 never executed
		branch  1 never executed
		- : 474 : {
#####:  475:	  players[i] = -9999;
		-:  476 : }
	-: 477 : else
		- :  478 : {
#####:  479:	  players[i] = scoreFor (i, state);
		call    0 never executed
			- :  480 : }
	-: 481 : }
-:  482 :
	-: 483 :  //find highest score
#####:  484:  j = 0;
#####:  485:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 486 : {
#####:  487:      if (players[i] > players[j])
	branch  0 never executed
		branch  1 never executed
		- : 488 : {
#####:  489:	  j = i;
		-:  490 : }
	-: 491 : }
#####:  492:  highScore = players[j];
-:  493 :
	-: 494 :  //add 1 to players who had less turns
#####:  495:  currentPlayer = whoseTurn(state);
	call    0 never executed
#####:  496:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 497 : {
#####:  498:      if ( players[i] == highScore && i > currentPlayer )
	branch  0 never executed
		branch  1 never executed
		branch  2 never executed
		branch  3 never executed
		- : 499 : {
#####:  500:	  players[i]++;
		-:  501 : }
	-: 502 : }
-:  503 :
	-: 504 :  //find new highest score
#####:  505:  j = 0;
#####:  506:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 507 : {
#####:  508:      if ( players[i] > players[j] )
	branch  0 never executed
		branch  1 never executed
		- : 509 : {
#####:  510:	  j = i;
		-:  511 : }
	-: 512 : }
#####:  513:  highScore = players[j];
-:  514 :
	-: 515 :  //set winners in array to 1 and rest to 0
#####:  516:  for (i = 0; i < MAX_PLAYERS; i++)
	branch  0 never executed
	branch  1 never executed
	- : 517 : {
#####:  518:      if ( players[i] == highScore )
	branch  0 never executed
		branch  1 never executed
		- : 519 : {
#####:  520:	  players[i] = 1;
		-:  521 : }
	-: 522 : else
		- :  523 : {
#####:  524:	  players[i] = 0;
		-:  525 : }
	-: 526 : }
-:  527 :
#####:  528:  return 0;
	-:  529 : }
-:  530 :
	function drawCard called 1893 returned 100 % blocks executed 38 %
	1893 : 531 : int drawCard(int player, struct gameState *state)
	- : 532 : {	int count;
-:  533 : int deckCounter;
1893:  534 : if (state->deckCount[player] <= 0) {//Deck is empty
	branch  0 taken 0 % (fallthrough)
		branch  1 taken 100 %
		-:  535 :
		-: 536 :    //Step 1 Shuffle the discard pile back into a deck
		-: 537 : int i;
	-:  538 :    //Move discard to deck
#####:  539:    for (i = 0; i < state->discardCount[player];i++){
		branch  0 never executed
		branch  1 never executed
#####:  540:      state->deck[player][i] = state->discard[player][i];
#####:  541:      state->discard[player][i] = -1;
		-:  542 : }
	-:  543 :
#####:  544:    state->deckCount[player] = state->discardCount[player];
#####:  545:    state->discardCount[player] = 0;//Reset discard
		-:  546 :
		-: 547 :    //Shufffle the deck
#####:  548:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
		call    0 never executed
		- :  549 :
		-: 550 : if (DEBUG) {//Debug statements
		-:  551 : printf("Deck count now: %d\n", state->deckCount[player]);
		-:  552 :
	}
	-: 553 :
#####:  554:    state->discardCount[player] = 0;
		-:  555 :
		-: 556 :    //Step 2 Draw Card
#####:  557:    count = state->handCount[player];//Get current player's hand count
		-:  558 :
		-: 559 : if (DEBUG) {//Debug statements
		-:  560 : printf("Current hand count: %d\n", count);
		-:  561 :
	}
	-: 562 :
#####:  563:    deckCounter = state->deckCount[player];//Create a holder for the deck count
		-:  564 :
#####:  565:    if (deckCounter == 0)
		branch  0 never executed
		branch  1 never executed
#####:  566:      return -1;
		-:  567 :
#####:  568:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
#####:  569:    state->deckCount[player]--;
#####:  570:    state->handCount[player]++;//Increment hand count
		-:  571 :
}
-:  572 :
	-: 573 : else {
	1893:  574 : int count = state->handCount[player];//Get current hand count for player
	-:  575 : int deckCounter;
	-:  576 : if (DEBUG) {//Debug statements
		-:  577 : printf("Current hand count: %d\n", count);
		-:  578 :
	}
	-: 579 :
		1893 : 580 : deckCounter = state->deckCount[player];//Create holder for the deck count
	1893:  581 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
	1893:  582 : state->deckCount[player]--;
	1893:  583 : state->handCount[player]++;//Increment hand count
	-:  584 :
}
-:  585 :
	1893 : 586 : return 0;
-:  587 : }
-:  588 :
	function getCost called 87 returned 100 % blocks executed 100 %
	87 : 589 : int getCost(int cardNumber)
	- : 590 : {
	87:  591 : switch (cardNumber)
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
		-:  592 : {
		-:  593 : case curse:
			3 : 594 : return 0;
			-:  595 : case estate:
				3 : 596 : return 2;
				-:  597 : case duchy:
					3 : 598 : return 5;
					-:  599 : case province:
						3 : 600 : return 8;
						-:  601 : case copper:
							3 : 602 : return 0;
							-:  603 : case silver:
								3 : 604 : return 3;
								-:  605 : case gold:
									3 : 606 : return 6;
									-:  607 : case adventurer:
										3 : 608 : return 6;
										-:  609 : case council_room:
											3 : 610 : return 5;
											-:  611 : case feast:
												3 : 612 : return 4;
												-:  613 : case gardens:
													3 : 614 : return 4;
													-:  615 : case mine:
														3 : 616 : return 5;
														-:  617 : case remodel:
															3 : 618 : return 4;
															-:  619 : case smithy:
																3 : 620 : return 4;
																-:  621 : case village:
																	3 : 622 : return 3;
																	-:  623 : case baron:
																		3 : 624 : return 4;
																		-:  625 : case great_hall:
																			3 : 626 : return 3;
																			-:  627 : case minion:
																				3 : 628 : return 5;
																				-:  629 : case steward:
																					3 : 630 : return 3;
																					-:  631 : case tribute:
																						3 : 632 : return 5;
																						-:  633 : case ambassador:
																							3 : 634 : return 3;
																							-:  635 : case cutpurse:
																								3 : 636 : return 4;
																								-:  637 : case embargo:
																									3 : 638 : return 2;
																									-:  639 : case outpost:
																										3 : 640 : return 5;
																										-:  641 : case salvager:
																											3 : 642 : return 4;
																											-:  643 : case sea_hag:
																												3 : 644 : return 4;
																												-:  645 : case treasure_map:
																													3 : 646 : return 4;
																													-:  647 : }
	-:  648 :
		6 : 649 : return -1;
	-:  650 : }
function playSmithy called 3 returned 100 % blocks executed 100 %
3:  651 : void playSmithy(int currentPlayer, struct gameState *state, int handPos)
- : 652 : {
	-:  653 : int i;
	-:  654 :	//+3 Cards
		12 : 655 : for (i = 0; i < 3; i++)
		branch  0 taken 75 %
		branch  1 taken 25 % (fallthrough)
		-: 656 : {
		9:  657 : drawCard(currentPlayer, state);
		call    0 returned 100 %
			-:  658 : }
	3 : 659 : discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100 %
		3:  660 : }
function playAdventurer called 3 returned 100 % blocks executed 67 %
3:  661 : void playAdventurer(int currentPlayer, struct gameState *state, int handPos)
- : 662 : {
	3:  663 : int z = 0;
	3:  664 : int drawntreasure = 0;
	-:  665 : int temphand[MAX_HAND];
	-:  666 : int cardDrawn;
	-:  667 :
		3 : 668 : discardCard(handPos, currentPlayer, state, 0);
	call    0 returned 100 %
		-:  669 :
		12 : 670 : while (drawntreasure<2) {
		branch  0 taken 67 %
			branch  1 taken 33 % (fallthrough)
			6:  671 : if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			branch  0 taken 0 % (fallthrough)
				branch  1 taken 100 %
#####:  672:			shuffle(currentPlayer, state);
				call    0 never executed
				- :  673 :
		}
		6:  674 : drawCard(currentPlayer, state);
		call    0 returned 100 %
			6:  675 : cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		6:  676 : if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			branch  2 never executed
			branch  3 never executed
			branch  4 never executed
			branch  5 never executed
			6:  677 : drawntreasure++;
		-:  678 : else {
#####:  679:			temphand[z] = cardDrawn;
#####:  680:			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
#####:  681:			z++;
			-:  682 :
		}
		-:  683 :
	}
	6:  684 : while (z - 1 >= 0) {
		branch  0 taken 0 %
			branch  1 taken 100 % (fallthrough)
#####:  685:		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
#####:  686:		z = z - 1;
			-:  687 :
	}
	3:  688 : }
function playCouncil_Room called 0 returned 0 % blocks executed 0 %
#####:  689:void playCouncil_Room(int currentPlayer, struct gameState *state, int handPos)
- : 690 : {
	-:  691 : int i;
#####:  692:	for (i = 0; i < 4; i++)
	branch  0 never executed
		branch  1 never executed
		- : 693 : {
#####:  694:		drawCard(currentPlayer, state);
		call    0 never executed
			- :  695 : }
	-: 696 :
#####:  697:	state->numBuys++;
		-:  698 :
#####:  699:	discardCard(handPos, currentPlayer, state, 0);
		call    0 never executed
		- :  700 :
		-: 701 :
		-: 702 :	//Each other player draws a card
#####:  703:	for (i = 0; i < state->numPlayers; i++)
		branch  0 never executed
		branch  1 never executed
		- : 704 : {
#####:  705:		if (i != currentPlayer)
		branch  0 never executed
			branch  1 never executed
			- : 706 : {
#####:  707:			drawCard(i, state);
			call    0 never executed
				- :  708 : }
		-: 709 : }
#####:  710:}
	function playGardens called 3 returned 100 % blocks executed 100 %
		3:  711 : void playGardens(int currentPlayer, struct gameState *state, int handPos)
		- : 712 : {
		3:  713 : discardCard(handPos, currentPlayer, state, 0);
		call    0 returned 100 %
			3:  714 : }
	function playMine called 0 returned 0 % blocks executed 0 %
#####:  715:void playMine(int choice1, int choice2, int currentPlayer, struct gameState *state, int handPos)
		- : 716 : {
		-:  717 : int i;
#####:  718:	int j = state->hand[currentPlayer][choice1];  //store card we will trash
		-:  719 :
#####:  720:	if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
			branch  0 never executed
			branch  1 never executed
			branch  2 never executed
			branch  3 never executed
			- : 721 : {
#####:  722:		return -1;
			-:  723 : }
		-: 724 :
#####:  725:	if (choice2 > treasure_map || choice2 < curse)
			branch  0 never executed
			branch  1 never executed
			branch  2 never executed
			branch  3 never executed
			- : 726 : {
#####:  727:		return -1;
			-:  728 : }
		-: 729 :
#####:  730:	if ((getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2))
			call    0 never executed
			call    1 never executed
			branch  2 never executed
			branch  3 never executed
			- : 731 : {
#####:  732:		return -1;
			-:  733 : }
		-: 734 :
#####:  735:	gainCard(choice2, state, 2, currentPlayer);
			call    0 never executed
			- :  736 :
			-: 737 :	//discard card from hand
#####:  738:	discardCard(handPos, currentPlayer, state, 0);
			call    0 never executed
			- :  739 :
			-: 740 :	//discard trashed card
#####:  741:	for (i = 0; i < state->handCount[currentPlayer]; i++)
			branch  0 never executed
			branch  1 never executed
			- : 742 : {
#####:  743:		if (state->hand[currentPlayer][i] == j)
			branch  0 never executed
				branch  1 never executed
				- : 744 : {
#####:  745:			discardCard(i, currentPlayer, state, 0);
				call    0 never executed
#####:  746:			break;
					-:  747 : }
			-: 748 : }
		-:  749 :
			-: 750 : }
	function cardEffect called 12 returned 100 % blocks executed 6 %
		12:  751 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
		- : 752 : {
		-:  753 : int i;
		-:  754 : int j;
		-:  755 : int k;
		-:  756 : int x;
		-:  757 : int index;
		12:  758 : int currentPlayer = whoseTurn(state);
		call    0 returned 100 %
			12:  759 : int nextPlayer = currentPlayer + 1;
		-:  760 :
			12 : 761 : int tributeRevealedCards[2] = { -1, -1 };
		-:  762 : int temphand[MAX_HAND];// moved above the if statement
		12:  763 : int drawntreasure = 0;
		-:  764 : int cardDrawn;
		12:  765 : int z = 0;// this is the counter for the temp hand
		12:  766 : if (nextPlayer > (state->numPlayers - 1)) {
			branch  0 taken 0 % (fallthrough)
				branch  1 taken 100 %
#####:  767:    nextPlayer = 0;
				-:  768 :
		}
		-:  769 :
			-: 770 :
			-: 771 :  //uses switch to select card and perform actions
			12 : 772 : switch (card)
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
			-:  773 : {
			-:  774 : case adventurer:
				3 : 775 : playAdventurer(currentPlayer, state, handPos);
				call    0 returned 100 %
					3:  776 : return 0;
				-:  777 :
					-: 778 : case council_room:
#####:  779:	  playCouncil_Room(currentPlayer, state, handPos);
						call    0 never executed
#####:  780:      return 0;
							-:  781 :
							-: 782 : case feast:
								-: 783 :      //gain card with cost up to 5
									-: 784 :      //Backup hand
#####:  785:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
									branch  0 never executed
									branch  1 never executed
#####:  786:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####:  787:	state->hand[currentPlayer][i] = -1;//Set to nothing
									-:  788 : }
								-:  789 :      //Backup hand
									-: 790 :
									-: 791 :      //Update Coins for Buy
#####:  792:      updateCoins(currentPlayer, state, 5);
									call    0 never executed
#####:  793:      x = 1;//Condition to loop on
#####:  794:      while( x == 1) {//Buy one card
									branch  0 never executed
									branch  1 never executed
#####:  795:	if (supplyCount(choice1, state) <= 0){
									call    0 never executed
									branch  1 never executed
									branch  2 never executed
									- :  796 : if (DEBUG)
									-: 797 : printf("None of that card left, sorry!\n");
								-:  798 :
									-: 799 : if (DEBUG) {
									-:  800 : printf("Cards Left: %d\n", supplyCount(choice1, state));
									-:  801 :
								}
								-: 802 : }
#####:  803:	else if (state->coins < getCost(choice1)){
									call    0 never executed
									branch  1 never executed
									branch  2 never executed
#####:  804:	  printf("That card is too expensive!\n");
									call    0 never executed
									- :  805 :
									-: 806 : if (DEBUG) {
									-:  807 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
									-:  808 :
								}
								-: 809 : }
								-:  810 : else {
									-:  811 :
										-: 812 : if (DEBUG) {
										-:  813 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
										-:  814 :
									}
									-: 815 :
#####:  816:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
										call    0 never executed
#####:  817:	  x = 0;//No more buying cards
										-:  818 :
										-: 819 : if (DEBUG) {
										-:  820 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
										-:  821 :
									}
									-: 822 :
										-: 823 :
								}
								-:  824 : }
									-:  825 :
									-: 826 :      //Reset Hand
#####:  827:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
									branch  0 never executed
									branch  1 never executed
#####:  828:	state->hand[currentPlayer][i] = temphand[i];
#####:  829:	temphand[i] = -1;
									-:  830 : }
								-:  831 :      //Reset Hand
									-: 832 :
#####:  833:      return 0;
									-:  834 :
									-: 835 : case gardens:
										3 : 836 : playGardens(currentPlayer, state, handPos);
										call    0 returned 100 %
											3:  837 : return -1;
										-:  838 :
											-: 839 : case mine:
#####:  840:	  playMine(choice1, choice2, currentPlayer, state, handPos);
												call    0 never executed
#####:  841:      return 0;
													-:  842 :
													-: 843 : case remodel:
#####:  844:      j = state->hand[currentPlayer][choice1];  //store card we will trash
														-:  845 :
#####:  846:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
															call    0 never executed
															call    1 never executed
															branch  2 never executed
															branch  3 never executed
															- : 847 : {
#####:  848:	  return -1;
															-:  849 : }
														-: 850 :
#####:  851:      gainCard(choice2, state, 0, currentPlayer);
															call    0 never executed
															- :  852 :
															-: 853 :      //discard card from hand
#####:  854:      discardCard(handPos, currentPlayer, state, 0);
															call    0 never executed
															- :  855 :
															-: 856 :      //discard trashed card
#####:  857:      for (i = 0; i < state->handCount[currentPlayer]; i++)
															branch  0 never executed
															branch  1 never executed
															- : 858 : {
#####:  859:	  if (state->hand[currentPlayer][i] == j)
															branch  0 never executed
																branch  1 never executed
																- : 860 : {
#####:  861:	      discardCard(i, currentPlayer, state, 0);			
																call    0 never executed
#####:  862:	      break;
																	-:  863 : }
															-: 864 : }
														-:  865 :
															-: 866 :
#####:  867:      return 0;
															-:  868 :
															-: 869 : case smithy:
																3 : 870 : playSmithy(currentPlayer, state, handPos);
																call    0 returned 100 %
																	3:  871 : return 0;
																-:  872 :
																	-: 873 : case village:
																		-: 874 :      //+1 Card
																			3 : 875 : drawCard(currentPlayer, state);
																		call    0 returned 100 %
																			-:  876 :
																			-: 877 :      //+2 Actions
																			3 : 878 : state->numActions = state->numActions + 2;
																		-:  879 :
																			-: 880 :      //discard played card from hand
																			3 : 881 : discardCard(handPos, currentPlayer, state, 0);
																		call    0 returned 100 %
																			3:  882 : return 0;
																		-:  883 :
																			-: 884 : case baron:
#####:  885:      state->numBuys++;//Increase buys by 1!
#####:  886:      if (choice1 > 0){//Boolean true or going to discard an estate
																				branch  0 never executed
																					branch  1 never executed
#####:  887:	int p = 0;//Iterator for hand!
#####:  888:	int card_not_discarded = 1;//Flag for discard set!
#####:  889:	while(card_not_discarded){
																					branch  0 never executed
																					branch  1 never executed
#####:  890:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																					branch  0 never executed
																					branch  1 never executed
#####:  891:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  892:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  893:	    state->discardCount[currentPlayer]++;
#####:  894:	    for (;p < state->handCount[currentPlayer]; p++){
																					branch  0 never executed
																					branch  1 never executed
#####:  895:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																					-:  896 : }
#####:  897:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  898:	    state->handCount[currentPlayer]--;
#####:  899:	    card_not_discarded = 0;//Exit the loop
																					-:  900 : }
#####:  901:	  else if (p > state->handCount[currentPlayer]){
																					branch  0 never executed
																					branch  1 never executed
																					- :  902 : if (DEBUG) {
																					-:  903 : printf("No estate cards in your hand, invalid choice\n");
																					-:  904 : printf("Must gain an estate if there are any\n");
																					-:  905 :
																				}
#####:  906:	    if (supplyCount(estate, state) > 0){
																				call    0 never executed
																					branch  1 never executed
																					branch  2 never executed
#####:  907:	      gainCard(estate, state, 0, currentPlayer);
																					call    0 never executed
#####:  908:	      state->supplyCount[estate]--;//Decrement estates
#####:  909:	      if (supplyCount(estate, state) == 0){
																					call    0 never executed
																					branch  1 never executed
																					branch  2 never executed
#####:  910:		isGameOver(state);
																					call    0 never executed
																					- :  911 : }
																					-:  912 : }
#####:  913:	    card_not_discarded = 0;//Exit the loop
																					-:  914 : }
																				-:  915 :
																					-: 916 : else {
#####:  917:	    p++;//Next card
																					-:  918 :
																				}
																				-:  919 : }
																					-:  920 : }
																		-:  921 :
																			-: 922 : else {
#####:  923:	if (supplyCount(estate, state) > 0){
																			call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  924:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																				call    0 never executed
#####:  925:	  state->supplyCount[estate]--;//Decrement Estates
#####:  926:	  if (supplyCount(estate, state) == 0){
																				call    0 never executed
																				branch  1 never executed
																				branch  2 never executed
#####:  927:	    isGameOver(state);
																				call    0 never executed
																				- :  928 : }
																				-:  929 : }
																		-:  930 :
																		}
																		-:  931 :
																			-: 932 :
#####:  933:      return 0;
																			-:  934 :
																			-: 935 : case great_hall:
																				-: 936 :      //+1 Card
#####:  937:      drawCard(currentPlayer, state);
																					call    0 never executed
																					- :  938 :
																					-: 939 :      //+1 Actions
#####:  940:      state->numActions++;
																					-:  941 :
																					-: 942 :      //discard card from hand
#####:  943:      discardCard(handPos, currentPlayer, state, 0);
																					call    0 never executed
#####:  944:      return 0;
																					-:  945 :
																					-: 946 : case minion:
																						-: 947 :      //+1 action
#####:  948:      state->numActions++;
																							-:  949 :
																							-: 950 :      //discard card from hand
#####:  951:      discardCard(handPos, currentPlayer, state, 0);
																							call    0 never executed
																							- :  952 :
#####:  953:      if (choice1)		//+2 coins
																							branch  0 never executed
																							branch  1 never executed
																							- : 954 : {
#####:  955:	  state->coins = state->coins + 2;
																							-:  956 : }
																						-: 957 :
#####:  958:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																							branch  0 never executed
																							branch  1 never executed
																							- :  959 : {
																							-:  960 :	  //discard hand
#####:  961:	  while(numHandCards(state) > 0)
																								call    0 never executed
																								branch  1 never executed
																								branch  2 never executed
																								- : 962 : {
#####:  963:	      discardCard(handPos, currentPlayer, state, 0);
																								call    0 never executed
																									- :  964 : }
																							-: 965 :
																								-: 966 :	  //draw 4
#####:  967:	  for (i = 0; i < 4; i++)
																								branch  0 never executed
																								branch  1 never executed
																								- : 968 : {
#####:  969:	      drawCard(currentPlayer, state);
																								call    0 never executed
																									- :  970 : }
																							-: 971 :
																								-: 972 :	  //other players discard hand and redraw if hand size > 4
#####:  973:	  for (i = 0; i < state->numPlayers; i++)
																								branch  0 never executed
																								branch  1 never executed
																								- : 974 : {
#####:  975:	      if (i != currentPlayer)
																								branch  0 never executed
																									branch  1 never executed
																									- : 976 : {
#####:  977:		  if ( state->handCount[i] > 4 )
																									branch  0 never executed
																										branch  1 never executed
																										- : 978 : {
																										-:  979 :		      //discard hand
#####:  980:		      while( state->handCount[i] > 0 )
																											branch  0 never executed
																											branch  1 never executed
																											- : 981 : {
#####:  982:			  discardCard(handPos, i, state, 0);
																											call    0 never executed
																												- :  983 : }
																										-: 984 :
																											-: 985 :		      //draw 4
#####:  986:		      for (j = 0; j < 4; j++)
																											branch  0 never executed
																											branch  1 never executed
																											- : 987 : {
#####:  988:			  drawCard(i, state);
																											call    0 never executed
																												- :  989 : }
																										-: 990 : }
																									-:  991 : }
																								-:  992 : }
																							-:  993 :
																								-: 994 : }
#####:  995:      return 0;
																						-:  996 :
																							-: 997 : case steward:
#####:  998:      if (choice1 == 1)
																								branch  0 never executed
																									branch  1 never executed
																									- : 999 : {
																									-: 1000 :	  //+2 cards
#####: 1001:	  drawCard(currentPlayer, state);
																										call    0 never executed
#####: 1002:	  drawCard(currentPlayer, state);
																										call    0 never executed
																										- : 1003 : }
#####: 1004:      else if (choice1 == 2)
																								branch  0 never executed
																									branch  1 never executed
																									- : 1005 : {
																									-: 1006 :	  //+2 coins
#####: 1007:	  state->coins = state->coins + 2;
																										-: 1008 : }
																								-: 1009 : else
																									- : 1010 : {
																									-: 1011 :	  //trash 2 cards in hand
#####: 1012:	  discardCard(choice2, currentPlayer, state, 1);
																										call    0 never executed
#####: 1013:	  discardCard(choice3, currentPlayer, state, 1);
																										call    0 never executed
																										- : 1014 : }
																								-: 1015 :
																									-: 1016 :      //discard card from hand
#####: 1017:      discardCard(handPos, currentPlayer, state, 0);
																									call    0 never executed
#####: 1018:      return 0;
																									-: 1019 :
																									-: 1020 : case tribute:
#####: 1021:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																										branch  0 never executed
																											branch  1 never executed
#####: 1022:	if (state->deckCount[nextPlayer] > 0){
																											branch  0 never executed
																											branch  1 never executed
#####: 1023:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1024:	  state->deckCount[nextPlayer]--;
																											-: 1025 : }
#####: 1026:	else if (state->discardCount[nextPlayer] > 0){
																											branch  0 never executed
																											branch  1 never executed
#####: 1027:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####: 1028:	  state->discardCount[nextPlayer]--;
																											-: 1029 : }
																										-: 1030 : else {
																											-: 1031 :	  //No Card to Reveal
																												-: 1032 : if (DEBUG) {
																												-: 1033 : printf("No cards to reveal\n");
																												-: 1034 :
																											}
																											-: 1035 :
																										}
																										-: 1036 : }
																								-: 1037 :
																									-: 1038 : else {
#####: 1039:	if (state->deckCount[nextPlayer] == 0){
																									branch  0 never executed
																										branch  1 never executed
#####: 1040:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																										branch  0 never executed
																										branch  1 never executed
#####: 1041:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####: 1042:	    state->deckCount[nextPlayer]++;
#####: 1043:	    state->discard[nextPlayer][i] = -1;
#####: 1044:	    state->discardCount[nextPlayer]--;
																										-: 1045 : }
																										-: 1046 :
#####: 1047:	  shuffle(nextPlayer,state);//Shuffle the deck
																										call    0 never executed
																										- : 1048 : }
#####: 1049:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1050:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1051:	state->deckCount[nextPlayer]--;
#####: 1052:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1053:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1054:	state->deckCount[nextPlayer]--;
																								-: 1055 :
																								}
																								-: 1056 :
#####: 1057:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																									branch  0 never executed
																									branch  1 never executed
#####: 1058:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####: 1059:	state->playedCardCount++;
#####: 1060:	tributeRevealedCards[1] = -1;
																									-: 1061 : }
																								-: 1062 :
#####: 1063:      for (i = 0; i <= 2; i ++){
																									branch  0 never executed
																									branch  1 never executed
#####: 1064:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																									branch  0 never executed
																									branch  1 never executed
																									branch  2 never executed
																									branch  3 never executed
																									branch  4 never executed
																									branch  5 never executed
#####: 1065:	  state->coins += 2;
																									-: 1066 : }
																									-: 1067 :
#####: 1068:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
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
#####: 1069:	  drawCard(currentPlayer, state);
																									call    0 never executed
#####: 1070:	  drawCard(currentPlayer, state);
																									call    0 never executed
																									- : 1071 : }
																								-: 1072 : else {//Action Card
#####: 1073:	  state->numActions = state->numActions + 2;
																									-: 1074 :
																								}
																								-: 1075 : }
																								-: 1076 :
#####: 1077:      return 0;
																									-: 1078 :
																									-: 1079 : case ambassador:
#####: 1080:      j = 0;		//used to check if player has enough cards to discard
																										-: 1081 :
#####: 1082:      if (choice2 > 2 || choice2 < 0)
																											branch  0 never executed
																											branch  1 never executed
																											branch  2 never executed
																											branch  3 never executed
																											- : 1083 : {
#####: 1084:	  return -1;				
																											-: 1085 : }
																										-: 1086 :
#####: 1087:      if (choice1 == handPos)
																											branch  0 never executed
																											branch  1 never executed
																											- : 1088 : {
#####: 1089:	  return -1;
																											-: 1090 : }
																										-: 1091 :
#####: 1092:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																											branch  0 never executed
																											branch  1 never executed
																											- : 1093 : {
#####: 1094:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																											branch  0 never executed
																												branch  1 never executed
																												branch  2 never executed
																												branch  3 never executed
																												branch  4 never executed
																												branch  5 never executed
																												- : 1095 : {
#####: 1096:	      j++;
																												-: 1097 : }
																											-: 1098 : }
#####: 1099:      if (j < choice2)
																										branch  0 never executed
																											branch  1 never executed
																											- : 1100 : {
#####: 1101:	  return -1;				
																											-: 1102 : }
																										-: 1103 :
																											-: 1104 : if (DEBUG)
																											-: 1105 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																										-: 1106 :
																											-: 1107 :      //increase supply count for choosen card by amount being discarded
#####: 1108:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																											-: 1109 :
																											-: 1110 :      //each other player gains a copy of revealed card
#####: 1111:      for (i = 0; i < state->numPlayers; i++)
																											branch  0 never executed
																											branch  1 never executed
																											- : 1112 : {
#####: 1113:	  if (i != currentPlayer)
																											branch  0 never executed
																												branch  1 never executed
																												- : 1114 : {
#####: 1115:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																												call    0 never executed
																													- : 1116 : }
																											-: 1117 : }
																										-: 1118 :
																											-: 1119 :      //discard played card from hand
#####: 1120:      discardCard(handPos, currentPlayer, state, 0);			
																											call    0 never executed
																											- : 1121 :
																											-: 1122 :      //trash copies of cards returned to supply
#####: 1123:      for (j = 0; j < choice2; j++)
																											branch  0 never executed
																											branch  1 never executed
																											- : 1124 : {
#####: 1125:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																											branch  0 never executed
																												branch  1 never executed
																												- : 1126 : {
#####: 1127:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																												branch  0 never executed
																													branch  1 never executed
																													- : 1128 : {
#####: 1129:		  discardCard(i, currentPlayer, state, 1);
																													call    0 never executed
#####: 1130:		  break;
																														-: 1131 : }
																												-: 1132 : }
																											-: 1133 : }
																										-: 1134 :
#####: 1135:      return 0;
																											-: 1136 :
																											-: 1137 : case cutpurse:
																												-: 1138 :
#####: 1139:      updateCoins(currentPlayer, state, 2);
																													call    0 never executed
#####: 1140:      for (i = 0; i < state->numPlayers; i++)
																													branch  0 never executed
																													branch  1 never executed
																													- : 1141 : {
#####: 1142:	  if (i != currentPlayer)
																													branch  0 never executed
																														branch  1 never executed
																														- : 1143 : {
#####: 1144:	      for (j = 0; j < state->handCount[i]; j++)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1145 : {
#####: 1146:		  if (state->hand[i][j] == copper)
																															branch  0 never executed
																																branch  1 never executed
																																- : 1147 : {
#####: 1148:		      discardCard(j, i, state, 0);
																																call    0 never executed
#####: 1149:		      break;
																																	-: 1150 : }
#####: 1151:		  if (j == state->handCount[i])
																															branch  0 never executed
																																branch  1 never executed
																																- : 1152 : {
#####: 1153:		      for (k = 0; k < state->handCount[i]; k++)
																																branch  0 never executed
																																	branch  1 never executed
																																	- : 1154 : {
																																	-: 1155 : if (DEBUG)
																																		-: 1156 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																	-: 1157 : }
#####: 1158:		      break;
																																-: 1159 : }
																															-: 1160 : }
																														-: 1161 :
																															-: 1162 : }
																													-: 1163 :
																														-: 1164 : }
																												-: 1165 :
																													-: 1166 :      //discard played card from hand
#####: 1167:      discardCard(handPos, currentPlayer, state, 0);			
																													call    0 never executed
																													- : 1168 :
#####: 1169:      return 0;
																													-: 1170 :
																													-: 1171 :
																													-: 1172 : case embargo:
																														-: 1173 :      //+2 Coins
#####: 1174:      state->coins = state->coins + 2;
																															-: 1175 :
																															-: 1176 :      //see if selected pile is in play
#####: 1177:      if ( state->supplyCount[choice1] == -1 )
																															branch  0 never executed
																															branch  1 never executed
																															- : 1178 : {
#####: 1179:	  return -1;
																															-: 1180 : }
																														-: 1181 :
																															-: 1182 :      //add embargo token to selected supply pile
#####: 1183:      state->embargoTokens[choice1]++;
																															-: 1184 :
																															-: 1185 :      //trash card
#####: 1186:      discardCard(handPos, currentPlayer, state, 1);		
																															call    0 never executed
#####: 1187:      return 0;
																															-: 1188 :
																															-: 1189 : case outpost:
																																-: 1190 :      //set outpost flag
#####: 1191:      state->outpostPlayed++;
																																	-: 1192 :
																																	-: 1193 :      //discard card
#####: 1194:      discardCard(handPos, currentPlayer, state, 0);
																																	call    0 never executed
#####: 1195:      return 0;
																																	-: 1196 :
																																	-: 1197 : case salvager:
																																		-: 1198 :      //+1 buy
#####: 1199:      state->numBuys++;
																																			-: 1200 :
#####: 1201:      if (choice1)
																																			branch  0 never executed
																																			branch  1 never executed
																																			- : 1202 : {
																																			-: 1203 :	  //gain coins equal to trashed card
#####: 1204:	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																				call    0 never executed
																																				call    1 never executed
																																				- : 1205 :	  //trash card
#####: 1206:	  discardCard(choice1, currentPlayer, state, 1);	
																																				call    0 never executed
																																				- : 1207 : }
																																		-: 1208 :
																																			-: 1209 :      //discard card
#####: 1210:      discardCard(handPos, currentPlayer, state, 0);
																																			call    0 never executed
#####: 1211:      return 0;
																																			-: 1212 :
																																			-: 1213 : case sea_hag:
#####: 1214:      for (i = 0; i < state->numPlayers; i++){
																																				branch  0 never executed
																																					branch  1 never executed
#####: 1215:	if (i != currentPlayer){
																																					branch  0 never executed
																																					branch  1 never executed
#####: 1216:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####: 1217:	  state->discardCount[i]++;
#####: 1218:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																					-: 1219 : }
																																					-: 1220 : }
#####: 1221:      return 0;
																																		-: 1222 :
																																			-: 1223 : case treasure_map:
																																				-: 1224 :      //search hand for another treasure_map
#####: 1225:      index = -1;
#####: 1226:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																					branch  0 never executed
																																					branch  1 never executed
																																					- : 1227 : {
#####: 1228:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																					branch  0 never executed
																																						branch  1 never executed
																																						branch  2 never executed
																																						branch  3 never executed
																																						- : 1229 : {
#####: 1230:	      index = i;
#####: 1231:	      break;
																																						-: 1232 : }
																																					-: 1233 : }
#####: 1234:      if (index > -1)
																																				branch  0 never executed
																																					branch  1 never executed
																																					- : 1235 : {
																																					-: 1236 :	  //trash both treasure cards
#####: 1237:	  discardCard(handPos, currentPlayer, state, 1);
																																						call    0 never executed
#####: 1238:	  discardCard(index, currentPlayer, state, 1);
																																						call    0 never executed
																																						- : 1239 :
																																						-: 1240 :	  //gain 4 Gold cards
#####: 1241:	  for (i = 0; i < 4; i++)
																																						branch  0 never executed
																																						branch  1 never executed
																																						- : 1242 : {
#####: 1243:	      gainCard(gold, state, 1, currentPlayer);
																																						call    0 never executed
																																							- : 1244 : }
																																					-: 1245 :
																																						-: 1246 :	  //return success
#####: 1247:	  return 1;
																																						-: 1248 : }
																																				-: 1249 :
																																					-: 1250 :      //no second treasure_map found in hand
#####: 1251:      return -1;
																																					-: 1252 : }
		-: 1253 :
#####: 1254:  return -1;
			-: 1255 : }
	-: 1256 :
		function discardCard called 12 returned 100 % blocks executed 78 %
		12 : 1257 : int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
		- : 1258 : {
		-: 1259 :
			-: 1260 :  //if card is not trashed, added to Played pile 
			12 : 1261 : if (trashFlag < 1)
			branch  0 taken 100 % (fallthrough)
			branch  1 taken 0 %
			-: 1262 : {
			-: 1263 :      //add card to played pile
				12 : 1264 : state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
			12: 1265 : state->playedCardCount++;
			-: 1266 : }
		-: 1267 :
			-: 1268 :  //set played card to -1
			12 : 1269 : state->hand[currentPlayer][handPos] = -1;
		-: 1270 :
			-: 1271 :  //remove card from player's hand
			12 : 1272 : if (handPos == (state->handCount[currentPlayer] - 1)) 	//last card in hand array is played
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1273 : {
			-: 1274 :      //reduce number of cards in hand
#####: 1275:      state->handCount[currentPlayer]--;
				-: 1276 : }
		12 : 1277 : else if (state->handCount[currentPlayer] == 1) //only one card in hand
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
			-: 1278 : {
			-: 1279 :      //reduce number of cards in hand
#####: 1280:      state->handCount[currentPlayer]--;
				-: 1281 : }
		-: 1282 : else
			- : 1283 : {
			-: 1284 :      //replace discarded card with last card in hand
				12 : 1285 : state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
			-: 1286 :      //set last card to -1
				12 : 1287 : state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
			-: 1288 :      //reduce number of cards in hand
				12 : 1289 : state->handCount[currentPlayer]--;
			-: 1290 : }
		-: 1291 :
			12 : 1292 : return 0;
		-: 1293 : }
	-: 1294 :
		function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1295:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
		- : 1296 : {
		-: 1297 :  //Note: supplyPos is enum of choosen card
			-: 1298 :
			-: 1299 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1300:  if ( supplyCount(supplyPos, state) < 1 )
			call    0 never executed
			branch  1 never executed
			branch  2 never executed
			- : 1301 : {
#####: 1302:      return -1;
			-: 1303 : }
		-: 1304 :
			-: 1305 :  //added card for [whoseTurn] current player:
			-: 1306 :  // toFlag = 0 : add to discard
			-: 1307 :  // toFlag = 1 : add to deck
			-: 1308 :  // toFlag = 2 : add to hand
			-: 1309 :
#####: 1310:  if (toFlag == 1)
			branch  0 never executed
			branch  1 never executed
			- : 1311 : {
#####: 1312:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1313:      state->deckCount[player]++;
			-: 1314 : }
#####: 1315:  else if (toFlag == 2)
		branch  0 never executed
			branch  1 never executed
			- : 1316 : {
#####: 1317:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1318:      state->handCount[player]++;
			-: 1319 : }
		-: 1320 : else
			- : 1321 : {
#####: 1322:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1323:      state->discardCount[player]++;
			-: 1324 : }
		-: 1325 :
			-: 1326 :  //decrease number in supply pile
#####: 1327:  state->supplyCount[supplyPos]--;
			-: 1328 :
#####: 1329:  return 0;
			-: 1330 : }
	-: 1331 :
		function updateCoins called 1695 returned 100 % blocks executed 100 %
		1695 : 1332 : int updateCoins(int player, struct gameState *state, int bonus)
		- : 1333 : {
		-: 1334 : int i;
		-: 1335 :
			-: 1336 :  //reset coin count
			1695 : 1337 : state->coins = 0;
		-: 1338 :
			-: 1339 :  //add coins for each Treasure card in player's hand
			7530 : 1340 : for (i = 0; i < state->handCount[player]; i++)
			branch  0 taken 77 %
			branch  1 taken 23 % (fallthrough)
			-: 1341 : {
			5835: 1342 : if (state->hand[player][i] == copper)
				branch  0 taken 43 % (fallthrough)
				branch  1 taken 57 %
				-: 1343 : {
				2490: 1344 : state->coins += 1;
				-: 1345 : }
			3345 : 1346 : else if (state->hand[player][i] == silver)
				branch  0 taken 30 % (fallthrough)
				branch  1 taken 70 %
				-: 1347 : {
				990: 1348 : state->coins += 2;
				-: 1349 : }
			2355 : 1350 : else if (state->hand[player][i] == gold)
				branch  0 taken 42 % (fallthrough)
				branch  1 taken 58 %
				-: 1351 : {
				990: 1352 : state->coins += 3;
				-: 1353 : }
			-: 1354 : }
		-: 1355 :
			-: 1356 :  //add bonus
			1695 : 1357 : state->coins += bonus;
		-: 1358 :
			1695 : 1359 : return 0;
		-: 1360 :
			-: 1361 : }
	-: 1362 :
		-: 1363 :
		-: 1364 :
		-: 1365 ://end of dominion.c
		-: 1366 :

		---- - ADVENTURER RESULTS : ---- -
		In 1000 tests...
		Success : 991
		Error in Actions : 0
		Error in Buys : 8
		Error in Coins : 0
		Error in Hand Count : 0
		Error in Discard + Deck + Played Count : 0
		Error in Treasure Cards in Hand : 9
		Error in Treausre Cards in Discard + Deck + Played : 0
		Error in Supplies : 0
		Error in Opponents Deck : 0
		Error in Opponents Discard : 0
		File 'dominion.c'
		Lines executed : 25.66% of 569
		Branches executed : 26.62% of 417
		Taken at least once : 18.71% of 417
		Calls executed : 13.83% of 94
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
		function compare called 67066 returned 100 % blocks executed 100 %
		67066 : 8 : int compare(const void* a, const void* b) {
		67066:    9 : if (*(int*)a > *(int*)b)
			branch  0 taken 28 % (fallthrough)
			branch  1 taken 72 %
			18786 : 10 : return 1;
		48280:   11 : if (*(int*)a < *(int*)b)
			branch  0 taken 40 % (fallthrough)
			branch  1 taken 60 %
			19231 : 12 : return -1;
		29049:   13 : return 0;
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
		function shuffle called 2250 returned 100 % blocks executed 100 %
		2250 : 201 : int shuffle(int player, struct gameState *state) {
		-:  202 :
			-: 203 :
			-: 204 : int newDeck[MAX_DECK];
		2250:  205 : int newDeckPos = 0;
		-:  206 : int card;
		-:  207 : int i;
		-:  208 :
			2250 : 209 : if (state->deckCount[player] < 1)
			branch  0 taken 6 % (fallthrough)
			branch  1 taken 94 %
			125 : 210 : return -1;
		2125:  211 : qsort((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare);
		call    0 returned 100 %
			-:  212 :  /* SORT CARDS IN DECK TO ENSURE DETERMINISM! */
			-: 213 :
			31918 : 214 : while (state->deckCount[player] > 0) {
			branch  0 taken 93 %
				branch  1 taken 7 % (fallthrough)
				27668:  215 : card = floor(Random() * state->deckCount[player]);
			call    0 returned 100 %
				27668:  216 : newDeck[newDeckPos] = state->deck[player][card];
			27668:  217 : newDeckPos++;
			202933:  218 : for (i = card; i < state->deckCount[player] - 1; i++) {
				branch  0 taken 86 %
					branch  1 taken 14 % (fallthrough)
					175265:  219 : state->deck[player][i] = state->deck[player][i + 1];
				-:  220 :
			}
			27668:  221 : state->deckCount[player]--;
			-:  222 :
		}
		29793:  223 : for (i = 0; i < newDeckPos; i++) {
			branch  0 taken 93 %
				branch  1 taken 7 % (fallthrough)
				27668:  224 : state->deck[player][i] = newDeck[i];
			27668:  225 : state->deckCount[player]++;
			-:  226 :
		}
		-:  227 :
			2125 : 228 : return 0;
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
#####:  429:	  if (state->hand[player][i] == gardens) {
			branch  0 never executed
			branch  1 never executed
#####:  430:		  score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
			-:  431 : };
		-:  432 : }
	-:  433 :
		-: 434 :  //score from discard
#####:  435:  for (i = 0; i < state->discardCount[player]; i++)
		branch  0 never executed
		branch  1 never executed
		- : 436 : {
#####:  437:      if (state->discard[player][i] == curse) { score = score - 1; };
		branch  0 never executed
			branch  1 never executed
#####:  438:      if (state->discard[player][i] == estate) { score = score + 1; };
			branch  0 never executed
			branch  1 never executed
#####:  439:      if (state->discard[player][i] == duchy) { score = score + 3; };
			branch  0 never executed
			branch  1 never executed
#####:  440:      if (state->discard[player][i] == province) { score = score + 6; };
			branch  0 never executed
			branch  1 never executed
#####:  441:      if (state->discard[player][i] == great_hall) { score = score + 1; };
			branch  0 never executed
			branch  1 never executed
#####:  442:	  if (state->hand[player][i] == gardens) {
			branch  0 never executed
			branch  1 never executed
#####:  443:		  score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
			-:  444 : };
		-:  445 : }
	-:  446 :
		-: 447 :  //score from deck
#####:  448:  for (i = 0; i < state->deckCount[player]; i++)
		branch  0 never executed
		branch  1 never executed
		- : 449 : {
#####:  450:      if (state->deck[player][i] == curse) { score = score - 1; };
		branch  0 never executed
			branch  1 never executed
#####:  451:      if (state->deck[player][i] == estate) { score = score + 1; };
			branch  0 never executed
			branch  1 never executed
#####:  452:      if (state->deck[player][i] == duchy) { score = score + 3; };
			branch  0 never executed
			branch  1 never executed
#####:  453:      if (state->deck[player][i] == province) { score = score + 6; };
			branch  0 never executed
			branch  1 never executed
#####:  454:      if (state->deck[player][i] == great_hall) { score = score + 1; };
			branch  0 never executed
			branch  1 never executed
#####:  455:	  if (state->hand[player][i] == gardens) {
			branch  0 never executed
			branch  1 never executed
#####:  456:		  score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
			-:  457 : };
		-:  458 : }
	-:  459 :
#####:  460:  return score;
		-:  461 : }
	-:  462 :
		function getWinners called 0 returned 0 % blocks executed 0 %
#####:  463:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
		-:  464 : int i;
	-:  465 : int j;
	-:  466 : int highScore;
	-:  467 : int currentPlayer;
	-:  468 :
		-: 469 :  //get score for each player
#####:  470:  for (i = 0; i < MAX_PLAYERS; i++)
		branch  0 never executed
		branch  1 never executed
		- : 471 : {
		-:  472 :      //set unused player scores to -9999
#####:  473:      if (i >= state->numPlayers)
			branch  0 never executed
			branch  1 never executed
			- : 474 : {
#####:  475:	  players[i] = -9999;
			-:  476 : }
		-: 477 : else
			- :  478 : {
#####:  479:	  players[i] = scoreFor (i, state);
			call    0 never executed
				- :  480 : }
		-: 481 : }
	-:  482 :
		-: 483 :  //find highest score
#####:  484:  j = 0;
#####:  485:  for (i = 0; i < MAX_PLAYERS; i++)
		branch  0 never executed
		branch  1 never executed
		- : 486 : {
#####:  487:      if (players[i] > players[j])
		branch  0 never executed
			branch  1 never executed
			- : 488 : {
#####:  489:	  j = i;
			-:  490 : }
		-: 491 : }
#####:  492:  highScore = players[j];
	-:  493 :
		-: 494 :  //add 1 to players who had less turns
#####:  495:  currentPlayer = whoseTurn(state);
		call    0 never executed
#####:  496:  for (i = 0; i < MAX_PLAYERS; i++)
		branch  0 never executed
		branch  1 never executed
		- : 497 : {
#####:  498:      if ( players[i] == highScore && i > currentPlayer )
		branch  0 never executed
			branch  1 never executed
			branch  2 never executed
			branch  3 never executed
			- : 499 : {
#####:  500:	  players[i]++;
			-:  501 : }
		-: 502 : }
	-:  503 :
		-: 504 :  //find new highest score
#####:  505:  j = 0;
#####:  506:  for (i = 0; i < MAX_PLAYERS; i++)
		branch  0 never executed
		branch  1 never executed
		- : 507 : {
#####:  508:      if ( players[i] > players[j] )
		branch  0 never executed
			branch  1 never executed
			- : 509 : {
#####:  510:	  j = i;
			-:  511 : }
		-: 512 : }
#####:  513:  highScore = players[j];
	-:  514 :
		-: 515 :  //set winners in array to 1 and rest to 0
#####:  516:  for (i = 0; i < MAX_PLAYERS; i++)
		branch  0 never executed
		branch  1 never executed
		- : 517 : {
#####:  518:      if ( players[i] == highScore )
		branch  0 never executed
			branch  1 never executed
			- : 519 : {
#####:  520:	  players[i] = 1;
			-:  521 : }
		-: 522 : else
			- :  523 : {
#####:  524:	  players[i] = 0;
			-:  525 : }
		-: 526 : }
	-:  527 :
#####:  528:  return 0;
		-:  529 : }
	-:  530 :
		function drawCard called 20680 returned 100 % blocks executed 92 %
		20680 : 531 : int drawCard(int player, struct gameState *state)
		- : 532 : {	int count;
	-:  533 : int deckCounter;
	20680:  534 : if (state->deckCount[player] <= 0) {//Deck is empty
		branch  0 taken 1 % (fallthrough)
			branch  1 taken 99 %
			-:  535 :
			-: 536 :    //Step 1 Shuffle the discard pile back into a deck
			-: 537 : int i;
		-:  538 :    //Move discard to deck
			7793 : 539 : for (i = 0; i < state->discardCount[player]; i++) {
			branch  0 taken 98 %
				branch  1 taken 2 % (fallthrough)
				7668:  540 : state->deck[player][i] = state->discard[player][i];
			7668:  541 : state->discard[player][i] = -1;
			-:  542 :
		}
		-:  543 :
			125 : 544 : state->deckCount[player] = state->discardCount[player];
		125:  545 : state->discardCount[player] = 0;//Reset discard
		-:  546 :
			-: 547 :    //Shufffle the deck
			125 : 548 : shuffle(player, state);//Shuffle the deck up and make it so that we can draw
		call    0 returned 100 %
			-:  549 :
			-: 550 : if (DEBUG) {//Debug statements
			-:  551 : printf("Deck count now: %d\n", state->deckCount[player]);
			-:  552 :
		}
		-: 553 :
			125 : 554 : state->discardCount[player] = 0;
		-:  555 :
			-: 556 :    //Step 2 Draw Card
			125 : 557 : count = state->handCount[player];//Get current player's hand count
		-:  558 :
			-: 559 : if (DEBUG) {//Debug statements
			-:  560 : printf("Current hand count: %d\n", count);
			-:  561 :
		}
		-: 562 :
			125 : 563 : deckCounter = state->deckCount[player];//Create a holder for the deck count
		-:  564 :
			125 : 565 : if (deckCounter == 0)
			branch  0 taken 0 % (fallthrough)
			branch  1 taken 100 %
#####:  566:      return -1;
			-:  567 :
			125 : 568 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
		125:  569 : state->deckCount[player]--;
		125:  570 : state->handCount[player]++;//Increment hand count
		-:  571 :
	}
	-:  572 :
		-: 573 : else {
		20555:  574 : int count = state->handCount[player];//Get current hand count for player
		-:  575 : int deckCounter;
		-:  576 : if (DEBUG) {//Debug statements
			-:  577 : printf("Current hand count: %d\n", count);
			-:  578 :
		}
		-: 579 :
			20555 : 580 : deckCounter = state->deckCount[player];//Create holder for the deck count
		20555:  581 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
		20555:  582 : state->deckCount[player]--;
		20555:  583 : state->handCount[player]++;//Increment hand count
		-:  584 :
	}
	-:  585 :
		20680 : 586 : return 0;
	-:  587 : }
	-:  588 :
		function getCost called 0 returned 0 % blocks executed 0 %
#####:  589:int getCost(int cardNumber)
		- : 590 : {
#####:  591:  switch( cardNumber ) 
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
			- :  592 : {
			-:  593 : case curse:
#####:  594:      return 0;
				-:  595 : case estate:
#####:  596:      return 2;
					-:  597 : case duchy:
#####:  598:      return 5;
						-:  599 : case province:
#####:  600:      return 8;
							-:  601 : case copper:
#####:  602:      return 0;
								-:  603 : case silver:
#####:  604:      return 3;
									-:  605 : case gold:
#####:  606:      return 6;
										-:  607 : case adventurer:
#####:  608:      return 6;
											-:  609 : case council_room:
#####:  610:      return 5;
												-:  611 : case feast:
#####:  612:      return 4;
													-:  613 : case gardens:
#####:  614:      return 4;
														-:  615 : case mine:
#####:  616:      return 5;
															-:  617 : case remodel:
#####:  618:      return 4;
																-:  619 : case smithy:
#####:  620:      return 4;
																	-:  621 : case village:
#####:  622:      return 3;
																		-:  623 : case baron:
#####:  624:      return 4;
																			-:  625 : case great_hall:
#####:  626:      return 3;
																				-:  627 : case minion:
#####:  628:      return 5;
																					-:  629 : case steward:
#####:  630:      return 3;
																						-:  631 : case tribute:
#####:  632:      return 5;
																							-:  633 : case ambassador:
#####:  634:      return 3;
																								-:  635 : case cutpurse:
#####:  636:      return 4;
																									-:  637 : case embargo:
#####:  638:      return 2;
																										-:  639 : case outpost:
#####:  640:      return 5;
																											-:  641 : case salvager:
#####:  642:      return 4;
																												-:  643 : case sea_hag:
#####:  644:      return 4;
																													-:  645 : case treasure_map:
#####:  646:      return 4;
																														-:  647 : }
		-:  648 :
#####:  649:  return -1;
			-:  650 : }
	function playSmithy called 0 returned 0 % blocks executed 0 %
#####:  651:void playSmithy(int currentPlayer, struct gameState *state, int handPos)
		- : 652 : {
		-:  653 : int i;
		-:  654 :	//+3 Cards
#####:  655:	for (i = 0; i < 3; i++)
			branch  0 never executed
			branch  1 never executed
			- : 656 : {
#####:  657:		drawCard(currentPlayer, state);
			call    0 never executed
				- :  658 : }
#####:  659:	discardCard(handPos, currentPlayer, state, 0);
		call    0 never executed
#####:  660:}
			function playAdventurer called 1000 returned 100 % blocks executed 100 %
			1000:  661 : void playAdventurer(int currentPlayer, struct gameState *state, int handPos)
			- : 662 : {
			1000:  663 : int z = 0;
			1000:  664 : int drawntreasure = 0;
			-:  665 : int temphand[MAX_HAND];
			-:  666 : int cardDrawn;
			-:  667 :
				1000 : 668 : discardCard(handPos, currentPlayer, state, 0);
			call    0 returned 100 %
				-:  669 :
				17680 : 670 : while (drawntreasure<2) {
				branch  0 taken 94 %
					branch  1 taken 6 % (fallthrough)
					15680:  671 : if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
					branch  0 taken 1 % (fallthrough)
						branch  1 taken 99 %
						125:  672 : shuffle(currentPlayer, state);
					call    0 returned 100 %
						-:  673 :
				}
				15680:  674 : drawCard(currentPlayer, state);
				call    0 returned 100 %
					15680:  675 : cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
				15680:  676 : if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
					branch  0 taken 96 % (fallthrough)
					branch  1 taken 4 %
					branch  2 taken 96 % (fallthrough)
					branch  3 taken 4 %
					branch  4 taken 5 % (fallthrough)
					branch  5 taken 95 %
					2000:  677 : drawntreasure++;
				-:  678 : else {
					13680:  679 : temphand[z] = cardDrawn;
					13680:  680 : state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
					13680:  681 : z++;
					-:  682 :
				}
				-:  683 :
			}
			15680:  684 : while (z - 1 >= 0) {
				branch  0 taken 93 %
					branch  1 taken 7 % (fallthrough)
					13680:  685 : state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
				13680:  686 : z = z - 1;
				-:  687 :
			}
			1000:  688 : }
		function playCouncil_Room called 0 returned 0 % blocks executed 0 %
#####:  689:void playCouncil_Room(int currentPlayer, struct gameState *state, int handPos)
			- : 690 : {
			-:  691 : int i;
#####:  692:	for (i = 0; i < 4; i++)
			branch  0 never executed
				branch  1 never executed
				- : 693 : {
#####:  694:		drawCard(currentPlayer, state);
				call    0 never executed
					- :  695 : }
			-: 696 :
#####:  697:	state->numBuys++;
				-:  698 :
#####:  699:	discardCard(handPos, currentPlayer, state, 0);
				call    0 never executed
				- :  700 :
				-: 701 :
				-: 702 :	//Each other player draws a card
#####:  703:	for (i = 0; i < state->numPlayers; i++)
				branch  0 never executed
				branch  1 never executed
				- : 704 : {
#####:  705:		if (i != currentPlayer)
				branch  0 never executed
					branch  1 never executed
					- : 706 : {
#####:  707:			drawCard(i, state);
					call    0 never executed
						- :  708 : }
				-: 709 : }
#####:  710:}
			function playGardens called 0 returned 0 % blocks executed 0 %
#####:  711:void playGardens(int currentPlayer, struct gameState *state, int handPos)
				- : 712 : {
#####:  713:	discardCard(handPos, currentPlayer, state, 0);
				call    0 never executed
#####:  714:}
					function playMine called 0 returned 0 % blocks executed 0 %
#####:  715:void playMine(int choice1, int choice2, int currentPlayer, struct gameState *state, int handPos)
					- : 716 : {
					-:  717 : int i;
#####:  718:	int j = state->hand[currentPlayer][choice1];  //store card we will trash
					-:  719 :
#####:  720:	if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
						branch  0 never executed
						branch  1 never executed
						branch  2 never executed
						branch  3 never executed
						- : 721 : {
#####:  722:		return -1;
						-:  723 : }
					-: 724 :
#####:  725:	if (choice2 > treasure_map || choice2 < curse)
						branch  0 never executed
						branch  1 never executed
						branch  2 never executed
						branch  3 never executed
						- : 726 : {
#####:  727:		return -1;
						-:  728 : }
					-: 729 :
#####:  730:	if ((getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2))
						call    0 never executed
						call    1 never executed
						branch  2 never executed
						branch  3 never executed
						- : 731 : {
#####:  732:		return -1;
						-:  733 : }
					-: 734 :
#####:  735:	gainCard(choice2, state, 2, currentPlayer);
						call    0 never executed
						- :  736 :
						-: 737 :	//discard card from hand
#####:  738:	discardCard(handPos, currentPlayer, state, 0);
						call    0 never executed
						- :  739 :
						-: 740 :	//discard trashed card
#####:  741:	for (i = 0; i < state->handCount[currentPlayer]; i++)
						branch  0 never executed
						branch  1 never executed
						- : 742 : {
#####:  743:		if (state->hand[currentPlayer][i] == j)
						branch  0 never executed
							branch  1 never executed
							- : 744 : {
#####:  745:			discardCard(i, currentPlayer, state, 0);
							call    0 never executed
#####:  746:			break;
								-:  747 : }
						-: 748 : }
					-:  749 :
						-: 750 : }
				function cardEffect called 1000 returned 100 % blocks executed 3 %
					1000:  751 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
					- : 752 : {
					-:  753 : int i;
					-:  754 : int j;
					-:  755 : int k;
					-:  756 : int x;
					-:  757 : int index;
					1000:  758 : int currentPlayer = whoseTurn(state);
					call    0 returned 100 %
						1000:  759 : int nextPlayer = currentPlayer + 1;
					-:  760 :
						1000 : 761 : int tributeRevealedCards[2] = { -1, -1 };
					-:  762 : int temphand[MAX_HAND];// moved above the if statement
					1000:  763 : int drawntreasure = 0;
					-:  764 : int cardDrawn;
					1000:  765 : int z = 0;// this is the counter for the temp hand
					1000:  766 : if (nextPlayer > (state->numPlayers - 1)) {
						branch  0 taken 0 % (fallthrough)
							branch  1 taken 100 %
#####:  767:    nextPlayer = 0;
							-:  768 :
					}
					-:  769 :
						-: 770 :
						-: 771 :  //uses switch to select card and perform actions
						1000 : 772 : switch (card)
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
						-:  773 : {
						-:  774 : case adventurer:
							1000 : 775 : playAdventurer(currentPlayer, state, handPos);
							call    0 returned 100 %
								1000:  776 : return 0;
							-:  777 :
								-: 778 : case council_room:
#####:  779:	  playCouncil_Room(currentPlayer, state, handPos);
									call    0 never executed
#####:  780:      return 0;
										-:  781 :
										-: 782 : case feast:
											-: 783 :      //gain card with cost up to 5
												-: 784 :      //Backup hand
#####:  785:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
												branch  0 never executed
												branch  1 never executed
#####:  786:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####:  787:	state->hand[currentPlayer][i] = -1;//Set to nothing
												-:  788 : }
											-:  789 :      //Backup hand
												-: 790 :
												-: 791 :      //Update Coins for Buy
#####:  792:      updateCoins(currentPlayer, state, 5);
												call    0 never executed
#####:  793:      x = 1;//Condition to loop on
#####:  794:      while( x == 1) {//Buy one card
												branch  0 never executed
												branch  1 never executed
#####:  795:	if (supplyCount(choice1, state) <= 0){
												call    0 never executed
												branch  1 never executed
												branch  2 never executed
												- :  796 : if (DEBUG)
												-: 797 : printf("None of that card left, sorry!\n");
											-:  798 :
												-: 799 : if (DEBUG) {
												-:  800 : printf("Cards Left: %d\n", supplyCount(choice1, state));
												-:  801 :
											}
											-: 802 : }
#####:  803:	else if (state->coins < getCost(choice1)){
												call    0 never executed
												branch  1 never executed
												branch  2 never executed
#####:  804:	  printf("That card is too expensive!\n");
												call    0 never executed
												- :  805 :
												-: 806 : if (DEBUG) {
												-:  807 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
												-:  808 :
											}
											-: 809 : }
											-:  810 : else {
												-:  811 :
													-: 812 : if (DEBUG) {
													-:  813 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
													-:  814 :
												}
												-: 815 :
#####:  816:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
													call    0 never executed
#####:  817:	  x = 0;//No more buying cards
													-:  818 :
													-: 819 : if (DEBUG) {
													-:  820 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
													-:  821 :
												}
												-: 822 :
													-: 823 :
											}
											-:  824 : }
												-:  825 :
												-: 826 :      //Reset Hand
#####:  827:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
												branch  0 never executed
												branch  1 never executed
#####:  828:	state->hand[currentPlayer][i] = temphand[i];
#####:  829:	temphand[i] = -1;
												-:  830 : }
											-:  831 :      //Reset Hand
												-: 832 :
#####:  833:      return 0;
												-:  834 :
												-: 835 : case gardens:
#####:  836:	  playGardens(currentPlayer, state, handPos);
													call    0 never executed
#####:  837:      return -1;
														-:  838 :
														-: 839 : case mine:
#####:  840:	  playMine(choice1, choice2, currentPlayer, state, handPos);
															call    0 never executed
#####:  841:      return 0;
																-:  842 :
																-: 843 : case remodel:
#####:  844:      j = state->hand[currentPlayer][choice1];  //store card we will trash
																	-:  845 :
#####:  846:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
																		call    0 never executed
																		call    1 never executed
																		branch  2 never executed
																		branch  3 never executed
																		- : 847 : {
#####:  848:	  return -1;
																		-:  849 : }
																	-: 850 :
#####:  851:      gainCard(choice2, state, 0, currentPlayer);
																		call    0 never executed
																		- :  852 :
																		-: 853 :      //discard card from hand
#####:  854:      discardCard(handPos, currentPlayer, state, 0);
																		call    0 never executed
																		- :  855 :
																		-: 856 :      //discard trashed card
#####:  857:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																		branch  0 never executed
																		branch  1 never executed
																		- : 858 : {
#####:  859:	  if (state->hand[currentPlayer][i] == j)
																		branch  0 never executed
																			branch  1 never executed
																			- : 860 : {
#####:  861:	      discardCard(i, currentPlayer, state, 0);			
																			call    0 never executed
#####:  862:	      break;
																				-:  863 : }
																		-: 864 : }
																	-:  865 :
																		-: 866 :
#####:  867:      return 0;
																		-:  868 :
																		-: 869 : case smithy:
#####:  870:      playSmithy(currentPlayer, state, handPos);
																			call    0 never executed
#####:  871:      return 0;
																				-:  872 :
																				-: 873 : case village:
																					-: 874 :      //+1 Card
#####:  875:      drawCard(currentPlayer, state);
																						call    0 never executed
																						- :  876 :
																						-: 877 :      //+2 Actions
#####:  878:      state->numActions = state->numActions + 2;
																						-:  879 :
																						-: 880 :      //discard played card from hand
#####:  881:      discardCard(handPos, currentPlayer, state, 0);
																						call    0 never executed
#####:  882:      return 0;
																						-:  883 :
																						-: 884 : case baron:
#####:  885:      state->numBuys++;//Increase buys by 1!
#####:  886:      if (choice1 > 0){//Boolean true or going to discard an estate
																							branch  0 never executed
																								branch  1 never executed
#####:  887:	int p = 0;//Iterator for hand!
#####:  888:	int card_not_discarded = 1;//Flag for discard set!
#####:  889:	while(card_not_discarded){
																								branch  0 never executed
																								branch  1 never executed
#####:  890:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																								branch  0 never executed
																								branch  1 never executed
#####:  891:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  892:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  893:	    state->discardCount[currentPlayer]++;
#####:  894:	    for (;p < state->handCount[currentPlayer]; p++){
																								branch  0 never executed
																								branch  1 never executed
#####:  895:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																								-:  896 : }
#####:  897:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  898:	    state->handCount[currentPlayer]--;
#####:  899:	    card_not_discarded = 0;//Exit the loop
																								-:  900 : }
#####:  901:	  else if (p > state->handCount[currentPlayer]){
																								branch  0 never executed
																								branch  1 never executed
																								- :  902 : if (DEBUG) {
																								-:  903 : printf("No estate cards in your hand, invalid choice\n");
																								-:  904 : printf("Must gain an estate if there are any\n");
																								-:  905 :
																							}
#####:  906:	    if (supplyCount(estate, state) > 0){
																							call    0 never executed
																								branch  1 never executed
																								branch  2 never executed
#####:  907:	      gainCard(estate, state, 0, currentPlayer);
																								call    0 never executed
#####:  908:	      state->supplyCount[estate]--;//Decrement estates
#####:  909:	      if (supplyCount(estate, state) == 0){
																								call    0 never executed
																								branch  1 never executed
																								branch  2 never executed
#####:  910:		isGameOver(state);
																								call    0 never executed
																								- :  911 : }
																								-:  912 : }
#####:  913:	    card_not_discarded = 0;//Exit the loop
																								-:  914 : }
																							-:  915 :
																								-: 916 : else {
#####:  917:	    p++;//Next card
																								-:  918 :
																							}
																							-:  919 : }
																								-:  920 : }
																					-:  921 :
																						-: 922 : else {
#####:  923:	if (supplyCount(estate, state) > 0){
																						call    0 never executed
																							branch  1 never executed
																							branch  2 never executed
#####:  924:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																							call    0 never executed
#####:  925:	  state->supplyCount[estate]--;//Decrement Estates
#####:  926:	  if (supplyCount(estate, state) == 0){
																							call    0 never executed
																							branch  1 never executed
																							branch  2 never executed
#####:  927:	    isGameOver(state);
																							call    0 never executed
																							- :  928 : }
																							-:  929 : }
																					-:  930 :
																					}
																					-:  931 :
																						-: 932 :
#####:  933:      return 0;
																						-:  934 :
																						-: 935 : case great_hall:
																							-: 936 :      //+1 Card
#####:  937:      drawCard(currentPlayer, state);
																								call    0 never executed
																								- :  938 :
																								-: 939 :      //+1 Actions
#####:  940:      state->numActions++;
																								-:  941 :
																								-: 942 :      //discard card from hand
#####:  943:      discardCard(handPos, currentPlayer, state, 0);
																								call    0 never executed
#####:  944:      return 0;
																								-:  945 :
																								-: 946 : case minion:
																									-: 947 :      //+1 action
#####:  948:      state->numActions++;
																										-:  949 :
																										-: 950 :      //discard card from hand
#####:  951:      discardCard(handPos, currentPlayer, state, 0);
																										call    0 never executed
																										- :  952 :
#####:  953:      if (choice1)		//+2 coins
																										branch  0 never executed
																										branch  1 never executed
																										- : 954 : {
#####:  955:	  state->coins = state->coins + 2;
																										-:  956 : }
																									-: 957 :
#####:  958:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																										branch  0 never executed
																										branch  1 never executed
																										- :  959 : {
																										-:  960 :	  //discard hand
#####:  961:	  while(numHandCards(state) > 0)
																											call    0 never executed
																											branch  1 never executed
																											branch  2 never executed
																											- : 962 : {
#####:  963:	      discardCard(handPos, currentPlayer, state, 0);
																											call    0 never executed
																												- :  964 : }
																										-: 965 :
																											-: 966 :	  //draw 4
#####:  967:	  for (i = 0; i < 4; i++)
																											branch  0 never executed
																											branch  1 never executed
																											- : 968 : {
#####:  969:	      drawCard(currentPlayer, state);
																											call    0 never executed
																												- :  970 : }
																										-: 971 :
																											-: 972 :	  //other players discard hand and redraw if hand size > 4
#####:  973:	  for (i = 0; i < state->numPlayers; i++)
																											branch  0 never executed
																											branch  1 never executed
																											- : 974 : {
#####:  975:	      if (i != currentPlayer)
																											branch  0 never executed
																												branch  1 never executed
																												- : 976 : {
#####:  977:		  if ( state->handCount[i] > 4 )
																												branch  0 never executed
																													branch  1 never executed
																													- : 978 : {
																													-:  979 :		      //discard hand
#####:  980:		      while( state->handCount[i] > 0 )
																														branch  0 never executed
																														branch  1 never executed
																														- : 981 : {
#####:  982:			  discardCard(handPos, i, state, 0);
																														call    0 never executed
																															- :  983 : }
																													-: 984 :
																														-: 985 :		      //draw 4
#####:  986:		      for (j = 0; j < 4; j++)
																														branch  0 never executed
																														branch  1 never executed
																														- : 987 : {
#####:  988:			  drawCard(i, state);
																														call    0 never executed
																															- :  989 : }
																													-: 990 : }
																												-:  991 : }
																											-:  992 : }
																										-:  993 :
																											-: 994 : }
#####:  995:      return 0;
																									-:  996 :
																										-: 997 : case steward:
#####:  998:      if (choice1 == 1)
																											branch  0 never executed
																												branch  1 never executed
																												- : 999 : {
																												-: 1000 :	  //+2 cards
#####: 1001:	  drawCard(currentPlayer, state);
																													call    0 never executed
#####: 1002:	  drawCard(currentPlayer, state);
																													call    0 never executed
																													- : 1003 : }
#####: 1004:      else if (choice1 == 2)
																											branch  0 never executed
																												branch  1 never executed
																												- : 1005 : {
																												-: 1006 :	  //+2 coins
#####: 1007:	  state->coins = state->coins + 2;
																													-: 1008 : }
																											-: 1009 : else
																												- : 1010 : {
																												-: 1011 :	  //trash 2 cards in hand
#####: 1012:	  discardCard(choice2, currentPlayer, state, 1);
																													call    0 never executed
#####: 1013:	  discardCard(choice3, currentPlayer, state, 1);
																													call    0 never executed
																													- : 1014 : }
																											-: 1015 :
																												-: 1016 :      //discard card from hand
#####: 1017:      discardCard(handPos, currentPlayer, state, 0);
																												call    0 never executed
#####: 1018:      return 0;
																												-: 1019 :
																												-: 1020 : case tribute:
#####: 1021:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																													branch  0 never executed
																														branch  1 never executed
#####: 1022:	if (state->deckCount[nextPlayer] > 0){
																														branch  0 never executed
																														branch  1 never executed
#####: 1023:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1024:	  state->deckCount[nextPlayer]--;
																														-: 1025 : }
#####: 1026:	else if (state->discardCount[nextPlayer] > 0){
																														branch  0 never executed
																														branch  1 never executed
#####: 1027:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####: 1028:	  state->discardCount[nextPlayer]--;
																														-: 1029 : }
																													-: 1030 : else {
																														-: 1031 :	  //No Card to Reveal
																															-: 1032 : if (DEBUG) {
																															-: 1033 : printf("No cards to reveal\n");
																															-: 1034 :
																														}
																														-: 1035 :
																													}
																													-: 1036 : }
																											-: 1037 :
																												-: 1038 : else {
#####: 1039:	if (state->deckCount[nextPlayer] == 0){
																												branch  0 never executed
																													branch  1 never executed
#####: 1040:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																													branch  0 never executed
																													branch  1 never executed
#####: 1041:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####: 1042:	    state->deckCount[nextPlayer]++;
#####: 1043:	    state->discard[nextPlayer][i] = -1;
#####: 1044:	    state->discardCount[nextPlayer]--;
																													-: 1045 : }
																													-: 1046 :
#####: 1047:	  shuffle(nextPlayer,state);//Shuffle the deck
																													call    0 never executed
																													- : 1048 : }
#####: 1049:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1050:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1051:	state->deckCount[nextPlayer]--;
#####: 1052:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1053:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1054:	state->deckCount[nextPlayer]--;
																											-: 1055 :
																											}
																											-: 1056 :
#####: 1057:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																												branch  0 never executed
																												branch  1 never executed
#####: 1058:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####: 1059:	state->playedCardCount++;
#####: 1060:	tributeRevealedCards[1] = -1;
																												-: 1061 : }
																											-: 1062 :
#####: 1063:      for (i = 0; i <= 2; i ++){
																												branch  0 never executed
																												branch  1 never executed
#####: 1064:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																												branch  0 never executed
																												branch  1 never executed
																												branch  2 never executed
																												branch  3 never executed
																												branch  4 never executed
																												branch  5 never executed
#####: 1065:	  state->coins += 2;
																												-: 1066 : }
																												-: 1067 :
#####: 1068:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
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
#####: 1069:	  drawCard(currentPlayer, state);
																												call    0 never executed
#####: 1070:	  drawCard(currentPlayer, state);
																												call    0 never executed
																												- : 1071 : }
																											-: 1072 : else {//Action Card
#####: 1073:	  state->numActions = state->numActions + 2;
																												-: 1074 :
																											}
																											-: 1075 : }
																											-: 1076 :
#####: 1077:      return 0;
																												-: 1078 :
																												-: 1079 : case ambassador:
#####: 1080:      j = 0;		//used to check if player has enough cards to discard
																													-: 1081 :
#####: 1082:      if (choice2 > 2 || choice2 < 0)
																														branch  0 never executed
																														branch  1 never executed
																														branch  2 never executed
																														branch  3 never executed
																														- : 1083 : {
#####: 1084:	  return -1;				
																														-: 1085 : }
																													-: 1086 :
#####: 1087:      if (choice1 == handPos)
																														branch  0 never executed
																														branch  1 never executed
																														- : 1088 : {
#####: 1089:	  return -1;
																														-: 1090 : }
																													-: 1091 :
#####: 1092:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																														branch  0 never executed
																														branch  1 never executed
																														- : 1093 : {
#####: 1094:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																														branch  0 never executed
																															branch  1 never executed
																															branch  2 never executed
																															branch  3 never executed
																															branch  4 never executed
																															branch  5 never executed
																															- : 1095 : {
#####: 1096:	      j++;
																															-: 1097 : }
																														-: 1098 : }
#####: 1099:      if (j < choice2)
																													branch  0 never executed
																														branch  1 never executed
																														- : 1100 : {
#####: 1101:	  return -1;				
																														-: 1102 : }
																													-: 1103 :
																														-: 1104 : if (DEBUG)
																														-: 1105 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																													-: 1106 :
																														-: 1107 :      //increase supply count for choosen card by amount being discarded
#####: 1108:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																														-: 1109 :
																														-: 1110 :      //each other player gains a copy of revealed card
#####: 1111:      for (i = 0; i < state->numPlayers; i++)
																														branch  0 never executed
																														branch  1 never executed
																														- : 1112 : {
#####: 1113:	  if (i != currentPlayer)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1114 : {
#####: 1115:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																															call    0 never executed
																																- : 1116 : }
																														-: 1117 : }
																													-: 1118 :
																														-: 1119 :      //discard played card from hand
#####: 1120:      discardCard(handPos, currentPlayer, state, 0);			
																														call    0 never executed
																														- : 1121 :
																														-: 1122 :      //trash copies of cards returned to supply
#####: 1123:      for (j = 0; j < choice2; j++)
																														branch  0 never executed
																														branch  1 never executed
																														- : 1124 : {
#####: 1125:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																														branch  0 never executed
																															branch  1 never executed
																															- : 1126 : {
#####: 1127:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																															branch  0 never executed
																																branch  1 never executed
																																- : 1128 : {
#####: 1129:		  discardCard(i, currentPlayer, state, 1);
																																call    0 never executed
#####: 1130:		  break;
																																	-: 1131 : }
																															-: 1132 : }
																														-: 1133 : }
																													-: 1134 :
#####: 1135:      return 0;
																														-: 1136 :
																														-: 1137 : case cutpurse:
																															-: 1138 :
#####: 1139:      updateCoins(currentPlayer, state, 2);
																																call    0 never executed
#####: 1140:      for (i = 0; i < state->numPlayers; i++)
																																branch  0 never executed
																																branch  1 never executed
																																- : 1141 : {
#####: 1142:	  if (i != currentPlayer)
																																branch  0 never executed
																																	branch  1 never executed
																																	- : 1143 : {
#####: 1144:	      for (j = 0; j < state->handCount[i]; j++)
																																	branch  0 never executed
																																		branch  1 never executed
																																		- : 1145 : {
#####: 1146:		  if (state->hand[i][j] == copper)
																																		branch  0 never executed
																																			branch  1 never executed
																																			- : 1147 : {
#####: 1148:		      discardCard(j, i, state, 0);
																																			call    0 never executed
#####: 1149:		      break;
																																				-: 1150 : }
#####: 1151:		  if (j == state->handCount[i])
																																		branch  0 never executed
																																			branch  1 never executed
																																			- : 1152 : {
#####: 1153:		      for (k = 0; k < state->handCount[i]; k++)
																																			branch  0 never executed
																																				branch  1 never executed
																																				- : 1154 : {
																																				-: 1155 : if (DEBUG)
																																					-: 1156 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																				-: 1157 : }
#####: 1158:		      break;
																																			-: 1159 : }
																																		-: 1160 : }
																																	-: 1161 :
																																		-: 1162 : }
																																-: 1163 :
																																	-: 1164 : }
																															-: 1165 :
																																-: 1166 :      //discard played card from hand
#####: 1167:      discardCard(handPos, currentPlayer, state, 0);			
																																call    0 never executed
																																- : 1168 :
#####: 1169:      return 0;
																																-: 1170 :
																																-: 1171 :
																																-: 1172 : case embargo:
																																	-: 1173 :      //+2 Coins
#####: 1174:      state->coins = state->coins + 2;
																																		-: 1175 :
																																		-: 1176 :      //see if selected pile is in play
#####: 1177:      if ( state->supplyCount[choice1] == -1 )
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 1178 : {
#####: 1179:	  return -1;
																																		-: 1180 : }
																																	-: 1181 :
																																		-: 1182 :      //add embargo token to selected supply pile
#####: 1183:      state->embargoTokens[choice1]++;
																																		-: 1184 :
																																		-: 1185 :      //trash card
#####: 1186:      discardCard(handPos, currentPlayer, state, 1);		
																																		call    0 never executed
#####: 1187:      return 0;
																																		-: 1188 :
																																		-: 1189 : case outpost:
																																			-: 1190 :      //set outpost flag
#####: 1191:      state->outpostPlayed++;
																																				-: 1192 :
																																				-: 1193 :      //discard card
#####: 1194:      discardCard(handPos, currentPlayer, state, 0);
																																				call    0 never executed
#####: 1195:      return 0;
																																				-: 1196 :
																																				-: 1197 : case salvager:
																																					-: 1198 :      //+1 buy
#####: 1199:      state->numBuys++;
																																						-: 1200 :
#####: 1201:      if (choice1)
																																						branch  0 never executed
																																						branch  1 never executed
																																						- : 1202 : {
																																						-: 1203 :	  //gain coins equal to trashed card
#####: 1204:	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																							call    0 never executed
																																							call    1 never executed
																																							- : 1205 :	  //trash card
#####: 1206:	  discardCard(choice1, currentPlayer, state, 1);	
																																							call    0 never executed
																																							- : 1207 : }
																																					-: 1208 :
																																						-: 1209 :      //discard card
#####: 1210:      discardCard(handPos, currentPlayer, state, 0);
																																						call    0 never executed
#####: 1211:      return 0;
																																						-: 1212 :
																																						-: 1213 : case sea_hag:
#####: 1214:      for (i = 0; i < state->numPlayers; i++){
																																							branch  0 never executed
																																								branch  1 never executed
#####: 1215:	if (i != currentPlayer){
																																								branch  0 never executed
																																								branch  1 never executed
#####: 1216:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####: 1217:	  state->discardCount[i]++;
#####: 1218:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																								-: 1219 : }
																																								-: 1220 : }
#####: 1221:      return 0;
																																					-: 1222 :
																																						-: 1223 : case treasure_map:
																																							-: 1224 :      //search hand for another treasure_map
#####: 1225:      index = -1;
#####: 1226:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																								branch  0 never executed
																																								branch  1 never executed
																																								- : 1227 : {
#####: 1228:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																								branch  0 never executed
																																									branch  1 never executed
																																									branch  2 never executed
																																									branch  3 never executed
																																									- : 1229 : {
#####: 1230:	      index = i;
#####: 1231:	      break;
																																									-: 1232 : }
																																								-: 1233 : }
#####: 1234:      if (index > -1)
																																							branch  0 never executed
																																								branch  1 never executed
																																								- : 1235 : {
																																								-: 1236 :	  //trash both treasure cards
#####: 1237:	  discardCard(handPos, currentPlayer, state, 1);
																																									call    0 never executed
#####: 1238:	  discardCard(index, currentPlayer, state, 1);
																																									call    0 never executed
																																									- : 1239 :
																																									-: 1240 :	  //gain 4 Gold cards
#####: 1241:	  for (i = 0; i < 4; i++)
																																									branch  0 never executed
																																									branch  1 never executed
																																									- : 1242 : {
#####: 1243:	      gainCard(gold, state, 1, currentPlayer);
																																									call    0 never executed
																																										- : 1244 : }
																																								-: 1245 :
																																									-: 1246 :	  //return success
#####: 1247:	  return 1;
																																									-: 1248 : }
																																							-: 1249 :
																																								-: 1250 :      //no second treasure_map found in hand
#####: 1251:      return -1;
																																								-: 1252 : }
					-: 1253 :
#####: 1254:  return -1;
						-: 1255 : }
				-: 1256 :
					function discardCard called 1000 returned 100 % blocks executed 89 %
					1000 : 1257 : int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
					- : 1258 : {
					-: 1259 :
						-: 1260 :  //if card is not trashed, added to Played pile 
						1000 : 1261 : if (trashFlag < 1)
						branch  0 taken 100 % (fallthrough)
						branch  1 taken 0 %
						-: 1262 : {
						-: 1263 :      //add card to played pile
							1000 : 1264 : state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
						1000: 1265 : state->playedCardCount++;
						-: 1266 : }
					-: 1267 :
						-: 1268 :  //set played card to -1
						1000 : 1269 : state->hand[currentPlayer][handPos] = -1;
					-: 1270 :
						-: 1271 :  //remove card from player's hand
						1000 : 1272 : if (handPos == (state->handCount[currentPlayer] - 1)) 	//last card in hand array is played
						branch  0 taken 1 % (fallthrough)
						branch  1 taken 99 %
						-: 1273 : {
						-: 1274 :      //reduce number of cards in hand
							12 : 1275 : state->handCount[currentPlayer]--;
						-: 1276 : }
					988 : 1277 : else if (state->handCount[currentPlayer] == 1) //only one card in hand
						branch  0 taken 0 % (fallthrough)
						branch  1 taken 100 %
						-: 1278 : {
						-: 1279 :      //reduce number of cards in hand
#####: 1280:      state->handCount[currentPlayer]--;
							-: 1281 : }
					-: 1282 : else
						- : 1283 : {
						-: 1284 :      //replace discarded card with last card in hand
							988 : 1285 : state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
						-: 1286 :      //set last card to -1
							988 : 1287 : state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
						-: 1288 :      //reduce number of cards in hand
							988 : 1289 : state->handCount[currentPlayer]--;
						-: 1290 : }
					-: 1291 :
						1000 : 1292 : return 0;
					-: 1293 : }
				-: 1294 :
					function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1295:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
					- : 1296 : {
					-: 1297 :  //Note: supplyPos is enum of choosen card
						-: 1298 :
						-: 1299 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1300:  if ( supplyCount(supplyPos, state) < 1 )
						call    0 never executed
						branch  1 never executed
						branch  2 never executed
						- : 1301 : {
#####: 1302:      return -1;
						-: 1303 : }
					-: 1304 :
						-: 1305 :  //added card for [whoseTurn] current player:
						-: 1306 :  // toFlag = 0 : add to discard
						-: 1307 :  // toFlag = 1 : add to deck
						-: 1308 :  // toFlag = 2 : add to hand
						-: 1309 :
#####: 1310:  if (toFlag == 1)
						branch  0 never executed
						branch  1 never executed
						- : 1311 : {
#####: 1312:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1313:      state->deckCount[player]++;
						-: 1314 : }
#####: 1315:  else if (toFlag == 2)
					branch  0 never executed
						branch  1 never executed
						- : 1316 : {
#####: 1317:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1318:      state->handCount[player]++;
						-: 1319 : }
					-: 1320 : else
						- : 1321 : {
#####: 1322:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1323:      state->discardCount[player]++;
						-: 1324 : }
					-: 1325 :
						-: 1326 :  //decrease number in supply pile
#####: 1327:  state->supplyCount[supplyPos]--;
						-: 1328 :
#####: 1329:  return 0;
						-: 1330 : }
				-: 1331 :
					function updateCoins called 1000 returned 100 % blocks executed 82 %
					1000 : 1332 : int updateCoins(int player, struct gameState *state, int bonus)
					- : 1333 : {
					-: 1334 : int i;
					-: 1335 :
						-: 1336 :  //reset coin count
						1000 : 1337 : state->coins = 0;
					-: 1338 :
						-: 1339 :  //add coins for each Treasure card in player's hand
						6000 : 1340 : for (i = 0; i < state->handCount[player]; i++)
						branch  0 taken 83 %
						branch  1 taken 17 % (fallthrough)
						-: 1341 : {
						5000: 1342 : if (state->hand[player][i] == copper)
							branch  0 taken 80 % (fallthrough)
							branch  1 taken 20 %
							-: 1343 : {
							4000: 1344 : state->coins += 1;
							-: 1345 : }
						1000 : 1346 : else if (state->hand[player][i] == silver)
							branch  0 taken 0 % (fallthrough)
							branch  1 taken 100 %
							-: 1347 : {
#####: 1348:	  state->coins += 2;
							-: 1349 : }
						1000 : 1350 : else if (state->hand[player][i] == gold)
							branch  0 taken 0 % (fallthrough)
							branch  1 taken 100 %
							-: 1351 : {
#####: 1352:	  state->coins += 3;
							-: 1353 : }
						-: 1354 : }
					-: 1355 :
						-: 1356 :  //add bonus
						1000 : 1357 : state->coins += bonus;
					-: 1358 :
						1000 : 1359 : return 0;
					-: 1360 :
						-: 1361 : }
				-: 1362 :
					-: 1363 :
					-: 1364 :
					-: 1365 ://end of dominion.c
					-: 1366 :

					---- - VILLAGE RESULTS : ---- -
					In 1000 tests...
					Success : 1000
					Error in Actions : 0
					Error in Buys : 0
					Error in Coins : 0
					Error in Hand Count : 0
					Error in Discard + Deck + played Count : 0
					Error in Supplies : 0
					Error in Opponents Deck : 0
					Error in Opponents Discard : 0
					File 'dominion.c'
					Lines executed : 20.04% of 569
					Branches executed : 22.78% of 417
					Taken at least once : 14.15% of 417
					Calls executed : 10.64% of 94
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
#####:  429:	  if (state->hand[player][i] == gardens) {
						branch  0 never executed
						branch  1 never executed
#####:  430:		  score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
						-:  431 : };
					-:  432 : }
				-:  433 :
					-: 434 :  //score from discard
#####:  435:  for (i = 0; i < state->discardCount[player]; i++)
					branch  0 never executed
					branch  1 never executed
					- : 436 : {
#####:  437:      if (state->discard[player][i] == curse) { score = score - 1; };
					branch  0 never executed
						branch  1 never executed
#####:  438:      if (state->discard[player][i] == estate) { score = score + 1; };
						branch  0 never executed
						branch  1 never executed
#####:  439:      if (state->discard[player][i] == duchy) { score = score + 3; };
						branch  0 never executed
						branch  1 never executed
#####:  440:      if (state->discard[player][i] == province) { score = score + 6; };
						branch  0 never executed
						branch  1 never executed
#####:  441:      if (state->discard[player][i] == great_hall) { score = score + 1; };
						branch  0 never executed
						branch  1 never executed
#####:  442:	  if (state->hand[player][i] == gardens) {
						branch  0 never executed
						branch  1 never executed
#####:  443:		  score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
						-:  444 : };
					-:  445 : }
				-:  446 :
					-: 447 :  //score from deck
#####:  448:  for (i = 0; i < state->deckCount[player]; i++)
					branch  0 never executed
					branch  1 never executed
					- : 449 : {
#####:  450:      if (state->deck[player][i] == curse) { score = score - 1; };
					branch  0 never executed
						branch  1 never executed
#####:  451:      if (state->deck[player][i] == estate) { score = score + 1; };
						branch  0 never executed
						branch  1 never executed
#####:  452:      if (state->deck[player][i] == duchy) { score = score + 3; };
						branch  0 never executed
						branch  1 never executed
#####:  453:      if (state->deck[player][i] == province) { score = score + 6; };
						branch  0 never executed
						branch  1 never executed
#####:  454:      if (state->deck[player][i] == great_hall) { score = score + 1; };
						branch  0 never executed
						branch  1 never executed
#####:  455:	  if (state->hand[player][i] == gardens) {
						branch  0 never executed
						branch  1 never executed
#####:  456:		  score = score + ((state->handCount[player] + state->discardCount[player] + state->deckCount[player]) / 10);
						-:  457 : };
					-:  458 : }
				-:  459 :
#####:  460:  return score;
					-:  461 : }
				-:  462 :
					function getWinners called 0 returned 0 % blocks executed 0 %
#####:  463:int getWinners(int players[MAX_PLAYERS], struct gameState *state) {
					-:  464 : int i;
				-:  465 : int j;
				-:  466 : int highScore;
				-:  467 : int currentPlayer;
				-:  468 :
					-: 469 :  //get score for each player
#####:  470:  for (i = 0; i < MAX_PLAYERS; i++)
					branch  0 never executed
					branch  1 never executed
					- : 471 : {
					-:  472 :      //set unused player scores to -9999
#####:  473:      if (i >= state->numPlayers)
						branch  0 never executed
						branch  1 never executed
						- : 474 : {
#####:  475:	  players[i] = -9999;
						-:  476 : }
					-: 477 : else
						- :  478 : {
#####:  479:	  players[i] = scoreFor (i, state);
						call    0 never executed
							- :  480 : }
					-: 481 : }
				-:  482 :
					-: 483 :  //find highest score
#####:  484:  j = 0;
#####:  485:  for (i = 0; i < MAX_PLAYERS; i++)
					branch  0 never executed
					branch  1 never executed
					- : 486 : {
#####:  487:      if (players[i] > players[j])
					branch  0 never executed
						branch  1 never executed
						- : 488 : {
#####:  489:	  j = i;
						-:  490 : }
					-: 491 : }
#####:  492:  highScore = players[j];
				-:  493 :
					-: 494 :  //add 1 to players who had less turns
#####:  495:  currentPlayer = whoseTurn(state);
					call    0 never executed
#####:  496:  for (i = 0; i < MAX_PLAYERS; i++)
					branch  0 never executed
					branch  1 never executed
					- : 497 : {
#####:  498:      if ( players[i] == highScore && i > currentPlayer )
					branch  0 never executed
						branch  1 never executed
						branch  2 never executed
						branch  3 never executed
						- : 499 : {
#####:  500:	  players[i]++;
						-:  501 : }
					-: 502 : }
				-:  503 :
					-: 504 :  //find new highest score
#####:  505:  j = 0;
#####:  506:  for (i = 0; i < MAX_PLAYERS; i++)
					branch  0 never executed
					branch  1 never executed
					- : 507 : {
#####:  508:      if ( players[i] > players[j] )
					branch  0 never executed
						branch  1 never executed
						- : 509 : {
#####:  510:	  j = i;
						-:  511 : }
					-: 512 : }
#####:  513:  highScore = players[j];
				-:  514 :
					-: 515 :  //set winners in array to 1 and rest to 0
#####:  516:  for (i = 0; i < MAX_PLAYERS; i++)
					branch  0 never executed
					branch  1 never executed
					- : 517 : {
#####:  518:      if ( players[i] == highScore )
					branch  0 never executed
						branch  1 never executed
						- : 519 : {
#####:  520:	  players[i] = 1;
						-:  521 : }
					-: 522 : else
						- :  523 : {
#####:  524:	  players[i] = 0;
						-:  525 : }
					-: 526 : }
				-:  527 :
#####:  528:  return 0;
					-:  529 : }
				-:  530 :
					function drawCard called 6000 returned 100 % blocks executed 38 %
					6000 : 531 : int drawCard(int player, struct gameState *state)
					- : 532 : {	int count;
				-:  533 : int deckCounter;
				6000:  534 : if (state->deckCount[player] <= 0) {//Deck is empty
					branch  0 taken 0 % (fallthrough)
						branch  1 taken 100 %
						-:  535 :
						-: 536 :    //Step 1 Shuffle the discard pile back into a deck
						-: 537 : int i;
					-:  538 :    //Move discard to deck
#####:  539:    for (i = 0; i < state->discardCount[player];i++){
						branch  0 never executed
						branch  1 never executed
#####:  540:      state->deck[player][i] = state->discard[player][i];
#####:  541:      state->discard[player][i] = -1;
						-:  542 : }
					-:  543 :
#####:  544:    state->deckCount[player] = state->discardCount[player];
#####:  545:    state->discardCount[player] = 0;//Reset discard
						-:  546 :
						-: 547 :    //Shufffle the deck
#####:  548:    shuffle(player, state);//Shuffle the deck up and make it so that we can draw
						call    0 never executed
						- :  549 :
						-: 550 : if (DEBUG) {//Debug statements
						-:  551 : printf("Deck count now: %d\n", state->deckCount[player]);
						-:  552 :
					}
					-: 553 :
#####:  554:    state->discardCount[player] = 0;
						-:  555 :
						-: 556 :    //Step 2 Draw Card
#####:  557:    count = state->handCount[player];//Get current player's hand count
						-:  558 :
						-: 559 : if (DEBUG) {//Debug statements
						-:  560 : printf("Current hand count: %d\n", count);
						-:  561 :
					}
					-: 562 :
#####:  563:    deckCounter = state->deckCount[player];//Create a holder for the deck count
						-:  564 :
#####:  565:    if (deckCounter == 0)
						branch  0 never executed
						branch  1 never executed
#####:  566:      return -1;
						-:  567 :
#####:  568:    state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to hand
#####:  569:    state->deckCount[player]--;
#####:  570:    state->handCount[player]++;//Increment hand count
						-:  571 :
				}
				-:  572 :
					-: 573 : else {
					6000:  574 : int count = state->handCount[player];//Get current hand count for player
					-:  575 : int deckCounter;
					-:  576 : if (DEBUG) {//Debug statements
						-:  577 : printf("Current hand count: %d\n", count);
						-:  578 :
					}
					-: 579 :
						6000 : 580 : deckCounter = state->deckCount[player];//Create holder for the deck count
					6000:  581 : state->hand[player][count] = state->deck[player][deckCounter - 1];//Add card to the hand
					6000:  582 : state->deckCount[player]--;
					6000:  583 : state->handCount[player]++;//Increment hand count
					-:  584 :
				}
				-:  585 :
					6000 : 586 : return 0;
				-:  587 : }
				-:  588 :
					function getCost called 0 returned 0 % blocks executed 0 %
#####:  589:int getCost(int cardNumber)
					- : 590 : {
#####:  591:  switch( cardNumber ) 
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
						- :  592 : {
						-:  593 : case curse:
#####:  594:      return 0;
							-:  595 : case estate:
#####:  596:      return 2;
								-:  597 : case duchy:
#####:  598:      return 5;
									-:  599 : case province:
#####:  600:      return 8;
										-:  601 : case copper:
#####:  602:      return 0;
											-:  603 : case silver:
#####:  604:      return 3;
												-:  605 : case gold:
#####:  606:      return 6;
													-:  607 : case adventurer:
#####:  608:      return 6;
														-:  609 : case council_room:
#####:  610:      return 5;
															-:  611 : case feast:
#####:  612:      return 4;
																-:  613 : case gardens:
#####:  614:      return 4;
																	-:  615 : case mine:
#####:  616:      return 5;
																		-:  617 : case remodel:
#####:  618:      return 4;
																			-:  619 : case smithy:
#####:  620:      return 4;
																				-:  621 : case village:
#####:  622:      return 3;
																					-:  623 : case baron:
#####:  624:      return 4;
																						-:  625 : case great_hall:
#####:  626:      return 3;
																							-:  627 : case minion:
#####:  628:      return 5;
																								-:  629 : case steward:
#####:  630:      return 3;
																									-:  631 : case tribute:
#####:  632:      return 5;
																										-:  633 : case ambassador:
#####:  634:      return 3;
																											-:  635 : case cutpurse:
#####:  636:      return 4;
																												-:  637 : case embargo:
#####:  638:      return 2;
																													-:  639 : case outpost:
#####:  640:      return 5;
																														-:  641 : case salvager:
#####:  642:      return 4;
																															-:  643 : case sea_hag:
#####:  644:      return 4;
																																-:  645 : case treasure_map:
#####:  646:      return 4;
																																	-:  647 : }
					-:  648 :
#####:  649:  return -1;
						-:  650 : }
				function playSmithy called 0 returned 0 % blocks executed 0 %
#####:  651:void playSmithy(int currentPlayer, struct gameState *state, int handPos)
					- : 652 : {
					-:  653 : int i;
					-:  654 :	//+3 Cards
#####:  655:	for (i = 0; i < 3; i++)
						branch  0 never executed
						branch  1 never executed
						- : 656 : {
#####:  657:		drawCard(currentPlayer, state);
						call    0 never executed
							- :  658 : }
#####:  659:	discardCard(handPos, currentPlayer, state, 0);
					call    0 never executed
#####:  660:}
						function playAdventurer called 0 returned 0 % blocks executed 0 %
#####:  661:void playAdventurer(int currentPlayer, struct gameState *state, int handPos)
						- : 662 : {
#####:  663:	int z = 0;
#####:  664:	int drawntreasure = 0;
						-:  665 : int temphand[MAX_HAND];
						-:  666 : int cardDrawn;
						-:  667 :
#####:  668:	discardCard(handPos, currentPlayer, state, 0);
							call    0 never executed
							- :  669 :
#####:  670:	while (drawntreasure<2) {
							branch  0 never executed
							branch  1 never executed
#####:  671:		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
							branch  0 never executed
							branch  1 never executed
#####:  672:			shuffle(currentPlayer, state);
							call    0 never executed
							- :  673 : }
#####:  674:		drawCard(currentPlayer, state);
							call    0 never executed
#####:  675:		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
#####:  676:		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
							branch  0 never executed
							branch  1 never executed
							branch  2 never executed
							branch  3 never executed
							branch  4 never executed
							branch  5 never executed
#####:  677:			drawntreasure++;
							-:  678 : else {
#####:  679:			temphand[z] = cardDrawn;
#####:  680:			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
#####:  681:			z++;
							-:  682 :
						}
						-:  683 : }
#####:  684:	while (z - 1 >= 0) {
						branch  0 never executed
							branch  1 never executed
#####:  685:		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
#####:  686:		z = z - 1;
							-:  687 : }
#####:  688:}
						function playCouncil_Room called 0 returned 0 % blocks executed 0 %
#####:  689:void playCouncil_Room(int currentPlayer, struct gameState *state, int handPos)
							- : 690 : {
							-:  691 : int i;
#####:  692:	for (i = 0; i < 4; i++)
							branch  0 never executed
								branch  1 never executed
								- : 693 : {
#####:  694:		drawCard(currentPlayer, state);
								call    0 never executed
									- :  695 : }
							-: 696 :
#####:  697:	state->numBuys++;
								-:  698 :
#####:  699:	discardCard(handPos, currentPlayer, state, 0);
								call    0 never executed
								- :  700 :
								-: 701 :
								-: 702 :	//Each other player draws a card
#####:  703:	for (i = 0; i < state->numPlayers; i++)
								branch  0 never executed
								branch  1 never executed
								- : 704 : {
#####:  705:		if (i != currentPlayer)
								branch  0 never executed
									branch  1 never executed
									- : 706 : {
#####:  707:			drawCard(i, state);
									call    0 never executed
										- :  708 : }
								-: 709 : }
#####:  710:}
							function playGardens called 0 returned 0 % blocks executed 0 %
#####:  711:void playGardens(int currentPlayer, struct gameState *state, int handPos)
								- : 712 : {
#####:  713:	discardCard(handPos, currentPlayer, state, 0);
								call    0 never executed
#####:  714:}
									function playMine called 0 returned 0 % blocks executed 0 %
#####:  715:void playMine(int choice1, int choice2, int currentPlayer, struct gameState *state, int handPos)
									- : 716 : {
									-:  717 : int i;
#####:  718:	int j = state->hand[currentPlayer][choice1];  //store card we will trash
									-:  719 :
#####:  720:	if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
										branch  0 never executed
										branch  1 never executed
										branch  2 never executed
										branch  3 never executed
										- : 721 : {
#####:  722:		return -1;
										-:  723 : }
									-: 724 :
#####:  725:	if (choice2 > treasure_map || choice2 < curse)
										branch  0 never executed
										branch  1 never executed
										branch  2 never executed
										branch  3 never executed
										- : 726 : {
#####:  727:		return -1;
										-:  728 : }
									-: 729 :
#####:  730:	if ((getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2))
										call    0 never executed
										call    1 never executed
										branch  2 never executed
										branch  3 never executed
										- : 731 : {
#####:  732:		return -1;
										-:  733 : }
									-: 734 :
#####:  735:	gainCard(choice2, state, 2, currentPlayer);
										call    0 never executed
										- :  736 :
										-: 737 :	//discard card from hand
#####:  738:	discardCard(handPos, currentPlayer, state, 0);
										call    0 never executed
										- :  739 :
										-: 740 :	//discard trashed card
#####:  741:	for (i = 0; i < state->handCount[currentPlayer]; i++)
										branch  0 never executed
										branch  1 never executed
										- : 742 : {
#####:  743:		if (state->hand[currentPlayer][i] == j)
										branch  0 never executed
											branch  1 never executed
											- : 744 : {
#####:  745:			discardCard(i, currentPlayer, state, 0);
											call    0 never executed
#####:  746:			break;
												-:  747 : }
										-: 748 : }
									-:  749 :
										-: 750 : }
								function cardEffect called 1000 returned 100 % blocks executed 4 %
									1000:  751 : int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
									- : 752 : {
									-:  753 : int i;
									-:  754 : int j;
									-:  755 : int k;
									-:  756 : int x;
									-:  757 : int index;
									1000:  758 : int currentPlayer = whoseTurn(state);
									call    0 returned 100 %
										1000:  759 : int nextPlayer = currentPlayer + 1;
									-:  760 :
										1000 : 761 : int tributeRevealedCards[2] = { -1, -1 };
									-:  762 : int temphand[MAX_HAND];// moved above the if statement
									1000:  763 : int drawntreasure = 0;
									-:  764 : int cardDrawn;
									1000:  765 : int z = 0;// this is the counter for the temp hand
									1000:  766 : if (nextPlayer > (state->numPlayers - 1)) {
										branch  0 taken 0 % (fallthrough)
											branch  1 taken 100 %
#####:  767:    nextPlayer = 0;
											-:  768 :
									}
									-:  769 :
										-: 770 :
										-: 771 :  //uses switch to select card and perform actions
										1000 : 772 : switch (card)
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
										-:  773 : {
										-:  774 : case adventurer:
#####:  775:	  playAdventurer(currentPlayer, state, handPos);
											call    0 never executed
#####:  776:      return 0;
												-:  777 :
												-: 778 : case council_room:
#####:  779:	  playCouncil_Room(currentPlayer, state, handPos);
													call    0 never executed
#####:  780:      return 0;
														-:  781 :
														-: 782 : case feast:
															-: 783 :      //gain card with cost up to 5
																-: 784 :      //Backup hand
#####:  785:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
																branch  0 never executed
																branch  1 never executed
#####:  786:	temphand[i] = state->hand[currentPlayer][i];//Backup card
#####:  787:	state->hand[currentPlayer][i] = -1;//Set to nothing
																-:  788 : }
															-:  789 :      //Backup hand
																-: 790 :
																-: 791 :      //Update Coins for Buy
#####:  792:      updateCoins(currentPlayer, state, 5);
																call    0 never executed
#####:  793:      x = 1;//Condition to loop on
#####:  794:      while( x == 1) {//Buy one card
																branch  0 never executed
																branch  1 never executed
#####:  795:	if (supplyCount(choice1, state) <= 0){
																call    0 never executed
																branch  1 never executed
																branch  2 never executed
																- :  796 : if (DEBUG)
																-: 797 : printf("None of that card left, sorry!\n");
															-:  798 :
																-: 799 : if (DEBUG) {
																-:  800 : printf("Cards Left: %d\n", supplyCount(choice1, state));
																-:  801 :
															}
															-: 802 : }
#####:  803:	else if (state->coins < getCost(choice1)){
																call    0 never executed
																branch  1 never executed
																branch  2 never executed
#####:  804:	  printf("That card is too expensive!\n");
																call    0 never executed
																- :  805 :
																-: 806 : if (DEBUG) {
																-:  807 : printf("Coins: %d < %d\n", state->coins, getCost(choice1));
																-:  808 :
															}
															-: 809 : }
															-:  810 : else {
																-:  811 :
																	-: 812 : if (DEBUG) {
																	-:  813 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
																	-:  814 :
																}
																-: 815 :
#####:  816:	  gainCard(choice1, state, 0, currentPlayer);//Gain the card
																	call    0 never executed
#####:  817:	  x = 0;//No more buying cards
																	-:  818 :
																	-: 819 : if (DEBUG) {
																	-:  820 : printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
																	-:  821 :
																}
																-: 822 :
																	-: 823 :
															}
															-:  824 : }
																-:  825 :
																-: 826 :      //Reset Hand
#####:  827:      for (i = 0; i <= state->handCount[currentPlayer]; i++){
																branch  0 never executed
																branch  1 never executed
#####:  828:	state->hand[currentPlayer][i] = temphand[i];
#####:  829:	temphand[i] = -1;
																-:  830 : }
															-:  831 :      //Reset Hand
																-: 832 :
#####:  833:      return 0;
																-:  834 :
																-: 835 : case gardens:
#####:  836:	  playGardens(currentPlayer, state, handPos);
																	call    0 never executed
#####:  837:      return -1;
																		-:  838 :
																		-: 839 : case mine:
#####:  840:	  playMine(choice1, choice2, currentPlayer, state, handPos);
																			call    0 never executed
#####:  841:      return 0;
																				-:  842 :
																				-: 843 : case remodel:
#####:  844:      j = state->hand[currentPlayer][choice1];  //store card we will trash
																					-:  845 :
#####:  846:      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
																						call    0 never executed
																						call    1 never executed
																						branch  2 never executed
																						branch  3 never executed
																						- : 847 : {
#####:  848:	  return -1;
																						-:  849 : }
																					-: 850 :
#####:  851:      gainCard(choice2, state, 0, currentPlayer);
																						call    0 never executed
																						- :  852 :
																						-: 853 :      //discard card from hand
#####:  854:      discardCard(handPos, currentPlayer, state, 0);
																						call    0 never executed
																						- :  855 :
																						-: 856 :      //discard trashed card
#####:  857:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																						branch  0 never executed
																						branch  1 never executed
																						- : 858 : {
#####:  859:	  if (state->hand[currentPlayer][i] == j)
																						branch  0 never executed
																							branch  1 never executed
																							- : 860 : {
#####:  861:	      discardCard(i, currentPlayer, state, 0);			
																							call    0 never executed
#####:  862:	      break;
																								-:  863 : }
																						-: 864 : }
																					-:  865 :
																						-: 866 :
#####:  867:      return 0;
																						-:  868 :
																						-: 869 : case smithy:
#####:  870:      playSmithy(currentPlayer, state, handPos);
																							call    0 never executed
#####:  871:      return 0;
																								-:  872 :
																								-: 873 : case village:
																									-: 874 :      //+1 Card
																										1000 : 875 : drawCard(currentPlayer, state);
																									call    0 returned 100 %
																										-:  876 :
																										-: 877 :      //+2 Actions
																										1000 : 878 : state->numActions = state->numActions + 2;
																									-:  879 :
																										-: 880 :      //discard played card from hand
																										1000 : 881 : discardCard(handPos, currentPlayer, state, 0);
																									call    0 returned 100 %
																										1000:  882 : return 0;
																									-:  883 :
																										-: 884 : case baron:
#####:  885:      state->numBuys++;//Increase buys by 1!
#####:  886:      if (choice1 > 0){//Boolean true or going to discard an estate
																											branch  0 never executed
																												branch  1 never executed
#####:  887:	int p = 0;//Iterator for hand!
#####:  888:	int card_not_discarded = 1;//Flag for discard set!
#####:  889:	while(card_not_discarded){
																												branch  0 never executed
																												branch  1 never executed
#####:  890:	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
																												branch  0 never executed
																												branch  1 never executed
#####:  891:	    state->coins += 4;//Add 4 coins to the amount of coins
#####:  892:	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
#####:  893:	    state->discardCount[currentPlayer]++;
#####:  894:	    for (;p < state->handCount[currentPlayer]; p++){
																												branch  0 never executed
																												branch  1 never executed
#####:  895:	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
																												-:  896 : }
#####:  897:	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
#####:  898:	    state->handCount[currentPlayer]--;
#####:  899:	    card_not_discarded = 0;//Exit the loop
																												-:  900 : }
#####:  901:	  else if (p > state->handCount[currentPlayer]){
																												branch  0 never executed
																												branch  1 never executed
																												- :  902 : if (DEBUG) {
																												-:  903 : printf("No estate cards in your hand, invalid choice\n");
																												-:  904 : printf("Must gain an estate if there are any\n");
																												-:  905 :
																											}
#####:  906:	    if (supplyCount(estate, state) > 0){
																											call    0 never executed
																												branch  1 never executed
																												branch  2 never executed
#####:  907:	      gainCard(estate, state, 0, currentPlayer);
																												call    0 never executed
#####:  908:	      state->supplyCount[estate]--;//Decrement estates
#####:  909:	      if (supplyCount(estate, state) == 0){
																												call    0 never executed
																												branch  1 never executed
																												branch  2 never executed
#####:  910:		isGameOver(state);
																												call    0 never executed
																												- :  911 : }
																												-:  912 : }
#####:  913:	    card_not_discarded = 0;//Exit the loop
																												-:  914 : }
																											-:  915 :
																												-: 916 : else {
#####:  917:	    p++;//Next card
																												-:  918 :
																											}
																											-:  919 : }
																												-:  920 : }
																									-:  921 :
																										-: 922 : else {
#####:  923:	if (supplyCount(estate, state) > 0){
																										call    0 never executed
																											branch  1 never executed
																											branch  2 never executed
#####:  924:	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
																											call    0 never executed
#####:  925:	  state->supplyCount[estate]--;//Decrement Estates
#####:  926:	  if (supplyCount(estate, state) == 0){
																											call    0 never executed
																											branch  1 never executed
																											branch  2 never executed
#####:  927:	    isGameOver(state);
																											call    0 never executed
																											- :  928 : }
																											-:  929 : }
																									-:  930 :
																									}
																									-:  931 :
																										-: 932 :
#####:  933:      return 0;
																										-:  934 :
																										-: 935 : case great_hall:
																											-: 936 :      //+1 Card
#####:  937:      drawCard(currentPlayer, state);
																												call    0 never executed
																												- :  938 :
																												-: 939 :      //+1 Actions
#####:  940:      state->numActions++;
																												-:  941 :
																												-: 942 :      //discard card from hand
#####:  943:      discardCard(handPos, currentPlayer, state, 0);
																												call    0 never executed
#####:  944:      return 0;
																												-:  945 :
																												-: 946 : case minion:
																													-: 947 :      //+1 action
#####:  948:      state->numActions++;
																														-:  949 :
																														-: 950 :      //discard card from hand
#####:  951:      discardCard(handPos, currentPlayer, state, 0);
																														call    0 never executed
																														- :  952 :
#####:  953:      if (choice1)		//+2 coins
																														branch  0 never executed
																														branch  1 never executed
																														- : 954 : {
#####:  955:	  state->coins = state->coins + 2;
																														-:  956 : }
																													-: 957 :
#####:  958:      else if (choice2)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
																														branch  0 never executed
																														branch  1 never executed
																														- :  959 : {
																														-:  960 :	  //discard hand
#####:  961:	  while(numHandCards(state) > 0)
																															call    0 never executed
																															branch  1 never executed
																															branch  2 never executed
																															- : 962 : {
#####:  963:	      discardCard(handPos, currentPlayer, state, 0);
																															call    0 never executed
																																- :  964 : }
																														-: 965 :
																															-: 966 :	  //draw 4
#####:  967:	  for (i = 0; i < 4; i++)
																															branch  0 never executed
																															branch  1 never executed
																															- : 968 : {
#####:  969:	      drawCard(currentPlayer, state);
																															call    0 never executed
																																- :  970 : }
																														-: 971 :
																															-: 972 :	  //other players discard hand and redraw if hand size > 4
#####:  973:	  for (i = 0; i < state->numPlayers; i++)
																															branch  0 never executed
																															branch  1 never executed
																															- : 974 : {
#####:  975:	      if (i != currentPlayer)
																															branch  0 never executed
																																branch  1 never executed
																																- : 976 : {
#####:  977:		  if ( state->handCount[i] > 4 )
																																branch  0 never executed
																																	branch  1 never executed
																																	- : 978 : {
																																	-:  979 :		      //discard hand
#####:  980:		      while( state->handCount[i] > 0 )
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 981 : {
#####:  982:			  discardCard(handPos, i, state, 0);
																																		call    0 never executed
																																			- :  983 : }
																																	-: 984 :
																																		-: 985 :		      //draw 4
#####:  986:		      for (j = 0; j < 4; j++)
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 987 : {
#####:  988:			  drawCard(i, state);
																																		call    0 never executed
																																			- :  989 : }
																																	-: 990 : }
																																-:  991 : }
																															-:  992 : }
																														-:  993 :
																															-: 994 : }
#####:  995:      return 0;
																													-:  996 :
																														-: 997 : case steward:
#####:  998:      if (choice1 == 1)
																															branch  0 never executed
																																branch  1 never executed
																																- : 999 : {
																																-: 1000 :	  //+2 cards
#####: 1001:	  drawCard(currentPlayer, state);
																																	call    0 never executed
#####: 1002:	  drawCard(currentPlayer, state);
																																	call    0 never executed
																																	- : 1003 : }
#####: 1004:      else if (choice1 == 2)
																															branch  0 never executed
																																branch  1 never executed
																																- : 1005 : {
																																-: 1006 :	  //+2 coins
#####: 1007:	  state->coins = state->coins + 2;
																																	-: 1008 : }
																															-: 1009 : else
																																- : 1010 : {
																																-: 1011 :	  //trash 2 cards in hand
#####: 1012:	  discardCard(choice2, currentPlayer, state, 1);
																																	call    0 never executed
#####: 1013:	  discardCard(choice3, currentPlayer, state, 1);
																																	call    0 never executed
																																	- : 1014 : }
																															-: 1015 :
																																-: 1016 :      //discard card from hand
#####: 1017:      discardCard(handPos, currentPlayer, state, 0);
																																call    0 never executed
#####: 1018:      return 0;
																																-: 1019 :
																																-: 1020 : case tribute:
#####: 1021:      if ((state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1){
																																	branch  0 never executed
																																		branch  1 never executed
#####: 1022:	if (state->deckCount[nextPlayer] > 0){
																																		branch  0 never executed
																																		branch  1 never executed
#####: 1023:	  tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1024:	  state->deckCount[nextPlayer]--;
																																		-: 1025 : }
#####: 1026:	else if (state->discardCount[nextPlayer] > 0){
																																		branch  0 never executed
																																		branch  1 never executed
#####: 1027:	  tributeRevealedCards[0] = state->discard[nextPlayer][state->discardCount[nextPlayer]-1];
#####: 1028:	  state->discardCount[nextPlayer]--;
																																		-: 1029 : }
																																	-: 1030 : else {
																																		-: 1031 :	  //No Card to Reveal
																																			-: 1032 : if (DEBUG) {
																																			-: 1033 : printf("No cards to reveal\n");
																																			-: 1034 :
																																		}
																																		-: 1035 :
																																	}
																																	-: 1036 : }
																															-: 1037 :
																																-: 1038 : else {
#####: 1039:	if (state->deckCount[nextPlayer] == 0){
																																branch  0 never executed
																																	branch  1 never executed
#####: 1040:	  for (i = 0; i < state->discardCount[nextPlayer]; i++){
																																	branch  0 never executed
																																	branch  1 never executed
#####: 1041:	    state->deck[nextPlayer][i] = state->discard[nextPlayer][i];//Move to deck
#####: 1042:	    state->deckCount[nextPlayer]++;
#####: 1043:	    state->discard[nextPlayer][i] = -1;
#####: 1044:	    state->discardCount[nextPlayer]--;
																																	-: 1045 : }
																																	-: 1046 :
#####: 1047:	  shuffle(nextPlayer,state);//Shuffle the deck
																																	call    0 never executed
																																	- : 1048 : }
#####: 1049:	tributeRevealedCards[0] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1050:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1051:	state->deckCount[nextPlayer]--;
#####: 1052:	tributeRevealedCards[1] = state->deck[nextPlayer][state->deckCount[nextPlayer]-1];
#####: 1053:	state->deck[nextPlayer][state->deckCount[nextPlayer]--] = -1;
#####: 1054:	state->deckCount[nextPlayer]--;
																															-: 1055 :
																															}
																															-: 1056 :
#####: 1057:      if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one 
																																branch  0 never executed
																																branch  1 never executed
#####: 1058:	state->playedCards[state->playedCardCount] = tributeRevealedCards[1];
#####: 1059:	state->playedCardCount++;
#####: 1060:	tributeRevealedCards[1] = -1;
																																-: 1061 : }
																															-: 1062 :
#####: 1063:      for (i = 0; i <= 2; i ++){
																																branch  0 never executed
																																branch  1 never executed
#####: 1064:	if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
																																branch  0 never executed
																																branch  1 never executed
																																branch  2 never executed
																																branch  3 never executed
																																branch  4 never executed
																																branch  5 never executed
#####: 1065:	  state->coins += 2;
																																-: 1066 : }
																																-: 1067 :
#####: 1068:	else if (tributeRevealedCards[i] == estate || tributeRevealedCards[i] == duchy || tributeRevealedCards[i] == province || tributeRevealedCards[i] == gardens || tributeRevealedCards[i] == great_hall){//Victory Card Found
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
#####: 1069:	  drawCard(currentPlayer, state);
																																call    0 never executed
#####: 1070:	  drawCard(currentPlayer, state);
																																call    0 never executed
																																- : 1071 : }
																															-: 1072 : else {//Action Card
#####: 1073:	  state->numActions = state->numActions + 2;
																																-: 1074 :
																															}
																															-: 1075 : }
																															-: 1076 :
#####: 1077:      return 0;
																																-: 1078 :
																																-: 1079 : case ambassador:
#####: 1080:      j = 0;		//used to check if player has enough cards to discard
																																	-: 1081 :
#####: 1082:      if (choice2 > 2 || choice2 < 0)
																																		branch  0 never executed
																																		branch  1 never executed
																																		branch  2 never executed
																																		branch  3 never executed
																																		- : 1083 : {
#####: 1084:	  return -1;				
																																		-: 1085 : }
																																	-: 1086 :
#####: 1087:      if (choice1 == handPos)
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 1088 : {
#####: 1089:	  return -1;
																																		-: 1090 : }
																																	-: 1091 :
#####: 1092:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 1093 : {
#####: 1094:	  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice1)
																																		branch  0 never executed
																																			branch  1 never executed
																																			branch  2 never executed
																																			branch  3 never executed
																																			branch  4 never executed
																																			branch  5 never executed
																																			- : 1095 : {
#####: 1096:	      j++;
																																			-: 1097 : }
																																		-: 1098 : }
#####: 1099:      if (j < choice2)
																																	branch  0 never executed
																																		branch  1 never executed
																																		- : 1100 : {
#####: 1101:	  return -1;				
																																		-: 1102 : }
																																	-: 1103 :
																																		-: 1104 : if (DEBUG)
																																		-: 1105 : printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);
																																	-: 1106 :
																																		-: 1107 :      //increase supply count for choosen card by amount being discarded
#####: 1108:      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;
																																		-: 1109 :
																																		-: 1110 :      //each other player gains a copy of revealed card
#####: 1111:      for (i = 0; i < state->numPlayers; i++)
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 1112 : {
#####: 1113:	  if (i != currentPlayer)
																																		branch  0 never executed
																																			branch  1 never executed
																																			- : 1114 : {
#####: 1115:	      gainCard(state->hand[currentPlayer][choice1], state, 0, i);
																																			call    0 never executed
																																				- : 1116 : }
																																		-: 1117 : }
																																	-: 1118 :
																																		-: 1119 :      //discard played card from hand
#####: 1120:      discardCard(handPos, currentPlayer, state, 0);			
																																		call    0 never executed
																																		- : 1121 :
																																		-: 1122 :      //trash copies of cards returned to supply
#####: 1123:      for (j = 0; j < choice2; j++)
																																		branch  0 never executed
																																		branch  1 never executed
																																		- : 1124 : {
#####: 1125:	  for (i = 0; i < state->handCount[currentPlayer]; i++)
																																		branch  0 never executed
																																			branch  1 never executed
																																			- : 1126 : {
#####: 1127:	      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
																																			branch  0 never executed
																																				branch  1 never executed
																																				- : 1128 : {
#####: 1129:		  discardCard(i, currentPlayer, state, 1);
																																				call    0 never executed
#####: 1130:		  break;
																																					-: 1131 : }
																																			-: 1132 : }
																																		-: 1133 : }
																																	-: 1134 :
#####: 1135:      return 0;
																																		-: 1136 :
																																		-: 1137 : case cutpurse:
																																			-: 1138 :
#####: 1139:      updateCoins(currentPlayer, state, 2);
																																				call    0 never executed
#####: 1140:      for (i = 0; i < state->numPlayers; i++)
																																				branch  0 never executed
																																				branch  1 never executed
																																				- : 1141 : {
#####: 1142:	  if (i != currentPlayer)
																																				branch  0 never executed
																																					branch  1 never executed
																																					- : 1143 : {
#####: 1144:	      for (j = 0; j < state->handCount[i]; j++)
																																					branch  0 never executed
																																						branch  1 never executed
																																						- : 1145 : {
#####: 1146:		  if (state->hand[i][j] == copper)
																																						branch  0 never executed
																																							branch  1 never executed
																																							- : 1147 : {
#####: 1148:		      discardCard(j, i, state, 0);
																																							call    0 never executed
#####: 1149:		      break;
																																								-: 1150 : }
#####: 1151:		  if (j == state->handCount[i])
																																						branch  0 never executed
																																							branch  1 never executed
																																							- : 1152 : {
#####: 1153:		      for (k = 0; k < state->handCount[i]; k++)
																																							branch  0 never executed
																																								branch  1 never executed
																																								- : 1154 : {
																																								-: 1155 : if (DEBUG)
																																									-: 1156 : printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
																																								-: 1157 : }
#####: 1158:		      break;
																																							-: 1159 : }
																																						-: 1160 : }
																																					-: 1161 :
																																						-: 1162 : }
																																				-: 1163 :
																																					-: 1164 : }
																																			-: 1165 :
																																				-: 1166 :      //discard played card from hand
#####: 1167:      discardCard(handPos, currentPlayer, state, 0);			
																																				call    0 never executed
																																				- : 1168 :
#####: 1169:      return 0;
																																				-: 1170 :
																																				-: 1171 :
																																				-: 1172 : case embargo:
																																					-: 1173 :      //+2 Coins
#####: 1174:      state->coins = state->coins + 2;
																																						-: 1175 :
																																						-: 1176 :      //see if selected pile is in play
#####: 1177:      if ( state->supplyCount[choice1] == -1 )
																																						branch  0 never executed
																																						branch  1 never executed
																																						- : 1178 : {
#####: 1179:	  return -1;
																																						-: 1180 : }
																																					-: 1181 :
																																						-: 1182 :      //add embargo token to selected supply pile
#####: 1183:      state->embargoTokens[choice1]++;
																																						-: 1184 :
																																						-: 1185 :      //trash card
#####: 1186:      discardCard(handPos, currentPlayer, state, 1);		
																																						call    0 never executed
#####: 1187:      return 0;
																																						-: 1188 :
																																						-: 1189 : case outpost:
																																							-: 1190 :      //set outpost flag
#####: 1191:      state->outpostPlayed++;
																																								-: 1192 :
																																								-: 1193 :      //discard card
#####: 1194:      discardCard(handPos, currentPlayer, state, 0);
																																								call    0 never executed
#####: 1195:      return 0;
																																								-: 1196 :
																																								-: 1197 : case salvager:
																																									-: 1198 :      //+1 buy
#####: 1199:      state->numBuys++;
																																										-: 1200 :
#####: 1201:      if (choice1)
																																										branch  0 never executed
																																										branch  1 never executed
																																										- : 1202 : {
																																										-: 1203 :	  //gain coins equal to trashed card
#####: 1204:	  state->coins = state->coins + getCost( handCard(choice1, state) );
																																											call    0 never executed
																																											call    1 never executed
																																											- : 1205 :	  //trash card
#####: 1206:	  discardCard(choice1, currentPlayer, state, 1);	
																																											call    0 never executed
																																											- : 1207 : }
																																									-: 1208 :
																																										-: 1209 :      //discard card
#####: 1210:      discardCard(handPos, currentPlayer, state, 0);
																																										call    0 never executed
#####: 1211:      return 0;
																																										-: 1212 :
																																										-: 1213 : case sea_hag:
#####: 1214:      for (i = 0; i < state->numPlayers; i++){
																																											branch  0 never executed
																																												branch  1 never executed
#####: 1215:	if (i != currentPlayer){
																																												branch  0 never executed
																																												branch  1 never executed
#####: 1216:	  state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
#####: 1217:	  state->discardCount[i]++;
#####: 1218:	  state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
																																												-: 1219 : }
																																												-: 1220 : }
#####: 1221:      return 0;
																																									-: 1222 :
																																										-: 1223 : case treasure_map:
																																											-: 1224 :      //search hand for another treasure_map
#####: 1225:      index = -1;
#####: 1226:      for (i = 0; i < state->handCount[currentPlayer]; i++)
																																												branch  0 never executed
																																												branch  1 never executed
																																												- : 1227 : {
#####: 1228:	  if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
																																												branch  0 never executed
																																													branch  1 never executed
																																													branch  2 never executed
																																													branch  3 never executed
																																													- : 1229 : {
#####: 1230:	      index = i;
#####: 1231:	      break;
																																													-: 1232 : }
																																												-: 1233 : }
#####: 1234:      if (index > -1)
																																											branch  0 never executed
																																												branch  1 never executed
																																												- : 1235 : {
																																												-: 1236 :	  //trash both treasure cards
#####: 1237:	  discardCard(handPos, currentPlayer, state, 1);
																																													call    0 never executed
#####: 1238:	  discardCard(index, currentPlayer, state, 1);
																																													call    0 never executed
																																													- : 1239 :
																																													-: 1240 :	  //gain 4 Gold cards
#####: 1241:	  for (i = 0; i < 4; i++)
																																													branch  0 never executed
																																													branch  1 never executed
																																													- : 1242 : {
#####: 1243:	      gainCard(gold, state, 1, currentPlayer);
																																													call    0 never executed
																																														- : 1244 : }
																																												-: 1245 :
																																													-: 1246 :	  //return success
#####: 1247:	  return 1;
																																													-: 1248 : }
																																											-: 1249 :
																																												-: 1250 :      //no second treasure_map found in hand
#####: 1251:      return -1;
																																												-: 1252 : }
									-: 1253 :
#####: 1254:  return -1;
										-: 1255 : }
								-: 1256 :
									function discardCard called 1000 returned 100 % blocks executed 78 %
									1000 : 1257 : int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
									- : 1258 : {
									-: 1259 :
										-: 1260 :  //if card is not trashed, added to Played pile 
										1000 : 1261 : if (trashFlag < 1)
										branch  0 taken 100 % (fallthrough)
										branch  1 taken 0 %
										-: 1262 : {
										-: 1263 :      //add card to played pile
											1000 : 1264 : state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
										1000: 1265 : state->playedCardCount++;
										-: 1266 : }
									-: 1267 :
										-: 1268 :  //set played card to -1
										1000 : 1269 : state->hand[currentPlayer][handPos] = -1;
									-: 1270 :
										-: 1271 :  //remove card from player's hand
										1000 : 1272 : if (handPos == (state->handCount[currentPlayer] - 1)) 	//last card in hand array is played
										branch  0 taken 0 % (fallthrough)
										branch  1 taken 100 %
										-: 1273 : {
										-: 1274 :      //reduce number of cards in hand
#####: 1275:      state->handCount[currentPlayer]--;
											-: 1276 : }
									1000 : 1277 : else if (state->handCount[currentPlayer] == 1) //only one card in hand
										branch  0 taken 0 % (fallthrough)
										branch  1 taken 100 %
										-: 1278 : {
										-: 1279 :      //reduce number of cards in hand
#####: 1280:      state->handCount[currentPlayer]--;
											-: 1281 : }
									-: 1282 : else
										- : 1283 : {
										-: 1284 :      //replace discarded card with last card in hand
											1000 : 1285 : state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
										-: 1286 :      //set last card to -1
											1000 : 1287 : state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
										-: 1288 :      //reduce number of cards in hand
											1000 : 1289 : state->handCount[currentPlayer]--;
										-: 1290 : }
									-: 1291 :
										1000 : 1292 : return 0;
									-: 1293 : }
								-: 1294 :
									function gainCard called 0 returned 0 % blocks executed 0 %
#####: 1295:int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
									- : 1296 : {
									-: 1297 :  //Note: supplyPos is enum of choosen card
										-: 1298 :
										-: 1299 :  //check if supply pile is empty (0) or card is not used in game (-1)
#####: 1300:  if ( supplyCount(supplyPos, state) < 1 )
										call    0 never executed
										branch  1 never executed
										branch  2 never executed
										- : 1301 : {
#####: 1302:      return -1;
										-: 1303 : }
									-: 1304 :
										-: 1305 :  //added card for [whoseTurn] current player:
										-: 1306 :  // toFlag = 0 : add to discard
										-: 1307 :  // toFlag = 1 : add to deck
										-: 1308 :  // toFlag = 2 : add to hand
										-: 1309 :
#####: 1310:  if (toFlag == 1)
										branch  0 never executed
										branch  1 never executed
										- : 1311 : {
#####: 1312:      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
#####: 1313:      state->deckCount[player]++;
										-: 1314 : }
#####: 1315:  else if (toFlag == 2)
									branch  0 never executed
										branch  1 never executed
										- : 1316 : {
#####: 1317:      state->hand[ player ][ state->handCount[player] ] = supplyPos;
#####: 1318:      state->handCount[player]++;
										-: 1319 : }
									-: 1320 : else
										- : 1321 : {
#####: 1322:      state->discard[player][ state->discardCount[player] ] = supplyPos;
#####: 1323:      state->discardCount[player]++;
										-: 1324 : }
									-: 1325 :
										-: 1326 :  //decrease number in supply pile
#####: 1327:  state->supplyCount[supplyPos]--;
										-: 1328 :
#####: 1329:  return 0;
										-: 1330 : }
								-: 1331 :
									function updateCoins called 1000 returned 100 % blocks executed 82 %
									1000 : 1332 : int updateCoins(int player, struct gameState *state, int bonus)
									- : 1333 : {
									-: 1334 : int i;
									-: 1335 :
										-: 1336 :  //reset coin count
										1000 : 1337 : state->coins = 0;
									-: 1338 :
										-: 1339 :  //add coins for each Treasure card in player's hand
										6000 : 1340 : for (i = 0; i < state->handCount[player]; i++)
										branch  0 taken 83 %
										branch  1 taken 17 % (fallthrough)
										-: 1341 : {
										5000: 1342 : if (state->hand[player][i] == copper)
											branch  0 taken 80 % (fallthrough)
											branch  1 taken 20 %
											-: 1343 : {
											4000: 1344 : state->coins += 1;
											-: 1345 : }
										1000 : 1346 : else if (state->hand[player][i] == silver)
											branch  0 taken 0 % (fallthrough)
											branch  1 taken 100 %
											-: 1347 : {
#####: 1348:	  state->coins += 2;
											-: 1349 : }
										1000 : 1350 : else if (state->hand[player][i] == gold)
											branch  0 taken 0 % (fallthrough)
											branch  1 taken 100 %
											-: 1351 : {
#####: 1352:	  state->coins += 3;
											-: 1353 : }
										-: 1354 : }
									-: 1355 :
										-: 1356 :  //add bonus
										1000 : 1357 : state->coins += bonus;
									-: 1358 :
										1000 : 1359 : return 0;
									-: 1360 :
										-: 1361 : }
								-: 1362 :
									-: 1363 :
									-: 1364 :
									-: 1365 ://end of dominion.c
									-: 1366 :
