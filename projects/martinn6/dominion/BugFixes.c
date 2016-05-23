-------------------------------------------------
TEST #: 1
CARD: Adventurer
-------------------------------------------------
BUG: Testing shows that the player ends up with the same number
	of cards they started with. Also, random testing shows that other players are in the 
	game have values that don't match what they should in their game state variables. Specifically
	in their hand count and deck count.
GDB TEST FOUND:

1) Random test choose player 2. When playAdventurer() was run, player 2 did not recieve any treasure cards.
2) Random test choose player 2; however, when playAdventurer() was run, the currentPlayer = 0.
3) Eventhough player 2 was chosen, player 0 recieved the treasure cards.

To FIX:
1) Assign currentPlayer to whoseTurn().

GDB RUN:

-bash-4.2$ gdb randomtestadventurer
GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /nfs/stak/students/m/martinn6/CS362/dominion/randomtestadventurer...done.
(gdb) breakpoint at playAdventurer
Undefined command: "breakpoint".  Try "help".
(gdb) break playAdventurer
Breakpoint 1 at 0x401b42: file dominion.c, line 11.
(gdb) watch currentPlayer
No symbol "currentPlayer" in current context.
(gdb) watch state->deckCount
No symbol "state" in current context.
(gdb) run
Starting program: /nfs/stak/students/m/martinn6/CS362/dominion/randomtestadventurer
----------------- Testing Card: adventurer ----------------
TEST: +2 treasure cards
Add Adventure Cards to user decks;
Start: Player Turn: 2; handcount: 1; before_deckTreasureCount=3; handpos: 2;

Breakpoint 1, playAdventurer (state=0x7fffffff0db0) at dominion.c:11
11              int drawntreasure = 0;
Missing separate debuginfos, use: debuginfo-install glibc-2.17-106.el7_2.6.x86_64
(gdb) print currentPlayer
$1 = 1965059956
(gdb) print state
$2 = (struct gameState *) 0x7fffffff0db0
(gdb) print state->deckcount
There is no member named deckcount.
(gdb) print state->deckCount
$3 = {5, 13, 3, 3}
(gdb) print drawntreasure
$4 = 32767
(gdb) watch currentPlayer
Hardware watchpoint 2: currentPlayer
(gdb) watch drawntreasure
Hardware watchpoint 3: drawntreasure
(gdb) continue
Continuing.
Hardware watchpoint 2: currentPlayer

Old value = 1965059956
New value = 0
playAdventurer (state=0x7fffffff0db0) at dominion.c:15
15              int z=0; //cards drawn
(gdb) continue
Continuing.
Hardware watchpoint 3: drawntreasure

Old value = 32767
New value = 1
0x0000000000401c50 in playAdventurer (state=0x7fffffff0db0) at dominion.c:26
26                              drawntreasure++;
(gdb) continue
Continuing.
Hardware watchpoint 3: drawntreasure

Old value = 1
New value = 2
0x0000000000401c50 in playAdventurer (state=0x7fffffff0db0) at dominion.c:26
26                              drawntreasure++;
(gdb) continue
Continuing.

Watchpoint 2 deleted because the program has left the block in
which its expression is valid.

Watchpoint 3 deleted because the program has left the block in
which its expression is valid.
0x0000000000401807 in main () at randomtestadventurer.c:119
119                     playAdventurer(&testG);
(gdb) ----------------- Testing Card: adventurer ----------------
Undefined command: "-----------------".  Try "help".
(gdb) TEST: +2 treasure cards
Undefined command: "TEST".  Try "help".
(gdb) Add Adventure Cards to user decks;
Ambiguous command "Add Adventure Cards to user decks;": .
(gdb) Start: Player Turn: 2; handcount: 1; before_deckTreasureCount=3; handpos: 2;
The program being debugged has been started already.
Start it from the beginning? (y or n) (gdb) print currentPlayer
$1 = 1965059956
(gdb) print state
$2 = (struct gameState *) 0x7fffffff0db0
(gdb) print state->deckcount
There is no member named deckcount.
(gdb) print state->deckCount
$3 = {5, 13, 3, 3}
(gdb) print drawntreasure
$4 = 32767
(gdb) watch currentPlayer
Hardware watchpoint 2: currentPlayer
(gdb) watch drawntreasure
Hardware watchpoint 3: drawntreasure
(gdb) continue
Continuing.
Hardware watchpoint 2: currentPlayer

Old value = 1965059956
New value = 0
playAdventurer (state=0x7fffffff0db0) at dominion.c:15
15              int z=0; //cards drawn
(gdb) continue
Continuing.
Hardware watchpoint 3: drawntreasure

Old value = 32767
New value = 1
0x0000000000401c50 in playAdventurer (state=0x7fffffff0db0) at dominion.c:26
Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Please answer y or n.
The program being debugged has been started already.
Start it from the beginning? (y or n) Program not restarted.
(gdb) playAdventurer (state=0x7fffffff0db0) at dominion.c:15
Undefined command: "playAdventurer".  Try "help".
(gdb) 15              int z=0; //cards drawn
Undefined command: "15".  Try "help".
(gdb) (gdb) continue
Undefined command: "".  Try "help".
(gdb) Continuing.
Undefined command: "Continuing".  Try "help".
(gdb) Hardware watchpoint 3: drawntreasure
Undefined command: "Hardware".  Try "help".
(gdb)
Undefined command: "Hardware".  Try "help".
(gdb) Old value = 32767
Undefined command: "Old".  Try "help".
(gdb) New value = 1
Undefined command: "New".  Try "help".
(gdb) 0x0000000000401c50 in playAdventurer (state=0x7fffffff0db0) at dominion.c:26
Undefined command: "0x0000000000401c50".  Try "help".
(gdb) 26                              drawntreasure++;
which its expression is valid.
0x0000000000401807 in main () at randomtestUndefined command: "26".  Try "help".adventurer
.c:119
119                     playAdventurer(&testG);
(gdb)
(gdb) (gdb) continue
Undefined command: "".  Try "help".
(gdb) Continuing.
Undefined command: "Continuing".  Try "help".
(gdb) Hardware watchpoint 3: drawntreasure
Undefined command: "Hardware".  Try "help".
(gdb)
Undefined command: "Hardware".  Try "help".
(gdb) Old value = 1
Undefined command: "Old".  Try "help".
(gdb) New value = 2
Undefined command: "New".  Try "help".
(gdb) 0x0000000000401c50 in playAdventurer (state=0x7fffffff0db0) at dominion.c:26
Undefined command: "0x0000000000401c50".  Try "help".
(gdb) 26                              drawntreasure++;
Undefined command: "26".  Try "help".
(gdb) (gdb) continue
Undefined command: "".  Try "help".
(gdb) Continuing.
Undefined command: "Continuing".  Try "help".
(gdb)
Undefined command: "Continuing".  Try "help".
(gdb) Watchpoint 2 deleted because the program has left the block in
Undefined command: "Watchpoint".  Try "help".
(gdb) which its expression is valid.
Undefined command: "which".  Try "help".
(gdb)
Undefined command: "which".  Try "help".
(gdb) Watchpoint 3 deleted because the program has left the block in
Undefined command: "Watchpoint".  Try "help".
(gdb) which its expression is valid.
Undefined command: "which".  Try "help".
(gdb) 0x0000000000401807 in main () at randomtestadventurer.c:119
Undefined command: "0x0000000000401807".  Try "help".
(gdb) 119                     playAdventurer(&testG);
Undefined command: "119".  Try "help".
(gdb) (gdb)
Undefined command: "".  Try "help".
(gdb) print testG.hand[2]
$5 = {7, 0 <repeats 499 times>}
(gdb) print testG.hand[0]
$6 = {4, 4, 1, 4, 4, 7, 4, 4, 0 <repeats 492 times>}
(gdb)

-------------------------------------------------
TEST #: 2
CARD: Smithy
-------------------------------------------------
BUG: The specifications for Dominion say that the smithy card should give the
	player who delt it three cards. However, testing shows that the player ends up with
	an extra seven cards.
	
GDB TEST FOUND:

1) Random test choose player 1. Card Count before = 1
2) After test, card count = 5 (+4 cards)
3) Running GDB found that drawCard() 4 times instead of 3.

To FIX:
1) Change for loop from <= 3 to < 3.

GDB RUN:


-bash-4.2$ gdb randomtestcard
GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /nfs/stak/students/m/martinn6/CS362/dominion/randomtestcard...done.
(gdb) break playSmithy
Breakpoint 1 at 0x401a04: file dominion.c, line 43.
(gdb) run
Starting program: /nfs/stak/students/m/martinn6/CS362/dominion/randomtestcard
----------------- Testing Card: smithy ----------------
TEST: +3 cards
Add smity Cards to user decks; handcount = 5handcount = 0handcount = 0handcount = 0
Start: Player Turn: 1; handcount: 1; handpos: 2;

Breakpoint 1, playSmithy (state=0x7fffffff0dc0, handPos=2) at dominion.c:43
43              int currentPlayer = whoseTurn(state);
Missing separate debuginfos, use: debuginfo-install glibc-2.17-106.el7_2.6.x86_64
(gdb) watch currentPlayer
Hardware watchpoint 2: currentPlayer
(gdb) watch state->handCount[currentPlayer]
Hardware watchpoint 3: state->handCount[currentPlayer]
(gdb) continue
Continuing.
Hardware watchpoint 2: currentPlayer

Old value = -143323975
New value = 1
Hardware watchpoint 3: state->handCount[currentPlayer]

Old value = <unreadable>
New value = 1
playSmithy (state=0x7fffffff0dc0, handPos=2) at dominion.c:46
46          for (int i = 0; i <= 3; i++)
(gdb) continue
Continuing.
Hardware watchpoint 3: state->handCount[currentPlayer]

Old value = 1
New value = 2
0x0000000000403e03 in drawCard (player=1, state=0x7fffffff0dc0) at dominion.c:702
702         state->handCount[player]++;//Increment hand count
(gdb) continue
Continuing.
Hardware watchpoint 3: state->handCount[currentPlayer]

Old value = 2
New value = 3
0x0000000000403e03 in drawCard (player=1, state=0x7fffffff0dc0) at dominion.c:702
702         state->handCount[player]++;//Increment hand count
(gdb) continue
Continuing.
Hardware watchpoint 3: state->handCount[currentPlayer]

Old value = 3
New value = 4
0x0000000000403e03 in drawCard (player=1, state=0x7fffffff0dc0) at dominion.c:702
702         state->handCount[player]++;//Increment hand count
(gdb) continue
Continuing.
Hardware watchpoint 3: state->handCount[currentPlayer]

Old value = 4
New value = 5
0x0000000000403e03 in drawCard (player=1, state=0x7fffffff0dc0) at dominion.c:702
702         state->handCount[player]++;//Increment hand count
(gdb) continue
Continuing.
Hardware watchpoint 3: state->handCount[currentPlayer]

Old value = 5
New value = 4
0x0000000000406af4 in discardCard (handPos=2, currentPlayer=1, state=0x7fffffff0dc0, trashFlag=0) at dominion.c:1383
1383          state->handCount[currentPlayer]--;
(gdb) continue
Continuing.

Watchpoint 2 deleted because the program has left the block in
which its expression is valid.

Watchpoint 3 deleted because the program has left the block in
which its expression is valid.
0x00000000004015be in main () at randomtestcard.c:95
95                      playSmithy(&testG2, handpos);
(gdb)



-------------------------------------------------
TEST #: 3
CARD: Village
-------------------------------------------------
BUG: Card count is one more then it should be after play.
	 hand count before=6; hand count after=7; expected=6 FAILED
	
GDB TEST FOUND:
1) drawCard was ran adding card to hand
2) 2 actions were added.
3) Village was not discarded.


To FIX:
1) Call discard function.

GDB RUN:

-bash-4.2$ gdb randomtestvillage
GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /nfs/stak/students/m/martinn6/CS362/dominion/randomtestvillage...done.
(gdb) break playVillage
Breakpoint 1 at 0x401abd: file dominion.c, line 58.
(gdb) run
Starting program: /nfs/stak/students/m/martinn6/CS362/dominion/randomtestvillage
----------------- Testing Card: village ----------------
TEST: +1 cards & 2 actions
Add village Cards to user decks; handcount = 5handcount = 0handcount = 0handcount = 0
Start: Player Turn: 1; handcount: 1; handpos: 2;

Breakpoint 1, playVillage (state=0x7fffffff0dc0, handPos=2) at dominion.c:58
58              int currentPlayer = whoseTurn(state);
Missing separate debuginfos, use: debuginfo-install glibc-2.17-106.el7_2.6.x86_64
(gdb) watch state->handCount
Hardware watchpoint 2: state->handCount
(gdb) continue
Continuing.
Hardware watchpoint 2: state->handCount

Old value = {6, 1, 1, 1}
New value = {6, 2, 1, 1}
0x0000000000403e03 in drawCard (player=1, state=0x7fffffff0dc0) at dominion.c:702
702         state->handCount[player]++;//Increment hand count
(gdb) continue
Continuing.

Watchpoint 2 deleted because the program has left the block in
which its expression is valid.
0x00000000004015be in main () at randomtestvillage.c:95
95                      playVillage(&testG2, handpos);
(gdb) print testG2.handCount
$1 = {6, 2, 1, 1}
(gdb)


-------------------------------------------------
TEST #: 4
CARD: Feast
-------------------------------------------------
BUG: Chosen card is not added to the player's hand.
	
GDB TEST FOUND:
1) playFeast was ran.
2) state->coins was updated to 5.
3) set breakPoint on supplyCount; however, program never broke.
   This means supplyCount was never ran.

To FIX:
1) Make sure that while loop is running. Since while loops runs while x==1,
	update int x = 1 instead of int x = 0.

GDB RUN:

-bash-4.2$ gdb randomtestfeast
GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /nfs/stak/students/m/martinn6/CS362/dominion/randomtestfeast...done.
(gdb) break playFeast
Breakpoint 1 at 0x401b22: file dominion.c, line 70.
(gdb) watch state->coins
No symbol "state" in current context.
(gdb) run
Starting program: /nfs/stak/students/m/martinn6/CS362/dominion/randomtestfeast
----------------- Testing Card: feast ----------------
TEST: +1 cards chosen
Add village Cards to user decks; handcount = 5handcount = 0handcount = 0handcount = 0
Start: Player Turn: 1; handcount: 1; handpos: 2;

Breakpoint 1, playFeast (state=0x7fffffff0dc0, choice1=11) at dominion.c:70
70              int currentPlayer = whoseTurn(state);
Missing separate debuginfos, use: debuginfo-install glibc-2.17-106.el7_2.6.x86_64
(gdb) watch state->coins
Hardware watchpoint 2: state->coins
(gdb) print state->coins
$1 = 4
(gdb) break supplyCount
Breakpoint 3 at 0x402c84: file dominion.c, line 446.
(gdb) continue
Continuing.
Hardware watchpoint 2: state->coins

Old value = 4
New value = 0
updateCoins (player=1, state=0x7fffffff0dc0, bonus=5) at dominion.c:1434
1434      for (i = 0; i < state->handCount[player]; i++)
(gdb) continue
Continuing.
Hardware watchpoint 2: state->coins

Old value = 0
New value = 5
updateCoins (player=1, state=0x7fffffff0dc0, bonus=5) at dominion.c:1453
1453      return 0;
(gdb) continue
Continuing.

Watchpoint 2 deleted because the program has left the block in
which its expression is valid.
0x0000000000401597 in main () at randomtestfeast.c:89
89                      playFeast(&testG2, mine);
(gdb)










