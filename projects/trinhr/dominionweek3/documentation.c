smithy
--This calls a loop that will run 3 times and each time will call the drawCard
function. This adds 3 cards to the player's hand. 
 
adventurer
--This allows the player to keep drawing cards from their deck and stops until they've drawn two
treasure cards: copper, silver, or gold. 
--A variable that keeps track of the treasure cards called drawntreasure
controls the while loop and stops when it is equal to two. 
--Inside the while loop, there is a function
that first checks that the deck isn't empty. If it is, then it calls a function which will shuffle the 
discard pile and add it to the players current deck. 
--Calls the draw function which will add a card to the players hand.
--Checks if it's a treasure card, if not it saves it to a temporary hand which will discard all non-treasure drawn cards
after two treasure cards are found. 
    
discardCard()
--This sets the status of the card as played if the player hasn't trashed it aka decided not to use it. 
The card is then removed from the players hand and the variable controlling the number of cards in the player's 
hand is updated. 
  
updateCoins()
--A variable keeps track of the number of coins there are and it is initialized at zero. There is a for loop
that runs through the players hand and checks each treasure card and adds the coins according the worth of the card.
Gold will add 3 coins, Silver will add 2 coins and copper will add 1 coin. Then at the end it'll add any bonus coins
resulting from other card effects. 
