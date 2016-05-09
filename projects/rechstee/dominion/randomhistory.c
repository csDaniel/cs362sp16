//Process of creating Random Test Cases
/*
	Random Adventurer inputs:
	In my first attempt I went through my first card test which also happened to be dominion. I set up a clone but without
	the asserts and extra variables that were only pertinent to the original file like xtra coins. I did this because I wanted
	it to run the function by itself just to see how it ran. Then I had to run this function in a "while loop" being called in the 
	main by the main function, which contained it. Putting in functions that got the random variables and putting the default "0"
	in them allowed me to test for any memory I may need to pass. I found that with a void function,which I called, testMe(),
	there were no segmentation faults.This is due to the lack of values being called outside of the function with all the 
	variables being declared in the void.

	I was still running into errors though, whenever the program ran into the discarding portion of the adventurer function I 
	ran into another segmentation fault. I then looked at the random tester and included the library "#include<time.h>" and 
	ammended the main to be similar with  "srand(time(NULL))". Now the function displayed my print messages and returned.
	
	The next step I took was setting these random variables. I initially wanted the player to be random but found this caused
	sementation faults. I decided to bypass it for the time being and focused on making the random treasure out of a possibility of 
	500 drawn treasure cards, the defined maximum in the macro in the dominion header file. I did the same for the variable 
	declaring amount of cards drawn. However, I did when being tested in the conditional statements I tested for the outputs.
	My end case is that the drawn treasure is equal to the amount of coins in the game for player 1.
	The amount drawn for the adventurer card and the cards drawn is equal to
	the deckcount of the game when initialized (testG.deckCount[thisPlayer]), which should be 5.

	The function has returned as late as 1095 and early as 261 in my tests.

	In the Random Smithy card I figured out player randomization through rand maxing out at 4. Added it to adventurer but found
	that I still hit  a segmentation fault, just after the last iteration. Error is still at temphand.


	Random Smithy inputs:
	To give myself a solid starting point I worked off of my previous random test program for Adventurer. I changed the 
	random funcitons to just the player and one to account for hand count. Here I set the random parameter for hand pos to 7 and I
	figured out how to randomize the player effectively! 
*/