package SC2002.AY1819_Sem2_Paper.Q2;

class A {
  public void fun(double d) {
    System.out.println("A");
  }
  // public void fun(int d) {
  //   System.out.println("A");
  // }
}

class B {
  public void fun(int i) {
    System.out.println("B");
  }
}

class C extends A {
  public void fun(int i) {
    System.out.println("C");
  }
}

class D extends B {
  public void fun(double d) {
    System.out.println("D");
  }
}

class E extends B {
  public void fun(double d) {
    System.out.println("E");
  }
  public void fun(int i) {
    System.out.println("F");
  }
}

public class Test {
  public static void main(String[] args) {
    C c = new C(); c.fun(6);
    D d = new D(); d.fun(6);
    A x = new C(); x.fun(6);
    B y = new D(); y.fun(6);
    B z = new E(); z.fun(6);
  }
}
