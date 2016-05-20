####################################################
#Suyana Lozada
#Assignment #5
#Date: 05/16/2016
#Description: BugsInTeammates.c bug report of
#bugs encountered in teammates dominion source code
#####################################################


***********Teammate #1 Shawn Seibert****************

######Bug Report #1######### 

Title:Player draws 4 cards instead of 3 cards when drawing the smithy card..

Product: Dominion Game 

Classification: Serious bug which causes the smithy card effect to be
incorrect when this card is drawn by a player in the game.

Platform: 
host:  flip 3
LSB Version:	:core-4.1-amd64:core-4.1-noarch:cxx-4.1-amd64:cxx-4.1-noarch:desktop-4.1-amd64:desktop-4.1-noarch:languages-4.1-amd64:languages-4.1-noarch:printing-4.1-amd64:printing-4.1-noarch
Distributor ID:	CentOS
Description:	CentOS Linux release 7.2.1511 (Core) 
Release:	7.2.1511
Codename:	Core
kernel version: Linux 3.10.0-327.10.1.el7.x86_64 x86_6


Can it be reproduced?: Yes it can be reproduced every time player draws the Smithy card.

Description:Player does not draw three cards when the smithy card is drawn. Player draws 4 cards when the smithy card is drawn. 

What is the error: The is no error message associated with this bug.

Supporting Information: 

Steps to reproduce: Run cardtest1.c

cs362sp16/projects/lozadas/teammate1Dominion/cardtest1.c

1.Initialize Game
2.Draw smithy card
3.Count the number of cards in the player hand.

Expected Results: The expected result is for the player to draw the correct
number of cards ( 3 cards)

Actual results: The Player draws 4 cards. 

Workaround: No work arounds has being identified. 


Attachments: Unit test results:

Testing smithy()
Test 1: player 0 draws the correct number of cards (3 cards)
FAIL: test = 8, expected = 7

######Bug Report #2######### 

Title: Player does not draw two treasury cards when drawing adventurer card. 

Product: Dominion Game 

Classification: Serious bug which causes the adventurer cards effect to be
incorrect when this card is drawn by a player in the game.

Platform: 
host:  flip 3
LSB Version:	:core-4.1-amd64:core-4.1-noarch:cxx-4.1-amd64:cxx-4.1-noarch:desktop-4.1-amd64:desktop-4.1-noarch:languages-4.1-amd64:languages-4.1-noarch:printing-4.1-amd64:printing-4.1-noarch
Distributor ID:	CentOS
Description:	CentOS Linux release 7.2.1511 (Core) 
Release:	7.2.1511
Codename:	Core
kernel version: Linux 3.10.0-327.10.1.el7.x86_64 x86_6


Can it be reproduced?: Yes it can be reproduced every time player draws the Adventurer card.

Description:Player does not draw two treasury cards when the smithy card is drawn. Player does not draw two cards.

What is the error: The is no error message associated with this bug.

Supporting Information: 

Steps to reproduce: Run cardtest2.c

cs362sp16/projects/lozadas/teammate1Dominion/cardtest2.c

1.Initialize Game
2.Draw adventurer card
3.Count the number of treasury cards in the player’s hand. 

Expected Results: The expected result is for the player to draw two treasury
cards from the deck

Actual results: The Player does not draw treasury cards from the deck.

Workaround: No work arounds has being identified. 


Attachments: Unit test results:


Testing adventurer()
Test 1: player 0 draws two treasury cards from deck
FAIL: test = 0, expected = 8
Test 2: player 1 deck remains unchanged
PASS: test = 10, expected = 10
Test 3: discard deck should not have any treasure cads
PASS: test = 0, expected = 0

Testing complete 

######Bug Report #3######### 

Title: Player does not draw 4 cards when drawing the council room card. 

Product: Dominion Game 

Classification: Serious bug which causes the council room card effect to be
incorrect when this card is drawn by a player in the game.

Platform: 
host:  flip 3
LSB Version:	:core-4.1-amd64:core-4.1-noarch:cxx-4.1-amd64:cxx-4.1-noarch:desktop-4.1-amd64:desktop-4.1-noarch:languages-4.1-amd64:languages-4.1-noarch:printing-4.1-amd64:printing-4.1-noarch
Distributor ID:	CentOS
Description:	CentOS Linux release 7.2.1511 (Core) 
Release:	7.2.1511
Codename:	Core
kernel version: Linux 3.10.0-327.10.1.el7.x86_64 x86_6


Can it be reproduced?: Yes it can be reproduced every time the player draws the council room card.

Description:Player does not draw 4 cards when the council room card is drawn. Player draws 5 cards instead of 4 cards.

What is the error: The is no error message associated with this bug.

Supporting Information: 

Steps to reproduce: Run cardtest3.c

cs362sp16/projects/lozadas/teammate1Dominion/cardtest3.c

1.Initialize Game
2.Draw council room card
3.Count the number of cards in the player’s hand. 

Expected Results: The expected result is for the player to draw 4 cards
cards from the deck

Actual results: player draws 5 cards instead of 4 cards.

Workaround: No work arounds has being identified. 


Attachments: Unit test results:
layer draws 5 cards instead of 4

Testing council_room ()
Test 1: player 0 draws 4 cards from deck
FAIL: test = 9, expected = 8
Test 2: 1 buy is added to the state of the game
FAIL: test = 1, expected = 2
Test 3:Each other player in the game draws one card
PASS: test = 1, expected = 1

######Bug Report #4######### 

Title: One buy is not added to the game when player draws the council room card. 

Product: Dominion Game 

Classification: Serious bug which causes the council room card effect to be
incorrect when this card is drawn by a player in the game.

Platform: 
host:  flip 3
LSB Version:	:core-4.1-amd64:core-4.1-noarch:cxx-4.1-amd64:cxx-4.1-noarch:desktop-4.1-amd64:desktop-4.1-noarch:languages-4.1-amd64:languages-4.1-noarch:printing-4.1-amd64:printing-4.1-noarch
Distributor ID:	CentOS
Description:	CentOS Linux release 7.2.1511 (Core) 
Release:	7.2.1511
Codename:	Core
kernel version: Linux 3.10.0-327.10.1.el7.x86_64 x86_6


Can it be reproduced?: Yes it can be reproduced every time a player draws the council room card.

Description:One buy is not added to the game when drawing the council room card. The number of buys in the game remain the same after the player draws the council room card.

What is the error: The is no error message associated with this bug.

Supporting Information: 

Steps to reproduce: Run cardtest3.c

cs362sp16/projects/lozadas/teammate1Dominion/cardtest3.c

1.Initialize Game
2.Draw council room card
3.Count the of buys in the game 

Expected Results: The number of buys in the game is increased by one after the player draws the council room card.
Actual results: he number of buys in the game remain the same after the player draws the council room card.

Workaround: No work arounds has being identified. 


Attachments: Unit test results:
layer draws 5 cards instead of 4

Testing council_room ()
Test 1: player 0 draws 4 cards from deck
FAIL: test = 9, expected = 8
Test 2: 1 buy is added to the state of the game
FAIL: test = 1, expected = 2
Test 3:Each other player in the game draws one card
PASS: test = 1, expected = 1

***********Teammate #2 Ellard Gerritsen van der Hoop ****************
######Bug Report #1######### 

Title:Player draws 2 cards instead of 3 cards when drawing the smithy card.

Product: Dominion Game 

Classification: Serious bug which causes the smithy card effect to be
incorrect when this card is drawn by a player in the game.

Platform: 
host:  flip 3
LSB Version:	:core-4.1-amd64:core-4.1-noarch:cxx-4.1-amd64:cxx-4.1-noarch:desktop-4.1-amd64:desktop-4.1-noarch:languages-4.1-amd64:languages-4.1-noarch:printing-4.1-amd64:printing-4.1-noarch
Distributor ID:	CentOS
Description:	CentOS Linux release 7.2.1511 (Core) 
Release:	7.2.1511
Codename:	Core
kernel version: Linux 3.10.0-327.10.1.el7.x86_64 x86_6


Can it be reproduced?: Yes it can be reproduced every time player draws the smithy card.

Description:Player does not draw three cards when the smithy card is drawn.Player draws 2 cards when the smithy card is drawn. 

What is the error: The is no error message associated with this bug.

Supporting Information: 

Steps to reproduce: Run cardtest1.c

cs362sp16/projects/lozadas/teammate1Dominion/cardtest1.c

1.Initialize Game
2.Draw smithy card
3.Count the number of cards in the player hand.

Expected Results: The expected result is for the player to draw the correct
number of cards ( 3 cards)

Actual results: The Player draws 2 cards. 

Workaround: No work arounds has being identified. 


Attachments: Unit test results:
Testing smithy()
Test 1: player 0 draws the correct number of cards (3 cards)
FAIL: test = 6, expected = 7
Test 1: correct number of cards in player 0 deck (1 card discarded)
PASS: test = 2, expected = 2
Test 2: player 0 draws cards from the correct pile
PASS: test = 2, expected = 2
Test 3: player 1 deck remains unchanged
PASS: test = 10, expected = 10

######Bug Report #2######### 

Title: Player does not draw two treasury cards when drawing adventurer card. 

Product: Dominion Game 

Classification: Serious bug which causes the adventurer cards effect to be
incorrect when this card is drawn by a player in the game.

Platform: 
host:  flip 3
LSB Version:	:core-4.1-amd64:core-4.1-noarch:cxx-4.1-amd64:cxx-4.1-noarch:desktop-4.1-amd64:desktop-4.1-noarch:languages-4.1-amd64:languages-4.1-noarch:printing-4.1-amd64:printing-4.1-noarch
Distributor ID:	CentOS
Description:	CentOS Linux release 7.2.1511 (Core) 
Release:	7.2.1511
Codename:	Core
kernel version: Linux 3.10.0-327.10.1.el7.x86_64 x86_6


Can it be reproduced?: Yes it can be reproduced every time player draws the Adventurer card.

Description:Player does not draw two treasury cards when the smithy card is drawn. Player does not draw two cards.

What is the error: The is no error message associated with this bug.

Supporting Information: 

Steps to reproduce: Run cardtest2.c

cs362sp16/projects/lozadas/teammate1Dominion/cardtest2.c

1.Initialize Game
2.Draw adventurer card
3.Count the number of treasury cards in the player’s hand. 

Expected Results: The expected result is for the player to draw two treasury
cards from the deck

Actual results: The Player does not draw treasury cards from the deck.

Workaround: No work arounds has being identified. 


Attachments: Unit test results:

Testing adventurer()
Test 1: player 0 draws two treasury cards from deck
FAIL: test = 6, expected = 8
Test 2: player 1 deck remains unchanged
FAIL: test = 9, expected = 10
Test 3: discard deck should not have any treasure cads
PASS: test = 0, expected = 0
Testing complete 


######Bug Report #3######### 

Title: Other player hand does not remain unchanged after drawing the adventurer card.

Product: Dominion Game 

Classification: Serious bug which causes the adventurer cards effect to be
incorrect when this card is drawn by a player in the game.

Platform: 
host:  flip 3
LSB Version:	:core-4.1-amd64:core-4.1-noarch:cxx-4.1-amd64:cxx-4.1-noarch:desktop-4.1-amd64:desktop-4.1-noarch:languages-4.1-amd64:languages-4.1-noarch:printing-4.1-amd64:printing-4.1-noarch
Distributor ID:	CentOS
Description:	CentOS Linux release 7.2.1511 (Core) 
Release:	7.2.1511
Codename:	Core
kernel version: Linux 3.10.0-327.10.1.el7.x86_64 x86_6


Can it be reproduced?: Yes it can be reproduced every time player draws the Adventurer card.

Description:Player 2 hand changes after Player 1 draws the adventurer card. 

What is the error: The is no error message associated with this bug.

Supporting Information: 

Steps to reproduce: Run cardtest2.c

cs362sp16/projects/lozadas/teammate1Dominion/cardtest2.c

1.Initialize Game
2.Draw adventurer card
3.Check the number of cards on player 2 hand after player 1 draws adventurer card.
4.Compare number of cards with control game. 

Expected Results: The expected result is for the other player hand to remain unchanged.

Actual results: layer 2 number of cards in hand increases by one. 

Workaround: No work arounds has being identified. 


Attachments: Unit test results:

Testing adventurer()
Test 1: player 0 draws two treasury cards from deck
FAIL: test = 6, expected = 8
Test 2: player 1 deck remains unchanged
FAIL: test = 9, expected = 10
Test 3: discard deck should not have any treasure cads
PASS: test = 0, expected = 0
Testing complete 

