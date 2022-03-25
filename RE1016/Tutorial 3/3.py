# 02/31/2022 23:59:59

# datetime = input('Please enter date and time in the format MM/DD/YYYY HR:MIN:SEC: ')
# month, date, year = [int(i) for i in datetime.split()[0].split('/')]
# hour, minute, second = [int(i) for i in datetime.split()[1].split(':')]

# # positive number
# if month < 0 or date < 0 or year < 0 or hour < 0 or minute < 0 or second < 0:
#     print('Invalid datetime string!')
# elif month > 12 or date > 31 or year > 9999 or hour > 23 or minute > 59 or second > 59:
#     print('Invalid datetime string!')
# else:
#     print(f'{date}/{month}/{year}')
#     print(f'{hour}:{minute}:{second}')
#     print(f'{month}/{year}')
#     if hour < 12:
#         print('AM')
#     else: 
#         print('PM')


## CHEATY DATETIME SOLUTION
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