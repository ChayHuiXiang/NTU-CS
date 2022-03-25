import random
sum = count = 0
while sum <= 1000 and count < 100:
    sum += random.randint(1,20)
    count += 1
    print(sum)