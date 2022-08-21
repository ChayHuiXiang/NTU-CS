#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

typedef struct _linkedList{
    ListNode *head;
    int size;
}LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList* llptr);

LinkedList rearrange (LinkedList ll);

int main()
{
    LinkedList ll;

    ll.head = NULL;
    ll.size = 0;
    ListNode* temp;

	int i = 0;

	while (scanf("%d", &i)){
		if (ll.head == NULL){
			ll.head = (ListNode*) malloc(sizeof(ListNode));
			temp = ll.head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
		ll.size++;
	}
	temp->next = NULL;

	ll=rearrange(ll);

	printList(ll);
    deleteList(&ll);
	return 0;
}

void printList(LinkedList ll){
    ListNode* temp = ll.head;

    while(temp !=NULL){
        printf("%d ",temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void deleteList(LinkedList* llptr){
    ListNode *cur = llptr->head;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	llptr->head=NULL;
	llptr->size =0;
}

LinkedList firstTraverse(LinkedList ll) {
  if (ll.size == 1) {
    LinkedList combined;
	  combined.size = ll.size;
	  combined.head = (ListNode*) malloc(sizeof(ListNode));
    combined.head->item = ll.head->item;
    return combined;
  }
	int leftSize = ll.size / 2;
	LinkedList left;
	LinkedList right;

	left.head = ll.head;
	left.size = leftSize;
	
	right.size = ll.size - leftSize;
	ListNode* temp = ll.head;
	while (leftSize > 0) {
		temp = temp->next;
		leftSize--;
	}
	right.head = temp;

	LinkedList combined;
	combined.size = ll.size;
	combined.head = NULL;
	ListNode* leftTemp = left.head;
	ListNode* rightTemp = right.head;
	temp = NULL;
	for (int i = 0; i < left.size; i++) {
		if (combined.head == NULL) {
			combined.head = (ListNode*) malloc(sizeof(ListNode));
			temp = combined.head;
		} else {
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
			rightTemp = rightTemp->next;
		}
		temp->item = rightTemp->item;
		temp->next = (ListNode*) malloc(sizeof(ListNode));
		temp = temp->next;
		temp->item = leftTemp->item;
		leftTemp = leftTemp->next;
	}
  if (rightTemp->next != NULL) {
    temp->next = (ListNode*) malloc(sizeof(ListNode));
    rightTemp = rightTemp->next;
    temp = temp->next;
    temp->item = rightTemp->item;
  }
	
	return combined;
}

LinkedList secondTraverse(LinkedList ll) {
  if (ll.size == 1) {
    LinkedList combined;
	  combined.size = ll.size;
	  combined.head = (ListNode*) malloc(sizeof(ListNode));
    combined.head->item = ll.head->item;
    return combined;
  }
	int leftSize = ll.size / 2;
	LinkedList left;
	LinkedList right;

	left.head = ll.head;
	left.size = leftSize;
	
	right.size = ll.size - leftSize;
	ListNode* temp = ll.head;
	while (leftSize > 0) {
		temp = temp->next;
		leftSize--;
	}
	right.head = temp;

	LinkedList combined;
	combined.size = ll.size;
	combined.head = NULL;
	ListNode* leftTemp = left.head;
	ListNode* rightTemp = right.head;
	temp = NULL;

	for (int i = 0; i < left.size; i++) {
		if (combined.head == NULL) {
			combined.head = (ListNode*) malloc(sizeof(ListNode));
			temp = combined.head;
		} else {
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
			leftTemp = leftTemp->next;
		}
		temp->item = leftTemp->item;
		temp->next = (ListNode*) malloc(sizeof(ListNode));
		temp = temp->next;
		temp->item = rightTemp->item;
		rightTemp = rightTemp->next;
	}
  if (rightTemp != NULL) {
    temp->next = (ListNode*) malloc(sizeof(ListNode));
    temp = temp->next;
    temp->item = rightTemp->item;
  }
	
	return combined;
}

LinkedList rearrange (LinkedList ll){
// Write your code here
	LinkedList once = firstTraverse(ll);
	LinkedList second = secondTraverse(once);
	return second;
}
