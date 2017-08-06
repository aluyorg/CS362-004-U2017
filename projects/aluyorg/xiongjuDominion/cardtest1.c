#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


// Unit Test for Adventurer

int main (int argc, char** argv) {

  struct gameState G;
  int choice1 = 0, choice2 = 0, choice3 = 0;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  initializeGame(2, k, 4, &G);

  assert(cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL) == 0);
  printf("Adventurer test passed\n");

}
