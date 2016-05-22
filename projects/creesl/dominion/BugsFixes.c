/*
Bug Fixes
Assignment 5

Reported Bugs
Adventurer
	Added a line to decrement numActions variable in adventurerEffect(),
	line 1255.
	Added discardCard() after adventuerEffect() in cardEffect(), line 671.
	Changed tempHand index from z to z-1, line 1252. This is the same as bug introduced in refactor.

Smithy
	Added a line to decrement numActions variable in adventurerEffect(),
	line 1266.
	Changed trashflag in discardCard() from 1 to 0, line 1268. This is the same
	as bug introduced in refactor.

Refactored Bugs
Treasure Map
	Changed return -1 to 1, line 1297.

Sea Hag
	Changed == to !=, line 1308.

Minion
	Changed state->coins + 1 to 2, line 1328.

Finding Bugs - Faults and Effects
The bugs refactored into the code were both caught in teammates' testing,
as well as some additional bugs.  With the adventurer card, the tests
caught that there was an issue, but the specific cause was a bit oblique.
If I had not refactored that particular code, it would have been
difficult to find that particular bug (the z instead of z-1). The effects
of the bug were being detected in the handCount of the players. However,
that was a result of a discarding error, and as such, looking for a
bug in handCount counting would not have detected the bug. This is an
example that the effects of a bug, even this directly, still aren't
necessarily an indicator of a direct cause. They can be good hints,
but more testing around a phenomena would probably be necessary to rule
out other causes.

Coverage - Reassurance without Guarantee
Having high coverage on tests is definitely preferable to having low
low coverage.  The indication that more of the code is being tested
can be a reassurance that bugs are not being missed due to simply
not executing faulty code. However, it is not a guarantee that bugs
will be detected in code covered simply because it is covered 
or that bugs caught when covered will be easy to locate.
The discard bug mentioned can serve as an example of this. While
the tests on adventurer covered this code and caught the bug,
the effects were oblique enough that the bug might not be readily
pinpointed.
Additionally, in tests with high coverge, even 100%, there is no
guarantee for bug detection. In my own tests with adventurer, for
example, there was very high code coverage, but I did not detect
the discardCard bug. This displays the importance of knowing thoroughly
what is being tested and the effects it should have and should not
have. While discarding is not necessarily a direct effect of adventurer,
it is an effect that playing  adventurer should have after it is played. 
Thus, even thoroughly covering the adventurer code would not be enough
to detect something that is not there and an effect that is somewhat
indirect.
Overall, code coverage seems to be a reassurance but not a guarantee.
It reassures that bugs are not hiding because of code that is not
tested but it does not guarantee bug detection in code that is covered.
Detection of bugs and pinpointing them relies more on test design
rather than just code coverage.

*/