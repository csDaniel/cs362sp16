#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar() {
    // Generate a random number from 20 to 126 (ASCII printable characters)
    char r = (rand() % 107) + 20;
    return r;
}

char *inputString() {
    int i;
    char static string[6];
    for (i = 0; i < 5; i ++) {
      // Generate a random number from 97 to 122 (ASCII printable)
      string[i] = (rand() % 26) + 97;
    }
    string[5] = '\0';

    // char static testing[6] = "reset\0";
    return string;
}

void testme() {
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


int main(int argc, char *argv[]) {
    srand(time(NULL));
    testme();
    return 0;
}