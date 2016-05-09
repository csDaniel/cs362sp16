/*(20 points) Write up and check in the development of your random testers, including improvements in
		coverage and effort to check the correctness of your specification, as randomhistory.c. Be detailed and thorough!


RUN THE FOLLOWING TO GENERATE OUTPUT ON ADVENTURER RANDOM TEST:

make testAdventure

RUN THE FOLLOWING TO GENERATE OUTPUT ON GCOV FOR RANDOM CARD:

make testRandom

My random testers were created by randomly creating gamestates using various unit test to check the status of the game.

Random test were run on Sea_Hag card and Adventure card.

The random states were made by initializing the game randomly before using various unit test to find out if the cards were able to
be run successfully.

I ran all the unit test I had on the gamestates and I also randomized the gamestate completly and ran it 10,000 times, calling the
"card effect" function with the desired card several times.

The randomizations done are on the following using the remainder of the random() function.
Kingdom cards.
Number of players.
Discard Count for Players
Cards in Deck
Cards in Hand.
Actions
Whose Turn it is
Number of Buys


When I created the random test the iterations took a bit longer than I thought. My oracle was actually wrong and threw an error
associated with an array out of bounds. It took me a few hours to find out that the actual oracle was broken and the card implementation
was not broken as the error was relatively random and did not pop unless a few iterations of the program were run.

My bug fixing efforts lead me to review some of the source code with the game initialization and I believe there MAY be a game associated with it
because the decks, and arrays are not malloc'ed and therefore will eventually be filled with garbage. This might be incorrect as they
are initialized as deck[MAX_PLAYER][MAX_CARD] which might allocate space. I am unsure if this allocates space between the functions.

There is a bug in the logic of the game where cards are ALWAYS shuffled in the discard pile after a persons turn is done
(instead of keeping their hands until the round is over). This was noticed as I realized that the gamestate is not going to accurately
reflect how the game will run.

Overall a random tester was difficult to develop correctly and I based my efforts on Piazza post saying it was going to randomize
the gamestate and run unit test.

Another issue with the random test was figuring out how to move forward with randomizing test inputs on a small function with limited amounts
of input. The adventure card has the same input each time it is played and the only feature that can be randomized effectively is the
gamestate itself.

I was able to find out a bug from the random testing, which I was happy about.

1) The Witch Card mistakenly tallys victory points on MOST game states.
2) The Witch card mistakenly puts discard piles for MOST game states
3) The MOST IMPORTANT test was on the adventure card. It Regularly found errors on how many cards
were supposed to be in a hand REGARDLESS on the amount of cards in the hand. I looked in and found this was because
the adventure card does not run "draw card" effectively making it so all discard pile cards are not looked at when the adventure card
is played.

Random testing was helpful in finding the above bugs, especially bug #3, which would not have
been found without a randomized game state.

The coverage using the random test increased several fold and also allowed me to see that some of the gamestates are almost never,
even in a completely random way, hit. The gcov coverage clearly shows that the tested functions are run through over 13000 times as a minimum.



		*/
