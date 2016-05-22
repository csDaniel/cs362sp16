/********************************
** filename:BugFixes.c
** author: Candis Pike
** date: April 16, 2016
** description: report on how bugs were fixed
***********************************/

Report of teammates:
Adventure:
Total Adventurer Errors: 4

Adventurer Error #1:
-----------------------
Severity: Moderate
Description: Instead of adding two treasure cards, it adds 3 cards from the deck. 

Adventurer Error #2:
-----------------------
Severity: Minor
Description: Adventurer does not add silver cards, even when available from the deck.

Adventurer Error #3:
-----------------------
Severity: Minor
Description: Adventurer card is not discarded after playing.
	
Adventurer Error #4:
-----------------------
Severity: Major
Description: If there aren’t 3 treasure cards in the discard pile and deck, the game ends up discarding all the cards in the hand and sometimes causing a segmentation fault (it keeps drawing from an empty hand into an out-of-bounds array). 

Bug #1
Title: playAdventurer() does not count silver as treasure

Bug #2
Title: playAdventurer() adventurer card is not discarded 
__________________________________________________________________________________________________________________
Smithy:
Smithy Error #1
---------------------
Severity: Moderate
Description: Smithy draws only 2 cards from the deck, not 3.

Bug #5
Title: playSmithy() Does not draw the right number of cards 

__________________________________________________________________________________________________________________
Village:
Bug #3
Title: playVillage() Number of actions added incorrectly  
Bug #4
Title: playVillage() Village card is trashed  

___________________________________________________________________________________________________________________
Bug Fixes of Adventurer
Bug: incorrect number of cards are being drawn. 
In GDB set a breakpoint to step into the playAdventurer function and a display to track the value of drawntreasure within the while loop at line 15 dominion.c
The value starts at 0 and ends at 2 before exiting the while loop. This is suggestive that line 15 while (drawntreasure <=2) is the line that contains the bug.
Changing the line to while (drawntreasure < 2) fixes the bug.

Bug: adventurer is not being discarded.
In GDB stepping into the playAdventurer code and investigating line by line there is no line to discard the adventurer card at the end of play. This is futher reinforced with code review.
The following changes to the code were required to fix the bug:
1. added line of code to the end of the playAdventurer function fixes the bug discardCard(handPos, currentPlayer, state, 0)
2. added the hand position of adventurere as a function parameter int playAdventurer (struct gameState *state, int handPos)

Bug: no silver cards are added to hand/silver cards are being discarded
This bug was found during code inspection during the GDB debugging of incorrect number of cards drawn. On line 21-22 the code reads
if (cardDrawn == copper || cardDrawn == gold)
	drawntreasure++;
there is no check for silver cards in the if statement thereby preventing that card from being added to the hand and is instead being discarded.
Changing the line to read if (cardDrawn == copper || cardDrawn == silver ||cardDrawn == gold) fixes the bug.

Bug: having less then 3 treasure cards in deck and discard pile combined creates a segmentation fault
This is a sever bug however it is not a high priority bug and can be considered an edge case with a high probability that it will bot be encountered during the course of typical game.
Each player starts the game with 7 copper coin cards. Adventure requires 6 coins to purchase.From this one can infer that by the time this card is purchased and 
used the player will have ample coin cards in the deck and discard piles to avoid falling below the 3 that are requried when the card is played.
__________________________________________________________________________________________________________________
Bug Fixes Smithy
Bug: incorect number of cards drawn
In GDB set a break to step into the playSmithy function also set a display to track the value of i in the for loop on line 39 of dominion.c.
The final value of i is 3, however, the for loop is executed twice. 
The code at line 39 is for (i=1; i<3; i++)
Changing the line to the following fixes the bug: for (i=0; i<3; i++)
	
___________________________________________________________________________________________________________________
Bug Fixes Village
Bug: incorrect number of actions
In GDB set a breakpoint to step into the playVillage function, set a display for the struct gameState member numActions. The final value of numActions is 2. 
This is set in line 113 dominion.c:  state->numActions = state->numActions + 1;
Changing the line to the following fixes the bug:  state->numActions = state->numActions + 2;

Bug: village card is trashed and not discarded
In GDB set a breakpoint to the discardCard function that is present in the playVillage function and set a display for the trashFlag variable.
The display showed a value of 2 for the trashFlag. This data along with code inspection showed that indeed the card was being trashed.
The line of code in question is 116 of dominion.c:  discardCard(handPos, currentPlayer, state,2)
Changing it to the following fixes the bug:  discardCard(handPos, currentPlayer, state,0) 

________________________________________________________________________________________________________________
Bug Fixes Cutpurse
Bug: player does not receive bonus
No fix wsa needed. In GDB set a display for coins and current player. This bug is not being caused by how the player is gaining the bonus in line 1345
the code is updateCoins (player=0, state=0x7fffffff1300, bonus=2) which is correct for setting 2 bonus coins, therefore, the player coin count must be caused elsewhere.
 
Bug: current player is losing more cards from hand then intended and other players are keeping all cards in hand
By code inspection line  128 is incorrect: if (i == currentPlayer) which would cause the current player to lose cards instead of the other players
The following change was made to fix the code: if (i != currentPlayer)

Bug: silver coin card is being discarded
In GDB set a break to step through the playCutpurse function. Also set displays for the card in the current hand position and i (for loop variable).
Stepping through the function show that if the current card is 5 then it is being discarded. The line of code that does is as follows: 	if (state->hand[i][j] == silver)
The following change was made to fix the code: if (state->hand[i][j] == copper)
	
Bug: cutpurse is not being discarded
In GDB  set a break to step through the playCutpurse function and the discardCard function. Also set displays for the card in the current hand position.
Since handPos of the village card is passed as an argument to the playCutpurse function that is used for the discardCard function, however, since the current player is losing cards, the
position of village has shifted, therefore the wrong card is being discarded. This bug is caused by line 128 and when fixed fixes the bug.

__________________________________________________________________________________________________________________
Bug Fixes Feast
Bug: incorrect bonus applied
In GDB set a break to step into the playFeast function and a display for the state.coins to track the change in coins. The value starts at 3 and ends at 5. meaning only 2 bonus coins are
added. Stepping into the updateCoin function shows that none of the players hand is being counted by tracking the state.coins at each step.
When investigating the palyFeast card is is noted that a back-up of the hand is occuring before the adding the bonus.
 Moving this line updateCoins(currentPlayer, state, 5); to before the back-up fixes the bug.

Bug: Feast is not being discarded.
Under code review there is no line of code to discard the card at the end of play. The following line was added before the return   discardCard(handPos, currentPlayer, state,0);

Bug: When buying a card with less coin that player has there is an infinite loop. Using GDB to find this bug it is noted that there is no mechanism in place to have the player
choose another card that would be less then the coins they have. To eleminate this the following lines of code were added to both the too expensive option and the supply card is depleted option
		printf("Choose another card: ");
		scanf("%d", &choice1);
Alternatively, x could have been set to 0 but then the player would not receive the card entiteld to.
______________________________________________________________________________________________________________
Additional bug fixes
Eventhough I had not refactored remodel one of my teammates did. They found a bug in the code. That being the remodel is not properly allowing the player to properly
gain a card with up to 2 cost more then the card to be trashed. Any card that costs upto 2 is not being allowed.
This bug was caught during code inspection. It is on line 891 of dominion.c which is the following: if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
The code was changed to fix the bug to the following: if ( (getCost(state->hand[currentPlayer][choice1]) + 2) < getCost(choice2) )

________________________________________________________________________________________________________________
Coverage:
After fixing the above mentioned bugs I again ran unittestresults.out and examined the coverage of the dominion code.

Before bug fixes:
File 'dominion.c'
Lines executed:33.27% of 565
Branches executed:30.12% of 415
Taken at least once:22.89% of 415
Calls executed:26.00% of 100
Creating 'dominion.c.gcov'

After bug fixes:
File 'dominion.c'
Lines executed:34.33% of 571
Branches executed:31.41% of 417
Taken at least once:24.46% of 417
Calls executed:25.47% of 106
Creating 'dominion.c.gcov'

There is a slight increase in lines executed, however, not enough to increase confidence that the dominion code is correct and relatively bug free. Again more unit tests need to instill
a greater confidence in the dominion code.


	


