#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

//Unit Test for getCost game function


int main(){

  assert(getCost(0) == 0);

  assert(getCost(adventurer) == 6);

  assert(getCost(village) == 3);

  assert(getCost(baron) == 4);

  return 0;
}