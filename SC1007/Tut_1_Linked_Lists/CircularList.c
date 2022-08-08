#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int item ;
  struct node* next ;
} ListNode ;

int main() {
}

void Q3F1 ( ListNode * Aptr , ListNode * Bptr ) {
  Q3F2 ( Aptr , Bptr ); // Aptr = A, Bptr = D , C.next = A
  Q3F2 ( Bptr , Aptr );
}
void Q3F2 ( ListNode *s , ListNode *q ) {
  ListNode * temp = s;
  while ( temp -> next != q ) temp = temp -> next; 
  temp -> next = s;
}


// breaks the linked list into 2, 
// first linked list: Aptr to Bptr.prev, loops back to Aptr
// second linked list: Bptr to Aptr.prev, loops back to Bptr
