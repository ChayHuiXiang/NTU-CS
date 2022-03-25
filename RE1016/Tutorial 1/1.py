# A day has 86,400 secs (24*60*60). Given a number in the range 1 – 86,400, output the current time 
# as hours, minutes, and seconds with a 24-hour clock. For example, 70,000 sec is 19 hours, 26 minutes, 
# and 40 seconds.

number = input('Number: ')
number = int(number)
hours = number/3600
remainder = number%3600

minutes = remainder/60
seconds = remainder%60

print(f'Hours: {hours}, Minutes: {minutes}, Seconds: {seconds}')