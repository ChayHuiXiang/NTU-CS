import java.util.Scanner;

public class Shape {
  enum ShapeType {
    SQUARE,
    RECTANGLE,
    CIRCLE,
    TRIANGLE
  }

  private ShapeType shapeType;
  private int length;
  private int breadth;
  private int radius;

  private static Scanner sc;

  public Shape() {
    sc = new Scanner(System.in);
    while (shapeType == null) {
      System.out.println("Enter your desired shape: ");
      String shape = sc.nextLine();
      shape = shape.toLowerCase();
      switch (shape) {
        case "triangle":
          System.out.println("Please enter your desired length");
          length = sc.nextInt();
          System.out.println("Please enter your desired breadth");
          breadth = sc.nextInt();
          shapeType = ShapeType.TRIANGLE;
          break;
        
        case "square":
          System.out.println("Please enter your desired length");
          length = sc.nextInt();
          shapeType = ShapeType.SQUARE;
          break;
  
        case "rectangle":
          System.out.println("Please enter your desired length");
          length = sc.nextInt();
          System.out.println("Please enter your desired breadth");
          breadth = sc.nextInt();
          shapeType = ShapeType.RECTANGLE;
          break;
  
        case "circle":
          System.out.println("Please enter your desired radius");
          radius = sc.nextInt();
          shapeType = ShapeType.CIRCLE;
          break;
  
        default:
          System.out.println("Invalid shape! Please try again");
          break;
      }
    }
  }

  public double calculateArea() {
    switch (shapeType) {
      case CIRCLE:
        return Math.PI * radius * radius;

      case SQUARE:
        return length * length;

      case TRIANGLE:
        return 0.5*length*breadth;

      case RECTANGLE:
        return length * breadth;
    
      default:
        return 0;
    }
  }

  public double calculation() {
    String calculation = "";
    do {
      System.out.println("Enter the type of calculation: ");
      calculation = sc.nextLine();
      calculation = calculation.toLowerCase();
      if (calculation == "area") {
        return calculateArea();
      } else if (calculation == "volume") {
        return calculateArea();
      } else {
        System.out.println("Calculation Type not supported! Supported Types are: Area | Volume");
      }
    } while (calculation != "area" && calculation != "volume");
    return -1;
  }
}
