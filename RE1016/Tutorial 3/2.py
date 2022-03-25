# message = input('Please enter a string: ')
# if len(message) <= 160:
#     print(message)
# else:
#     print(message[:160])

#### WORD CHECKER ####
message = input('Please enter a string: ')
stringList = message.split()
print(stringList)
if len(stringList) <= 20:
    print(message)
else:
    print(" ".join(stringList[:20]))