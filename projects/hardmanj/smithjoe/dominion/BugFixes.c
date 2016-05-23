in line 15, file assignment2.c in function smithyAss2, fixed a bug where int i was initialized to 1 instead of 0. This bug
resulting in drawCard being called one less time than was necessary.

In line 29, file assignment2.c, in function adventurerAss2, fixed while(drawntreasure<1) to while(drawntreasure<2). The adventurer
card is supposed to affect two treasures, not one. In this bug the adventurer card was having the wrong effect.

In line 55, file assignment2.c, in function councilroomAss2, fixed i < 3 to i < 4. Councilroom was giving only +3 cards instead of
+4 cards as it should.

In line 84, file assignment2.c, in function feastAss2, fixed i = 1 to i = 0. The hand was not being entirely backed up due to 
i being initialized to the wrong value. 