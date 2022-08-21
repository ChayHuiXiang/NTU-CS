#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
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

ListNode *reverseSegment(ListNode* head, int start, int end) {
  int count = 0;
  ListNode* countNode = head;
  while (count <= end) {
    if (countNode == NULL) {
      return head;
    }
    countNode = countNode->next;
    count++;
  }

	int currIndex = 0;
	ListNode* dummy = head;
	ListNode* preNode = NULL;
	ListNode* currNode = head;
	while (currIndex != start) {
		preNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}

	ListNode* preTemp = preNode;
	ListNode* endTemp = currNode;

	preNode = currNode;
	currNode = currNode->next;
	preNode->next = NULL;
	currIndex++;

	ListNode* temp = NULL;
	while (currIndex <= end) {
		temp = currNode;
		currNode = currNode->next;
		temp->next = preNode;
		preNode = temp;
		currIndex++;
	}
  
  if (preTemp != NULL) {
	  preTemp->next = preNode;
  } else {
    dummy = preNode;
  }
	endTemp->next = currNode;

	return dummy;
}
