#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int SIZE = 1000;

typedef struct _listNode {
  struct _listNode* next;
  char* item;
} ListNode;

typedef ListNode StackNode;

typedef struct _stack {
  ListNode* head;
  int size;
} Stack;

char* peek(Stack);

void push(Stack*, char*);

int pop(Stack*);

int isEmptyStack(Stack);

void pre2In(char*, char*);

int main() {
  char prefix[SIZE];
  char infix[SIZE];
  printf("Enter a prefix expression: ");
  scanf("%[^\n]%*c",prefix);

  pre2In(prefix, infix);
  printf("%s", infix);
}

char* peek(Stack s) {
  return s.head->item;
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

int isEmptyStack(Stack s) {
  return s.size == 0;
}

void pre2In(char* prefix, char* infix) {
  Stack stack;
  stack.head = NULL;
  stack.size = 0;
  Stack* sPtr = &stack;

  while (*prefix) {
    prefix++;
  }

  prefix--;
  while (*prefix) {
    char character = *prefix;
    char* characters = (char*) malloc(sizeof(char)*3);
    char* charactersStart = characters;
    if (character == '>' || character == '<' || character == '&') {
      *characters++ = character;
      *characters++ = character;
      *characters = '\0';
      prefix--;
    } else {
      *characters++ = character;
      *characters = '\0';
    }
    if (isalnum(character)) {
      char* charPtr = (char*)malloc(sizeof(char)*2);
      char* charPtrStart = charPtr;
      *charPtr++ = character;
      *charPtr = '\0';
      push(sPtr, charPtrStart);
    } else {
      char* operand1 = peek(*sPtr);
      pop(sPtr);
      char* operand2 = peek(*sPtr);
      pop(sPtr);
      char* charPtr = (char*)malloc(sizeof(char) * SIZE);
      char* charPtrStart = charPtr;
      while (*operand1) {
        char oper1Char = *operand1++;
        *charPtr++ = oper1Char;
      }
      while (*charactersStart) {
        char operator = *charactersStart++;
        *charPtr++ = operator;
      }
      while (*operand2) {
        char oper2Char = *operand2++;
        *charPtr++ = oper2Char;
      }
      *charPtr = '\0';
      push(sPtr, charPtrStart);
    }
    prefix--;
  }
  char* result = peek(*sPtr);
  while (*result) {
    *infix++ = *result++;
  }
  *infix = '\0';
}
