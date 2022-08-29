package SC2002.Tut_3_Class_Methods_Inheritance;

import java.lang.Math;

public class Circle extends Point {
  private int radius;
  public Circle(int radius, int x, int y) {
    super(x, y);
    this.radius = radius;
  }
  public void setRadius(int radius) {
    this.radius = radius;
  }
  public int getRadius() {
    return radius;
  }
  public double area() {
    return Math.PI * radius * radius;
  }
  public String toString() {
    String output = super.toString();
    output = output.substring(1);
    return "[ " + radius + "," + output;
  }
}
