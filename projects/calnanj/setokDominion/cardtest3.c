/// Jessica Calnan
/// CS 362 Fall 2017
/// Assignment 3 Due 10/22/17
/// Card Test: Embargo

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv)	//argument count and num arguments passed to function
{
	struct gameState GS;
	int n;
	
	printf ("\nStart of Card Test: Embargo\n"); //message to indicate the card test has begun

	n = cardEffect(embargo, 0, 0, 0, &GS, 1, 0);
	assert(n == 0);
	assert(GS.coins == 2);
	printf ("\nPass\n");

	printf ("\nEnd of Card Test: Embargo\n"); //message to indicate the test has finished

	return 0; //exit
}