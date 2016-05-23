Osbaldo Esquivel
CS 362
Assignment 5
19MAY2016

===========================
             Dominion Bug Reports
===========================

To start, I grabbed the necessary dominion.c files from my teammates and placed them in folders I created in my Dominion folder. Then, I copied all of my unit tests and card tests to the folder to run them and find any bugs. After reviewing both of my teammate's files, it was apparent that I did not need to refactor their code in order to run my tests which saved me some time. Below are the results for the tests I ran against my teammate's dominion.c files:

---------------------------------------
     Jason Loomis Bug Report
---------------------------------------

** Coverage information **

File 'dominion.c'
Lines executed:43.99% of 566
Branches executed:52.97% of 421
Taken at least once:33.49% of 421
Calls executed:29.59% of 98

--------------------
       Bug #1
--------------------

Class: Bug

Date: 17MAY2016
Reported by: Osbaldo Esquivel
Email: esquiveo@oregonstate.edu

Product: dominion.c
Platform: flip.engr.oregonstate.edu
Browser: n/a
URL: n/a

Is it reproducible: Yes

Description
=============

When I ran my unit test for the cardEffectAdventurer() function, the expected state and the actual state did not match. My random test also showed that the deck card count was not valid.

Steps to Reproduce
=============

1. Start a new game
2. Initialize the state of the game
3. Call cardEffect() specifying the Adventurer card

Expected Results
=============

The expectation is that this card function will loop until two treasure cards are drawn.

Actual Results
=============

The function loops until three treasure cards are drawn which may cause buffer overflow.

Workaround
=============

Change the while loop to while(drawntreasure < 2) to only draw two cards.

Attachments
=============

None

Other Information
=============

None



--------------------
       Bug #2
--------------------

Class: Bug

Date: 17MAY2016
Reported by: Osbaldo Esquivel
Email: esquiveo@oregonstate.edu

Product: dominion.c
Platform: flip.engr.oregonstate.edu
Browser: n/a
URL: n/a

Is it reproducible: Yes

Description
=============

When I ran my unit test for the cardEffectSmithy() function, the expected state and the actual state did not match.

Steps to Reproduce
=============

1. Start a new game
2. Initialize the state of the game
3. Call cardEffect() specifying the Smithy card

Expected Results
=============

The expectation is that three cards are drawn and then one is discarded.

Actual Results
=============

The for loop in smithyCard() loops 4 times instead of 3 so too many cards are drawn.

Workaround
=============

Change the for loop to loop while i < 3 instead of i <= 3.

Attachments
=============

None

Other Information
=============

None


---------------------------------------
     Preston From Bug Report
---------------------------------------

** Coverage information **

File 'dominion.c'
Lines executed:43.81% of 557
Branches executed:52.15% of 418
Taken at least once:33.01% of 418
Calls executed:30.11% of 93

--------------------
       Bug #1
--------------------

Class: Bug

Date: 17MAY2016
Reported by: Osbaldo Esquivel
Email: esquiveo@oregonstate.edu

Product: dominion.c
Platform: flip.engr.oregonstate.edu
Browser: n/a
URL: n/a

Is it reproducible: Yes

Description
=============

In the adventurerCard() function of dominion.c, I receive a SEG fault when attempting to run a unit test on this card. The assert statement in my unit test that compares the game state to the expected game state fails.

Steps to Reproduce
=============

1. Start a new game
2. Initialize the state of the game
3. Call cardEffect() specifying the Adventurer card

Expected Results
=============

The expectation is that this card function will loop until two treasure cards are drawn and the deck is only shuffled when it is empty.

Actual Results
=============

The function only loops until it finds one treasure and then it returns. Additionally, it will shuffle the deck every time instead of only when it is empty.

Workaround
=============

None

Attachments
=============

None

Other Information
=============

None



--------------------
       Bug #2
--------------------

Class: Bug

Date: 17MAY2016
Reported by: Osbaldo Esquivel
Email: esquiveo@oregonstate.edu

Product: dominion.c
Platform: flip.engr.oregonstate.edu
Browser: n/a
URL: n/a

Is it reproducible: Yes

Description
=============

In the smithyCard() function of dominion.c, I receive a SEG fault when attempting to run a unit test on this card. The expected state and the actual state did not match.

Steps to Reproduce
=============

1. Start a new game
2. Initialize the state of the game
3. Call cardEffect() specifying the Smithy card

Expected Results
=============

The expectation is that this card function will loop and draw three cards and then discard a card.

Actual Results
=============

The for loop in smithyCard() loops 4 times instead of 3 so too many cards are drawn. Also,  setting the trashFlag variable to 1 means it is not added to the played pile which I believe may cause buffer overflow.

Workaround
=============

None

Attachments
=============

None

Other Information
=============

None