
def dp(weights, profits, C, n):

  # Initialise DP Table
  table = [0 for i in range(C + 1)]

  # Fill up table from bottom-up by capacity
  for i in range(1, C + 1):

    # maxProfit refers to the max profit at current capacity
    maxProfit = 0
    for j in range(n):
      profit = table[i - weights[j]] + profits[j] if i - weights[j] >= 0 else 0
      maxProfit = max(profit, maxProfit)

    # Set the entry in the table to the max profit at current capacity
    table[i] = maxProfit

  return table[C]

if __name__ == "__main__":

  # 4(a) parameters
  weights1 = [4, 6, 8]
  profits1 = [7, 6, 9]
  n1 = len(weights1)

  capacity1 = 14

  result = dp(weights1, profits1, capacity1, n1)
  print()
  print(f"Result of 4a: {result}")
  print()

  # 4(b) parameters
  weights2 = [5, 6, 8]
  profits2 = [7, 6, 9]
  n2 = len(weights2)

  capacity2 = 14

  result = dp(weights2, profits2, capacity2, n2)
  print(f"Result of 4b: {result}")
  print()
