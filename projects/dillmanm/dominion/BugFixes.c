The following bugs in adventurer and smithy were picked up by both of my teammates:

Refactor playAdventurer
declare currentPlayer, drawntreasure, cardDrawn, tempHand[MAX_HAND], z
Bug: for loop searches hand for two treasures after each draw then terminates
so that treasures already in hand are counted in addition to drawn treasures.
changed at line 1325

Refactor playSmithy
declare currentPlayer, loopvariable
Bug: check if deck has less than three cards left, end turn and return if true.
changed at line 1341

The fix for the first involves removing the treasure count for-loop in the adventurer
refactored function. The smithy fix involves removing the check for the deck empty
condition and allowing the drawCard function's built-in reshuffle check to operate.

Coverage:

My tests provided complete statement and branch coverage for all targeted functions,
but did not attain total path coverage between unit tests and random tests, however. For instance, 
I did not test cases in Adventurer where only treasures in deck and discard are gold and there 
is a forced reshuffle. There cases would probably be advantageous and would pick up more insidious bugs
such as a compound bug where the reshuffle resets treasure counts and gold are not counted as
treasure.

Since none of these bugs were encountered and a quick survey of the relatively simple functions
can conclude that these bugs do not exist in my version of dominion nor my teammates, I think
it suffices to say that not attaining full path coverage was not detrimental. In far more
complicated systems more time should be devoted to tracking path coverage and pushing the
test routine toward 100% path coverage when possible.

Interestingly, I noticed that the C best practice of declaring used variables at the top
of any given function unless there is some sort of conditional dynamic creation makes
def-use coverage easily obtainable and synonymous with branch coverage. This is not the
case with all languages or with more obfuscated C code.

Full coverage information can be found in the related documents in this directory.

GDB:

I debugged my programs in both GDB and Valgrind. The final corrections do not encounteer any
memory problems or out of bound reads. The targeted regions of memory behave as anticipated.
The full GDB readouts are found in the files GDB<executablename>.out found in this directory.