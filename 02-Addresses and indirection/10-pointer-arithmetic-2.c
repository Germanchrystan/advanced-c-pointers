#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COUNT 4

int a[COUNT];
float b[COUNT];
double c[COUNT];
long long int d[COUNT];
short int e[COUNT];
long int f[COUNT];

int main()
{
  int* pa;
  float* pb;
  double* pc;
  long long int* pd;
  short int* pe;
  long int* pf;

  printf("size are: int %d; float %d; double %d; long long int %d; short int %d; long int %d\n",
  sizeof(int),
  sizeof(float),
  sizeof(double),
  sizeof(long long int),
  sizeof(short int),
  sizeof(long int)
  );

  pa = a;
  pb = b;
  pc = c;
  pd = d;
  pe = e;
  pf = f;


  for(int i = 0; i < COUNT; i++)
  {
    a[i] = i;
    b[i] = (float)i;
    c[i] = (double)i;
    d[i] = i;
    e[i] = i;
    f[i] = i;
  }

  // Let's do some arithmetic
  pa += 1;
  pb += 1;
  pc += 1;
  pd += 1;
  pe += 1;
  pf += 1;

  // NOTE: the addresses have been increased by the correct amount: 4 for int, float and long int
  // 8 for double and long long int.
  // 2 for short int
  printf("address of a is %p [%d]; value of pa is %p [%d]; value pointed to by pa is %d\n", a, a, pa, pa, *pa);
  printf("address of b is %p [%d]; value of pb is %p [%d]; value pointed to by pb is %d\n", b, b, pb, pb, *pb);
  printf("address of c is %p [%d]; value of pc is %p [%d]; value pointed to by pc is %d\n", c, c, pc, pc, *pc);
  printf("address of d is %p [%d]; value of pd is %p [%d]; value pointed to by pd is %d\n", d, d, pd, pd, *pd);
  printf("address of e is %p [%d]; value of pe is %p [%d]; value pointed to by pe is %d\n", e, e, pe, pe, *pe);
  printf("address of f is %p [%d]; value of pf is %p [%d]; value pointed to by pf is %d\n", f, f, pf, pf, *pf);
  
  /**
   * The output should be something like this
   * 
   * sizes are: int 4; float 4; double 8; long long int 8; short int 2; long int 4
   * address of a is 00405060 [4214880]; value of pa is 00405064 [4214884]; value pointed to by pa is 1
   * address of b is 00405078 [4214904]; value of pb is 0040507C [4214908]; value pointed to by pb is 1.000000
   * address of c is 004050E0 [4215008]; value of pc is 004050E8 [4215016]; value pointed to by pc is 1.000000
   * address of d is 004050A0 [4214944]; value of pd is 004050A8 [4214952]; value pointed to by pd is 1.000000
   */

  // So this is what I see when I've added one to the pointer variables that's had the effect of moving to
  // the element at the next index of each array.
  
  /**
   * In fact, on some platforms and with some C compilers, the sizes of data types may be different.

    I ran this code just to test it out on my Mac, for instance. And when I did that,
    I noticed that a long int has a size of eight bytes.

    Whereas on my windows pc, the same long int datatype has four bytes.
   */

  return 0;
}
