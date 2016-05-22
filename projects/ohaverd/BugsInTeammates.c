/* Diana O'Haver
   Assignment 4, part 1
   Report of bugs found in teammates' code

   ##############################################

   Report for STRAMELM:

   Bug Name: adventurer card results in net hand increase of 3 cards
   Bug ID: 1

   Description:
     Playing the adventurer card results in net hand increase of 3 cards,
     when 2 is expected.

   Steps To Reproduce:
     Establish active valid game with known size of user's hand. Pass
     cardEffect adventurer card along with valid game.

   Expected results:
     With initial hand size of 5, expected postHandCount of 7.

   -----------------------------------------------

   Bug Name: adventurer card results in discard increase of 2
   Bug ID: 2

   Description:
     Playing the adventurer card results in discard increase of 2 cards,
     when 1 is expected.

   Steps To Reproduce:
     Establish active valid game with known size of user's hand. Pass
     cardEffect adventurer card along with valid game.

   Expected results:
     With initial discardCount of 0, expected postDiscardCount of 1.

   -----------------------------------------------

   Bug Name: council_room card results in net hand increase of 4 cards
   Bug ID: 3

   Description:
     Playing the council_room card results in net hand increase of 4 cards,
     when 3 is expected, 4 drawn and 1 discarded.

   Steps To Reproduce:
     Establish active valid game with known size of user's hand. Pass
     cardEffect council_room card along with valid game.

   Expected results:
     With initial hand size of 5, expected postHandCount of 8.

   ##############################################

   Report for FAESSLEK:

   Bug Name: smithy card results in net hand increase of 3 cards
   Bug ID: 1

   Description:
     Playing the smithy card results in net hand increase of 3 cards,
     when 2 is expected.

   Steps To Reproduce:
     Establish active valid game with known size of user's hand. Pass
     cardEffect smithy card along with valid game.

   Expected results:
     With initial hand size of 5, expected postHandCount of 7.

   -----------------------------------------------

   Bug Name: council_room card has no net effect on hand size
   Bug ID: 2

   Description:
     Playing the council_room card results in no net effect on hand size,
     when 3 is expected, 4 drawn and 1 discarded.

   Steps To Reproduce:
     Establish active valid game with known size of user's hand. Pass
     cardEffect council_room card along with valid game.

   Expected results:
     With initial hand size of 5, expected postHandCount of 8.

   -----------------------------------------------

   Bug Name: great_hall card results in increase of actions by 3
   Bug ID: 3

   Description:
     Playing the great_hall card results increase of actions by 3,
     when 1 is expected.

   Steps To Reproduce:
     Establish active valid game with known size of user's hand. Pass
     cardEffect great_hall card along with valid game.

   Expected results:
     With initial numActions of 0, expected numActions of 1.

   ##############################################
*/
