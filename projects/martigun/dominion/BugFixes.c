//
// Gunnar Martin
// CS362
// Spring 2016
//
// Assignment 5
// Bug Fixes
//
// Note: I slightly altered my test files from assignment 4. My new files are called
// `randomtestadventurer_a05.c` and `randomtestcard_a05.c` to avoid confusion.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug fix for brewbakl smithy card
// Teammate: brewbakl
// Card: smithy
// File: dominion.c
// Date: 22 MAY 2016
//
// Discussion: 
//
// To investigate this bug, I used GDB on my executable `randomtestcard` by typing in:
// `gdb randomtestcard` into the unix command prompt. I knew that I wanted to zero in and step through
// the lines of code within `cardEffect`, since that is where all the card functions are. So I typed in
// `break cardEffect` to tell GDB to break once we got to the `cardEffect` function. Then I typed `run` to 
// start the program. It correctly executed a break at the right spot and I started entering `next` to step
// through the pieces of `cardEffect` that were running, while not going into any other functions.
// As I was stepping through the steps I realized 3 things. First, I was coming back to `drawCard` way more than
// the 3 times that I was supposed to. Second, the fact that the loop was set to stop at 'i<6' instead of 'i<3'
// was the reason for this. Third, that after the loop, `discardCard` was called twice. Using GDB to step through
// the active code helped me to identify the issues.
//
// Fix: 
//
// To fix the code, I replaced 'i<6' with 'i<3' in the `drawCard` loop and I removed one of the calls to
// `discardCard`. After running my tests again, I saw that the tests were now passing.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug fix for brewbakl adventurer card
// Teammate: brewbakl
// Card: adventurer
// File: dominion.c
// Date: 22 MAY 2016
//
// Discussion: 
//
// To investigate this bug, I used GDB on my executable `randomtestadventurer` by typing in:
// `gdb randomtestadventurer` into the unix command prompt. I knew that I wanted to zero in and step through
// the lines of code within `cardEffect`, since that is where all the card functions are. So I typed in
// `break cardEffect` to tell GDB to break once we got to the `cardEffect` function. Then I typed `run` to 
// start the program. It correctly executed a break at the right spot and I started entering `next` to step
// through the pieces of `cardEffect` that were running, while not going into any other functions.
// As I was stepping through the steps I realized that the if statement that is looking for treasures
// (determining whether the card drawn was copper, silver, or gold) was not looking for copper.
// The if statement was 'if(cardDrawn==silver||cardDrawn==gold)...' which excludes copper. Using GDB to step
// through the active code helped me to identify the issue.
//
// Fix: 
//
// To fix the code, I replaced 'if(cardDrawn==silver||cardDrawn==gold)...' with 
// 'if(cardDrawn==silver||cardDrawn==gold||cardDrawn==copper)...'. After running my tests again, I saw that
// test were now running without any failing the "shuffle anomaly" that I described in `BugsInTeammates.c`.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug fix for brownjoh smithy card
// Teammate: brownjoh
// Card: smithy
// File: dominion.c
// Date: 22 MAY 2016
//
// Discussion: 
//
// To investigate this bug, I used GDB on my executable `randomtestcard` by typing in:
// `gdb randomtestcard` into the unix command prompt. I knew that I wanted to zero in and step through
// the lines of code within `cardEffect`, since that is where all the card functions are. So I typed in
// `break cardEffect` to tell GDB to break once we got to the `cardEffect` function. Then I typed `run` to 
// start the program. It correctly executed a break at the right spot and I started entering `step` to step
// through the pieces of `cardEffect` that were running, since I needed to jump to the function that brownjoh
// called to handle the action of smithy, `playSmithy`. As I was stepping through the steps I realized that as  
// the function `playSmithy` was calling the function `discardCard`, it was setting the trashFlag to 1,  
// instead of 0. Using GDB to step through the active code helped me to identify the issues.
//
// Fix: 
//
// To fix the code, I replaced `discardCard(handPos, currentPlayer, state, 1)` with
// `discardCard(handPos, currentPlayer, state, 0)`. After running my tests again, I saw that the tests 
// were now passing.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug fix for brownjoh adventurer card
// Teammate: brownjoh
// Card: adventurer
// File: dominion.c
// Date: 22 MAY 2016
//
// Discussion: 
//
// To investigate this bug, I used GDB on my executable `randomtestadventurer` by typing in:
// `gdb randomtestadventurer` into the unix command prompt. I knew that I wanted to zero in and step through
// the lines of code within `cardEffect`, since that is where all the card functions are. So I typed in
// `break cardEffect` to tell GDB to break once we got to the `cardEffect` function. Then I typed `run` to 
// start the program. It correctly executed a break at the right spot and I started entering `step` to step
// through the pieces of `cardEffect` that were running, since I needed to jump to the function that brownjoh
// called to handle the action of adventurer. As I was stepping though the steps I noticed 2 things. First,
// the if statement that controls how many loops are done while still looking for treasures was actually not
// stopping until 3 treasures were drawn instead of 2. Second, the while loop that controls the movement of the
// `tempHand` into the discard pile was running too few loops. Using GDB to step
// through the active code helped me to identify the issue.
//
// Fix: 
//
// To fix the code, I performed a replace of the code 'while(drawntreasure<=2)...' with 
// 'while(drawntreasure<2)...' for the treasure search loop. Also, I replaced the instances of
// 'drawnTreasure' in the tempHand to discard loop with 'z', which is the correct counter for moving
// cards from tempHand to discard. After running my tests again, I saw that the tests 
// were now passing.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug fix for martigun smithy card
// Teammate: martigun
// Card: smithy
// File: dominion.c
// Date: 22 MAY 2016
//
// Discussion: 
//
// To investigate this bug, I used GDB on my executable `randomtestcard` by typing in:
// `gdb randomtestcard` into the unix command prompt. I knew that I wanted to zero in and step through
// the lines of code within `cardEffect`, since that is where all the card functions are. So I typed in
// `break cardEffect` to tell GDB to break once we got to the `cardEffect` function. Then I typed `run` to 
// start the program. It correctly executed a break at the right spot and I started entering `next` to step
// through the pieces of `cardEffect` that were running, while not going into any other functions.
// As I was stepping through the steps I realized 3 things. First, I was coming back to `drawCard` more than
// the 3 times that I was supposed to. Second, the fact that the loop was set to stop at 'i<4' instead of 'i<3'
// was the reason for this. Third, that after the loop, `discardCard` was called twice, with the second call
// discarding an incorrect card. Using GDB to step through the active code helped me to identify the issues.
//
// Fix: 
//
// To fix the code, I replaced 'i<4' with 'i<3' in the `drawCard` loop and I removed one of the calls to
// `discardCard`. After running my tests again, I saw that the tests were now passing.
//
// ----------------------------------------------------------------------------------------------------------
// Title: Bug fix for martigun adventurer card
// Teammate: martigun
// Card: adventurer
// File: dominion.c
// Date: 22 MAY 2016
//
// Discussion: 
//
// To investigate this bug, I used GDB on my executable `randomtestadventurer` by typing in:
// `gdb randomtestadventurer` into the unix command prompt. I knew that I wanted to zero in and step through
// the lines of code within `cardEffect`, since that is where all the card functions are. So I typed in
// `break cardEffect` to tell GDB to break once we got to the `cardEffect` function. Then I typed `run` to 
// start the program. It correctly executed a break at the right spot and I started entering `next` to step
// through the pieces of `cardEffect` that were running, while not going into any other functions.
// As I was stepping through the steps I realized that when `discardCard` was being called, even though
// it should not be.  Using GDB to step through the active code helped me to identify the issues.
//
// Fix: 
//
// To fix the code, I replaced `discardCard(handPos, currentPlayer, state, 1)` with
// `discardCard(handPos, currentPlayer, state, 0)`. 

// To fix the code, I removed the call to `discardCard`. After running my tests again, I saw that the tests 
// were now passing.
//
