/*Lucile Behmer
 * CS362
 * Assignment 4
 *
 *
 * 
 *****NOTES about my compilation of make! If you run: 
 *****make randomtestcard.out it will make both of the out
 *****files,randomtestcard.out and randomtestadventurer.out
 *****files for you! Thank you!
 *
 *
 * For the first random test I tested the Smithy card.
 * I used a random number generator and for loop so that I 
 * could go over a large amount of tests. In particular I
 * tested a random numer of cards that the player would have.
 * I saw that this was very efficient in picking up the 
 * bug that I introduced for this card. 
 * This test shows that there is sometime very wrong
 * with, in particular, the logic of the code because none of the 
 * tests would pass. I also found that the coverage was higher 
 * than the unit test as well.
 *
 *For my second random test I focused on the Adventurer card.
 *I was able to really cover a lot more coverage with this one
 *and I felt like with the combination of this and the unit test 
 *it was highly effective in fining bugs. It also found the bug that 
 *I introduced. In particular,I tested the number of cards for the user.
 *This allowed me to see if the program would stumble if say a user 
 *has a very high or low numer of cards. I was hoping that if
 *the number was close to the max of 500 that I would find a bug that
 *I did not introduce but that was not the case.
 */
