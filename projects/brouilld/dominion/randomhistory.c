

5/8/2016

	Developed random testing framework for inclusion in UnitTestFramework.
	Implemented random testers for 'Adventurer' and 'Village' cards.
	Further abstraction is needed for random testers in this framework,
		however, these tests work in this situation.
	
	In order to implement random testing, I had to add a new 'TestSuite'
	method named 'TestSuiteRandom'. Currently, this supports the addition
	of 5 random properties that the user can implement. Future development
	will hopefully lead to no cap on the randomly tested properties
	(within reason of course).

	The random testing on 'Adventurer' and 'Village' cards exposed the
	same issues the previous unit testing did : the 'Adventurer' has
	incorrect conditionals and 'Village' incorrectly discards.