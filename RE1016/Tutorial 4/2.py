def transpose(listVariable):
    newList = [[None for x in range(len(listVariable))] for x in range(len(listVariable[0]))]
    for rowIndex, row in enumerate(listVariable):
        for columnIndex, column in enumerate(row):
            newList[columnIndex][rowIndex] = column
    return newList

inputList = [['AAA', 'BBB', 'CCC', 'DDD', 'EEE', 'FFF', 'GGG', 'HHH', 'III'],
             ['1', '262', '86', '48', '8', '39', '170', '16', '4'],
             ['1', '56', '84', '362', '33', '82', '296', '40', '3'],
             ['10', '238', '149', '205', '96', '89', '223', '65', '5'],
             ['92', '142', '30', '237', '336', '140', '210', '50', '2']]

print(transpose(inputList))

### FULLY LIST COMPREHENSION SOLUTION ###
def transpose(listVariable):
    return [[x[i] for x in listVariable] for i in range(len(listVariable[0]))]
print(transpose(inputList))