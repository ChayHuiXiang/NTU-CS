#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const int SIZE = 1000;

typedef struct _listNode {
  struct _listNode* next;
  char item;
} ListNode;

typedef ListNode StackNode;

typedef struct _stack {
  StackNode* head;
  int size;
} Stack;

void push(Stack* sPtr, char item) {
  StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
  newNode->item = item;
  newNode->next = sPtr->head;
  sPtr->head = newNode;
  sPtr->size++;
}

int isEmptyStack(Stack s) {
  if (s.size == 0) return 1;
  else return 0;
}

int pop(Stack* sPtr) {
  if (sPtr == NULL || sPtr->head == NULL) {
    return 0;
  } else {
    StackNode *temp = sPtr->head;
    sPtr->head = sPtr->head->next;
    free(temp);
    sPtr->size--;
    return 1;
  }
}

char peek(Stack s) {
  return s.head->item;
}

void in2Post(char*, char*);

int main() {
  char infix[SIZE];
  char postfix[SIZE];

  printf("Enter an infix expression:\n");
  scanf("%[^\n]%*c",infix);

  in2Post(infix, postfix);
  printf("%s", postfix);
}

int precedence(char character) {
  switch(character) {
    case '*':
      return 5;
      break;
    case '/':
      return 5;
      break;
    case '%':
      return 5;
      break;
    case '+':
      return 4;
      break;
    case '-':
      return 4;
      break;
    case '<':
      return 3;
      break;
    case '>':
      return 3;
      break;
    case '&':
      return 2;
      break;
    case '=':
      return 1;
  }
  return 0;
}

int higherPrecedence(char first, char second) {
  int firstPrecedence = precedence(first);
  int secondPrecedence = precedence(second);
  return firstPrecedence >= secondPrecedence;
}

void in2Post(char* infix, char* postfix) {
  Stack stack;
  stack.head = NULL;
  stack.size = 0;
  Stack* stackPtr = &stack;

  for (;*infix;infix++) {
    char character = *infix;
    if (isalnum(character)) {
      *postfix++ = character;
    } else if (character == '(') {
      push(stackPtr, character);
    } else if (character == ')') {
      while (peek(*stackPtr) != '(') {
        char operator = peek(*stackPtr);
        pop(stackPtr);
        *postfix++ = operator;
      }
      pop(stackPtr);
    } else {
      if (character == '&' || character == '<' || character == '>') infix++;
      while (!isEmptyStack(*stackPtr) && peek(*stackPtr) != '(' && higherPrecedence(peek(*stackPtr), character)) {
        char operator = peek(*stackPtr);
        pop(stackPtr);
        if (operator == '&' || operator == '<' || operator == '>') {
          *postfix++ = operator;
        }
        *postfix++ = operator;
      }
      push(stackPtr, character);
    }
  }
  while (!isEmptyStack(*stackPtr)) {
    char operator = peek(*stackPtr);
    pop(stackPtr);
    if (operator == '&' || operator == '<' || operator == '>') {
      *postfix++ = operator;
    }
    *postfix++ = operator;
  }
  *postfix = '\0';
}
