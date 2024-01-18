#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* der;
	struct node* izq;
};

struct node* newNode(int);
struct node* insert(struct node**, int);

void mostrarArbol(struct node*);

int main()
{
	struct node* arbol = NULL;
	arbol = insert(&arbol, 5);
:x
	mostrarArbol(arbol);
	return 0;
}

struct node* newNode(int data)
{
	struct node* nodo = (struct node*)malloc(sizeof(struct node));
	nodo->data = data;
	nodo->der = NULL;
	nodo->izq = NULL;
}

struct node* insert(struct node** root, int data)
{
	if (root == NULL)
		return newNode(data);
	if (data <= (*root)->data)
		(*root)->izq = insert(&((*root)->izq), data);
	else
		(*root)->der = insert(&((*root)->der), data);
	return *root;
}

void mostrarArbol(struct node* root)
{
	if (root->izq != NULL){
		mostrarArbol(root->izq);
		printf("%d ", root->data);
		mostrarArbol(root->der);
	}
	printf("\n");
}
