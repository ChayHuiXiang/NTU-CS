# In certain chat programs or messaging applications, there is a limit on the number of characters that 
# you can send in a message. Write a function that takes as input the message (a string) and checks 
# whether the number of characters is less than 160 (or not). If the length of the message is less than 
# 160, the message should be returned. If the length of the message is greater than 160, a string 
# consisting of only the first 160 characters should be returned.
# How would you check if the restriction is on number of words rather than characters? Write a 
# function that allows a message with only 20 words.

#### CHARACTER CHECKER ####
message = input('Please enter a string: ')
if len(message) <= 160:
    print(message)
else:
    print(message[:160])

#### WORD CHECKER ####
message = input('Please enter a string: ')
stringList = message.split()
print(stringList)
if len(stringList) <= 20:
    print(message)
else:
    print(" ".join(stringList[:20]))