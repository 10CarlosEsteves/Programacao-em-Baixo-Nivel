#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

struct Node {
    int value;
    Node* prev; // ponteiro para o nó anterior
    Node* next; // ponteiro para o nó seguinte
};

struct List{
    Node* head; // cabeça da lista
    Node* tail; // cauda da lista
    int size;
};

// Função para criar um novo nó
Node* createNode(int value);

//Função para criar uma nova lista
List* createList();

// Função para adicionar um nó no final da lista
void addToEnd(List* list, int value);

// Função para adicionar um nó no início da lista
void addToBeginning(List* list, int value);

// Função para remover um nó do final da lista
void removeFromEnd(List* list);

// Função para remover um nó do início da lista
void removeFromBeginning(List* list);

void removeAt(List* list, int index){

	Node* removeNode = list->head;
	int listIndex = list->size-1;
	int counter = 0;
	
	if(index > listIndex){
		printf("Error, element out of range\n");
		exit(0);
	}
	
	else if(index == 0){
		removeFromBeginning(list);
	}
	
	else if(index == listIndex){
		removeFromEnd(list);
	}
	
	else{
		
		while(counter!=index){
			counter++;
			removeNode = removeNode->next;
		}
		
		list->size--;
		removeNode->prev->next = removeNode->next;
        removeNode->next->prev = removeNode->prev;
		free(removeNode);		
	}
	
	
	
		
}

// Função para listar um nó da lista
void printNode(List* list, int index);

// Função para listar todos os nós da lista
void printList(List* list);

int main() {

    List* minhaLista = createList();

    addToEnd(minhaLista,100);
    addToEnd(minhaLista,200);
    addToEnd(minhaLista,300);
    addToEnd(minhaLista,400);
    addToEnd(minhaLista,500);

    printf("Minha lista: "); printList(minhaLista);
    printf("Tamanho: %i \n\n", minhaLista->size);
    
    removeAt(minhaLista, 1);
    printf("Minha lista: "); printList(minhaLista);
    printf("Tamanho: %i \n\n", minhaLista->size);
    
    removeAt(minhaLista, 1);
    printf("Minha lista: "); printList(minhaLista);
    printf("Tamanho: %i \n\n", minhaLista->size);
    
    removeAt(minhaLista, 1);
    printf("Minha lista: "); printList(minhaLista);
    printf("Tamanho: %i \n\n", minhaLista->size);
    
	return 0;
}




Node* createNode(int value) {
    Node* newNode = (Node*) calloc(1, sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

List* createList(){
    List* newList = (List*) calloc(1,sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

void addToEnd(List* list, int value) {
    Node* newNode = createNode(value);
    
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } 
    else {
        newNode->prev = list -> tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
    

}

void addToBeginning(List* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } 
    else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}

void removeFromEnd(List* list) {
    if (list->tail == NULL) {
        printf("Lista vazia\n");
        return;
    }
    Node* nodeToRemove = list->tail;
    list->tail = list->tail->prev;
    if (list->tail == NULL) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }
    list->size--;
    free(nodeToRemove);
}

void removeFromBeginning(List* list) {
    if (list->head == NULL) {
        printf("Lista vazia\n");
        return;
    }
    Node* nodeToRemove = list->head;
    list->head = list->head->next;
    if (list->head == NULL) {
        list->tail = NULL;
    } else {
        list->head->prev = NULL;
    }
    list->size--;
    free(nodeToRemove);
}

void printNode(List* list, int index) {
    Node* current = list->head;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("Elemento não encontrado\n");
    } else {
        printf("Elemento na posicao %d: %d\n", index, current->value);
    }
}

void printList(List* list) {
    Node* current = list->head;
    printf("[");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("]\n");
}
