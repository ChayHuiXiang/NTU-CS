# Write a short program that will:
# • prompt the user for a number
# • print the absolute value of the number if it is not a positive number
# • prompt the user for another number if the input was not positive
# Hint: math module will be useful.

negative = True
while negative:
    try:
        number = int(input('Please key in a number: '))
        if number > 0:
            negative = False
        print(abs(number))
    except:
        print('Invalid number!')