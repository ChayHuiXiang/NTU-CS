#include "childAnimal.h"
#include <vector>

string getName() {
  string name;
  cout << "Enter its name: ";
  cin >> name;
  return name;
}

COLOR getColor() {
  int choice;
  while (1) {
    cout << "Enter its colour: (1) Green, (2) Blue, (3) White, (4) Black, (5) Brown ";
    cin >> choice;
    switch (choice) {
      case 1:
        return Green;
      
      case 2:
        return Blue;

      case 3:
        return White;

      case 4:
        return Black;

      case 5:
        return Brown;
      
      default:
        cout << "Invalid colour! Please Choose Again" << endl;
        break;
    }
  }
}

string getOwner() {
  string owner;
  cout << "Enter its owner: ";
  cin >> owner;
  return owner;
}

int main() {
  int choice = 1;
  vector<Mammal*> listofMammals;
  while (choice <= 4 && choice >= 1) {
    string name;
    COLOR color;
    string owner;
    Mammal* aniPtr;
    cout << "Select the animal to send to Zoo:" << endl;
    cout << "(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit" << endl;
    cin >> choice;
    if (choice == 1 || choice == 2 || choice == 3) {
      name = getName();
      color = getColor();
      owner = getOwner();
      switch (choice)
      {
      case 1:
        cout << "You have chosen (1) Dog!" << endl;
        aniPtr = new Dog(owner, color, name);
        break;

      case 2:
        cout << "You have chosen (2) Cat!" << endl;
        aniPtr = new Cat(owner, color, name);
        break;

      case 3:
        cout << "You have chosen (3) Lion!" << endl;
        aniPtr = new Lion(owner, color, name);
        break;
      
      default:
        break;
      }
      listofMammals.push_back(aniPtr);
    } else if (choice == 4) {
      cout << "You have chosen (4) Move all animals!" << endl;
      for (int i = 0; i<listofMammals.size(); i++) {
        Mammal* mammal = listofMammals[i];
        mammal->move();
        mammal->speak();
        mammal->eat();
      }
    } else {
      cout << "Bye Bye!" << endl;
      for (int i = 0; i<listofMammals.size(); i++) {
        Mammal* mammal = listofMammals[i];
        delete mammal;
      }
      break;
    }
  }

  return 0;
}
