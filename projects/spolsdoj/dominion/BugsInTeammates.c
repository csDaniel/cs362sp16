Assigment 5 Teammate Bug Report
By: James Spolsdoff

Teammate 1 = Jonathan Hardman

I ran my test suite against Jon's code. I found two bugs within his code.
The first bug was that the Smithy card was drawing 4 cards instead of the required
3 cards that are required to be correct. I did not need to refactor my test suite
to catch this bug as I included a similiar bug in my own code. The second bug that
I found was that adventurer card was not returning the correct number of coins.
At first I thought this was simply the loop running too many iterations but upon 
looking closer at the code I noticed that the adventurer card was not returning
after it was called. It would just go into the next cards effect. This was caught
by my test checking to see how many cards and treasure were drawn by the adventurer
card. I needed to just add a return on the switch statement in order to fix this bug.
None of my method names or parameters past needed to be changed for these tests. I edited 
my teammates makefile to run all the tests and output the results to tests.out. 

Teammate 2 = Andrew DiMuzio

I ran my test suite against Andrew's code. The first bug I found was in the Smithy card.
Like Jonathan's bug I would find that the card was drawing 4 cards instead of 3 as the
card originally was suppose to. I did not have to alter my test code as this was the same
bug that I had introduced in my version of Dominion. The second bug I found was rather
hard to find. Initially everything was working correctly with the adventurer card. It
was revealing the correct number of treasure cards. It was not until running my random tests
did I notice a bug. By running thousands of tests I noticed that there were no coppers
that were drawn. This struck me as odd and upon examining the code I came to realize that
the copper conditional was taken out of the card. I put this back in and ran my random
tests and noticed that coppers were again being drawn. None of the method names or parameters
passed needed to be changed in a major way for these tests. I edited my teammates amefile to
run all the tests and output the results to test.out.    
