**********************
Bugs fixed
**********************
playSmithy()
-------------------
1. As reported by my teammates, I had introduced a bug that left the beginning of a for loop uninitialized. Instead of allowing i to remain uninitialized, I initialized it to 0 so that the proper number of cards was being drawn.  
2. As reported by my teammates, the smithy card was not being discarded. This was because in the discardCard() function, the hand position and the player position had been switched. Therefore, I switched them back, allowing the smithy card to be properly discarded from the current player’s hand.  

playAdventurer()
-------------------
1. As my teammates found, one of the bugs I had introduced was to discard too many cards, since I had initialized the index of the temporary hand to be the current player. Instead, I reinitialized z to 0 so that the temporary hand would fill starting from the first index, preventing the wrong number of cards from being discarded from the hand. 
2.  Another of one the bugs my teammates found was one I had introduced to prevent any non-treasure cards from being discarded from the hand. To fix this, I simply allowed the original handcount to be decremented, rather than a bogus temporary count. 
3. A bug that I had not introduced but that my teammates found was that the adventurer card was not being discarded at the end of the turn. Therefore, after both while loops ended, I used the discardCard() function to discard the adventurer card. 

playAmbassador()
-------------------
1. Although none of my teammates tested this card, I had introduced a bug to have the wrong card revealed from the player’s hand (choice 1 rather than choice2), so I fixed it so that the proper card was being revealed. 
2. Another bug I fixed was that which cards were to be trashed – the cards returned to supply – and the card to be discarded – the ambassador card – were switched. I fixed this bug by simply putting the trash flag down for the ambassador card and the trash flag up for the other cards. 

playCutpurse()
--------------------
1. As my teammates noticed, the cutpurse function did not actually discard the copper from another player’s hand, but instead, forced the wrong player to discard the wrong card. Therefore, I fixed the order of the parameters of the discardCard() call so that the right card from the right player was being discarded. 
2. I had also introduced an error that forced the other players to reveal every item in their hand whether or not they had any coppers. However, I realized later that this was an error that would only be found if the DEBUG variable were set to true, which wouldn’t actually affect gameplay. Either way, I fixed the bug so that it only happens when the player has no coppers. 


**********************
Discussion of bugs fixed
**********************
Ironically, because I had purposely tried to make my bugs very subtle, it was very difficult to remember how the bugs I had introduced were affecting dominion.c. For example, in cutpurse, I had switched the first 2 discardCard() parameters from (j, i...) to (i, j....). Because I had to figure out what i and j were supposed to represent as well as remember the order of the parameters of the discardCard() function, these subtle errors took me a while to figure out. 

Surprisingly, the test coverage itself was not as helpful here as one might think. After I fixed the bugs in my functions, the line coverage for my unittests was exactly the same. Moreover, my unittests had far greater line coverage than my random tests because they relied on a number of other variables, but they again relied on hand-coded assumptions that proved inaccurate upon closer inspection of the dynamics of the game. For example, I had assumed that the discardCard() function actually discarded the card at the end of every play, so I always made sure that the discard pile count increased. However, I later learned that after a card is played, it doesn’t immediately go back into the discard pile, to avoid getting reshuffled back into the deck. 










