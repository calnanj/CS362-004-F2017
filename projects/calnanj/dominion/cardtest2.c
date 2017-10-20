/// Jessica Calnan
/// CS 362 Fall 2017
/// Assignment 3 Due 10/22/17
/// Card Test: Smithy

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() 
{

	
	int  j, pass;
	int c[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy}; //cards
	
	
	struct gameState GS;
	
	printf("\nStart of Card Test: Smithy\n"); //message to indicate the card test has begun
	
	j = initializeGame(2, c, 2, &GS);
	
	assert(j == 0);
	
	GS.hand[0][0] = smithy;
	GS.handCount[0] = 1;
	GS.discardCount[0] = 0;
	
	GS.deck[0][0] = copper; //deck cards (coin cards)
	GS.deck[0][1] = silver;
	GS.deck[0][2] = gold;
	GS.deckCount[0] = 3;
	
	playCard(0, 0, 0, 0, &GS);
	
	pass = 1;
	if (GS.handCount[0] != 3) {
		printf("Hand count is wrong.\nIt is: %d\nIt should be: 3\n", GS.handCount[0]);
		pass = 0;
	}
	if (GS.discardCount[0] != 1) {
		printf("Discard count is wrong.\nIt is: %d\nIt should be: 1\n", GS.discardCount[0]);
		pass = 0;
	}
	if (GS.deckCount[0] != 0) {
		printf("Deck count is wrong.\nIt is %d\nIt should be: 0\n", GS.deckCount[0]);
		pass = 0;
	}
	if (GS.numActions != 0) {
		printf("Action count is wrong.\nIt is: %d\nIt should be: 0\n", GS.numActions);
		pass = 0;
	}
	
	if(pass);
	
	printf("\nPass\n");
	
	printf ("\nEnd of Card Test: Smithy\n"); //message to indicate the test has finished
	return 0; //exit
}
