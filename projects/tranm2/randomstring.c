//------------------------
Name: Dat Tran
ONID: tranm2
CS362 - Spring 2016
Random Testing Quiz 2
//-------------------------

inputChar function is rewritten to randomly producing characters in ASCII table, ranging from 'SPACE' (#32) to '}' (125).
The test would run several iterations and increase the state count every time it detect an error character, specified in the list {'{','}','[',']','(',')',' ','a','x'}.
The state count would stop at 9 and the loop would continue forever if it were not reset by inputString() as "reset\0".
So in the inputString function, at recall the same inputChar() to append letter to the random string with random length. 
Only when the random length equals 6, the string would be set to "reset\0", hence stop the main test loop. 
This gives a high chance that state count would reach level 9 before dropping out.
