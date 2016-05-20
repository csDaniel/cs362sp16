/*
Author: Ryan Peters
Date: 04/20/16
Description: Unit test for updateCoins().  There are test for all coin
cards, hands containing only coins, hands without coins, and hands with
coins and other cards.  Test the bonus with both positive and negative 
numbers.
*/
#include<stdio.h>
#include "dominion.h"

void testUpdateCoins()
{
	int i;
	int player = 1;
	struct gameState state;
	
	state.handCount[player] = 5;
	
	/*Test with a hand of 5 copper cards*/
	for(i = 0; i < state.handCount[player]; i++)
	{
		state.hand[player][i] = copper;
	}	
	updateCoins(player, &state, 0);
	if(state.coins == 5)
		printf("updateCoins: PASS have five copper in hand.\n");
	else
		printf("updateCoins: FAIL have five copper in hand.\n");
	
	/*Test with a hand of 5 silver cards*/
	for(i = 0; i < state.handCount[player]; i++)
	{
		state.hand[player][i] = silver;
	}	
	updateCoins(player, &state, 0);
	if(state.coins == 10)
		printf("updateCoins: PASS have five silver in hand.\n");
	else
		printf("updateCoins: FAIL have five silver in hand.\n");
	
	/*Test with a hand of 5 gold coins*/
	for(i = 0; i < state.handCount[player]; i++)
	{
		state.hand[player][i] = gold;
	}	
	updateCoins(player, &state, 0);
	if(state.coins == 15)
		printf("updateCoins: PASS have five gold in hand.\n");
	else
		printf("updateCoins: FAIL have five gold in hand.\n");
	
	/*Test with a hand of 5 gold coins and a bonus of 5*/
	for(i = 0; i < state.handCount[player]; i++)
	{
		state.hand[player][i] = gold;
	}	
	updateCoins(player, &state, 5);
	if(state.coins == 20)
		printf("updateCoins: PASS have five gold in hand and 5 bonus.\n");
	else
		printf("updateCoins: FAIL have five gold in hand and 5 bonus.\n");
	
	/*Test with a hand of 5 gold coins and a bonus of -1*/
	for(i = 0; i < state.handCount[player]; i++)
	{
		state.hand[player][i] = gold;
	}	
	updateCoins(player, &state, -1);
	if(state.coins == 14)
		printf("updateCoins: PASS have five gold in hand and -1 bonus.\n");
	else
		printf("updateCoins: FAIL have five gold in hand and -1 bonus.\n");
	
	/*Test with a hand of 100 copper coins*/
	state.handCount[player] = 100;
	for(i = 0; i < state.handCount[player]; i++)
	{
		state.hand[player][i] = copper;
	}	
	updateCoins(player, &state, 0);
	if(state.coins == 100)
		printf("updateCoins: PASS have 100 copper in hand.\n");
	else
		printf("updateCoins: FAIL have 100 copper in hand.\n");
	
	/*Test with a hand containing coins and other cards*/
	state.handCount[player] = 5;
	state.hand[player][0] = copper;
	state.hand[player][1] = silver;
	state.hand[player][2] = gold;
	state.hand[player][3] = estate;
	state.hand[player][4] = adventurer;
	updateCoins(player, &state, 0);
	if(state.coins == 6)
		printf("updateCoins: PASS hand with different cards.\n");
	else
		printf("updateCoins: FAIL have with different cards.\n");	
	
	/*Test with a hand containing no coins*/
	for(i = 0; i < state.handCount[player]; i++)
	{
		state.hand[player][i] = estate;
	}	
	updateCoins(player, &state, 0);
	if(state.coins == 0)
		printf("updateCoins: PASS have no coins in hand.\n");
	else
		printf("updateCoins: FAIL have no coins in hand.\n");

}

int main(int argc, char *argv[])
{
    testUpdateCoins();
    return 0;
}