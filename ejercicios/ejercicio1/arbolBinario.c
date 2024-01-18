#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

static int lookup(struct node*, int);
struct node* newNode(int, struct node*);
struct node* insert(struct node*, int, struct node*);
void mostrarArbol(struct node*, int);
void build123(struct node**);
int size(struct node*);
int maxDepth(struct node* node);
void inOrder(struct node* node);
void postOrder(struct node* node);
int search(struct node*, int datoBuscar);
struct node* deleteNode(struct node*, int);

int main(){
	struct node* three = NULL;
	build123(&three);
	insert(three, 1, NULL);
	insert(three, 2, NULL);
	printf("Size: %d\n", size(three));
	mostrarArbol(three, 1);
	printf("Hijo: %d Padre: %d\n", three->left->left->data, three->left->left->parent->data);
	
	printf("Maxdepth: %d\n", maxDepth(three));
	inOrder(three);
	printf("\n");
	
	deleteNode(three, 3);
	deleteNode(three, 3);
	
	
	postOrder(three);
	printf("\n");
	mostrarArbol(three, 0);
	printf("Busqueda: %d\n", search(three, 3));

	return 0;
}

static int lookup(struct node* node, int target){
	if (node == NULL){
		return 0;
	}
	else {
		if (target == node->data)
			return 1;
		else {
			if (target < node->data)
				return (lookup(node->left, target));
			else
				return (lookup(node->right, target));
		}
	}
}

struct node* newNode(int data, struct node* parent){
	struct node* node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return (node);
}

struct node* insert(struct node* node, int data, struct node* parent){
	if (node == NULL){
		return newNode(data, parent);
	}
	else {
		if (data <= node->data){
			node->left = insert(node->left, data, node);
		}
		else{
			node->right = insert(node->right, data, node);
		}
	}
	return node;
}

void mostrarArbol(struct node* node, int count){
	if (node != NULL){
		mostrarArbol(node->left, count+1);
		for (int i = 0; i < count; i++){
			printf("--");
		}
		printf("%d\n", node->data);
		mostrarArbol(node->right, count+1);
	}
}

void build123(struct node** three){
	(*three) = newNode(2, NULL);
	(*three)->left = newNode(1, *three);
	(*three)->right = newNode(3, *three);
}

int size(struct node* node){
	int i = 1;
	struct node* aux = node;
	if (node == NULL){
		return 0;
	}
	while (aux->left != NULL){
		i++;
		aux = aux->left;
	}
	aux = node;
	while (aux->right != NULL){
		i++;
		aux = aux->right;
	}
	return i;
}

int maxDepth(struct node* node){
	if (node == NULL) {
		return 0;
	} else {
		int leftDepth = maxDepth(node->left);
		int rightDepth = maxDepth(node->right);

		return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
	}
}

void inOrder(struct node* node){
	if (node == NULL){
		return;
	}
	inOrder(node->left);
	printf("%d ", node->data);
	inOrder(node->right);
}

void postOrder(struct node* node){
	if (node == NULL){
		return;
	}

	postOrder(node->left);
	postOrder(node->right);
	printf("%d ", node->data);
}

int search(struct node* node, int datoBuscar){
	if (node == NULL){
		return 0;
	}
	else{
		if (datoBuscar == node->data){
			return node->data;
		}
		else if (datoBuscar < node->data){
			search(node->left, datoBuscar);
		}
		else
			search(node->right, datoBuscar);
	}
}

struct node* deleteNode(struct node* root, int data){
	if (root == NULL)
		return root;
	if (data < root->data)
		root->left = deleteNode(root->left, data);

	else if (data > root->data)
		root->right = deleteNode(root->right, data);

	else {
		// Nodo solo hijo o sin nodos
		if (root->left == NULL){
			struct node* temp = root->right;
			free(root);
			return temp;
		}else if (root->right == NULL){
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;

		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
