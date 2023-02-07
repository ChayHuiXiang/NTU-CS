arr = [3, 1, 2, 9, 8, 4]
H = []

def is_leaf(H, node):
  return node * 2 > len(H)

def fixHeap(H, node, k):
  root = node
  left = root * 2
  while left <= len(H):
    if left < len(H) and H[left-1] < H[left]: left += 1
    if (k >= H[left - 1]): break
    H[root-1] = H[left-1]
    root = left
    left = left * 2
  H[root - 1] = k
  return H

def heapifying(H, node):
  if not is_leaf(H, node):
    H = heapifying(H, node * 2)
    H = heapifying(H, node * 2 + 1)
    k = H[node-1]
    H = fixHeap(H, node, k)
  return H

def constructHeap(arr):
  H = heapifying(arr, 1)
  return H


H = constructHeap(arr)
print(H)
