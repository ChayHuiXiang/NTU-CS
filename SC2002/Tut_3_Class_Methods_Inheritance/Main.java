package SC2002.Tut_3_Class_Methods_Inheritance;

public class Main {
  public static void main(String[] args) {
    Cylinder cylinder = new Cylinder(2, 1, 0, 0);
    System.out.println(cylinder.toString());
    System.out.println(cylinder.area());
    System.out.println(cylinder.volume());
  }
}
