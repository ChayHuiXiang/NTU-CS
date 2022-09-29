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

void in2Post(char*, char*);

int main()
{
  char infix[SIZE];
  char postfix[SIZE];

  printf("Enter an infix expression:\n");
  scanf("%[^\n]%*c",infix);

  in2Post(infix,postfix);
  printf("The postfix expression is \n");
  printf("%s\n",postfix);
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
  if (operator1 == '(') {
    return 0;
  }
  if ((operator2 == '*' || operator2 == '/') && (operator1 == '+' || operator1 == '-')) {
    return 0;
  }
  return 1;
}

void in2Post(char* infix, char* postfix) {
  Stack s;
  s.head = NULL;
  s.size = 0;
  Stack* sPtr = &s;

  while (*infix) {
    char curr = *infix;
    if (curr == '(') {
      push(sPtr, curr);
    } else if (isalnum(curr)) {
      *postfix++ = curr;
    } else if (curr == ')') {
      // for (int i = 0; i<2; i++) {
      //   char top = peek(*sPtr);
      //   pop(sPtr);
      //   *postfix++ = top;
      // }
      while (peek(*sPtr) != '(') {
        char top = peek(*sPtr);
        pop(sPtr);
        *postfix++ = top;
      }
      pop(sPtr);
    } else {
      while (!isEmptyStack(*sPtr) && higherPrecedence(peek(*sPtr), curr)) {
        char operator = peek(*sPtr);
        pop(sPtr);
        *postfix++ = operator;
      }
      push(sPtr, curr);
    }
    infix++;
  }

  while (!isEmptyStack(*sPtr)) {
    char operator = peek(*sPtr);
    pop(sPtr);
    *postfix++ = operator;
  }
  *postfix = '\0';
}
