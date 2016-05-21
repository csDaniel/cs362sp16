********************************************************************************
* randomhistory.c
*
* Jarrad Favre
*
* CS 362
*
* 5-11-2016
********************************************************************************

Last assignment's results for Adventurer Card in cardtest2.c

File 'cardtest2.c' - Adventurer Card
Lines executed:70.00% of 90
Branches executed:57.14% of 42
Taken at least once:30.95% of 42
Calls executed:52.50% of 40

This assignment's results for Adventurer Card in randomtestadventurer.c

File 'randomtestadventurer.c'
Lines executed:81.97% of 61
Branches executed:100.00% of 44
Taken at least once:72.73% of 44
Calls executed:100.00% of 8

    Compared to Assignment 3's and 4's results, I was able to get much better 
results. My lines executed went from 70% to 81.97%, and greatly improving my
branches and calls executed to 100% from 57.14% and 52.50% respectively. Even
my taken at least once results had greatly inproved from 30.95% to 72.72%. One
of the reason I believe I gotmuch better results, besides including random
testing with my test cases is that I took out a test case that I determined
was essentially not ended. Though I am happy with the improvement, I can still
do better, and one of the way I can do better is to better modularize my test
programs, as my test programs at the moment are not well divided up into 
functions, which will definitely help cut out some of the redundancy in them.

Last assignment's results for Smithy Card in cardtest1.c

Lines executed:80.39% of 51
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:62.96% of 27

This assignment's results for Smithy Card in randomtestcard.c

File 'randomtestcard.c'
Lines executed:80.49% of 41
Branches executed:100.00% of 18
Taken at least once:66.67% of 18
Calls executed:100.00% of 6

    Here we also see some great improvement compared to last assignments. Though
I was only able to improve my lines executed by a tenth, I am still happy with
the respectable 80.40% and know that if I just clean up my test program a bit
more that I can receive a much higher result. I was able to achieve the same
result of 100% in branches executed, but I greatly improved from 62.96 calls
executed to 100%. There was even improvement from taken at least once from 50%
to 66.67%

Last assignment's dominion coverage

File 'dominion.c'
Lines executed:33.21% of 560
Branches executed:40.24% of 415
Taken at least once:29.88% of 415
Calls executed:17.89% of 95

randomtestadventurer.c in dominion.c coverage

File 'dominion.c'
Lines executed:23.57% of 560
Branches executed:24.82% of 415
Taken at least once:17.35% of 415
Calls executed:12.63% of 95

randomtestcard.c in dominion.c coverage

File 'dominion.c'
Lines executed:23.57% of 560
Branches executed:24.82% of 415
Taken at least once:17.35% of 415
Calls executed:12.63% of 95

    A quick glance at randomtestadventurer.c and randomtestcard.c we see that I 
got the same exact results for both random test files. Now to compare them
individually with the results from last assignments, there is obviously a 
difference, but then we have to remember that last assignment's results were
from eight functions being tested and ran, getting a result of 33.21% of lines 
executed. This assignment only used did two! So considered that each random
test file, that specified on a card function, got 23.57% of lines executed
is significant improvement. Hopefully my testing knowledge and implementation
will continue to improve as I have seen thus far from one assignment to the
next.
