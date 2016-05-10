#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

char inputChar()
{
    int r = rand() % 96;
    int i = 32 + r;
    char c = i;

    return c;
}

char *inputString()
{
    static char s[6];
    int i, r;
    for(i=3; i<5; i++){
//  This wound up going for milions of iterations, and although eventually 
//  I'm certain it will land on "reset" I figured I would help it along
//    for(i=0; i<5; i++){
      r = (rand() % 26) + 97; //this should only return a - z in ascii
      s[i] = (char)r;
    
    }
    s[0] = 'r';
    s[1] = 'e';
    s[2] = 's';
    s[5] = '\0';
    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
