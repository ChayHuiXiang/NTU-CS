abbreviations = {'y':'why','r':'are','u':'you','l8':'late'}

textInput = input('Enter text message: ')
textOutput = ''
for word in textInput.split():
    try:
        newWord = abbreviations[word]
    except:
        newWord = word
    textOutput += f'{newWord}'
    
print(textOutput)