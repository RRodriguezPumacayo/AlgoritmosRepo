#include <stdio.h>
#include <stdlib.h>

// Definición de colores
#define RED 0
#define BLACK 1

struct Node {
    int data;
    int color;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

// Función para crear un nuevo nodo
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Función para realizar una rotación a la izquierda
void leftRotate(struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

// Función para realizar una rotación a la derecha
void rightRotate(struct Node *y) {
    struct Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

// Función para arreglar el árbol después de insertar un nodo
void fixInsert(struct Node *newNode) {
    while (newNode->parent != NULL && newNode->parent->color == RED) {
        if (newNode->parent == newNode->parent->parent->left) {
            struct Node *y = newNode->parent->parent->right;
            if (y != NULL && y->color == RED) {
                newNode->parent->color = BLACK;
                y->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotate(newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                rightRotate(newNode->parent->parent);
            }
        } else {
            struct Node *y = newNode->parent->parent->left;
            if (y != NULL && y->color == RED) {
                newNode->parent->color = BLACK;
                y->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotate(newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                leftRotate(newNode->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

// Función para insertar un nuevo nodo en el árbol rojo-negro
void insert(int data) {
    struct Node *newNode = createNode(data);
    struct Node *y = NULL;
    struct Node *x = root;

    while (x != NULL) {
        y = x;
        if (newNode->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    newNode->parent = y;

    if (y == NULL) {
        root = newNode;
    } else if (newNode->data < y->data) {
        y->left = newNode;
    } else {
        y->right = newNode;
    }

    fixInsert(newNode);
}

// Función para imprimir el árbol en orden
void inorder(struct Node *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);

    printf("Árbol rojo-negro en orden: ");
    inorder(root);

    return 0;
}

