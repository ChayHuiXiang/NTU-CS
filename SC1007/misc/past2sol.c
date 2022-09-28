#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode {
  struct _listNode* next;
  int item; 
} ListNode;

void swapPairwise(ListNode** head);
void printList(ListNode* head);
void deleteList(ListNode** head);

int main() {
  ListNode *head = NULL, *temp;
	int i = 0;

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

  swapPairwise(&head);
  printList(head); 
  deleteList(&head);

  return 1;
}

void printList(ListNode* head) {
  while (head) {
    printf("%d ", head->item);
    head = head->next;
  }
}

void deleteList(ListNode** ptrHead) {
  ListNode *cur = *ptrHead;
  ListNode *temp;
  while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

int swappable(ListNode* node) {
  if (!node || !(node->next)) {
    return 0;
  }
  return 1;
}

void swapPairwise(ListNode** head) {
  ListNode* temp = *head;
  if (!temp || !(temp->next)) {
    return;
  }
  *head = temp->next;
  ListNode* prevLast = NULL;

  while (swappable(temp)) {
    ListNode* first = temp;
    ListNode* second = temp->next;
    temp = temp->next->next;
    second->next = first;
    if (prevLast) {
      prevLast->next = second;
    }
    prevLast = first;
  }
  prevLast->next = temp;
}
