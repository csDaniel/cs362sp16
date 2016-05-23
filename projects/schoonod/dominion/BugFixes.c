/*
Dane Schoonover
362
Assignment 5
Date: 17 May 2016
************************************************************************
I fixed all of the original bugs intentionally introduced from the original refactoring assignments. They were as follows:

adventurerCard()
		dominion.c, line 235:   
		
		bug instroduced: 
			while(drawntreasure<3)

		fixed:  	
			while(drawntreasure<2)   


councilRoomCard()
		dominion.c, line 267
		
		bug instroduced: 
			state->numBuys+=5

		fixed:  	
	    	state->numBuys+=1


mineCard()
		domionion.c, line 358
 
		bug instroduced: 
		 	gainCard(choice2, state, 0, currentPlayer);
		
		fixed:  	
	     	gainCard(choice2, state, 2, currentPlayer); 
		

smithyCard()
	    dominion.c, line 382
	
		bug instroduced: 
			for (i = 0; i < 4; i++)

		fixed:  	
	     	for (i = 0; i < 3; i++) 

************************************************************************
The bugs found by my teammates that were not my originally introduced bugs
were the following:

	Teammate Alex Balaba:
	He found the same Smithy card bug that I instroduced. That is, I allowed for one extra card draw.
	This bug has since been fixed.

	Teammate Breet Irvin:
	He found the same Smithy card bug that I introduced.

************************************************************************
Discussion:

Overall, the testing that my teammates did on my code did not find anything new. Although, Brett Irivin seems to have found some anomalies when running his tests that he is uncertain to whether or not they are bugs in the dominion.c code. Perhaps an improvement in this exercise would be to reqiure testing of functions with several state changes involved, that way students would have a higher chance of finding bugs that their teammates did not. 


*/