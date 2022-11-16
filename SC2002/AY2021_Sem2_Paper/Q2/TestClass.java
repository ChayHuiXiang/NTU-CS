package SC2002.AY2021_Sem2_Paper.Q2;

public class TestClass {
  private double price;
  private String name;
  static int numberOfProduct = 0;

  public TestClass(String name) {
    this.name = name;
    this.price = 0;
    numberOfProduct++;
  }

  public static void greetings() {
    System.out.println("Hello, welcome to our product line.");
  }
  public void update(double price, String name) {
    this.price = price;
    this.name = name;
  }
  public void print() {
    System.out.println(name + ": costs S$" + price);
  }
  public void printNumberOfProduct() {
    System.out.println("number = " + numberOfProduct);
  }
}
