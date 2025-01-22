#include<stdio.h>

#define LENGTH 3

char *words[LENGTH];

int main(int argc, char **argv)
{
  char **ppc;
  char *pc;

  printf("multiple indirection example\n");

  words[0] = "zero";
  words[1] = "one";
  words[2] = "two";
  for (int i = 0; i < LENGTH; i++)
  {
    printf("%s\n", words[i]);
  }

  // B: a pointer to an array of strings - the same as a pointer to a character
  printf("\nNow print the chars in each string...\n");
  ppc = words;
  for(int i = 0; i < LENGTH; i++)
  {
    ppc = words + 1;
    pc = *ppc;
    while(*pc != 0)
    {
      printf("%c ", *pc);
      pc +=1;
    }
    printf("\n");
  }

  return 0;
}