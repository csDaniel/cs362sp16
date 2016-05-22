#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


 {
        void function2(){
        //This is a unit test for the shuffle function
          int i;
	  state->deckCount[player]= state->deckCount[MAX_PLAYERS+1];
          i= shuffle(1, state)
          assert(i==0);
	  state->deckCount[player]= state->deckCount[player];
	  i= shuffle(3, state)
	  assert(i==1);
	
          }
       
       int main()
       {
           function2();
           return 0;
       }
                                                        
