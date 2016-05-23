Fixed Bugs:

Fixed Adventurer where it would draw three treasures 
	-changed the amount the while loops

Fixed Smithy where it would draw four cards instead of three
	-changed the for loop

Fixed Council where the card would not be discarded from hand

Fixed Game over function where province cards could become negative
	- would not necessarily happen in traditional gameplay
	- discardCard bug is in the same vein so it doesn't necessarily need to be addressed

Fixed Adventurer bug where it would not discard card after the function ended
	- not sure if intentional or lost in the refactoring
	- was probably not lost in refactoring as handPos was never passed, but is needed in order to get discard the card.
	- added handPos and added discard



Discussion:

When creating these tests it did not occur to me how difficult it would be to maintain a test suite with assert statements. We didn't have a nice testing framework like JUnit as I did in my other classes, so when certain tests would fail it would cause the testing program to fail and as a result it was very difficult to find multiple bugs without going in and commenting out each assert statement.

With assert statements to test for bugs every time I encountered one I would have to make note and then comment it out so it would run, through the next test. While it helped make it obvious which bugs were present, it was a pain. In addition to this, I wasn't always sure if the assert was due to differences in the way my teammates codes and mine were refactored or not.

In the future if I had to redo this I would use if and else statements and print out desired results as this would've made my life much easier.

In testing the functions of my teammates I only had to refactor a little of the code so that it'd work. They used more of the innate functions of the program like whoseTurn() instead of passing in the player directly. Passing the current player directly allows for easier testing, but the result is fairly similar functions. 

As far as coverage goes, it happens that we added bugs in and chose to do the similar cards (council, in addition to the two required ones) which helped me find bugs as my testing code did cover those cards. However if they had chosen other cards this assignment and my coverage would have faltered and been much less useful.

overall the test suite was pretty useful in deciphering bugs, although I could've improved it in this case by using if statements instead of asserts. 

