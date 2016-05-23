Bugs1.c

Bug1
Adventurer Bugs: 
My refactored code makes continued errors: 
Hand Count Test: FAIL
Expected Result: 469
Actual Result: 471
Added Cards Test: FAIL
Expected Results: 6 Gold/ 5 Silver/ 4 Copper
Actual Count: 12, 13
Discard Count: FAIL
Expected Result: 182
Actual Result: 177
Player 0's Hand Count Test: FAIL
Expected Result: 5
Actual Result: 6
Player 0's Deck Count Test: FAIL
Expected Result: 5
Actual Result: 4

my refactoring causes an all around card-miscount 

Bug2
Smithy Bugs: 
Card Draw Sub Test: 3 Drawn, 1 Discarded, Net +2 Cards to Hand: FAIL, expected Net +2 Cards, Result +3 cards
Function was refactored to draw 4 instead of 3 cards 


My teammates found both of these problems as well, and to fix them, I just revert back to
the original cardEffect function. As the bugs found were Severe, but only changed the amount
of cards drawn and discarded, coverage didnt really change at all, just game play was affected.

Coverage: 
Coverage of Tests On Bug Code: 

Function 'playAdventurer'
Lines executed:100.00% of 19
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 4

As expected, our coverage of playAdventurer drops to 0: 
Function 'playAdventurer'
Lines executed:0.00% of 19
Branches executed:0.00% of 12
Taken at least once:0.00% of 12
Calls executed:0.00% of 4



/*Bug*/
Function 'updateCoins'
Lines executed:63.64% of 11
Branches executed:50.00% of 8
Taken at least once:37.50% of 8
No calls

/*No Bug*/
Function 'updateCoins'
Lines executed:63.64% of 11
Branches executed:50.00% of 8
Taken at least once:37.50% of 8
No calls

We see the same effect on updateCoins as this part wasn't effected. 

/*Bug*/
Function 'discardCard'
Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
No calls

/*No Bug*/
Function 'discardCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
No calls

We can see th difference. One of the bugs we introduced caused a discard to be triggered. 
Once we fixed it, we see the coverage drop to zero. 

/*Bug*/
Function 'cardEffect'
Lines executed:9.94% of 181
Branches executed:18.18% of 154
Taken at least once:5.84% of 154
Calls executed:9.80% of 51

/*No Bug*/
Function 'cardEffect'
Lines executed:11.86% of 194
Branches executed:20.48% of 166
Taken at least once:9.04% of 166
Calls executed:5.77% of 52

We see about a 2% increase in coverage because we reverted back to the 
original code which added about 20 lines of code back to our dominion.c file

/*Bug*/
Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

/*No Bug*/
Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

Same coverage for bug and no bug; even though there was a bug introduced, 
we still utilized this function to its full effect. 

Same for whoseTurn:
/*Bug*/
Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

/*No Bug*/
Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

Same for Shuffle:

/*Bug*/
Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2

/*No Bug*/
Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2

Same for initialize game: 

/*Bug*/
Function 'initializeGame'
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
Calls executed:100.00% of 5

/*No Bug*/
Function 'initializeGame'
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
Calls executed:100.00% of 5

Same for compare: 

/*Bug*/
Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

/*No Bug*/
Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls


We did see a drop in coverage for dominion.c: 

/*Bug*/
File 'dominion.c'
Lines executed:29.14% of 549
Branches executed:28.64% of 398
Taken at least once:21.86% of 398
Calls executed:18.09% of 94

/*No Bug*/
File 'dominion.c'
Lines executed:24.02% of 562
Branches executed:24.88% of 410
Taken at least once:19.02% of 410
Calls executed:11.58% of 95
Creating 'dominion.c.gcov'

This is attributed to our drop in discardCard and not using the function playAdventurer.
If we removed playAdventurer this would go up! 

We will experience very similar findings for our playSmithy bug testing, as we have only modified 
a small piece of the code, and for reasons of brevity, I will leave the actual results out of 
this file. 

For me, this was more of a lesson for moving forward in testing.  I examined the coverage after the fact, 
as I am not in the habit(yet!) of predicting coverage changes and factoring that into my testing. 
It was a good lesson to learn to identify places in our code to look for coverage and how it may change. 
The obvious example is that playAdventurer should (and did) drop to 0% once we fixed our bug. 
We can also look at things like, we want to see our discardCard function coverage change, as well 
as our overall coverage of the dominion.c file. 
