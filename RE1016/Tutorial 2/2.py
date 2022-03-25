negative = True
while negative:
    try:
        number = int(input('Please key in a number: '))
        if number > 0:
            negative = False
        print(abs(number))
    except:
        print('Invalid number!')