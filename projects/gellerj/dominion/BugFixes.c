/*

    BUGS FIXED:

    Bug: Smithy is not trashed after play. This bug was introduced in assignment 2 and found by a teammates'
    (Alex Samuel) card test. While fixing this bug I discovered a related bug in my test library, which
    returned a false negative for this test. After the library bug was fixed I was able to confirm that my
    Smithy trash bug was fixed as well. Smithy now passes all tests.

    Bug: Adventurer card does not consider Gold cards as Treasure cards when drawing 2 Treasure cards. This
    bug was introduced in assignment 2 and found by a teammates' (Alex Samuel) card test. I was able to fix
    this bug by adding gold cards back to the conditional list of checks made by the Adventurer card when
    scanning the deck for treasure cards. Adventurer now passes all tests.

    Bug: When Village card is played, player's actions are set to 2, instead of incremented by two. Both
    of my teammates' detected this bug, however, their tests did not accurately analyze the implications of the
    bug. Alex Samuel's failure message indicated that "actions are incremented by only +1 rather than +2", which
    is not accurate. It is true that the player's action count will be 2 if they start with 1 action, however, the
    real nature of the bug implies that the action count will *always* be two.

    Bug: scoreFor() does not calculate accurate scores for certain game states. This was not a bug I introduced
    in assignment 2, but rather one that seems to be present in the original copy of the game code. Thanks to
    helpful error messages provided by my teammates' tests, I was able to fix this function and return accurate
    game scores. First, I updated the code to iterate through the correct pile between 0 and deckCount rather
    than 0 and discardCount. This prevents the function from iterating through the discard pile twice.

    The second bug in this function was caught by both teammates' tests and relates to the way that scores are
    calculated for Garden cards. Garden card score is based on the number of cards in the deck, and in this
    buggy score function, only curse cards are counted. Therefore, garden cards are not awarded as many points
    as they should be. To fix this, I wrote a modified version of fullDeckCount called countAllDeckCards which
    simply sums the cards across all of the players' piles. I then replaced the calls to fullDeckCount in scoreFor,
    which fixed this bug.

    SUMMARY:

    The unit tests helped to discover existing bugs, as well as bugs I had not previously detected.
    Having more tests to run increased coverage and made it possible to explore new statements and branches
    that had not been touched.

    I found the addition of new tests helpful, especially the unit tests that
    relate to basic game functions like scoreFor(). Since so many game cards call these utility functions,
    they can be considered high-priority targets for testing. Fixing a bug in a function like scoreFor may
    end up fixing multiple bugs that appear downstream when this method is utilized throughout the game code.

    For similar reasons, I found the game card tests to be less useful. Often times, the bugs in game cards
    actually resulted from bugs in utility functions used by the game cards (e.g. discardCard, drawCard).
    This led to game card tests reporting bugs that did not actually have to do with the game card logic
    itself, making it harder to detect the actual source of the bug. It seems that the closer one gets to
    core game functions, the more useful the tests become.

    I also learned the importance of making sure your unit tests are not affected by unforeseen bugs. It's
    easy to think you are testing for the presence of a certain bug, but unanticipated bugs may cause your
    test to return false positives or negatives that are actually unrelated to the use case you thought you
    were testing for. This can be very tricky, since many bugs are unanticipated by their very nature. One
    way to reduce confusion in these cases is to use more generic error messages, and then use the debugger
    to determine their exact cause. Very specific error messages may mislead a developer into looking in
    the wrong spots for a bug that is actually caused by a bug in a different location.

 */