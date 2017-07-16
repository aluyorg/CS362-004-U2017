#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

// UnitTest for Steward

int main (int argc, char** argv) {

  struct gameState G;
  int choice1 = 0, choice2 = 0, choice3 = 0;
  int temp;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, steward, smithy};


  initializeGame(2, k, 2, &G);


  choice1 = 1;
  temp = numHandCards(&G);
  cardEffect(steward, choice1, choice2, choice3, &G, NULL);

  assert(numHandCards(&G) == temp + 1);
  printf("Steward test passed\n");

}