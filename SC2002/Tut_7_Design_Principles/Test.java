package SC2002.Tut_7_Design_Principles;

public class Test implements ITest {
  public void testing() {
    System.out.println("Inside testing()");
  }

  public static void main(String[] args) {
    ITest hello = new Test();
    hello.testing();
  }
}
