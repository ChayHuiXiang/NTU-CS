#ifndef CHILDANIMAL_H
#define CHILDANIMAL_H

#include "animal.h"

class Dog: public Mammal {
  private:
    string owner;
  public:
    Dog(string o, COLOR c, string n);
    ~Dog();
    void speak() const;
    void move() const;
};

class Cat: public Mammal {
  private:
    string owner;
  public:
    Cat(string o, COLOR c, string n);
    ~Cat();
    void speak() const;
    void move() const;
};

class Lion: public Mammal {
  private:
    string owner;
  public:
    Lion(string o, COLOR c, string n);
    ~Lion();
    void speak() const;
    void move() const;
};

#endif
