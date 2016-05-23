Bug Fixes RSTINE

Coverage helped here because I realized that there was almost no code coverage at all. Instead of trusting the function calls that my cards were using I took a deep dive into them and was able to fix other bugs. This helped when I was working with the SEA_HAG as well as the adventurer implementation as I was able to have a good idea of the background functions because I had to understand what they were supposed to do completely.

I feel that coverage had no impact overall on the way I debugged the program. I can see how it is nessesary to have good code coverage, as having poor code coverage is similar to having no code coverage. 


Saie:

1) Smithy Bug:

I completely re-wrote the smithy function. I had included a bunch of unnessasary and complicated code. The easiest implementation of this was to call the draw card function 3 times and then discard
the card. After doing this and implementing correctly I was able to pass Saie's test. 

2) Adventurer bug:

After reviewing the test I realized the oracle was wrong. The test incorreclty assumes the first card is not a treasure card. If it is it will count it as such and record an incorrect output. No fix was required to my code as the fault was in the oracle.

Mark:

1) Adventurer Bug:

Fixed a bug in adventurer test oracle. Oracle assigned values to cards and then reset using memcpy. After oracle bug fix the bug stayed in the code. The bug was found in the adventurer card because the discard from the deck was happening twice. Every other card was getting discarded before being seen. This created an error. I was able to fix it by deleting code which decreased the deckcount again.

Other Bugs Fixed:

Fixed bug in sea_hag putting the curse at the top of the deck.

Baron contains logic error that is unfixable and requires code refactor of dominion main. I deleted the offending code to add clarity.

Fixed discard card by correctly adding to discard pile.


