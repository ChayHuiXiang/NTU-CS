#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

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
    newNode = malloc(sizeof(StackNode));
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
    if ((operator1 == '*' || operator1 == '/') && (operator2 == '+' || operator2 == '-')) {
        return 1;
    }
    return 0;
}

void in2Pre(char* infix, char* prefix)
{
    //Write your code here
    Stack s;
    s.head = NULL;
    s.size = 0;
    Stack* sPtr = &s;

    Stack prefixS;
    prefixS.head = NULL;
    prefixS.size = 0;
    Stack* prefixSPtr = &prefixS;

    while (*infix) {
        infix++;
    }
    infix--;

    while (*infix) {
        if (*infix == ')') {
            push(sPtr, ')');
        } else if (isalnum(*infix)) {
            push(prefixSPtr, *infix);
        } else if (*infix == '(') {
            while (peek(*sPtr) != ')') {
                char top = peek(*sPtr);
                pop(sPtr);
                push(prefixSPtr, top);
            }
            pop(sPtr);
        } else {
            while (!isEmptyStack(*sPtr) && higherPrecedence(peek(*sPtr), *infix)) {
                int operator = peek(*sPtr);
                pop(sPtr);
                push(prefixSPtr, operator);
            }
            push(sPtr, *infix);
        }
        infix--;
    }

    while (!isEmptyStack(*sPtr)) {
        char top = peek(*sPtr);
        pop(sPtr);
        push(prefixSPtr, top);
    }

    while (!isEmptyStack(*prefixSPtr)) {
        char top = peek(*prefixSPtr);
        pop(prefixSPtr);
        *prefix++ = top;
    }
    *prefix = '\0';

}
