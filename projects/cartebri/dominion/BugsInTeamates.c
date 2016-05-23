Brianna Carter
Assignment 5 Part 1: Testing teammember code

Team Member 1:
 Bug in Smithy card is that the player only draws 2 cards instead of 3. 
 Using my unit test I was able to find this bug quickly by checking the players 
 hand count and the deck count. 

 My test returned some failed cases right away. I noticed that the hand count 
 that was expected was one greater than what the hand count actually was. The 
 check of the deck count also failed, it showed that the deck had one more card 
 than expected. These two things seem to correlate since all other tests passed.
 So I was able to hypothesize that the player only draws two cards when they should
 draw three.

 To confirm that my hypothesis was correct, I set a watch point on the for loop 
 counter (i) and noticed that the loop only iterated twice. This is because the 
 counter only loops from 1-3 and stops as soon as i is equal to 3. for this code 
 to work properly the loop should say for(i = 0; i < 3; i++) or for(i = 1; i <= 3; i++) 
 or for(i = 1; i < 4; i++). 


 The bug found in Adventurer is that the player draws three treasure cards 
 instead of two..

 The bug took a little bit of modifying to my test in order to be sure I knew what was 
 happening. I saved the hand count of the player before the Adventurer card was played 
 and compared it to the hand count after it was played. There should be a gain of two cards 
 but instead there was a gain of three. To further investigate I watched the players hand and which 
 card was in which position before and after the card was played. After comparing both hands 
 the difference was the addition of three treasure cards at the end of the deck. The 
 expected difference was two treasure cards being added to the end of the deck. 

 To solve the bug I added a watch point to the drawntreasure variable to see how many times 
 the while loop executes. This showed me that it executes 3 times instead of just 2 so the 
 loop should be while(drawntreasure<2) instead of while(drawntreasure<3).

Team member 2:
 Testing Smithy card revealed that the only failing test was that the card itself was not placed 
 in the discarded pile. To further investigate, I ran tests with different situations but saw that 
 the number of cards in the players hand and deck were always correct. I needed investigate further 
 so I examined the types of card that were drawn and didnt notice any specific correlation between the 
 error and a specific card. So tracing what happens programatically to the Smithy card after it 
 is played led me to the discard card function. As soon as I looked at that function, I noticed that the 
 Smithy card was being trashed instead of placed back into the players deck to be drawn again at a later 
 time. This was a tricky bug that took some digging to discover. This really showed that my tests need 
 to look deeper into obscure situations that I may not think about. 

 Testing the Adventurer card showed that when searching for treasusre cards, the function ignores silver.
 This was tricky to discover because my tests werent specifically looking at what treasure cards were 
 disocvered in the deck. During some situations all tests would pass but in others some would fail. This 
 made me wonder if the cards werent being discarded properly so I added watch points to the players deck
 and hand to see that the proper number of cards were flowing. When I saw that everything was in order there, 
 I decided to look more closely at the type of card being drawn from the deck. I specifically wanted to watch 
 for the treasure cards so I stopped whenever the card drawn was equal to 4, 5, or 6 (the numbers in the enum 
 corresponding to the coins). Just after that I watched the drawntreasure variable to be sure it was incremented. 
 These watchpoints showed me that the drawn treasure variable was only increasing when a copper or gold were 
 encountered and not a silver.