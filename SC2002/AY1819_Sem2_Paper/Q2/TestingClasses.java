package SC2002.AY1819_Sem2_Paper.Q2;

class A {
  public static void print() {
    System.out.println("In A!");
  }
}

class B extends A {
  public static void print() {
    System.out.println("In B!");
  }
}

public class TestingClasses {
  public static void main(String[] args) {
    A a = new B();
    B b = (B)a;
    b.print();
  }
}
