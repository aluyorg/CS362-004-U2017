#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);
int smithyRef(int currentPlayer,struct gameState *state,int handPos);
int adventurerRef(int drawntreasure,struct gameState *state,int currentPlayer,int cardDrawn,int temphand[MAX_HAND],int z);
int villageRef(int currentPlayer,struct gameState *state,int handPos);
int mineRef(struct gameState *state,int currentPlayer,int choice1,int choice2,int j,int i,int handPos);
int embargoRef(struct gameState *state,int choice1,int handPos,int currentPlayer);
#endif
