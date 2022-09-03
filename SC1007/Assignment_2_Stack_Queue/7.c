int numMountainPairs(CDblLinkedList CDLL)
{
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here
    int result = 0;
    int size = CDLL.size;

    CDblListNode* curr = CDLL.head;
    for (int i = 0; i<size; i++) {
        CDblListNode* loop = curr;
        int start = loop->item;
        int max = 0;
        int chosen[size];
        for (int j = 0; j<size; j++) {
            chosen[j] = 0;
        }
        for (int j = 0; j < size-i-1; j++) { // forward pass
            loop = loop->next;
            int end = loop->item;
            int min = start < end ? start : end;
            if (min >= max) {
                chosen[j] = 1;
                result++;
            }
            max = end > max ? end : max;
        }

        loop = curr;
        max = 0;
        for (int j = 0; j<i; j++) {
            loop = loop->pre;
            int end = loop->item;
            max = end > max ? end : max;
        }
        for (int j = 0; j< size-i-1; j++) {
            loop = loop->pre;
            int end = loop->item;
            int min = start < end ? start : end;
            if (min >= max && chosen[size-j-i-2] != 1) {
                result++;
            }
            max = end > max ? end : max;
        } // backward pass
        curr = curr->next;
    }

    return result;
}
