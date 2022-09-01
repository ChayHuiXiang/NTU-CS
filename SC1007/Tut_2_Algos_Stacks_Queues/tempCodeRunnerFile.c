      if (character == '&' || character == '<' || character == '>') infix++;
      while (peek(*stackPtr) != '(' && !isEmptyStack(*stackPtr) && higherPrecedence(peek(*stackPtr), character)) {
        char operator = peek(*stackPtr);
        pop(stackPtr);
        if (operator == '&' || operator == '<' || operator == '>') {
          *postfix++ = operator;
        }
        *postfix++ = operator;
      }