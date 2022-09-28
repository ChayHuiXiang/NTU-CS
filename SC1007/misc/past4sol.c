#include <stdlib.h>
#include <stdio.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;
typedef ListNode StackNode;
typedef ListNode QueueNode;

typedef struct _linkedlist{
   int size;
   StackNode *head;
} LinkedList, Stack;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

//Prototypes of Interface functions for Stack structure
void push(Stack *sPtr, int item);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void deleteStack(Stack *sPtr);

//Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void deleteQueue(Queue *qPtr);

void reverseFirstKItems(Queue *qPtr, int k);

//For practice purpose here, I just use it for an easy access to a queue
//to print out all the elements.
//It is noted that it is not a very correct approach
void printQueue(Queue q);
void interqueue(Queue* qPtr);

int main()
{
  Queue q;
  q.head = NULL;
  q.tail = NULL;
  q.size = 0;

  int item;
  int K;

  printf("Enter a list of numbers, terminated by any non-digit character: \n");
  while(scanf("%d",&item))
      enqueue(&q,item);
  scanf("%*s");

  interqueue(&q);
  printQueue(q);

  return 1;
}


void printQueue(Queue q){
  QueueNode *cur = q.head;
  printf("Current List has %d elements: ",q.size);

  while (cur != NULL){
      printf("%d ", cur->item);
      cur = cur->next;
  }
  printf("\n");
}

void push(Stack *sPtr, int item){
  StackNode *newNode;
  newNode= (StackNode *)malloc(sizeof(StackNode));
  newNode->item = item;
  newNode->next = sPtr->head;
  sPtr->head = newNode;
  sPtr->size++;
}

int pop(Stack *sPtr){
  if(sPtr==NULL || sPtr->head==NULL){
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

int peek(Stack s){
  return s.head->item;
}

int isEmptyStack(Stack s){
  if(s.size==0) return 1;
  else return 0;
}

void deleteStack(Stack *sPtr){
  while(pop(sPtr));
}

void enqueue(Queue *qPtr, int item){
  QueueNode *newNode;
  newNode = malloc(sizeof(QueueNode));
  newNode->item = item;
  newNode->next = NULL;

  if(isEmptyQueue(*qPtr))
      qPtr->head=newNode;
  else
      qPtr->tail->next = newNode;

  qPtr->tail = newNode;
  qPtr->size++;
}

int dequeue(Queue *qPtr){
  if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
      return 0;
  }
  else{
      QueueNode *temp = qPtr->head;
      qPtr->head = qPtr->head->next;
      if(qPtr->head == NULL) //Queue is emptied
          qPtr->tail = NULL;

      free(temp);
      qPtr->size--;
      return 1;
  }
}

int getFront(Queue q){
  return q.head->item;
}

int isEmptyQueue(Queue q){
  if(q.size==0) return 1;
  else return 0;
}
void deleteQueue(Queue *qPtr)
{
  while(dequeue(qPtr));
}

void rotate(Queue* qPtr, int k) {
  for (int i = 0; i<k; i++) {
    int value = getFront(*qPtr);
    dequeue(qPtr);
    enqueue(qPtr, value);
  }
}

void interqueue(Queue* qPtr) {
  int half = (qPtr->size)/2;
  Stack s;
  s.head = NULL;
  s.size = 0;
  Stack* sPtr = &s;

  for (int i = 0; i<half; i++) {
    int front = getFront(*qPtr);
    dequeue(qPtr);
    push(sPtr, front);
  }

  int startingRotations = half - 1;
  rotate(qPtr, startingRotations);

  int top = peek(*sPtr);
  enqueue(qPtr, top);
  pop(sPtr);

  while (!isEmptyStack(*sPtr)) {
    rotate(qPtr, startingRotations);
    int top = peek(*sPtr);
    enqueue(qPtr, top);
    pop(sPtr);
    startingRotations++;
  }

  rotate(qPtr, qPtr->size - 1);
}
