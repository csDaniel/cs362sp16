inputChar()

I looked up methods to generate random characters online and found this: 
http://stackoverflow.com/questions/19724346/generate-random-characters-in-c
reference which had the fairly elegant solution of treating a string literal as an array. 
It was easy to set the string literal as a set of lowercase letters, brackets, and a space.


inputString()

I set up a string of 6 characters. The first 5 characters are generated by the inputChar() 
function to create a random string with letters a-z, brackets, and a space. I then add a 
null terminator to the end of the string. I then return that string. The only problem with 
this method is that there is a 1/33^5 probability of getting "reset\0" as a string and exiting the 
loop. For faster testing it would probably be more useful to decrease the character pool instead of 
calling inputChar().