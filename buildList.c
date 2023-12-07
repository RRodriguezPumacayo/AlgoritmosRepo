#include <stdio.h>
#include <stdlib.h>

// Primero declaramos la estructura nodo
struct node {
	int data;
	struct node* next;
};

// Declaramos la funcion BuildOneTwoThree de tipo node*
struct node* BuildOneTwoThree()
{
	struct node* head = malloc(sizeof(struct node));

	head->data = 1;
	head->next = malloc(sizeof(struct node));

	head->next->data = 2;
	head->next->next = malloc(sizeof(struct node));

	head->next->next->data = 3;
	head->next->next->next = NULL;

	return head;
}

// Imprimir
void print(struct node* head)
{
	while(head){
	  printf("%d ", head->data);
	  head = head->next;
	}
	printf("\n");
}

// Liberar memoria
void freeMemory(struct node* head)
{
	while(head){
		struct node* next = head->next;
		free(head);
		head = next;
	}
}

int main()
{
	struct node* lista;
	lista = BuildOneTwoThree();
	print(lista);
	freeMemory(lista);

	return 0;
}	
