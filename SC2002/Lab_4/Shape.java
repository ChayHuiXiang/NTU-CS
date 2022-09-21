import java.util.Scanner;

public class Shape {
  public String shapeType;
  public int length;
  public int breadth;
  public int radius;

  public static Scanner sc;

  public Shape() {
    sc = new Scanner(System.in);
    System.out.println("test la");
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
          shapeType = "triangle";
          break;
        
        case "square":
          System.out.println("Please enter your desired length");
          length = sc.nextInt();
          shapeType = "square";
          break;
  
        case "rectangle":
          System.out.println("Please enter your desired length");
          length = sc.nextInt();
          System.out.println("Please enter your desired breadth");
          breadth = sc.nextInt();
          shapeType = "rectangle";
          break;
  
        case "circle":
          System.out.println("Please enter your desired radius");
          radius = sc.nextInt();
          shapeType = "circle";
          break;
  
        default:
          System.out.println("Invalid shape! Please try again");
          break;
      }
    }
  }

  public double calculateArea() {
    switch (shapeType) {
      case "circle":
        return Math.PI * radius * radius;

      case "square":
        return length * length;

      case "triangle":
        return 0.5*length*breadth;

      case "rectangle":
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
