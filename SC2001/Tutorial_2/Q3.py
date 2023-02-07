arr = [0, 1, 2, 5, 2, 3, 4, 1]

def mergesort(arr):

  mid = len(arr) // 2
  if len(arr) == 1:
    return arr
  if len(arr) == 2:
    first = arr[0]
    second = arr[1]
    return [first, second] if first < second else [second, first]
  else:
    left = mergesort(arr[:mid])
    right = mergesort(arr[mid:])

    leftP, rightP = 0, 0
    leftLen = len(left)
    rightLen = len(right)

    ans = []
    while leftP < leftLen or rightP < rightLen:
      if leftP < leftLen and rightP < rightLen:
        leftItem = left[leftP]
        rightItem = right[rightP]
        if (leftItem < rightItem):
          ans.append(leftItem)
          leftP += 1
        else:
          ans.append(rightItem)
          rightP += 1
      elif leftP < leftLen:
        leftItem = left[leftP]
        ans.append(leftItem)
        leftP += 1
      else:
        rightItem = right[rightP]
        ans.append(rightItem)
        rightP += 1
    
    return ans

ans = mergesort(arr)
print(ans)

