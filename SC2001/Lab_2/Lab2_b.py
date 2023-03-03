import math
import heapq
import random

def dijkstra(graph, start):
  V = len(graph)
  d = [math.inf for i in range(V)]
  pi = [None for i in range(V)]
  visited = [False for i in range(V)]
  pq = [(0, start)]
  d[start] = 0

  while len(pq):
    (dist, curr) = heapq.heappop(pq)
    if visited[curr] == True:
      continue
    visited[curr] = True
    adjList = graph[curr]
    for (v, weight) in adjList:
      dist_from_start = weight + d[curr]
      if dist_from_start < d[v]:
        d[v] = dist_from_start
        pi[v] = curr
        heapq.heappush(pq, (dist_from_start, v))

  return d, pi

def randomiseGraph(graph, V, E):
  while E > 0:
    row = random.randint(0, V-1)
    col = random.randint(0, V-1)
    weight = random.randint(1, 10)
    graph[row][col] = weight
    E -= 1

def convertList(graph, V):
  result = {}
  for i in range(V):
    result[i] = []
  for row in range(V):
    for col in range(V):
      weight = graph[row][col]
      if weight > 0:
        result[row].append((col, weight))

  return result


if __name__ == "__main__":

  # # -----
  # # adjacency list is in the format (vertice, weight)
  # # eg. 
  # graph = {
  #   0: [(1, 10), (3, 5)],
  #   1: [(3, 2), (2, 1)],
  #   2: [(4, 4)],
  #   3: [(1, 3), (2, 9), (4, 2)],
  #   4: [(0, 7), (2, 6)]
  # }
  # # -----
  
  # Comment the block below and uncomment the block above to input your own graph
  # -----
  V = int(input("Enter number of vertices (V): "))
  E = int(input("Enter number of edges (E): "))
  graph = [[0 for i in range(V)] for i in range(V)]
  randomiseGraph(graph, V, E)
  graph = convertList(graph, V)
  # -----

  print("Graph: ")
  print(graph)
  print()

  [d, pi] = dijkstra(graph, 0)
  print(f"d array: {d}")
  print(f"pi array: {pi}")
