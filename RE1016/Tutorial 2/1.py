# Write a program that prints all the leap years from 1900 to 2020 (inclusive).
# Hint: A leap year in the Gregorian calendar system is a year that is divisible by 4 but not by 100, 
# unless it is also divisible by 400.

for i in range(1900,2021,4):
    if i%100 != 0 or i%400 == 0:
        print(i)