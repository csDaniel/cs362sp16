//Unittest Bug Report
/*
	In unittest 4 (whoseTurn) I attempted to see how many players the game could
	handle by changing the var numPlayers in a for loop and running the entire function
	within it. Anytime past 4 players there is a memory leak.

	In unittest3 (numHandCount): After initializing the game I found that I had to refill the
	player's hand after the first loop. Otherwise it wouldn't iterate the count to the next player. The refilling of the hand
	bypassed this.

*/