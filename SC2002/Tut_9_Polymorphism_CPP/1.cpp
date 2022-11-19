#include <iostream>

using namespace std;

class A {
  public:
    int a,b;
  public :
    A(int y, int x=0) {
      a = x;
      b = y;
    }
    virtual void print() ;
};

class B: public A {
  private:
  float p,q;
  public:
    B(int m, int n, float u, float v): A(m, n), p(u), q(v) {}
    B(): A(0, 0), p(0), q(0) {}
    void input(float u, float v);
    virtual void print(void);
};

void A::print(void) {
  cout << "A values: " << a << " " << b << "\n" ;
}

void B::print(void) {
  cout << "B values : " << p << " " << q << "\n" ;
}

void B::input(float x, float y) {
  p = x; q = y;
}

int doubleIt(A a) { return a.a * a.a ; }
int main() {
  A a1(10,20), *ptr ;
  B b1;
  b1.input(7.5, 3.142);
  ptr = &a1 ;
  ptr->print();
  ptr = &b1;
  ptr->print();
}
