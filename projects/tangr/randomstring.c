Random Tester:
Identify random characters
32 to 126 are usable characters.
Create a randomizor to pick a character from 32 to 126
126 - 32 = 94
rand() % 94 + 32 <---
Realized an error, 
' ' + (random() % 94) <----


I picked a random length between 0 and 10
Create a new charString on each call.

The test checks for 1 random char

with the initial '!'... realized that the check would not pass because ' ' was not an option.

with initial ' '... it was very difficult to get past the final test. Looking for a specific combination for the first 6 chars is akin to 94^6


How it finds "error"
First, it must generate random characters 
'['
'('
'{'
' '
'a'
'x'
'}'
')'
']'
in that order for variable "c" in that order. Each one represents a state from 0 to 8 pass point.

To pass state 9, a specific string of "reset" followed by '\0' must be generated by a random string. My code did not find the phrase within 1,000,000 iterations done several times.
