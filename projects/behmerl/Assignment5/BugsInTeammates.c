/*Lucile Behmer
 * CS 362
 * Assignment 5 
 * Bug Report
 * Teammate 1 is Aaron Sealy
 * Teammate 2 is Mark Dillman
 *
 *
 ****Bug Report 1****
 ***Teammate 1***


 * ID: 01
 * 
 * Location: smithyCard function 
 * How to make bug happen: This function passed my unit tests but it did not 
 * pass the card test. cardtest1.c showed that the incorrect number
 * of cards was drawn. 
 *
 *Reproducable: Yes
 *
 *Estimated Severity: Moderate
 *
 *Estimated Priority: High


 * ID: 02
 *
 *Location: adventurerCard function
 *
 *How to make bug happen: My cardtest.2 caught that drawntreasure was not 
 *incrementing correctly. At first I was not completely sure what went wrong.
 *It led me to look closer at the code and from
 *there I noticed that gold was missing from the if statement to increment 
 *drawntreasure.
 *      
 *Reproducable: Yes
 *     
 *Estimated Severity: Moderate
 *   
 *Estimated Priority: Moderate
 

 ***Teammate2***


 *ID: 03
 *
 *Location: playSmithy function
 *
 *How to make bug happen: The unit test caught a failure in the 
 *Smithy function. I noticed through my unit test that the function 
 *did not finish properly and so I looked at the code and saw a 
 *return statement that messed everything up.
 *
 *Reproducable: Yes
 *
 *Estimated Severity: High
 *
 *Estimated Priority: High
 
 	
 *ID: 04
 *
 *Location: playGreatHall
 *
 *How to make bug happen: None of my tests caught a bug in this 
 *function at first so I had to make a new one. By double checking 
 *all of the new values dealing with handPos I was able to see that
 *the handPos of the current player had been modified where it was 
 *not supposed to.
 *
 *Reproducable: Yes
 *
 *Estimated Severity: High
 *
 *Estimated Priority: High
 */



