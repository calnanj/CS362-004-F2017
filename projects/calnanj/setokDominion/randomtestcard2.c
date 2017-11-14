//  Jessica Calnan
//  CS 362-004-F2017 
//  Assignment 5 (Due 11/19/17)
//  randomtestcard2.c
//  Random Test for Smithy Card
//  Refactored from previous assignment to test on setok's code

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dominion.h"
#include "rngs.h"

// Smithy: Draw 3 Cards

int main()
{
    srand(time(NULL));
    
    struct gameState GS;
    
    int players = (rand() % MAX_PLAYERS - 1) + 2; 
    int tests = 500;
    int random = 0;
    int i, deckCount;
    int err = 0;
    int pass = 0;
    
    int k[10] = {adventurer, council_room, minion, feast, mine, smithy, steward, village, tribute, sea_hag};
    
    printf("Random Test: Smithy Card\n");
    
    
    for (i = 0; i < tests; i++)
    {
        int seed = rand();
        
        struct gameState prev;
        initializeGame(players, k, seed, &GS);
        
        int currPlayer = rand() % players;
        
        random = rand() % 10;
        if (random == 5)
        {
            GS.deckCount[currPlayer] = 0;
            deckCount = 0;
        }
        else
        {
            deckCount = rand() % MAX_DECK;
            GS.deckCount[currPlayer] = deckCount;
        }
        
        GS.handCount[currPlayer] = rand() % MAX_HAND;
        
        GS.discardCount[currPlayer] = rand() % MAX_DECK;
        
        int cardA = rand() % 10;
        int cardB = rand() % 10;
        int cardC = rand() % 10;
        
        memcpy(&prev, &GS, sizeof(struct gameState));
       
        GS.hand[currPlayer][0] = smithy;
        cardEffect(smithy, cardA, cardB, cardC, &GS, 0, 0);
        
        // check +3 cards??
        if(GS.handCount[currPlayer] != prev.handCount[currPlayer] + 3)
        {
            err++;
            printf("There were not 3 cards added\n");
        }
        else pass++;
        
        // discard count accurate??
        if(GS.discardCount[currPlayer] != prev.discardCount[currPlayer] + 1)
        {
            err++;
            printf("Discard count not accurate\n");
        }
        else pass++;
        
        // smithy discarded??
        if (GS.hand[currPlayer][0] != smithy)
        {
            pass++;
        }
        else
        {
            err++;
            printf("Smithy card not discarded\n");
        }
        
        
    }
    printf("End of Random Test: Smithy Card\n");
    printf("There were %d errors\n", err);
    printf("%d of the tests passed\n", pass);

}
