#include <stdio.h>
#include <stdlib.h>

typedef struct _graph {
  int V;
  int E;
  int* visited;
  int** matrix;
} Graph;

typedef struct _listNode {
  int vertice;
  struct _listNode* next;
} QueueNode;

typedef struct _queue {
  QueueNode* head;
  QueueNode* tail;
  int size;
} Queue;

int isSafe(Graph g, int[], int, int);
int getFront(Queue);
void dequeue(Queue*);
int isEmptyQueue(Queue);
void enqueue(Queue*, int);
int nodeUnvisited(Graph);

int bfsColouring(Graph, int[], int);

int main() {
  Graph g;
  g.E = 0;
  g.V = 0;

  printf("Enter the number of vertices: ");
  scanf("%d", &g.V);
  int* visitedArr = (int*)malloc(sizeof(int) * g.V);
  int** matrix = (int**)malloc(sizeof(int*) * g.V);

  for (int i = 0; i<g.V; i++) {
    matrix[i] = (int*)malloc(sizeof(int)*g.V);
    for (int j = 0; j<g.V; j++) {
      matrix[i][j] = 0;
    }
  }

  g.visited = visitedArr;
  g.matrix = matrix;

  int v1, v2;
  printf("Enter a pair of connected vertices: ");
  while (scanf("%d %d", &v1, &v2) == 2) {
    if (v1 > 0 && v1 <= g.V && v2 > 0 && v2 <= g.V) {
      g.matrix[v1-1][v2-1] = 1;
      g.matrix[v2-1][v1-1] = 1;
      g.E++;
    } else {
      break;
    }
  }
  scanf("%*c");

  int m;
  int color[g.V];

  printf("Enter the number of colours: ");
  scanf("%d", &m);

  int result = bfsColouring(g, color, m);
  if (result) {
    for (int i = 0; i<g.V; i++) {
      printf("%d ", color[i]);
    }
  } else {
    printf("Result not found");
  }
}

int isEmptyQueue(Queue q) {
  if (q.size == 0) {
    return 1;
  } else {
    return 0;
  }
}

int getFront(Queue q) {
  if (isEmptyQueue(q)) {
    return -1;
  } else {
    return (q.head)->vertice;
  }
}

void enqueue(Queue* qPtr, int v) {
  QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
  newNode->vertice = v;
  newNode->next = NULL;

  if (isEmptyQueue(*qPtr)) {
    qPtr->head = newNode;
  } else {
    QueueNode* tail = qPtr->tail;
    tail->next = newNode;
  }
  qPtr->tail = newNode;
  qPtr->size++;
}

void dequeue(Queue* qPtr) {
  if (isEmptyQueue(*qPtr)) {
    return;
  } else {
    qPtr->head = qPtr->head->next;
    if (qPtr->head == NULL) {
      qPtr->tail = NULL;
    }
    (qPtr->size)--;
  }
}

int isSafe(Graph g, int color[], int c, int v) {
  int* list = g.matrix[v-1];
  for (int i = 0; i<g.V; i++) {
    if (list[i] == 1 && color[i] == c) {
      return 0;
    }
  }
  return 1;
}

int nodeUnvisited(Graph g) {
  for (int i = 0; i<g.V; i++) {
    if (g.visited[i] == 0) {
      return i;
    }
  }
  return -1;
}

int bfsColouring(Graph g, int color[], int m) {

  for (int i = 0; i<g.V; i++) {
    color[i] = 1;
  }
  int unvisitedNode = nodeUnvisited(g);
  while (unvisitedNode != -1) {
    Queue q;
    Queue* qPtr = &q;
    qPtr->size = 0;
    
    enqueue(qPtr, unvisitedNode);
    g.visited[unvisitedNode] = 1;

    while (!isEmptyQueue(q)) {
      int index = getFront(q);
      dequeue(qPtr);
      int indexColor = color[index];

      for (int i = 0; i<g.V; i++) {
        if (g.matrix[index][i] == 1) {
          if (indexColor == color[i]) {
            color[i]++;
            if (color[i] > m) {
              return 0;
            }
          }

          if (g.visited[i] == 0) {
            g.visited[i] = 1;
            enqueue(qPtr, i);
          }
        }
      }
    }
    unvisitedNode = nodeUnvisited(g);
  }

  return 1;
}
