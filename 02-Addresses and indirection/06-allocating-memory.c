#include<stdio.h>
#include<string.h>

#define MAXSTRLEN 100

char * string_function(char *astring)
{
  char* s;
  s = (char*)malloc(MAXSTRLEN);
  s[0] = 0; // Need this to initialize the buffer created by malloc. This creates an empty string
  strcat(s, astring);
  strcat(s, "\n");

  return s;
}

int main(int argc, char **argv)
{
  printf(string_function("Fred"));
  printf(string_function("Gussie Fink-Nottle"));

  return 0;
}

/**
 * Malloc allocates memory on the heap. This is important.
 * The local variables declared inside a function are allocated memory in an are called the stack.
 * When we exit from a function, the variables on the stack are cleaned up.
 * They not longer exist when the function exits.
 * 
 * But the heap is where global data is stored in memory.
 * Data assigned to variables on the heap continues to exist even after we have exited the function in which they were allocated.
 * 
 * 
 * So now I have 100 bytes set aside for my string. Everything works correctly as long
 * as I don't try to create a string that has more than 100 characters.
 * But what if I do need a longer string?
 * 
 * By allocating more memory than I need, I'm wasting memory in a very big program, one that handles large amounts of data.
 * Or conversely, if I'm writing a program for some sort of hardware device that has very small amounts of memory.
 * Wasting memory in this way could be a problem.
 */