# Bugs Found in Teammates' Code

---

## Emily Snyder (snyderem)

### Relevant Files

    snyderemDominion/unittestresults.out
    snyderemDominion/randomtestadventurer.out
    snyderemDominion/randomtestcard.out

### Synopsis: Bugs Found

*(see actual test for bug documentation)*

1. Bug in discardCard method
2. Bug in Smithy card
3. Bug in Adventurer card
4. Bug in Village card (random test)

### 1. Unit Test: `shuffle`

**Coverage**

  -- gcov for function 'shuffle' in unittest1 --
  Function 'shuffle'
  Lines executed:100.00% of 16
  Branches executed:100.00% of 8
  Taken at least once:100.00% of 8
  Calls executed:100.00% of 2

**Test Results**

All tests passed

### 2. Unit Test: `getCost`

**Coverage**

  -- gcov for function 'getCost' in unittest2 --
  Function 'getCost'
  Lines executed:100.00% of 30
  Branches executed:100.00% of 28
  Taken at least once:100.00% of 28
  No calls

**Test Results**

All tests passed

### 3. Unit Test: `discardCard`

**Coverage**

  -- gcov for function 'discardCard' in unittest3 --
  Function 'discardCard'
  Lines executed:100.00% of 13
  Branches executed:100.00% of 6
  Taken at least once:100.00% of 6
  No calls

**Test Results**

Some tests failed.

* Testing discard non trash card
  * cardPlayedCount should be 1 but was 0
  * playedCardCount should be 1 but was 0
  * discard card not correctly discarding non trash cards
* Testing discard trash card
  * cardDiscardCount should be 1 but was 0
  * discardCount should be 1 but was 0
  * discard card is not correctly discarding a trash card
* Testing discard hand (not trash)
  * Hand is not correctly discarded, there is a major issue with discarding cards


### 4. Unit Test: `whoseTurn`

**Coverage**

  -- gcov for function 'whoseTurn' in unittest4 --
  Function 'whoseTurn'
  Lines executed:100.00% of 2
  No branches
  No calls

**Test Results**

All tests passed.

### 5. Card Test: `smithy`

**Coverage**

  -- gcov for function 'playSmithy' in cardtest1 --
  Function 'smithyEffect'
  Lines executed:100.00% of 5
  Branches executed:100.00% of 2
  Taken at least once:100.00% of 2
  Calls executed:100.00% of 2

**Test Results**

Some tests failed.

* After playing Smithy there is an incorrect number of cards in the player's hand

### 6. Card Test: `adventurer`

**Coverage**

  -- gcov for function 'playAdventurer' in cardtest2 --
  Function 'adventurerEffect'
  Lines executed:100.00% of 17
  Branches executed:100.00% of 10
  Taken at least once:90.00% of 10
  Calls executed:100.00% of 2

Not all paths were taken at least once.  Since we found bugs in the code this is likely a result of
not gaining two treasure cards or the improper discard of the adventurer card.

**Test Results**

Some tests failed.

* Playing adventurer does not gain two treasure cards
* Adventurer card is not discarded


### 7. Card Test: `village`

**Coverage**

  -- gcov for function 'playVillage' in cardtest3 --
  Function 'playVillage'
  Lines executed:100.00% of 3
  No branches
  Calls executed:100.00% of 1

The coverage for this function is slightly meaningless as we are evaluating the coverage of our helper
function which facilitated testing.  

**Test Results**

All tests passed.

### 8. Card Test: `great_hall`

**Coverage**

  -- gcov for function 'playGreatHall' in cardtest4 --
  Function 'playGreatHall'
  Lines executed:100.00% of 3
  No branches
  Calls executed:100.00% of 1

The coverage for this function is slightly meaningless as we are evaluating the coverage of our helper
function which facilitated testing.  

**Test Results**

All tests passed.

### 9. Random Test: `adventurer`

**Coverage**


  -- gcov for function 'adventurerEffect' in randomtestadventurer --
  Function 'adventurerEffect'
  Lines executed:100.00% of 17
  Branches executed:100.00% of 10
  Taken at least once:90.00% of 10
  Calls executed:100.00% of 2

**Test Results**

Some tests failed.

* Bugs are same as those described in the Card Test

### 10. Random Test: `village`

**Coverage**

  -- gcov for function 'playVillage' in randomtestcard --
  Function 'playVillage'
  Lines executed:100.00% of 3
  No branches
  Calls executed:100.00% of 1

**Test Results**

Some tests failed

* The village card was not discarded correctly in some of the tests.  This could be an issue with the discard
function or an issue with the random test itself.

---

## William George (georgew)

### Relevant Files

    georgewDominion/unittestresults.out
    georgewDominion/adv.out
    georgewDominion/randomtestcard.out

### Synopsis: Bugs Found

*(see actual test for bug documentation)*

1. Bug in discardCard method
2. Bug in Smithy card
3. Bug in Adventurer card
4. Bug in Village card (random tests)

### 1. Unit Test: `shuffle`

**Coverage**

  -- gcov for function 'shuffle' in unittest1 --
  Function 'shuffle'
  Lines executed:100.00% of 16
  Branches executed:100.00% of 8
  Taken at least once:100.00% of 8
  Calls executed:100.00% of 2

**Test Results**

All tests passed.

### 2. Unit Test: `getCost`

**Coverage**

  -- gcov for function 'getCost' in unittest2 --
  Function 'getCost'
  Lines executed:100.00% of 30
  Branches executed:100.00% of 28
  Taken at least once:100.00% of 28
  No calls

**Test Results**

All tests passed.

### 3. Unit Test: `discardCard`

**Coverage**

  -- gcov for function 'discardCard' in unittest3 --
  Function 'discardCard'
  Lines executed:100.00% of 13
  Branches executed:100.00% of 6
  Taken at least once:100.00% of 6
  No calls

**Test Results**

Some tests failed.

* Testing discard non trash card
  * cardPlayedCount should be 1 but was 0
  * playedCardCount should be 1 but was 0
  * discard card not correctly discarding non trash cards
* Testing discard trash card
  * cardDiscardCount should be 1 but was 0
  * discardCount should be 1 but was 0
  * discard card is not correctly discarding a trash card
* Testing discard hand (not trash)
  * Hand is not correctly discarded, there is a major issue with discarding cards

### 4. Unit Test: `whoseTurn`

**Coverage**

  -- gcov for function 'whoseTurn' in unittest4 --
  Function 'whoseTurn'
  Lines executed:100.00% of 2
  No branches
  No calls

**Test Results**

All tests passed.

### 5. Card Test: `smithy`

**Coverage**

  -- gcov for function 'playSmithy' in cardtest1 --
  Function 'smithyCard'
  Lines executed:100.00% of 5
  Branches executed:100.00% of 2
  Taken at least once:100.00% of 2
  Calls executed:100.00% of 2

**Test Results**

* Wrong number of cards in hand after playing Smithy

### 6. Card Test: `adventurer`

**Coverage**

  -- gcov for function 'playAdventurer' in cardtest2 --
  Function 'adventurerCard'
  Lines executed:100.00% of 17
  Branches executed:100.00% of 12
  Taken at least once:91.67% of 12
  Calls executed:100.00% of 2

Not all paths were taken at least once. This is likely due to the bugs that were found.

**Test Results**

* Adventurer card not being discarded
* Not gaining correct number of treasure cards in some instances

### 7. Card Test: `village`

**Coverage**
  
  -- gcov for function 'playVillage' in cardtest3 --
  Function 'playVillage'
  Lines executed:100.00% of 3
  No branches
  Calls executed:100.00% of 1

The coverage for this function is slightly meaningless as we are evaluating the coverage of our helper function which facilitated testing.

**Test Results**

All tests passed.

### 8. Card Test: `great_hall`

**Coverage**

  -- gcov for function 'playGreatHall' in cardtest4 --
  Function 'greatHallCard'
  Lines executed:100.00% of 5
  No branches
  Calls executed:100.00% of 2

**Test Results**

All tests passed.

### 9. Random Test: `adventurer`

**Coverage**

Coverage information not available due to a segmentation fault.

**Test Results**

* Adventurer card was not discarded
* Segmentation fault occurred.  Likely an infinite loop or some other issue with previously described bug.

### 10. Random Test: `village`

**Coverage**

  -- gcov for function 'playVillage' in cardtest3 --
  Function 'playVillage'
  Lines executed:100.00% of 3
  No branches
  Calls executed:100.00% of 1

The coverage for this function is slightly meaningless as we are evaluating the coverage of our helper function which facilitated testing.

**Test Results**

Some tests failed

* The village card was not discarded correctly in some of the tests.  This could be an issue with the discard
function or an issue with the random test itself.
