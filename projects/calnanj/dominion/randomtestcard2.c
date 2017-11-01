#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


#define DEBUG 0
#define NOISY_TEST 1

int cardSmithy(struct gameState *GS, int *currPlayer, int *handPos);

int rand_num(int min, int max){
    int result=0,low=0,hi=0;
    if(min < max)
    {
        low = min;
        hi = max + 1; // includes max in output
    }else{
        low = max + 1; // includes max in output
        hi = min;
    }
    srand(time(NULL));
    result = (rand()%(hi - low ))+low;
    return result;
}

int main(int argc, char const *argv[]){
	
	struct gameState GS;

	int i, j;
	int n[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int card;

	// initialize smithy vars
	int currPlayer;
	int handPos = -1;
	int handCards;



	for (i = 0; i < rand_num(0, 100); i ++){ // loop random # of times <100
		initializeGame(rand_num(2,4), n, rand_num(1, 9), &GS); // random seed

		for (j = 0; j < 10000; j++){ // run 10000 times w/rand vars
			currPlayer = GS.whoseTurn;

			handCards = GS.handCount[currPlayer];

			if((card = cardSmithy(&GS, &currPlayer, &handPos)) != 0)
				printf("Error: Smithy returned something other than 0. Random Game[%d] iteration[%d]\n", i, j);
			
			if (handCards <= GS.handCount[currPlayer])
				printf("Error: Player did not draw enough cards. Random Game[%d] iteration[%d]\n", i, j);
			
			GS.outpostPlayed = 0;
  			GS.phase = 0;
			GS.numActions = 1;
			GS.numBuys = 1;
			GS.playedCardCount = 0;
			GS.whoseTurn = rand_num(2, GS.numPlayers);
			GS.handCount[GS.whoseTurn] = 0;
		}
	}

	return 0;
}
