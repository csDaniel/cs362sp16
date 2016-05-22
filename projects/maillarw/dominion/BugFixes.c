William Maillard
5/22/16
CS 362
Bug Fixes

The following is a list of bugs found and fixed using the results of my teammates tests, my tests, 
and GDB.  
The coverage in my tests helped immensely with testing of these bugs.  All of the coverage 
information can be found in the combinedRandomUnitSaved.out file.  Because the coverage of the 
functions in question, for the majority of these bugs was 100%, it none of the bugs listed by 
teammates were not already found by my tests (except one, which was in function that I did not 
test).  The bugs reported by my teammates and myself in bugs1 have all been fixed and the program 
should run much better now.  

	
Bug #1
Effect: scoreFor() was producing incorrect results
	
Fix 1.1: Each occurence of this line:
	if (state->hand[player][i] == gardens) { score = score + fullDeckCount(player, 0, state) / 10 ; }; 
was replaced with this line:
	if (state->hand[player][i] == gardens) { score = score + ( totalCards / 10 ); }; 
and this line was added at the start of scoreFor():
	int totalCards = state->handCount[player] + state->deckCount[player] + state->discardCount[player];
Reason: fullDeckCount() returns the number of a specific card (in this case card 0: curse) in the 
deck, the hand, and the discard.  The gardens score is instead based on the sum of all cards in all 
three files, so this was fixed with the totalCards sum.
	
Fix 1.2: In the third loop (counting the score for the deck) this line:
	 for (i = 0; i < state->discardCount[player]; i++) 
was replaced by this line:
	 for (i = 0; i < state->deckCount[player]; i++) 
Reason: This loop was only counting up to the number of discard cards, when it should be counting 
up to the number of deck cards.

These two fixes fixed the following bugs reported and allowed my unit tests to pass:

Teammates found:
1.	Bug in scoreFor().There is a bug in how it determines the score for gardens.When the hand, 
discard and deck all have only 5 cards(all gardens), it does not give the expected score of 15.
2.	Bug in scoreFor().This bug has to do with different size hands.When the hand has 4 estates, 
discard has 5 estates and deck have 6 estates, it does not produce the expected output of 15.

I found:
The scoreFor() function returns a score of 10 when the player has one of every 
card in his/her hand.  This score should be 12.
The scoreFor() function returns a score of -7 when the player has one of every 
card in his/her discard pile. This score should be 12.
The scoreFor() function returns 0 when the player’s deck has one of every card 
in it, should return 12.
	
Bug #2
Effect: playSmithy() function is not having the desired effect (3 cards are added to hand, 3 cards 
are removed from the deck)

Fix 2.1: The following lines in the playSmithy() function were incorrect:
  int i;
  //draw three cards
  for (i; i < 3; i++)
and they were changed to:
  int i;
  //draw three cards
  for (i = 0; i < 3; i++)

Reason: The i variable in these lines was uninitiallized, causing unpredictable behavior (i could 
start as any number)
	
This fix fixed the following reported bugs and allowed my cardtest1 (3 tests) to pass:

Teammates found:
3.	Bug in Smithy.After initializing a new game and playing Smithy, the players hand count is 
expected to be 3 but is actually 4.  The deck is count is expected to be 2 but is actually 5.
Smithy, card player hand count is incorrect shows 4 instead of expected 7. Also  card player’s deck 
count is also incorrect, shows 5 expected 2.

I found:Unit Test 2
5.  When playSmithy() is called with normal initial settings, either three 
cards are not drawn or the Smithy card is not dicarded, or both.
6.  When playSmithy() is called with an empty deck and a full discard pile, 
either three cards are not drawn or the Smithy card is not dicarded, or both.
	
Bug #3
//Effect: playAdventurer is not having the desire effect (up 2 two treasure cards (depending on the 
number of treasure cards in the players deck and discard) are added to the player's hand)

Fix 3.1: This line: 
    z=z-3;
was replaced with this line:
z=z-1

Reason: z is a counter that keeps track of how many cards are in the temp hand (holds cards while 
looking for treasure cards).  z is decremented while cards are discarded from the temp hand.  It 
was originally decremented by 3 for every card when it should be decremented by only one.

Fix 3.2:  The following was added to the end of playAdventurer():
  
  int handPos = 0;
  int i;
  for(i = 0; i < state->handCount[currentPlayer]; i++){
    if(state->hand[currentPlayer][i] == adventurer){
      handPos = i;
      break;
    }
  }
  discardCard(handPos, currentPlayer, state, 0);

Reason: The playAdventurer() function does not discard the adventurer card after it is played.  
Because much of the code relies on this function only having 1 parameter, this fix was added to 
discard an adventurer card without knowing its location.
	
	
These fixes fixed the following reported bugs and allowed my cardtest2 (3 tests) to pass:											
			


Adventurer card bugs, the card players hand count is incorrect 7 instead of 6. Also the card 
players deck count is incorrect, showing 2 expected 3. 
	
Teammates found:

4.	Bug in Adventurer.After initializing a new game and playing adventurer, the players hand count 
is expected to be 6 but is actually 7.  The discard and played count is expected to be 4, but is 
actually 3.
Adventurer card bugs, the card players hand count is incorrect 7 instead of 6. Also the card 
players deck count is incorrect, showing 2 expected 3.
	
I found:

7.   When the playAdventurer() function is called, no cards are added to the 
playedCards array

	
Bug #4
	
Effect: When playing the gardens card, no cards are discarded

Fix 4.1: This line is added in the gardens switch in the cardEffect() function:
	discardCard(handPos, currentPlayer, state, 0);
Reason: This makes sure that the Gardens card is discarded after it is played
	
This fix fixed the following reported bugs:

Teammates found:
	
	5.	Bug in gardens.After initializing a new game and playing gardens, hand count is expected to be 
4 but is actually 5. The sum of discard deck and played deck is expected to be 1 but is actually 0.
	
Bug #5

Effect: playVillage() is not having the desired effect (1 card is added to the players and and 2 
actions are also added)

Fix 5.1: This line in playVillage():
      int currentPlayer = whoseTurn(state) + 1;
is replaced with this line:
      int currentPlayer = whoseTurn(state);

Reason: The current player is returned by whoseTurn(state) not whoseTurn(state) + 1
	
These fixes fixed the following reported bugs and allowed my cardtest4 (3 tests) to pass:

Bugs teammates found:		
	
6.	Bug in Village.After initializing a new game and playing village, the deck count is expected to 
be 4 but is actually 5.  The opponents deck count is expected to be 10 but is actually 9.
Village card bug, card palyers deck count shows 5 instead of expected 4. Also player 1’s deck count 
shows 9 not 10 as expected. 

Bugs I found:

9. When the playVillage() function is called either a card is not added to the 
player’s hand or a card is not removed from the player’s hand or both.
10.  When the playVillage() function is called, one card, specifically the 
Village card, is not sent to the playedCards array.
	
Bug #6

Effect: playFeast() is not having the desired effect(Trash feast card and gain a card costing up to 
5)
	
Fix 6.1

This block in playFeast():	
	for(i = 0; i < 5; i++){
	gainCard(choice1, state, 0, currentPlayer);//Gain the card
	}
was changed to:
	gainCard(choice1, state, 0, currentPlayer);//Gain the card

Reason: Only one card should be gained, not 5
	
Bug #7
	
Effect: isGameOver() does not return the correct value when there are 5 players

Fix 7.1
The block:
  if ( j >= 3)
    {
      return 1;
    }
was changed to:
  if ( j >= 3 && state->numPlayers < 5)
    {
      return 1;
    }
  else if(j >= 4 && state->numPlayers >= 5)
    return 1;

Reason: This allows testing to see if the game is over with 5 players, as the rules for ending the 
game require that 4 stacks are empty or the provinces are gone.
	

These fixes fixed the following reported bugs and allowed my unittest2 (4 tests) to pass:

In the function isGameOver() there is bug in which the function returns 1 when 
3 supply stacks are empty and there are 5 players (it should return 0 based on 
the rules of Dominion).  This may be a limitation in the number of allowed 
players in this simulation.
		
		
		
