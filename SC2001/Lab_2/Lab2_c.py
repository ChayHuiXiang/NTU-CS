import math
import heapq
import random
import csv
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

def mat_dijkstra(graph, start):
  V = len(graph)
  d = [math.inf for i in range(V)]
  pi = [None for i in range(V)]
  visited = [False for i in range(V)]
  pq = []
  if V > 0:
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

def dijkstra(graph, start):
  V = len(graph)
  d = [math.inf for i in range(V)]
  pi = [None for i in range(V)]
  visited = [False for i in range(V)]
  pq = []
  if V > 0:
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
    if row == col:
      continue
    if graph[row][col] == 0:
      graph[row][col] = weight
      E -= 1

def randomiseSparseGraph(graph, V):
  for i in range(V):
    row = i
    col = (i + 1) % V
    weight = random.randint(1, 10)
    if graph[row][col] == 0:
      graph[row][col] = weight

def randomiseConnectedGraph(graph, V):
  for row in range(V):
    for col in range(V):
      weight = random.randint(1, 10)
      if row == col:
        continue
      graph[row][col] = weight

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
  
  header = ["V", "E", "time"]
  f = open("data_c2.csv", "w")
  writer = csv.writer(f)
  writer.writerow(header)

  V = 0
  while V <= 100:
    # E = V # For sparse graphs
    E = (V-1) * (V-1) # For dense graphs

    graph = [[0 for i in range(V)] for i in range(V)]
    # randomiseSparseGraph(graph, V) # For sparse graphs
    randomiseConnectedGraph(graph, V) # For dense graphs
    # graph = convertList(graph, V) # Convert adjacency matrix to adj list

    start = time.time()
    [d, pi] = mat_dijkstra(graph, 0)
    # [d, pi] = dijkstra(graph, 0)
    end = time.time()

    print(f"Time taken in seconds for V = {V} and E = {E}: {end - start}")
    writer.writerow([V, E, end-start])

    V += 1

  f.close()

