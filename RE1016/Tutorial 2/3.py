# Write a program that continually generates and sums up random numbers between 1 and 20 and 
# stops when the sum exceeds 1000. Stop early if more than 100 numbers have been generated.
# Hint: random module will be useful

import random
sum = count = 0
while sum <= 1000 and count < 100:
    sum += random.randint(1,20)
    count += 1
    print(sum)