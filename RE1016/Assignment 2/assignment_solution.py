import pygame
from PIL import Image
import time
import pandas as pd
import math

# load dataset for keyword dictionary - provided
def load_stall_keywords(data_location="canteens.xlsx"):
    # get list of canteens and stalls
    canteen_data = pd.read_excel(data_location)
    canteens = canteen_data['Canteen'].unique()
    canteens = sorted(canteens, key=str.lower)

    stalls = canteen_data['Stall'].unique()
    stalls = sorted(stalls, key=str.lower)

    keywords = {}
    for canteen in canteens:
        keywords[canteen] = {}

    copy = canteen_data.copy()
    copy.drop_duplicates(subset="Stall", inplace=True)
    stall_keywords_intermediate = copy.set_index('Stall')['Keywords'].to_dict()
    stall_canteen_intermediate = copy.set_index('Stall')['Canteen'].to_dict()

    for stall in stalls:
        stall_keywords = stall_keywords_intermediate[stall]
        stall_canteen = stall_canteen_intermediate[stall]
        keywords[stall_canteen][stall] = stall_keywords

    return keywords


# load dataset for price dictionary - provided
def load_stall_prices(data_location="canteens.xlsx"):
    # get list of canteens and stalls
    canteen_data = pd.read_excel(data_location)
    canteens = canteen_data['Canteen'].unique()
    canteens = sorted(canteens, key=str.lower)

    stalls = canteen_data['Stall'].unique()
    stalls = sorted(stalls, key=str.lower)

    prices = {}
    for canteen in canteens:
        prices[canteen] = {}

    copy = canteen_data.copy()
    copy.drop_duplicates(subset="Stall", inplace=True)
    stall_prices_intermediate = copy.set_index('Stall')['Price'].to_dict()
    stall_canteen_intermediate = copy.set_index('Stall')['Canteen'].to_dict()

    for stall in stalls:
        stall_price = stall_prices_intermediate[stall]
        stall_canteen = stall_canteen_intermediate[stall]
        prices[stall_canteen][stall] = stall_price

    return prices


# load dataset for location dictionary - provided
def load_canteen_location(data_location="canteens.xlsx"):
    # get list of canteens
    canteen_data = pd.read_excel(data_location)
    canteens = canteen_data['Canteen'].unique()
    canteens = sorted(canteens, key=str.lower)

    # get dictionary of {canteen:[x,y],}
    canteen_locations = {}
    for canteen in canteens:
        copy = canteen_data.copy()
        copy.drop_duplicates(subset="Canteen", inplace=True)
        canteen_locations_intermediate = copy.set_index('Canteen')['Location'].to_dict()
    for canteen in canteens:
        canteen_locations[canteen] = [int(canteen_locations_intermediate[canteen].split(',')[0]),
                                      int(canteen_locations_intermediate[canteen].split(',')[1])]

    return canteen_locations


# get user's location with the use of PyGame - provided
def get_user_location_interface():
    # get image dimensions
    image_location = 'NTUcampus.jpg'
    pin_location = 'pin.png'
    screen_title = "NTU Map"
    image = Image.open(image_location)
    image_width_original, image_height_original = image.size
    scaled_width = int(image_width_original)
    scaled_height = int(image_height_original)
    pinIm = pygame.image.load(pin_location)
    pinIm_scaled = pygame.transform.scale(pinIm, (60, 60))
    # initialize pygame
    pygame.init()
    # set screen height and width to that of the image
    screen = pygame.display.set_mode([scaled_width, scaled_height])
    # set title of screen
    pygame.display.set_caption(screen_title)
    # read image file and rescale it to the window size
    screenIm = pygame.image.load(image_location)

    # add the image over the screen object
    screen.blit(screenIm, (0, 0))
    # will update the contents of the entire display window
    pygame.display.flip()

    # loop for the whole interface remain active
    while True:
        # checking if input detected
        pygame.event.pump()
        event = pygame.event.wait()
        # closing the window
        if event.type == pygame.QUIT:
            pygame.display.quit()
            mouseX_scaled = None
            mouseY_scaled = None
            break
        # resizing the window
        elif event.type == pygame.VIDEORESIZE:
            screen = pygame.display.set_mode(
                event.dict['size'], pygame.HWSURFACE | pygame.DOUBLEBUF | pygame.RESIZABLE)
            screen.blit(pygame.transform.scale(screenIm, event.dict['size']), (0, 0))
            scaled_height = event.dict['h']
            scaled_width = event.dict['w']
            pygame.display.flip()
        # getting coordinate
        elif event.type == pygame.MOUSEBUTTONDOWN:
            # get outputs of Mouseclick event handler
            (mouseX, mouseY) = pygame.mouse.get_pos()
            # paste pin on correct position
            screen.blit(pinIm_scaled, (mouseX - 25, mouseY - 45))
            pygame.display.flip()
            # return coordinates to original scale
            mouseX_scaled = int(mouseX * 1281 / scaled_width)
            mouseY_scaled = int(mouseY * 1550 / scaled_height)
            # delay to prevent message box from dropping down
            time.sleep(0.2)
            break

    pygame.quit()
    pygame.init()
    return mouseX_scaled, mouseY_scaled

# Keyword-based Search Function - to be implemented
def search_by_keyword(keywords):

    keywords_list = keywords.split()
    keywords_list = [keyword.capitalize() for keyword in keywords_list]
    output, total_matches, error = get_keyword_output(keywords_list)

    if error: return True
    if display_output(output, total_matches): return True
    return False
        
# Price-based Search Function - to be implemented
def search_by_price(keywords, max_price):
    
    total_price_matches = 0
    output = []
    
    keywords_list = keywords.split()
    keywords_list = [keyword.capitalize() for keyword in keywords_list]

    try:
        max_price = float(max_price)
    except:
        print("Error: Meal price is not a numerical value. Please try again.")
        return True

    if max_price < 0:
        print("Error: Meal price cannot be a negative number. Please try again.")
        return True

    matches_output, total_keyword_matches, error = get_keyword_output(keywords_list)
    if error: return True

    if total_keyword_matches == 0:
        print("Food Stalls found: No food stall found with input keyword.")
        return True
    
    for entry in matches_output:
        matches_dict, price_matching_no = find_no_price_matches(max_price, list(entry.items())[0])
        total_price_matches += price_matching_no
        output.append(matches_dict)

    if display_output(output, total_price_matches, matches_output): return True
    return False

# Location-based Search Function - to be implemented
def search_nearest_canteens(user_locations, k=1):
    try:
        k = int(k)
    except:
        print("Warning: Non integer value of k detected. Default k = 1 is set.")
        k = 1
    if k < 0:
        k = 1
        print("Warning: k cannot be negative value. Default k = 1 is set.")

    output = []
    for canteen in canteen_locations.items():
        distance = round(math.sqrt(abs(user_locations[0] - canteen[1][0])**2+abs(user_locations[1] - canteen[1][1])**2))
        if len(output) < k:
            output.append({'canteen':canteen[0],'coordinates':canteen[1],'distance':distance})
        else:
            for entry in output:
                if distance < entry['distance']:
                    output.pop()
                    output.append({'canteen':canteen[0],'coordinates':canteen[1],'distance':distance})
                    break
        output = sorted(output,key=lambda d: d['distance'])
    print(f"{len(output)} Nearest Canteen found:") if len(output) == 1 else print(f"{len(output)} Nearest Canteens found:")
    for canteen in output: print(f"{canteen['canteen']} - {canteen['distance']}m")

# Any additional function to assist search criteria
def keywords_validation(keywords_list_processed):
    if len(keywords_list_processed) == 0:
        print("Error: No input found. Please try again.")
        return True
    
    elif "Mixed" in keywords_list_processed and "Rice" in keywords_list_processed:
        if keywords_list_processed.index("Mixed") + 1 == keywords_list_processed.index("Rice"):
            keywords_list_processed.remove("Mixed")
            keywords_list_processed.remove("Rice")
            keywords_list_processed.append("Mixed Rice")
    return False

def find_no_keyword_matches(keywords_list_processed, matches_no):
    matches = []
    matches_dict = {}
    for canteen in canteen_stall_keywords.items():
        for shop in canteen[1].items():
            if sum(keyword in shop[1].split(", ") for keyword in keywords_list_processed) == matches_no:
                matches.append({'canteen':canteen[0],'shop':shop[0]}) 
    matches_dict[matches_no] = matches
    return matches_dict, len(matches)

def get_keyword_output(keywords_list):
    output = []
    total_matches = 0
    keywords_list_processed = [keyword for keyword in keywords_list if keyword != "Or" and keyword != "And"]
    if keywords_validation(keywords_list_processed):
        return output, total_matches, True

    if "Or" in keywords_list:
        for i in range(len(keywords_list_processed)):
            matches_no = len(keywords_list_processed) - i
            matches_dict, matches_length = find_no_keyword_matches(keywords_list_processed, matches_no)
            output.append(matches_dict)
            total_matches += matches_length
    else:
        matches_dict, matches_length = find_no_keyword_matches(keywords_list_processed, len(keywords_list_processed))
        output.append(matches_dict)
        total_matches += matches_length

    return output, total_matches, False

def find_no_price_matches(max_price, entry):
    keyword_matching_no, shops = entry[0], entry[1]
    matches_dict = {}
    matches = []
    for shopData in shops:
        price = canteen_stall_prices[shopData['canteen']][shopData['shop']]
        if price <= max_price:
            shopData['price'] = price
            matches.append(shopData)
    matches = sorted(matches, key= lambda d: d['price'])
    matches_dict[keyword_matching_no] = matches
    return matches_dict, len(matches)

def find_closest_price_match(entries):
    matches = []
    for entry in entries:
        for shopsData in entry.values():
            for shopData in shopsData:
                price = canteen_stall_prices[shopData['canteen']][shopData['shop']]
                if not matches or price < matches[0]['price']:
                    matches = []
                    shopData['price'] = price
                    matches.append(shopData)
                elif price == matches[0]['price']: 
                    shopData['price'] = price
                    matches.append(shopData)
    return matches

def display_output(output, total_matches, matches_output = []):
    if total_matches == 0:
        if matches_output:
            output = find_closest_price_match(matches_output)
            print("Food Stalls found: No food stall found with specified price range.\nRecommended Food Stall(s) with the closest price range.")
            for shopData in output:
                print(f"{shopData['canteen']} - {shopData['shop']} - S${shopData['price']}")
        else:
            print("Food Stalls found: No food stall found with input keyword.")
            return True
    else:
        print(f"Food Stalls found: {total_matches}")
        for entry in output:
            entry = list(entry.items())[0]
            matching_no, shops = entry[0], entry[1]
            if shops:
                if matching_no == 1:
                    print(f"Food stalls that match {matching_no} keyword:")
                else:
                    print(f"Food stalls that match {matching_no} keywords:")
                if matches_output:
                    for shopData in shops:
                        print(f"{shopData['canteen']} - {shopData['shop']} - S${shopData['price']}")
                else:
                    for shopData in shops:
                        print(f"{shopData['canteen']} - {shopData['shop']}")
        print("")
    return False

# Main Python Program Template
# dictionary data structures
canteen_stall_keywords = load_stall_keywords("canteens.xlsx")
canteen_stall_prices = load_stall_prices("canteens.xlsx")
canteen_locations = load_canteen_location("canteens.xlsx")

# main program template - provided
def main():
    loop = True

    while loop:
        print("=======================")
        print("F&B Recommendation Menu")
        print("1 -- Display Data")
        print("2 -- Keyword-based Search")
        print("3 -- Price-based Search")
        print("4 -- Location-based Search")
        print("5 -- Exit Program")
        print("=======================")

        try:
            option = int(input("Enter option [1-5]: "))
        except:
            print("Error: Non integer value detected. Please try again.")
        if option == 1:
            # print provided dictionary data structures
            print("1 -- Display Data")
            print("Keyword Dictionary: ", canteen_stall_keywords)
            print("Price Dictionary: ", canteen_stall_prices)
            print("Location Dictionary: ", canteen_locations)
            
        elif option == 2:
            # keyword-based search
            print("Keyword-based Search")
            keywords_invalid = True
            while keywords_invalid:
                keywords = input("Enter type of food: ")
                # call keyword-based search function
                keywords_invalid = search_by_keyword(keywords)
        elif option == 3:
            # price-based search
            print("Price-based Search")
            price_invalid = True
            while price_invalid:
                keywords = input("Enter type of food: ")
                max_price = input("Enter maximum meal price (S$): ")
                # call price-based search function
                price_invalid = search_by_price(keywords, max_price)
        elif option == 4:
            # location-based search
            print("Location-based Search")

            # call PyGame function to get two users' locations
            userA_location = get_user_location_interface()
            print("User A's location (x, y): ", userA_location)
            userB_location = get_user_location_interface()
            print("User B's location (x, y): ", userB_location)

            location_iterator = zip(userA_location,userB_location)
            user_locations = tuple([sum(i)/2 for i in location_iterator])
            # call location-based search function
            k = input("Number of canteens: ")
            search_nearest_canteens(user_locations, k)

        elif option == 5:
            # exit the program
            print("Exiting F&B Recommendation")
            loop = False
        
        else:
            print("Error: Input out of range. Please try again.")

main()