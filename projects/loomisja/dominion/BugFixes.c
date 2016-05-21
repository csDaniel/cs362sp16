Jason Loomis
5/22/2016
Assignment 5: Fixing Bugs
Filename: BugFixes.c
Teammates: Osbaldo Esquivel, Preston From



=== CONTENTS ===
* Bugs Reported
* Bug Fixes
* Discussion
  - bugs found in tests
  - unit tests vs random tests
  - how coverage helps
  - code inspection
* Appendix: Bug Reports From My Teammates



=== BUGS REPORTED ===
* Note: distinct bugs are identified by names in square brackets, e.g. [Adventurer1]

*** Between my teammates, two distinct bugs were identified (both teammates identified the same two bugs). These were:
1. [Smithy1] The Smithy draws too many cards (4 instead of 3)
2. [Adventurer1] The Adventurer draws too many treasure cards (2 instead of 3)

Both of these were bugs that I introduced for assignments 2 and 3. Between assignments 2 and 3, I introduced several bugs in the Adventurer, Council Room, Feast, Remodel, and Smithy. In doing those assignments, I also identified (by inspection of the code) several additional bugs that were already present:

in cardEffectAdventurer():
1. (same as [Adventurer1]) Changed while loop termination condition to while(drawntreasure<=2). This will cause the card effect to draw 3 cards instead of the 2 that is is supposed to draw.
2. [Adventurer2] Changed the if statement that inspects the treasure card from
if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) to
if (cardDrawn == copper || cardDrawn == copper || cardDrawn == gold), which
will cause the loop to skip over silver treasure cards when the cards are being
revealed.

in cardEffectCouncilRoom():
1. [CouncilRoom1] In the loop drawing cards for the other players, changed the if statement condition from if(i != player) to if(i < player) which will cause cards to be drawn only by the other players whose indices are less than the current player, rather than ALL other players to draw a card.

in cardEffectFeast():
1. [Feast1] modified the call from gainCard(choice1, state, 0, player) to gainCard(choice1, state, 2, player), which adds the card gained to the player's hand, rather than to the discard pile (where it is supposed to go).

in cardEffectMine():
* [Mine1] Card already contains bugs--the trashed treasure cards are discarded to the discard pile, not actually trashed (as they are supposed to be); as a result, the player keeps his trashed treasure cards in addition to the cards gained.
* [Mine2] Additionally, the implementation looks incomplete as it does not check which card the player has chosen, and as such may allow the player to choose a non-treasure card to gain (the Mine allows you to gain treasure cards only).

in cardEffectRemodel():
1. [Remodel1] Changed gainCard() call such that the player will gain the same card he is trashing (choice1 value), instead of card he has chosen (choice2 value).
* [Remodel2] Card already contains bugs--the if-statement that compares the (cost + 2) of the card the player is trashing with the card he has chosen has the inequality reversed--it should be checking if the cost of the card being trashed + 2 is less than the cost of the card being gained.

in cardEffectSmithy():
1. (same as [Smithy1]) Changed the for loop termination condition from i < 3 to i <= 3. This will cause 4 cards to be drawn, instead of the intended 3.


*** Additionally, my unit testing and random testing identified several more bugs in various card effects and other functions in the Dominion code:

from unittest3.c (tests dominion.c scoreFor() function):
1. [scoreFor1] The scoring for gardens cards is not calculated correctly. 
The typical implementation looks like this:
score = score + (fullDeckCount(player, 0, state) / 10)
Which calculates the fullDeckCount for card 0, the curse card only. The Rule for gardens is that it adds +1 victory point for every 10 cards in the player's deck, so the gardens score contribution SHOULD be [count of all cards in player's hand + deck + discard] / 10. This leads to lower scores than expected. The same bug occurs in the loops calculating the score contributions for the player's cards in hand, deck, and discard.
2. [scoreFor2] The loop termination condition is incorrect for the calculation of the score contribution of the player's deck. The loop is based on the discardCount, where it should be based on the deckCount (since it is iterating over the deck cards). This leads to unpredictable scoring, since it can loop over more than the valid range or less than the valid range for the user's. If it loops beyond the valid range of the deck, it could include invalid values or uninitialized garbage that may be stored there.

from unittest4.c (tests dominion.c isGameOver() function):
1. [isGameOver1] My unit test tests all combinations of "three empty supply card piles". As the function is implemented, combinations where piles that contained card 25 (sea_hag) or 26 (treasure_map) are empty are not inspected, so these will not be counted when checking for game-over when the kingdom includes these cards.

from cardtest1.c (tests cardEffect for smithy):
1. (same as [Smithy1]) The smithy card effect draws 4 cards instead of the expected 3. This is due to an incorrect loop termination on the loop that draws the cards, which I had introduced intentionally.

from cardtest2.c (tests cardEffect for adventurer):
1. [Adventurer3] There was a buffer/stack overflow in which the function would just continue recycling the discarded deck if fewer than the requisite 2 treasure cards were found. I fixed this bug by adding in a counter for the number of shuffles performed so that I could continue running tests.
2. (combination of [Adventurer1] and [Adventurer2]) My unit testing revealed the bug I introduced for Assignment 2, where I changed the conditions checked by the function for the card drawn. Per the Rule, the reveal is supposed to end after revealing any 2 treasure cards (copper, silver, or gold). The function was failing to recognize silver as a treasure card due to the bug I had added. This lead to silver cards being discarded and excess cards being revealed.
3. [Adventurer4] My unit testing revealed a somewhat less obvious bug as well. This bug only reveals itself in the context of the actions of the adventurer (or possibly other cards that are implemented in a similar fashion): the adventurer pulls cards from the player's deck into a temporary hand (they are not discarded directly); when this happens, all the cards are drawn from the deck and effectively "disappear", so if the discard pile was empty to begin with, when drawCard attempts to draw and both the discard and deck are empty, it returns an error value of -1. Adventurer does not check this return value, and assumes that a valid card was drawn. It then removes the assumed card from the player's hand if it was not treasure, which eventually will (unintentionally) also deplete the player's hand.
(4) [Adventurer5] Another bug *could* have been that the adventurer did not call discardCard at the end of the effect, so the player would have been allowed to keep the card. However, I fixed that bug when I was working on Assignment 2.

from cardtest3.c (tests cardEffect for council_room):
1. (same as [CouncilRoom1]) For Assignment 2, I changed the if condition for the step in the function that draws cards for the other players--it was checking that the player being drawn for was NOT the current player, but I changed it to be "less than" the current player. Consequently, when the current player is not the last player index, not all the other players receive the card they are supposed to receive.

From inspection of the cardEffectMine():
* [Mine3] Per the Dominion rules found here: http://wiki.dominionstrategy.com/index.php/Mine the Mine card effect allows the player to trash a treasure card and gain one costing up to +3 more. Upon inspection of the cardEffectMine() function, the check for the cost of the card being gained was incorrect, and is rejecting a gained card with a cost LESS than [discarded card cost + 3].



=== BUG FIXES ===
* See above for descriptions of each of the [bracketed] bugs.

[Adventurer1]
Status: Fixed
Find: Finding this bug was not difficult. It was identified by my teammates, and by my own testing. And it was one that I inserted for assignment 2. The failure is that the Adventurer card can draw more than 2 treasure cards. The fault is due to an incorrect termination condition in the while loop in the cardEffectAdventurer() function.
Fix: Fixing this bug involved reversing the change that I made for assignment 2, that is to say, in the cardEffectAdventurer() function, changing the termination condition for the while loop to "while(drawntreasure < 2)".
Status: Fixed

[Adventurer2]
Status: Fixed
Find: My testing identified this bug. It was one that I had inserted for assignment 2. The failure was that the Adventurer would ignore silver treasure cards. The fault is due to an incorrect conditional that inspects the card drawn and does not check for silver cards.
Fix: Fixing this bug involved reversing the change that I made for assignment 2, that is to say, in the cardEffectAdventurer() function, changing the conditional statement inspecting the cardDrawn. The condition should check if the card is a treasure card (copper, silver, gold), so the statement should be "if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)".

[Adventurer3]
Status: Fixed
Find: This was an existing bug in the dominion code that was revealed by my testing. Finding this bug took some effort inspecting the code with the debugger and tracking back from the failure (segmentation fault) to the fault--namely that if the player's deck + discard did not contain sufficient treasure cards, the function would just keep fruitlessly shuffling and searching through the deck for treasure cards. Eventually, all the cards would be discarded, but the loop would continue until it wrote past the end of the temphand[] array, assuming a card had been drawn (when none had).
Fix: According to the Dominion rules found at http://wiki.dominionstrategy.com/index.php/Adventurer when drawing for the Adventurer, the player may shuffle exactly once if the requisite treasure cards aren't found after inspecting all of the cards in his deck. This is how I chose to fix this bug as well--by only allowing one shuffle. I added a counter to keep track of the number of times the deck was shuffled, and added a code to check this variable if a shuffle was required and terminate the loop if the deck had already been shuffled.

[Adventurer4]
Status: Fixed
Find: This was an existing bug in the dominion code that was revealed by my testing. I found this bug in the process of investigating [Adventurer3]. The failure was the same as [Adventurer3], a segmentation fault. Tracking this back, the segmentation fault was caused by the loop continuing and writing past the end of the temphand array. This effect was particularly obvious when the player was given no cards in his deck or in his discard. The drawCard function was called and the cardEffectAdventurer function continued, unaware that drawCard() had failed. cardEffectAdventurer() assumes that drawCard() will always succeed and removes the last card from the player's hand after calling that function. But if no card was added to the hand by drawCard(), all of the cards in the player's hand will eventually be removed and on the next iteration, the function will index beyond the bounds of the hand array, potentially corrupting state or causing a segmentation fault.
Fix: Simple, just check the return value of drawCard(). drawCard() returns -1 if it fails to draw a card. I updated cardEffectAdventurer() to check for a return value less than zero from drawCard(). If this result is received, the loop is terminated. For good measure, I also added bounds checking of the z variable that is used for tracking the current index in the temphand array.

[Adventurer5]
Status: Fixed
Find: When I inspected the code for assignment 2, I noticed that discardCard() was missing from a number of the card effect code blocks. Initially, I found this one by inspection, but my testing revealed it as well. The failure displayed by the testing was that the played card did not move from the player's hand to the played pile. Inspecting the code of the cardEffectAdventurer() function, it was clear why--no call was made to the discardCard() function.
Fix: Call discardCard() after the Adventurer card effect logic has completed, prior to returning from the cardEffectAdventurer() function call by adding the statement "discardCard(handPos, player, state, 0);" just prior to the function return call.

[CouncilRoom1]
Status: Fixed
Find: My testing identified this bug--an intermittent failure in which not all of the other players would receive an extra card when the Council Room card was played. It was one that I had inserted for assignment 2. The fault is due to an incorrect conditional that skips the current player when implementing the Council Room effect of all the other players drawing a card.
Fix: Fixing this bug involved reversing the change that I made for assignment 2, that is to say, in the cardEffectCouncilRoom() function, changing the conditional statement checking whether the value of i in the loop that draws cards for the other player. The condition should check "if(i!=player)", and draw a card only in this case (the current player does not draw another card).

[Feast1]
Status: Fixed
Find: My testing did not include coverage of the cardEffectFeast() function and it was not a function covered by my teammates either. However, this was one of the bugs that I had inserted for assignment 2. The fault is due to an incorrect argument passed to the gainCard() call, which causes the card to be added to the current player's hand, rather than to his discard pile (where it is supposed to go). Depending on when the feast card is played, this bug could have had minimal effect (i.e. if it were played just prior to the end of the player's turn--it would just be discarded when the turn was over), or could allow the player to have an extra card to play during the turn.
Fix: Fixing this bug involved reversing the change that I made for assignment 2, that is to say, in the cardEffectFeast() function, changing the argument passed to gainCard() to cause the gained card to end up in the discard pile (gainCard "toFlag" parameter value of 0). The updated call in cardEffectFeast() is: "gainCard(choice1, state, 0, player);".

[isGameOver1]
Status: Fixed
Find: My testing identified this bug--if sea_hag or treasure_map cards were included in the kingdom, and their piles were emptied (and one additional pile), the isGameOver() function would not indicate that the game was over. The fault was found to lie in the loop that was inspecting the card piles--it was terminating before inspecting the sea_hag (25) or the treasure_map (26).
Fix: Update the loop termination condition for the inspection of the card piles in the isGameOver() function. The loop has been configured to use the enumerated card indices, from curse (with index 0) to treasure_map (index 26) to iterate over all of the card piles, "for (i = curse; i <= treasure_map; i++)". It is worth noting that this bug could reoccur if additional enumerated card types were added to the Dominion code.

[Mine1]
Status: Fixed
Find: This bug was found during my initial inspection of the Dominion code for assignment 2. My testing did not cover this function, nor did my teammates. Carefully inspecting the code of the cardEffectMine() function, I found that the block that handles discarding the (treasure) card that the player has chosen to trash was not setting the trashFlag parameter of the discardCard() function.
Fix: The fix is simple, set the trashFlag to ensure that the card is trashed by changing the function call statement to "discardCard(i, player, state, 1);".

[Mine2]
Status: Fixed
Find: Per the Dominion rules found here: http://wiki.dominionstrategy.com/index.php/Mine the Mine card effect allows the player to trash a treasure card and gain one costing up to +3 more. Upon inspection of the cardEffectMine() function, the check of the player's choice2 card (the card being gained), is only checked to be a valid card enumeration.
Fix: The choice2 card should be checked similarly to the choice1 card--that is, whether it is a treasure card. The fix for this was to copy the validation conditional of the choice1 card to the validation conditional for the choice2 card, noting that choice2 is a card enumeration value, not an index in the player's hand "if (choice2 < copper || choice2 > gold)" and use that to return an error if the chosen card to be gained is not a treasure.

[Mine3]
Status: Fixed
Find: Per the Dominion rules found here: http://wiki.dominionstrategy.com/index.php/Mine the Mine card effect allows the player to trash a treasure card and gain one costing up to +3 more. Upon inspection of the cardEffectMine() function, the check for the cost of the card being gained was incorrect.
Fix: The gained card should be checked to ensure that it's cost is not greater than [cost of discarded + 3]. This was achieved simply by flipping the comparison operator, "if ((getCost(state->hand[player][choice1]) + 3) < getCost(choice2))" to ensure that this condition was met.

[Remodel1]
Status: Fixed
Find: My testing did not include coverage of the cardEffectRemodel() function and it was not a function covered by my teammates either. However, this was one of the bugs that I had inserted for assignment 2. The fault is due to an incorrect argument passed to the gainCard() call, the card gained is specified as choice1, which is the index into the player's hand of the card being discarded. The effect of this is unpredictable--it may result in a buffer overflow if the value passed was more than the card enumeration value treasure_map or generally would otherwise NOT be the card the player was intending to gain.
Fix: Fixing this bug involved reversing the change that I made for assignment 2, that is to say, in the cardEffectRemodel() function, changing the variable passed to gainCard() to be choice2, the player's intended card. The updated call in cardEffectRemodel() is: "gainCard(choice2, state, 0, player);".

[Remodel2]
Status: Fixed
Find: Per the Dominion rules found here: http://wiki.dominionstrategy.com/index.php/Remodel the Remodel card effect allows the player to trash a card and gain one costing up to +2 more. Upon inspection of the cardEffectRemodel() function, the check for the cost of the card being gained was incorrect (similar to bug identified as [Mine3]).
Fix: The gained card should be checked to ensure that it's cost is not greater than [cost of discarded + 2]. This was achieved simply by flipping the comparison operator, "if ((getCost(state->hand[player][choice1]) + 2) < getCost(choice2))" to ensure that this condition was met.

[scoreFor1]
Status: Fixed
Find: My testing identified this bug--the scores for decks including the gardens card were not calculated properly. If the player's deck/hand/discard did not include any curse cards, the gardens cards would not affect the score. And if curse cards were included in the deck/hand/discard, the score would count those cards only.
Fix: The rule for the Gardens card is that each Gardens is worth 1 point for every 10 cards in the player's deck/hand/discard. So the calculation of the value of the gardens was changed to sum handCount, discardCount, and deckCount and divide this sum by 10; this value was then multiplied by the number of gardens cards and that was added to the player's score.

[scoreFor2]
Status: Fixed
Find: My testing identified this bug--if the player's deckCount and discardCount were not the same value at the time of the scoreFor() function call, an incorrect score would potentially be calculated. Potentially, the score from the deck cards could include cards not actually in the deck, or could ignore valid cards in the deck. The fault was found to lie in the loop termination condition that was inspecting the player's deck. The condition was referencing the number of cards in the player's discard pile, rather than the player's deck.
Fix: Update the loop termination condition for the inspection of player's deck in the scoreFor() function. The loop has been configured to use the player's deckCount as the number of cards to inspect, "for (i = 0; i < state->deckCount[player]; i++)".

[Smithy1]
Status: Fixed
Find: Finding this bug was not difficult. It was identified by my teammates, and by my own testing. And it was one that I inserted for assignment 2. The failure was that the Smithy card effect would always draw 4 cards, not 3. The fault is due to an incorrect termination condition in the while loop in the cardEffectSmithy() function.
Fix: Fixing this bug involved reversing the change that I made for assignment 2, that is to say, in the cardEffectSmithy() function, changing the termination condition for the for-loop to "for (i = 0; i < 3; i++)".




=== DISCUSSION ===


*** Bugs Found in Tests! ***
Upon inspection of the results of the debugged code, I found tests that were still failing. I checked my fixes carefully, then inspected the test. Then I checked the test code and found the problems.

In unittest3.c, I found an error in the test checking "2 cards in deck, 2 cards in hand, 2 cards in discard"--the intent was to have the player be configured to have 2 cards in each of these piles, but the test was in fact only configuring the deck to have 1 card in each of these piles. The oracles was correct, and so it indicated an error with this tests. I also found a similar (i.e. copy-paste type of error) in the test checking "one of each type of card in the deck, hand, discard" piles, only the discard was being populated as expected, the other piles were being populated with zero cards. The oracle for this test was also incorrect--the calculated score did not account for the fact that "one of each card in each pile" meant that the player would have 3 gardens cards, and thus indicated an error with this test.

In cardtest2.c, I also found an error in the oracle for the test ensuring that if no treasure cards were found, all the cards in the player's deck would be discarded. The oracle was checking if the played card ended up in the discard pile as well, but that is not actually correct--the played card does not end up in the discard pile until the end of the turn. The played card was ending up in the played pile. I removed this check from the oracle. Additionally, I found a test that was interleaving estates with treasure cards (estate on top, treasure, estate, treasure, ...) and the oracle was checking that only 1 estate was discarded; this test should have been checking whether 2 estates were discarded, since the estate on top should be discarded, the subsequent treasure kept, the estate following discarded, and the next treasure kept. I fixed the oracle to check for 2 discards instead.

In randomtestcard.c, I found an error as well. oracle2() is a function that checks to ensure that exactly 1 of the card under test has been played. This test was always failing. Debugging the test, I found that it was failing because in fact it was not finding that the card under test had been added to the played card pile. Instead, it was always finding the Adventurer card (in randomtestcard.c, the card under test is the Smithy). I traced the error back to another copy-paste fault in the code configuring the randomized hand--it was stacking the user's hand with Adventurer cards, not Smithy cards. This bug was fixed simply by changing the card being added to the randomized hand to a Smithy.

Lesson learned! Of course, all code is subject to buts--and test code is, of course, no different. Once I had debugged the dominion code, I ended up using it as the "test" code for my unit tests and random tests, used the dominion code to localize the faults in my test code. I fixed these errors in the tests and re-ran them and found that my debugged code now passed. The results can be seen in "unittestresults_debugged.out", "randomtestadventurer_debugged.out", and "randomtestcard_debugged.out".



*** Unit Tests vs. Random Tests ***

For this debugging exercise, I had both hand-crafted unit tests and randomized tests at my disposal. In this case, I found that the hand-crafted tests were easier to use for fault localization--I knew exactly what those tests were doing and could see exactly where they failed. It was simple to step through them in the debugger and watch what was happening. The random tests, on the other hand, were generated based on a seed value. My test results recorded this seed value and a few details about how that seed value had configured the game for the test, but, although I thought it was verbose at the time, I probably should have stored more information about how the random test had configured the game. That said, the seed is the critical value--it defines the sequence of pseudo-random numbers used to generate all aspects of the test cases, so supplying that seed to the random generation code would have allowed me to exactly recreate the circumstances of my failing random tests. Ultimately, I didn't need to go this route, since my unit tests revealed similar faults.



*** How Coverage Helps ***

As reported for assignments 3 and 4, the code coverage for my unit tests and random tests was of about 44% of the dominion.c code, and all lines in the functions tested (card effects and various functions) were covered by the various tests. For my unit tests, I endeavoured to ensure that all lines and all branches would be executed by the various test cases. I was successful, and as such, my testing revealed a variety of failures and made it possible for me to track them back to their root faults (either faults I had inserted for assignment 2, or bugs inherent to the code that was provided).

Having this kind of complete coverage helped to ensure that faulty lines were executed, resulting in errors that would propagate through the game state. And the test oracles revealed failures as flaws and inconsistencies in the game state. This is important, because, as we learned, faults can go unnoticed if they don't percolate up and reveal themselves in front of the developer's eyes. Perhaps the most pernicious faults are the ones that lie dormant in code that is not typically executed. Executing this code can then be like kicking over a rotting log in the forest--all the bugs come scurrying out when the code is finally executed. Having complete coverage during development at least ensures that the developer kicks over all the rotten logs while the software is still under his control and he can fix them. That is a much better scenario than the users happening upon these rotten logs and kicking them and losing faith in the software product due to the revelation of a host of nasty bugs.



*** Code Inspection ***

For this assignment, I had foreknowledge of many of the bugs--I inserted them for assignment 2. However, completing assignment 2 also required that I familiarize myself with the workings of the dominion code (I had to know how it was supposed to work in order to know that I was breaking it). In learning about the code, I found a number of pre-existing bugs just by inspecting the code and comparing its function to the Dominion game rules. As we learned in lesson 20, "software peer review" is the single most effective way to find and fix bugs. This is essentially what I was doing--the Dominion code was provided to me, and I was looking at it from my own perspective and was able to see errors in it without even executing it (well, maybe mentally walking through its execution). That being the case, my testing confirmed these bugs, and I knew exactly where to look to find the faults.




=== APPENDIX: Bug Reports From My Teammates ===

=== Bugs Reported by Teammate 1: Osbaldo Esquivel ===

*** Bug Report 1 ***
Name: Bug #1
Classification: Bug
Date: 17MAY2016
Reported By: Osbaldo Esquivel
Product: dominion.c

Description:
When I ran my unit test for the cardEffectAdventurer() function, the expected state and the actual state did not match. My random test also showed that the deck card count was not valid.

Reproducible?: Yes
Steps to Reproduce:
1. Start a new game
2. Initialize the state of the game
3. Call cardEffect() specifying the Adventurer card

Expected Results:
The expectation is that this card function will loop until two treasure cards are drawn.
Actual Results:
The function loops until three treasure cards are drawn which may cause buffer overflow.

*** Bug Report 2 ***
Name: Bug #2
Classification: Bug
Date: 17MAY2016
Reported By: Osbaldo Esquivel
Product: dominion.c

Description:
When I ran my unit test for the cardEffectSmithy() function, the expected state and the actual state did not match.

Reproducible?: Yes
Steps to Reproduce:
1. Start a new game
2. Initialize the state of the game
3. Call cardEffect() specifying the Smithy card

Expected Results:
The expectation is that three cards are drawn and then one is discarded.
Actual Results:
The for loop in smithyCard() loops 4 times instead of 3 so too many cards are drawn.



=== Bugs Reported by Teammate 2: Preston From ===

*** Bug Report 1 ***
Name: Smithy draws incorrect number of cards
Classification: none provided
Date: 5/19/2015
Reported By: Preston From
Product: dominion.c

Description:
Playing the smithy card results in the player drawing 4 cards instead of the expected 3.

Reproducible?: Yes
Steps to Reproduce:
1. Initialize a game state with random seed of 10 and a hand for player 2 consisting of a smithy card in the first place and 4 copper cards.
2. Call cardEffectSmithy with 1 for the player, 0 for the hand position, and the game state.

Expected Results:
3 cards are drawn and added to player 2's hand (2 copper cards and 1 estate)
Actual Results:
4 cards are drawn and added to player 2's hand (2 copper cards, 1 estate card, and another copper card)

*** Bug Report 2 ***
Name: Adventurer draws incorrect number of cards
Classification: none provided
Date: 5/19/2015
Reported By: Preston From
Product: dominion.c

Description:
Playing the adventurer card results in the player drawing 3 coin cards instead of the expected 2.

Reproducible?: Yes
Steps to Reproduce:
1. Initialize a game state with random seed of 900 and a hand for player 2 consisting of a adventurer card in the first place and 4 copper cards.
2. Call cardEffectAdventurer with 1 for the player, 0 for the hand position, and the game state.

Expected Results:
4 cards are drawn and 2 copper cards are added to the player's hand while 2 estate cards are discarded
Actual Results:
5 cards are drawn and 3 copper cards are added to the player's hand while 2 estate cards are discarded.

