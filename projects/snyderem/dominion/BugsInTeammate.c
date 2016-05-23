/******************************************************************************
                           Bugs In Teammates' Code                                                 

GEORGEW

Bug 1: Adventurer
When the treasure card is either silver or gold, the correct cards are not 
removed from the hand, discarded or played:
  Input: one silver or gold card anywhere in the deck or an entire deck full of 
         either silver or gold cards.
  Results:
    -  Hand after is -1 (instead of previous hand + number of treasure cards)
    -  Discard pile now includes all of the deck cards, all of the hand cards 
       and 1 additional card
    -  No treasure cards are found in the hand after playing the adventurer card 
       although there should be.
  This bug is a high priority since it prevents the player from getting the most
  valuable plays for this card.

Bug 2: Adventurer
When the deck has no treasure cards, the number of cards in the hand, the discard 
pile and the played card pile are not correct.
  Input: deck full of cards that are not treasure cards
  Results:
    -  Two cards removed from the hand (none should be removed) and moved to the 
       discard pile.
    -  Entire deck moved to the played card pile (none should be there)
    -  3 treasure cards in the hand after the play, when no treasure cards 
       should have been found
  This bug is a high priority since the playr can end up with 3 treasure cards
  even when there are no treasure cards in the deck, giving them an unfair
  advantage.

BODALJ

Bug1: Adventurer
When there is just one treasure card in the deck (copper, silver or gold) and 
it is in the middle of the deck, the entire deck is not searched.
  Input: one treasure card (copper, silver or gold) in the middle of the deck 
         (position = deck size/2)
  Results: once the treasure card is found, no further cards are removed from 
           the deck.
  This bug is a high priority since it limits the search of the deck to just
  part of the cards.

Bug 2: Council Room
Other players do not draw one extra card
  Input: n/a
  Results: after the card is played all of the other players have the same 
           number of cards in their hand, deck and discard pile.
  This bug is a high priority since a key action taken by this card is not
  implemented.

******************************************************************************/
