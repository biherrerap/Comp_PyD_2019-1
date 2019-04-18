#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define OPERATIONS 4000000000


double calPi(long x)
{
    double local = 0.0;
    long i;
      for(i = 0; i<=x; i++){
        long denom = 2*i+1;
        local += (i%2 ? -1 : 1) * (1.0/denom);
      }

      return local;

}


int main(void)

{
    double a;
    a = calPi(OPERATIONS);
    printf("Pi %f\n", a*4);
    exit(0);

}
