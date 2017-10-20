/// Jessica Calnan
/// CS 362 Fall 2017
/// Assignment 3 Due 10/22/17
/// Card Test: Adventurer

#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>

int main (int argc, char** argv) //argument count and num arguments passed to function
{
  struct gameState *GS = newGame();
  int players = 2;
  int rand = 60; 
  int c[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  int status = initializeGame(players, c, rand, GS); //initialize game
  if(status == 0){
	printf( "\nStart of Card Test: Adventurer\n");} //message to indicate the testing has begun
  
  int cards = 0;
  buyCard(smithy, GS);
  int result = cardEffect(adventurer, cards, cards, cards, GS, 0, NULL);
  if(result == 0){
	printf( "Pass! End of Test: Adventurer\n");}  


  return 0; //exit
}
