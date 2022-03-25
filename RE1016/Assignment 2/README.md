# RE1016 Assignment 2

## Section 1: Project Overview and Description
The assignment / project requires us to design a Python Program that recommends a canteen in NTU based on 3 different search criteria (keyword-based search, price-based search, location-based search). An excel fileof information regarding NTU canteens and shops has already been provided. As a starting point, the given Python template already pre-processes the canteens.xlsx excel file, and returns the user a dictionary of information regarding NTU canteens and shops. Our job is to then utilise this dictionary, to then achieve the desired search functionality.

## Section 2: Files within the folder
assignment_solution.py - holds the completed Python code
assignment_template.py - holds the initial Python code given
canteens.xlsx - the excel file of the information regarding NTU canteens and shops
NTUcampus.jpg - the image file containing the NTU map for user input for location-based search
pin.png - the image file of the pin for location-based search
README.md - current file containing all information regarding the project

## Section 3: Key Functionality
1. display data

The display data feature will display a Python dictionary of the pre-processed data from the canteens.xlsx excel file.

2. keyword-based search

The various shops in the canteens.xlsx excel file are associated with keywords such as Chinese, Spicy etc that describe the characteristics of the foods sold at the shops. With the Python Program, users are able to input keywords into the program, and the program will automatically output shops associated with the keywords. On top of this, users are able to input multiple keywords into the program, and chain these keywords with 'and' and 'or' operators. For example,'spicy or chinese' will return all shops that sell either spicy, or chinese foods, or both, while 'spicy and chinese' will return all shops that sell both spicy and chinese foods. 

3. price-based search

The price-based search is a more refined version of the keyword-based search, as it enables users to enter the maximum price of shops that they want to search for. Users will first key in the keywords of the shops that they are looking for, followed by a maximum price. The Python program will automatically output all shops that both match the inputted keywords, and are within the maximum price set by the user. If the maximum price set by the user is too low, the program will automatically output the shop with price closest to the maximum price set by the user.

4. location-based search

The location-based search recommends the nearest canteen for two users, A and B. When the location-based search feature is selected, the Python program will automatically start-up a pygame sequence of the NTU campus map. The user will then select the location of users A and B using the pin. Following which, the user will be prompted to key in the number of closest canteens that they want displayed. The python program will then output the closest canteens from the midpoint of users A and B. The number of closest canteens outputted will depend on the user input.

5. exit program

The Python program will be terminated upon selection of this feature.