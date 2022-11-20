#include <iostream>

using namespace std;

class A {
  public:
    A() {
      cout << "Creating A";
    }
    ~A() {}
};

class B {
  public:
    B() {
      cout << "Creating B";
    }
    ~B() {}
};

class C: public A, B {
  public: 
    C() {}
    ~C() {}
};


int main() {
  C cObj;
  return 1;
}
