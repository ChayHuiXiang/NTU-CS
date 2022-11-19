package SC2002.Tut_5_Inheritance_Polymorphism;

public class Triangle extends Polygon {
  public Triangle(String theName, float theWidth, float theHeight) {
    super(theName, theWidth, theHeight);
    polytype = KindofPolygon.POLY_TRIANG;
  }

  @Override
  public float calArea() {
    return (float)(0.5 * height * width);
  }
}
