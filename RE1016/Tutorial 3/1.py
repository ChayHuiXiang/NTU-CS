import string

stringy = input('Please key in a string: ')
new_stringy = ''

ascii = string.ascii_lowercase

for char in stringy:
    i = ascii.find(char)+1
    newIndex = 26 - i
    new_stringy = new_stringy + ascii[newIndex]

print(new_stringy)