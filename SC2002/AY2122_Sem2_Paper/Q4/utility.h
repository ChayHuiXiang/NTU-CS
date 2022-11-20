#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

using namespace std;

class Collection {
  public:
    virtual void add(string s) = 0;
};

class List: public Collection {
  public:
    virtual string get(int index) = 0;
};

class ArrayList: public List {
  private:
    int size;
    string* items;
  public:
    ArrayList(int size);
    void add(string s);
    string get(int index);
};

#endif
