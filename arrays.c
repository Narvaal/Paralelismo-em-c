/*
1)  Crie um programa em C que multiplica todos os elementos de um array por 4 ou por um valor fornecido pelo usuário
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g = 0;
int  arr[4] =  {1,2,3,4};

void *myThreadFun(void *vargp)
{
  	int *myid = (int *)vargp;
  	arr[g] *= 4; ++g;
	
	printf("ID: %d, Value: %d\n", *myid, ++g);
  	return NULL;
}

int main()
{
	int i;
	pthread_t tid;

	for (i = 0; i < 4; i++){ 
		pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
 }
  	pthread_exit(NULL);
	return 0;
}
