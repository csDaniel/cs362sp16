//Derek Wong
//5/18/2016
//CS362
~~~Fixes~~~

It was really helpful that my teammates ran there unit test on my file because we all have different unit test suite. We all might be
checking for different things in our unit test so having other people test our code can help detect bugs that we may not find on our
own. 

Smithy Card:
The bug was that when this card is played it goes in the trash instead of going into the played pile. After the for loop to draw 3 cards
the discardCard function is called. When I was debugging I noticed that the trashFlag value is incorrect when passing into that function.
0 represents it going into the played pile and 2 means that it will trashed. I changed it back to the value of 2 so that the Smithy card 
will go into the played pile. 

Council Room Card:
The bug was that the current player is drawing an extra card from their deck when this is played. This results in incorrect deck size
and incorrect hand size. I debug through the first 2 part of the code where drawCard is called 4 times and numBuys is increased by 1. 
Those parts were comepletly fine, but when I look through the code where every other player draws a card, there is no statement preventing
the current player from drawing a card as well. So I added an if statement saying that if you're not the current player you can draw a card.

Village Card:
The bug was that the numAction is increasing incorrectly when this card is played. The first part of the card which is to draw 1 card
is fine. When it is suppose to add +2 numAction it is actually get replaced by numBuy +2.

Old: state->numActions = state->numBuys + 2;
New: state->numActions = state->numActions + 2;

I switched it back to numAction so that is it being added correctly.
