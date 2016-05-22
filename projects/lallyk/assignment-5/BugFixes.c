/* 
Kara Franco
Assignment #5 Part 2
Due Date: May 22, 2016


------- Bug’s Found by Rosa --------

I failed several of Rosa’s tests for the adventurer(), smithy() and great_hall() cards. 

In adventurer() I failed her tests “Player does not receive 2 new cards” and “Exactly 2 cards are taken from the deck”. To fix 
these bugs I used gdb to find the while loop where the treasure cards are given. I then changed the <= 2 to < 2.

In smithy() I failed her tests “Player does not receive 3 new cards” and “Exactly 3 cards are taken from the deck”. To fix these 
bugs I used gdb to find the for loop in smithy() where the count started at 1. I change the index to count from 0. 

In great_hall() I failed her test “Exactly one card was not taken from the deck”. To fix this I ran my program through gdb and 
found the line where I added the state->numActions--. This resolved this bug, and gave the player one action.

------- Bug’s Found by Sam -------

I failed Sam’s tests in for the smithy() and adventurer() cards. 

In adventurer() he found the same bug as Rosa, where there treasure cards we not disbursed correctly. So this bug was already 
fixed. 

In smithy() Sam found the bug that Rosa also found. This bug was fixed to give the player 3 cards rather than 2. 

---- Bug’s I fixed myself ----
In adventurer() I fixed the bug where the silver coin was not an option in the disbursement of coins. I ended up fixing this 
bug through gdb, where I found that throughout the game the silver coin was never released from adventurer(). In smithy() my 
classmates found all my bugs. In great_hall() Rosa caught the bug. In gardens() I removed the line: state->coins = state->coins + 2 
that gave an extra perk to the card. Lastly, I fixed minion() by changing the increment of j back to (j = 0; j < 4; j++) in the 
for loop. The last two bugs I found and fixed through gdb and inspecting the scripts. 

*/