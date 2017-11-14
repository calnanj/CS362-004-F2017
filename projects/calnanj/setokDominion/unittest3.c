/// Jessica Calnan
/// CS 362 Fall 2017
/// Assignment 3 Due 10/22/17
/// Unit Test: Whose Turn

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
    int n;
	int c[10] = {sea_hag, tribute, smithy, village, minion, mine, adventurer, gardens, embargo, cutpurse}; //cards
	
	printf ("\nStart Test: Whose Turn\n"); //message that testing has begun
	
	printf("\nTest Pass Expected: 3 times\n"); //loop through 3 times and expecting 3 passes
	
    for (int i = 2 ; i < 5 ; ++i)	{
        n = initializeGame(2, c, 5, &GS);
        n = whoseTurn(&GS);
        assert(n == GS.whoseTurn);
		printf("\nPass\n");		
	}

	printf("\nEnd of Test: Whose Turn\n"); //message that testing has ended

	return 0; //exit
} 