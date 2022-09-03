#include <ctype.h>
#include <math.h>

int precedence(char character) {
    if (character == '+' || character == '-') {
        return 0;
    } else {
        return 1;
    }
}

int higherPrecedence(char first, char second) {
    int firstPrecedence = precedence(first);
    int secondPrecedence = precedence(second);
    return firstPrecedence < secondPrecedence;
}

void in2PreLL(char* infix, LinkedList *inExpLL)
{
    //Write your code here
    Stack stack;
    stack.head = NULL;
    stack.size = 0;
    Stack* sPtr = &stack;
    
    while (*infix) {
        infix++;
    }
    infix--;

    int number = 0;
    int count = -1;
    while (*infix) {
        char character = *infix;
        if (isdigit(character)) {
            count++;
            int digit = character - '0';
            number += (digit * pow(10, count));
        } else {
            if (count != -1) {
                insertNode(inExpLL, number, OPERAND);
                count = -1;
                number = 0;
            }
            if (character == ')') {
                push(sPtr, character);
            } else if (character == '(') {
                while (peek(*sPtr) != ')') {
                    char opt = peek(*sPtr);
                    pop(sPtr);
                    insertNode(inExpLL, opt, OPT);
                }
                pop(sPtr);
            } else {
                while (!isEmptyStack(*sPtr) && peek(*sPtr) != ')' && higherPrecedence(character, peek(*sPtr))) {
                    char opt = peek(*sPtr);
                    pop(sPtr);
                    insertNode(inExpLL, opt, OPT);
                }
                push(sPtr, character);
            }
        }
        infix--;
    }
    if (count != -1) {
        insertNode(inExpLL, number, OPERAND);
    }
    while (!isEmptyStack(*sPtr)) {
        char opt = peek(*sPtr);
        pop(sPtr);
        insertNode(inExpLL, opt, OPT);
    }
}
