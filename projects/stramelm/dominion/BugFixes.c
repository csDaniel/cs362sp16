=================================================
Bug Resolution Report #1
=================================================

Description: adventurer card results in net hand increase of 3 cards
               when 2 is expected 

Reported By: ohaverd

Resolution:

(1) updated while loop to end with correct value for drawntreasure
(2) added handPos to adventurerCardEffect() function signature and added call
    within function to discardCard()
(3) reran tests and verified correct functionality




=================================================
Bug Resolution Report #2
=================================================

Description: adventurer card results in discard increase of 2 cards
               when 1 is expected

Reported By: ohaverd

Resolution:

(1) Bug report has insufficent data to reproduce bug.  Increase in
    discard pile is dependent upon the order and the actual cards drawn.
(2) Modified/expanded my own tests to verify correct discard increase as a function
    of change in hand and deck counts.
(3) reran tests and verified correct functionality




=================================================
Bug Resolution Report #3
=================================================

Description: council room card results in incorrect number of cards
               added to hand of current player

Reported By: faesslek & ohaverd

Resolution:

(1) updated equality test during player loop to add card to other
    players instead of to current player
(2) reran tests and verified correct functionality




=================================================
Bug Resolution Report #4
=================================================

Description: council room card doesn't correctly add one new card
               to the hands of other players

Reported By: faesslek

Resolution:

(1) this is a different resulting problem caused by the same bug
    that was fixed in Bug Resolution Report #3
(2) verified correct functionality




=================================================
Bug Resolution Report #5
=================================================

Description: smithy card results in wrong number of cards in discard pile

Reported By: stramelm

Resolution:

(1) This isn't a problem with the code but instead it's a problem with
    the understanding of the code.  The expectation was that the smithy
    card would immediately be returned to discard, but in reality it
    isn't returned until later when endTurn() is called.  The reason
    for this is that we don't want the card in play being drawn from the
    deck in the event of a shuffle during the current turn.
(2) Verified understanding of requirements, updated test, and reran to 
    verify correct functionality.




=================================================
Bug Resolution Report #6
=================================================

Description: village card results in wrong number of cards in discard pile

Reported By: stramelm

Resolution:

(1) This isn't a problem with the code but instead it's a problem with
    the understanding of the code.  The expectation was that the smithy
    card would immediately be returned to discard, but in reality it
    isn't returned until later when endTurn() is called.  The reason
    for this is that we don't want the card in play being drawn from the
    deck in the event of a shuffle during the current turn.
(2) Verified understanding of requirements, updated test, and reran to 
    verify correct functionality.





=================================================
Bug Resolution Report #7
=================================================

Description: isGameOver() returns incorrect value when treasure_map and/or
             sea_hag are 1 or 2 of the 3 empty non-province cards

Reported By: stramelm

Resolution: 

(1) updated for loop to end on index that includes all element of enum CARD, 
    it was ending early before looking at the last two cards in the list
(2) reran tests and verified correct functionality




=================================================
Bug Resolution Report #8
=================================================

Description: scoreFor() returns incorrect value

Reported By: stramelm

Resolution:

(1) updated deck score loop to use deckCount instead of discardCount
(2) eliminated incorrect usage of call to fullDeckCount() and replaced it
    with ongoing counters for total cards and garden cards
(3) moved garden card scoring outside of hand, discard, and deck scoring
    loops
(4) reran tests and verified correct functionality
