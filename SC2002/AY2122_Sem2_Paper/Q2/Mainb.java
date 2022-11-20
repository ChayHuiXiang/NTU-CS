package SC2002.AY2122_Sem2_Paper.Q2;

class A {
  public void move(Object o) {
    System.out.println("A move");
  }
  public void keep(String s) {
    System.out.println("A keep");
  }
}

class B extends A {
  public void move(Object o) {
    System.out.println("B move");
  }
  public void keep(Object o) {
    System.out.println("B keep");
  }
}

class C extends B {
  public void move(String s) {
    super.move(s);
    System.out.println("C move");
  }
  public void keep(String s) {
    super.keep(s);
    System.out.println("C keep");
  }
}

public class Mainb {
  public static void main(String[] args) {
    A a = new A();
    A b = new B();
    A c = new C();
    a.move("Test");
    b.move("Test");
    b.keep("Test");
    c.move("Test");
    c.keep("Test");
  }  
}
