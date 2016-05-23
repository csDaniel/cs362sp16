/*
Dane Schoonover
362
Assignment 5
Date: 17 May 2016
************************************************************************
Product: Brett Irvine's dominion.c file, commit v. 6e1c81b42bd345345c232b1541d3ce35eb2c9a13
Platform: Mac 10.11.4

Description.
-------------------------
Three bugs were found when testing Brett Irvine's dominion.c file.


Steps to produce.
-------------------------
To produce the bugs, I refactored cardtest1 and cardtest2 to function properly with his dominion.c file, and ran a make file using those two cardtests, as well as unittest 1 - 4, and the randomtestadventurer test.


Bugs Found.
-------------------------
1: Smithy card test. Playing the smithy card caused smithCard() test 1 to fail. This means an incorrect player hand count occurs after calling smithCard().

2. scoreFor() test failed. The expected score is 78, but the actual score was 50. This indicates a logic error somewhere in the function.

3. randomtestadventurer.out segfaults upon make. This fault is traced back to line 18 in dominion.c.

************************************************************************
Product: Alex Balaba's dominion.c file, commit v. 51889621491ab0ab1dc8a347baf8851e7747ecf7
Platform: Mac 10.11.4

Description.
-------------------------
1 bug was found when testing Alex Balaba's dominion.c file.


Steps to produce.
-------------------------
To produce the bug, I refactored cardtest1 and cardtest2 to function properly with his dominion.c file, and ran a make file using those two cardtests, as well as unittest 1 - 4, and the randomtestadventurer test.


Bug Found.
-------------------------
1. scoreFor() test failed. The expected score is 78, but the actual score was 50. This indicates a logic error somewhere in the function. This was the same exact failure that Brett Irvine's code failed, indicating that this is an error with the original source code.

************************************************************************
The refactoring needed in order to run my unit tests against their source was not much, meaning the code is very maintainable. In fact it might not have been necessary at all had the original refactoring assignment required all students to use the same function names and parameters.


*/