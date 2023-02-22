#include <stdio.h>
#include <stdlib.h>

int tamanho = 0 ;

int *pilha = NULL;

void Inserir(int num);
int  Remover();

int main(){
	
	int escolha;
	int numero;

	pilha = (int*) calloc( tamanho , sizeof(int) );
	while (escolha!=3){
	
		printf("------------------\n");
		printf("       PILHA      \n");
		printf("------------------\n");
		printf(" 1 - Inserir dado \n");
		printf(" 2 - Remover dado \n");
		printf(" 3 - Sair         \n");
		printf("------------------\n");
		printf(">");
		scanf("%i",&escolha);

		if(escolha==1){
			printf("Digite um numero: ");
			scanf("%i",&numero);
			Inserir(numero);
		}

		else if(escolha==2){
			Remover();
		}

		else{
			free(pilha);
			printf("Adeus :)\n");
			exit(0);
		}
		
		system("pause");
		system("cls");
		
	}
	
	return 0;
}

void Inserir(int num){
	tamanho++;
	pilha = (int*) realloc(pilha,tamanho);
	pilha[tamanho-1]=num;
	printf("Topo da pilha: %i\n", pilha[tamanho-1]);
}

int  Remover(){
	if(tamanho-1<0){
		printf("Error, estouro de pilha");
		exit(0);
	}

	else{
		tamanho--;
		pilha = (int*) realloc(pilha,tamanho);
		printf("Topo da pilha: %i\n", pilha[tamanho-1]);
		return pilha[tamanho-1];
	}
}
