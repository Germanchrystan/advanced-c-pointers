#include<stdio.h>
#include<string.h>

int main()
{
  char* s;
  int i;
  int* p;

  // use malloc first to alloate some memory and see what it is in it (usually rubbish)
  s = (char*) malloc(6);
  for(i = 0; i < 6; i++) printf("s[%d] = %d\n", i, s[i]);
  free(s);
  printf("\n");

  // now we will use calloc to do the same. Note that the memory is 'zeroed out'
  // The syntax of calloc is different for malloc. The second argument gives the size in memory of each element.
  s = (char*)calloc(6, sizeof(char));
  for(i = 0; i < 6; i++) printf("s[%d] = %d\n", i, s[i]);
  free(s);
  printf("\n");
  

  return 0;
}