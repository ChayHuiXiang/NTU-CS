#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

enum COLOR { Green, Blue, White, Black, Brown };

class Animal {
  public:
    Animal();
    Animal(string n, COLOR c);
    virtual ~Animal();
    virtual void speak () const;
    virtual void move() const = 0;
  private:
    string _name;
    COLOR _color;
};

class Mammal: public Animal {
  public:
    Mammal(string n, COLOR c);
    ~Mammal();
    void eat() const;
    void move() const;
};

#endif
