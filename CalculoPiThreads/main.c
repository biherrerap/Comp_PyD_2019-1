# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

#define NUM_THREADS 8
#define VALUE 4000000000

double global = 0.0;


void* calPi(void *x)
{
    int tam;
    int ini;
    int end;
    double local = 0.0;

    tam = VALUE/ NUM_THREADS;
    ini = (long)x * tam;
    end = (((long)x + 1) * tam);


    int i;
      for(i = ini; i<end; i++){
        int denom = 2*i+1;

        local += (i%2 ? -1 : 1) * (1.0/denom);

      }

      global += local;
}


int main(void)

{
    pthread_t threads[NUM_THREADS];
    long k;
    int rev;

    //CREATE THREADS DEPENDING ON THE QUANTITY
    for(k = 0; k < NUM_THREADS; k++){
        rev = pthread_create(&threads[k], NULL, calPi, (void *)k);
       if(rev){
            printf("ERROR: return code %d\n", rev);
        }
    }

    // JOIN THREADS
    for(k = 0; k < NUM_THREADS; k++){
        rev = pthread_join(threads[k], NULL);
      if(rev){
        printf("ERROR: return code %d\n", rev);
        exit(-1);
        }
      }

    printf("Pi %f\n", global*4);
    exit(0);

}


