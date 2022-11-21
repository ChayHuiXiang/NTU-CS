package SC2002.Lab_4;


import java.util.Scanner;
public class Shape2DApp {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the total number of shapes: ");
    int shapeCount = sc.nextInt();

    Shape[] shapes = new Shape[shapeCount];

    for (int i = 0; i < shapeCount; i++) {
      int shapeChoice;
      while (true) {
        System.out.println("(1) - Square");
        System.out.println("(2) - Rectangle");
        System.out.println("(3) - Circle");
        System.out.println("(4) - Triangle");
        System.out.print("Choose the shape of your choice: ");
        shapeChoice = sc.nextInt();
        if (shapeChoice <= 0 && shapeChoice >= 5) {
          System.out.println("Invalid choice! Please choose again!");
        } else {
          break;
        }
      }

      int dimension1, dimension2 = 0;
      Shape shape;

      switch (shapeChoice) {
        case 1:
          System.out.print("Enter length of square: ");
          dimension1 = sc.nextInt();
          shape = new Shape(dimension1, "square");
          break;

        case 2:
          System.out.print("Enter length of rectangle: ");
          dimension1 = sc.nextInt();
          System.out.print("Enter breadth of rectangle: ");
          dimension2 = sc.nextInt();
          shape = new Shape(dimension1, dimension2, "rectangle");
          break;

        case 3:
          System.out.print("Enter radius of circle: ");
          dimension1 = sc.nextInt();
          shape = new Shape(dimension1, "circle");
          break;

        case 4:
          System.out.print("Enter base of triangle: ");
          dimension1 = sc.nextInt();
          System.out.print("Enter height of triangle: ");
          dimension2 = sc.nextInt();
          shape = new Shape(dimension1, dimension2, "triangle");
          break;
      
        default:
          shape = new Shape(0, "square");
          break;

      }
      shapes[i] = shape;
    }

    double totalArea = 0;
    for (Shape s: shapes) {
      double area = s.calculateArea();
      totalArea += area;
    }

    System.out.println("Total area: " + totalArea);
    sc.close();
  }
}
