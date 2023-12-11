#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node* next;
};

struct node *BuildOneTwoThree(){
	struct node* head = NULL;

	head = (struct node *)malloc(sizeof(struct node));

	head->data = 5;
	head->next = (struct node *)malloc(sizeof(struct node));

	head->next->data = 6;
	head->next->next = NULL;

	return head;
}

int length(struct node* head)
{
	struct node* current = head;
	int count = 0;
	while (current){
	   count++;
	   current = current->next;
	}
	
	return count;
}

void printList(struct node* head)
{
	struct node* current = head;
	while(current)
	{
		printf("  %d-%p  \n", current->data, current);
		current = current->next;
	}
}

void freeList(struct node* head)
{
	struct node* current = head;
	struct node* next;

	while (current){
		next = current->next;
		free(current);
		current = next;
	}
}
int main()
{
	struct node* lista;
	lista = BuildOneTwoThree();

	printf("   Len: %d\n", length(lista));
	// freeList(lista);
	printList(lista);
	return 0;
}
