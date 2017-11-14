#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>


#define MAX_TESTS 10000

int main() {

	int n[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int i, j, players, player, seed, errors = 0;
	struct gameState GS;
	struct gameState tempState; 
	srand(time(NULL));
	printf("Beginning of Random Card Test: Village\n"); // card not refactored in Assignment 3
	for (i = 0; i < MAX_TESTS; i++) {
		do {
			players = rand() % 4;
		} while (players < 2);

		seed = rand();		// random seed
		initializeGame(players, n, seed, &GS);	//initialize Gamestate 

		do {
			player = rand() % players; 
		} while (player == 0);	

		// initiate GS vars
		GS.whoseTurn = player;
		GS.deckCount[player] = rand() % MAX_DECK; // random deck size
		GS.discardCount[player] = rand() % MAX_DECK;
		GS.handCount[player] = rand() % MAX_HAND;
		GS.hand[player][0] = village;
		GS.numActions = rand() % 10; 
		memcpy(&tempState, &GS, sizeof(struct gameState));
		j = cardEffect(village, 0, 0, 0, &GS, 0, 0);		// run card
		assert (j == 0);
		if (GS.deckCount[player] != (tempState.deckCount[player] - 1)) { errors++; }
		if (GS.numActions != (tempState.numActions + 2)) { errors++; }		// village card = +2 actions

	}	
	printf("Errors: %d\n", errors);
	printf("End of Random Card Test: Village\n");
	return 0;
}
