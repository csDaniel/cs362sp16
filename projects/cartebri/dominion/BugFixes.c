Brianna Carter
5/22/16
Fixing Dominion Bugs

Bugs to be fixed from refactor.c:
	Smithy: Code will only draw cards if the next player number is greater than the number of players. 
	There is a conditional before the for loop.

	Adventurer: Reveal whole deck no matter how many treasure cards are revealed. The while loop was alterd to 
	continue while the current players hand is > 0. Every card is added to the temp hand, including treasure cards.

	Feast: Player can gain multiple cards totaling 5 coins instead of just one card up to 5 coins.
	The conditional x should be initialized to 1 instead of 5, the while loop on should be x==1  and when a 
	card is purchased x should be updated to 0 instead of subtracting the cost.

	Council Room: Instead of each player drawing a card, the current player draws as many cards as there are
	players. The if statement in the for loom should be != current player.

Team member reported bugs (only 1 team mate reported):
	Smithy: correct bug found
	Adventurer: correct bug found


	The first bug I am going to fix is the Smithy card. Using gdb I first ran the program without any debugging
to see if it would fail. As expected, the code ran through to completion with no trouble. I then added a 
breakpoint at the playSmithy function so I could step through and see what was being executed. Stepping through
this function showed me that the discardCard function is executed immediately when the drawCard function should
execute. Upon further investigation I saw that a nexPlayer variable is set and the correct code is only executed
when nextPlayer is greater than the total number of players. This means if there are two total players and it is
player ones turn (currentPlayer = 0), nextPlayer will be set to 1 and compared to the max position in the player
array, in this case 1. The only time when this would be true is when it is the last players turn. To fix this, I 
removed the conditional and reran the code. The resulting score was different but the Smithy card had the proper
outcome. 
	Next I will look at the but in the Adventurer card. I set a breakpoint at the playAdventurer function and 
stepped through each line. The first thing I noticed was that all cards are placed in the temp hand to be discarded,
not just the non-treasure cards. The second thing I noticed was that the code kept looping through the deck after
two treasure cards were discovered. Upon closer examination of the code, I saw a while loop that kept the loop going
as long as the player has cards in their hand. The other error is caused by a missing else statement.
	I applied the same process to the Feast card. I set a brakpoint and stepped through the function. I noticed that
the loop continued even after the player chose a card. This was caused by the loop condition being equal to five
instead of one and the loop continuing while it is 2 or higher. After the player chose a card, the loop condition 
was decremented by the cost of that card, meaning the player was able to buy multiple cards whose cost equaled five
or less. There are no cards worth fewer than two coins so as soon as the conditional was less than 2, the loop 
terminated. This was fixed by changing the conditional to one and reducing it to zero after the player chooses 
a card.
	Last is the Council Room. The proper function of this card is that the current player gains 4 cards and a buy
and the other players draw one card. This function fails to change the state of the other players cards. While 
stepping through the code, it appears that the for loop cycles through the number of players but the conditional
inside only allows the current player to draw a card. This should be changed to exclude only the current player as 
they have already drawn four additional cards.
