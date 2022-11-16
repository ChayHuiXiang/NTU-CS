package SC2002.AY2021_Sem2_Paper.Q2;

public class TestClassApp {
  public static void main(String[] args) {
    TestClass.greetings();
    TestClass myProduct = new TestClass("Amazing");
    myProduct.print();
    myProduct.update(999.99, "AmazingII");
    myProduct.print();
    myProduct.printNumberOfProduct();

    TestClass tomProduct = new TestClass("Tom");
    tomProduct.printNumberOfProduct();
  }
}
