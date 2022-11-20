package SC2002.AY2122_Sem2_Paper.Q2;

class A {
  private int n;
  A() {
    System.out.println("a1");
  }
  A(int n) {
    n++;
    System.out.println("a2: " + n);
    this.n = n;
  }
}

class B extends A {
  private int n;
  B() {
    System.out.println("b1");
  }
  public B(int n) {
    super(30);
    System.out.println("b2: " + n);
    this.n = n;
  }
}

class C extends A {
  private int n;
  C() {
    super(30);
    System.out.println("c1");
  }
  public C(int n) {
    System.out.println("c2: " + n);
    this.n = n;
  }
}

public class Main {
  public static void main(String[] args) {
    B test1 = new B();
    // B test2 = new B(10);
    // C test3 = new C();
    // C test4 = new C(20);
  }
}
