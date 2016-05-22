/***
Alex Marsh
CS362 Assignment 5

My teammates reported several bugs in their reports.  These bugs are listed below along with my effort to correct them. 


The bug report from my teammate Tatsiana Clifton contained 4 bugs.  The first bug was found in the function scoreFor(). The function was returning an incorrect scrore for discard and deck. With a priority and severity both set at high, I set out to find my error.  Using my own and teammates test cases along with the gbd debugger I found the error in a for-loop within the function.  The tests showed that the score count for deck was always 0.  The error layed in the line : 
        for (i = 0; i < state->discardCount[player]; i++)
This line has the deck count rely on the discard count instead of the intended deckCount.  With this line the function goes through the discard pile for iterations in order to count the deck.  In the tests, the other piles (discard and hand) were set to 0 in order to correctly test a count for deck.  To correct this error I changed the line to:
        for (i = 0; i < state->deckCount[player]; i++)
This proved to be a correct fix for the scoreFor function. 

Another bug found by my teammate was in the implementation of the smithy card.  The error was that when playing the smithy card the current player recieving 4 cards instead of the intended 3.  This count is supposed to be 3 as the player draws three cards and the discards the smithy card. However, the tests found that the players hand contained the unintended 4 cards. Using my own and teammates test cases along with the gbd debugger I found the error in a for-loop within the function. The error was found in the line:
        for (i = 0; i <= 3; i++)
The code "i <=3" resulted in the loop executed 4 times and allowing the player to draw one to many cards.  To fix this error I changed the line to:
        for (i = 0; i < 3; i++)
This way the for loop only executes 3 times and the player draws the correct amount of cards. 

The third bug found by Tatsiana Clifton was found in the implementation of the adventurer card. My teammate reported that the adventurer card did not change the play count. In her report she states "The play count should be increased by 1. The call of the function discardCard should be added to the adventurer card." I had a lot of difficulty finding the source of this error. Using my own and teammates test cases along with the gbd debugger I found the error lied in my own introduced bug.  Initially I introduced an error in the while loop. Originally the code was 'while(drawntreasrue<2)...', but I changed it to 'while(drawntreasrue<=2).  This caused the loop to execute three times instead of the intended two. Because the extra iteration gave the player another card, it seemed in the tests that the player never discards.  By fixing my intial bug (changing <= to <) I found and fixed the reported error. 

The last bug reported by my teammate was in implementing the village card. Her error is titled: The village card: the player does not receive exact 1 card. In her report she states The function should add 1 card to the player's hand. It adds 1. One drawCard(currentPlayer, state); should be removed."  It seems that this report has found the error I introduced in the previous assignment. Originally I had called the drawCard function twice.  This gave the player two cards instead of the intended one.  In order to fix this error I removed one of the drawCard call from the village card implementation. 


My other teammate, Christina Nock, reported the same error in the adventurer card and smithy card implement as my first teammate.  By correcting the errors from Tatsiana's bug report, I intermitedly fixed the bugs Christina reported as well. This shows that both teammates wrote test cases with good coverage of the dominion code. 

Along with the errors reported by my teammates, I also fixed the errors I had previous introduced. The reports found the errors I introduced in the smithy, adventurer, and village card implementation.  However, I still had introduced an error in the minion implementation. In order to fix this error I needed to change the bug I placed in the for loop from 'i < 4' to 'i <= 4'. This error allowed the player to draw the proper amount of cards. 


**/