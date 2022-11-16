#include <stdio.h>

#define V 4

int count = 0;

int isSafe(int graph[V][V], int color[], int v, int desiredColor) {
  for (int j = 0; j<V; j++) {
      if (graph[v][j] == 1 && color[j] == desiredColor) {
        return 0;
      }
  }

  return 1;
}

void graphColoring(int graph[V][V], int m, int color[], int v) {
  if (v >= V) {
    count++;
    return;
  }

  if (v == 0) {
    color[v] = 1;
    graphColoring(graph, m, color, v+1);
    color[v] = 0;
  } else {
    for (int i = 1; i <= m; i++) {
      if (isSafe(graph, color, v, i)) {
        color[v] = i;
        graphColoring(graph, m, color, v+1);
        color[v] = 0;
      }
    }
  }

  return;
}

int main() {
  int graph[V][V] = {
    { 0, 1, 1, 1 },
    { 1, 0, 1, 0 },
    { 1, 1, 0, 1 },
    { 1, 0, 1, 0 },
  };

  int m = 3;

  int color[V];
  for (int i = 0; i < V; i++) {
    color[i] = 0;
  }

  graphColoring(graph, m, color, 0);
  printf("Count: %d", count);
  return 0;
}
