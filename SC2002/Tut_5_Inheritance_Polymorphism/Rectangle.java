package SC2002.Tut_5_Inheritance_Polymorphism;

public class Rectangle extends Polygon {
  public Rectangle(String theName, float theWidth, float theHeight) {
    super(theName, theWidth, theHeight);
    polytype = KindofPolygon.POLY_RECT;
  }

  @Override
  public float calArea() {
    return height * width;
  }
}
