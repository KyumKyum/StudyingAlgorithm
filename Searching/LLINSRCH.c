// Linear Search Linked List Version.

#include <stdio.h>
#include <stdlib.h>

typedef struct _node { //Linked List Node
	struct _node *next;
} NODE;

void init_list (node **p){ //Initialize the HEAD
	*p = (NODE*)malloc(sizeof(NODE));
	(*p)->next = NULL; //NULL at End of the node
}

//Search
void *llv_search(void *key, NODE *base, size_t *num, size_t width, FCMP fcmp){
	NODE *t;
	t = base->next; //t = The very first node of Linked List
	while (fcmp(t+1, key) != 0 && t != NULL) t = t->next; //Sequential Search

	return (t == NULL ? NULL : t+1); //Return Record if it is found
}

//Insert
void *llv_insert(void *key, NODE *base, size_t *num, size_t width, FCMP fcmp){
	NODE *t;
	
	if((t = (NODE*)malloc(sizeof(NODE)*width))==NULL) return NULL; //Allocate space for new node (sizeof NODE + width) 

	memcpy(t+1, key, width); // Copy key on the record space

	t->next = base->next; //Locate on the Front
	base->next = t;
	(*num)++; //Increase #element
	
	return t;//Return target pointer.
}

//Delete
void *llv_delete(void *key, NODE *base, size_t *num, size_t width, FCMP fcmp){
	node *t, *p;

	if(base->next != NULL){ //If the list is not empty
		if((t = (NODE*)llv_search(key, base, num, width, fcmp)) == NULL) return NULL; //Return null if the target isn't found

		t = t-1; // Move the pointer from the record to node
		p = base; //Pointet to finde t node's parent for deletion

		while(p->next != t) p = p->next; //Searching
		p->next = t->next; // Disconnect the target node
		free(t); //delete target

		(*num)--; //Decrease #element

		return p; //Return target node's parent
	}
	return NULL;
}

//Self-Orginizing Search
void *llfv_search(void *key, NODE *base, size_t *num, size_t width, FCMP fcmp){
	void *v, *f;

	if((v = liv_search(key,base,num,width,fcmp))==NULL) return NULL; //SEARCH

	f = malloc(width); //temporarily store the record
	memcpy(f, v, width);
	liv_delete(key,base,num,width,fcmp); //Delete the targer record
	v = liv_insert(f,base,num,width,fcmp); //Insert f at the front

	free(f); //Delete temporal storage
	return v;
}

//Delete All
void *llv_deleteall(NODE *base){
	node *t, *s; //t = base, s = target
	t = base->next;

	while (t != NULL){
		s = t;
		t = t->next;
		free(s);
	}

	base->next = NULL; //Empty Linked List
	return base;
}
