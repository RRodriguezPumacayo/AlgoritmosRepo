#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* small;
	struct node* large;
};

typedef struct node* Node;

static void join(Node a, Node b) {
	a->large = b;
	b->small = a;
}

static Node append(Node a, Node b) {
	Node aLast, bLast;

	if (a==NULL) return(b);
	if (b==NULL) return(a);

	aLast = a->small;
	bLast = b->small;

	join(aLast, b);
	join(bLast, a);

	return (a);
}

static Node treeToList(Node root) {
	Node aList, bList;

	if (root==NULL) return NULL;

	aList = treeToList(root->small);
	bList = treeToList(root->large);

	root->small = root;
	root->large = root;

	aList = append(aList, root);
	aList = append(aList, bList);

	return aList;
}

/* Create a new node */
static Node newNode(int data) {
	Node node = (Node)malloc(sizeof(struct node));
	node->data = data;
	node->small = NULL;
	node->large = NULL;
	return node;
}

/* Add a new node into a tree */
static void treeInsert(Node* rootRef, int data) {
	Node root = *rootRef;
	if (root == NULL) *rootRef = newNode(data);
	else{
		if (data <= root->data) treeInsert(&(root->small), data);
		else treeInsert(&(root->large), data);
	}
}

static void printList(Node head){
	Node current = head;

	while (current != NULL){
		printf("%d ", current->data);
		current = current->large;
		if (current == head)
			break;
	}
	printf("\n");
}

int main(){
	Node root = NULL;
	Node head;

	treeInsert(&root, 4);
	treeInsert(&root, 2);
	treeInsert(&root, 1);
	treeInsert(&root, 3);
	treeInsert(&root, 5);

	head = treeToList(root);

	printList(head);

	return 0;
}
