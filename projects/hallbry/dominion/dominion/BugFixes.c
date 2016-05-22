
My teammates identified errors in adventurer, smithy and council room.  These were 
3 of the 4 errors that I had introduced where the last refactored card was in steward. 
This card 

The bugs I fixed in my own code were for the adventuerer card and the smithy card.  
For adventurer,  I changed the choices so choice1 and choice2 were now using the not
equal operator. The specific changes I made are outlined below. 


Adventurer
	Was: 
		while (Z+1 >=0) 
	Changed to:
		while(Z-1 >=0) 
		
	
Play Smithy
	Was:
		for (i = 0; i < 6; i++)
	Changed to:
		for (i = 0; i < 3; i++)
	


Play Steward
	
	Was:
		if (choice1 <= 1)
	
	is now:
		if (choice1 == 1)
	
	Was:
		else if (choice1 != 2)
	Changed to:
		else if (choice1 == 2)
			
Play Council Room
	Was:
		for (i = 1; i < 8; i++)
 	Changed to:
		for (i = 0; i < 4; i++)
			

After running my unit tests again