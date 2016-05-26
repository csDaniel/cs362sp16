Author: Jonathan Hardman
Filename: randomhistory.c

Note: For both of these tests I put some notes and the card specification in the testing program itself

randomtestadventurer.c: When I stated this assignment doing this tester, I wanted to use as many assets as I 
						could from the unit test I made back in assignment 3 since it did a good job of 
						checking the proper behavior of the card. So I used my adventurer cardtest as a template 
						for the random tester.
						
						The first challenge of making a random tester was figureing out what needed to be 
						randomized and what range of values to use for each variable. If you look at the 
						top of the code you'll see a bit of the thought process which was built off of the 
						unit card test. I specifically looked for what input variables the card was using 
						and what variables it relied on within its function to do its card effect.
						
						So after taking a look at all of these variables and variable ranges I started 
						thinking about all of the changes and improvements I wanted this tester	to have 
						in comparison to the old unit test:
						- It needed a for-loop to run the test with randomly generated variables multiple
						  times
						- It needed to randomly generate values for all of the used variables in the card 
						  effect (using my defined value ranges)
						- I wanted it to print the generated values in a table along with the results of 
						  the test so that it is easier to find out whether the test result was correct or 
						  incorrect
						- It needed to use and pass all of the conditions set from my old unit card test
						- And finally I also wanted to keep the old print statments (which I modified a bit)
						  in case someone wanted to use them later for debugging purposes
						
						With this level of customized conditions I needed to modify the initializeGame2 function
						(which I used in my unit card test) even further so that it can accept these random 
						generated inputs and use them to set up the game state. 
						
						Once I made a modified initializeGame2 function and implemented all of those changes listed
						above I began testing. On the first compiled run of my random tester I got something like 90-95%
						coverage on the Adventurer card effect, then reason was because I didn't change the current player
						at all, meaning it was always player 0 and thus the following lines never ran:
						
						if (nextPlayer > (state->numPlayers - 1))
						{
							nextPlayer = 0;
						}
						
						So in order to run these lines (and ultimately get 100% coverage) I made it so the 
						current player would be randomized (between 0 and the generated total number of players)
						and passed that info onto initializeGame2 so that it would set the current player
						accordingly.
						
						The bugs I've found, aside from what I put in, is that the adventurer card doesn't get 
						discarded at all, and that the function doesn't know how to handle situations where when 
						all of the treasure cards are already in hand. This is most common when when all of the 
						cards in the deck have already been drawn into the players hand.
						
randomtestcard.c: For this tester, I used a lot of the same structure from the randomtestadventurer.c file and used
				  it to test the smithy card. I used the same thought process as explained above, so I'll skip to some
				  of the implementation details.
				  
				  In the tester I obviously had to get rid of all the treasure card tracking in the main function itself
				  and in the initializeGame2 function. For simplicity I just made it so initializeGame2 would set all of the
				  players cards to estate since what each card is doesn't really matter for the smithy card effect.
				  
				  The testing specification was a lot simpler with this card and probably is more comparable to the 
				  smithy unit test than the randomtestadventurer card test.
				  
				  Because this test was a lot simpler in specification, it was a lot quicker to implement than the 
				  adventurer card and produced a lot better results. On first compiled run without any introduced bugs,
				  all of the tests passed with 100% coverage on the smithy card effect in dominion.c. After some searching
				  not find any other bugs besides my introduced one.