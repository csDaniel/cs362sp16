/*************************************************************************************************************
 * Ben Fisher
 * fisheben@oregonstate.edu
 * file: BugsInTeammates.c
 * Description: This file will document the bugs found in my team-mates
 * dominion.c code.
 *************************************************************************************************************
 *************************************************************************************************************
 Kristen Dhuse
 I found that Kristen had fixed the discardCard function by using the trashCount
 variable.  This required me to update my test cases so that they initialize
 the trashCount varaible when building a test case.

/*************************************************************************************************************
Bugs Found in Kristens code:
  
Title: Bug1 - Discarded cards not being added to discard pile

Class: Serious Bug

Date: 05/19/2016
Reported By: Ben Fisher

Product: dominion.c
Platform: Version: flip3

Is it reproducible: Yes

Description
===========
Discarded card is not properly discarded. discardCount is off.


Steps to Produce/Reproduce
--------------------------
Run unittest3.c


Expected Results
----------------
Discarded card is added to discard deck and discard count is incremented by one


Actual Results
--------------
Discard count is not incremented, card is not added to discard deck.

/************************************************************************************************************
  
Title: Bug2 - Hand count's are not correct after playing smithy card.

Class: Serious Bug

Date: 05/19/2016
Reported By: Ben Fisher

Product: dominion.c
Platform: Version: flip3

Is it reproducible: Yes

Description
===========
Hand counts or decks counts are off


Steps to Produce/Reproduce
--------------------------
Run cardtest1.c


Expected Results
----------------
Hand count is incremented by 3 cards, deck count should not change.


Actual Results
--------------
Hand count is incremented by 4 cards.

/************************************************************************************************************
  
Title: Bug3 - Hand count's are not correct after playing adventurer card.

Class: Serious Bug

Date: 05/19/2016
Reported By: Ben Fisher

Product: dominion.c
Platform: Version: flip3

Is it reproducible: Yes

Description
===========
Hand counts are off


Steps to Produce/Reproduce
--------------------------
Run cardtest2.c


Expected Results
----------------
Hand count is incremented by 1 card(2 cards added and 1 card  ).


Actual Results
--------------
Hand count's are not correct.

/************************************************************************************************************
  
Title: Bug4 - Played card count's are not correct after playing village card.

Class: Serious Bug

Date: 05/19/2016
Reported By: Ben Fisher

Product: dominion.c
Platform: Version: flip3

Is it reproducible: Yes

Description
===========
Hand counts are off


Steps to Produce/Reproduce
--------------------------
Run cardtest3.c


Expected Results
----------------
Played card count is incremented by 1.


Actual Results
--------------
Played card count's are not correct.
	

 
*************************************************************************************************************
*************************************************************************************************************
David Hite
I found that the playVillage function call from the cardEffect function had the arguments in the wrong order
which was causing a seg fault.  I swtiched the handPos and currentPlayer in the call which resolved the seg
fault.  I also found the playSmithy was incrementing the handPos variable in the function which also caused a 
seg fault, removing this resolved the issue.

/*************************************************************************************************************
Bugs Found in David's code:
  
Title: Bug1 - Discarded cards not being added to discard pile

Class: Serious Bug

Date: 05/19/2016
Reported By: Ben Fisher

Product: dominion.c
Platform: Version: flip3

Is it reproducible: Yes

Description
===========
Discarded card is not properly discarded. discardCount is off.


Steps to Produce/Reproduce
--------------------------
Run unittest3.c


Expected Results
----------------
Discarded card is added to discard deck and discard count is incremented by one


Actual Results
--------------
Discard count is not incremented, card is not added to discard deck.

/************************************************************************************************************
  
Title: Bug2 - Hand count's are not correct after playing adventurer card.

Class: Serious Bug

Date: 05/19/2016
Reported By: Ben Fisher

Product: dominion.c
Platform: Version: flip3

Is it reproducible: Yes

Description
===========
Hand counts are off


Steps to Produce/Reproduce
--------------------------
Run cardtest2.c


Expected Results
----------------
Hand count is incremented by 1 card(2 cards added and 1 card  ).


Actual Results
--------------
Hand count's are not correct.

/************************************************************************************************************
  
Title: Bug2 - Num action's count is not correct after playing village card.

Class: Serious Bug

Date: 05/19/2016
Reported By: Ben Fisher

Product: dominion.c
Platform: Version: flip3

Is it reproducible: Yes

Description
===========
Num action count is off


Steps to Produce/Reproduce
--------------------------
Run cardtest3.c


Expected Results
----------------
Num action is incremented by 2.


Actual Results
--------------
Num action is not correct.

/************************************************************************************************************
 