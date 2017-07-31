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
	int pass = 0; // track the number of passes
	int fail = 0; // track the number of fails
		
	printf(" Testing Village\n");	
	
	for(z = 1; z <= 1000; z++) // test for loop
	{
		// random kingdom cards set (9 random with Village card)
		numKingdomCards = 0;
		while(numKingdomCards < 10)
		{
			haveCard = false;
			r = (rand() % 20 + 7); // gets a random kingdom card
			
			// check if already have card in kingdom set k
			for(i = 0; i < numKingdomCards; i++)
				if(k[i] == r)
					haveCard = true;
			
			// if we don't have it, add it to k set and increment the numKingdomCards
			if(!haveCard)
			{
				k[numKingdomCards] = r;
				numKingdomCards++;
			}
		}
		// now with random set, we have to make sure Village card is in the kingdom pile
		// if not we'll randomly replace one of the 10 kindgom cards with an Village.
		haveCard = false;
		// check 10 kingdom pile for Village
		for(i = 0; i < 10; i++)
		{
			if(k[i] == village)
			{
				haveCard = true;
			}
		}
		// no Village found, have to randomly add it.
		if(!haveCard)
		{
			r = (rand() % 10); // random position
			k[r] = village;
		}
		
		// random number of players from 2 to 5
		numPlayer = ((rand() % 3) + 2);
		
		printf(" Starting Test #%d for Village\n", z);
		
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
		
		// set random actions count for each player
		G.numActions = ((rand() % 50) + 1);

		// initialize counters
		bugCount = 0;
		
		memcpy(&prevG, &G, sizeof(struct gameState)); //create clone of game state to run tests on
		village_func(G.handCount[0], &G);
		
		printf("Deck Count before Village: %d\n", prevG.deckCount[0]);
		printf("Deck Count after Village: %d\n", G.deckCount[0]);
		
		// if there are less than 1 cards, village can only draw what is available
		// figure out how much should be drawn
		numDraw = 1;
		
		if (prevG.deckCount[0] < 1)		
			numDraw = prevG.deckCount[0] - G.deckCount[0];
		

		// check if hand count correct after Village
		printf("\nChecking hand count is correct after using refactored Village.\n");
		printf("Previous hand count: %d cards, After Village: %d cards\n", prevG.handCount[0], G.handCount[0]);
		printf("Expected hand count after using Village is %d.\n", prevG.handCount[0] - 1 + numDraw);
		if(G.handCount[0] == prevG.handCount[0] -1 + numDraw){
			printf("Ended with the correct number of cards in hand after Village.\n");
			bugCount = bugCount+1;
		}
		else
			printf("Bug->Ended with the incorrect number of cards in hand after Village.\n");

		// check if Village drew the correct cards from deck
		printf("\nChecking if refactored Village card drew enough cards to hand.\n");
		printf("Previous deck count: %d cards, After Village: %d cards\n", prevG.deckCount[0], G.deckCount[0]);
		printf("Village drew: %d card. Expected to draw 1 card\n", prevG.deckCount[0] - G.deckCount[0]);
		if((prevG.deckCount[0] - G.deckCount[0]) != numDraw){
			printf("Bug->Village didn't draw correct nunmber of cards from the deck.\n");
			bugCount = bugCount+1;
		}
		else
			printf("Village drew correct number of cards from deck.\n");

		// check if Village gave player +2 actions
		printf("\nChecking if refactored Village gave player +2 actions.\n");
		printf("Previous actions count: %d, After Village: %d\n", prevG.numActions, G.numActions);
		printf("Expected to get +2 actions after using Village.\n");
		if((G.numActions - prevG.numActions) != 2){
			printf("Bug->Village didn't add +2 actions for player as it should.\n");
			bugCount = bugCount+1;
		}
		else
			printf("Village added +2 actions for player.\n");

		// check if Village altered other player's piles 
		printf("\nChecking if refactored Village altered other player's hand.\n");
		if(prevG.handCount[1] != G.handCount[1]){
			printf("Bug-> Village altered other player's hand pile.\n");
			bugCount = bugCount+1;
		}
		else if(prevG.deckCount[1] != G.deckCount[1]){
			printf("Bug->Village altered other player's deck pile.\n");
			bugCount = bugCount+1;
		}
		else if(prevG.discardCount[1] != G.discardCount[1]){
			printf("Bug->Village altered other player's discard pile.\n");
			bugCount = bugCount+1;
		}
		else
			printf("Village didn't altered other player's piles.\n");
		
		// check if Village altered the victory and kingdom piles
		printf("\nChecking if refactored Village altered the Victory and Kingdom piles.\n");
		int arraySize = sizeof(G.supplyCount) / sizeof(int);
		for(i = 0; i < arraySize; i++){
			if(G.supplyCount[i] != prevG.supplyCount[i]){
				flag = 1;
			}
		}
		if(flag == 0)
			printf("Village didn't alter the Victory and Kingdom piles.\n");
		else
		{
			printf("Bug->Kingdom/Victory supplied have been altered!\n");
			bugCount = bugCount+1;
		}

		// output the test results overall
		printf(" Test #%d results for Village\n", z);

		if(bugCount == 0)
		{
			printf("All tests passed for the Village!\n\n");
			pass = pass + 1;
		}
		else if(bugCount != 0)
		{
			printf("Village failed for %d condition(s), check above for which ones.\n\n", bugCount);
			fail = fail + 1;
		}
		
	}
	
	// output the final test results overall
	printf(" Final Testing results for Village\n");

	if(fail == 0)
		printf("All tests passed for the Village! Amazing!\n\n");
	else if(fail != 0)
		printf("Village passed %d tests and failed %d tests, check above for which ones.\n\n", pass, fail);
		
	return 0;
}