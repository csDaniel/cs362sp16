/*Bugs for Teammate 1: Tatsiana Clifton
Bug #1
Title: Adventurer card is not discarded and remains in hand after it is played
Severity: High
Priority: High
Assigned to: Tatsiana Clifton
Reported by: Christina Nock
Reported on: 5/16/2016
Status: Active
Environment: Linux
Description:
Playing the Adventurer card should result in the Adventurer card leaving the player’s hand and going into the played pile. The actual results were that the Adventurer card is never discarded, it does not go into the played pile after being played and it remains in the hand.
Steps to reproduce:
1)	Navigate to https://github.com/aburasali/cs362sp16/tree/master/projects/nockc/teammate1Dominion/dominion
2)	Run below commands in current directory:
$make clean
$make cardtest2
$./cardtest2
3)	Review test results

Bug #2
Title: Playing Smithy adds four extra cards to player’s hand instead of three
Severity: High
Priority: High
Assigned to: Tatsiana Clifton
Reported by: Christina Nock
Reported on: 5/16/2016
Status: Active
Environment: Linux
Description:
Playing the Smithy card should result in the hand count increasing by 2 (three extra cards minus discarded Smithy) and the deck count decreasing by 3. Actual results after playing Smithy were that hand count was 4(increased by 3 instead of by 2 as expected) and deck count was 1 (decreased by 4 instead of by 3 as expected). This suggests there was an extra card being added to player’s hand (4 instead of 3) as a result of playing Smithy.
Steps to reproduce:
1)	Navigate to https://github.com/aburasali/cs362sp16/tree/master/projects/nockc/teammate1Dominion/dominion
2)	Run below commands in current directory:
$make cardtest1
$./cardtest1
3)	Review test results

Bugs for Teammate 2: Alex Marsh
Bug #1
Title: Adventurer card is not discarded and remains in hand after it is played
Severity: High
Priority: High
Assigned to: Alex Marsh
Reported by: Christina Nock
Reported on: 5/16/2016
Status: Active
Environment: Linux
Description:
Playing the Adventurer card should result in the Adventurer card leaving the player’s hand and going into the played pile. The actual results were that the Adventurer card is never discarded, it does not go into the played pile after being played and it remains in the hand.
Steps to reproduce:
1)	Navigate to https://github.com/aburasali/cs362sp16/tree/master/projects/nockc/teammate2Dominion/dominion 
2)	Run below commands in current directory:
$make clean
$make cardtest2
$./cardtest2
3)	Review test results

Bug #2
Title: Playing Smithy adds four extra cards to player’s hand instead of three
Severity: High
Priority: High
Assigned to: Alex Marsh
Reported by: Christina Nock
Reported on: 5/16/2016
Status: Active
Environment: Linux
Description:
Playing the Smithy card should result in the hand count increasing by 2 (three extra cards minus discarded Smithy) and the deck count decreasing by 3. Actual results after playing Smithy were that hand count was 4(increased by 3 instead of by 2 as expected) and deck count was 1 (decreased by 4 instead of by 3 as expected). This suggests there was an extra card being added to player’s hand (4 instead of 3) as a result of playing Smithy.
Steps to reproduce:
1)	Navigate to https://github.com/aburasali/cs362sp16/tree/master/projects/nockc/teammate2Dominion/dominion
2)	Run below commands in current directory:
$make cardtest1
$./cardtest1
3)	Review test results

*/
