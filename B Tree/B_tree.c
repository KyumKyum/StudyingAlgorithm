//B-tree in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 1

//Tree Node
struct BTREENODE {
	int val[MAX + 1], count;
	struct BTREENODE * link[MAX + 1];
};

//Root
struct BTREENODE *root;

//Create Node
struct BTREENODE *createNode(int val, struct BTREENODE *child) {
	struct BTREENODE *newNode;

	newNode = (struct BTREENODE *)malloc(sizeof(struct BTREENODE));
	newNode->val[1] = val;
	newNode->count = 1;
	newNode->link[0] = root;
	newNode->link[1] = child;
	return newNode;
}

//Insert Node
void insertNode(int val, int pos, struct BTREENODE *node, 
	struct BTREENODE *child) {

	int j = node->count;
	while (j > pos) {
		node->val[j + 1] = node->val[j];
		node->link[j + 1] = node->link[j];
		j--;
	}
	node->val[j + 1] = val;
	node->link[j + 1] = child;
	node->count++;
}

//Split Node
void splitNode(int val, int *pval, int pos, struct BTREENODE *node,
		struct BTREENODE *child, struct BTREENODE **newNode) {
	int median, j;

	if (pos > MIN)
		median = MIN + 1;
	else
		median = MIN;

	*newNode = (struct BTREENODE *)malloc(sizeof(struct BTREENODE));
	j = median + 1;

	while (j <= MAX) {
		(*newNode)->val[j - median] = node->val[j];
		(*newNode)->link[j - median] = node->link[j];
		j++;
	}
	node->count = median;
	(*newNode)->count = MAX - median;

	if (pos <= MIN) {
		insertNode(val, pos, node, child);
	}
	else {
		insertNode(val, pos - median, *newNode, child);
	}
	*pval = node->val[node->count];
	(*newNode)->link[0] = node->link[node->count];
	node->count--;
}

int setValue(int val, int *pval,
	struct BTREENODE *node, struct BTREENODE **child) {
	int pos;
	
	if (!node) {
		*pval = val;
		*child = NULL;
		return 1;
	}

	if (val < node->val[1]) {
		pos = 0;
	}
	else {
		for (pos = node->count; (val < node->val[pos]
			&& pos > 1); pos--);
		if (val == node->val[pos]) {
			printf("DUPLICATED ELEMENTS ARE NOT PERMITTED");
			return 0;
		}
	}

	if (setValue(val, pval, node->link[pos], child)) {
		if (node->count < MAX) {
			insertNode(*pval, pos, node, *child);
		}
		else {
			splitNode(*pval, pval, pos, node, *child, child);
			return 1;
		}
	}
	return 0;
}

//Insert Value

void insert(int val) {
	int flag, i;
	struct BTREENODE*child;

	flag = setValue(val, &i, root, &child);
	if (flag)
		root = createNode(i, child);
}

//Search
void search(int val, int *pos, struct BTREENODE *myNode) {
	if (!myNode) { // NODE NOT FOUND
		printf("%d NOT FOUND", val);
		return;
	}

	if (val < myNode->val[1]) {
		*pos = 0;
	}
	else {
		for (*pos = myNode->count; (val < myNode->val[*pos] 
			&& pos >1); (*pos)--);

		if (val == myNode->val[*pos]) {
			printf("%d is found", val);
			return;
		}
	}
	search(val, pos, myNode->link[*pos]);

	return;
}

//Traverse
void traversal(struct BTREENODE *myNode) {
	int i;
	if (myNode) {
		for (i = 0; i < myNode->count; i++) {
			traversal(myNode->link[i]);
			printf("%d ", myNode->val[i + 1]);
		}
		traversal(myNode->link[i]);
	}
}

int main() {
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(70);

	printf("\n");

	traversal(root);

}