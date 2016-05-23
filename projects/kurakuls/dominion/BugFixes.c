Bug Fixes


From Teammates

Smithy

    Both of my teammates found the issue with Smithy. I introduced a small bug into the for loop count causing
    four cards to be drawn instead of 3.
    - for (i = 0; i < 3; i++)
    + for (i = 0; i <= 3; i++)

    I fixed this in my dominion code

Village
    
    One of my teammates found one of the bugs. He correctly found that there was an extra drawcard call, but heapcheck
    did not catch that the action count only increased by one instead of two.
    
    I fixed both of these bugs in my dominion code.


Adventurer

    One of my teammates found the bug in my adventurer code. I had set the count to be +=2, which meants that adventurer
    would incorrectly stop since it believed two coins had been drawn, but in reality only one coin had been drawn.
    
    I fixed this in my dominion code
    


Teammates Didn't Find:

My bug for the steward card was not found:

  Modified if choice 1 == 2 to assign coin value to 2
  else if (choice1 == 2)
	{
	  //+2 coins
	  - state->coins = state->coins + 2;
	  + state->coins = 2;
	}
  
This bug was if a player chose to increase their coin count by two, it would instead set their coin count to 2.


REFLECTION

Mostly I was surprised about the amount of detail both of my teammates went into with the code. I think they did a half
bug report, half code review. I have done testing before for a software company and we were told that it was best to 
mostly focus on the state changes, expected vs. actual, and let the programmers figure out the cause. But I did think
that after seeing both of my teammates unit tests that mine were severly lacking. I do believe that mine were accurate
and would lead to a programmer finding the correct bug, or at least making them aware there was an issue, but were casting
and incredibly wide net.
I did make it hard for my programmer to guess where the code was not working.

If I had the time to go back, I think I would focus on writing very thorough unit tests. I would try to check all aspects
of the state that could be checked, even if the card wasn't supposed to change that particular aspect. Such as checking
the number of players when you run smithy. It's not supposed to change it, and we should verify.

I definitely think that my unit tests were lacking compared to my teammates. I think part of it was laziness and the other
part was an underestimation of their usefulness. I have worked mostly with manual testing, and not automated. 

Good automated tests, even though they take a long time to set up properly, are well worth it, because as you build things
it's a lot easier to run an automated test, then to have a manual tester go through and verify things.


    