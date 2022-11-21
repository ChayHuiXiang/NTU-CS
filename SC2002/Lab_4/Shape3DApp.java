package SC2002.Lab_4;


import java.util.Scanner;

public class Shape3DApp {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the total number of shapes: ");
    int shapeCount = sc.nextInt();

    Shape3D[] shapes = new Shape3D[shapeCount];

    for (int i = 0; i < shapeCount; i++) {
      int shapeChoice;
      while (true) {
        System.out.println("(1) - Sphere");
        System.out.println("(2) - Pyramid");
        System.out.println("(3) - Cuboid");
        System.out.println("(4) - Cone");
        System.out.println("(5) - Cylinder");
        System.out.print("Choose the shape of your choice: ");
        shapeChoice = sc.nextInt();
        if (shapeChoice <= 0 && shapeChoice >= 6) {
          System.out.println("Invalid choice! Please choose again!");
        } else {
          break;
        }
      }

      int dimension1, dimension2, dimension3 = 0;
      Shape3D shape;

      switch (shapeChoice) {
        case 1:
          System.out.print("Enter length of sphere: ");
          dimension1 = sc.nextInt();
          shape = new Shape3D(dimension1, "sphere");
          break;

        case 2:
          System.out.print("Enter length of pyramid: ");
          dimension1 = sc.nextInt();
          System.out.print("Enter height of pyramid: ");
          dimension2 = sc.nextInt();
          shape = new Shape3D(dimension1, dimension2, "pyramid");
          break;

        case 3:
          System.out.print("Enter length of cuboid: ");
          dimension1 = sc.nextInt();
          
          System.out.print("Enter breadth of cuboid: ");
          dimension2 = sc.nextInt();
          
          System.out.print("Enter height of cuboid: ");
          dimension3 = sc.nextInt();

          shape = new Shape3D(dimension1, dimension2, dimension3, "cuboid");
          break;

        case 4:
          System.out.print("Enter radius of cone: ");
          dimension1 = sc.nextInt();
          System.out.print("Enter height of cone: ");
          dimension2 = sc.nextInt();

          shape = new Shape3D(dimension1, dimension2, "cone");
          break;

        case 5:
          System.out.print("Enter radius of cylinder: ");
          dimension1 = sc.nextInt();
          System.out.print("Enter height of cylinder: ");
          dimension2 = sc.nextInt();

          shape = new Shape3D(dimension1, dimension2, "cylinder");
          break;

        default:
          shape = new Shape3D(0, "sphere");
          break;

      }
      shapes[i] = shape;
    }
    int calculationChoice;
    while (true) {
      System.out.println("Choose the calculation of your choice: ");
      System.out.println("(1) - Area");
      System.out.println("(2) - Volume");
      calculationChoice = sc.nextInt();
      if (calculationChoice == 1 || calculationChoice == 2) {
        break;
      } else {
        System.out.println("Invalid choice! Please choose again!");
      }
    }

    switch (calculationChoice) {
      case 1:
        double totalArea = 0;
        for (Shape3D s: shapes) {
          double area = s.calculateArea();
          totalArea += area;
        }
        System.out.println("Total area: " + totalArea);
        break;

      case 2:
        double totalVolume = 0;
        for (Shape3D s: shapes) {
          double volume = s.calculateVolume();
          totalVolume += volume;
        };
        System.out.println("Total volume: " + totalVolume);
        break;
    
      default:
        break;
      }
    sc.close();
  }
}
