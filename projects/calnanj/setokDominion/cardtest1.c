/// Jessica Calnan
/// CS 362 Fall 2017
/// Assignment 3 Due 10/22/17
/// Card Test: Great Hall

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
	int tmp;
	
	printf ("\nStart of Card Test: Great Hall\n"); //message to indicate the card test has begun

	GS.numActions = 0;
	GS.handCount[0] = 1;
	GS.hand[0][0] = great_hall;
	tmp = cardEffect(great_hall, 0, 0, 0, &GS, 0, 0);
	assert(tmp == 0);
	//assert(GS.handCount[0] == 1);
	assert(GS.numActions == 1);
	printf("\nPass\n");
	
	printf ("\nEnd of Card Test: Great Hall\n"); //message to indicate the test has finished
	
	return 0; //exit
}
