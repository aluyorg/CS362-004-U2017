#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

//Unit Test for whoseTurn()

int main(){

  struct gameState state;

  int turn = 0;
  int s = 0;

  for (int i = 0; i < 15; i++){
    state.whoseTurn = turn;
    s = whoseTurn(&state);

    assert(s == turn);

    turn++;
  }
  printf("whoseTurn test passed\n");
  return 0;
}
