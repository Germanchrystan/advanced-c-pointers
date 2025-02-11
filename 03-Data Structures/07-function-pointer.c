#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*PFI) (int); // Pointer to a function that returns an int;

int square(int a) 
{
  return a * a;
}

int main()
{
  PFI test;
  char input[50];
  int value;
  int result;

  // set the function pointer test to the address of the function square
  test = square;

  printf("enter the number to square...");
  value = atoi(gets(input));
  result = test(value);
  printf("the result is %d\n", result);
  return 0;

}