//Process of Refactoring
/*
	I started by looking over the dominion header and C file. I made a seperate function for adventurer
	but named it "Adventurer". This didn't work as expected. Upon closer examination of the header file
	I noticed the playAdventurer() prototype function. Afterwards I added that to the main source file as 
	my function seperate from the switch statement. Then it was just a matter of looking up how to pass 
	structs and arrays to functions before they all worked.
	
	The errors that I created are a pointer on the function call in playAdventurer() and declaring the iterative
	looping integer "i" in the playSmithy function.
*/