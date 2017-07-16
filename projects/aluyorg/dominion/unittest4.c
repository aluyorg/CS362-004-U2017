#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>'

//Unit Test for buyCard

int main(){

  struct gameState state;
  int s;
  int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  initializeGame(2, k, 2, &state);

  state.numBuys = 0;

  s = buyCard(5, &state);

  assert(s == -1);

  state.numBuys = 5;

  state.coins = 0;

  s = buyCard(5, &state);

  assert(s == -1);

  state.coins = 100;

  s = buyCard(5, &state);

  assert(s == 0);

  printf("buyCard test passed\n");
  return 0;
}