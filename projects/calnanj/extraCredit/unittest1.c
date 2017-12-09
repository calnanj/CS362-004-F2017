/// Jessica Calnan
/// CS 362 Fall 2017
/// Assignment 3 Due 10/22/17
/// Unit Test: Is Game Over

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv) //argument count and num arguments passed to function
{
	struct gameState GS;
	int c[10] = { sea_hag, tribute, smithy, village, minion, mine, adventurer, gardens, embargo, cutpurse }; //cards
	int n = initializeGame(2, c, 3, &GS);
	
	printf("\nBegin Testing: Is Game Over\n"); //message that testing has begun

	int i = isGameOver(&GS); //did the test pass?
	assert(i == 0);
	printf("\n Pass \n");

	printf("\nEnd of Test: Is Game Over\n"); //message that testing has ended
	
	assert(n == 0);
	return 0; //exit
} 
