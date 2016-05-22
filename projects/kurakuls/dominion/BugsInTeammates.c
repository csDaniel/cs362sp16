// Begin Robert Stine Report

Bug Report
Robert Stine - Dominion Code

Submitter
Saie Kurakula - Kurakuls@oregonstate.edue

5/21/16

All Tests Run on Flip

Bug 1
Tried to Run Smithy Card with cardtest3.c. Ran into infinite loop 3/3 times that I tried to run the unit test.
Finally I had to comment out cardtes3 from from running just so I could finish the rest of the testing.

Severity
Severe. The infinite loop stopped everything else from running.

Steps to Reproduce
Following Commands on the command line:
make all
make unit
make card
make unittestresults.out

Actual Behavior
Infinite loop stopped programming from running

Expected Behavior
Smithy would increase the count by 2



Bug 2
Adventurer adds less than 2 coins before quitting.

Severity
Medium, card functionality is broken, but game can continue

Steps to Reproduce
make all
make unit
make card
make unittestresults.out
search inside of unittestresults.out for phrase "Testing Adventurer"

Actual Behavior
Adventurer stops before two coins are found

Expected Behavior
Adventurer would add two coins into player's hand



// Begin Mark Rushmere Report

Bug Report
Mark Rushmere - Dominion Code

Submitter
Saie Kurakula - Kurakuls@oregonstate.edue

5/21/16

All Tests Run on Flip

Bug 1
Smithy Card changes hand count by more than two.

Severity
Low.

Steps to Reproduce

Following Commands on the command line:
-make all
-make unit
-make card
-make unittestresults.out

Inside of unittestresults.out
-search inside of unittestresults.out for phrase "Testing Smithy"

Actual Behavior
Smithy allows user to get more than two cards

Expected Behavior
Smithy would increase the count by 2


Bug 2
Adventurer doesn't add two coins

Severity
Medium, card functionality is broken, but game can continue

Steps to Reproduce
Following Commands on the command line:
-make all
-make unit
-make card
-make unittestresults.out

Inside of unittestresults.out
-search inside of unittestresults.out for phrase "Testing Adventurer"

Actual Behavior
Adventurer added either more than or less than two coins over several tests.

Expected Behavior
Adventurer would add two coins into player's hand