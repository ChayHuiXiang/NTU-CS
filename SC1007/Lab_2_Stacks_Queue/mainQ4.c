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

int higherPrecedence(char first, char second) {
    if (second == '+' || second == '-') {
        return 1;
    } else {
        return 0;
    }
}

void in2Post(char* infix, char* postfix) {
    //Write your code here

    char* dummy = postfix;

    Stack stack;
    stack.head = NULL;
    stack.size = 0;
    Stack* stackPtr = &stack;

    for (;*infix;infix++) {
        char character = *infix;
        if (isdigit(character)) {
            printf("%s %c\n", postfix, character);
            *postfix++ = character;
            printf("%s %c\n", postfix, character);
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
            while (!isEmptyStack(*stackPtr) && peek(*stackPtr) != '(' && higherPrecedence(peek(*stackPtr), character)) {
                char operator = peek(*stackPtr);
                printf("%c", operator);
                pop(stackPtr);
                *postfix++ = operator;
            }
            push(stackPtr, character);
        }
    }

    while (!isEmptyStack(*stackPtr)) {
        char operator = peek(*stackPtr);
        pop(stackPtr);
        *postfix++ = operator;
    }
    *postfix = '\0';
}
