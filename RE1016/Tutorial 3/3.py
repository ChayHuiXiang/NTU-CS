# Write a function that takes as input a string that stores date and time (24-hour clock) in the following 
# format:
# “MM/DD/YYYY HR:MIN:SEC” and prints the following:
# • DD/MM/YYYY
# • HR:MIN:SEC
# • MM/YYYY
# • Whether the time is “AM” or “PM”.
# Validation of the input in the function is necessary. For example, if the user gives an input of 
# “122/04/1990 13:12:12”, the given string is invalid, as there can be only 12 months in a year. Think 
# of all possible erroneous inputs and write code to handle them. The function does not return anything

## NON CHEATY SOLUTION ##
datetime = input('Please enter date and time in the format MM/DD/YYYY HR:MIN:SEC: ')
month, date, year = [int(i) for i in datetime.split()[0].split('/')]
hour, minute, second = [int(i) for i in datetime.split()[1].split(':')]

# positive number
if month < 0 or date < 0 or year < 0 or hour < 0 or minute < 0 or second < 0:
    print('Invalid datetime string!')
elif month > 12 or date > 31 or year > 9999 or hour > 23 or minute > 59 or second > 59:
    print('Invalid datetime string!')
else:
    print(f'{date}/{month}/{year}')
    print(f'{hour}:{minute}:{second}')
    print(f'{month}/{year}')
    if hour < 12:
        print('AM')
    else: 
        print('PM')

## CHEATY DATETIME SOLUTION ##
from datetime import datetime
input = input('Please enter date and time in the format MM/DD/YYYY HR:MIN:SEC: ')
month, date, year = [int(i) for i in input.split()[0].split('/')]
hour, minute, second = [int(i) for i in input.split()[1].split(':')]
try:
    datetime.strptime(input, "%m/%d/%Y %H:%M:%S")
    print(f'{date}/{month}/{year}')
    print(f'{hour}:{minute}:{second}')
    print(f'{month}/{year}')
    if hour < 12:
        print('AM')
    else: 
        print('PM')
except:
    print('Invalid datetime string!')


dict = {"test":["test","test","test","test","test","test","test","test","test"]}