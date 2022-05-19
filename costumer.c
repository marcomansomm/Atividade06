#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int qtd_buffer = 0;
int *buffer;
int limite;

sem_t mutex;

void *func_produtor(void *arg);
void *func_consumidor(void *arg);

int main(void){
	int qtd_consumidor=0, qtd_produtor=0;
	scanf("%d", &qtd_consumidor);
	scanf("%d", &qtd_produtor);
	scanf("%d", &limite);
	scanf("%d", &qtd_buffer);

	buffer = malloc(qtd_buffer * sizeof(int));


	sem_init(&mutex, 0, 1);

	pthread_t consumidores[qtd_consumidor], produtores[qtd_produtor];

	int produtor_id[qtd_produtor], consumidor_id[qtd_consumidor];

	for(int i = 0; i<qtd_consumidor; i++){
		pthread_create(&(consumidores[i]), NULL, func_consumidor, &consumidor_id[i]);
	}

	for(int i = 0; i<qtd_produtor; i++){
		pthread_create(&(produtores[i]), NULL, func_produtor, &produtor_id[i]);
	}

	for(int i = 0; i<qtd_consumidor; i++){
		pthread_join(consumidores[i], NULL);
	}

	for(int i = 0; i<qtd_consumidor; i++){
		pthread_join(produtores[i], NULL);
	}

	return 0;
}

void *func_consumidor(void *id){
	int consumido = 0, j = 0;
	int *id_consumidor = (int*) id;
	// pegar um valor do buffer
	while(1){ // loop infinito para percorrer o buffer
		
		if(buffer[j] == 0){
			sem_wait(&mutex);
			consumido = buffer[j]; // ele vai pegar o numero
			printf("Produtor %d produzindo %d na posição %d\n", *id_consumidor, consumido, j);
			buffer[j] = 0; // e liberar o espaço no buffer
			sem_post(&mutex);
		}

		if(j == limite){
			j = 0;
		}

		j++;
		
	}
}



void *func_produtor(void *id){

	int *id_produtor = (int*) id;
	int produto, i=0, j=0;
	while(1){
		if(i >= limite){
			i = 0;
		} else {
			produto = (2 * i) + 1;	
		}
		
		while(1){
			if(buffer[j] == 0){
				sem_wait(&mutex);
				buffer[j] = produto;
				printf("Produtor %d produzindo %d na posição %d\n", *id_produtor, produto, j);
				sem_post(&mutex);
				break;
			}
			
			if (j == qtd_buffer){
				j = 0;
			}
			
			j++;
		}

		i++;
	}
}