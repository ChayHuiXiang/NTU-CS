package SC2002.AY2021_Sem2_Paper.Q1;

class A {
  public A() {
    System.out.println("constructor A");
  }
  void method(int a) {
    System.out.println("A1");
  }
  void method(double a) {
    System.out.println("A2");
  }
}
class B extends A {
  public B() {
    System.out.println("constructor B");
  }
  void method(double a) {
    System.out.println("B1");
  }
}
class C extends B {
  public C() {
    System.out.println("constructor C");
  }
  void method(int a) {
    System.out.println("C1");
  }
}
public class Test {
  public static void main(String[] args) {
    B ob = new B();
    C oc = new C();
    ob.method(100);
    oc.method(100);
    ob.method(9.9);
    oc.method(9.9);
  }
}
