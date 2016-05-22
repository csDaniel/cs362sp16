/***********************************
* Name: Trent Richardson
* Assignment 5 - BugFixes.c
* CS362-400
***********************************/

The following bugs were found in my code and fixed accordingly:

1.  playSmithy() - the player draws two cards instead of three.  By changing the for loop
            in my code (where the cards are drawn), the bug was corrected.  My teammates
            correctly identified this bug.

2.  playAdventurer() - the player draws three cards instead of two.  By changing the loop
            in my code, the bug was corrected.  My teammates correctly identified this
            bug.

3.  playVillage() - the number of actions was set to 4.  By modifying this and setting
            the number of actions to 2, the bug was corrected.

4.  playCutpurse() -  the incorrect treasure card was being used as a conditional when
            discarding cards.  My code had if == gold, resulting in a bug.  The correct
            card to use is the copper card.  This has been corrected.
