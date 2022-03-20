#pragma once
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

//define Status
typedef enum Status {
	error,
	ok
} Status;
Status InitList(LinkedList* L);
void DestroyList(LinkedList* L);
Status DeleteList(LNode* p, ElemType* e);
Status InsertList(LNode* p, LNode* q);
void TraverseList(LinkedList L);
Status SearchList(LinkedList L, ElemType e);