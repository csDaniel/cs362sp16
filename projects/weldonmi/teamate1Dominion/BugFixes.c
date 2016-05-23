/*

Miranda Weldon
May 22, 2016
CS 362 Spring 2016
BugFixes.c

Smithy Card:
	Bug Fixed: #1 (line 675, variable i not declared)
	Notes: Bug I did not introduce found by teammates Joe Cuellar and James Taylor.
	Old Code: 
	      //+3 Cards
	      for (i = 0; i < 3; i++)
		  drawCard(i, state);
	New Code: 
	      int i;

	      //+3 Cards
	      for (i = 0; i < 3; i++)
	          drawCard(i, state);

Smithy Card:
	Bug Fixed: #2 (line 676, drawCard() being passed i, not currentPlayer)
	Notes: Bug I introduced found by teammates Joe Cuellar and James Taylor.
	Old Code: 
	      int i;

	      //+3 Cards
	      for (i = 0; i < 3; i++)
		  drawCard(i, state);
	New Code: 
	      int i;

	      //+3 Cards
	      for (i = 0; i < 3; i++)
	          drawCard(currentPlayer, state);

Adventurer Card:
	Bug Fixed: #3 (line 664, variable z not incremented) 
	Notes: Bug I introduced found by teammate Joe Cuellar. Teammate James Taylor narrowed possible bug to same region.
	Old Code: 
		else{
		  temphand[z]=cardDrawn;
		  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
		}
	New Code: 
	        else{
	          temphand[z]=cardDrawn;
	          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	          z++;
	        }

Ambassador Card:
	Bug Fixed: #4 (lines 737 - 767, choice1 and choice2 switched)
	Notes: Bug I introduced found by teammate Joe Cuellar.
	Old Code: 
	      if (choice1 > 2 || choice1 < 0)
		  return -1;				

	      if (choice2 == handPos)
		  return -1;

	      for (i = 0; i < state->handCount[currentPlayer]; i++)
		  if (i != handPos && i == state->hand[currentPlayer][choice1] && i != choice2)
		      j++;

	      if (j < choice1)
		  return -1;				

	      if (DEBUG) 
		printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice2]);

	      //increase supply count for choosen card by amount being discarded
	      state->supplyCount[state->hand[currentPlayer][choice2]] += choice1;
			
	      //each other player gains a copy of revealed card
	      for (i = 0; i < state->numPlayers; i++)
		  if (i != currentPlayer)
		      gainCard(state->hand[currentPlayer][choice2], state, 0, i);

	      //discard played card from hand
	      discardCard(handPos, currentPlayer, state, 0);			

	      //trash copies of cards returned to supply
	      for (j = 0; j < choice2; j++)
		  for (i = 0; i < state->handCount[currentPlayer]; i++)
		      if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice2])
			{
			  discardCard(i, currentPlayer, state, 1);
			  break;
			}
	New Code: 
	      if (choice2 > 2 || choice2 < 0)
	          return -1;

	      if (choice1 == handPos)
	          return -1;

	      for (i = 0; i < state->handCount[currentPlayer]; i++)
	          if (i != handPos && i == state->hand[currentPlayer][choice2] && i != choice1)
	              j++;

	      if (j < choice2)
	          return -1;

	      if (DEBUG)
	        printf("Player %d reveals card number: %d\n", currentPlayer, state->hand[currentPlayer][choice1]);

	      //increase supply count for choosen card by amount being discarded
	      state->supplyCount[state->hand[currentPlayer][choice1]] += choice2;

	      //each other player gains a copy of revealed card
	      for (i = 0; i < state->numPlayers; i++)
	          if (i != currentPlayer)
	              gainCard(state->hand[currentPlayer][choice1], state, 0, i);

	      //discard played card from hand
	      discardCard(handPos, currentPlayer, state, 0);

	      //trash copies of cards returned to supply
	      for (j = 0; j < choice1; j++)
	          for (i = 0; i < state->handCount[currentPlayer]; i++)
	              if (state->hand[currentPlayer][i] == state->hand[currentPlayer][choice1])
	                {
	                  discardCard(i, currentPlayer, state, 1);
	                  break;
	                }

Remodel Card:
	Bug Fixed: #5 (line 900, no return statement included)
	Notes: Bug I introduced, was not found and potentially wasn't tested by anyone.
	Old Code: 
	    case remodel:
	      remodelCard(state, currentPlayer, handPos, choice1, choice2);
	New Code: 
	    case remodel:
	      remodelCard(state, currentPlayer, handPos, choice1, choice2);
	      return 0;

Council Room Card:
	Bug Fixed: #6 (lines 694 - 699, (i != currentPlayer checked prematurely)
	Notes: Bug I introduced, was not found and potentially wasn't tested by anyone.
	Old Code: 
	      i = 0;		
	      //Each other player draws a card
	      while(i < state->numPlayers && i != currentPlayer){
		  drawCard(i, state);
		  i++
	      }
	New Code: 
	      //Each other player draws a card
	      for(i = 0; i < state->numPlayers; i++)
	          if(i != currentPlayer)
	                drawCard(i, state);

Final Comments: Having someone else test my code helped greatly, as he found more issues with my function than what just what I had introduced. Using gdb was not very helpful as I was not able to get to dominion.c through it. GDB requires to run an executable file, which there is not directly one for dominion.c; running "gdb playdom" then "run" only gives me access to playdom.c.

Addendum: Console display for GDB session
flip3 ~/CS362/dominion 157% gdb playdom
GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /nfs/stak/students/w/weldonmi/CS362/dominion/playdom...done.
(gdb) run
Starting program: /nfs/stak/students/w/weldonmi/CS362/dominion/playdom
Starting game.

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7751167 in ____strtoll_l_internal () from /lib64/libc.so.6
Missing separate debuginfos, use: debuginfo-install glibc-2.17-106.el7_2.6.x86_64
(gdb) backtrace
#0  0x00007ffff7751167 in ____strtoll_l_internal () from /lib64/libc.so.6
#1  0x00007ffff774db70 in atoi () from /lib64/libc.so.6
#2  0x0000000000401133 in main (argc=1, argv=0x7fffffffe178) at playdom.c:13
(gdb) quit
A debugging session is active.

        Inferior 1 [process 6155] will be killed.

Quit anyway? (y or n) y
flip3 ~/CS362/dominion 158%

*/