import random
SORT_THRESHOLD = 10

def merge(left, right, count):
  sorted_arr = []
  left_pointer = 0
  right_pointer = 0
  left_len = len(left)
  right_len = len(right)

  while left_pointer < left_len and right_pointer < right_len:
    left_item = left[left_pointer]
    right_item = right[right_pointer]
    count += 1
    if left_item <= right_item:
      sorted_arr.append(left_item)
      left_pointer += 1
    else:
      sorted_arr.append(right_item)
      right_pointer += 1

  sorted_arr.extend(left[left_pointer:left_len])
  sorted_arr.extend(right[right_pointer:right_len])
  return sorted_arr, count

def hybridsort(arr):
  length = len(arr)
  if length <= SORT_THRESHOLD:
    return insertionsort(arr)

  mid = length // 2
  left, leftCount = hybridsort(arr[:mid])
  right, rightCount = hybridsort(arr[mid:])
  
  return merge(left, right, leftCount + rightCount)

def insertionsort(arr):
  count = 0
  length = len(arr)
  for i in range(1, length):
    for j in range(i, 0, -1):
      count += 1
      if arr[j] < arr[j-1]:
        arr[j], arr[j-1] = arr[j-1], arr[j]
      else:
        break
  return arr, count

def mergesort(arr):
  length = len(arr)
  if length == 1:
    return arr, 0
  mid = length // 2
  left, leftCount = mergesort(arr[:mid])
  right, rightCount = mergesort(arr[mid:])
  return merge(left, right, leftCount + rightCount)

if __name__ == "__main__":
  START = 1000
  END = 10000000
  while START <= END:
    arr = []
    for i in range(START):
      arr.append(random.randint(0, START))

    answer, count = mergesort(arr)
    START *= 10
    print(f"n: {START}, count: {count}")
