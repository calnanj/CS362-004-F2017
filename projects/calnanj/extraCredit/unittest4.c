/// Jessica Calnan
/// CS 362 Fall 2017
/// Assignment 3 Due 10/22/17
/// Unit Test: Buy Card

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main (int argc, char** argv) //argument count and num arguments passed to function	
{
	struct gameState GS;
	printf("\nStart Test: Buy Card\n"); //message that testing has begun
	
	GS.numBuys = 2;
	GS.coins = 2;
	printf("Need more coins to test\n");
 	int test = buyCard(2, &GS);
		if(test == -1)
			printf("\nPass\n"); //test pass? (1)
		else
			printf("\nFail\n");
	printf("Test: purchase\n");
	GS.coins = 10;
	test = buyCard(2, &GS);
		if(test == 0)
			printf("\nPass\n"); //test pass? (2)
		else
			printf("\nFail\n");
 	printf("Test: amount\n");
 	test = buyCard(2, &GS);
		if(test == 0)
			printf("\nPass\n"); //test pass? (3)
		else
			printf("\nFail\n");
 	printf("Test: purchases remaining\n");
 	GS.coins = 6;
	test = buyCard(2, &GS);
		if(test == -1)
			printf("\nPass\n"); //test pass all 3 times = pass for whole test
		else
			printf("\nFail\n");
		
 	printf("\nEnd of Test: Buy Card\n");  //message that testing has ended
	
 	return 0;	 //exit
}