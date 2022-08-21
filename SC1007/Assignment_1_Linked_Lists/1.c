#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void triPartition(ListNode** head, int pivot);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int pivot = 0;

	scanf("%d",&pivot);

	while (scanf("%d", &i)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
	}
	temp->next = NULL;


	triPartition(&head, pivot);
	printList(head);
	deleteList(&head);

	return 0;
}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%d ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

void triPartition(ListNode** head, int pivot){
	ListNode* curr = *head;
	ListNode* less = NULL;
	ListNode* equal = NULL;
	ListNode* more = NULL;
	ListNode* temp;
	while (curr != NULL) {
		if (curr->item < pivot) {
			if (less == NULL) {
				less = (ListNode*) malloc(sizeof(ListNode));
				temp = less;
			} else {
				temp->next = (ListNode*) malloc(sizeof(ListNode));
				temp = temp->next;
			}
			temp->item = curr->item;
		}
		curr = curr->next;
	}
	curr = *head;
	while (curr != NULL) {
		if (curr->item == pivot) {
			if (equal == NULL) {
				equal = (ListNode*) malloc(sizeof(ListNode));
				temp = equal;
			} else {
				temp->next = (ListNode*) malloc(sizeof(ListNode));
				temp = temp->next;
			}
			temp->item = curr->item;
		}
		curr = curr->next;
	}
	curr = *head;
	while (curr != NULL) {
		if (curr->item > pivot) {
			if (more == NULL) {
				more = (ListNode*) malloc(sizeof(ListNode));
				temp = more;
			} else {
				temp->next = (ListNode*) malloc(sizeof(ListNode));
				temp = temp->next;
			}
			temp->item = curr->item;
		}
		curr = curr->next;
	}
	temp = less;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = equal;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = more;
	*head = less;
// Write your code here
}
