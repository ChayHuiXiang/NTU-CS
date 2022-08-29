package SC2002.Tut_3_Class_Methods_Inheritance;

import java.lang.Math;
public class Cylinder extends Circle {
  private int height;
  public Cylinder(int height, int radius, int x, int y) {
    super(radius, x, y);
    this.height = height;
  }

  public void setHeight(int height) {
    this.height = height;
  }

  public int getHeight() {
    return height;
  }

  public double area() {
    int radius = getRadius();
    double circumference = 2 * Math.PI * radius;
    return super.area() * 2 + circumference * height;
  }

  public double volume() {
    return super.area() * height;
  }

  public String toString() {
    String output = super.toString();
    output = output.substring(1);
    return "[ " + height + "," + output;
  }
}
