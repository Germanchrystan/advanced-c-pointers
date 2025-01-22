#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COUNT 4

int main()
{
  int *p;
  int a[COUNT];
  printf("size of an int is %d\n", sizeof(int));

  for(int i = 0; i < COUNT; i++) a[i] = i;

  p = a;
  printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);
  
  p = p + 1;
  printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

  p = p + 2;
  printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

  // what happens if we go beyong the array end? There is nothing to stop us or warn us...
  p = p + 1;
  printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

  return 0;
}

/**
 * The result will look something like this
 * 
 * size of an 'int' is 4
 * address of a is 0028FF08; value of p is 0028FF08 [2686728]; value pointed to by p is 0
 * address of a is 0028FF08; value of p is 0028FF0C [2686732]; value pointed to by p is 1
 * address of a is 0028FF08; value of p is 0028FF14 [2686740]; value pointed to by p is 3
 * address of a is 0028FF08; value of p is 0028FF18 [2686744]; value pointed to by p is 2686744
 * 
 * It's because C knows that an int takes up four bytes. And so it knows that when I add one to my pointer,
 * what I mean to do is to increase the value of that pointer. That is to increment the address that it stores by,
 * however many bytes are needed to move to the next element of an array.
 * 
 * Pointer arithmetic with fairly complex types such as structs is just as simple as with simple types such as integers.
 * Adding one to the pointer variable moves it to the next element.
 *  That is the second element in my array of structs.
 * The compiler can figure out how many bytes each element in an array occupies.
 * 
 * When I add one, I'm not adding a specific number, certainly not the integer value one to the value of the pointer.
 * I'm telling the pointer to move one complete element along the array and that is how pointer arithmetic
 */