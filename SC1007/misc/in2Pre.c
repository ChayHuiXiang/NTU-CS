#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

void in2Pre(char*, char*);

int main()
{
  char infix[SIZE];
  char prefix[SIZE];

  printf("Enter an infix expression:\n");
  scanf("%[^\n]%*c",infix);

  in2Pre(infix,prefix);
  printf("The prefix expression is \n");
  printf("%s\n",prefix);
  return 0;
}

void push(Stack *sPtr, char item){
  StackNode *newNode;
  newNode = (StackNode *) malloc(sizeof(StackNode));
  newNode->item = item;
  newNode->next = sPtr->head;
  sPtr->head = newNode;
  sPtr->size++;
}

int pop(Stack *sPtr){
  if(sPtr == NULL || sPtr->head == NULL){
      return 0;
  }
  else{
      StackNode *temp = sPtr->head;
      sPtr->head = sPtr->head->next;
      free(temp);
      sPtr->size--;
      return 1;
  }
}

char peek(Stack s){
  return s.head->item;
}

int isEmptyStack(Stack s){
  if(s.size == 0) return 1;
  else return 0;
}

int higherPrecedence(char operator1, char operator2) {
  if (operator2 == '*' || operator2 == '/' || operator1 == ')') {
    return 0;
  }
  return 1;
}

void in2Pre(char* infix, char* prefix) {
  Stack s;
  s.head = NULL;
  s.size = 0;
  Stack* sPtr = &s;

  Stack pre;
  pre.head = NULL;
  pre.size = 0;
  Stack* preS = &pre;
  
  while (*infix) {
    infix++;
  }
  infix--;

  while (*infix) {
    char curr = *infix;
    if (curr == ')') {
      push(sPtr, curr);
    } else if (isalnum(curr)) {
      push(preS,curr);
    } else if (curr == '(') {
      while (peek(*sPtr) != ')') {
        char top = peek(*sPtr);
        pop(sPtr);
        push(preS,top);
      }
      pop(sPtr);
    } else {
      while (!isEmptyStack(*sPtr) && higherPrecedence(peek(*sPtr), curr)) {
        char top = peek(*sPtr);
        pop(sPtr);
        push(preS,top);
      }
      push(sPtr, curr);
    }
    infix--;
  }

  while (!isEmptyStack(*sPtr)) {
    char top = peek(*sPtr);
    pop(sPtr);
    push(preS,top);
  }

  while (!isEmptyStack(*preS)) {
    char top = peek(*preS);
    pop(preS);
    *prefix++ = top;
  }
}
