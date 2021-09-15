/*
1)  Crie um programa em C que multiplica todos os elementos de um array por 4 ou por um valor fornecido pelo usuário
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
  Array 
*/
int arr[4] =  {1,2,3,4};
int g = 0; // var controle do index do vetor
/*
  Minha thread onde eu multiplico 4 pelo valor
  do array
*/
void *myThreadFun(void *vargp)
{
  int *myid = (int *)vargp;
  arr[g] *= 4;
  printf("ID: %d, Value: %d\n", *myid, arr[g]);
  g++;
  return NULL;
}

/*
  Main onde é criado as 4 threads 
*/
int main()
{
  int i;
  pthread_t threads[4];
  for(i = 0 ;i < 4 ;i++){
    pthread_create(&(threads[i]), NULL, myThreadFun, (void *)&threads[i]);
  }
  pthread_exit(NULL);
	return 0;
}
