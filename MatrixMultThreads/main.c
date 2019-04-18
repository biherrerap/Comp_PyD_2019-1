
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

//Programa que multiplica matrices dependiendo del número de hilos ingresados
//1,2,4,8,16 hilos
//16,32,64,128,256,512,1024 tamaño

#define NUM_THREADS 4
#define SIZE 500


int mat_uno[SIZE][SIZE];
int mat_dos[SIZE][SIZE];
int mat_resp[SIZE][SIZE];

void* mmult(void* x)
{
    int tam;
    int ini;
    int end;

    tam = SIZE/ NUM_THREADS;
    ini = (int)x * tam;
    end = (((int)x + 1) * tam);

    int i,j,k;

      for(i = ini; i < end; i++){
            for(k = 0; k < SIZE; k++){
                    for(j = 0; j < SIZE; j++){
                        mat_resp[i][k] += mat_uno[i][j] * mat_dos[j][k];
                }
            }
      }
}


int main(void)
{
    pthread_t threads[NUM_THREADS];
    int w,q,v,u,k,f, l, rev, cont;
    cont = 0;

    for(w = 0; w < SIZE; w++){
        for(q = 0; q < SIZE; q++){
            l = rand();
            f = rand();
            mat_uno[w][q] = l;
            mat_dos[w][q] = f;
            mat_resp[w][q] = 0;
        }
    }
    //CREATE THREADS DEPENDING ON THE QUANTITY
    for(k = 0; k < NUM_THREADS; k++){
        rev = pthread_create(&threads[k], NULL, mmult, (void *)k);
       if(rev){
            printf("ERROR: return code %d\n", rev);
        }
    }

    //JOIN THREADS

     for(k = 0; k < NUM_THREADS; k++){
        rev = pthread_join(threads[k], NULL);
      if(rev){
        printf("ERROR: return code %d\n", rev);
        exit(-1);
        }
      }

    for(u = 0; u < SIZE; u++){
        for(v = 0; v < SIZE; v++){
                printf("%i ", mat_resp[u][v]);
        }
        printf("\n");
    }

    exit(0);
    }


