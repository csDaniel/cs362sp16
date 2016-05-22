To fix the bugs David found:
Bug1:
Added check in playAdventurer() function to make sure that the card in the hand position being passed in is actually Adventurer.

Bug2:
Fixed the loop condition in playSmithy() so that it goes while i is less than 3 instead of less than or equal to 3.

Bug3:
Fixed trashFlag for discarding in the playVillage() function to zero (for discarding) instead of 1 (which would be for trashing).  Fixed discardCard() function so that when the trashFlag is less than 1 it adds the card to the discard pile and increments the discardCount instead of adding the card to the played cards pile and incrementing the played cards count.


-------------------------------------------------------------------------------------
To fix the bugs that Ben found:
Bug1:
Fixed as part of fixing David’s Bug3 above.

Bug2:
Fixed as part of fixing David’s Bug2 above.

Bug3:
Fixed playAdventurer() function by changing the index of temphand in the second while loop back to “z-1” instead of the erroneous “z”.

Bug4:
Fixed as part of fixing David’s Bug3 above.


-------------------------------------------------------------------------------------
To fix my bugs that I inserted or found:
Adventurer:
Fixed as part of fixing Ben’s Bug3 above.  Also, call updateCoins at the end of playAdventurer() function so that the current player’s coin count reflects the treasure cards drawn.

Smithy:
Fixed as part of fixing David’s Bug2 above.

Village:
Fixed as part of fixing David’s Bug3 above.

Council Room:
Changed the if condition in the for loop to be true when i is not equal to currentPlayer so that the other players each draw a card.

discardCard:
Fixed as part of fixing David’s Bug3 above.


-------------------------------------------------------------------------------------
Discussion:
While my tests provided good code coverage for the functions that I was testing, David still managed to find something that I had not tested for due to different assumptions about how the functions would be called.  I assumed that the refactored card functions would only be called by the cardEffect() function and therefore, they would always be passed the correct card in the player’s hand (i.e. playAdventurer() would always be passed the hand position of the Adventurer card).  David assumed that these functions could be called independently of the cardEffect() function and therefore, the function needed to validate that it had been passed the correct card.  I don’t think either assumption is wrong since there is nothing in the specifications to indicate one way or the other.  I think this illustrates that when code is being worked on by different developers, it is important to state assumptions so that code doesn’t get used in ways other than what was intended.  The other bugs that David and Ben found were the same as the bugs that I had found for the functions that they tested.  As I discussed in the BugsInTeammates.c file, there is almost always room for improvement to test suites.  I realized that I wasn’t testing to make sure cards were or weren’t being trashed, which is an important part of the gameplay for some cards and therefore is an important part of the game state.  Again, this shows that even with good coverage of the tested functions, coverage alone doesn’t tell us whether or not we are testing everything that we should be.  It is just a good indicator that you are on the right track with your testing.