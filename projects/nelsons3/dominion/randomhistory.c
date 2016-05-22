/*
Using the new random test for randomtestadventurer yields 
100% of 37 lines, 100% of 16 branches, 94% of 16 branches was taken at least once, 
and 94% of 17 calls were executed according to gcov file.  

The randomcardtest was much worse in terms of whether or not it passed or failed.  It 
appears I wrote it wrong as the test passes 50% of the time and 'fails' 50% of the time.
I believe these are false positive fails though as the values are indeed what I expect..
it just triggers the fail message for some reason.  Randomtestcard.c still managed to execute 
96% of 50 lines, all 22 branches, most of the lines were taken at least once (91%), 94% of 30
calls were executed according to the randomtestcard.c.gcov.  

Dominion still has 41% of 563 lines being executed and achieves a 40% of the branches being 
executed (out of 563 possible).  
*/