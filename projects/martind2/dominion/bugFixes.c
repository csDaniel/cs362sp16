/* Bug fixes

In total I fixed fix bugs sprinkled through my code.

Runa and Lauren reported the Smithy bug (drawing too many cards). This
was a simple fix. I changed the 'for' loop for the playSmithy function
(dominion.c:1260) so it's upper limit was reduced to 3.

Lauren additionally reported a discard count bug, however, I'm unsure
of the precise specifications of this function and I am unable to 
refactor or determine if there truely is a bug here. There lies some
confusion among discardCount, playedCards and the discardCard function.
Specifically, when each should be updated and when a test should execute
within the cycle of the game state.

Runa reported bugs in my playAdventurer() and playVillage() functions.
The adventuer function was allowing the hand count to exceed 
expectations. To fix, I simply took out an added statement that
decremented the drawtreasurers variable each time a non-treasure
was drawn.

playVillage() was simply only providing one additional action, rather
than two. I simply changed hard-coded integer within this function.

Bugs not caught included problems in playCouncil_Room and playFeast.
Council Room did not allow the zero'th player to draw a card. This 
fix involved removing a statement within the if clause. Feast 
was not updating coins for the current player after the player
made their choice of card. I simply uncommented a line to update
coins for the player at the start of the function.

*/