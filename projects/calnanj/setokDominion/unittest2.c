/// Jessica Calnan
/// CS 362 Fall 2017
/// Assignment 3 Due 10/22/17
/// Unit Test: Update Coins

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
	
int main (int argc, char** argv)	//argument count and num arguments passed to function
{
	struct gameState GS;
	GS.coins = 0;
	
	printf("\nBegin Testing: Update Coins\n"); //message that testing has begun
	
	//must test all three coin types (silver, gold, copper)
	//must test that another card (not a coin card) will yield zero coins 
	
	printf("\nWe will start by testing zero coins\n");
	GS.hand[0][1] = smithy;
	GS.hand[0][2] = smithy;
	GS.hand[0][3] = smithy;
	GS.hand[0][4] = smithy;
	GS.hand[0][5] = smithy;
	GS.hand[0][6] = smithy;
	GS.hand[0][7] = smithy;
	GS.hand[0][8] = smithy;
	GS.hand[0][9] = smithy;
	updateCoins(0,&GS, 0);
	printf("\nWe should have no coins: %d\n", GS.coins);
	if(GS.coins == 0)
		printf("\nPass"); //did the test pass?
	else
		printf("\nFail");
	
	//begin coin cards tests
	printf("\nThen, we will test gold coins\n");
	GS.hand[0][0] = gold;
	GS.hand[0][1] = gold;
	GS.hand[0][2] = gold;
	GS.hand[0][3] = gold;
	GS.hand[0][4] = gold;
	GS.hand[0][5] = gold;
	GS.hand[0][6] = gold;
	GS.hand[0][7] = gold;
	GS.hand[0][8] = gold;
	GS.hand[0][9] = gold;
	updateCoins(0,&GS, 0);
	printf("\nThere should be 10 gold coins: %d\n", GS.coins);
	if(GS.coins == 10)
		printf("\nPass\n"); //did the test pass?
	else
		printf("\nFail\n");
	
	printf("\nNext, we will test silver coins\n");
	GS.hand[0][0] = silver;
	GS.hand[0][1] = silver;
	GS.hand[0][2] = silver;
	GS.hand[0][3] = silver;
	GS.hand[0][4] = silver;
	GS.hand[0][5] = silver;
	GS.hand[0][6] = silver;
	GS.hand[0][7] = silver;
	GS.hand[0][8] = silver;
	GS.hand[0][9] = silver;
	updateCoins(0,&GS, 0);
	printf("\nThere should be 10 silver coins: %d\n", GS.coins);
	if(GS.coins == 20)
		printf("\nPass\n"); //did the test pass?
	else
		printf("\nFail\n");
	
	printf("\nFinally, we will test copper coins\n");
	GS.hand[0][1] = gold;
	GS.hand[0][2] = gold;
	GS.hand[0][3] = gold;
	GS.hand[0][4] = gold;
	GS.hand[0][5] = gold;
	GS.hand[0][6] = gold;
	GS.hand[0][7] = gold;
	GS.hand[0][8] = gold;
	GS.hand[0][9] = gold;
	updateCoins(0,&GS, 0);
	printf("\nThere should be 10 copper coins: %d\n", GS.coins);
	if(GS.coins == 30)
		printf("\nPass\n"); //did the test pass?
	else
		printf("\nFail\n");
	
	printf("\nEnd of Test: Update Coins******\n"); //message that testing has ended

	return 0; //exit
}
