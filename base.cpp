#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#define true 1 //Necessário apenas para C
#define N_cliente 100 //Quantidade de clientes
volatile int buffer[N_cliente+2],idx=0;
//buffer de comunição cliente -> servidor
volatile int valores_clientes[N_cliente+2],vc=0;
//Dados que seram utilizados para determinar a prioridade do clientes
volatile int retorno[1002],check[1002],v=0;
//Resposta do servidor para o cliente
pthread_mutex_t mutex_zone= PTHREAD_MUTEX_INITIALIZER, mutex_clients=
PTHREAD_MUTEX_INITIALIZER;
pthread_t server,cliente[N_cliente];
void * thread_servidor(void * v){
int resposta[1002],count=0;
resposta[1]=1;
for(int i=2;i<=1000;i++)
resposta[i]=resposta[i-1]+i;
while(true){
if(count==N_cliente) break;
while(idx==0);
pthread_mutex_lock(&mutex_zone);
count++;
int num_cliente=buffer[--idx];
retorno[num_cliente]=resposta[num_cliente];
pthread_mutex_unlock(&mutex_zone);
}
}
void * thread_cliente(void * v){
int valor_cliente;
pthread_mutex_lock(&mutex_clients);
int k=rand()%1000+1;
while(check[k])
k=rand()%1000+1;
check[k]=1;
valores_clientes[vc++]=k;
valor_cliente=k;
pthread_mutex_unlock(&mutex_clients);
pthread_mutex_lock(&mutex_zone);
buffer[idx++]=valor_cliente;
pthread_mutex_unlock(&mutex_zone);
while(retorno[valor_cliente]==0);
printf("%d\n",retorno[valor_cliente]);
//esse printf serve para checar se a exclusão mútua funcionou
}
/*
pthread_create(&var,NULL,funcao,NULL);
pthread_join(var, NULL);
*/
int main(){
srand(time(NULL));
int x;
pthread_create(&server,NULL,thread_servidor,NULL);
for(x=0;x<N_cliente;x++)
pthread_create(&cliente[x],NULL,&thread_cliente,NULL);
pthread_join(server, NULL);
for(x=0;x<N_cliente;x++)
pthread_join(cliente[x], NULL);
}
