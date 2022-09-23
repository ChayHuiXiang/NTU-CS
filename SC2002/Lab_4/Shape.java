public class Shape {
  public String shapeType;
  public int dimension1;
  public int dimension2;

  public Shape(int dimension1, String shapeType) {
    this(dimension1, 0, shapeType);
  }
  public Shape(int dimension1, int dimension2, String shapeType) {
    this.dimension1 = dimension1;
    this.dimension2 = dimension2;
    this.shapeType = shapeType;
  }

  public double calculateArea() {
    switch (shapeType) {
      case "circle":
        return Math.PI * dimension1 * dimension1;

      case "square":
        return dimension1 * dimension1;

      case "triangle":
        return 0.5 * dimension1 * dimension2;

      case "rectangle":
        return dimension1 * dimension2;
    
      default:
        return 0;
    }
  }


}
