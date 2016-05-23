I run 4 card tests, 4 unittest and 2 random tests against
teammates code. I had to modify the adventurer card test and 
the smithy card test to match teammmates refactored code.
As a result, the number of bugs were found. 

Teammate 1: Bugs were found in the adventurer, smithy and village cards.
Also the bug was found in the scoreFor() function.

Teammate 2: Bugs were found in the adventurer, smithy and village cards.
Also the bug was found in the scoreFor() function.

The following reports were 
send to teammates:

Teammmate 1

Bug #1

Title: The scoreFor() function does not return correct score for discard and deck

Severity: High

Priority: High

Assigned to: Christina Nock

Reported by: Tatsiana Clifton

Reported on: 5/17/2016

Status: Active

Environment: Flip Server (Linux)

Description:
The for loop of counting score for deck is not based on the deck count.
state->discardCount[player] should be state->deckCount[player]

Steps to reproduce:
1) Navigate to

https://github.com/aburasali/cs362sp16/tree/master/projects/cliftota/nockc

2) Run below commands in current directory:

$make clean

$make unittest3

$./unittest3

3) Review test results


Bug #2

Title: The smithy card: the current player does not receive exactly 3 cards

Severity: High

Priority: High

Assigned to: Christina Nock

Reported by: Tatsiana Clifton

Reported on: 5/17/2016

Status: Active

Environment: Flip Server (Linux)

Description: The function should add 3 cards to the player's hand. It adds 5.
for (i = 0; i <= 4; i++) should be for (i = 0; i < 3; i++)

Steps to reproduce:
1) Navigate to

https://github.com/aburasali/cs362sp16/tree/master/projects/cliftota/nockc

2) Run below commands in current directory:

$make clean

$make cardtest1

$./cardttest1

3) Review test results


Bug #3

Title: The adventurer card: play count is not changed

Severity: High

Priority: High

Assigned to: Christina Nock

Reported by: Tatsiana Clifton

Reported on: 5/17/2016

Status: Active

Environment: Flip Server (Linux)

Description: The play count should be increased by 1. The call of the function discardCard should be added to the adventurer card.

Steps to reproduce:
1) Navigate to

https://github.com/aburasali/cs362sp16/tree/master/projects/cliftota/nockc

2) Run below commands in current directory:

$make clean

$make cardtest3

$./cardttest3

3) Review test results


Bug #4

Title: The village card: the number of actions is not increased by 2

Severity: High

Priority: High

Assigned to: Christina Nock

Reported by: Tatsiana Clifton

Reported on: 5/17/2016

Status: Active

Environment: Flip Server (Linux)

Description: The function should add 2 actions. It adds 3.
state->numActions = state->numActions + 3; should be state->numActions = state->numActions + 2;

Steps to reproduce:
1) Navigate to

https://github.com/aburasali/cs362sp16/tree/master/projects/cliftota/nockc

2) Run below commands in current directory:

$make clean

$make cardtest3

$./cardttest3

3) Review test results



Teammate 2

Bug #1

Title: The scoreFor() function does not return correct score for discard and deck

Severity: High

Priority: High

Assigned to: Alex Marsh

Reported by: Tatsiana Clifton

Reported on: 5/17/2016

Status: Active

Environment: Flip Server (Linux)

Description:

The for loop of counting score for deck is not based on the deck count.

state->discardCount[player] should be state->deckCount[player]

Steps to reproduce:

1) Navigate to

https://github.com/aburasali/cs362sp16/tree/master/projects/cliftota/marshal

2) Run below commands in current directory:

$make clean

$make unittest3

$./unittest3

3) Review test results


Bug #2

Title: The smithy card: the current player does not receive exactly 3 cards

Severity: High

Priority: High

Assigned to: Alex Marsh

Reported by: Tatsiana Clifton

Reported on: 5/17/2016

Status: Active

Environment: Flip Server (Linux)

Description: The function should add 3 cards to the player's hand. It adds 4.

for (i = 0; i <= 3; i++) should be for (i = 0; i < 3; i++)

Steps to reproduce:

1) Navigate to

https://github.com/aburasali/cs362sp16/tree/master/projects/cliftota/marshal

2) Run below commands in current directory:

$make clean

$make cardtest1

$./cardttest1

3) Review test results


Bug #3

Title: The adventurer card: play count is not changed

Severity: High

Priority: High

Assigned to: Alex Marsh

Reported by: Tatsiana Clifton

Reported on: 5/17/2016

Status: Active

Environment: Flip Server (Linux)

Description: The play count should be increased by 1. The call of the function discardCard 

should be added to the adventurer card.

Steps to reproduce:

1) Navigate to

https://github.com/aburasali/cs362sp16/tree/master/projects/cliftota/marshal

2) Run below commands in current directory:

$make clean

$make cardtest3

$./cardttest3

3) Review test results


Bug #4

Title: The village card: the player does not receive exact 1 card

Severity: High

Priority: High

Assigned to: Alex Marsh

Reported by: Tatsiana Clifton

Reported on: 5/17/2016

Status: Active

Environment: Flip Server (Linux)

Description: The function should add 1 card to the player's hand. It adds 1.

One drawCard(currentPlayer, state); should be removed.

Steps to reproduce:

1) Navigate to

https://github.com/aburasali/cs362sp16/tree/master/projects/cliftota/marshal

2) Run below commands in current directory:

$make clean

$make cardtest3

$./cardttest3

3) Review test results