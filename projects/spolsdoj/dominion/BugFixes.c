CS 362 Assignment 5
By: James Spolsdoff

Dominion BugFix for Andrew Dimuzio
-added copper as a conditional for incrementing draw treasure
 when card is played.
-changed the loop range from 4 to 3 so that the correct number of
 cards is drawn for the smithy.

Dominion BugFix for Jonathan Hardman
-took out the = from the smithy loop. It was drawing too many cards.
-added 'return' to the switch statement after 'adventurer' card condition
 was met.

Dominion BugFix for James Spolsdoff
-change adventurer implementation to assure loop allowed for correct number
 of treasure card draws.
-changed the loop range to 3 in order for the correct number of cards to be
 drawn.

During my testing I realized that my code coverage could definately be improved.
For example it was tough for me to catch the reason for Jonathan's adventurer card
returning a higher number of treasure. I knew something was wrong with the card
but all of the branches were functioning correctly through my tests. It wasn't until
I went through physically line by line talking through the code did I realize that 
something was missing and that was the 'return' statement. I guess its a lesson that
sometimes testing will tell you that something is wrong but can never beat actually
talking your way through the code.  
