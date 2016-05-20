BugsInTeamMates.c

=== Ben ===
-- myAdventurer() --
Tested in cardtest2.c
My unit test for this method located an error in which the deck had too many
cards after myAdventurer was called, and the discard pile had too few, i.e.
no cards were discarded. 
This was due to a bug in which a statement which was supposed to check cards
types ended up assigning the checked card type to gold. Since gold is a treasure
card, the first card in the deck was returned as gold. The test was set up so
that the first card should be discarded, since it is not a treasure card.

-- mySmithy() -- 
Tested in cardtest1.c
My unit test for this method was unable to catch any bugs. Upon inspecting the
code, I found that Ben had introduced a bug in which the trash flag was set.
I modified my unit test to check for that just to see how it would go, and it
caught the error. It was an error case I hadn't thought of on my own.

=== Kristen ===
-- playAdventurer() --
Tested in cardtest2.c
My unit test did not account for Kristen's addition of the functionality of
removing the adventurer card from the current player's hand.
After adjusting my unit test, I found that there is no checking to make sure 
that the card to be played and discarded is an adventurer card.

-- playSmithy() --
Tested in cardtest1.c
I found that the results of my unit test were not very specific or helpful.
While it did find an error initially, it did not tell what the wrong result
was.
After changing my untit test to show the card counts, it was clear that four
cards had been moved from the deck to the hand instead of three.
On inspecting the code, I found the for loop went 0 <= 3, instead of 0 < 3.

-- playVillage() --
Tested in cardtest3.c
My unit test found that no cards were moved to the played card pile, where
the used Village card should have been moved to the played card pile.
This is because the trash flag in discardCard() should have been set below
1, but it was 1.