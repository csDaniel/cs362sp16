/******************************************************************************
Michael Hueter
CS 362 Assignment 5
BugsInTeammates.c - identifying bugs in teammates' dominon code

My two teammates were Jessica Siano (sianoj) and Grant Smith (smithg6). Each of
their dominion folders have been copied in this directory. You can see my tests
have also been inserted there (check the *hueterm.c files). Jessica and Grant
had vastly different function and test implementations, but I was able to modify
my test suite to effectively test and uncover bugs in each of their projects.
For evidence of this, check the Makefiles in each of their project folders here
and examine the unittestresultshueterm.out and randomtestadventurerhueterm.out
for logs and coverage information. Below I will document what bugs I reported
to my teammates and how I was able to modify my test suite to fit each of their
implementations.

-- teammate #1 - sianojDominion (Jessica) --------------------------------------
    Jessica implemented the  card functions in a very different way
    than I did. Specifically, she made the card functions void() where my tests
    were expecting an int() with a checkable return value. Therefore, I examined
    her test code and realized she was using cardEffect() to call the card
    functions. Luckily, I was able refactor my tests to do the same thing
    without compromising their functionality.

--- adventurer card tests [BUG FOUND]
    After running these tests, my assertions immediately pointed out that
    Jessica's adventurer function was giving out too many cards to users:
    "! ASSERTION FAILED: EXPECTED Player 1 should now have 8 cards == 8, NOT 9."
    Using GDB, I was able to step through and I found that the 'drawntreasure'
    variable was being allowed to increment to 2, meaning player 0 consequently
    could draw three cards, instead of 2. I pointed this bug out, and it turns
    out this is the bug she introduced (she modified while loop on line 1287).
    All other types of assertions passed, so I concluded her function was
    otherwise OK.

--- random test adventurer [BUG FOUND]
    Both Grant and I had segmentation faults when calling our random testers
    on Jessica's adventurer card. Unfortunately, gdb was not very helpful
    because it pointed to memory location 0x0000000 ?? () when we tried to
    isolate the segfault. I noticed that in my code print statements, however,
    that more cards were being discarded than were being drawn, which makes
    sense that it would eventually cause a segfault because cardEffect would try
    to reference invalid memory locations to discardCard(). I hypothesize that
    the bug is related to this compiler warning in Jessica's code: "dominion.c:
    In function ‘cardEffect’ dominion.c:670:20: warning: ‘cardDrawn’ may be used
    uninitialized in this function". I believe 'cardDrawn' needs to be
    initialized to zero to prevent this warning and subsequently, the
    segmentation fault, so I've notified Jessica of this bug.

--- smithy card tests [BUG FOUND]
    Similar to the adventurer card above, I noticed that smithy was throwing an
    off-by-one assertion error, specifically: "! ASSERTION FAILED: EXPECTED
    Player 1 should draw 3 cards and discard smithy to have 8 total == 8, NOT 7"
    There were also other assertion errors which indicated that smithy was not
    drawing three cards (as intended). It seemed to only let the player draw two
    cards. Upon closer inspection with gdb, this was certainly the case because
    I noticed in dominion.c on line 1264, the smithy function starts at i = 1
    instead of i = 0. This means drawCard() only gets called twice and the
    player only draws two cards instead of three. I reported this to Jessica,
    lo and behold it was another problem that she introduced in her original
    assignment. All other assertions passed, thus I concluded her function was
    otherwise OK.

--- other functions' unit tests [NO BUGS FOUND]
    My other unit tests ran against getCost(), isGameOver(), numHandCards(), and
    gainCard() and I did not uncover any additional bugs. This makes sense
    because I did not find any bugs against my own dominion code for these
    functions and I do not believe Jessica modified any of these in her dominion
    source.
--------------------------------------------------------------------------------

-- teammate #2 - smithg6 (Grant) -----------------------------------------------
    Grant's function implementations were much more similar to mine, so it was
    really straightforward to hook up my card tests to his implementation.

--- adventurer card tests & randomtestadventurer [BUG FOUND]
    The bug in Grant's adventurer function is more difficult to locate. It seems
    that from both the card test and random tester that the player is not being
    allowed to draw treasure cards properly. These assertions failed:
    (1) "! ASSERTION FAILED: EXPECTED Player 1's n-1 card should be treasure
    == 1, NOT 0."
    (2) "! ASSERTION FAILED: EXPECTED Player 1 should now have 8
    cards == 8, NOT 6."
    (3) "! ASSERTION FAILED: EXPECTED Player 1's 7th card should be treasure ==
    1, NOT 0."
    Basically, this leads me to conclude that no treasure cards are being drawn.
    I suspect this has to be something with drawntreasure not incrementing
    properly. I reported this bug to Grant.

--- smithy card tests [NO BUGS FOUND]
    My card tests cannot identify any bugs in Grant's smithy function. It would
    appear that his function is working properly. Although it is certainly
    possible that my unit tests are not able to find the error. On manual
    inspection, it seems that he has set his discardCard() trash flash to i,
    I'm not sure what effect this would have on the game itself but it will
    not effect the cardSmithy() function as he introduced a bug in another
    function that I have not set up tests for. I notified him of this.

--- other functions' unit tests [NO BUGS FOUND]
    As above, my other unit tests ran against getCost(), isGameOver(), 
    numHandCards(), and gainCard() and I did not uncover any additional bugs.
******************************************************************************/
