#include<stdio.h>

#define LENGTH 3

int data[LENGTH];

int main(int argc, char **argv)
{
  int *pi;
  int **ppi;

  printf("multiple indiretion example\n");

  for(int i = 0; i < LENGTH; i++)
  {
    data[i] = i;
  }
  for(int i = 0; i < LENGTH; i++)
  {
    printf("%d\n", data[i]);
  }

  // A: simple pointer to a pointer to an integer
  pi = data;
  ppi = &pi;

  for(int i = 0; i < LENGTH; i++)
  {
    printf("\nLoop[%d] array address is %p\n", i, data);
    printf("item pointed to by pi is %d\n", *pi);
    printf("item pointed to by ppu is %p\n", *ppi);
    printf("item pointed to by double indirection of ppi is %d\n\n", **ppi);
    printf("The address of pi is %p and the value of pi (what it points to) is %p\n\n", &pi, ppi);
    printf("The value of pi is %p and it points to %d\n\n", pi, *pi);
    pi += 1;
  }

  return 0;
}