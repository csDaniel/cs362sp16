/*Since both teammates refactored their code differently than I did, I had to make some modification
 * to run the tests against their files. Instead of figuring out what arguments the functions required
 * or whether they returned a int or void, I just changed my test calls to call the cardEffect method. For example,
 * cardEffect(16, 0, 0, 0, &G, handpos, 0); Since the function I was testing was called from there, it worked great
 * and saved me some time and hassle. This may not strictly be the correct thing to do, but since the cardEffect
 * method was just a switch, I though it would be safe to handle it this way. In addition, I could reuse these
 * tests for any future refactoring. For example, one of my cardtest files tested a card that was only in the
 * cardEffect method. If this were to be refactored later, I would have to change anything to test the refactor.



David DeRisi

Smithy Card: All tests failed. Only 5 cards in hand when there should be 7.

Adventurer Card: Tests all crashed when there is only one card in the deck.

Robert Brauer

Smithy Card: All tests failed. Only 5 cards in hand when there should be 7.

Adventurer Card: All test result in the hand count being in the range of -7000. This of course is way off. It should
				always be 6 or fewer.
*/
