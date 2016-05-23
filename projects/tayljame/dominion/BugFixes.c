/*
Author: James Taylor
Date: 5/22/16

Bug fix report:

 - From Joe Cuellar bug report:
    --------------------------------------------------------
    Bug4: 'i' was set to begin at 1 in the for loop rather than 0
    Fix: corrected loop counter and set to 0.
    Location: smit_ref() line: 713 (different from report of 709, different versions suspected)
    Update code snippet: for (i = 0; i < 3; i++)

    notes: counter was adjusted and ran against test suite. All tests passed.

    status: resolved

    ---------------------------------------------------------
    Bug5: deckCount condition was > instead of <.
    Fix: corrected code to >
    Location: adventurer_ref() line:660 (bug report reflects line 656, confirmed same location)
    Updated code snippet: if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck

    notes: shuffle function appears to be corrected but further testing is required. Current test suite does not have adeguate coverage or reporting
            and did not find fault in initial testing. My current test suite does not determine pre and post status of the the player deck.

    status: requires further testing. action suggested is refined test suite for specific issue.

    ----------------------------------------------------------
    Bug6: council_room_ref function does not call discardCard.
    Fix: added function call to discardCard, refactored council_room_ref() to include handPos param
            and tracked function calls in cardEffect() to add additional param changes.
    Location: line 679 - adjusted function declaration to include handPos param
                            code snippet: int council_room_ref(struct gameState* state, int currentPlayer, int handPos)
              line 700 - added call to discardCar()
                            code snippet:  discardCard(handPos, currentPlayer, state, 0);

              line 768-769 - added param to function call in cardEffect
                            code snippet: return council_room_ref(state, currentPlayer, handPos);


    -----------------------------------------------------------

    Discussion:
    It was a good to take this process and see both sides of debugging, both as the tester and the programmer making the bug fixes. The
    concepts of proper reporting with clear, concise language and standards really become clear as I was comparing the two bug reports from
    teammates. Two interesting points I noticed, first in bug 6 I got to see (on a limited basis of course) the way a bug in one part of the
    code required refactoring throughout the piece of software. Changing the declaration of the function required fixing the bug across more
    than one location. Second, while the tests I wrote for previous assignments found and validated key pieces of information they did not in fact
    find one of my introduced bugs. The shuffle() function being incorrectly called every time did not change the game state, but would actually affect
    the outcome of an actual game played in a real implementation of the system. The code coverage included the bug, but did not find it. My testing
    logic was not refined enough. The use of a debugger in this case would be helpful, as I would be able to see and step into the call of the shuffle function, and
    see it was done at an inappropriate time.







*/
