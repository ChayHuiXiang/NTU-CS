#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int SIZE = 1000;

typedef struct _listNode {
  struct _listNode* next;
  char* item;
} ListNode;

typedef ListNode StackNode;

typedef struct _struct {
  StackNode* head;
  int size;
} Stack;

void push(Stack*, char* item);
int pop(Stack*);
char* peek(Stack);
int isEmptyStack(Stack);
void post2pre(char*, char*);

int main() {

  char postfix[SIZE];
  char prefix[SIZE];
  printf("Enter a postfix expression: ");
  scanf("%[^\n]%*c",postfix);

  post2pre(postfix, prefix);
  printf("%s", prefix);
}

void push(Stack* sPtr, char* item) {
  StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
  newNode->item = item;
  newNode->next = sPtr->head;
  sPtr->head = newNode;
  sPtr->size++;
}

int pop(Stack* sPtr) {
  if (sPtr == NULL || sPtr->head == NULL) {
    return 0;
  } else {
    StackNode* temp = sPtr->head;
    sPtr->head = temp->next;
    free(temp);
    sPtr->size--;
    return 1;
  }
}

char* peek(Stack s) {
  return s.head->item;
}

int isEmptyStack(Stack s) {
  return s.size == 0;
}

void post2pre(char* postfix, char* prefix) {
  Stack stack;
  stack.head = NULL;
  stack.size = 0;
  Stack* sPtr = &stack;

  while (*postfix) {
    char character = *postfix;
    char* characters = (char*)malloc(sizeof(char)*3);
    char* charactersStart = characters;
    if (character == '&' || character == '<' || character == '>') {
      *characters++ = character;
      postfix++;
    }
    *characters++ = character;
    *characters = '\0';

    if (isalnum(character)) {
      push(sPtr, charactersStart);
    } else {
      char* operand1 = peek(*sPtr);
      pop(sPtr);
      char* operand2 = peek(*sPtr);
      pop(sPtr);
      char* charPtr = (char*)malloc(sizeof(char)*SIZE);
      char* charPtrStart = charPtr;
      while (*charactersStart) {
        *charPtr++ = *charactersStart++;
      }
      while (*operand1) {
        *charPtr++ = *operand1++;
      }
      while (*operand2) {
        *charPtr++ = *operand2++;
      }
      *charPtr = '\0';
      push(sPtr, charPtrStart);
    }
    postfix++;
  }
  char* result = peek(*sPtr);
  while (*result) {
    *prefix++ = *result++;
  }
  *prefix = '\0';
}
