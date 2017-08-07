
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define TEST_RUNS 1000

int main() {
    int i, j, r, z;
    int numPlayer;
    int bugCount = 0;
    int flag = 0; // flag for other player piles
	struct gameState G, prevG;
	int seed = 1000;
	srand(time(NULL));
	int k[10]; // for kingdom cards
	int numKingdomCards;
	bool haveCard;
	int numDraw;
	int pass = 0; 
	int fail = 0; 

	printf("Smithy\n");
    
	for(z = 1; z <= 1000; z++) // test for loop
	{
		// random kingdom cards set (9 random with smithy card)
		numKingdomCards = 0;
		while(numKingdomCards < 10)
		{
			haveCard = false;
			r = (rand() % 20 + 7); // gets a random kingdom card
			
			// check if already have card in kingdom set k
			i = 0;
			while(i < numKingdomCards)
			{
				if(k[i] == r)
					haveCard = true;
				i++;
			}
			// if we don't have it, add it to k set and increment the numKingdomCards
			if(!haveCard)
			{
				k[numKingdomCards] = r;
				numKingdomCards++;
			}
		}
		// now with random set, we have to make sure smithy card is in the kingdom pile
		// if not we'll randomly replace one of the 10 kindgom cards with an smithy.
		haveCard = false;
		// check 10 kingdom pile for smithy
		i =0;
		while(i < 10)
		{
			if(k[i] == smithy)
				haveCard = true;
			i++;
		}
		// no smithy found, have to randomly add it.
		if(!haveCard)
		{
			r = (rand() % 10); // random position
			k[r] = smithy;
		}
		
		// random number of players from 2 to 5
		numPlayer = ((rand() % 3) + 2);
		
		printf(" Starting Test #%d for Smithy\n", z);
		
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G); // initialize a new game
		
		// set random deck count for each player
		for(i = 0; i < numPlayer; i++)
			G.deckCount[i] = (rand() % (MAX_DECK/numPlayer));
		
		// fill each players' decks with random cards
		for(i = 0; i < numPlayer; i++)
		{
			for(j = 0; j < G.deckCount[i]; j++) 
			{
				r = rand() % 3;
				switch(r) 
				{
					case 0: G.deck[i][j] = (rand() % 4); // victory card 
						break;
					case 1: G.deck[i][j] = (rand() % 3) + 4; // treasuer card 
						break;
					case 2: G.deck[i][j] = k[(rand() % 10)]; // kingdom card 
						break;
				}
			}
		}
		
		// initialize counters
		bugCount = 0;
		
		memcpy(&prevG, &G, sizeof(struct gameState)); //create clone of game state to run tests on
		smithy_func(G.handCount[0],&G);
		
		printf("Deck Count before Smithy: %d\n", prevG.deckCount[0]);
		printf("Deck Count after Smithy: %d\n", G.deckCount[0]);
		
		// if there are less than 3 cards, smithy can only draw what is available
		// figure out how much should be drawn
		numDraw = 3;
		
		if (prevG.deckCount[0] < 3)		
			numDraw = prevG.deckCount[0] - G.deckCount[0];
		
		// check if hand count correct after Smithy 
		printf("\nChecking hand count is correct after using refactored Smithy.\n");
		printf("Previous hand count: %d, After Smithy: %d\n", prevG.handCount[0], G.handCount[0]);
		printf("Expected hand count after Smithy: %d\n", (prevG.handCount[0] + numDraw - 1));
		if((prevG.handCount[0] + numDraw - 1) != G.handCount[0])
		{
			printf("Bug->Ended with the incorrect number of cards in hand after Smithy.\n");
			bugCount=bugCount+1;
		}
		else
			printf("Ended with the correct number of cards in hand after Smithy.\n");

		// check if Smithy drew the correct cards from deck
		printf("\nChecking if refactored Smithy drew enough cards to hand.\n");
		printf("Previous deck count: %d, After Smithy: %d\n", prevG.deckCount[0], G.deckCount[0]);
		printf("Smithy drew: %d cards. Expected to draw %d cards.\n", (prevG.deckCount[0] - G.deckCount[0]), numDraw);
		if((prevG.deckCount[0] - G.deckCount[0]) != numDraw){
			printf("Bug->Smithy didn't draw correct nunmber of cards from the deck.\n");
			bugCount=bugCount+1;
		}
		else
			printf("Great! Smithy drew correct number of cards from deck.\n");

		// check if smithy altered other player's cards
		printf("\nChecking if refactored Smithy altered other player's hand.\n");
		if(prevG.handCount[1] != G.handCount[1]){
			printf("Bug->Smithy altered other player's cards\n");
			bugCount=bugCount+1;
		}
		else if(prevG.deckCount[1] != G.deckCount[1]){
			printf("Bug->Smithy altered other player's cards\n");
			bugCount=bugCount+1;
		}
		else if(prevG.discardCount[1] != G.discardCount[1]){
			printf("Bug->Smithy altered other player's cards\n");
			bugCount=bugCount+1;
		}
		else
			printf("No Bugs in Smithy\n");
		
		// check if Smithy altered the victory and kingdom piles
		printf("\nChecking if refactored Smithy altered the Victory and Kingdom piles.\n");
		int arraySize = sizeof(G.supplyCount) / sizeof(int);
		for(i = 0; i < arraySize; i++){
			if(G.supplyCount[i] != prevG.supplyCount[i])
				flag = 1;
		}
		if(flag == 0)
			printf("No bugs in Smithy\n");
		else
		{
			printf("Bug->Kingdom/Victory supplied have been altered\n");
			bugCount=bugCount+1;
		}

		// output the test results overall
		printf(" Test #%d results for Smithy\n", z);
		if(bugCount == 0)
		{
			printf("All tests passed for the Smithy!\n\n");
			pass=pass+1;
		}
		else if(bugCount != 0)
		{
			printf("Smithy failed for %d condition(s), check above for which ones.\n\n", bugCount);
			fail=fail+1;
		}
	}

	if(fail == 0)
		printf("All Smith Tests Passed");
	else if(fail != 0)
		printf("Smithy passed %d tests and failed %d tests", pass, fail);
		
	return 0;
}
