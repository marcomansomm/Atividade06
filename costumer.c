#include <stdio.h>
#include <stdlib.h>
#include <pthreads.h>

typedef struct node{
    char name[20];
    float valor;
    int quantidade;
    struct node *next;
}Node;

typedef struct list{
    int size;
    Node *head;
}List;

Node* createList(){

}

int isEmpty (struct node *head){
	if(head == NULL){
		return 1;
	} else {
		return 0;
	}

}

void func_produtor(void *arg);
void func_consumidor(void *arg);

int main(void){
	int qtd_consumidor=0, qtd_produtor=0;
	printf("Quantos consumidores vão existir?> ");
	scanf("%d", &qtd_consumidor);
	printf("Quantos produtores vão existir?> ");
	scanf("%d", &qtd_produtor);

	thread_t consumidores[qtd_consumidor], produtores[qtd_produtor];

	for(int i = 0; i<qtd_consumidor; i++){
		thread_create(&(consumidor[i]), NULL, func_consumidor, NULL);
	}

	for(int i = 0; i<qtd_produtor; i++){
		thread_create(&(produtor[i]), NULL, func_produtor, NULL);
	}

	for(int i = 0; i<qtd_consumidor; i++){
		thread_join(consumidores[i], NULL);
	}

	for(int i = 0; i<qtd_consumidor; i++){
		thread_join(produtores[i], NULL);
	}

	return 0;
}

void func_consumidor(void *arg){

	return arg;
}

void func_produtor(void *arg){
	
	return arg;
}
