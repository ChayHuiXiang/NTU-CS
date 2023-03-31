
def dp(weights, profits, n, C):
  # Initialise DP Table
  table = [[0 for i in range(n + 1)] for i in range(C + 1)]

  # Fill up table row by row
  for i in range(C + 1):
    for j in range(1, n + 1):
      weight = weights[j-1]
      profit = profits[j-1]

      # Profits if cj was unused
      unused = table[i][j-1]

      # Profits if cj was used
      used = table[i - weight][j] + profit if i - weight >= 0 else 0

      # Set the entry in the table to the max of unused and used
      table[i][j] = max(unused, used)
  return table[C][n]

if __name__ == "__main__":

  # 4(a) parameters
  weights1 = [4, 6, 8]
  profits1 = [7, 6, 9]
  n1 = len(weights1)
  capacity1 = 14

  result = dp(weights1, profits1, n1, capacity1)
  print()
  print(f"Result of 4a: {result}")
  print()
  # 4(b) parameters
  weights2 = [5, 6, 8]
  profits2 = [7, 6, 9]
  n2 = len(weights2)

  capacity2 = 14

  result = dp(weights2, profits2, n2, capacity2)
  print(f"Result of 4b: {result}")
  print()
