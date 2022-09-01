#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    double item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char*);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    scanf("%[^\n]%*c",postfix);

    printf("The answer is %.2lf.\n",exePostfix(postfix));

    return 0;
}

void push(Stack *sPtr, double item){
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

double peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
    if(s.size == 0) return 1;
    else return 0;
}

double exePostfix(char* postfix)
{
    Stack stack;
    stack.head = NULL;
    stack.size = 0;
    Stack* stackPtr = &stack;

    for (; *postfix; postfix++) {
        char character = *postfix;
        printf("%c\n", character);
        if (isdigit(character)) {
            push(stackPtr, strtod(&character, NULL));
        } else {
            double digit1 = peek(*stackPtr);
            pop(stackPtr);
            double digit2 = peek(*stackPtr);
            pop(stackPtr);
            printf("%lf %lf\n", digit1, digit2);
            double result;
            switch (character) {
                case '*':
                    result = digit2 * digit1;
                    break;

                case '/':
                    result = digit2 / digit1;
                    break;

                case '+':
                    result = digit2 + digit1;
                    break;

                case '-':
                    result = digit2 - digit1;
                    break;
                
                default:
                    break;
            }
            push(stackPtr, result);
        }
    }

    return peek(*stackPtr);


}
