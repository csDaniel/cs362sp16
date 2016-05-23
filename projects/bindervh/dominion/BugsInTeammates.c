Bug Reports
Heidi Binder-Vitti
Assignment 5

Ashley Castiglione
adventurer: test failed. An incorrect number of cards are added to the current players hand.  
smithy: test failed. Treasure card is not added to the current player’s hand.
village: test failed. One too many actions added.

Bryan Serif
adventurer: test failed. Cards incorrectly added to the current player’s hand.
smithy: test failed. Incorrect number of cards added to current player’s hand.
village: test failed. One too many cards added to hand, one too few actions added.


All bugs were found using the cardtests I wrote for a previous assignemnt.  The smithy and adventurer tests were 
especially useful because those were cards everyone was required to put into a separate function and introduce 
bugs in.  My village card test also turned out to be useful since both group members had bugs in the village card. 
The unittests I had written were not as useful because they did not test as many things as the individual card tests.
The cardtests included better coverage of the specific cards so it was easier to find errors whereas the unittests 
tested individual functions but did not always test the code where that function was called.