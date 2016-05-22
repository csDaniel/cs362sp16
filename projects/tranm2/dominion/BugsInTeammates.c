# Reported by: tranm2
# CS362 - Spring 2016

#-------------Teammate 1 bugs report

#----- Title: Running series of cardtest1-4.c
* Date: 5/20/2016
* Class: Serious
* Is is reproducible: yes

* Test method: At the begin of the game, for each test, play the tested card and observe the state conditions

* Bug description:
1 - Adventure card failed with "Segmentation fault" error
2 - Smithy failed to take 3 extra cards (got 2 instead). Smithy also failed to discard card itself after playing
3 - Village also failed to discard itself after playing
4 - Council room failed to discard itself after playing

#----- Title: Running randomtestsadventurer.c and andomtestsvillage.c
* Date: 5/20/2016
* Class: Serious
* Is is reproducible: yes

* Test method: At the begin of the game, for each test, play the tested card at random hand position
and random deck and observe the state conditions

* Bug description:
5 - Adventurer card is supposed to take 2 treasure cards from the deck but it
stops at 1 copper card. It also fails to discard card after playing (expected 1 card).
6 - Village card failed to transfer bonus card from deck to hand. Missing discarded card as shown above 


#------------Teammate 2 bugs report

#----- Title: Running series of cardtest1-4.c
* Date: 5/21/2016
* Class: Serious
* Is is reproducible: yes

* Test method: At the begin of the game, for each test, play the tested card and observe the state conditions

* Bug description:
1 - Adventure stopped going through deck before finding treasure cards
2 - Smithy failed to discard itself into discard pile
3 - Village failed to discard itself into discard pile
4 - Council room failed to discard itself into discard pile

#----- Title: Running randomtestsadventurer.c and andomtestsvillage.c
* Date: 5/20/2016
* Class: Serious
* Is is reproducible: yes

* Test method: At the begin of the game, for each test, play the tested card at random hand position
and random deck and observe the state conditions

* Bug description:
- Same bugs found for adventure and village