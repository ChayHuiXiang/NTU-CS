#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void reverseKNodes(ListNode** head, int K);

int main()
{
  ListNode *head = NULL, *temp;
	int i = 0;
	int K = 0;

	scanf("%d",&K);

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


	reverseKNodes(&head, K);
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

int checkNodes(ListNode* head, int K) {
  int count = 0;
  while (count != K) {
    if (head == NULL) {
      return 0;
    }
    head = head->next;
    count++;
  }
  return 1;
}

void reverseKNodes(ListNode** head, int K){
//Write your code here
  if (K == 0) {
    return;
  }
  int index = 0;
  int loopCount = 0;
  ListNode* prevFirstNode = NULL;
  ListNode* preNode = NULL;
  ListNode* temp = NULL;
  ListNode* currNode = *head;

  while (1) {
    ListNode* firstNode = currNode;
    if (checkNodes(firstNode, K) == 0) {
      if (prevFirstNode != NULL) {
        prevFirstNode->next = firstNode;
      }
      return;
    }
    do {
      temp = currNode;
      currNode = currNode->next;
      temp->next = preNode;
      preNode = temp;
      index++;
    } while (index % K != 0);
    if (loopCount == 0) {
      *head = preNode;
    }
    if (prevFirstNode != NULL) {
      prevFirstNode->next = preNode;
    }
    prevFirstNode = firstNode;
    loopCount++;
  }
}
