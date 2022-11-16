#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    char* item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
} Stack;

void push(Stack *sPtr, char* item);
int pop(Stack *sPtr);
char* peek(Stack s);
int isEmptyStack(Stack s);

void post2In(char*, char*);

int main()
{
  char infix[SIZE];
  char postfix[SIZE];

  printf("Enter an postfix expression:\n");
  scanf("%[^\n]%*c",postfix);

  post2In(postfix,infix);
  printf("The infix expression is \n");
  printf("%s\n",infix);
  return 0;
}

void push(Stack *sPtr, char* item){
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

char* peek(Stack s){
  return s.head->item;
}

int isEmptyStack(Stack s){
  if(s.size == 0) return 1;
  else return 0;
}

void post2In(char* postfix, char* infix) {
  Stack s;
  s.head = NULL;
  s.size = 0;
  Stack* sPtr = &s;
  
  for (int i = 0; i<3; i++) {
    char curr = *postfix;
    if (isalnum(curr)) {
      char* currString = (char*)malloc(sizeof(char) * 10);
      currString[0] = curr;
      push(sPtr, currString);
    } else {
      char* first = peek(*sPtr);
      pop(sPtr);
      // char* second = peek(*sPtr);
      // pop(sPtr);

      printf("%s", first);

      // char* finalString = (char*)malloc(sizeof(char) * 10);
      // char* finalStringStart = finalString;
      // while (*first) {
      //   *finalString++ = *first++;
      // }
      // *finalString++ = curr;
      // while (*second) {
      //   *finalString++ = *second++;
      // }
      // *finalString = '\0';
      // push(sPtr, finalStringStart);
    }
    postfix++;
  }

  char* infixStackString = peek(*sPtr);
  while (*infixStackString) {
    *infix++ = *infixStackString++;
  }
}
