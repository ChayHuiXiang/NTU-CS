number = input('Number: ')
number = int(number)
hours = number/3600
remainder = number%3600

minutes = remainder/60
seconds = remainder%60

print(f'Hours: {hours}, Minutes: {minutes}, Seconds: {seconds}')