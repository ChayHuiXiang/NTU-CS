import math
import random
import time

def extractCheapest(pq):
  cheapest = -1
  weight = math.inf
  cheapestIndex = 0
  index = 0
  for i in pq:
    if i[0] < weight:
      cheapest = i[1]
      cheapestIndex = index
    index += 1
  
  pq.pop(cheapestIndex)
  return (weight, cheapest)
    
# Edit to add in array priority queue implementation
def dijkstra(graph, start):
  V = len(graph)
  d = [math.inf for i in range(V)]
  pi = [None for i in range(V)]
  visited = [False for i in range(V)]
  d[start] = 0

  pq = [(0, start)]
  while len(pq):
    (weight, curr) = extractCheapest(pq)
    if visited[curr] == True:
      continue
    visited[curr] = True
    startingMat = graph[curr]
    for i in range(V):
      node = startingMat[i]
      dist_from_start = node + d[curr]
      if node > 0 and dist_from_start < d[i]:
        d[i] = dist_from_start
        pi[i] = curr
        pq.append((dist_from_start, i))

  return d, pi

def randomiseGraph(graph, V, E):
  while E > 0:
    row = random.randint(0, V-1)
    col = random.randint(0, V-1)
    weight = random.randint(1, 10)
    if row == col:
      continue
    if graph[row][col] == 0:
      graph[row][col] = weight
      E -= 1

if __name__ == "__main__":

  # # -----
  # # adjacency matrix with weights
  # # eg.
  # graph = [
  #   [0, 10, 0, 5, 0],
  #   [0, 0, 1, 2, 0],
  #   [0, 0, 0, 0, 4],
  #   [0, 3, 9, 0, 2],
  #   [7, 0, 6, 0, 0]
  # ]
  # # -----


  # Comment the block below and uncomment the block above to input your own graph
  # -----
  V = int(input("Enter number of vertices (V): "))
  E = int(input("Enter number of edges (E): "))
  graph = [[0 for i in range(V)] for i in range(V)]
  randomiseGraph(graph, V, E)
  # -----

  print("Graph: ")
  print(graph)
  print()

  start = time.time()
  [d, pi] = dijkstra(graph, 0)
  end = time.time()
  print(f"d array: {d}")
  print(f"pi array: {pi}")
  print(f"Time taken in seconds: {end - start}")
