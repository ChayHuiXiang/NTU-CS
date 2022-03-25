# Jacob has been passing notes in class without a problem until his teacher intercepted one today. In 
# order to prevent future embarrassment, he wants a way to encode his notes so his teacher cannot 
# read them. Help him by writing a program that encrypts a string by switching every letter with 
# alphabetical position i with the letter with alphabetical position 26-i. It should be letter ‘m’ = 12
# becomes the letter ‘o’ = 14.
# Hint: string module will be useful.

import string

stringy = input('Please key in a string: ')
new_stringy = ''

ascii = string.ascii_lowercase

for char in stringy:
    i = ascii.find(char)+1
    newIndex = 26 - i
    new_stringy = new_stringy + ascii[newIndex]

print(new_stringy)