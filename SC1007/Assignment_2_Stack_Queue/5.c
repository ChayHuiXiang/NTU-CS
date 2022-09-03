void expressionQ(char *infix, Queue* qPtr)
{
    int number = -1;
    while (*infix) {
        char character = *infix;
        if (character == '+' || character == '-' || character == '*' || character == '/' || character == '(' || character == '%' || character == ')') {
            if (number != -1) {
                enqueue(qPtr, number, OPERAND);
            }
            enqueue(qPtr, character, OPT);
            number = -1;
        } else {
            int digit = character - '0';
            number = number == -1 ? 0 : number;
            number *= 10;
            number += digit;
        }
        infix++;
    }
    if (number != -1) {
        enqueue(qPtr, number, OPERAND);
    }
// Write your code here
}
