        queue = *queuePtr;
        stack = *stackPtr;
        char queueItem = getFront(queue);
        char stackItem = peek(stack);
        if (stackItem != queueItem) {
            return 0;
        }