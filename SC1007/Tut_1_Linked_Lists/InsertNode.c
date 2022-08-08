#include <stdio.h>
#include <stdlib.h>

struct _listnode {
  int item ;
  struct _listnode * next ;
};
typedef struct _listnode ListNode ;

ListNode * findNode ( ListNode * cur , int i) {
  if ( cur == NULL || i <0)
    return NULL ;
  while (i >0) {
    cur = cur -> next ;
    if ( cur == NULL )
    return NULL;
    i--;
  }
  return cur ;
}

int insertNode ( ListNode ** ptrHead , int i , int item ){
    ListNode * pre , * newNode ;
  // If empty list or inserting first node , update head pointer
    if (i == 0) {
      newNode = ( ListNode *) malloc ( sizeof ( ListNode ));
      newNode -> item = item ;
      newNode -> next = * ptrHead ;
      * ptrHead = newNode ;
      return 1;
    }
   // Find the nodes before and at the target position
   // Create a new node and reconnect the links
    else if (( pre = findNode (* ptrHead , i -1) ) != NULL ){
      newNode = ( ListNode *) malloc ( sizeof ( ListNode ));
      newNode -> item = item ;
      newNode -> next = pre -> next ;
      pre -> next = newNode ;
      return 1;
    }
  return 0;
}

int recInsertNode(ListNode** ptrHead, int i, int item) {
  ListNode* newNode;
  if (i == 0) {
    newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->item = item;
    newNode -> next = * ptrHead;
    *ptrHead = newNode;
    return 1;
  } else if (i == 1) {
    newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->item = item;
    newNode->next = (*ptrHead)->next;
    (*ptrHead)->next = newNode;
    return 1;
  }
  i--;
  ListNode* nextPtr = (*ptrHead)->next;
  ListNode** adjustedHead = &nextPtr;
  recInsertNode(adjustedHead, i, item);
}

int main() {
  ListNode head;
  head.item = 0;
  ListNode* ptrHead = &head;
  ListNode** ptrptrHead = &ptrHead;
  insertNode(ptrptrHead, 1, 10);
  recInsertNode(ptrptrHead, 2, 20);
  recInsertNode(ptrptrHead, 3, 30);
  recInsertNode(ptrptrHead, 1, 50);
  // printf("%p", ptrptrHead);
  // printf("\n%d", ptrHead->item);
  // printf("\n%d", ptrHead->next->item);
  // printf("%p", ptrHead->next);
  ListNode** ptr = ptrptrHead;
  for (int i = 0; i < 5; i++) {
    printf("\n%d", (*ptr)->item);
    *ptr = (*ptr)->next;
  }
}
