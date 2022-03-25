# Texting on portable devices has developed a set of abbreviations due to the necessary brevity of text 
# messages. Create a dictionary of texting abbreviations and use it to write functions that can translate 
# to and from English. Of course, your dictionary cannot be complete. For example: “y r u l8?” 
# translates to “Why are you late?”

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