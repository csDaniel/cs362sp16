I had an interesting time fixing the bugs found by my partners and the ones I introduced. I found myself thinking about the udacity lectures a lot. One of the things that stuck out to me the most, is when the lecturer says something about don’t just try things and see what happens. When I’ve debugged in the past I’ve typically just try this or that and seen what happened as a result, this time I  commented out some code so there was a record of what was replaced as well as some insight as to what I thought was happening. Another point raised in the lectures was only change one thing, then test. I typically would change couple of things, which makes debugging much more difficult. 
The most interesting thing I found when debugging for this assignment was how much of an expert one must be on the source code to do adequate debugging and testing. This was my first experience testing/debugging code that I didn’t have a large part in producing. Being very familiar with the all parts of the source code you are debugging is critical. For example when I debugged the adventurer card, I discovered an error in my adventurer test. I found this an interesting concept that one bug leads to another and even crossed into the card tests. It was interesting to see how the intial infection can propagate through the code. 
Recently in other projects I’ve been thinking a lot about test driven developing. When I first learned about writing tests before writing source I had a hard time figuring out why. This debugging experience helped me figure out, that writing tests after the source code is written is much harder than writing incremental tests during development. Again the udacity lectures raised this question of keeping a log in one’s mind is never a good idea, writing tests which is a sort of documentation during development will really reduce the amount loose ends to keep track.
The assignment suggests I touch on coverage during debugging. I didn’t end up using the coverage in my debugging at all. I think coverage is a great tool for testing code but not necessarily for debugging in this case. One reason for this is the structure of the dominion code, it is easily navigated and functions are small with only one or two additional function call in each card or game function. This allows the debugger to manually inspect and to manually step into function calls. With a larger code base coverage during debugging would become much more valuable. The coverage metric also lends itself to the tarantula debugging method which would be so useful in a large code base. The coverage metric can also be used to slice a program which would be useful again with a larger code base. But for dominion.c I believe both trantualla and coverage slice would be overkill. However, I would bet most students are debugging with a  type of manual slice. 

The bugs reported to me were as follows by teammate 1.
1.	Bug in scoreFor().There is a bug in how it determines the score for gardens.When the hand, discard and deck all have only 5 cards(all gardens), it does not give the expected score of 15.

Original code:
Found in 3 separate for loops for lines 422- 455  
  if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
  The error is in calling fullDeckCount, fullDeckCount only counts a particular card contained in the deck.
      if (state->hand[player][i] == gardens) { score = score + ( state->handCount[player] + state->deckCount[player] + state->discardCount[player] / 10 ); };
      The fix above replaces in the particular loop it’s found in 1 for deck, 1 for hand and 1 for discard.



      2.	Bug in scoreFor().This bug has to do with different size hands.When the hand has 4 estates, discard has 5 estates and deck have 6 estates, it does not produce the expected output of 15.

      Line 444 has the key bug here below. The for loop is using the discard count instead of deck count to count victory cards in the deck. 
       //score from deck
         for (i = 0; i < state->discardCount[player]; i++)

	 fix 
	 for (i = 0; i < state->deckCount[player]; i++)


	 3.	Bug in Smithy.After initializing a new game and playing Smithy, there are three incorrect values.First, the players hand count is supposed to be 3 but is actual 8.  Discard count is expected to be 1 but is actual 0.  Opponent’s deck is supposed to be 0, but is actually - 1.
	 The Error is located in the line below, the discard is added to next players discard count and the trash falg is set. I also believe my teammate errored in his test. I believe the smith adds 3 cards for a net gain of 2, since the smithy is put in played after used. 
	 discardCard(handPos, currentPlayer + 1 , state, 1 );  
	 changed to:
	 discardCard(handPos, currentPlayer, state, 0 );


	 4.	Bug in adventurer.After initializing a new game and playing adventurer, there are two incorrect values.First, player’s hand count is expected to be 6 but is actually 7.  Secondly, discard, deck and played count(combined) is expected to be 4 but is actually 3.
	 	
			The problem here stems from the z++ in the else statement. The other problem noted by my teammate I believe is a flaw in my test. For example when starting a new game a player doesn’t automatically start with an adventurer card, thus one shouldn’t be discarded. However during real game play of coarse one should be discarded. Again being an expert on the source code is necessary for complete sound testing.
			else{
				  temphand[z]=cardDrawn;
				  	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
					  	  z++;            <- removed the z++ 
						           drawntreasure--;


							   5.	Bug in gardens.After initializing a new game and playing gardens, hand count is expected to be 4 but is actually 5. The sum of discard deck and played deck is expected to be 1 but is actually 0.
							   I believe this is due to a gardens card not being able to be played. This is not an action card and is really more of a passive bonus counted during the end of the game. 





							   6.	Bug in adventurer : In random testing, 98.9% of tests had an error in the count of treasures cards in hand and count of treasure cards in discard + deck + played decks.
							   SEE discussion above about Adventurer card
							   The bugs reported to me were as follows by teammate 2.
							   ***  Teammate 1: Bug 1. ***
							   	
								Number: 7
								Function: smithy_function()
								Effect: The player's hand count does not match the expected hand count after playing the smithy card
								Possible location: Line 717: the discardCard function is being passed the incorrect player's 
								Location

								This was determined based on the fact that the smithy_function() failed the following test:

								--------Card Test 1: Test 1: Play Smithy and Check that 3 Cards are Drawn and 1 (Smithy) is 
								Discarded---------

								Failed
								SEE NOTE ABOVE ABOUT FIX #3

								*** Teammate 1: Bug 2.  ***

								Number: 8
								Function: council_room_function()
								Effect: The player's number of buys does not increase by 1
								Possible location: Line 658: The number of buys is incremented by a predetermined amount that may 
								not equal 1


								This was determined based on the fact that the council_room_function() failed the following test:       -------Card Test 4: Test 4: Play CouncilRoom. Number of buys should be increased by 1 ------------

								Errored code =  state->numBuys = state->numBuys + state->numBuys;
								This is a difficult error to spot and was probably picked up by the random tester, many situations the buys will be 1 and thus playing the council room card will increase to 2 properly. The fix is to simply increase by one not double as seen below.
								 state->numBuys = state->numBuys + 1;


								 I was thinking about putting the priority and severity rating on each of these bugs but I had a hard time figuring what it might be. They all effect game play however none of them terminate is with a segfault or something similar. I decided the severity and priority should all be equal in these cases because each does lead to an infection and faulty game state.





								 :
