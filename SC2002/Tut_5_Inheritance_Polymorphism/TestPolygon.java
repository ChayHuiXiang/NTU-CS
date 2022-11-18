package SC2002.Tut_5_Inheritance_Polymorphism;

public class TestPolygon {
  // public static void printArea(Rectangle r) {
  //   float area = r.calArea();
  //   System.out.println("Area: " + area);
  // };

  // public static void printArea(Triangle t) {
  //   float area = t.calArea();
  //   System.out.println("Area: " + area);
  // }

  public static void printArea(Polygon p) {
    float area = p.calArea();
    System.out.println("Area: " + area);
  }

  public static void main(String[] args) {
    // static binding, require new printArea method everytime new polygons are introduced
    Rectangle r = new Rectangle("rectangle", 10, 25);
    // printArea(r);
    Triangle t = new Triangle("triangle", 10, 25);
    // printArea(t);

    // dynamic binding, does not require new printArea method everytime new polygons are introduced
    printArea(r);
    printArea(t);
  }

}
