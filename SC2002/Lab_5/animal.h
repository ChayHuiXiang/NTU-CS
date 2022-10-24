#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

enum COLOR { Green, Blue, White, Black, Brown };

class Animal {
  public:
    Animal(): _name("unknown") {
      cout << "constructing Animal object " << _name << endl;
    }
    Animal(string n, COLOR c) {
      cout << "constructing Animal object with string " << n << " and Color " << c << endl;
      _name = n;
      _color = c;
    }
    virtual ~Animal() {
      cout << "destructing Animal object " << _name << endl;
    }
    virtual void speak () const {
      cout << "Animal speaks" << endl;
    }
    virtual void move() const = 0;
  private:
    string _name;
    COLOR _color;
};

class Mammal: public Animal {
  public:
    Mammal(string n, COLOR c): Animal(n, c) {}
    ~Mammal() {}
    void eat() const {
      cout << "Mammal eat" << endl;
    }
    void move() const {
      cout << "Mammal move" << endl;
    }
};

#endif
