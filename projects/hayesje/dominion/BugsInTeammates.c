/*
#################################################################################
                                 BUG SUMMARY
##################################################################################

BUG 1: Teammate 1 - Smithy Card

       Description: Test results show that only 2 cards are drawn from the deck

       Severity: Minor
               Although 2 cards are drawn from the deck rather than 3, this
               only changes the "rules" of game rather than preventing game play 

       Priority: Minor 
               A slight modification of the rules of the game my be considered
               by some as Major, the bug would be addressed after bugs that 
               prevented game play were addressed.
               
       Failure Sample:
           Oracle: 
               pre:  deck:{7,8,9,10,11}  hand:{13}         discard:{}  played:{}
               post: deck:{7,8}          hand:{9,10,11}    discard:{}  played:{13}
           Test Results:
               pre:  deck:{7,8,9,10,11}  hand:{13}         discard:{}  played:{}   
               post: deck:{7,8,9}        hand:{10,11}      discard:{}  played:{13}
 
       Failure Analysis: The Oracle illustrates that when the Smithy card is played 
            from the hand, 3 cards are drawn from the deck and placed in the hand,
            while the Smithy card (13) is placed in the played pile. The test
            results show that only 2 cards are drawn from the deck, suggesting
            a bug in the code controlling the number for cards drawn.  

       Bug Identification: See BugFixes.c

       Unit Test Summary:                
               Unit Test: cardtest1.c            
               Target: Smithy Card
               Status: FAILED
               Passed: 0
               Failed: 24

       Random Test Summary
               randomtestcard => Passed:0  Failed:1000

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

BUG 2: Teammate 1 - Adventurer Card

       Description: Cards continue to be drawn from deck after 2 treasure cards have 
               been revealed

       Severity: Moderate
               Although the Failure Sample below illustrates the post hand containing
               the correct number of treasure cards, the increased transfer of 
               of deck cards to the discard pile can effectively decrease the 
               number of cards in the player's deck, thus impacting game play. 
                
       Priority: Moderate 
               The bug should be addressed after all Major bugs are addressed.

       Failure Sample:
           Oracle: 
               pre:  deck:{7,4,5,10,11}  hand:{}       discard:{} 
               post: deck:{7}            hand:{5,4}    discard:{11,10}  
           Test Results:
               pre:  deck:{7,4,5,10,11}  hand:{}       discard:{} 
               post: deck:{}             hand:{5,4}    discard:{7,10,11} 
 
       Failure Analysis: The initial sequence of cards on the deck from top to bottom 
               is 11,10,5,4,7. The treasure cards 5 and 4 (silver and copper) can only 
               be obtained by first removing cards 11 and 10 and placing them in the 
               discard pile.  The 2 treasure cards are then placed correctly into the 
               hand which should terminate play, however the last card in the deck appears
               to be drawn and placed in the discard pile. Something is preventing play 
               to end after 2 treasure cards is drawn.   

       Bug Identification: See BugFixes.c

       Unit Test Summary:                
              Unit Test: cardtest2.c
                 Target: Adventurer Card
                 Status: FAILED
                 Passed: 4
                 Failed: 28

       Random Test Summary
               Segmentation fault (core dumped)

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

BUG 3: Teammate 1 - Adventurer Card

       Description: Test results suggest that 'gold' is not recognized as treasure card

       Severity: Moderate
               The bug does not prevent game play, although it does significantly decrease
               the value of playing the Adventurer Card. 
                
       Priority: Moderate 
               The bug should be addressesed after all Major bugs are addressed.


       Failure Sample:
             Oracle: 
                  pre:  deck:{5,6,9,10,11}  hand:{}       discard:{} 
                  post: deck:{}             hand:{6,5}    discard:{11,10,9}  
             Test Results:
                  pre:  deck:{5,6,9,10,11}  hand:{}       discard:{}
                  post: deck:{}             hand:{5}      discard:{6,9,10,11} 
 
       Failure Analysis: The initial sequence of cards on the deck from top to bottom is
             11,10,9,6,5. The treasure cards 6 and 5 (gold and silver) can only be 
             obtained by first removing cards 11, 10 and 9 and placing them in the discard
             pile. The gold treasure card should be placed in the hand, however it is 
             placed in the discard pile.  It appears the code does not recognize 'gold' 
             as a treasure card.  

       Bug Identification: See BugFixes.c

       Unit Test Summary:
             Unit Test: cardtest2.c
                Target: Adventurer Card
                Status: FAILED
                Passed: 4
                Failed: 28
 
       Random Test Summary
             Segmentation fault (core dumped)

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

BUG 4: Teammate 2 - Smithy Card

       Description: Test results show that no cards are drawn from the deck.

       Severity: Minor
               The bug does not prevent game play, although it does significantly decrease
               the value of playing the Smithy Card. 
                
       Priority: Minor 
               The bug should be addressed after all Major bugs are addressed.

       Failure Sample:
            Oracle: 
                 pre:  deck:{7,8,9,10,11}  hand:{13}         discard:{}  played:{}
                 post: deck:{7,8}          hand:{9,10,11}    discard:{}  played:{13}
            Test Results:
                 pre:  deck:{7,8,9,10,11}  hand:{13}         discard:{}  played:{}   
                 post: deck:{7,8,9,10,11}  hand:{}           discard:{}  played:{13}
 
       Failure Analysis: The Oracle illustrates that when the Smithy card is played from
                 the hand, 3 cards are drawn from the deck and placed in the hand,
                 while the Smithy card (13) is placed in the played pile. The test
                 results show that no cards are drawn from the deck, suggesting
                 a bug in the code controlling the number for cards drawn.

       Bug Identification: See BugFixes.c

       Unit Test Summary:                
           Unit Test: cardtest1.c
               Target: Smithy Card
               Status: FAILED
               Passed: 0
               Failed: 24

       Random Test Summary
           randomtestcard => Passed:0  Failed:1000

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

BUG 5: Teammate 2 - Adventurer Card

       Description: Segmentation fault occurred when running both unit test and random test

       Severity: Major
               The bug prevents game play whenever the Adventurer card is played. 
                
       Priority: Major
               The bug should be addressed as soon as possible/.

     . Failure Sample:
           No samples available ... core dump on first sample.
 
       Failure Analysis
           Since no samples were available to give guidance on where the fault might be 
           located, the only alternative was to do a code review, looking for obvious problems
           in the code.  

       Bug Identification: See BugFixes.c

       Unit Test Summary:                
           Segmentation fault (core dumped)
 
       Random Test Summary
           Segmentation fault (core dumped)
       
*/
