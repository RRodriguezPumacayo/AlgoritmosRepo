#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct Node {
    int key;
    enum Color color;
    struct Node *left, *right, *parent;
};

struct RedBlackTree {
    struct Node *root, *nil;
};

struct Node* createNode(int key, enum Color color, struct Node *nil) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->color = color;
    node->left = nil;
    node->right = nil;
    node->parent = nil;
    return node;
}

struct RedBlackTree* createRedBlackTree() {
    struct RedBlackTree *tree = (struct RedBlackTree*)malloc(sizeof(struct RedBlackTree));
    struct Node *nil = createNode(0, BLACK, NULL);
    tree->nil = nil;
    tree->root = nil;
    return tree;
}

void leftRotate(struct RedBlackTree *tree, struct Node *x) {
    // Implementar rotación izquierda
}

void rightRotate(struct RedBlackTree *tree, struct Node *y) {
    // Implementar rotación derecha
}

void insertFixup(struct RedBlackTree *tree, struct Node *z) {
    // Implementar reglas de corrección después de la inserción
}

void insert(struct RedBlackTree *tree, int key) {
    struct Node *z = createNode(key, RED, tree->nil);
    struct Node *y = tree->nil;
    struct Node *x = tree->root;

    while (x != tree->nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == tree->nil) {
        tree->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    insertFixup(tree, z);
}

void printTreeRecursive(struct Node *node, int level){
	if (node != NULL){
		printTreeRecursive(node->left, level+1);
		for (int i = 0; i < level; i++){
			printf("---");
		}
		printf("%d\n", node->key);
		printTreeRecursive(node->right, level + 1);
	}
}

void printTree(struct RedBlackTree *tree){
	printTreeRecursive(tree->root, 0);
}

int main() {
    struct RedBlackTree *tree = createRedBlackTree();

    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
	
    printTree(tree);
    // ... continúa insertando más nodos según sea necesario

    return 0;
}

