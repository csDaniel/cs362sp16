/*
	Rosa Tung
	CS 362
	Assignment 5
	BugFixes.c
*/

//From refactor.c
//subtle bugs I introduced:
	/*playAdventurer line 677: commented out break statement*/ fixed
	/*playSmithy line 722: commented out break statement*/ fixed
	/*playVillage line 1090: changed counter to + 4*/ fixed
	playFeast line: left alone
	/*playCouncil_Room line 1110: changed != to ==*/ fixed
	
Bugs Found by Teammates: 

	Kara Franco:
	
	772 ------------------------Card Test 1-----------------------------
	773 
	774 ---Test adventurer()---
	775 Initialize Game...
	776 Testing that adventurer() cardEffect function return value is 0...
	777 PASS
	778 Testing if adventurer() card gave player 2 new treasure cards...
	779 FAIL
	780 current handCount: 8, previous handCount: 5
	781 Testing if adventurer() card removed 2 cards from the deck...
	782 FAIL
	783 current deckCount: 1, previous deckCount: 5
	784 Testing if adventurer() action did not alter victory points...
	785 PASS
	786 ---adventurer() Test Complete---^M

	/*
		Although my function is correct, because of the absence of the break/return statement I introduced,
		more than one card effect is running, thus the incorrect treasure card and handcount values. To fix the 
		bug I added in the appropriate return value.
	*/
	
	972 ------------------------Card Test 2-----------------------------
	973 
	974 ---Test smithy()---
	975 Initialize Game...
	976 Testing that smithy() cardEffect function return value is 0...
	977 PASS
	978 Testing if smithy() card gave player 3 new cards...
	979 FAIL
	980 current handCount: 6, previous handCount: 5
	981 Testing if smithy() card removed 3 cards from the deck...
	982 FAIL
	983 current deckCount: 3, previous deckCount: 5
	984 Testing if smithy() action did not alter victory points...
	985 PASS
	986 ---smithy() Test Complete---
	
	/*
		Although my function is correct, because of the absence of the break/return statement I introduced,
		more than one card effect is running, thus the incorrect treasure card and handcount values. To fix the 
		bug I added in the appropriate return value.
	*/
	
	1172 ------------------------Card Test 3-----------------------------
	1173 
	1174 ---Test village()---
	1175 Initialize Game...
	1176 Testing that village() cardEffect function return value is 0...
	1177 PASS
	1178 Testing if village() card gave player 1 new card...
	1179 FAIL
	1180 current handCount: 5, previous handCount: 5
	1181 Testing if village() card removed 1 card from the deck...
	1182 PASS
	1183 Testing if village() action did not alter victory points...
	1184 PASS
	1185 Testing if village() gave 2 actions...
	1186 PASS
	1187 ---village() Test Complete---
	
	/*
		It appears that my function is not correctly giving cards to players, which I found that the reason 
		this was happening is due to an incorrect counter in addition to the card effect from before that 
		lacked a break. The correction from before as well as a correction of the counter fixed the bug.
	*/
	
	1373 ------------------------Card Test 4-----------------------------
	1374 
	1375 ---Test council_room()---
	1376 Initialize Game...
	1377 Testing that council_room() cardEffect function return value is 0...
	1378 PASS
	1379 Testing if council_room() card gave player 4 new cards...
	1380 FAIL
	1381 current handCount: 8, previous handCount: 5
	1382 Testing if council_room() card removed 4 cards from the deck...
	1383 PASS
	1384 Testing if council_room() action did not alter victory points...
	1385 PASS
	1386 Testing if council_room() action gave an extra buy...
	1387 PASS
	1388 ---council_room() Test Complete---

	/*
		It appears that my function is not correctly giving cards to players, which I found that the reason 
		this was happening is due to an incorrect comparison in an if statement that affects the drawCard 
		portion of this card effect. Changing the comparison fixes the bug. 
	*/

	Sam Nelson:

	/*
		It appears that Sam's tests for all my cards passed, but that's fine since Kara's tests found all my bugs!
	*/



	