import java.util.Scanner;

public class Shape2DApp {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Shape[] shapes = new Shape[10];
    int shapeIndex = 0;
    int choice = 0;
    while (choice != 3) {
      System.out.println("Perform the following methods: ");
      System.out.println("1 - Add shape to figure");
      System.out.println("2 - Calculate total area");
      System.out.println("3 - Quit");
      choice = sc.nextInt();
      switch (choice) {
        case 1:
          Shape newShape = new Shape();
          shapes[shapeIndex] = newShape;
          shapeIndex++;
          System.out.println("Shape Added!");
          break;

        case 2:
          double totalArea = 0;
          for (Shape s: shapes) {
            if (s != null) {
              totalArea += s.calculateArea();
            }
          }
          System.out.println("Total Area: " + totalArea);
          break;

        case 3:
          return;
      
        default:
          System.out.println("Invalid choice!");
          break;
      }
    }
    sc.close();
  }
}
