#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int a; // 4 bytes
  int c; // 4 bytes
  double b; // 8 bytes
  long long int d; // 8 bytes
} MYSTRUCT;

#define COUNT 4

int main()
{
  MYSTRUCT *p, *q;
  void* v;

  printf("size of MYSTRUCT = %d\n", sizeof(MYSTRUCT));

  p = (MYSTRUCT*)calloc(COUNT, sizeof(MYSTRUCT));

  for(int i = 0; i < COUNT; i++)
  {
    p[i].a = i;
    p[i].b = 100000000 + 1;
    p[i].c = i * 20;
    p[i].d = 1241241241 + i;
  }

  q = p;
  printf("[0] values: \na is %d\nb is %f\nc is %d\nd is %lld\n", q->a, q->b, q->c, q->d);
  printf("addresses: \na is %p\nb is %p\nc is %pd is %p\n", &q->a, &q->b, &q->c, &q->d);

  q = p + 3;
  printf("[3] values: \na is %d\nb is %f\nc is %d\nd is %lld\n", q->a, q->b, q->c, q->d);
  printf("addresses: \na is %p\nb is %p\nc is %pd is %p\n", &q->a, &q->b, &q->c, &q->d);

  v = p + 3; // look at the third element of the array of MYSTRUCTs
  printf("struct at index 3\n");
  for(int i = 0; i < sizeof(MYSTRUCT) / sizeof(int); i++)
  {
    printf("v[%d] = %d\n", i, ((int*)v)[i]);
  }
}