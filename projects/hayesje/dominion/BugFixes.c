/*
#################################################################################
                                   BUG FIXES
##################################################################################

BUG 1: Teammate 1 - Smithy Card

       Description: Test results show that only 2 cards are drawn from the deck

       Bug Identification: Looking at teammate1 smithyCard code, the bug is easily
            spotted in the for loop controlling the number of cards.

            Bad code:  loop only iterates 2 times.
                 for (i = 0; i < 2; i++) {
                    drawCard(currentPlayer, state);
                 }
 
            Fixed code:  loop iterates 3 times
                 for (i = 0; i <= 2; i++) {
                      drawCard(currentPlayer, state);
                 }

       Unit Test Summary after Fix:
            Unit Test: cardtest1.c
               Target: Smithy Card
               Status: PASSED
               Passed: 24
               Failed: 0

       Random Test Summary after Fix
              randomtestcard => Passed:1000  Failed:0

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

BUG 2: Teammate 1 - Adventurer Card

       Description: Cards continue to be drawn from deck after 2 treasure cards have 
               been revealed

       Bug Identification: Looking at teammate1 adventurerCard code, the bug is easily
               spotted in the while loop controlling the number of treasure cards to be drawn

               Bad code:  loop attempts to find 4 treasure cards.
                    while(drawntreasure<4){
                        // do something
                     }
 
               Fixed code:  loop now attempts to find 2 treasure cards
                     while(drawntreasure<2){
                        // do something
                     }

       Unit Test Summary after First Fix:  (An improvement, however bugs remain)
            Unit Test: cardtest2.c
               Target: Adventurer Card
               Status: FAILED
               Passed: 16
               Failed: 16

       Random Test Summary after First Fix  (Segmentation faults remains)
            Segmentation fault (core dumped)


- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

BUG 3: Teammate 1 - Adventurer Card

       Description: Test results suggest that 'gold' is not recognized as treasure card

       Bug Identification: Looking at teammate1 adventurerCard code, the bug is easily 
           spotted in the condition statement that determines if a drawn card is a treasure
           card.

           Bad code: The code only recognizes copper and silver as treasure cards.
                  if (cardDrawn == copper || cardDrawn == silver)
                      // do something
                  }
 
           Fixed code:  Statement now includes 'gold' as a treasure card.
                  if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
                      // do something
                  }

       Unit Test Summary after Second Fix:
          Unit Test: cardtest2.c
             Target: Adventurer Card
             Status: PASSED
             Passed: 32
             Failed: 0

       Random Test Summary after Second Fix
             randomtestadventurer => Passed:1000  Failed:0

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

BUG 4: Teammate 2 - Smithy Card

       Description: Test results show that no cards are drawn from the deck.

       Bug Identification: Looking at teammate2 smithyCard code, the bug is easily 
              spotted in the for loop controlling the number of cards.

              Bad code:  loop never iterates.
                   for (i = 0; i > 3; i++)
                   {
                       drawCard(currentPlayer, state);
                   }
      	
              Fixed code:  loop iterates 3 times
                   for (i = 0; i < 3; i++) {
                       drawCard(currentPlayer, state);
                   }


       Unit Test Summary after Fix:
            Unit Test: cardtest1.c
               Target: Smithy Card
               Status: PASSED
               Passed: 24
               Failed: 0

       Random Test Summary after Fix
               randomtestcard => Passed:1000  Failed:0

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

BUG 5: Teammate 2 - Adventurer Card

       Description: Segmentation fault occurred when running both unit test and random test

       Bug Identification: Looking at teammate2 adventurerCard code, a bug is easily spotted in 
              a Boolean statement 

              Bad code: Assignment used rather than comparison in Boolean expression.
                   if (state->deckCount[currentPlayer] = 0) { 
	               shuffle(currentPlayer, state);
	           }
 
              Fixed code:  Boolean expression now does a comparison
                   if (state->deckCount[currentPlayer] == 0) { 
	              shuffle(currentPlayer, state);
	           }

    Unit Test Summary after Fix:
         Unit Test: cardtest2.c
            Target: Adventurer Card
            Status: PASSED
            Passed: 32
            Failed: 0


     Random Test Summary after Fix
          randomtestadventurer => Passed:1000  Failed:0


Summary:  All bugs were found by the non-random unit tests cardtest1 and cardtest2, with
          the exception of bug 5 which is found by code inspection.  An attempt was made
          using gdb on bug 5 (see below), however the debugger (or user) had difficultly
          seperating the cause from the effect of the fault.  The segmentation fault was being
          reported at line 1273, however the cause of the fault was the variable assignment
          in a Boolean expression on line 1259. Visual inspection quickly found the error. 
          Although the random testers did not find an error, they are actually better at
          finding errors when shuffles occur. 

          All bugs reported in my teammates refactor.c file for the Adventurer and Smithy 
          cards were found in test. Statement and branch coverage is 100% for both cards,
          however this wasn't particularly difficult with the combination of the unit testers
          and random testers.   

gdb debugging: 

    (gdb) run
    Starting program: /home/ubuntu/cs362/project/cs362sp16/projects/hayesje/teammate2Dominion/cardtest2 
    Unit Test: cardtest2.c
       Target: Adventurer Card

    Program received signal SIGSEGV, Segmentation fault.
    0x0000000000407050 in adventurerCard (cardDrawn=0, drawntreasure=2, state=0x7fffffff1750, currentPlayer=2, 
        temphand=0x7fffffff0f80, z=563) at dominion.c:1273
    1273  state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
    (gdb) 
   
          
#########################################################################################
                                    CODE COVERAGE
#########################################################################################
TEAMMATE 1:  Smithy Card  

        function smithyCard called 1024 returned 100% blocks executed 100%
         1024: 1041:int smithyCard(int handPos, int currentPlayer, struct gameState *state) {
            -: 1042:    int i;
         4096: 1043:    for (i = 0; i <= 2; i++) {
    branch  0 taken 75%
    branch  1 taken 25% (fallthrough)
         3072: 1044:    drawCard(currentPlayer, state);
    call    0 returned 100%
            -: 1045:  }
            -: 1046:
         1024: 1047:    discardCard(handPos, currentPlayer, state, 0);
    call    0 returned 100%
         1024: 1048:    return 0;
            -: 1049:}
            -: 1050:
    
-------------------------------------------------------------------------------

TEAMMATE 1:  Adventurer Card  

             function adventurerCard called 1032 returned 100% blocks executed 100%
         1032: 1051:int adventurerCard(int drawntreasure, struct gameState *state, int z, int currentPlayer) {
            -: 1052:    int temphand[MAX_HAND];
        12338: 1053:    while(drawntreasure<2){
    branch  0 taken 91%
    branch  1 taken 9% (fallthrough)
        10274: 1054:        if (state->deckCount[currentPlayer] <1){
    branch  0 taken 5% (fallthrough)
    branch  1 taken 95%
          471: 1055:          shuffle(currentPlayer, state);
    call    0 returned 100%
            -: 1056:        }
        10274: 1057:        drawCard(currentPlayer, state);
    call    0 returned 100%
        10274: 1058:        int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
        10274: 1059:        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
    branch  0 taken 93% (fallthrough)
    branch  1 taken 7%
    branch  2 taken 93% (fallthrough)
    branch  3 taken 7%
    branch  4 taken 8% (fallthrough)
    branch  5 taken 92%
         2064: 1060:          drawntreasure++;
            -: 1061:        else{
         8210: 1062:          temphand[z]=cardDrawn;
         8210: 1063:          state->handCount[currentPlayer]--;
         8210: 1064:          z++;
            -: 1065:        }
            -: 1066:      }
        10274: 1067:    while(z-1>=0){
    branch  0 taken 89%
    branch  1 taken 11% (fallthrough)
         8210: 1068:  state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
         8210: 1069:  z=z-1;
            -: 1070:    }
            -: 1071:
         1032: 1072:    return 0;
            -: 1073:}
            -: 1074:
            -: 1075:

-------------------------------------------------------------------------------

TEAMMATE 2:  Smithy Card 

     function smithyCard called 1024 returned 100% blocks executed 100%
         1024: 1280:int smithyCard(int currentPlayer, struct gameState *state, int handPos)
            -: 1281:{
            -: 1282:      int i;
            -: 1283:      //+3 Cards
         4096: 1284:      for (i = 0; i < 3; i++)
    branch  0 taken 75%
    branch  1 taken 25% (fallthrough)
            -: 1285:      {
         3072: 1286:         drawCard(currentPlayer, state);
    call    0 returned 100%
            -: 1287:       }
            -: 1288:      		  				
            -: 1289:      //discard card from hand
         1024: 1290:      discardCard(handPos, currentPlayer, state, 0);
    call    0 returned 100%
         1024: 1291:      return 0;
            -: 1292:}
            -: 1293:

-------------------------------------------------------------------------------

TEAMMATE 2:  Adventurer Card  

      function adventurerCard called 1032 returned 100% blocks executed 100%
         1032: 1256:int adventurerCard(int cardDrawn, int drawntreasure, struct gameState *state, int currentPlayer, int *temphand, int z)
            -: 1257:{
        12338: 1258:  while(drawntreasure<2){
    branch  0 taken 91%
    branch  1 taken 9% (fallthrough)
        10274: 1259:	if (state->deckCount[currentPlayer] == 0) { 
    branch  0 taken 5% (fallthrough)
    branch  1 taken 95%
          471: 1260:	  shuffle(currentPlayer, state);
    call    0 returned 100%
            -: 1261:	}
        10274: 1262:	drawCard(currentPlayer, state);
    call    0 returned 100%
        10274: 1263:	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];.
        10274: 1264:	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
    branch  0 taken 93% (fallthrough)
    branch  1 taken 7%
    branch  2 taken 93% (fallthrough)
    branch  3 taken 7%
    branch  4 taken 8% (fallthrough)
    branch  5 taken 92%
         2064: 1265:	  drawntreasure++;
            -: 1266:	else{
         8210: 1267:	  temphand[z]=cardDrawn;
         8210: 1268:	  state->handCount[currentPlayer]--; 
         8210: 1269:	  z++;
            -: 1270:	}
            -: 1271:  }
        10274: 1272:  while(z-1>=0){
    branch  0 taken 89%
    branch  1 taken 11% (fallthrough)
         8210: 1273:	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
         8210: 1274:	z=z-1;
            -: 1275:  }
         1032: 1276:  return 0;
            -: 1277:}
            -: 1278:

*/
