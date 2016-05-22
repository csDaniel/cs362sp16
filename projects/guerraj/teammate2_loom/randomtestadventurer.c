/*
Author: Ryan Peters
Date: 05/05/16
Description: Random tester for adventurer card.  Tests that the player draws cards,
if other players draw or discard calls.  Tests if player discards treasure cards.
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>
#include "dominion.h"



void testPlayAdventurer()
{	
	int i, k, p, r;
	int bonus = 0;
	int handPos;
	int player;
	int preTreasure = 0;
	int postTreasure = 0;
	int treasureDiscard = 0;
	int handCountPass = 0;
	int returnValuePass = 0;
	int treasureDrawPass = 0;
	int otherPlayerDrawPass = 0;
	int otherPlayerDrawFail = 0;
	int otherPlayerDeckPass = 0;
	int otherPlayerDeckFail = 0;
	int otherPlayerDiscardPass = 0;
	int otherPlayerDiscardFail = 0;
	int treasureDiscardPass = 0;
	int playerDiscardPass = 0;
	struct gameState pre;
	struct gameState post;
	int seed = 100;
	int kc[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};
	
	
	printf("Testing Adventure Card.\n");
	
	for(i = 0; i < 1; i++){
		
		memset(&post, 0, sizeof(struct gameState));
		p = floor(rand() % 4) + 1;
		initializeGame(p, kc, seed, &post);
		post.numPlayers = floor((rand() % 4) + 1);
		post.deckCount[p] = floor(rand() % 50);
		post.discardCount[p] = floor(rand() % 50);
		post.handCount[p] = floor(rand() % 50);
		post.hand[p][0] = adventurer;
		player = floor(rand() % p);
		post.whoseTurn = player;
		if(post.handCount[player] > 0)
			handPos = floor(rand() % pre.handCount[player]);
		else
			handPos = 0;
		memcpy(&pre, &post, sizeof(struct gameState));	
		printf("-------- START TEST %d --------\n", i);
		r = cardEffect(adventurer, 0, 0, 0, &post, handPos, &bonus);
		
		
		/*Test player adds two cards*/
		if(post.handCount[player] == pre.handCount[player] + 2){
			printf("playAdventurer: PASS two cards added to player hand.\n");
			handCountPass++;
		}
		else{
			printf("playAdventurer: FAIL two cards added to player hand.\n");
		}
		
		/*Test return value 0*/
		if(r == 0){
			printf("playAdventurer: PASS exit code 0.\n");
			returnValuePass++;
		}
		else
			printf("playAdventurer: FAIL exit code 0.\n");
		
		/*Check is treasure is added to hand*/
		for(k = 0; k < pre.handCount[player]; k++){
			if(pre.hand[player][k] == copper || pre.hand[player][k] == silver || pre.hand[player][k] == gold)
				preTreasure++;
		}
		
		for(k = 0; k < post.handCount[player]; k++){
			if(post.hand[player][k] == copper || post.hand[player][k] == silver || post.hand[player][k] == gold)
				postTreasure++;
		}
		
		if(postTreasure == preTreasure + 2){
			printf("playAdventurer: PASS draw two treasure cards.\n");
			treasureDrawPass++;
		}
		else
			printf("playAdventurer: FAIL draw two treasure cards.\n");

		/*Test other players do not draw cards*/
		for(k = 0; k <= pre.numPlayers; k++){
			if(k != p)
			{
				if(post.handCount[k] == pre.handCount[k]){
					printf("playAdventurer: PASS other player %d did not draw card.\n", k);
					otherPlayerDrawPass++;
				}
					
				else {
					printf("playAdventurer: FAIL other player %d did not draw card.\n", k);
					otherPlayerDrawFail++;
				}
				if(post.deckCount[k] == pre.deckCount[k]){
					printf("playAdventurer: PASS other player %d deck is same size.\n", k);
					otherPlayerDeckPass++;
				}
				else{
					printf("playAdventurer: FAIL other player %d deck is dame size.\n", k);
					otherPlayerDeckFail++;
				}
				if(post.discardCount[k] == pre.discardCount[k]){
					printf("playAdventurer: PASS other player %d did not discard cards.\n", k);
					otherPlayerDiscardPass++;
				}
				else{
					printf("playAdventurer: FAIL other player %d did not discard cards.\n", k);
					otherPlayerDiscardFail++;
				}				
			}
		}	
		
		/*Test players discards cards*/
		for(k = pre.discardCount[p]; k < post.discardCount[p]; k++){
			if(post.discard[p][k] == copper || post.discard[p][k] == silver || post.discard[p][k] == gold) {
				treasureDiscard++;
			}
		}
		if(treasureDiscard > 0)
			printf("playAdventurer: FAIL treasure discarded.\n");
		else{
			printf("playAdventurer: PASS treasure not discarded.\n");
			treasureDiscardPass++;
		}
			
		if(post.discardCount[p] > 0){
			printf("playAdventurer: PASS player discarded cards.\n");
			playerDiscardPass++;
		}
		else
			printf("playAdventurer: FAIL player discarded cards.\n");
		
			printf("-------- END TEST %d --------\n\n", i);
	}

	printf("-------- TEST STATISTICS --------\n");
	printf("Tests passed for player drawing two cards: %d\n", handCountPass);
	printf("Tests passed for return value: %d\n", returnValuePass);
	printf("Tests passed for player drawing treasure cards: %d\n", treasureDrawPass);
	printf("Tests passed for other players not drawing cards: %d\n", otherPlayerDrawPass);
	printf("Tests failed for other players not drawing cards: %d\n", otherPlayerDrawFail);
	printf("Tests passed for other players not deck the same size: %d\n", otherPlayerDeckPass);
	printf("Tests failed for other players not deck the same size: %d\n", otherPlayerDeckFail);
	printf("Tests passed for other players not discarding cards: %d\n", otherPlayerDiscardPass);
	printf("Tests failed for other players not discarding cards: %d\n", otherPlayerDiscardFail);
	printf("Tests passed for player not discarding treasure cards: %d\n", treasureDiscardPass);
	printf("Tests passed for players discarding cards: %d\n", playerDiscardPass);
	printf("-------- END STATISTICS --------\n\n");

}	

int main(int argc, char *argv[])
{	
	srand(time(0));
    testPlayAdventurer();
    return 0;
}