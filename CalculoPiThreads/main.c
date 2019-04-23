# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <omp.h>

#define NUM_THREADS 4
#define VALUE 4000000000
#define PAD 8

double global = 0.0;


/*
void* calPi(void *x)
{
    int tam;
    int ini;
    int end;
    double local = 0.0;

    tam = VALUE/ NUM_THREADS;
    ini = (long)x * tam;
    end = (((long)x + 1) * tam);


    printf("inicio: %d",ini);
    printf("fin: %d",end);


    int i;
      for(i = ini; i<end; i++){

        int denom = 2*i+1;

        local += (i%2 ? -1 : 1) * (1.0/denom);

      }

      global += local;
}

*/
int main(void)

{

/*
    pthread_t threads[NUM_THREADS];
    long k;
    int rev;
*/
	
    #pragma omp parallel num_threads(NUM_THREADS)
    {
    
    int ID = omp_get_thread_num();
    double sum [NUM_THREADS][PAD];
    int tam;
    int ini;
    int end;
    double local = 0.0;

    tam = VALUE/ NUM_THREADS;
    ini = (long)ID * tam;
    end = (((long)ID + 1) * tam);

    int i;
    int j = 0;
    int k = 0;
      for(i = ini; i<end; i++){
        int denom = 2*i+1;
	if (i%2 == 0){
	  sum[j][k] = 
	  local += 1 * (1.0/denom);
	}else{
	  sum[j][k] = 
          local += -1 * (1.0/denom);
	}
//        local += (i%2 ? -1 : 1) * (1.0/denom);
      }
      global += local;
    }

/*

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

*/

    printf("Pi %f\n", global*4);
    exit(0);

}


