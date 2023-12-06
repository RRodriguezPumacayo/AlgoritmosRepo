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
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

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
