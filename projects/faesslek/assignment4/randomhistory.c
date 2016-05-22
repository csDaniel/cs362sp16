/*****************************************************************************
* Author: Kelby Faessler
* Class: CS 362
* Assignment: #4 random testers
*****************************************************************************

I started by using a random number of players and checking outputs the same 
way I did in assignment 3. Then, I started generating random byte values to
put into the gamestate struct. It turns out that this completely breaks the
program (seg faults) because all the values being looked up in the adventurer 
card implementation rely on dereferencing values from the gamestate struct and
there aren't safety checks before this is done. It seems as though the 
adventurer implementation assumes the values in the gamestate struct that is
passed in will be valid. So, I had to comment out this random test (case 2)
and that's why it does not appear in the test output.

I knew that cardEffect when called for the adventurer card uses the deck count
for the current player. So, I decided to randomly set that. Again, this breaks
the program with segmentation faults because there are no checks before 
dereferencing things. But, if I set the deck count to something between 0 and 
150 (i.e. a more reasonable value) then the segmentation fault goes away. In
fact, the tests pass and the function works in this case.

When I randomly set the value of the hand count for the current player, again
I had to give it a somewhat reasonable value in order to avoid seg faults. 
This is a good lesson for me personally: always check any pointer value 
before using it! This time I decided to give it a value between 0 and 1000
and that still behaves alright.

As with the last assignment, we output coverage metrics using gcov to our
output file. For both tests my coverage seemed higher than with my unit tests
from assignment 3. Although that might partially be due to the fact that I
adjusted the tests to increase coverage as I went along.


*/