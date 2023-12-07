#include <stdio.h>

struct node {
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree()
{
	struct node* head = malloc(sizeof(struct node));
	struct node* second = malloc(sizeof(struct node));
	struct node* three = malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = three;

	three->data = 3;
	three->next = NULL;
}

void print(struct node* head)
{
	while (head){
		printf("%d", head->data);
		head = head->next;
	}
	printf("\n");
}

void freeMemory(struct node* head)
{
	while (head){
		struct node* next = head->next;
		free(head);
		head = next;
	}
}

int main()
{
	struct node* lista;
	lista = BuildaOneTwoThree();
	print(lista);
	freeMemory(lista);

	return 0;
}

