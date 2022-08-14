package SC2002.Tut_2_Classes_Objects;

public class Circle {
  private double radius; // radius of circle
  private static final double PI = 3.14159;
  // constructor
  public Circle(double rad) {
    setRadius(rad);
  }
  // mutator method – set radius
  public void setRadius(double rad) {
    this.radius = rad;
  }
  // accessor method – get radius
  public double getRadius(){
    return this.radius;
  }
  // calculate area
  public double area() {
    return PI * this.radius * this.radius;
  }
  // calculate circumference
  public double circumference() {
    return 2 * PI * this.radius;
  }
  // print area
  public void printArea(){
    System.out.println(area());
  }
  // print circumference
  public void printCircumference(){
    System.out.println(circumference());
  } 
}
