class WQUPC:
  def __init__(self, nodesNum):
    self.sz = [0 for i in range(nodesNum)]
    self.id = [i for i in range(nodesNum)]

  def find(self, node):
    while node != self.id(node):
      self.id[node] = self.id[self.id[node]]
      node = self.id(node)
    return node
  
  def union(self, node1, node2):
    id1 = self.find(node1)
    id2 = self.find(node2)

    size1 = self.sz[id1]
    size2 = self.sz[id2]

    if size1 >= size2: # Add tree 2 to tree 1
      self.sz[id1] += size2
      self.id[id2] = id1
    else:
      self.sz[id2] += size1
      self.id[id1] = id2
    
if __name__ == "__main__":
  wqupc = WQUPC(5)
  print(wqupc.find(0))
  print(wqupc.find(4))

  wqupc.union(0, 4)
  print(wqupc.find(0))
  print(wqupc.find(4))

  wqupc.union(1, 3)
  wqupc.union(0, 1)
  print(wqupc.find(3))
  print(wqupc.find(1))


