#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define NUM_TESTS 10
#define CARD_COUNT treasure_map

int main(){
	
	int i,j, player_count, player, seed, deck_treasures, hand_count, pre_count , post_count;
	int n[10] = {curse,estate,duchy,province,copper,baron, smithy, treasure_map, minion, steward};
	srand(time(NULL));   
	struct gameState GS;
	
	printf("Beginning of Random Test: Adventurer\n");	//refactored in assignment 3 (manditory test for assignment 4)
	//Loop
	for(i = 0;i < NUM_TESTS; i++){ 
		pre_count = 0; post_count = 0;
  		player_count = rand() % 3 + 2;
		seed = rand() % 100;	
		//when game initialized:
		if(initializeGame(player_count, n, seed, &GS) == -1){ 
			printf("Error with initialization\n");
			exit(0);
		}
		// random player
		player = rand() % player_count; 
		GS.whoseTurn = player;
		GS.numActions = 1;
		GS.handCount[player] = 5;
		GS.deckCount[player] = rand() % MAX_HAND;
		GS.discardCount[player] = 0;
		
		//random deck
		for(j = 0; j < GS.deckCount[player]; j++){
			GS.deck[player][j] = rand() % CARD_COUNT;
			if(GS.deck[player][j] >= copper && GS.deck[player][j] <= gold){ 
				deck_treasures++;
			}
		}
		//random hand
		for(j = 0; j < GS.handCount[player]; j++){	
			GS.hand[player][j] = rand() % CARD_COUNT;
			if(GS.hand[player][j] >= copper && GS.hand[player][j] <= gold){ 
				pre_count++;	}
		}
	
		GS.hand[player][0] = adventurer; 
		hand_count = GS.handCount[player];
		playCard(0, 0, 0, 0, &GS); 
		//2 cards added to hand
		if(hand_count + 2 != GS.handCount[player]){
			printf("Error! Can't add 2 cards to the player's hand\n");
			exit(0);	
		}
		
		for(j = 0; j < GS.handCount[player]; j++){
			if(GS.hand[player][j] >= copper && GS.hand[player][j] <= gold)
					post_count++;
		}
		printf("Pre Count: %d\n", pre_count);
		printf("Post Count: %d\n", post_count);
		
		if(pre_count + 2 != post_count){
			printf("Error! Can't add 2 cards to the player's hand\n");
			exit(0);	
		}
		printf("Iteration #%d: \n", i);
		
	}
	printf("End of Random Test: Adventurer\n");	
	return 0;
}

