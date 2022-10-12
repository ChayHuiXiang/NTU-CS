public class Shape3D extends Shape {
  public int dimension3;

  public Shape3D(int dimension1, String shapeType) {
    this(dimension1, 0, shapeType);
  }

  public Shape3D(int dimension1, int dimension2, String shapeType) {
    this(dimension1, dimension2, 0, shapeType);
  }

  public Shape3D(int dimension1, int dimension2, int dimension3, String shapeType) {
    super(dimension1, dimension2, shapeType);
    this.dimension3 = dimension3;
  }

  public double calculateArea() {
    switch (shapeType) {
      case "sphere":
        return 4 * Math.PI * dimension1 * dimension1;
      
      case "pyramid":
        return dimension1 * dimension1 + 2 * dimension1 * Math.sqrt(dimension1 * dimension1 / 4 + dimension2 * dimension2);

      case "cuboid":
        return  2 * (dimension1 * dimension2) + 2 * (dimension1 * dimension3) + 2 * (dimension2 * dimension3);

      case "cone":
        return Math.PI * dimension1 * (dimension1 + Math.sqrt(dimension2 * dimension2 + dimension1 * dimension1));

      case "cylinder":
        return 2 * Math.PI * dimension1 * dimension2 + 2 * Math.PI * dimension1 * dimension1;

      default:
        return 0;
    }
  }

  public double calculateVolume() {
    switch (shapeType) {
      case "sphere":
        return Math.PI * dimension1 * dimension1 * dimension1 * 4 / 3;

      case "pyramid":
        return dimension3 * dimension1 * dimension2 / 3;

      case "cuboid":
        return dimension1 * dimension2 * dimension3;

      case "cylinder":
        return Math.PI * dimension1 * dimension1 * dimension2;

      case "cone":
        return Math.PI * dimension1 * dimension1 * dimension2 / 3;
    
      default:
        return 0;
    }
  }
}
