# Q1

Conduct binary search on the array.

Pseudocode:
```
min = arr[start]
while start != end:
  mid = (start + end) // 2
  if arr[mid] < arr[start]: // in the case of 5 6 0 1 2 3 4, search leftwards
    end = mid - 1
  else: // in the case of 3 4 5 6 0 1 2, search rightwards
    start = mid + 1

return min
```
