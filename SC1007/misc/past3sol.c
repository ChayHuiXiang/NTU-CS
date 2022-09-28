#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode {
  struct _listNode* next;
  int item;
} ListNode;

void printList(ListNode* node);
void removeDuplicate(ListNode* node);

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

  removeDuplicate(head);
  printList(head);
}

void printList(ListNode* node) {
  while (node) {
    printf("%d ",node->item);
    node = node->next;
  }
}

void removeDuplicate(ListNode* node) {
  ListNode* temp = node;
  ListNode* prev = NULL;
  int arr[120];
  for (int i = 0; i < 120; i++) {
    arr[i] = 0;
  } 
  while (temp) {
    int item = temp->item;
    if (arr[item] == 1) {
      prev->next = temp->next;
    } else {
      arr[item] = 1;
      prev = temp;
    }
    temp = temp->next;
  }
}
