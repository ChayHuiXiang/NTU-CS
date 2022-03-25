data = []
with open('credit.txt','r') as fhand:
    for line in fhand:
        stripped_line = line.strip()
        name = stripped_line.split()[0]
        cards = stripped_line.split()[1].split(',')
        data.append([name, cards])
        print(data)
    nameInput = input('Please enter name: ')
    for element in data:
        if element[0] == nameInput:
            print(element)
