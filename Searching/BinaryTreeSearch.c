#include <stdio.h>
#include <stdlib.h>

int idx = 0;
int arr[100] = { 0 };

typedef struct _node {
	int key;
	struct _node*left; //Smaller than a key value
	struct _node*right; //Bigget than a key value
} NODE;

//Search
NODE *bti_search(int key, NODE *base) {
	NODE *s;
	s = base->left; //base->left == root
	while (key != s->key && s != NULL) { //While finding a key
		if (key < s->key) s = s->left; //If smaller, go left
		else s = s->right; // If bigger, go right.
	}

	if (s == NULL) return NULL; //Failed to find the key
	else return s; //Return the node found
}

//Insert
NODE *bti_insert(int key, NODE *base) {
	NODE *p, *s;
	p = base; //p == parent node of s
	s = base->left; //s == finds NULL (The place to put the key)

	while (s != NULL) {
		p = s;
		if (key < s->key) s = s->left; //smaller -> goes left
		else s = s->right; //bigger -> goes right

	}

	if ((s = (NODE*)malloc(sizeof(NODE)) == NULL)) return NULL; // ERROR: OUT OF MEMEORY

	s->key = key;//Generate New Node;
	s->left = NULL;
	s->right = NULL;

	if (key < p->key || p == base) p->left = s; //if key is smaller than the parent or p==base, s == left child
	else p->right = s; //else, s == right child

	//Increasing #Element
	return s;
}

//Delete
NODE *bti_delete(int key, NODE *base) {
	NODE *parent, *son, *del, *nexth;
	parent = base;
	del = base->left;

	while (key != del->key && del != NULL) {//Find the target
		parent = del;
		if (key < del->key) del = del->left;
		else del = del->right;
	}

	if (del == NULL) return NULL; //Failed to find

	if (del->right == NULL) son = del->left; //Target has no right child
	else if (del->right->left == NULL) {//Target's right child has no left child
		son = del->right;
		son->left = del->left;
	}
	else {
		nexth = del->right;
		while (nexth->left->left != NULL) nexth = nexth->left;//Search node that doesn't have left child
		son = nexth->left;//Searched
		nexth->left = son->right;
		son->left = del->left;
		son->right = del->right;
	}
	//Generate new node
	if (key < parent->key || parent == base)parent->left = son;
	else parent->right = son;

	free(del); //relese the target
	return parent;
}

void bti_traverse(NODE *p) {

	if (p != NULL) {
		bti_traverse(p->left);
		arr[idx++] = p->key;
		bti_traverse(p->right);
	}

	idx = 0;
}

int main() {

	printf("*******Binary Tree Search*******\n\n\n");

	int key, i = 0;
	int isTrue = 1;
	NODE *root, *isComplete = NULL;
	root = (NODE*)malloc(sizeof(NODE));

	while (isTrue) {
		int op = 0;

		printf("1.Traverse\n2.Insert\n3.Search\n4.Delete\n0.Exit\n\nOption: ");
		scanf("%d", &op);

		switch (op) {
		case 1:
			i = 0;
			bti_traverse(root);

			for (i = 0; arr[i] != 0; i++) printf("%d ", arr[i]);

			printf("\n");
			break;

		case 2:
			key = 0;
			printf("Insert: ");
			scanf("%d", &key);
			isComplete = bti_insert(key, root);
			if (isComplete != NULL) printf("Finished\n");
			else printf("ERROR\n");
			break;

		case 3:
			key = 0;
			printf("Search: ");
			scanf("%d", &key);
			isComplete = bti_search(key, root);
			if (isComplete != NULL) printf("Searched\n");
			else printf("Failed\n");
			break;

		case 4:
			key = 0;
			printf("Delete: ");
			scanf("%d", &key);
			isComplete = bti_delete(key, root);
			if (isComplete != NULL) printf("Deleted\n");
			else printf("ERROR\n");
			break;

		case 0:
			isTrue = 0;
			break;

		default:
			break;

		}
	}
}
