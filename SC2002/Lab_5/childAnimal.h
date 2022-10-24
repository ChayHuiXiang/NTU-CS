#ifndef CHILDANIMAL_H
#define CHILDANIMAL_H

#include "animal.h"

class Dog: public Mammal {
  private:
    string owner;
  public:
    Dog(string o, COLOR c, string n): Mammal(n, c) {
      owner = o;
    }
    ~Dog() {}
    void speak() const {
      cout << "Dog Woof" << endl;
    }
    void move() const {
      cout << "Dog move" << endl;
    }
};

class Cat: public Mammal {
  private:
    string owner;
  public:
    Cat(string o, COLOR c, string n): Mammal(n, c) {
      owner = o;
    }
    ~Cat() {}
    void speak() const {
      cout << "Cat Meow" << endl;
    }
    void move() const {
      cout << "Cat move" << endl;
    }
};

class Lion: public Mammal {
  private:
    string owner;
  public:
    Lion(string o, COLOR c, string n): Mammal(n, c), owner(o) {}
    ~Lion() {}
    void speak() const {
      cout << "Lion Roar" << endl;
    }
    void move() const {
      cout << "Lion move" << endl;
    }
};

#endif
