arr = [0, 1, 4, 2, 3, 5, 8, 7, 6]

def solution(arr):
  arrLength = len(arr)
  if (arrLength == 1):
    return [arr[0], arr[0]]
  elif (arrLength == 2):
    first = arr[0]
    second = arr[1]
    if first < second:
      return [first, second]
    else:
      return [second, first]
  else:
    [lmin, lmax] = solution(arr[:arrLength//2])
    [rmin, rmax] = solution(arr[arrLength//2:])
    return [lmin if lmin < rmin else rmin, lmax if lmax > rmax else rmax]

ans = solution(arr)
print(ans)
